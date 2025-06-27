#include <iostream>
#include <ctime>
#include <random>

using namespace std;

static const int MAXSIZE = 26;

class Graph {
    int size;
    bool M[MAXSIZE][MAXSIZE];
    int weight[MAXSIZE][MAXSIZE];
    int testM[MAXSIZE][MAXSIZE];
    char order[MAXSIZE];
    int *res_wight;
    char vertex_name[MAXSIZE];
    char **name_res_wight;
    int count_wight = 0;
    int count_vertex_name = 0;
    int *count_arr_vertex_name;
    int count_name_res_wight = 0;
    bool check_two = true;
    void print_search();
    void clearM();
    void clear_test_M();
    void fill();
    void search(int x, int& l);
    void creat_dynamic_arr();
public:
    Graph(int i);
    Graph();
    ~Graph();
    void print();
    void addEdgles();
    void search_cycle(int start);
};

void Graph::search_cycle(int start = 0)
{
    for (int i = 0; i < size; ++i) {
        for (int k = 0; k < size; ++k) {
            if (M[i][k]) {
                int l = 0;
                if (testM[i][k] == 0) {
                    testM[i][k] += 1;
                    search(k, l);
                }
            }
        }
    }
    print_search();
}


Graph::Graph() : size(MAXSIZE) {
    clearM();
    clear_test_M();
    creat_dynamic_arr();
    fill();
    print();
}

void Graph::search(int i, int& l)
{
    for (size_t k = 0; k < size; ++k) {
        if (M[i][k]) {
            if (testM[i][k] == 0) {
                testM[i][k] += 1;
                search(k, l);
            }
            if (testM[i][k] == 1) {
                testM[i][k] += 1;
                l += weight[i][k];
                if (count_vertex_name == 0) {
                    vertex_name[count_vertex_name++] = order[i];
                }
                else {
                    if (vertex_name[count_vertex_name - 1] != order[i])
                        vertex_name[count_vertex_name++] = order[i];
                }
                check_two = true;
                search(k, l);
            }
            if (testM[i][k] == 2) {
                if (check_two && count_vertex_name >= 2) {
                    check_two = false;
                    res_wight[count_wight++] = l;
                    l = 0;
                    for (int b = 0; b < count_vertex_name; ++b) {
                        name_res_wight[count_name_res_wight][b] = vertex_name[b];
                    }
                    count_arr_vertex_name[count_name_res_wight] = count_vertex_name;
                    ++count_name_res_wight;
                    count_vertex_name = 0;
                }
            }
        }
        
        
    }
}

void Graph::creat_dynamic_arr()
{
    res_wight = new int[100];
    count_arr_vertex_name = new int[100];
    name_res_wight = new char *[100];
    for (int i = 0; i < 100; ++i) {
        name_res_wight[i] = new char[100];
    }
}

Graph::Graph(int i) : size(i) {
    clearM();
    clear_test_M();
    creat_dynamic_arr();
    cout << "NODES: ";
    for (int i = 0; i < size; i++) {
        order[i] = 'a' + i;
        cout << order[i] << ' ';
    }
    cout << endl;
    addEdgles();
    print();
}

Graph::~Graph() {
    delete[] res_wight;
    delete[] count_arr_vertex_name;
    for (int i = 0; i < 100; ++i) {
        delete[] name_res_wight[i];
    }
    delete[] name_res_wight;
}

void Graph::addEdgles() {
    cout << "Adding the edgles: please enter chosen nodes" << endl;
    cout << "If you want to finish, please enter 0" << endl;
    char second = '1', first = '1';
    while (second != '0' || first != '0') {
        cout << "Enter start node: ";
        cin >> first;
        if (first == '0') break;
        cout << "Enter end node: ";
        cin >> second;
        if (first >= 'a' && first < 'a' + size && second >= 'a' && second < 'a' + size && first != second) {
            int iFirst = 0, iSecond = 0;
            for (int i = 0; i < size; i++) {
                if (order[i] == first) iFirst = i;
                if (order[i] == second) iSecond = i;
            }
            M[iFirst][iSecond] = true;
            int choice_weight = 0;
            std::cout << "Select the edge weight: ";
            std::cin >> choice_weight;
            weight[iFirst][iSecond] = choice_weight;
        }
        else cout << "ERROR: Wrong input. Please try again!" << endl;
    }
}

void Graph::print() {
    cout << "  ";
    for (int i = 0; i < size; i++) cout << order[i] << ' ';
    cout << endl;
    for (int i = 0; i < size; i++) {
        cout << order[i] << ' ';
        for (int j = 0; j < size; j++) cout << M[i][j] << ' ';
        cout << endl;
    }
}


void Graph::print_search()
{
    bool flag_if_negative_cycle = false;
    for (int i = 0; i < count_wight; ++i) {
        if (res_wight[i] < 0) {
            flag_if_negative_cycle = true;
            std::cout << "Res wight: " << res_wight[i] << " { ";
            for (int z = 0; z < count_arr_vertex_name[i]; ++z) {
                std::cout << name_res_wight[i][z] << ' ';
            }
            std::cout << "}" << std::endl;
        }
    }
    if (!flag_if_negative_cycle) {
        std::cout << "No negative cycle" << std::endl;
    }
}

void Graph::clearM() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) M[i][j] = false;
    }
}

void Graph::clear_test_M()
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) testM[i][j] = 0;
    }
}

void Graph::fill() {
    for (int i = 0; i < MAXSIZE; i++) {
        order[i] = 'a' + i;
        for (int j = 0; j < MAXSIZE; j++) {
            if (rand() % 7 > 5 && i != j) {
                M[i][j] = true;
                int var_weight = 0;
                if(rand() % 7 > 3)
                    var_weight = -10 + rand() % 1;
                else
                    var_weight = 10 + rand() % 1;
                weight[i][j] = var_weight;
            }

        }
    }
}

int main()
{
    srand(time(0));

    //cin
    int x;
    cout << "Enter the number of the nodes: ";
    cin >> x;
    Graph g(x);
    //rand
    //Graph g;
    g.search_cycle();
}


#include <iostream>
#include <fstream>
using namespace std;

// Узел связного списка
struct Node {

    char *str; // строка
    char marker = '@'; //маркер
    int length = 0; // длина
    Node *next;

    ~Node() {
        str = nullptr;
        marker = 0;
    }
};

// Класс для реализации односвязного списка
    class LinkedList {
        Node *last;
        Node *head;
        const char* empt = "";
    public:
        int countElem;
        LinkedList() {
            head = nullptr;
            last = nullptr;
            countElem = 0;
        }
        ~LinkedList(){
            if (isEmpty()) return;
            Node *curr = head;
            while (curr != nullptr) {
                Node *remove = curr;
                curr = curr->next;
                head = curr;
                delete remove;
            }
            countElem = 0;
            last = nullptr;
        }

        // Для добавления элемента в список
        void addString(char source[1000]) {
            countElem++;
            Node *node = new Node;

            int size = 0;
            while (source[size] != '\000') size++;
            node->str = new char [size];
            for(int i = 0; i <= size; i++){
                if(i < size){
                    node->str[i] = source[i];
                    node->length++;
                } else{
                    node->str[i] = node->marker;
                }
            }
            node->next = nullptr;
            if (isEmpty()) { // Если список пуст создаем первый узел
                head = node;
                last = node;
            } else { // иначе добавляем в конец списка
                Node *current = last;
                current->next = node;
                last = node;
            }
        }

        // проверка на пустоту списка
        bool isEmpty() {
            return head == nullptr;
        }

        // удалить элемент по заданному номеру
        bool removeByIndex(int i) {
            if (countElem < i) {
                printf("Can't found by index: %d, Total %d elements", i, countElem);
                return false;
            }
            Node *current = head;
            int index = 1;
            while (current->next != nullptr) {
                if (i == 1) { // если номер элемента == 1 (голова списка)
                    Node *remove = current;
                    head = current->next;
                    print(remove);
                    delete remove;
                    countElem--;
                    return true;
                }
                if (index + 1 == i) {
                    Node *remove = current->next;
                    if (remove == last) { // если удаляемый элемент конец списка
                        last = current;
                        print(remove);
                        delete remove;
                        countElem--;
                        return true;
                    }
                    current->next = current->next->next;
                    print(remove);
                    delete remove;
                    countElem--;
                    return true;
                }
                index++;
                current = current->next;
            }
            return true;
        }

        // распечатать строку элемента
        void print(Node *node) {
            printf("Node with string remove:\n");
            for (int i = 0; node->str[i] != node->marker; i++) {
                std::cout << (node->str[i]);
            }
            std::cout << '\n';
        }

        // вернуть строку по номеру элемента
        char * getStr(int i) {
            Node *current = head;
            int currentIndex = 1;
            while (current != nullptr) {
                if (currentIndex == i) {
                    return current->str;
                }
                currentIndex++;
                current = current->next;
            }
            return const_cast<char *>(empt);
        }

        // удалить k элементов, начиная с элемента i
        void removeFromTo(int i, int k)
        {
            if (countElem < i) {
                printf("Can't found by index: %d, Total %d elements\n", i, countElem);
                return;
            }
            if ((i + k) >countElem ) {
                printf("Can't delete: %d, Total %d elements after index: %d\n ", k, countElem - i, i);
                return;
            }
            if (i < 1) {
                printf("Can't found by index: %d, The first element: %d \n", i, 1);
                return;
            }
            if (k < 0) {
                printf("Can't remove: %d\n", k);
                return;
            }
            for (int j = 0; j <= k-1; ++j) {
                removeByIndex(i);
            }
        }

    };

int main() {
    int startIndex;
    int countElements;
    LinkedList *linkedList = new LinkedList;

    // запись строк из файла в связный список, где каждый узел списка представляет строку с маркером
    ifstream input("..\\input.txt"); //открываем поток для чтения файла
    if (input.is_open()) {
        char temp[1000];
        while (input.getline(temp, 1000)) {
            linkedList->addString(temp); // запись очередной строки файла в список
        }
    } else {
        printf("Can't found input.txt");
        return 1;
    }

    cout << "Data before remove: " << endl;
    for (int i = 1; i <= linkedList->countElem; i++) {
        char *stringMarker = linkedList->getStr(i);
        for (int j = 0; stringMarker[j] != '@'; j++) {
            cout << stringMarker[j];
        }
        cout << "\n";
    }

    cout << "Enter start index and how many elements to remove:" << endl;
    cout << "Start index: ";
    cin >> startIndex;
    cout << endl << "How many elements to remove: ";
    cin >> countElements;
    cout << endl;

    ofstream result("..\\result.txt", ios::out);
    if (result.is_open()) {
        result << "Data before remove:\n";
        for (int i = 1; i <= linkedList->countElem; i++) {
            char *stringMarker = linkedList->getStr(i);
            for (int j = 0; stringMarker[j] != '@'; j++) {
                result << stringMarker[j];
            }
            result << "\n";
        }
        linkedList->removeFromTo(startIndex,countElements);
        result << "\nData after remove:\n";
        for (int i = 1; i <= linkedList->countElem; i++) {
            char *stringMarker = linkedList->getStr(i);
            for (int j = 0; stringMarker[j] != '@'; j++) {
                result << stringMarker[j];
            }
            result << "\n";
        }
    }
    result.close();
    cout << "Data after remove: " << endl;
    for (int i = 1; i <= linkedList->countElem; i++) {
        char *stringMarker = linkedList->getStr(i);
        for (int j = 0; stringMarker[j] != '@'; j++) {
            cout << stringMarker[j];
        }
        cout << "\n";
    }
    delete linkedList;
    return 0;
}
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>

using namespace std;
static const int WIDTH = 80;
static const int MAXPOWER = 26;
static bool unbrocken = 1;

template <class X> class STACK {
    X* x; int t;
public:
    STACK(int maxPower) : x(new X[maxPower]), t(0) {}
    bool isEmpty() const { return t == 0; }
    void push(X el) { x[t++] = el; }
    X pop() { return (t ? x[--t] : 0); }
};

template <class X> class QUEUE {
    X* x; int h, t, N;
public:
    QUEUE(int maxQ) : h(0), t(0), N(maxQ), x(new X[maxQ + 1]) {}
    bool isEmpty() const { return (h % N) == t; }
    void push(X el) { x[t++] = el; t %= N; }
    X pop() { h %= N; return x[h++]; }
};


class Node {
    char tag;
    Node* l;
    Node* r;
    int lvl;
public:
    Node();
    Node(char ch);
    ~Node();
    char getTag() { return tag; }
    friend class Tree;
};

Node::Node() : l(nullptr), r(nullptr), lvl(0), tag('0') {}
Node::Node(char ch) : l(nullptr), r(nullptr), lvl(0), tag(ch) {}
Node::~Node() {
    if (l) delete l;
    if (r) delete r;
}

class Tree {
    Node* root;
    int curPower;
    char** SCREEN;
    int curHeight;
    int shift;
    void clear();
    void printNodes(Node* v, int r, int c);
    Tree(const Tree&);
    Tree(Tree&&);
    Tree operator = (const Tree&) const = delete;
    Tree operator = (Tree&&) const = delete;
public:
    Tree();
    ~Tree();
    void growTree();
    void setTree();
    void printTree();
    Node* createNode(int lvl);
    Node* getUserInput(int lvl);
    int DFS();
    bool isEmpty() { return (curPower == 0); }
};

int Tree::DFS() {
    int count = 0;
    STACK <Node*> S(MAXPOWER);
    S.push(root);
    while (!S.isEmpty()) {
        Node* node = S.pop();
        if (node->l) {
            S.push(node->l);
            if (node->l->l == nullptr && node->l->r == nullptr) ++count;
        }
        if (node->r) S.push(node->r);
    }
    return count;
}

Tree::Tree() :root(nullptr), SCREEN(new char* [MAXPOWER]), curHeight(0), curPower(0), shift(WIDTH / 2) {
    for (int i = 0; i < MAXPOWER; i++) SCREEN[i] = new char[WIDTH];
}

Tree::~Tree() {
    for (int i = 0; i < MAXPOWER; i++) delete[] SCREEN[i];
    delete[]SCREEN;
    delete root;
}

void Tree::growTree() { root = createNode(0); }
void Tree::setTree() { root = getUserInput(0); }

Node* Tree::createNode(int lvl) {
    Node* node = nullptr;
    if (curPower < 26 && curHeight < MAXPOWER && (lvl < rand() % 11 + 1)) {
        node = new Node;
        node->lvl = lvl;
        node->tag = ('a' + curPower++);
        node->l = createNode(lvl + 1);
        node->r = createNode(lvl + 1);
    }
    return node;
}

Node* Tree::getUserInput(int lvl) {
    Node* node = nullptr;
    char ch = '0';
    if (curPower < 1) {
        cout << "Enter root value (a-z):" << endl;
        cout << "> for NULLPTR please enter 0" << endl;
        cout << "> for finishing the process please enter 1" << endl;
    }
    cin >> ch;

    if (ch == '1') { unbrocken = 0; }
    if (isalpha(ch) && curHeight < MAXPOWER && curPower < MAXPOWER && unbrocken) {
        node = new Node;
        node->lvl = lvl;
        node->tag = (ch); curPower++;
        if (curPower == MAXPOWER || (!unbrocken)) return node;
        cout << "Enter " << ch << "'s LEFT child value:" << endl;
        node->l = getUserInput(lvl + 1);
        if (curPower == MAXPOWER || (!unbrocken)) return node;
        cout << "Enter " << ch << "'s RIGHT child value:" << endl;
        node->r = getUserInput(lvl + 1);
    }
    return node;
}

void Tree::printTree() {
    if (root == nullptr) {
        cout << "ERROR: Tree does not exist." << endl;
        return;
    }
    clear();
    printNodes(root, 1, shift);
    for (int i = MAXPOWER-1; i >= 0; --i) {
        SCREEN[i][WIDTH - 1] = 0;
        cout << endl;
        cout << SCREEN[i];
    }
    cout << endl;
}

void Tree::printNodes(Node* node, int x, int s) {
    if (x && s && (s < WIDTH)) SCREEN[x - 1][s - 1] = node->tag;
    if (x < MAXPOWER) {
        if (node->l) printNodes(node->l, x + 1, s - (shift >> x));
        if (node->r) printNodes(node->r, x + 1, s + (shift >> x));
    }

}

void Tree::clear() {
    for (int i = 0; i < MAXPOWER; i++) memset(SCREEN[i], '.', WIDTH);
}


int main()
{
    srand(time(0));
    Tree tree;
    tree.growTree();
    //tree.setTree();
    tree.printTree();
    if (!tree.isEmpty()) {
        cout << "There are ";
        cout << tree.DFS() << " count left leaves";
    }
}

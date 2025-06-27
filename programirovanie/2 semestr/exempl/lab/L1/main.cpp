#include <iostream>
#include <fstream>

using namespace std;

class MyString {
public:
    int length = 0;
    char *str = nullptr;
    const char MARKER = '@';
    int bracketsType;

    void addString(const char *str) {
        for (int i = 0; str[i] != '\000'; ++i) {
            length++;
        }
        this->str = new char[length + 1];
        for (int i = 0; i < length; i++) {
            this->str[i] = str[i];
        }
        this->str[length] = MARKER;
    }



    void Print() {
        for (int i = 0; str[i] != MARKER; i++) {
            cout << str[i];
        }
    }

/*    void СhoiceBrackets() */

    void DeleteTextInBrackets() {
        char first;
        char second;
        if (bracketsType == 1) {
            first = '(';
            second = ')';
        }
        if (bracketsType == 2) {
            first = '[';
            second = ']';
        }
        if (bracketsType == 3) {
            first = '{';
            second = '}';
        }
        for (int i = 0; i < length; i++) {
            if (str[i] == first) {
                for (int j = i; j < length; j++) {
                    if (str[j] == second) {
                        int tempL = length - ((j - i) + 1);
                        char *temp = new char[tempL];
                        int f = 0;
                        for (; f < i; f++) {
                            temp[f] = str[f];
                        }
                        for (int d = j + 1; d <= length; d++, f++) {
                            temp[f] = str[d];
                        }
                        length = tempL;
                        str = temp;
                    }
                }
            }
        }
    }

};


int main() {
    setlocale(LC_ALL, "ru");
    cout << "Laboratory work number 1" << endl;
    cout << "Completed by a student of the group 0336" << endl;
    cout << "Nasekin S.A." << endl << endl;

    MyString str;
    ifstream input("..\\input.txt");
    if (input.is_open()){
        char* temp = new char[1000];
        input.getline(temp, 1000);
        str.addString(temp);

    } else{
        cout << "File didn't find" << endl;
        return 1;
    }
    input.close();
    cout << "current marker: " << str.MARKER << endl;
    cout << "Original text:" << endl;
    str.Print();
    cout << "Select bracket type: " << endl;
    cout << "1 - () " << endl;
    cout << "2 - [] " << endl;
    cout << "3 - {} " << endl;
    cout << "Your reply: ";
    cin >> str.bracketsType;
    cout << endl << "Modified text:" << endl;
    str.DeleteTextInBrackets();
    str.Print();
    ofstream result("..\\result.txt",ios::out);
    for (int i = 0; str.str[i]!=str.MARKER; ++i) {
        result << str.str[i];
    }
    result.close();
    cout << endl << endl << "Modified text written to file." << endl;
    return 0;
}
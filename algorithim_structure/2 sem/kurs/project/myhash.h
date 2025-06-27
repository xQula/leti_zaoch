#include <ctime>
#include <string>
#include <list>
#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <fstream>
#include <chrono>
using namespace std;
int p = 5; class hasht{
    unordered_set <int> table;
    list <int> al;
public:
    void ShowHash(char N) const; int Fill();
    friend int uset_union(const hasht &A, const hasht &B, hasht &C); friend  int uset_inter(const hasht &A, const hasht &B, hasht &C);
    friend int utransform(const hasht &A, const hasht &B,  hasht &C, int action, int
    pos);
    void FillManualy();
    int size() const {return(table.size() + al.size());}
};
int hasht:: Fill()
{ for(int i = 0; i < p; ++i) al.push_back(rand()%1000);
    al.unique(); list <int> tmp (al); while(!tmp.empty())
    { table.insert(tmp.front()); tmp.pop_front();
    }
    return size();
}
/*void hasht :: FillManualy()
{ int goodstr = 1; char ch[10]; while(goodstr)
{
ShowHash(); cout << "\nHash function will automaticly determinate a position of element.
Just write elements.\nWrite a symbol to stop\n"; cin.get(ch, 10).get();
for(int j = 0; goodstr  && ch[j] != '\0'; ++j) goodstr = isdigit(ch[j]);
if(goodstr)
{ table.emplace(stoi(ch)); al.push_back(stoi(ch));
}
system("cls");
} system("cls"); ShowHash(); cin.get(); cin.get(); system("cls");
}*/
int uset_union(const hasht &A, const hasht &B, hasht &C)
{
    C.al.clear();
    C.table.clear();
    list<int> tmp (A.al);
    list<int> stmp (B.al);
    tmp.sort(); stmp.sort();
    set_union(tmp.begin(), tmp.end(), stmp.begin(), stmp.end(), back_inserter(C.al));
    tmp = C.al; while(!tmp.empty())
    {
        C.table.insert(tmp.front()); tmp.pop_front();
    }
    return C.size();
}
int uset_inter(const hasht &A, const hasht &B, hasht &C)
{
    C.al.clear();
    C.table.clear();
    list<int> tmp (A.al);
    list<int> stmp (B.al);
    stmp.sort(); tmp.sort();
    set_intersection(tmp.begin(), tmp.end(), stmp.begin(), stmp.end(),
                     back_inserter(C.al));
    tmp = C.al; while(!tmp.empty())
    {
        C.table.insert(tmp.front()); tmp.pop_front();
    }
    return C.size();
}
int utransform(const hasht &A, const hasht &B, hasht &C, int action, int pos = 0) // 1 - excl (delete second from first if it includes second), 2 - subst (includes from P position, do not replace stuff), 3 - change (includes from p WITH replacing)
{
    C.al.clear(); C.table.clear();
    switch(action){
        case 1:
        {
//cout << "\nEXCL\n...";
            list<int> Btmp  (B.al);
            list<int> tmp (A.al);
            list <int>:: iterator p;
            p = search(tmp.begin(), tmp.end(), Btmp.begin(), Btmp.end()); for(int i = 0; p!=tmp.end() && i < Btmp.size(); ++i) p = tmp.erase(p); C.al = tmp; while(!tmp.empty())
            {
                C.table.insert(tmp.front()); tmp.pop_front();
            }
//cout << "\nDone!\n";
        } break;
        case 2:
        {
//cout << "\nSUBST...\nEnter the position number to add before ";
list <int> tmp(A.al);
list <int> stmp(B.al);
while(pos && !tmp.empty())
            {
                C.al.push_back(tmp.front());
                C.table.insert(tmp.front()); tmp.pop_front();
                --pos;
            }
            while(!stmp.empty())
            {
                C.al.push_back(stmp.front());
                C.table.insert(stmp.front()); stmp.pop_front();
            }
            while(!tmp.empty())
            {
                C.al.push_back(tmp.front());
                C.table.insert(tmp.front()); tmp.pop_front();
            }
//cout << "\nDone!\n";
        } break;
        case 3:
        {
//cout << "\nCHANGE...\nEnter the position number FROM ";
list <int> tmp(A.al);
list <int> stmp(B.al);
while(pos && !tmp.empty())
            {
                C.al.push_back(tmp.front());
                C.table.insert(tmp.front()); tmp.pop_front();
                --pos;
            }
            while(!stmp.empty())
            {
                C.al.push_back(stmp.front());
                C.table.insert(stmp.front()); stmp.pop_front(); if(!tmp.empty()) tmp.pop_front();
            }
            while(!tmp.empty())
            {
                C.al.push_back(tmp.front());
                C.table.insert(tmp.front()); tmp.pop_front();
            }
        } break;
        default:
//cout << "\nWrong index";
        break;
    }
    return C.size();
}
void hasht :: ShowHash(char N) const{ list <int> tmp;
    cout << "\n" << N << '(' << p << ") = [ "; for(auto q = table.begin(); q != table.end(); ++q) cout << *q << ' ';
    cout << ']'; cout << "\nSequence: <"; tmp = al; while(!tmp.empty())
    { cout << " " << tmp.front(); tmp.pop_front();
    }
    cout << " >\n"; };

#include "myhash.h"
const int U = 6;
int main(){
    srand(time(0));
    fstream out("in.txt");
    if(!out.is_open()) {
        cout << "\nError!"; return(1);
    }
    int q = 300, dp = 2;
    hasht H[U];
    out << static_cast <int> ((q-p)/dp+1);
    do
    { try
        { size_t k = 0, sets = 0; for(int i = 0; i < U; ++i)
            { k += H[i].Fill(); sets++;
            }
            //	for(int i = 0; i < U; ++i)
            //	H[i].ShowHash(i+65);
            auto start_time = std::chrono::steady_clock::now();
// union, inter, excl, sub, change5
        k += uset_union(H[1], H[4], H[3]);
        k += utransform(H[4], H[0], H[2], 3, 5);
        k += utransform(H[0], H[2], H[1], 2, 3);
        k += uset_inter(H[1], H[0], H[4]);
        k += utransform(H[4], H[1], H[1], 1);
        k += utransform(H[2], H[4], H[0], 3, 2);
        k += utransform(H[1], H[0], H[0], 2);
        k += uset_union(H[2], H[3], H[4]);
        k += uset_union(H[0], H[0], H[4]);
        k += utransform(H[3], H[1], H[2], 1);
            auto end_time = std::chrono::steady_clock::now();
            auto elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);//H[4].ShowHash('E');
            k /= sets;
            cout << "\np = " << p << " k = " << k << " Dt = " << elapsed_ns.count();
            out << "\np = " << p << " k = " << k << " Dt = " << elapsed_ns.count();
        } catch(...)
        { cout << "\nCycle error";
        }
    }
    while((p += dp) <= q); out.close(); cin.get(); cin.get(); return 0;
}


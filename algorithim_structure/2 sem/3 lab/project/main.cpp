#include <iostream>
#include <algorithm>
#include <set>
#include <ctime>
#include <iterator>
#include <chrono>
#include <vector>


using namespace std;
using MySet = std::set<int>;
using MyIt = std::set<int>::iterator;
using MySeq = std::vector<MyIt>;

const int lim = 10; //ОГРАНИЧИТЕЛЬ для множества ключей

class MyCont {
    int power;
    char tag;
    MySet A;
    MySeq sA;

    MyCont &operator=(const MyCont &) = delete;
    MyCont &operator=(MyCont &&) = delete;
public:
    MyCont(int, char);
    MyCont(const MyCont &);
    MyCont(MyCont &&);
    MyCont &operator|=(const MyCont &); // объединение
    MyCont operator|(const MyCont &rgt) const {
        MyCont result(*this);
        return (result |= rgt);
    }
    MyCont &operator&=(const MyCont &);  // пересечение
    MyCont operator&(const MyCont &rgt) const {
        MyCont result(*this);
        return (result &= rgt);
    }
    MyCont &operator-=(const MyCont &); // разность
    MyCont operator-(const MyCont &rgt) const {
        MyCont result(*this);
        return (result -= rgt);
    }
    MyCont& operator ^= (const MyCont & rgt); // исключающее или

    // последовательности
    void Merge(const MyCont &);
    void Concat(const MyCont &);
    void Mul(int);
    void Erase(size_t, size_t);
    void Excl(const MyCont &);
    void Subst(const MyCont &, size_t);
    void Change(const MyCont &, size_t);
    void Show() const;

    size_t Power() const { return sA.size(); }

    void PrepareExcl(const MyCont &); // Подготовка excl
    friend void PrepareAnd(MyCont &, MyCont &, int); // подготовка and и sub
};

MyCont::MyCont(int p, char t = 'R') : power(p), tag(t) {
    for (int i = 0; i < power; ++i) {
        sA.push_back(A.insert(std::rand() % lim).first);
    }
}

MyCont::MyCont(MyCont &&source) // Копия "с переносом"
        : power(source.power), tag(source.tag),
          A(std::move(source.A)), sA(std::move(source.sA)) {}

MyCont::MyCont(const MyCont &source) // Конструктор копии
        : power(source.power), tag(source.tag) {
    for (auto x : source.A) sA.push_back(A.insert(x).first);
}

void MyCont::Show() const {
    using std::cout;
    cout << "\n" << tag << ": ";

    for (auto x : A) cout << x << " "; // Выдача множества
    cout << "\n < ";
    for (auto x : sA) cout << *x << " "; // Выдача последовательности
    cout << ">";
}

void PrepareAnd(MyCont &first, MyCont &second, const int quantity) {
    for (int i = 0; i < quantity; ++i) { // Подготовка пересечения:
        int x = rand() % lim;        // добавление общих эл-тов
        first.sA.push_back(first.A.insert(x).first);
        second.sA.push_back(second.A.insert(x).first);
    }
}

MyCont &MyCont::operator-=(const MyCont &rgt) { // Разность мн-в
    MySet temp;
    MySeq stemp;
    for (auto x : A)
        if (rgt.A.find(x) == rgt.A.end())
            stemp.push_back(temp.insert(x).first);
    temp.swap(A);
    stemp.swap(sA);
    return *this;
}

MyCont &MyCont::operator&=(const MyCont &rgt) { // Пересечение
    MySet temp;
    MySeq stemp;
    for (auto x : A)
        if (rgt.A.find(x) != rgt.A.end())
            stemp.push_back(temp.insert(x).first);
    temp.swap(A);
    stemp.swap(sA);
    return *this;
}

MyCont &MyCont::operator|=(const MyCont &rgt) { // Объединение
    for (auto x : rgt.A) sA.push_back(A.insert(x).first);
    return *this;
}

MyCont& MyCont::operator^=( const MyCont & rgt) { // Исключающее ИЛИ
    MySet temp;
    MySeq stemp;

    MySet R;
    MySeq sR;
    // пересечь
    for (auto x : A)
        if (rgt.A.find(x) != rgt.A.end())
            sR.push_back(R.insert(x).first);

    // объединить
    for (auto x : rgt.A) sA.push_back(A.insert(x).first);
    // вычесть
    for (auto x : A)
        if (R.find(x) == R.end())
            stemp.push_back(temp.insert(x).first);

    temp.swap(A);
    stemp.swap(sA);
    return *this;
}

void MyCont::Erase(size_t p, size_t q) { // Исключение фр-та от p до q
    using std::min;
    size_t r(Power());
    p = min(p, r);
    q = min(q + 1, r);
    if (p <= q) {
        MySet temp;
        MySeq stemp;
        for (size_t i = 0; i < p; ++i)
            stemp.push_back(temp.insert(*sA[i]).first);
        for (size_t i = q; i < r; ++i)
            stemp.push_back(temp.insert(*sA[i]).first);
        A.swap(temp);
        sA.swap(stemp);
    }
}

void MyCont::Mul(int k) { // Размножение (не более чем в 5 раз)
    auto p = sA.begin(), q = sA.end();
    if (p != q && (k = k % 5) > 1) { //П ропуск, если мн-во пусто или k < 2
        std::vector<int> temp(A.begin(), A.end());
        MySeq res(sA);
        for (int i = 0; i < k - 1; ++i) {
            std::copy(p, q, back_inserter(res));
            A.insert(temp.begin(), temp.end());
        }
        sA.swap(res);
    }
}

void MyCont::Merge(const MyCont &rgt) { // Слияние
    using std::sort;
    MySeq temp(rgt.sA), res;
    auto le = [](MyIt a, MyIt b) -> bool { return *a < *b; };// Критерий
    sort(sA.begin(), sA.end(), le);
    sort(temp.begin(), temp.end(), le);
    std::merge(sA.begin(), sA.end(), temp.begin(), temp.end(),
               std::back_inserter(res), le); // Слияние для последовательностей...
    A.insert(rgt.A.begin(), rgt.A.end()); // ... и объединение множеств
    sA.swap(res);
}

void MyCont::PrepareExcl(const MyCont &rgt) {
    // Подготовка объекта исключения в пустом контейнере...
    int a = rand() % rgt.Power(), b = rand() % rgt.Power();
    // ... из случайного [a, b] отрезка rgt
    if (b > a) {
        for (int x = a; x <= b; ++x) {
            int y = *(rgt.sA[x]);
            sA.push_back(A.insert(y).first);
        }
    }
}

void MyCont::Excl(const MyCont &rgt) { // Исключение подпоследовательности
    size_t n(Power()), m(rgt.Power());
    if (m)
        for (size_t p = 0; p < n; ++p) { // Поиск первого элемента
            bool f(true);
            // int a(*sA[p]), b(*rgt.sA[0]); //ОТЛАДКА
            if (*sA[p] == *rgt.sA[0]) { // Проверка всей цепочки
                size_t q(p), r(0);
                if (m > 1)
                    do {
                        ++q, ++r;
                        size_t c(*sA[q]), d(*rgt.sA[r]);
                        f &= c == d;
                    } while ((r < m - 1) && f);
                if (f) { // Цепочки совпали, удаляем
                    MySet temp;
                    MySeq stemp;
                    for (size_t i = 0; i < p; ++i)
                        stemp.push_back(temp.insert(*sA[i]).first);
                    for (size_t i = p + m; i < Power(); ++i)
                        stemp.push_back(temp.insert(*sA[i]).first);
                    A.swap(temp);
                    sA.swap(stemp);
                    break;
                }
            }
        }
}

void MyCont::Concat(const MyCont &rgt) { // Сцепление
    for (auto x : rgt.sA) sA.push_back(A.insert(*x).first);
}

void MyCont::Subst(const MyCont &rgt, size_t p) { // Подстановка
    if (p >= Power()) Concat(rgt);
    else {
        MySeq stemp(sA.begin(), sA.begin() + p);    // Начало
        std::copy(rgt.sA.begin(), rgt.sA.end(), back_inserter(stemp)); // Вставка
        std::copy(sA.begin() + p, sA.end(), back_inserter(stemp)); // Окончание
        MySet temp;
        sA.clear();
        for (auto x : stemp) sA.push_back(temp.insert(*x).first);
        A.swap(temp);
    }
}

void MyCont::Change(const MyCont &rgt, size_t p) { // Замена
    if (p >= Power()) Concat(rgt);
    else {
        MySeq stemp(sA.begin(), sA.begin() + p);    // Начало
        std::copy(rgt.sA.begin(), rgt.sA.end(), back_inserter(stemp));
        // Замена
        size_t q = p + rgt.Power();
        if (q < Power())
            std::copy(sA.begin() + q, sA.end(), back_inserter(stemp)); // Окончание
        MySet temp;
        sA.clear();
        for (auto x : stemp) sA.push_back(temp.insert(*x).first);
        A.swap(temp);
    }
}

int main() {
    using std::cout;
    using namespace std::chrono;
    srand((unsigned int) 7); // Пока здесь константа, данные повторяются
    //srand((unsigned int)time(nullptr)); //Разблокировать для случайных данных
    bool debug = true; // false, чтобы запретить отладочный вывод
    auto MaxMul = 5;
    int middle_power = 0, set_count = 0;

    auto Used = [&](MyCont &t) {
        middle_power += t.Power();
        ++set_count;
    };

    auto DebOut = [debug](MyCont &t) {
        if (debug) {
            t.Show();
            cout << " Press <Enter>" << endl;
            // cin.get();
        }
    };

    auto rand = [](int d) {
        return std::rand() % d;
    }; // Лямбда-функция!

    int p = rand(20) + 1; // Текущая мощность (место для цикла по p)
    //=== Данные ===
    MyCont A(p, 'A');
    MyCont B(p, 'B');
    MyCont C(p, 'C');
    MyCont D(p, 'D');
    MyCont E(p, 'E');
    MyCont R(p);

    int q_and(rand(MaxMul) + 1);
    PrepareAnd(A, R, q_and);
    if (debug) B.Show(); Used(B);
    if (debug) C.Show(); Used(C);

    // === Цепочка операций ===
    // (Операция пропускается (skipped!), если аргументы некорректны)
    // Идёт суммирование мощностей множеств и подсчёт их количества,
    // измеряется время выполнения цепочки
     auto t1 = std::chrono::high_resolution_clock::now();

    // 10  A \ (B ∩ C) \ D ⊕ E
    if (debug) cout << endl << "=== B&C === (q_and = " << q_and << ") ";
    B &= C; DebOut(B); Used(B);

    if (debug) A.Show(); Used(A);
    if (debug) cout << endl << "=== A - (B&C) ===";
    A -= B; DebOut(A); Used(A);

    if (debug) D.Show(); Used(D);
    if (debug) cout << endl << "=== A - (B&C) - D ===";
    A -= D; DebOut(A); Used(D);

    if (debug) E.Show(); Used(E);
    if (debug) cout << endl << "=== A – (B&C) – D xor E";
    A ^= D; DebOut(A); Used(A);

    //merge, subst, mul
    R.Show(); Used(R);

    if (debug) cout << endl << "=== R.Mul(F) ===";
    R.Show(); Used(E);
    R.Mul(2);   DebOut(R); Used(R);

    if (debug) cout << endl << "=== R.Merge(F) ===";
    R.Show(); Used(E);
    R.Merge(E);   DebOut(R);   Used(R);

    int e = rand(R.Power());
    if (debug) cout << endl << "=== R.Subst(F) ===";
    R.Show(); Used(E);
    R.Subst(E, e);   DebOut(R);    Used(R);

     auto t2 = std::chrono::high_resolution_clock::now();
     auto dt = duration_cast<duration<double>>(t2 - t1);
     middle_power /= set_count;
     cout << "\n=== Ready === \n(Power = " << p << " Set_count = " << set_count << " Middle_power = " << middle_power << " DT=" << (dt.count()) << ")\n";

    // cin.get();
    return 0;
}

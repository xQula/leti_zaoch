#pragma warning(disable: 4996)
#include <iostream>
#include <bitset>
#include <concepts>
#include <vector>

#if defined _WIN64

#include <windows.h>

namespace {
    constexpr int CHAR_BITS = 8;
    constexpr int TIME = 700;
    constexpr int X1 = 10;
    constexpr int X2 = 70;
    constexpr int Y1 = 15;
    constexpr int Y2 = 20;
}

using BitsetFLoat = std::bitset<sizeof(float)* CHAR_BITS>;
using BitsetLong = std::bitset<sizeof(long)* CHAR_BITS>;

template <typename T>
concept isMyBitset = std::is_same_v<T, BitsetFLoat> || std::is_same_v<T, BitsetLong>;

template<typename T>
concept isMyType = std::is_same_v<T, float> || std::is_same_v<T, long>;

template<isMyBitset T>
auto outBitsetFloat(const T& var) -> void;

union
{
    float input; // assumes sizeof(float) == sizeof(int)
    int   output;
} data;

enum class ConsoleColor
{
    Black = 0,
    Blue = 1,
    Green = 2,
    Cyan = 3,
    Red = 4,
    Magenta = 5,
    Brown = 6,
    LightGray = 7,
    DarkGray = 8,
    LightBlue = 9,
    LightGreen = 10,
    LightCyan = 11,
    LightRed = 12,
    LightMagenta = 13,
    Yellow = 14,
    White = 15,
    MAX_COUNT = 16
};

auto gotoxy(const int x, const int y) -> void
{
    COORD point;
    point.X = x;
    point.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}

// Устанавливает цвет текста и фона в консоли
auto SetColorOutput(const int text, const int background, const bool console) -> void
{
    if (console)
    {
        char color[] = "color 00";
        itoa(background, color + 6, 16);
        itoa(text, color + 7, 16);
        system(color);
    }
    else
    {
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
    }
}

auto GetScroll(const size_t sx, const size_t sy, const size_t sxx, const size_t syy, const int dx, const int dy) -> void
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE); // Установка дескрпитора  экранного буффера
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo; // Информация о буффере экрана
    GetConsoleScreenBufferInfo(hStdout, &csbiInfo);
    SMALL_RECT srctScrollRect; // Область 	перемещаемая
    if (sx != NULL)
        srctScrollRect.Left = sx;
    else
        srctScrollRect.Left = 0;
    if (sxx != NULL)
        srctScrollRect.Right = sxx;
    else
        srctScrollRect.Right = csbiInfo.dwSize.X;
    if (sy != NULL)
        srctScrollRect.Top = sy;
    else
        srctScrollRect.Top = 0;
    if (syy != NULL)
        srctScrollRect.Bottom = syy;
    else
        srctScrollRect.Bottom = csbiInfo.dwSize.Y;
    COORD coordDest; // Координаты перемещения
    coordDest.X = 0 + dx;
    coordDest.Y = 0 + dy;
    SMALL_RECT srctClipRect; // Область отсечения (для неизменности результата равна области перемещаемой)
    srctClipRect = srctScrollRect;
    CHAR_INFO chiFill; // Символ-заполнитель для области вне перемещаемой области
    chiFill.Attributes = 0 | 0;
    chiFill.Char.UnicodeChar = '*';
    ScrollConsoleScreenBuffer(hStdout, &srctScrollRect, &srctClipRect, coordDest, &chiFill); // Прокрутка
}

template<isMyBitset T>
auto GetPrintColor(const int text, const int background, const T& info) -> void
{
    switch (static_cast<ConsoleColor>(background))
    {
        case ConsoleColor::Black:			std::cout << "1 ";   break;
        case ConsoleColor::Blue:			std::cout << "2 ";   break;
        case ConsoleColor::Green:			std::cout << "3 ";   break;
        case ConsoleColor::Cyan:			std::cout << "4 ";   break;
        case ConsoleColor::Red:			std::cout << "5 ";   break;
        case ConsoleColor::Magenta:		std::cout << "6 ";   break;
        case ConsoleColor::Brown:			std::cout << "7 ";   break;
        case ConsoleColor::LightGray:		std::cout << "8 ";   break;
        case ConsoleColor::DarkGray:		std::cout << "9 ";   break;
        case ConsoleColor::LightBlue:		std::cout << "10 ";  break;
        case ConsoleColor::LightGreen:	std::cout << "11 ";  break;
        case ConsoleColor::LightCyan:		std::cout << "12 ";  break;
        case ConsoleColor::LightRed:		std::cout << "13 ";  break;
        case ConsoleColor::LightMagenta:	std::cout << "14 ";  break;
        case ConsoleColor::Yellow:		std::cout << "15 ";  break;
        case ConsoleColor::White:			std::cout << "16 ";  break;
    }
    switch (static_cast<ConsoleColor>(text))
    {
        case ConsoleColor::Black:
            std::cout << "Black          ";
            break;
        case ConsoleColor::Blue:
            std::cout << "Blue           ";
            break;
        case ConsoleColor::Green:
            std::cout << "Green          ";
            break;
        case ConsoleColor::Cyan:
            std::cout << "Cyan           ";
            break;
        case ConsoleColor::Red:
            std::cout << "Red            ";
            break;
        case ConsoleColor::Magenta:
            std::cout << "Magenta        ";
            break;
        case ConsoleColor::Brown:
            std::cout << "Brown          ";
            break;
        case ConsoleColor::LightGray:
            std::cout << "LightGray      ";
            break;
        case ConsoleColor::DarkGray:
            std::cout << "DarkGray       ";
            break;
        case ConsoleColor::LightBlue:
            std::cout << "LightBlue      ";
            break;
        case ConsoleColor::LightGreen:
            std::cout << "LightGreen     ";
            break;
        case ConsoleColor::LightCyan:
            std::cout << "LightCyan      ";
            break;
        case ConsoleColor::LightRed:
            std::cout << "LightRed       ";
            break;
        case ConsoleColor::LightMagenta:
            std::cout << "LightMagenta   ";  // Светло-пурпурный - место в консоли не хватает, пусть будет так
            break;
        case ConsoleColor::Yellow:
            std::cout << "Yellow         ";
            break;
        case ConsoleColor::White:
            std::cout << "White          ";
            break;
    }
    outBitsetFloat(info);
}

auto createBitset(const float var) -> BitsetFLoat
{
    data.input = var;
    return (data.output);
}

auto createBitset(const long var) -> BitsetLong
{
    return (var);
}

template<isMyBitset T>
auto outBitsetFloat(const T& var) -> void
{
    gotoxy(0, 0);
    std::cout << var << std::endl;
}

template<isMyBitset T>
auto swapGroupBits(const int posFirst, const int posSecond, const int sizeGroup, T& var) -> void
{
    if (var.size() < posFirst || var.size() < posSecond) {
        throw std::out_of_range("Invalid position");
    }
    if (posFirst + sizeGroup > var.size() || posSecond + sizeGroup > var.size()) {
        throw std::out_of_range("Invalid group size");
    }
    for (int i = 0; i < sizeGroup; i++) {
        const auto tmp = static_cast<int>(var[posFirst + i]);
        var[posFirst + i] = var[posSecond + i];
        var[posSecond + i] = tmp;
    }
}

template<isMyType T>
auto startProgram() -> void
{
    std::cout << "Entering number: ";
    T var;
    std::cin >> var;
    const auto bitset = createBitset(var);
    system("cls");
    for (int background = 0; background <= static_cast<int>(ConsoleColor::MAX_COUNT); background++)
    {
        for (int text = 0; text <= static_cast<int>(ConsoleColor::MAX_COUNT); text++)
        {
            gotoxy(65, 0);
            SetColorOutput(text, background, false);
            GetPrintColor(text, background, bitset);
            // GetScroll(Left, top,right,bottom, dx, dy Координаты перемещения)
            GetScroll(::X1, ::Y1, ::X2, ::Y2, 0, 0);
            Sleep(::TIME); // ШАГ Т (время в милисекундах)
        }
        SetColorOutput(15, 0, false);
        system("cls");
    }
    gotoxy(0, 0);
}
int main()
{
    try {
        if (const auto choice = []() -> int {
                std::cout << "Choice type: 1 - float, 2 - long: ";
                int choiceTmp;
                std::cin >> choiceTmp;
                return choiceTmp;
            }(); choice == 1) {
            startProgram<float>();
        }
        else if (choice == 2) {
            startProgram<long>();
        }
        else {
            std::cout << "Invalid choice" << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cout << e.what();
    }
}

#endif
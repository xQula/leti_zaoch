#include <iostream>
#include <bitset>
#include <concepts>

namespace {
  constexpr int CHAR_BITS = 8;
}

using BitsetFLoat = std::bitset<sizeof(float) * CHAR_BITS>;
using BitsetLong = std::bitset<sizeof(long) * CHAR_BITS>;

template <typename T>
concept isMyBitset = std::is_same_v<T, BitsetFLoat> || std::is_same_v<T, BitsetLong>;

template<typename T>
concept isMyType = std::is_same_v<T, float> || std::is_same_v<T, long>;

union
{
  float input; // assumes sizeof(float) == sizeof(int)
  int   output;
} data;

template <typename T>
// requires std::is_integral_v<T>
auto print_bits(T value) -> void
{
  std::cout << value << std::endl;
  std::cout << "{ ";
  for (int i = 0; i < sizeof(T) * CHAR_BITS; i++)
  {
    std::cout << (value & (1 << i) ? "1" : "0");
    if (i != sizeof(T) * CHAR_BITS - 1) std::cout << "|";
  }
  std::cout << " }" << std::endl;
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
auto outBitsetFloat(const T &var) -> void
{
  std::cout << var << std::endl;
}

template<isMyBitset T>
auto swapGroupBits(const int posFirst, const int posSecond, const int sizeGroup, T& var) -> void
{
  if(var.size() < posFirst || var.size() < posSecond) {
    throw std::out_of_range("Invalid position");
  }
  if(posFirst + sizeGroup > var.size() || posSecond + sizeGroup > var.size()) {
    throw std::out_of_range("Invalid group size");
  }
  for(int i = 0; i < sizeGroup; i++) {
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
  auto varBitset = createBitset(var);
  outBitsetFloat(varBitset);
  std::cout << "Entering position first bit: ";
  int posFirst;
  std::cin >> posFirst;
  std::cout << "Entering position second bit: ";
  int posSecond;
  std::cin >> posSecond;
  std::cout << "Entering group size: ";
  int sizeGroup;
  std::cin >> sizeGroup;
  swapGroupBits(posFirst, posSecond, sizeGroup, varBitset);
  outBitsetFloat(varBitset);
}
int main()
{
  try {
    if(const auto choice = []() -> int {
      std::cout << "Choice type: 1 - float, 2 - long: ";
      int choiceTmp;
      std::cin >> choiceTmp;
      return choiceTmp;
    }(); choice == 1) {
      startProgram<float>();
    }
    else if(choice == 2) {
      startProgram<long>();
    }else {
      std::cout << "Invalid choice" << std::endl;
    }
  }catch (const std::exception& e) {
    std::cout << e.what();
  }
}
#include <iostream>
#include "workFile/WorkFile.h"

int main()
{
   try {
       WorkFile workFile;
       workFile.readToFile();
       workFile.saveToFile();
   }catch (std::logic_error &ex) {
       std::cout << ex.what() << std::endl;
   }
}

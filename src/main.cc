#include <iostream>

#include "tetra.hh"

int main(int argc, char** argv) {
  std::cout << "Hello World!" << std::endl;
  for (int i = 0; i < argc; ++i)
    std::cout << argv[i] << std::endl;
}

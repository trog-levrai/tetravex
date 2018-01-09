#include <iostream>

#include "grid.hh"

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cout << "Usage: ./tetravex GRID_SIZE" << std::endl;
    return 1;
  }
  size_t s = atoi(argv[1]);
  auto grid = std::vector<std::vector<Tetra>>();
  for (size_t i = 0; i < s; ++i) {
    grid.push_back(std::vector<Tetra>());
    for (size_t j = 0; j < s; ++j) {
      grid[i].push_back(Tetra(1, 2, 3, 4));
    }
  }
  auto g = Grid(grid);
  g.print();
  return 0;
}

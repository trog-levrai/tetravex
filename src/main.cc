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
    for (size_t j = 0; j < s; ++j)
      grid[i].push_back(Tetra(j, i, j + 1, i + 1));
  }
  auto g = Grid(grid);
  g.print();
  auto r = g.random_grid();
  r.print();
  std::cout << g.get_err() << std::endl;
  std::cout << r.get_err() << std::endl;
  return 0;
}

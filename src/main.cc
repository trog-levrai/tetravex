#include <iostream>
#include <fstream>

#include "grid.hh"

Grid read_grid(size_t s, std::string path) {
  std::ifstream file(path);
  int u, r, d, l;
  auto grid = std::vector<std::vector<Tetra>>();
  for (size_t i = 0; i < s; ++i) {
    grid.push_back(std::vector<Tetra>());
    for (size_t j = 0; j < s; ++j) {
      file >> u >> r >> d >> l;
      grid[i].push_back(Tetra(u, r, d, l));
    }
  }
  return Grid(grid);
}

int main(int argc, char** argv) {
  std::srand(time(0));
  if (argc != 3) {
    std::cout << "Usage: ./tetravex GRID_SIZE" << std::endl;
    return 1;
  }
  size_t s = atoi(argv[1]);
  auto g = read_grid(s, argv[2]);
  g.print();
  auto r = g.random_grid();
  r.print();
  std::cout << g.get_err() << std::endl;
  std::cout << r.get_err() << std::endl;
  return 0;
}

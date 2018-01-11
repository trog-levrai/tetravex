#include <iostream>
#include <fstream>
#include <math.h>

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

bool temp_test(double temp, size_t diff) {
  double random = ((double)std::rand() / RAND_MAX);
  return random < exp(-diff / temp);
}

int main(int argc, char** argv) {
  std::srand(time(0));
  if (argc != 3) {
    std::cout << "Usage: ./tetravex GRID_SIZE path/to/grid.grid" << std::endl;
    return 1;
  }

  double T = 1.;
  size_t s = atoi(argv[1]);
  auto g = read_grid(s, argv[2]).random_grid();
  g.print();

  auto err = g.get_err();
  size_t i = 0;
  while (err != 0) {
    auto r = Grid(g);
    r.swap_tetra();
    auto nerr = r.get_err();
    if (nerr < err || temp_test(T, err - nerr)) {
      err = nerr;
      g = r;
      g.print();
      T *= 0.99;
    }
    ++i;
  }

  std::cout << "Solution found in " << i << " iterations!" << std::endl;
  return 0;
}

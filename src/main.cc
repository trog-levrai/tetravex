#include <iostream>
#include <fstream>
#include <math.h>
#include <string>

#include "grid.hh"

Grid read_grid(size_t s, std::string path) {
  std::ifstream file(path);
  auto grid = std::vector<std::vector<Tetra>>();
  for (size_t i = 0; i < s; ++i) {
    grid.push_back(std::vector<Tetra>());
    for (size_t j = 0; j < s; ++j) {
      int t;
      file >> t;
      int l = t % 10;
      t /= 10;
      int d = t % 10;
      t /= 10;
      int r = t % 10;
      t /= 10;
      int u = t % 10;
      grid[i].push_back(Tetra(u, r, d, l));
      file.get();
    }
  }
  return Grid(grid);
}

bool temp_test(double temp, int diff) {
  double random = ((double)std::rand() / RAND_MAX);
  return random < exp(-((.0001 + diff) / temp));
}

int main(int argc, char** argv) {
  std::srand(time(0));
  if (argc != 3) {
    std::cout << "Usage: ./tetravex GRID_SIZE path/to/grid.grid" << std::endl;
    return 1;
  }

  double T = 1.;
  size_t s = atoi(argv[1]);
  auto g = read_grid(s, argv[2]);

  auto err = g.get_err();
  size_t i = 0;
  while (err != 0) {
    auto r = Grid(g);
    r.swap_tetra();
    auto nerr = r.get_err();
    if (nerr < err || temp_test(T, nerr - err)) {
      // Acceptance
      err = nerr;
      g = r;
      T *= 0.9999;
      i = 0;
    } else if (i >= 5000) {
      //Temperature increase if stuck too long
      T *= 50000.;
      i = 0;
    }
    ++i;
  }
  g.print();
}

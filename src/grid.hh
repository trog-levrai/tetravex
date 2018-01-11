#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

#include "tetra.hh"

class Grid {
  public:
    Grid(std::vector<std::vector<Tetra>> grid)
    : grid_(grid)
    {};
    Grid(const Grid& g)
    : grid_(g.grid_)
    {};
    void print() const;
    size_t get_err() const;
    Grid random_grid() const;

  private:
    std::vector<std::vector<Tetra>> grid_;
};

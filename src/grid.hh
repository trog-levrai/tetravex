#pragma once

#include <iostream>
#include <vector>

#include "tetra.hh"

class Grid {
  public:
    Grid(std::vector<std::vector<Tetra>> grid)
    : grid_(grid)
    {};
    void print() const;
    size_t get_err() const;
  private:
    std::vector<std::vector<Tetra>> grid_;
};

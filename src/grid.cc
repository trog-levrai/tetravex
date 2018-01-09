#include "grid.hh"

void Grid::print() const {
  for (size_t i = 0; i < 1 + 4 * grid_.size(); ++i)
    std::cout << "-";
  std::cout << std::endl;
  for (size_t i = 0; i < grid_.size(); ++i) {
    //Printing the top figure
    for (size_t j = 0; j < grid_.size(); ++j)
      std::cout << "| " << grid_[i][j].up << " ";
    std::cout << "|" << std::endl;
    //Printing the middle figures
    for (size_t j = 0; j < grid_.size(); ++j)
      std::cout << "|" << grid_[i][j].left << " " << grid_[i][j].right;
    std::cout << "|" << std::endl;
    //Printing the bottom figure
    for (size_t j = 0; j < grid_.size(); ++j)
      std::cout << "| " << grid_[i][j].down << " ";
    std::cout << "|" << std::endl;
    //Printing Tetra line separation
    for (size_t i = 0; i < 1 + 4 * grid_.size(); ++i)
      std::cout << "-";
    std::cout << std::endl;
  }
}

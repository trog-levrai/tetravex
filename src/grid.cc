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

size_t Grid::get_err() const {
  size_t ans = 0;

  //Counting errors for columns
  for (size_t i = 0; i < grid_.size(); ++i) {
    for (size_t j = 0; j < grid_.size() - 1; ++j)
      ans += grid_[i][j].down == grid_[i][j + 1].up ? 0 : 1;
  }

  //Counting errors for rows
  for (size_t i = 0; i < grid_.size() - 1; ++i) {
    for (size_t j = 0; j < grid_.size(); ++j)
      ans += grid_[i][j].right == grid_[i + 1][j].left ? 0 : 1;
  }
  return ans;
}

Grid Grid::random_grid() const {
  auto ans = Grid(*this);
  for (size_t i = 0; i < ans.grid_.size(); ++i)
    std::random_shuffle(ans.grid_[i].begin(), ans.grid_[i].end());
  std::random_shuffle(ans.grid_.begin(), ans.grid_.end());
  return ans;
}

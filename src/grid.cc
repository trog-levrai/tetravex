#include "grid.hh"

void Grid::print() const {
  std::cout << std::endl;
  for (size_t i = 0; i < grid_.size(); ++i) {
    //Printing the top figure
    std::cout << " ";
    for (size_t j = 0; j < grid_.size(); ++j) {
      std::cout << grid_[i][j].up;
      if (j != grid_.size() - 1)
        std::cout << "   ";
    }
    std::cout << std::endl;
    //Printing the middle figures
    for (size_t j = 0; j < grid_.size(); ++j) {
      std::cout << grid_[i][j].left << " " << grid_[i][j].right;
      if (j != grid_.size() - 1)
        std::cout << " ";
    }
    std::cout << std::endl;
    //Printing the bottom figure
    std::cout << " ";
    for (size_t j = 0; j < grid_.size(); ++j) {
      std::cout << grid_[i][j].down;
      if (j != grid_.size() - 1)
        std::cout << "   ";
    }
    std::cout << std::endl;
    //Printing Tetra line separation
  }
}

size_t Grid::get_err() const {
  size_t ans = 0;

  //Counting errors for columns
  for (size_t i = 0; i < grid_.size(); ++i) {
    for (size_t j = 0; j < grid_.size() - 1; ++j)
      ans += grid_[i][j].right == grid_[i][j + 1].left ? 0 : 1;
  }

  //Counting errors for rows
  for (size_t i = 0; i < grid_.size() - 1; ++i) {
    for (size_t j = 0; j < grid_.size(); ++j)
      ans += grid_[i][j].down == grid_[i + 1][j].up ? 0 : 1;
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

void Grid::swap_tetra() {
  size_t x1 = std::rand() % grid_.size();
  size_t y1 = std::rand() % grid_.size();
  size_t x2 = std::rand() % grid_.size();
  size_t y2 = std::rand() % grid_.size();
  auto aux = grid_[x1][y1];
  grid_[x1][y1] = grid_[x2][y2];
  grid_[x2][y2] = aux;
}

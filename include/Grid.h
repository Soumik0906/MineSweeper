//
// Created by soumik on 11/28/24.
//
#ifndef GRID_H
#define GRID_H

#include "Cell.h"
#include <vector>
#include <SFML/Graphics.hpp>

class Grid {
private:
    std::vector<std::vector<Cell>> cells;
    int rows, cols;
    int totalMines;

    void initializeGrid();
    [[nodiscard]] int countAdjacentMines(int row, int col) const;

public:
    Grid(int rows, int cols, int totalMines);

    void draw(sf::RenderWindow& window, sf::Font& font) const;
    void revealCell(int row, int col);
    Cell& getCellAt(int row, int col);
    [[nodiscard]] int getRows() const;
    [[nodiscard]] int getCols() const;
    [[nodiscard]] int getMines() const;
};

#endif
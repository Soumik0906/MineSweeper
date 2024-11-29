//
// Created by soumik on 11/28/24.
//

#ifndef CELL_H
#define CELL_H

#include <SFML/Graphics.hpp>

class Cell {
public:
    enum State { Hidden, Revealed, Marked };

    bool isMine;            // True if the cell contains a mine
    int adjacentMines;      // Number of adjacent mines
    State state;            // Current state of the cell
    sf::Vector2i position;  // Position of the cell in the grid

    // Constructor
    Cell(int x, int y);

    // Methods
    void reveal();
    void toggle();
};

#endif // CELL_H

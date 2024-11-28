//
// Created by soumik on 11/28/24.
//

#ifndef GRID_H
#define GRID_H

#include "Grid.h"
#include "Constants.h"
#include <random>

Grid::Grid(const int rows, const int cols, const int totalMines)
    : rows(rows), cols(cols), totalMines(totalMines) {
    cells.resize(rows, std::vector<Cell>(cols, Cell(0, 0)));
    initializeGrid();
}

void Grid::initializeGrid() {
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> distRow(0, rows - 1);
    std::uniform_int_distribution<int> distCol(0, cols - 1);

    int placedMines = 0;
    while (placedMines < totalMines) {
        const int r { distRow(rng) };
        const int c { distCol(rng) };
        if (!cells[r][c].isMine) {
            cells[r][c].isMine = true;
            ++placedMines;
        }
    }

    // Calculate adjacent mines
    for (int r { 0 }; r < rows; ++r) {
        for (int c { 0 }; c < cols; ++c) {
            if (!cells[r][c].isMine) {
                cells[r][c].adjacentMines = countAdjacentMines(r, c);
            }
        }
    }
}

int Grid::countAdjacentMines(const int row, const int col) const {
    int count { 0 };
    for (int dr { -1 }; dr <= 1; ++dr) {
        for (int dc { -1 }; dc <= 1; ++dc) {
            const int nr { row + dr };
            const int nc { col + dc };
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                if (cells[nr][nc].isMine) {
                    ++count;
                }
            }
        }
    }
    return count;
}

// draw the grid
void Grid::draw(sf::RenderWindow& window, sf::Font& font) const {
    for (int r { 0 }; r < rows; ++r) {
        for (int c { 0 }; c < cols; ++c) {
            sf::RectangleShape cellShape(sf::Vector2f(CELL_SIZE - 2, CELL_SIZE - 2));
            cellShape.setPosition(c * CELL_SIZE, r * CELL_SIZE);

            if (cells[r][c].state == Cell::Revealed) {
                cellShape.setFillColor(sf::Color::White);
                if (cells[r][c].isMine) {
                    cellShape.setFillColor(sf::Color::Red);
                }
            } else if (cells[r][c].state == Cell::Marked) {
                cellShape.setFillColor(sf::Color::Blue);
            } else {
                cellShape.setFillColor(sf::Color::Green);
            }

            window.draw(cellShape);

            if (cells[r][c].state == Cell::Revealed && cells[r][c].adjacentMines > 0 && !cells[r][c].isMine) {
                sf::Text text{};
                text.setFont(font);
                text.setString(std::to_string(cells[r][c].adjacentMines));
                text.setCharacterSize(CELL_SIZE / 3);
                text.setFillColor(sf::Color::Black);

                // Center the text
                sf::FloatRect textBounds { text.getLocalBounds() };

                text.setOrigin(textBounds.left + textBounds.width / 2.0f,
                textBounds.top + textBounds.height / 2.0f);

                text.setPosition(c * CELL_SIZE + CELL_SIZE / 2.0f,
                    r * CELL_SIZE + CELL_SIZE / 2.0f);

                window.draw(text);
            }
        }
    }
}

Cell& Grid::getCellAt(const int row, const int col) {
    return cells[row][col];
}

int Grid::getRows() const {
    return rows;
}

int Grid::getCols() const {
    return cols;
}

int Grid::getMines() const {
    return totalMines;
}

#endif
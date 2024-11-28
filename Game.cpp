//
// Created by soumik on 11/28/24.
//

#include "Game.h"
#include <iostream>
#include "Constants.h"

Game::Game(const int rows, const int cols, const int totalMines)
    : grid(rows, cols, totalMines), state(Playing) {}

void Game::handleInput(const sf::Event& event) {
    if (event.type == sf::Event::MouseButtonPressed) {
        const int col { event.mouseButton.x / CELL_SIZE };
        const int row { event.mouseButton.y / CELL_SIZE };

        if (row >= 0 && row < grid.getRows() && col >= 0 && col < grid.getCols()) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                grid.revealCell(row, col);
                if (grid.getCellAt(row, col).isMine) {
                    state = Lost;
                }
            } else if (event.mouseButton.button == sf::Mouse::Right) {
                grid.getCellAt(row, col).mark();
            }
        }
    }
}

void Game::update() {
    if (state == Playing) {
        int revealedCells { 0 };
        const int totalCells { grid.getRows() * grid.getCols() };
        for (int r { 0 }; r < grid.getRows(); r++) {
            for (int c { 0 }; c < grid.getCols(); c++) {
                if (grid.getCellAt(r, c).state == Cell::Revealed) {
                    ++revealedCells;
                }
            }
        }
        if (revealedCells == totalCells - grid.getMines()) {
            state = Won;
        }
    }
}

void Game::draw(sf::RenderWindow& window, sf::Font& font) {
    grid.draw(window, font);

    if (state == Lost) {
        std::cout << "LOST" << std::endl;
    } else if (state == Won) {
        std::cout << "WON" << std::endl;
    }
}
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Constants.h"
#include <iostream>

int main() {
    constexpr int GRID_ROWS = 12;
    constexpr int GRID_COLS = 12;
    constexpr int totalMines = 20;

    sf::RenderWindow window(sf::VideoMode(GRID_COLS * CELL_SIZE, GRID_ROWS * CELL_SIZE), "Minesweeper");
    sf::Font font;
    if (!font.loadFromFile("../resources/Arial.ttf")) {
        std::cerr << "Failed to load font." << std::endl;
        return -1;
    }

    Game game(GRID_ROWS, GRID_COLS, totalMines);

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            game.handleInput(event);
        }

        game.update();

        window.clear();
        game.draw(window, font);
        window.display();
    }

    return 0;
}

//
// Created by soumik on 11/28/24.
//

#ifndef GAME_H
#define GAME_H

#include "Grid.h"

class Game {
private:
    Grid grid;
    enum State { Playing, Won, Lost } state;

public:
    //Constructor
    Game(int rows, int cols, int totalMines);

    // Methods
    void handleInput(const sf::Event& event);
    void update();
    void draw(sf::RenderWindow& window, sf::Font& font);
};

#endif //GAME_H

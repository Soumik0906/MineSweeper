//
// Created by soumik on 11/28/24.
//

#include "Cell.h"

Cell::Cell(const int x, const int y)
    : isMine(false), adjacentMines(0), state(Hidden), position(x, y) {}

void Cell::reveal()  {
  state = Revealed;
}

void Cell::toggle() {
    state = (state == Hidden) ? Marked : Hidden;
}

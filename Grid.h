//
// Created by a on 6/24/21.
//

#ifndef GAME_OF_LIFE_GRID_H
#define GAME_OF_LIFE_GRID_H

#include "Cell.h"
#include <array>

using namespace std;

template <size_t N_cells>  /* Declares Grid as a template type- must be instantiated like 'Grid<100>' */
class Grid {
private:
    size_t size = N_cells;
    array<Cell, N_cells> cells; /* Note: this calls the default constructor of Cell * N_cells times */
public:
    Grid() { };
    ~Grid() = default;

    size_t get_size() {
        return this->size;
    }
};


#endif //GAME_OF_LIFE_GRID_H

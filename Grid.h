//
// Created by a on 6/24/21.
//

#ifndef GAME_OF_LIFE_GRID_H
#define GAME_OF_LIFE_GRID_H

#include "Cell.h"
#include <array>
#include <map>  /* Python-dict equiv */

using namespace std;

typedef pair<size_t, size_t> point;

template <size_t wid, size_t hgt>  /* Declares Grid as a template type- must be instantiated like 'Grid<100>' */
class Grid {
private:
    size_t width = wid;
    size_t height = hgt;
    size_t size = wid*hgt;
    array<Cell, wid*hgt> cells; /* Note: this calls the default constructor of Cell * N_cells times */
public:
    Grid() { };
    ~Grid() = default;

    size_t get_size() {
        return this->size;
    }

    /* Convert Coordinate to index in cells array */
    size_t get_index(point pt) {
        return pt.first * pt.second;
    }

    /* Get Cell object given array index */
    Cell* get_cell(size_t i) {
        return &cells.at(i);
    }

    /* Get Cell object given coordinate pair */
    Cell* get_cell(point pt) {  /* Return as reference */
        return &cells[get_index(pt)];
    }


};


#endif //GAME_OF_LIFE_GRID_H

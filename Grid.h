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

template<size_t wid, size_t hgt>  /* Declares Grid as a template type- must be instantiated like 'Grid<100>' */
class Grid {
private:
    size_t width = wid;
    size_t height = hgt;
    size_t size = wid * hgt;
    array<Cell, wid * hgt> cells; /* Note: this calls the default constructor of Cell * N_cells times */
public:
    Grid() {};

    ~Grid() = default;

    size_t get_size() {
        return this->size;
    }

    /* Convert Coordinate to index in cells array */
    size_t get_index(point pt) {
        return pt.first + pt.second * this->width;
    }

    /* Get Cell object given array index */
    Cell *get_cell(size_t i) {
        return &cells.at(i);
    }

    /* Get Cell object given coordinate pair */
    Cell *get_cell(point pt) {  /* Return as reference */
        return &cells[get_index(pt)];
    }

    void update_cells() {
        for (int x = 0; x < this->width; ++x) {
            for (int y = 0; y < this->height; ++y) {
                this->update_cell(x, y);
            }
        }
        /* Swap */
        for (int x = 0; x < this->width; ++x) {
            for (int y = 0; y < this->height; ++y) {
                this->get_cell(point(x,y))->swap_states();
            }
        }
    }

    void update_cell(int x, int y) {
        auto cell = this->get_cell(point(x,y));

        size_t adj_alive = 0;
        /* Check neighbors */
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                if (dx == 0 && dy == 0) continue;
                if (x <= 0 || x >= this->width - 1) continue;
                if (y <= 0 || y >= this->height - 1) continue;
                auto nx = x + dx;
                auto ny = y + dy;
                if (this->get_cell(point(nx,ny))->get_curr_state()) { ++adj_alive; }
            }
        }
        bool is_alive = cell->get_curr_state();
        /* Do Game of Life rules */
        cell->set_prev_state(false);
        if (is_alive) {
            /* 1 Any live cell with fewer than two live neighbours dies, as if by underpopulation. */
            /* 2 Any live cell with two or three live neighbours lives on to the next generation. */
            /* 3 Any live cell with more than three live neighbours dies, as if by overpopulation. */
            if (adj_alive == 2 || adj_alive == 3){ cell->set_prev_state(true); }
        }
        /* 4 Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction. */
        else if (adj_alive == 3) { cell->set_prev_state(true); }
    }
};

#endif //GAME_OF_LIFE_GRID_H

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Cell.h"
#include "Grid.h"
#include <random>
#include <stdlib.h>

using namespace std;

int main() {

    constexpr size_t width = 100;
    constexpr size_t height = 100;
    srand (time(0)); /* Seed rand() based on time */

    auto grid = Grid<width,height>();  /* Note: Templating is required to create a std::array with a dynamic size */
    cout << grid.get_size() << endl;

    /* Init states */
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            if (rand() % 100 < 95) continue;
            /* b.c. Objects are passed by copy by default */
            grid.get_cell( pair<int, int>(x, y) )->set_curr_state(true);;
        }
    }

    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            cout << *(grid.get_cell(pair<int, int>(x, y)));
        }
    }
    return 0;
}

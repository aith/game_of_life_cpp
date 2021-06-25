#include <iostream>
#include <SFML/Graphics.hpp>

#include "Cell.h"
#include "Grid.h"
#include "Render.h"
#include <random>
#include <stdlib.h>

using namespace std;


int main() {

    constexpr size_t width = 300;
    constexpr size_t height = 300;
    constexpr size_t cell_w = 1;
    constexpr size_t cell_h = 1;

    srand (time(0)); /* Seed rand() based on time */

    /* Init Grid */
    auto grid = Grid<width,height>();  /* Note: Templating is required to create a std::array with a dynamic size */
    cout << "size is " << grid.get_size() << endl;

    /* Init states */
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            if (rand() % 100 < 95) continue;
            /* b.c. Objects are passed by copy by default */
            grid.get_cell( pair<int, int>(x, y) )->set_curr_state(true);
        }
    }

    /* Set up Rendering */
    auto render = Render<width,height>();  /* Note: Templating is required to create a std::array with a dynamic size */

    /* Update */
    sf::RenderWindow window(sf::VideoMode(width, height), "SFML works!");
    while (window.isOpen())
    {
        window.clear();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        render.color_cells< Grid<width,height> >(&window, &grid);

        /* Update State */
        grid.update_cells();

        window.display();

    }

    return 0;
}

//
// Created by a on 6/24/21.
//

#ifndef GAME_OF_LIFE_RENDER_H
#define GAME_OF_LIFE_RENDER_H

#include <SFML/Graphics.hpp>
#include <array>
#include <iostream>

template<size_t wid, size_t hgt>
class Render {
private:
    size_t width = wid;
    size_t height = hgt;
    size_t size = wid*hgt;
public:
    Render() {
        for (int i = 0; i < size; ++i) {
        }
    };
    ~Render() = default;

    template<typename Grid>
    void color_cells(sf::RenderWindow* window, Grid* grid) {
//         sf::RectangleShape cell (sf::Vector2<float>(1, 1));
        for (int i = 0; i < grid->get_size(); ++i) {
            sf::RectangleShape cell(sf::Vector2<float>(1,1));  /* This overloads the stack */
            cell.setSize(sf::Vector2f(1,1));

            auto color = sf::Color::Black;
            if (grid->get_cell(i)->get_curr_state()) { color = sf::Color::White; }
            cell.setFillColor(color);

            size_t x = i % this->width;
            size_t y = i / this->width;
            cell.setPosition(x,y);

            window->draw(cell);
        }

    }
};


#endif //GAME_OF_LIFE_RENDER_H

//
// Created by a on 6/24/21.
//

#ifndef GAME_OF_LIFE_CELL_H
#define GAME_OF_LIFE_CELL_H

#include "iostream"

using namespace std;

class Cell {
public:
    Cell() {
        this->curr_state = false;
        this->prev_state = false;
    };

    Cell(bool curr_state, bool prev_state) {
        this->curr_state = curr_state;
        this->prev_state = prev_state;
    };

    bool get_curr_state() const {
        return this->curr_state;
    }

    void set_curr_state(bool new_state) {
        this->curr_state = new_state;
    }

    bool get_prev_state() const {
        return prev_state;
    }

    void set_prev_state(bool new_state) {
        this->prev_state = new_state;
    }

    void swap_states() {
        bool temp = this->prev_state;
        this->prev_state = this->curr_state;
        this->curr_state = temp;
    }

    friend ostream& operator<<(ostream& out, const Cell cell);
private:
    bool curr_state;
    bool prev_state;
};


#endif //GAME_OF_LIFE_CELL_H

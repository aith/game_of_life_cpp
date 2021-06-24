//
// Created by a on 6/24/21.
//

#include "Cell.h"

ostream &operator<<(ostream &out, const Cell cell) {
    out << cell.get_curr_state();
    return out;
}

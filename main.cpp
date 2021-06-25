#include <iostream>

#include "Cell.h"
#include "Grid.h"

using namespace std;

int main() {
    Cell tcell(true,false);
    tcell.set_curr_state(false);
    auto grid = Grid<100>();  /* Note: Templating is required to create a std::array with a dynamic size */
    cout << grid.get_size();
    return 0;
}

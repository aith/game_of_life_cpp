#include <iostream>

#include "Cell.h"

using namespace std;

int main() {
    Cell tcell(true,false);
    cout << tcell.get_curr_state() << endl;
    tcell.set_curr_state(false);
    cout << tcell.get_curr_state() << endl;
    return 0;
}

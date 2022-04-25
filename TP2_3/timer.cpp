#include "timer.h"


Timer::Timer(sc_module_name name) : sc_module(name) {
    SC_THREAD(main);
}

void Timer::main() {
    bool state = true;
    
    while (true) {
        tick = state;
        wait(1, SC_US);
        state = !state;
    }
}

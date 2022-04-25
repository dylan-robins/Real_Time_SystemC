#ifndef __TIMER_H__
#define __TIMER_H__
#include <systemc.h>

#define TIMER_PERIOD 1000

using namespace sc_core;

class Timer : public sc_module {
   private:
    void main();

   public:
    SC_HAS_PROCESS(Timer);

    Timer(sc_module_name name);
    sc_out<bool> tick;
};

#endif
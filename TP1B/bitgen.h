#ifndef bitgen_h
#define bitgen_h

#include <systemc.h>

/* declare the BitGen module */

class BitGen : public sc_module {
   public:
    SC_HAS_PROCESS(BitGen);
    BitGen(sc_module_name name);

   public:
    void thProduce();

   public:
    sc_out<bool> data_out;
    sc_out<bool> rdy;
    sc_in<bool> ack;
};

#endif

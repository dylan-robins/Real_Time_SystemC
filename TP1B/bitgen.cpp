#include "bitgen.h"

#include <fstream>
#include <systemc.h>

/* define the BitGen module */

/* constructor */

BitGen::BitGen(sc_module_name name) : sc_module(name) {
    SC_THREAD(thProduce);
    sensitive << ack.pos();
}

/* definition of the thread thProduce */
void BitGen::thProduce() {
    // Open file
    char c;
    ifstream dataFile("a.txt");
    while (dataFile.read(&c, sizeof(char))) {
        for (char i = 0; i < 8; i++) {            
            // Shift out the i-th bit of the byte
            data_out = (c>>i) & 1;
            wait(2, SC_NS);

            // Indicate that data is available
            rdy = true;
            wait(2, SC_NS);

            // wait for acknowledgement
            if (ack == false) {
                wait();
            }
            wait(2, SC_NS);

            // reset state and wait a bit
            rdy = false;
            wait(2, SC_NS);
        }
    }
}

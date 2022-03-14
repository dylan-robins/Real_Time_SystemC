#include "consumer.h"

#include "systemc.h"
#include <string>
/* define the Consumer module */

/* constructor */

Consumer::Consumer(sc_module_name name) {
    SC_THREAD(thConsume);  // thConsume is a thread
}

void Consumer::thConsume() {
    char c;
    std::string content = "";

    while (true) {
        in->read(c);
        content += c;
        printf("[%lu] Received char %c\n", (unsigned long)sc_simulation_time(), c);
        printf("###   Full message: %s\n", content.c_str());

        wait(20, SC_NS);
    }
}

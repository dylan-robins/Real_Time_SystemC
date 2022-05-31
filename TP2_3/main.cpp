#include <string>

#include "processes.h"
#include "top.h"

int sc_main(int, char**) {
    // create some CPUs and add some processes (tasks) on them

    // instantiate the global trace file
    g_trace_file = sc_create_vcd_trace_file("trace");  // create a trace file
    g_trace_file->set_time_unit(1, SC_NS);

    Top top("top");
    // IntHandler par1(1);
    // IntHandler par2(2);
    // IntHandler par3(3);
    // Proc4ArgumentHandler par4(2, 2, "Hello World!");

    // top.cpu1.AddInitialTask(proc1, (void*)&par1, "cpu1 - proc1");
    // top.cpu1.AddInitialTask(proc2, (void*)&par2, "cpu1 - proc2");

    // top.cpu2.AddInitialTask(proc3, (void*)&par3, "cpu2 - proc3");
    // top.cpu2.AddInitialTask(proc4, (void*)&par4, "cpu2 - proc4");

    auto param = StrHandler("Hello world!");
    auto param_bis = StrHandler("Good-bye planet!");

    top.cpu1.AddInitialTask(proc_emitter, (void *)&param, "emitter_task");
    top.cpu1.AddInitialTask(proc_receiver, NULL, "receiver_task");
    top.cpu1.AddInitialTask(proc_emitter_bis, (void *)&param_bis, "emitter_task");
    sc_start(200000, SC_NS);

    sc_close_vcd_trace_file(g_trace_file);

    return 0;
}

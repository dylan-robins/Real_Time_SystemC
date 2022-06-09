#include "processes.h"

#define CHANBUFSIZE 256
char channels[MAX_CHANNEL][CHANBUFSIZE];

/* file containing the functions implementing the processes (also called tasks) */

bool proc1(Task* task, void* p) {
    IntHandler* par = (IntHandler*)p;
    Proc4ArgumentHandler *par5 = new Proc4ArgumentHandler(10, 10, "Foo Bar!");

    cout << task->m_name << " " << par->i << endl;

    CONSUME(par->i * 100);

    task->m_os->RegisterTask(proc5, (void *)par5, "cpu1 - proc5", 4, false);
    
    return true;
}

bool proc2(Task* task, void* p) {
    IntHandler* par = (IntHandler*)p;

    cout << task->m_name << " " << par->i << endl;

    CONSUME(par->i * 100);
    return true;
}

bool proc3(Task* task, void* p) {
    IntHandler* par = (IntHandler*)p;

    cout << task->m_name << " " << par->i << endl;

    CONSUME(par->i * 100);

    return true;
}

bool proc4(Task* task, void* p) {
    // To be completed
    Proc4ArgumentHandler * par = (Proc4ArgumentHandler *) p;
    std::cout << par->_a << " + " << par->_b << " = " << par->_a + par->_b 
                << ", " << par->_s << std::endl;
    CONSUME(50);
    
    return true;
}

bool proc5(Task* task, void* p) {
    // To be completed
    Proc4ArgumentHandler * par = (Proc4ArgumentHandler *) p;
    std::cout << par->_a << " + " << par->_b << " = " << par->_a + par->_b 
                << ", " << par->_s << std::endl;
    CONSUME(50);

    delete par;

    // Do not restart the process
    return false;
}

bool proc_emitter(Task* task, void* p) {
    const int PROC_CHAN_NUM = 0;
    auto par = (StrHandler*)p;
    std::cout << "[E1] Starting..." << std::endl;

    std::cout << "[E1] Waiting..." << std::endl;
    CONSUME(500);

    // Place message to send in the channel
    strncpy(channels[PROC_CHAN_NUM], par->str, par->len);

    std::cout << "[E1] Sending \"" << channels[PROC_CHAN_NUM] << '"' << std::endl;

    // Send data
    task->m_os->ChanOut(PROC_CHAN_NUM, channels[PROC_CHAN_NUM], CHANBUFSIZE);
    return false;
}

bool proc_emitter_bis(Task* task, void* p) {
    const int PROC_CHAN_NUM = 1;
    auto par = (StrHandler*)p;
    std::cout << "[E2] Starting..." << std::endl;

    // Place message to send in the channel
    strncpy(channels[PROC_CHAN_NUM], par->str, par->len);
    
    std::cout << "[E2] Sending \"" << channels[PROC_CHAN_NUM] << '"' << std::endl;

    // Send data
    task->m_os->ChanOut(PROC_CHAN_NUM, channels[PROC_CHAN_NUM], CHANBUFSIZE);
    return false;
}

bool proc_receiver(Task* task, void* p) {
    int bufSize = CHANBUFSIZE;
    std::cout << "[R] Starting..." << std::endl;

    int usedChannels[2] = {0, 1};

    task->m_os->AltIn(MAX_CHANNEL, usedChannels, channels[0], bufSize, bufSize);
    task->m_os->AltIn(MAX_CHANNEL, usedChannels, channels[1], bufSize, bufSize);
    std::cout << "[R] Read \"" << channels[0] << '"' << std::endl;
    std::cout << "[R] Read \"" << channels[1] << '"' << std::endl;

    return false;
}
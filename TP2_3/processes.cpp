#include "processes.h"

/* file containing the functions implementing the processes (also called tasks) */

bool proc1(Task* task, void* p) {
    IntHandler* par = (IntHandler*)p;

    cout << task->m_name << " " << par->i << endl;

    CONSUME(par->i * 100);

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
    return true;
}

bool proc5(Task* task, void* p) {
    // To be completed

    // Do not restart the process
    return false;
}

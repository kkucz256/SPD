#include "task.h"

int Task::index = 0;

Task::Task(int task_time, int access_time, int rest_time) {
    this->pj = task_time;
    this->rj = access_time;
    this->qj = rest_time;
    this->elem_index = index++;
}

int Task::get_p(){
    return pj;
}

int Task::get_r(){
    return rj;
}

int Task::get_q(){
    return qj;
}

int Task::get_index(){
    return elem_index;
}
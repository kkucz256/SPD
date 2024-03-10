#include "task.h"


Task::Task(int task_time, int access_time, int rest_time) {
    this->pj = task_time;
    this->rj = access_time;
    this->qj = rest_time;
    this->index = Task::j++;
}

int Task::get_p(){
    return this->pj;
}

int Task::get_r(){
    return this->rj;
}

int Task::get_q(){
    return this->qj;
}

int Task::get_index(){
    return this->index;
}
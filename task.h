#ifndef TASK_H
#define TASK_H
#include <string>

class Task {
private:
    int pj;
    int rj;
    int qj;
    int elem_index;
    static int index;
public:
    Task(int access_time, int task_time, int rest_time);
    int get_p();
    int get_r();
    int get_q();
    int get_index();


};


#endif //TASK_H

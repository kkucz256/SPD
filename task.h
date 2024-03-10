#ifndef TASK_H
#define TASK_H


class Task {
private:
    int pj;
    int rj;
    int qj;
    int index;
    int j=0;
public:
    Task(int task_time, int access_time, int rest_time);
    int get_p();
    int get_r();
    int get_q();
    int get_index();

};


#endif //TASK_H

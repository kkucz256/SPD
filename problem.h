#ifndef PROBLEM_H
#define PROBLEM_H
#include <vector>
#include "task.h"

class Problem {
private:
    int n;
    std::vector<Task> instance;
public:
    Problem(int n, std::vector<Task> tasks);
    void sort_q();
    void sort_r();
    void overview();



};


#endif //PROBLEM_H

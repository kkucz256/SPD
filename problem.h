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
    std::vector<Task> sort_q();
    std::vector<Task> sort_r();

    int overview();
};


#endif //PROBLEM_H

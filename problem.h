#ifndef PROBLEM_H
#define PROBLEM_H
#include <vector>
#include "task.h"
#include "result.h"

class Problem {
private:
    int n;
    std::vector<Task> instance;
public:
    Problem(int n, std::vector<Task> tasks);
    Result sort_q();
    Result sort_r();
    Result bruteforce();
    int calculate_cmax();

    std::vector<Task> get_instance();
};


#endif //PROBLEM_H

#ifndef UNTITLED_RESULT_H
#define UNTITLED_RESULT_H


#include <vector>
#include "task.h"

class Result {
private:
    std::vector<Task> best_items;
    int min_cmax;
public:
    Result(std::vector<Task> best_set, int cmax);
    void print_results();
    int get_cmax();
};


#endif //UNTITLED_RESULT_H

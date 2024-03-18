
#include <iostream>
#include "result.h"

Result::Result(std::vector<Task> best_set, int cmax)
{
    this->min_cmax = cmax;
    this->best_items = best_set;
}

void Result::print_results(){
    std::cout <<"The order of tasks: ";
    for(Task task: best_items)
    {
        std::cout << task.get_index() <<" ";
    }
    std::cout<<std::endl;

}

int Result::get_cmax(){
    return min_cmax;
}
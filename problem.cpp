#include <algorithm>
#include <iostream>
#include <math.h>
#include "problem.h"


Problem::Problem(int n, std::vector<Task> tasks){
    this ->instance = tasks;
    this ->n = n;
}

void Problem::sort_q()
{
    std::sort(instance.begin(), instance.end(), [](Task task1, Task task2) {
        return task1.get_q() < task2.get_q();
    });
    std::cout << "\n" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << "Task no: " << instance[i].get_index() << " pj: " << instance[i].get_p() << " rj: " << instance[i].get_r() << " qj: " << instance[i].get_q() << std::endl;
    }

}

void Problem::sort_r() {
    std::sort(instance.begin(), instance.end(), [](Task task1, Task task2) {
        return task1.get_r() < task2.get_r();
    });
    std::cout << "\n" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << "Task no: " << instance[i].get_index() << " pj: " << instance[i].get_p() << " rj: "
                  << instance[i].get_r() << " qj: " << instance[i].get_q() << std::endl;
    }
}

void Problem::overview()
{

}

int finish_time(std::vector<Task>instance, int n)
{
    int prev =0, curr=0;
    for(int i=0; i<n; i++)
    {
        prev = fmax(prev, instance[i].get_r()) + instance[i].get_p();
        curr = fmax(curr, prev + instance[i]. get_q());
    }
    return curr;
}


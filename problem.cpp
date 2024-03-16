#include <algorithm>
#include <iostream>
#include <math.h>
#include "problem.h"


Problem::Problem(int n, std::vector<Task> tasks) {
    this->instance = tasks;
    this->n = n;
}

std::vector<Task> Problem::sort_q() {
    std::sort(instance.begin(), instance.end(), [](Task task1, Task task2) {
        return task1.get_q() < task2.get_q();
    });
    return instance;

}

std::vector<Task> Problem::sort_r() {
    std::sort(instance.begin(), instance.end(), [](Task task1, Task task2) {
        return task1.get_r() < task2.get_r();
    });
    return instance;
}

void displayPermutation(const std::vector<Task>& permutation) {
    for (Task task : permutation) {
        std::cout << "Task " << task.get_index() << ": (r=" << task.get_r() << ", p=" << task.get_p() << ", q=" << task.get_q() << ") ";
    }
    std::cout << std::endl;
}

int Problem::overview() {
    std::vector<Task> temp_instance = instance;
    int min_cmax = 200000;

    do {
        int previous_completion_time = 0;
        int cmax = 0;
        for (Task task : temp_instance) {
            int completion_time = std::max(previous_completion_time, task.get_r()) + task.get_p();
            previous_completion_time = completion_time;
            if (completion_time > cmax) {
                cmax = completion_time;
            }
        }
        if (cmax < min_cmax) {
            min_cmax = cmax;

        }
    } while (std::next_permutation(temp_instance.begin(), temp_instance.end(), [](Task task1, Task task2) {
        return task1.get_index() < task2.get_index();
    }));
    std::cout << "\nMinimum Cmax: " << min_cmax;

    return min_cmax;
}




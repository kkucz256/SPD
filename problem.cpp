#include <algorithm>
#include <math.h>
#include "problem.h"


Problem::Problem(int n, std::vector<Task> tasks) {
    this->instance = tasks;
    this->n = n;
}


//Method to calculate cmax for further use in r sort, q sort and bruteforce according to the formula from lab class
int Problem::calculate_cmax() {
    int t = 0;
    int max_cq = 0;

    for (Task task : instance) {
        t = std::max(t, task.get_r());
        t += task.get_p();
        int cq = t + task.get_q();
        max_cq = std::max(max_cq, cq);
    }

    return max_cq;
}

//Method to sort the list of tasks by the smallest q parameter
Result Problem::sort_q() {
    std::sort(instance.begin(), instance.end(), [](Task task1, Task task2) {
        return task1.get_q() < task2.get_q();
    });
    int cmax = calculate_cmax();
    return Result(instance, cmax);
}

//Method to sort the list of tasks by the smallest r parameter
Result Problem::sort_r() {
    std::sort(instance.begin(), instance.end(), [](Task task1, Task task2) {
        return task1.get_r() < task2.get_r();
    });
    int cmax = calculate_cmax();
    return Result(instance, cmax);
}


//Method for bruteforce that generates n! permutations and finds the most optimal one
Result Problem::bruteforce() {
    int min_cmax = std::numeric_limits<int>::max();
    std::vector<Task> best;

    // Calculating cmax for the current permutation and updating best if it's smaller
    do {
        int cmax = calculate_cmax(); // Calculate cmax for current permutation
        if (cmax < min_cmax) {
            min_cmax = cmax;

            best = instance; // Update the best permutation
        }
    } while (std::next_permutation(instance.begin(), instance.end(), [](Task& task1, Task& task2) {
        return task1.get_index() < task2.get_index();
    }));

    return Result(best, min_cmax);
}

//Getter to return instance for easier printing
std::vector<Task> Problem::get_instance() {
    return instance;
}




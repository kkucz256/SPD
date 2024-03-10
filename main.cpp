#include "task.h"
#include "problem.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<Task> tasks;
    std::cout << "Provide the number of tasks: " << std::endl;
    int n;
    std::cin >> n;

    std::cout <<"Provide the seed: " << std::endl;
    int seed;
    std::cin >> seed;
    srand(seed);

    tasks.reserve(n);
    for(int i=0; i<n; i++)
    {
        tasks.push_back(Task(rand()%10+1,rand()%10+1,rand()%10+1));
    }

    for(int i=0; i<n; i++) {
        std::cout << "Task no: " << tasks[i].get_index() << " pj: "<< tasks[i].get_p() << " rj: "<< tasks[i].get_r() << " qj: "<< tasks[i].get_q() << std::endl;
    }

    Problem problem = Problem(n, tasks);
    problem.sort_q();
    problem.sort_r();

    return 0;
}
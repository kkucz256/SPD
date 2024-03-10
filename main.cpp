#include "task.h"
#include <iostream>

int main() {
    Task myTask(10, 20, 30);

    int taskTime = myTask.get_p();

    std::cout << "Task Time: " << taskTime << std::endl;

    return 0;
}
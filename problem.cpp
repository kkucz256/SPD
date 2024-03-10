#include "problem.h"


Problem::Problem(int n, std::vector<Task> tasks){
    this ->instance = tasks;
    this ->n = n;
}
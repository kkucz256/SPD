#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "task.h"
#include "problem.h"

using namespace std;

int main() {
    string input_file_path = "C:\\Users\\kkucz\\CLionProjects\\zad1_spd\\SCHRAGE1.DAT";
    string output_file_path = "C:\\Users\\kkucz\\CLionProjects\\zad1_spd\\out.DAT";

    ifstream input_file(input_file_path);
    int number;
    input_file >> number;


    vector<Task> tasks;
    tasks.reserve(number);
    for (int i = 0; i < number; i++) {
        int r, p, q;
        input_file >> r >> p >> q;
        tasks.emplace_back(r, p, q);
    }
    input_file.close();

    for (int i = 0; i < number; i++) {
        cout << "Task no: " << tasks[i].get_index() << " rj: " << tasks[i].get_r() << " pj: " << tasks[i].get_p()
             << " qj: " << tasks[i].get_q() << endl;
    }

    Problem problem(number, tasks);
    Problem problem_cpy = problem;

    vector<Task> r_sorted_tasks = problem.sort_r();
    cout << "\nSorted by r" << endl;
    for (int i = 0; i < number; i++) {
        cout << "Task no: " << r_sorted_tasks[i].get_index() << " rj: " << r_sorted_tasks[i].get_r() << " pj: "
             << r_sorted_tasks[i].get_p() << " qj: " << r_sorted_tasks[i].get_q() << endl;
    }

    vector<Task> q_sorted_tasks = problem.sort_q();
    cout << "\nSorted by q" << endl;
    for (int i = 0; i < number; i++) {
        cout << "Task no: " << q_sorted_tasks[i].get_index() << " rj: " << q_sorted_tasks[i].get_r() << " pj: "
             << q_sorted_tasks[i].get_p() << " qj: " << q_sorted_tasks[i].get_q() << endl;
    }


    int result = problem_cpy.overview();

    ofstream output_file(output_file_path);
    output_file <<"Result: " << result <<endl;
    output_file.close();

    return 0;
}
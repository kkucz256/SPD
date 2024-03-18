#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "task.h"
#include "problem.h"

using namespace std;

int main() {

    //Input and output file paths
    string input_file_path = "./data./SCHRAGE1.DAT";
    string output_file_path = "./data./out.DAT";


    //Reading number of tasks from file
    ifstream input_file(input_file_path);
    int number;
    input_file >> number;


    //Reading and printing tasks from file
    vector<Task> tasks;
    tasks.reserve(number);
    for (int i = 0; i < number; i++) {
        int r, p, q;
        input_file >> r >> p >> q;
        tasks.emplace_back(r, p, q);
    }
    input_file.close();

    cout << "\nTasks in file: " << endl;
    for (int i = 0; i < number; i++) {
        cout << "Task no: " << tasks[i].get_index() << " rj: " << tasks[i].get_r() << " pj: " << tasks[i].get_p()
             << " qj: " << tasks[i].get_q() << endl;
    }
    cout << endl;


    //Creating new instance of problem with the tasks previously read and solving them with bruteforce method + printing
    Problem problem(number, tasks);
    Result result = problem.bruteforce();
    cout << "Bruteforce output: " << result.get_cmax() << endl;
    result.print_results();


    //Writing the result to file and closing it
    ofstream output_file(output_file_path);
    output_file << result.get_cmax() <<endl;
    output_file.close();


    //Best cmax acquired from sorting the tasks by r
    Result result_r = problem.sort_r();
    cout << "R sort output: " << result_r.get_cmax() << endl;
    result_r.print_results();


    //Best cmax acquired from sorting the tasks by q
    Result result_q = problem.sort_q();
    cout << "Q sort output: " << result_q.get_cmax() << endl;
    result_q.print_results();

    return 0;
}
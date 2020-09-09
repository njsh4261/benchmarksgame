#include <iostream>
#include <cstdlib>
#include <chrono>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

#define BIG_NUMBER 50000000

void swap(int *array, int index1, int index2){
    int temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}

int partition(int *array, int begin, int end) {
    int smaller_end = begin-1;
    for(int larger_end = begin; larger_end < end; larger_end++){
        if(array[larger_end] <= array[end]){ // the last one is the pivot
            swap(array, ++smaller_end, larger_end);
        }
    }
    swap(array, ++smaller_end, end);
    return smaller_end;
}

void quicksort(int *array, int begin, int end) {
    if(begin < end){
        int split = partition(array, begin, end);
        quicksort(array, begin, split-1);
        quicksort(array, split+1, end);
    }
}

int main(int argc, char **argv) {
    // chrono::system_clock::time_point start_time = chrono::system_clock::now();

    // parse input from stdin (problem size)
    string file_in;
    getline(cin, file_in);
    int size = stoi(file_in);

    // read an array of integer to sort
    getline(cin, file_in);
    stringstream ss(file_in);
    string token;
    int* int_array = new int[size];
    for(int i=0; ss >> token; i++){
        int_array[i] = stoi(token);
    }

    // chrono::system_clock::time_point array_read_done_time = chrono::system_clock::now();

    // // parse user input (problem size)
    // // int size = atoi(argv[1]);
    // // if(size <= 0) {
    // //     size = BIG_NUMBER;
    // // }

    // // generate an array of integer to sort
    // // random_device rd;
    // // mt19937 gen(rd());
    // // uniform_int_distribution<int> dis(0, size);

    // // int *int_array = new int[size];
    // // for(int i=0; i<size; i++) {
    // //     int_array[i] = dis(gen);
    // // }

    // // do quicksort
    quicksort(int_array, 0, size-1);
    // chrono::system_clock::time_point quicksort_done_time = chrono::system_clock::now();

    // // print elapsed time
    // chrono::milliseconds rand_array_gen_time = chrono::duration_cast<std::chrono::milliseconds>(array_read_done_time - start_time);
    // chrono::milliseconds sorting_time = chrono::duration_cast<std::chrono::milliseconds>(quicksort_done_time - array_read_done_time);

    // // for(int i=0; i<size; i++){
    // //     cout << int_array[i] << " ";
    // // }
    // // cout << endl;

    // cout << "Read array from test case: " << rand_array_gen_time.count() << " ms" << endl;
    // cout << "Quicksorting: " << sorting_time.count() << " ms" << endl;

    delete[] int_array;
}
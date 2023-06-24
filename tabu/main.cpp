#include <iostream>
#include <fstream>
#include <stdio.h>
#include <limits.h>
#include <vector>
#include <string>
#include <cmath>
#include <limits>
#include <chrono>
#include <numeric>
#include <functional>
#include "subset.h"


#include "tabu.h"
//#include "subset.cpp"
//#include "tabu.cpp"



int main(int argc, char* argv[]){
    std::fstream numbers;
    std::fstream iter;
    std::vector<int> vect;
    std::vector<int> arr;
    std::vector<int> best_subset;
    int iterations = 0;
    int random_number = 0;
    int sum_to_find = 10;
    std::vector<std::vector<int> > vect_vect_all_combinations;
    std::vector<std::vector<int> > vect_all_neighbors_of_subset;
    std::vector<int> start_vector;
    numbers.open("numbers.txt", std::ios::in);
    iter.open("iter.txt", std::ios::in);
    if(numbers.is_open()){
        arr.clear();
        std::string num;
        while(getline(numbers,num)){
            int num1 = stoi(num);
            arr.push_back(num1);

        }
    }
    if(iter.is_open()){
        std::string num;
        while(getline(iter,num)){
            iterations = stoi(num);

        }

    }
    numbers.close();
    iter.close();


   if (argc == 1) {
        std::cout<<std::endl;
        std::cout << "From file"
             << std::endl;
        create_start_subset(arr.size(),start_vector);
        std::cout<<"start vetor: "<<std::endl;
        for (int i = 0; i < arr.size(); i++) {
               std::cout<<start_vector[i];
            }
        tabu(start_vector,vect_all_neighbors_of_subset,arr,sum_to_find,iterations);
    }
    if (argc > 1) {
        arr.clear();
        std::cout << "Number of arguments passed: " << argc
             << std::endl;

         int iteration_console = atoi(argv[1]);
         std::cout<<"iteration_console "<<iteration_console<<std::endl;
        for (int i = 2; i < argc; i++) {
           arr.push_back(atoi(argv[i]));
        }

         create_start_subset(arr.size(),start_vector);
        std::cout<<"start vetor: "<<std::endl;
        for (int i = 0; i < arr.size(); i++) {
               std::cout<<start_vector[i];
            }
        tabu(start_vector,vect_all_neighbors_of_subset,arr,sum_to_find,iteration_console);

    }





}



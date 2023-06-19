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


#include "hill_climbing_random.h"
//#include "subset.cpp"
//#include "hill_climbing_random.cpp"



int main(int argc, char* argv[]){
    std::fstream numbers;
    std::fstream iter;
    std::vector<int> vect;
    std::vector<int> arr;
    std::vector<int> best_subset;
    int iterations = 0;
    int random_number = 0;
    int sum_to_find = 15;
    std::vector<std::vector<int> > vect_vect_all_combinations;
    std::vector<std::vector<int> > vect_all_neighbors_of_subset;

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
        iter_create_binary(arr, vect_vect_all_combinations);
        random_number = create_random_number_arr(arr.size());
        hill_climbing_random(iterations,random_number,vect_vect_all_combinations,vect_all_neighbors_of_subset,arr,sum_to_find);
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

        iter_create_binary(arr, vect_vect_all_combinations);
        random_number = create_random_number_arr(arr.size());
        hill_climbing_random(iteration_console,random_number,vect_vect_all_combinations,vect_all_neighbors_of_subset,arr,sum_to_find);

    }





}



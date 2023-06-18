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


#include "hill_climbing_deter.h"
#include "hill_climbing_random.h"
#include "simulate_annealing.h"
#include "tabu.h"
#include "ga.h"

void check(std::vector<int>& arr);

int main(int argc, char* argv[]){
    std::fstream numbers;
    std::fstream iter;
    std::vector<int> vect;
    std::vector<int> arr;
    std::vector<int> arr3={1,0,1,1,0};
    std::vector<int> arr2={1,2,3,4,5};
    std::vector<int> best_subset;
    int iterations = 0;
    int random_number = 0;
    int arr_size = arr.size();
    std::vector<std::vector<int> > vect_vect_all_combinations;
    std::vector<std::vector<int> > vect_all_neighbors_of_subset;

    numbers.open("numbers2.txt", std::ios::in);
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
    iter_create_binary(arr, vect_vect_all_combinations);
    random_number = create_random_number_arr(1);
   // hill_climbing_deter(iterations,random_number,vect_vect_all_combinations,vect_all_neighbors_of_subset,arr,14);
    //simulated_annealing(iterations,random_number,vect_vect_all_combinations,vect_all_neighbors_of_subset,arr,11);
    //tabu(random_number,vect_vect_all_combinations,vect_all_neighbors_of_subset,arr,6,iterations);
    ga(5,1,arr.size(),vect_vect_all_combinations,arr,4);
   /* if (argc == 1) {
        std::cout << "No extra Command Line Argument passed "
                "other than program name"
             << std::endl;
    }
    if (argc > 1) {
        arr.clear();
        std::cout << "Number of arguments passed: " << argc
             << std::endl;
        std::cout << "----Following are the commnand line "
                "arguments passed----"
             << std::endl;
         int algorithm = atoi(argv[1]);
         int iteration_console = atoi(argv[2]);
         std::cout<<algorithm<<" "<<iteration_console<<std::endl;
        for (int i = 3; i < argc; i++) {
           arr.push_back(atoi(argv[i]));
        }
        //iter_create_binary( arr, vect_vect_all_combinations);
        //random_number = create_random_number_arr(arr.size());
        switch(algorithm){
            case 1:
                iter_create_binary(arr, vect_vect_all_combinations);
                random_number = create_random_number_arr(arr_size);
                //hill_climbing_deter(iteration_console,random_number,vect_vect_all_combinations,vect_all_neighbors_of_subset,arr,14);
            break;
        }
    }


    /*for(int i=0; i<arr.size();i++){
        std::cout<<arr[i]<<" ";
    } */

    //subsets_shuffle(vect_vect_all_combinations);
    //convert_binary_to_decimal(vect_vect_all_combinations,arr);
  //random_susbset(random_number,vect_vect_all_combinations,best_subset,arr2);
  //create_neighbors_best_subset(best_subset,arr,vect_all_neighbors_of_subset);
// hill_climbing_deter(iterations,random_number,vect_vect_all_combinations,vect_all_neighbors_of_subset,arr,14);
  //hill_climbing_random(iterations,random_number,vect_vect_all_combinations,vect_all_neighbors_of_subset,arr,14);
  //simulated_annealing(iterations,random_number,vect_vect_all_combinations,vect_all_neighbors_of_subset,arr,11);
   // convert_binary_to_decimal(vect_all_neighbors_of_subset,arr);

}

void check(std::vector<int>& arr){

    create_random_number_arr(arr.size());
}


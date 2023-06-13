#include <iostream>
#include <fstream>
#include <stdio.h>
#include <limits.h>
#include <vector>
#include <string>
#include <cmath>
#include <chrono>
#include <numeric>
#include <functional>
#include "subset.h"
#include "hill_climbing_deter.h"
#include "hill_climbing_random.h"
#include "simulate_annealing.h"

int main(){
    std::fstream numbers;
    std::fstream iter;
    std::vector<int> vect;
    std::vector<int> arr;
    std::vector<int> arr3={1,0,1,1,0};
    std::vector<int> arr2={1,2,3,4,5};
    std::vector<int> best_subset;
    int iterations = 0;
    std::vector<std::vector<int> > vect_vect_all_combinations;

    std::vector<std::vector<int> > vect_all_neighbors_of_subset;


    numbers.open("numbers.txt", std::ios::in);
    iter.open("iter.txt", std::ios::in);
    if(numbers.is_open()){
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
    iter_create_binary( arr, vect_vect_all_combinations);
    int random_number = create_random_number_arr(arr.size());
    /*for(int i=0; i<arr2.size();i++){
        std::cout<<arr2[i]<<" ";
    }*/
    //subsets_shuffle(vect_vect_all_combinations);
    //convert_binary_to_decimal(vect_vect_all_combinations,arr);
  //random_susbset(random_number,vect_vect_all_combinations,best_subset,arr2);
  //create_neighbors_best_subset(best_subset,arr,vect_all_neighbors_of_subset);
  hill_climbing_deter(iterations,random_number,vect_vect_all_combinations,vect_all_neighbors_of_subset,arr,14);
  //hill_climbing_random(iterations,random_number,vect_vect_all_combinations,vect_all_neighbors_of_subset,arr,14);
  //simulated_annealing(iterations,random_number,vect_vect_all_combinations,vect_all_neighbors_of_subset,arr,11);
   // convert_binary_to_decimal(vect_all_neighbors_of_subset,arr);

}


#include <iostream>
#include <stdio.h>
#include <limits.h>
#include <vector>
#include <cmath>
#include <chrono>
#include <numeric>
#include "subset.h"
#include "hill_climbing_deter.h"
#include "hill_climbing_random.h"

int main(){
    std::vector<int> vect;
    std::vector<int> arr={1,2,3,4,5};
    std::vector<int> arr3={1,0,1,1,0};
    std::vector<int> arr2;
    std::vector<int> best_subset;
    std::vector<std::vector<int> > vect_vect_all_combinations;
    iter_create_binary(vect, arr, vect_vect_all_combinations);
    std::vector<std::vector<int> > vect_all_neighbors_of_subset;
   int random_number = create_random_number_arr(arr.size());

    //subsets_shuffle(vect_vect_all_combinations);
    //convert_binary_to_decimal(vect_vect_all_combinations,arr);
  //random_susbset(random_number,vect_vect_all_combinations,best_subset,arr2);
  //create_neighbors_best_subset(best_subset,arr,vect_all_neighbors_of_subset);
  //hill_climbing_deter(6,random_number,vect_vect_all_combinations,vect_all_neighbors_of_subset,arr,14);
  hill_climbing_random(6,random_number,vect_vect_all_combinations,vect_all_neighbors_of_subset,arr,14);
   // convert_binary_to_decimal(vect_all_neighbors_of_subset,arr);

}


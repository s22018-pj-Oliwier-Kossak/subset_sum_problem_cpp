#include <iostream>
#include <stdio.h>
#include <limits.h>
#include <vector>
#include <cmath>
#include <chrono>
#include <numeric>
#include "subset.h"
#include "hill_climbing_deter.h"

int main(){
    std::vector<int> vect;
    std::vector<int> arr={-3,-2,-1,0,1,2,3,4,6,5,4,3,5,4,3};
    std::vector<int> arr3={1,0,1,1,0};
    std::vector<int> arr2;
    create_random_array(arr2,5,-20,20);
    std::vector<int> best_subset;
    std::vector<std::vector<int> > vect_vect_all_combinations;
    iter_create_binary(vect, arr, vect_vect_all_combinations);
    std::vector<std::vector<int> > vect_all_neighbors_of_subset;
   int random_number = create_random_number(arr);

    subsets_shuffle(vect_vect_all_combinations);
    //convert_binary_to_decimal(vect_vect_all_combinations,arr);
  //random_susbset(random_number,vect_vect_all_combinations,best_subset,arr2);
  //create_neighbors_best_subset(best_subset,arr,vect_all_neighbors_of_subset);
  std::cout<<"hill"<<std::endl;
  hill_climbing_deter(6,random_number,vect_vect_all_combinations,vect_all_neighbors_of_subset,arr,-21);
   // convert_binary_to_decimal(vect_all_neighbors_of_subset,arr);

}


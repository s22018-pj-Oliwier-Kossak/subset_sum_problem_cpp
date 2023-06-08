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
    std::vector<int> arr={1,2,3,4,5};
    std::vector<int> arr2;
    std::vector<std::vector<int> > vect_vect_all_combinations;
    std::vector<std::vector<int> > vect_all_neighbors_of_subset;
    int random_number = create_random_number(arr);
    create_random_array(arr2,5,3,20);
  iter_create_binary(vect, arr2, vect_vect_all_combinations);
  subsets_shuffle(vect_vect_all_combinations);
  print_vector2d_values(vect_vect_all_combinations);
  create_neighbors(vect_vect_all_combinations,random_number,arr2, vect_all_neighbors_of_subset);
  print_vector2d_values(vect_all_neighbors_of_subset);
  convert_binary_to_decimal(vect_all_neighbors_of_subset,arr2);

 print_vector2d_values(vect_vect_all_combinations);

 std::cout<<"random_number: "<<random_number;
}


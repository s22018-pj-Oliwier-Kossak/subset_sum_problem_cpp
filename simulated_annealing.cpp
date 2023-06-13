#include <bits/stdc++.h>
#include <algorithm>
#include <random>
#include <iostream>
#include <stdio.h>
#include <limits.h>
#include <vector>
#include <cmath>
#include <chrono>
#include <numeric>
#include <string>
#include <bitset>
#include <functional>
#include <random>
#include "subset.h"
#include "simulate_annealing.h"


void simulated_annealing(int iter, int random_number, std::vector<std::vector<int> >& vect_all_combinations, std::vector<std::vector<int> >& vect_all_neighbors_of_subset,  std::vector<int>& arr, int sum_to_find){
    std::vector<int> best_subset;
    std::vector<int> best_subset_global;
    random_susbset(random_number,vect_all_combinations,best_subset,arr);
    best_subset_global=best_subset;
    for(int i=0; i<iter; i++){
        std::cout<<std::endl;
        std::cout<<"iter: "<<i<<std::endl;
        create_neighbors_best_subset(best_subset, arr, vect_all_neighbors_of_subset);
        goal_function_simulated_annealing(iter,[](int k){return 1000/k;},vect_all_neighbors_of_subset,best_subset,best_subset_global,arr,sum_to_find);
        vector2d_remove_all(vect_all_neighbors_of_subset);
        std::cout<<"best actual {" ;
        for(int j=0; j<arr.size(); j++){
                if(best_subset[j]==1){

                        std::cout<<arr[j] <<", ";
                    }
            }
            std::cout<<"}" <<std::endl;
            std::cout<<"best global: {" ;
        for(int j=0; j<arr.size(); j++){
                if(best_subset_global[j]==1){

                        std::cout<<arr[j] <<", ";
                    }
            }
            std::cout<<"}" <<std::endl;
    }
}




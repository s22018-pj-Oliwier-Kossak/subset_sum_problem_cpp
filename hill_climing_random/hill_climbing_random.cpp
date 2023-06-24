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
#include "subset.h"
#include "hill_climbing_random.h"


void hill_climbing_random(int iter,std::vector<int>&  start_subset, std::vector<std::vector<int> >& vect_all_neighbors_of_subset,  std::vector<int>& arr, int sum_to_find){
    std::vector<int> best_subset;
    best_subset = start_subset;

    for(int i=0; i<iter; i++){
        std::cout<<std::endl;
        std::cout<<"iter: "<<i+1<<std::endl;
        create_neighbors_best_subset(best_subset, arr, vect_all_neighbors_of_subset);
        goal_function_hill_random(vect_all_neighbors_of_subset,best_subset, arr, sum_to_find);
        vect_all_neighbors_of_subset.clear();
        std::cout<<"{" ;
        for(int j=0; j<arr.size(); j++){
                if(best_subset[j]==1){

                        std::cout<<arr[j] <<", ";
                    }
            }
            std::cout<<"}" <<std::endl;
    }
}

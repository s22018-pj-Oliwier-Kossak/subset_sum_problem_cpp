
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
#include "hill_climbing_deter.h"


void hill_climbing_deter(int iter, int random_number, std::vector<std::vector<int> >& vect_all_combinations, std::vector<std::vector<int> >& vect_all_neighbors_of_subset,  std::vector<int>& arr, int sum_to_find){
    std::vector<int> best_subset;
    random_susbset(random_number,vect_all_combinations,best_subset,arr);

    for(int i=0; i<iter; i++){
        std::cout<<std::endl;
        std::cout<<"iter: "<<i+1<<std::endl;
        create_neighbors_best_subset(best_subset, arr, vect_all_neighbors_of_subset);
        goal_function(vect_all_neighbors_of_subset,best_subset, arr, sum_to_find);
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

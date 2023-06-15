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
#include <limits>
#include <bitset>
#include "subset.h"
#include "hill_climbing_deter.h"


void tabu( int random_number, std::vector<std::vector<int> >& vect_all_combinations, std::vector<std::vector<int> >& vect_all_neighbors_of_subset,  std::vector<int>& arr, int sum_to_find, int tabu_size=std::numeric_limits<double>::infinity()){
    std::vector<int> best_subset;
    std::vector<int> best_subset_global;
    std::vector<std::vector<int> > tabu_list;
    random_susbset(random_number,vect_all_combinations,best_subset,arr);
    best_subset_global=best_subset;
    tabu_list.push_back(best_subset);
    int iteration=0;
    bool tabu_start = true;
    while(tabu_start){
        std::cout<<"tab: ";
         print_vector2d_values(tabu_list);
        std::cout<<std::endl;
        std::cout<<"iter: "<<iteration<<std::endl;
        create_neighbors_best_subset(best_subset, arr, vect_all_neighbors_of_subset);
        goal_function_tabu(vect_all_neighbors_of_subset, best_subset, arr, sum_to_find, tabu_list, best_subset_global, tabu_start);
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
            iteration++;
            if(tabu_list.size()==tabu_size){
                break;
            }
    }

}

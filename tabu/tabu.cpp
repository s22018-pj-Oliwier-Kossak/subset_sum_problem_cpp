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



void check_best_global(std::vector<int>& best_subset, std::vector<int>& best_subset_global, std::vector<int>& arr,int sum_to_find);
void tabu( int random_number, std::vector<std::vector<int> >& vect_all_combinations, std::vector<std::vector<int> >& vect_all_neighbors_of_subset,  std::vector<int>& arr, int sum_to_find, int tabu_size){
    std::vector<int> best_subset;
    std::vector<int> best_subset_global;
    std::vector<std::vector<int> > tabu_list;
    random_susbset(random_number,vect_all_combinations,best_subset,arr);
    best_subset_global=best_subset;
    tabu_list.push_back(best_subset);
    int iteration=0;
    bool tabu_start = true;
    while(tabu_start){


        std::cout<<std::endl;
        std::cout<<"iter: "<<iteration<<std::endl;
        create_neighbors_best_subset(best_subset, arr, vect_all_neighbors_of_subset);
        goal_function_tabu(vect_all_neighbors_of_subset, best_subset, arr, sum_to_find, tabu_list, tabu_start, tabu_size);
        check_best_global(best_subset ,best_subset_global ,arr ,sum_to_find);
        std::cout<<"tab: "<<std::endl;
        print_vector2d_values(tabu_list);
        vect_all_neighbors_of_subset.clear();
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

void check_best_global(std::vector<int>& best_subset, std::vector<int>& best_subset_global, std::vector<int>& arr,int sum_to_find){
    int points_global_subset_best = 0;
    int sum_global_subset_best = 0;
    int points_actual_subset = 0;
    int sum_actual_subset = 0;
    for(int j=0; j<arr.size(); j++){
        if(best_subset_global[j]==1){
                sum_global_subset_best+=arr[j];
            }
        }
    for(int j=0; j<arr.size(); j++){
        if(best_subset[j]==1){
               sum_actual_subset  += arr[j];
            }
        }
    points_global_subset_best = abs(sum_global_subset_best-sum_to_find);
    points_actual_subset = abs(sum_actual_subset-sum_to_find);
    if(points_global_subset_best >= points_actual_subset){
        std::cout<<"points_global_subset_best : "<<points_global_subset_best<<" points_actual_subset:" <<points_actual_subset<<std::endl;
        sum_global_subset_best=sum_actual_subset ;
        best_subset_global = best_subset;
        points_global_subset_best=0;
    }
    sum_global_subset_best=0;
    points_global_subset_best=0;
    points_actual_subset=0;
    sum_actual_subset=0;

}

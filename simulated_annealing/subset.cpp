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
#include <functional>
#include "subset.h"

void create_binary(int byte,std::vector<int>& arr, std::vector<std::vector<int> >& vect_vect)
{
     std::vector<int> vect;
     for (int i = arr.size()-1; i >= 0; i--) {
        int b = byte >> i;
        if (b & 1){
            //cout << 1;
            vect.push_back(1);
        }
        else{
            //cout << 0;
            vect.push_back(0);
        }
    }
    vect_vect.push_back(vect);
    for (int i = arr.size()-1; i >= 0; i--) {
        vect.pop_back();
    }
}

//create 2d vecotr with binary numbers
void iter_create_binary(std::vector<int>& arr, std::vector<std::vector<int> >& vect_vect){
    int iter = pow(2, arr.size());


    for(int i=0; i<iter; i++){
        create_binary(i,arr,vect_vect);
    }

}

//print values of 2d vector
void print_vector2d_values(std::vector<std::vector<int> >& vect){

        for (std::vector<int> vect1D : vect)
        {
             std::cout<<"{";
            for (int x : vect1D)
            {
                std::cout << x << ", ";
            }
            std::cout<<"}";
            std::cout << std::endl;
        }
}


void vector2d_remove_all(std::vector<std::vector<int> >& vect){
    vect.erase(vect.begin(),vect.end());
}



void random_susbset(int random_number, std::vector<std::vector<int> >& vect, std::vector<int>& random_subset, std::vector<int>& arr){


        for(int i=0; i<arr.size(); i++){

            random_subset.insert(random_subset.begin()+i,vect[random_number][i]);
        }

}

void create_neighbors_best_subset(std::vector<int>& best_subset, std::vector<int>& arr, std::vector<std::vector<int> >& vect_all_neighbors_of_subset){
        vector2d_remove_all(vect_all_neighbors_of_subset);
        std::vector<int> vect_neighbor = best_subset;

        vect_all_neighbors_of_subset.push_back(vect_neighbor);

        for(int i=0; i<arr.size(); i++){

            if(vect_neighbor.at(i)==1) {

                vect_neighbor.erase(vect_neighbor.begin()+i);
                vect_neighbor.insert(vect_neighbor.begin()+i,0);



            }
            else if(vect_neighbor.at(i)==0) {


                vect_neighbor.erase(vect_neighbor.begin()+i);
                vect_neighbor.insert(vect_neighbor.begin()+i,1);


            }

            vect_all_neighbors_of_subset.push_back(vect_neighbor);
            vect_neighbor = best_subset;

        }

        for(int i=1; i<arr.size(); i++){
                 for(int j=0; j<i*5; j++){
                    vect_all_neighbors_of_subset[i].pop_back();
                }
        }

}



void convert_binary_to_decimal(std::vector<std::vector<int> >& vect, std::vector<int>& arr){
    std::cout<<std::endl;
    for(int i=0; i<arr.size(); i++){
        std::cout<<"{" ;
        for(int j=0; j<arr.size(); j++){

           if(vect[i][j] == 1){
                std::cout<<arr[j]<<", " ;
           }

        }
        std::cout<<"}" ;
        std::cout<<std::endl;
    }

}

void display_subset(std::vector<int>& vect){
    std::cout<<"{";
    for(int i=0; i<vect.size(); i++){
        std::cout<<vect[i]<<" ,";
    }
    std::cout<<"}"<<std::endl;
}

int create_random_number_arr(int size)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, pow(2, size)-1);
    int numb = dis(gen);
    return numb;
}

int create_random_number(int start_index,int end_index)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(start_index, end_index);
    int numb = dis(gen);
    return numb;
}


void goal_function_simulated_annealing(int iter,std::function<double(int)> T, std::vector<std::vector<int> >& vect_all_neighbors_of_subset, std::vector<int>& best_subset,std::vector<int>& best_subset_global, std::vector<int>& arr, int sum_to_find){
        std::random_device rd;
        std::mt19937 rgen(rd());

        int current_neighbor_sum = 0;
        int current_neighbor_points = 0;
        int best_subset_sum = 0;
        int best_subset_points = 0;
        int best_subset_sum_global = 0;
        int best_subset_points_global = 0;
        int random_neighbor = 0;
        int random_neighbor_index = arr.size();
        for(int i=0; i<arr.size()+1; i++){
            random_neighbor = create_random_number(1,random_neighbor_index);
            for(int j=0; j<arr.size(); j++){
                if(best_subset_global[j]==1){
                        best_subset_sum_global +=arr[j];

                    }
                }
            for(int i=0; i<arr.size(); i++){
                if(best_subset[i]==1){
                        best_subset_sum +=arr[i];

                    }
                }
            std::cout<<std::endl;

            for(int j=0; j<arr.size(); j++){
                    std::cout<<best_subset[j];
                }

            for(int j=0; j<arr.size(); j++){
                if(vect_all_neighbors_of_subset[random_neighbor][j]==1){
                        current_neighbor_sum  += arr[j];
                    }
                }
                 current_neighbor_points = abs(current_neighbor_sum-sum_to_find);
                 best_subset_points = abs(best_subset_sum-sum_to_find);
                 best_subset_points_global = abs(best_subset_sum_global-sum_to_find);
            std::cout<<" best points: "<<best_subset_points<<" best sum: "<<best_subset_sum<<" random_neighbor_index:"<<random_neighbor<<std::endl;
            for(int j=0; j<arr.size(); j++){
                        std::cout<<vect_all_neighbors_of_subset[random_neighbor][j];
                }

            std::cout<<" current_neighbor_points: "<<current_neighbor_points<<" current_neighbor_sum: "<<current_neighbor_sum<<std::endl;
            for(int j=0; j<arr.size(); j++){
                    std::cout<<best_subset_global[j];
                }
            std::cout<<" best points global: "<<best_subset_points_global<<" best global sum: "<<best_subset_sum_global<<" random_neighbor_index:"<<random_neighbor<<std::endl;



            if(best_subset_points >= current_neighbor_points ){

                best_subset_sum = current_neighbor_sum;

                for(int j=0; j<arr.size(); j++){
                        best_subset.pop_back();
                }

                for(int j=0; j<arr.size(); j++){
                        best_subset.insert(best_subset.begin()+j,vect_all_neighbors_of_subset[random_neighbor][j]);
                }
                if(best_subset_points_global >= best_subset_points){

                    best_subset_sum_global = best_subset_sum;
                    best_subset_global = best_subset;

                 }
                break;

            }
            else if(random_neighbor_index>1){

                std::uniform_real_distribution<double> u(0.0,1.0);
                if(u(rgen) < std::exp(-std::abs(current_neighbor_points-best_subset_points)/T(iter))){
                    best_subset.clear();

                    for(int j=0; j<arr.size(); j++){
                            best_subset.insert(best_subset.begin()+j,vect_all_neighbors_of_subset[random_neighbor][j]);
                    }
                    vect_all_neighbors_of_subset.erase(vect_all_neighbors_of_subset.begin()+random_neighbor);
                    break;
                }
                vect_all_neighbors_of_subset.erase(vect_all_neighbors_of_subset.begin()+random_neighbor);


            }
            else {
                break;

            }

            current_neighbor_sum = 0;
            best_subset_sum = 0;
            best_subset_sum_global = 0;
            random_neighbor_index--;


        }
        best_subset_sum_global = 0;
        best_subset_points_global = 0;
        best_subset_sum = 0;
        current_neighbor_sum = 0;
        best_subset_sum = 0;
        best_subset_points = 0;


}


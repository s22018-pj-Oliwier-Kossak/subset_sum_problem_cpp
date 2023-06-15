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
            //std::cout<<vect[value][i];
            random_subset.insert(random_subset.begin()+i,vect[random_number][i]);
        }
        /*for(int i=0; i<arr.size(); i++){

            std::cout<< random_subset[i];

        } */
}
void goal_function( std::vector<std::vector<int> >& vect_all_neighbors_of_subset, std::vector<int>& best_subset, std::vector<int>& arr, int sum_to_find){


        int current_neighbor_sum = 0;
        int current_neighbor_points = 0;
        int best_subset_sum = 0;
        int best_subset_points = 0;

        for(int i=0; i<arr.size()+1; i++){
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
                if(vect_all_neighbors_of_subset[i][j]==1){
                        current_neighbor_sum  += arr[j];
                    }
                }
                 current_neighbor_points = abs(current_neighbor_sum-sum_to_find);
                 best_subset_points = abs(best_subset_sum-sum_to_find);
            std::cout<<" best points: "<<best_subset_points<<" best sum: "<<best_subset_sum<<std::endl;
            for(int j=0; j<arr.size(); j++){
                        std::cout<<vect_all_neighbors_of_subset[i][j];
                }
            std::cout<<" current_neighbor_points: "<<current_neighbor_points<<" current_neighbor_sum: "<<current_neighbor_sum<<std::endl;




            if(best_subset_points >= current_neighbor_points ){
                best_subset_sum = current_neighbor_sum;
                for(int j=0; j<arr.size(); j++){
                        best_subset.pop_back();
                }
                for(int j=0; j<arr.size(); j++){
                        best_subset.insert(best_subset.begin()+j,vect_all_neighbors_of_subset[i][j]);
                }

            }
            current_neighbor_sum = 0;
            best_subset_sum = 0;


        }
        best_subset_sum = 0;
        current_neighbor_sum = 0;
        best_subset_sum = 0;
        best_subset_points = 0;


}

void create_neighbors_best_subset(std::vector<int>& best_subset, std::vector<int>& arr, std::vector<std::vector<int> >& vect_all_neighbors_of_subset){
        vector2d_remove_all(vect_all_neighbors_of_subset);
        std::vector<int> vect_neighbor = best_subset;

        vect_all_neighbors_of_subset.push_back(vect_neighbor);

        /*for(int i=0; i<arr.size(); i++){

            std::cout<<vect_neighbor[i];

        }*/
        for(int i=0; i<arr.size(); i++){

            if(vect_neighbor.at(i)==1) {

                vect_neighbor.erase(vect_neighbor.begin()+i);
                vect_neighbor.insert(vect_neighbor.begin()+i,0);



            }
            else if(vect_neighbor.at(i)==0) {


                vect_neighbor.erase(vect_neighbor.begin()+i);
                vect_neighbor.insert(vect_neighbor.begin()+i,1);


            }
            /*display neighbors
            std::cout<<std::endl;
            for(int j=0; j<arr.size(); j++){
                std::cout<<vect_neighbor[j];
            }
            */
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



int create_random_number_arr(int size)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, pow(2, size));
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

void goal_function_hill_random( std::vector<std::vector<int> >& vect_all_neighbors_of_subset, std::vector<int>& best_subset, std::vector<int>& arr, int sum_to_find){


        int current_neighbor_sum = 0;
        int current_neighbor_points = 0;
        int best_subset_sum = 0;
        int best_subset_points = 0;
        int random_neighbor = 0;
        int random_neighbor_index = arr.size();
        for(int i=0; i<arr.size()+1; i++){
            random_neighbor = create_random_number(1,random_neighbor_index);
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
            std::cout<<" best points: "<<best_subset_points<<" best sum: "<<best_subset_sum<<" random_neighbor_index:"<<random_neighbor<<std::endl;
            for(int j=0; j<arr.size(); j++){
                        std::cout<<vect_all_neighbors_of_subset[random_neighbor][j];
                }

            std::cout<<" current_neighbor_points: "<<current_neighbor_points<<" current_neighbor_sum: "<<current_neighbor_sum<<std::endl;



            if(best_subset_points >= current_neighbor_points ){

                best_subset_sum = current_neighbor_sum;

                for(int j=0; j<arr.size(); j++){
                        best_subset.pop_back();
                }

                for(int j=0; j<arr.size(); j++){
                        best_subset.insert(best_subset.begin()+j,vect_all_neighbors_of_subset[random_neighbor][j]);
                }


                break;

            }
            else if(random_neighbor_index>1){
                vect_all_neighbors_of_subset.erase(vect_all_neighbors_of_subset.begin()+random_neighbor);

            }
            else{


                break;
            }
            current_neighbor_sum = 0;
            best_subset_sum = 0;
            random_neighbor_index--;


        }
        best_subset_sum = 0;
        current_neighbor_sum = 0;
        best_subset_sum = 0;
        best_subset_points = 0;


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
                vect_all_neighbors_of_subset.erase(vect_all_neighbors_of_subset.begin()+random_neighbor);
                std::uniform_real_distribution<double> u(0.0,1.0);
                if(u(rgen) < std::exp(-std::abs(current_neighbor_points-best_subset_points)/T(iter))){
                    for(int j=0; j<arr.size(); j++){
                        best_subset.pop_back();
                    }

                    for(int j=0; j<arr.size(); j++){
                            best_subset.insert(best_subset.begin()+j,vect_all_neighbors_of_subset[random_neighbor][j]);
                    }
                    break;
                }


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

void goal_function_tabu( std::vector<std::vector<int> >& vect_all_neighbors_of_subset, std::vector<int>& best_subset, std::vector<int>& arr, int sum_to_find, std::vector<std::vector<int> >& tabu_list, std::vector<int>& best_subset_global, bool& tabu_start){


        int current_neighbor_sum = 0;
        int current_neighbor_points = 0;
        int current_neighbor_sum_best = 0;
        int current_neighbor_points_best = 0;
        int best_subset_sum_global = 0;
        int best_subset_points_global = 0;
        int best_subset_sum = 0;
        int best_subset_points = 0;
        int iter_index_loop=0;
        std::vector<int> neighbor_subset_in_tabu;
        std::vector<int> best_subset_neighbor;
        for(int i=0; i<arr.size(); i++){
            if(best_subset[i]==1){
                best_subset_sum +=arr[i];

            }
        }
        best_subset_points = abs(best_subset_sum-sum_to_find);
        best_subset_points_global = best_subset_points;

        vect_all_neighbors_of_subset.erase(vect_all_neighbors_of_subset.begin());
        best_subset_neighbor.clear();
        for(int j=0; j<arr.size(); j++){
                    best_subset_neighbor.push_back(vect_all_neighbors_of_subset[0][j]);
                }
        while(iter_index_loop < vect_all_neighbors_of_subset.size()){
            current_neighbor_sum = 0;
            best_subset_sum = 0;
            current_neighbor_sum_best=0;
                std::cout<<"vect_all_neighbors_of_subset.size():"<<vect_all_neighbors_of_subset.size()<<std::endl;
            std::cout<<"vect2d neighbor: "<<std::endl;
             for (int i=0; i<vect_all_neighbors_of_subset.size(); i++)
                {
                     std::cout<<"{";
                    for (int j=0; j<arr.size(); j++)
                    {
                        std::cout << vect_all_neighbors_of_subset[i][j]<< ", ";
                    }
                    std::cout<<"}";
                    std::cout << std::endl;
                }


             for(int j=0; j<arr.size(); j++){
                if(best_subset_neighbor[j]==1){
                    current_neighbor_sum_best+=arr[j];

                }
            }

            for(int j=0; j<arr.size(); j++){
                if(vect_all_neighbors_of_subset[iter_index_loop][j]==1){
                        current_neighbor_sum +=arr[j];

                    }
                }
            std::cout<<std::endl;

            for(int j=0; j<arr.size(); j++){
                    std::cout<<best_subset_neighbor[j];
                }


                 current_neighbor_points = abs(current_neighbor_sum-sum_to_find);
                 current_neighbor_points_best = abs(current_neighbor_sum_best-sum_to_find);

            std::cout<<" current_neighbor_points_best: "<<current_neighbor_points_best<<" current_neighbor_sum_best: "<<current_neighbor_sum_best<<std::endl;
            for(int j=0; j<arr.size(); j++){
                        std::cout<<vect_all_neighbors_of_subset[iter_index_loop][j];
                }
            std::cout<<" current_neighbor_points: "<<current_neighbor_points<<" current_neighbor_sum: "<<current_neighbor_sum<<std::endl;




            if(current_neighbor_points_best >= current_neighbor_points ){
                neighbor_subset_in_tabu.clear();
                for(int i=0 ; i<arr.size(); i++){
                    neighbor_subset_in_tabu.insert(neighbor_subset_in_tabu.begin()+i,vect_all_neighbors_of_subset[iter_index_loop][i]);
                }
                bool is_present_neighbor = std::find(tabu_list.begin(), tabu_list.end(), neighbor_subset_in_tabu) != tabu_list.end();
                bool is_present = std::find(tabu_list.begin(), tabu_list.end(), best_subset_neighbor) != tabu_list.end();
                std::cout<<"is_present: "<<is_present<<std::endl;
                if(is_present_neighbor == 1){
                     if(vect_all_neighbors_of_subset.size()<=1){
                            std::cout<<"BREAKKBREAK PRES" <<std::endl;
                            tabu_start=false;
                            break;
                        }
                    vect_all_neighbors_of_subset.erase(vect_all_neighbors_of_subset.begin()+iter_index_loop);
                    std::cout<<"vect_all_neighbors_of_subset.size():"<<vect_all_neighbors_of_subset.size()<<std::endl;
                    best_subset_neighbor.clear();
                        for(int j=0; j<arr.size(); j++){
                            best_subset_neighbor.insert(best_subset_neighbor.begin()+j,vect_all_neighbors_of_subset[0][j]);
                        }
                    iter_index_loop=-1;
                }

                    else if(is_present == 1){

                        std::cout<<"TRUE"<<std::endl;
                        std::cout<<"iter_index_loop: "<<iter_index_loop<<std::endl;
                        vect_all_neighbors_of_subset.erase(vect_all_neighbors_of_subset.begin()+iter_index_loop);
                        std::cout<<"vect_all_neighbors_of_subset.size():"<<vect_all_neighbors_of_subset.size()<<std::endl;

                        best_subset_neighbor.clear();
                        for(int j=0; j<arr.size(); j++){
                            best_subset_neighbor.insert(best_subset_neighbor.begin()+j,vect_all_neighbors_of_subset[iter_index_loop][j]);
                        }
                        iter_index_loop=-1;
                    }
                    else{
                        std::cout<<"FALSE"<<std::endl;
                        current_neighbor_sum_best = current_neighbor_sum;
                        best_subset_neighbor.clear();
                        for(int j=0; j<arr.size(); j++){
                            best_subset_neighbor.insert(best_subset_neighbor.begin()+j,vect_all_neighbors_of_subset[iter_index_loop][j]);
                        }
                    }






            }


            iter_index_loop++;


        }

        best_subset=best_subset_neighbor;
        std::cout<<"current_neighbor_points_best: "<<current_neighbor_points_best<<" best_subset_points_global"<<best_subset_points_global<<std::endl;
        if(best_subset_points_global >= current_neighbor_points_best  ){

                    best_subset_points_global  = current_neighbor_points;
                    best_subset_global.clear();
                    best_subset_global = best_subset;

                    for(int j=0; j<arr.size(); j++){
                            if(best_subset_global[j]==1){
                                    std::cout<<arr[j] <<", ";
                            }
                    }

             }




        std::cout<<"push tabu list: "<<std::endl;

        for(int i=0; i<best_subset_neighbor.size(); i++){

                std::cout<<best_subset_neighbor[i];

        }
        std::cout<<std::endl;
        for(int i=0; i<best_subset_neighbor.size(); i++){
            if(best_subset_neighbor[i]==1){
                    std::cout<<arr[i];
                }
            }
        std::cout<<std::endl;
        tabu_list.push_back(best_subset_neighbor);



        best_subset_sum = 0;
        current_neighbor_sum = 0;
        best_subset_sum = 0;
        best_subset_points = 0;
        current_neighbor_sum_best=0;
        current_neighbor_points_best=0;


}
/*
//shuffle subsets in vector
void subsets_shuffle(std::vector<std::vector<int> > & vect)
{
     unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(vect.begin(),vect.end(), std::default_random_engine(seed));
}

//The funtcion which create arr with random numbers
void create_random_array(std::vector<int>& arr, int arr_size, int start_index, int end_index)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(start_index, end_index);


    for (int i=0; i<arr_size; ++i){
        int random_num = dis(gen);
        arr.push_back(random_num);

    }
} */


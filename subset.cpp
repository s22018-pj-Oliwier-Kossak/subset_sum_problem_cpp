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
#include "subset.h"

void create_binary(int byte,std::vector<int>& vect,std::vector<int>& arr, std::vector<std::vector<int> >& vect_vect)
{

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
void iter_create_binary(std::vector<int>& vect,std::vector<int>& arr, std::vector<std::vector<int> >& vect_vect){
    int iter = pow(2, arr.size());


    for(int i=0; i<iter; i++){
        create_binary(i,vect,arr,vect_vect);
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

//print values of 2d vector
void vector2d_remove_all(std::vector<std::vector<int> >& vect){
    vect.erase(vect.begin(),vect.end());
}

//create neighbors for subset
void create_neighbors(std::vector<std::vector<int> >& vect, int value, std::vector<int> arr, std::vector<std::vector<int> >& vect_all_neighbors_of_subset){
        std::vector<int> vect_neighbor;

        for(int i=0; i<arr.size(); i++){

            //std::cout<<vect[value][i];
            vect_neighbor.insert(vect_neighbor.begin()+i,vect[value][i]);
        }


        /*for(int i=0; i<arr.size(); i++){

            std::cout<<vect_neighbor[i];

        } */

        std::cout<<std::endl;
        std::cout<<std::endl;
        for(int i=0; i<arr.size(); i++){

            if(vect_neighbor.at(i)==1) {

                vect_neighbor.erase(vect_neighbor.begin()+i);
                vect_neighbor.insert(vect_neighbor.begin()+i,0);



            }
            else if(vect_neighbor.at(i)==0) {


                vect_neighbor.erase(vect_neighbor.begin()+i);
                vect_neighbor.insert(vect_neighbor.begin()+i,1);


            }

           /* for(int j=0; j<arr.size(); j++){
                std::cout<<vect_neighbor[j];
            } */

            vect_all_neighbors_of_subset.push_back(vect_neighbor);
            for(int j=0; j<arr.size(); j++){
                vect_neighbor.insert(vect_neighbor.begin()+j,vect[value][j]);
            }

        }

        for(int i=1; i<arr.size(); i++){
                 for(int j=0; j<i*5; j++){
                    vect_all_neighbors_of_subset[i].pop_back();
                }
        }

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
            std::cout<<std::endl;
            for(int j=0; j<arr.size(); j++){
                if(vect_all_neighbors_of_subset[i][j]==1){
                        current_neighbor_sum  += arr[j];
                    }
                }
                 current_neighbor_points = abs(current_neighbor_sum-sum_to_find);
                 best_subset_points = abs(best_subset_sum-sum_to_find);
            std::cout<<"best points: "<<best_subset_points<<" best sum: "<<best_subset_sum<<std::endl;
            std::cout<<"current_neighbor_points: "<<current_neighbor_points<<" current_neighbor_sum: "<<current_neighbor_sum<<std::endl;




            if(best_subset_points >= current_neighbor_points ){
                best_subset_sum = current_neighbor_sum;
                for(int j=0; j<arr.size(); j++){
                        best_subset.pop_back();
                }
                for(int j=0; j<arr.size(); j++){
                        best_subset.insert(best_subset.begin()+j,vect_all_neighbors_of_subset[i][j]);
                }
                std::cout<<std::endl;
                for(int j=0; j<arr.size(); j++){
                        std::cout<<best_subset[j];
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
        std::cout<<std::endl;
        std::cout<<std::endl;
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
            /* display neighbors
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
}

int create_random_number(std::vector<int>& arr)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, pow(2, arr.size()));
    int numb = dis(gen);
    return numb;
}


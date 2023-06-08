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

//create neighbors for subset
void create_neighbors(std::vector<std::vector<int> >& vect, int value, std::vector<int> arr, std::vector<std::vector<int> >& vect_all_neighbors_of_subset){
        std::vector<int> vect_neighbor;

        for(int i=0; i<arr.size(); i++){

            std::cout<<vect[value][i];
            vect_neighbor.insert(vect_neighbor.begin()+i,vect[value][i]);
        }
        std::cout<<std::endl;
        std::cout<<std::endl;

        for(int i=0; i<arr.size(); i++){

            std::cout<<vect_neighbor[i];

        }

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

            for(int j=0; j<arr.size(); j++){
                std::cout<<vect_neighbor[j];
            }
            std::cout<<std::endl;

            vect_all_neighbors_of_subset.push_back(vect_neighbor);
            for(int j=0; j<arr.size(); j++){
                vect_neighbor.insert(vect_neighbor.begin()+j,vect[value][j]);
            }

        }

        for(int i=1; i<arr.size(); i++){
                 for(int j=0; j<i*5; j++){
                    vect_all_neighbors_of_subset[i].pop_back();
                }
                std::cout<<std::endl;
        }

}

void convert_binary_to_decimal(std::vector<std::vector<int> >& vect, std::vector<int> arr){
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


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





void random_susbset(int random_number, std::vector<std::vector<int> >& vect, std::vector<int>& random_subset, std::vector<int>& arr){


        for(int i=0; i<arr.size(); i++){
            random_subset.insert(random_subset.begin()+i,vect[random_number][i]);
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



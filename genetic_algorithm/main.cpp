#include <iostream>
#include <fstream>
#include <stdio.h>
#include <limits.h>
#include <vector>
#include <string>
#include <cmath>
#include <limits>
#include <chrono>
#include <numeric>
#include <functional>
#include "subset.h"


#include "ga.h"
//#include "subset.cpp"
//#include "ga.cpp"



int main(int argc, char* argv[]){
    std::fstream numbers;
    std::fstream iter;
    std::fstream method;
    std::vector<int> vect;
    std::vector<int> arr;
    std::vector<int> best_subset;
    int iterations = 0;
    int random_number = 0;
    int sum_to_find = 10;
    int method_cross = 0;
    std::vector<std::vector<int> > vect_vect_all_combinations;

    numbers.open("numbers.txt", std::ios::in);
    iter.open("iter.txt", std::ios::in);
    method.open("method.txt", std::ios::in);
    if(numbers.is_open()){
        arr.clear();
        std::string num;
        while(getline(numbers,num)){
            int num1 = stoi(num);
            arr.push_back(num1);

        }
    }
    if(iter.is_open()){
        std::string num;
        while(getline(iter,num)){
            iterations = stoi(num);

        }

    }
     if(method.is_open()){
        std::string method_index;
        while(getline(method,method_index)){
            method_cross = stoi(method_index);

        }

    }
    numbers.close();
    iter.close();
    method.close();

   if (argc == 1) {
        std::cout<<std::endl;
        std::cout << "From file"
             << std::endl;

        ga(iterations,method_cross,8,arr,sum_to_find);
    }
    if (argc > 1) {
        arr.clear();
        std::cout << "Number of arguments passed: " << argc
             << std::endl;

         int iteration_console = atoi(argv[1]);
         int method_console = atoi(argv[2]);
         std::cout<<"iteration_console "<<iteration_console<<std::endl;
         std::cout<<"method_console  "<<method_console <<std::endl;
        for (int i = 2; i < argc; i++) {
           arr.push_back(atoi(argv[i]));
        }


        ga(iteration_console,method_console ,10,arr,sum_to_find);
    }





}



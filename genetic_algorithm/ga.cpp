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
#include <iomanip>
#include "subset.h"
#include "ga.h"

void ga(int iter, int method, int population_size, std::vector<std::vector<int> >& vect_vect_all_combinations,std::vector<int>& arr, int sum_to_find){
    std::vector<std::vector<int> > population;
    std::vector<int> points_after_scale;
    create_population(population_size, vect_vect_all_combinations, population, arr);
    bool start = true;
    int index = 0;
    while((index<iter)&&(start)){
        std::cout<<std::endl;
        std::cout<<"iteration: "<<index+1<<std::endl;
        print_vector2d_values(population);
        ga_goal_function(population, population_size, arr, sum_to_find, points_after_scale, start);
        roulette(population, population_size, points_after_scale, arr) ;
        choose_cross_method(method,population,population_size, arr);
        mutation(population, population_size, arr);
        index++;
    }
    convert_binary_to_decimal(population,arr);

}

void create_population(int population_size, std::vector<std::vector<int> >& vect_vect_all_combinations, std::vector<std::vector<int> >& population, std::vector<int>& arr){
    int number;
    std::vector<int> vect_to_push;
    for(int i=0; i<population_size; i++){
        number=create_random_number_arr(arr.size());
        for(int j=0; j<arr.size(); j++){
            vect_to_push.push_back(vect_vect_all_combinations[number][j]);
        }
        std::cout<<number<<std::endl;
        population.push_back(vect_to_push);
        vect_to_push.clear();
    }

}

void ga_goal_function(std::vector<std::vector<int> >& population ,int population_size, std::vector<int>& arr, int sum_to_find,std::vector<int>& points_after_scale,bool& start){
    std::vector<int> all_points_gene;
    int points_of_gene=0;
    int sum_of_gene=0;
    int all_gene_sum=0;
    for(int i=0; i<population_size; i++){
        for(int j=0; j<arr.size(); j++){
            if(population[i][j]==1){
                sum_of_gene+=arr[j];

            }

        }
        points_of_gene = abs(sum_of_gene-sum_to_find);
        if(points_of_gene == 0){

            start = false;
        }
        all_points_gene.push_back(points_of_gene*population_size);
        points_of_gene=0;
        sum_of_gene=0;
    }
     for(int i=0; i<population_size; i++){
        std::cout<<i<< " points: "<<all_points_gene[i]<<std::endl;
        all_gene_sum+=all_points_gene[i];
    }
    std::cout<<"  all_gene_sum: "<<all_gene_sum<<std::endl;
    for(int i=0; i<population_size; i++){
        points_after_scale.push_back( all_gene_sum-all_points_gene[i]);
    }
    std::cout<<std::endl;
    for(int i=0; i<population_size; i++){
        std::cout<<i<< " points_after_scale: "<< points_after_scale[i]<<std::endl;

    }
    points_after_scale.clear();
    all_points_gene.clear();

}

void roulette(std::vector<std::vector<int> >& population, int population_size ,std::vector<int>& points_after_scale, std::vector<int>& arr){
    std::vector<int> probability;
    std::vector<std::vector<int> > population_probability;
    int sum_points_after_scale = 0;
    int probability_sum = 0;
    for(int i=0; i<population_size; i++){
        sum_points_after_scale+=points_after_scale[i];
    }
    std::cout<< "sum_points_after_scale: "<< sum_points_after_scale<<std::endl;
     for(int i=0; i<population_size; i++){
        float  float_points_after_scale = points_after_scale[i];
        float  float_sum_points_after_scale = sum_points_after_scale;
        float percent = (float_points_after_scale/float_sum_points_after_scale)*100;
        int convert_percent =  (int)(percent + 0.5);
        std::cout<<"percent: "<<percent<<std::endl;
        probability.push_back(convert_percent);
        percent=0;
    }
    std::cout<<std::endl;
    for(int i=0; i<population_size; i++){
        std::cout<<i<< " probability: "<< probability[i]<<std::endl;
        probability_sum += probability[i];
    }
    std::cout<< "probability sum: "<< probability_sum<<std::endl;
    int index_of_iter=0;
    while(index_of_iter < population_size){
        for(int i=0; i<probability[index_of_iter]; i++){
            population_probability.push_back(population[index_of_iter]);
        }
        index_of_iter++;
    }
    print_vector2d_values(population_probability);
    population.clear();

    int number;
    for(int i=0; i<population_size; i++){
        std::vector<int> vect_to_push;
        number=create_random_number(0,probability_sum-1);
        for(int j=0; j<arr.size(); j++){
            vect_to_push.push_back(population_probability[number][j]);
        }
        std::cout<<number<<std::endl;
        population.push_back(vect_to_push);
        vect_to_push.clear();
    }
    std::cout<<"population: "<<std::endl;
      print_vector2d_values(population);


}

void cross_half(std::vector<std::vector<int> >& population, int population_size, std::vector<int>& arr){
    int cross_index = create_random_number(1,arr.size()-2);
    std::vector<int> first_parent;
    std::vector<int> second_parent;
    std::vector<int> first_child;
    std::vector<int> second_child;
    std::vector<int> last_in_population;
    std::vector<std::vector<int> > new_population;
    if(population_size%2 == 0){
        for(int i=0; i<population_size; i+=2){
                std::cout<<"cross_index: "<<cross_index<<std::endl;
                for(int j=0; j<arr.size(); j++){
                    first_parent.insert(first_parent.begin()+j, population[i][j]);
                    second_parent.insert(second_parent.begin()+j, population[i+1][j]);
                }
                std::cout<<"first_parent: {";
                for(int i=0; i<arr.size(); i++){
                    std::cout<<first_parent[i]<<" ,";
                }
                std::cout<<"}"<<std::endl;
                std::cout<<"second_parent: {";
                for(int i=0; i<arr.size(); i++){
                    std::cout<<second_parent[i]<<" ,";
                }
                std::cout<<"}"<<std::endl;
                for(int j=0; j<cross_index; j++){
                    first_child.push_back(first_parent[j]);
                     second_child.push_back(second_parent[j]);
                }
                for(int j=cross_index; j<arr.size(); j++){
                    first_child.push_back(second_parent[j]);
                     second_child.push_back(first_parent[j]);
                }
                std::cout<<"first_child: {";
                for(int i=0; i<arr.size(); i++){
                    std::cout<<first_child[i]<<" ,";
                }
                std::cout<<"}"<<std::endl;
                std::cout<<"second_child: {";
                for(int i=0; i<arr.size(); i++){
                    std::cout<< second_child[i]<<" ,";
                }
                std::cout<<"}"<<std::endl;
            new_population.push_back(first_child);
            new_population.push_back(second_child);
            first_child.clear();
            second_child.clear();
            first_parent.clear();
            second_parent.clear();

        }
        population.clear();
        population = new_population;
        new_population.clear();
    }
    else{
            for(int i=0; i<population_size-1; i+=2){

                std::cout<<"cross_index: "<<cross_index<<std::endl;
                for(int j=0; j<arr.size(); j++){
                    first_parent.insert(first_parent.begin()+j, population[i][j]);
                    second_parent.insert(second_parent.begin()+j, population[i+1][j]);
                }
                std::cout<<"first_parent: {";
                for(int i=0; i<arr.size(); i++){
                    std::cout<<first_parent[i]<<" ,";
                }
                std::cout<<"}"<<std::endl;
                std::cout<<"second_parent: {";
                for(int i=0; i<arr.size(); i++){
                    std::cout<<second_parent[i]<<" ,";
                }
                std::cout<<"}"<<std::endl;
                for(int j=0; j<cross_index; j++){
                    first_child.push_back(first_parent[j]);
                     second_child.push_back(second_parent[j]);
                }
                for(int j=cross_index; j<arr.size(); j++){
                    first_child.push_back(second_parent[j]);
                     second_child.push_back(first_parent[j]);
                }
                std::cout<<"first_child: {";
                for(int i=0; i<arr.size(); i++){
                    std::cout<<first_child[i]<<" ,";
                }
                std::cout<<"}"<<std::endl;
                std::cout<<"second_child: {";
                for(int i=0; i<arr.size(); i++){
                    std::cout<< second_child[i]<<" ,";
                }
                std::cout<<"}"<<std::endl;
            new_population.push_back(first_child);
            new_population.push_back(second_child);
            first_child.clear();
            second_child.clear();
            first_parent.clear();
            second_parent.clear();

        }
        for(int j=0; j<arr.size(); j++){
            last_in_population.insert(last_in_population.begin()+j, population[population_size-1][j]);
        }
        new_population.push_back(last_in_population);
        population.clear();
        last_in_population.clear();
        population = new_population;
        new_population.clear();

    }

}

void choose_cross_method(int method, std::vector<std::vector<int> >& population, int population_size, std::vector<int>& arr){
    if(method == 1){
        cross_half(population,population_size, arr);
    }
    else{
        cross_random(population,population_size, arr);
    }
}

void mutation(std::vector<std::vector<int> >& population, int population_size, std::vector<int>& arr){
    for(int i=0; i<population_size; i++){
      int chance_to_mutation = create_random_number(0,9);
      if(chance_to_mutation == 1){
            std::cout<<"index: "<<i<<" subset before mutation: {";
            for(int j=0; j<arr.size(); j++){
                std::cout<< population[i][j]<<" ,";
            }
            std::cout<<"}  ";
            for(int j=0; j<arr.size(); j++){
                int chance_to_mutation_index = create_random_number(0,3);
                if(chance_to_mutation_index == 1){

                    if(population[i][j]==0){
                        population[i][j]=1;
                    }
                    else{
                        population[i][j]=0;
                    }

                }
            }

            std::cout<<" subset after mutation: {";
            for(int j=0; j<arr.size(); j++){
                std::cout<< population[i][j]<<" ,";
            }
            std::cout<<"}"<<std::endl;

        }
    }
    print_vector2d_values(population);


}

void cross_random(std::vector<std::vector<int> >& population, int population_size, std::vector<int>& arr){
    int cross_index_smaller = create_random_number(1,2);
    int cross_index_bigger = create_random_number(2,arr.size()-2);
    std::vector<int> first_parent;
    std::vector<int> second_parent;
    std::vector<int> first_child;
    std::vector<int> second_child;
    std::vector<int> last_in_population;
    std::vector<std::vector<int> > new_population;
    if(population_size%2 == 0){
        for(int i=0; i<population_size; i+=2){
                std::cout<<"cross_index_smaller: "<<cross_index_smaller<<std::endl;
                std::cout<<"cross_index_bigger: "<<cross_index_bigger<<std::endl;
                for(int j=0; j<arr.size(); j++){
                    first_parent.insert(first_parent.begin()+j, population[i][j]);
                    second_parent.insert(second_parent.begin()+j, population[i+1][j]);
                }
                std::cout<<"first_parent: {";
                for(int i=0; i<arr.size(); i++){
                    std::cout<<first_parent[i]<<" ,";
                }
                std::cout<<"}"<<std::endl;
                std::cout<<"second_parent: {";
                for(int i=0; i<arr.size(); i++){
                    std::cout<<second_parent[i]<<" ,";
                }
                std::cout<<"}"<<std::endl;
                for(int j=0; j<cross_index_smaller; j++){
                    first_child.push_back(first_parent[j]);
                     second_child.push_back(second_parent[j]);
                }
                for(int j=cross_index_smaller; j<=cross_index_bigger; j++){
                    first_child.push_back(second_parent[j]);
                     second_child.push_back(first_parent[j]);
                }
                for(int j=cross_index_bigger+1; j<arr.size(); j++){
                    first_child.push_back(first_parent[j]);
                     second_child.push_back(second_parent[j]);
                }
                std::cout<<"first_child: {";
                for(int i=0; i<arr.size(); i++){
                    std::cout<<first_child[i]<<" ,";
                }
                std::cout<<"}"<<std::endl;
                std::cout<<"second_child: {";
                for(int i=0; i<arr.size(); i++){
                    std::cout<< second_child[i]<<" ,";
                }
                std::cout<<"}"<<std::endl;
            new_population.push_back(first_child);
            new_population.push_back(second_child);
            first_child.clear();
            second_child.clear();
            first_parent.clear();
            second_parent.clear();

        }
        population.clear();
        population = new_population;
        new_population.clear();
    }
    else{
            for(int i=0; i<population_size-1; i+=2){

                std::cout<<"cross_index_smaller : "<<cross_index_smaller<<std::endl;
                std::cout<<"cross_index_bigger: "<<cross_index_bigger<<std::endl;
                for(int j=0; j<arr.size(); j++){
                    first_parent.insert(first_parent.begin()+j, population[i][j]);
                    second_parent.insert(second_parent.begin()+j, population[i+1][j]);
                }
                std::cout<<"first_parent: {";
                for(int i=0; i<arr.size(); i++){
                    std::cout<<first_parent[i]<<" ,";
                }
                std::cout<<"}"<<std::endl;
                std::cout<<"second_parent: {";
                for(int i=0; i<arr.size(); i++){
                    std::cout<<second_parent[i]<<" ,";
                }
                std::cout<<"}"<<std::endl;
                for(int j=0; j<cross_index_smaller; j++){
                    first_child.push_back(first_parent[j]);
                     second_child.push_back(second_parent[j]);
                }
                for(int j=cross_index_smaller; j<=cross_index_bigger; j++){
                    first_child.push_back(second_parent[j]);
                     second_child.push_back(first_parent[j]);
                }
                for(int j=cross_index_bigger+1; j<arr.size(); j++){
                    first_child.push_back(first_parent[j]);
                     second_child.push_back(second_parent[j]);
                }
                std::cout<<"first_child: {";
                for(int i=0; i<arr.size(); i++){
                    std::cout<<first_child[i]<<" ,";
                }
                std::cout<<"}"<<std::endl;
                std::cout<<"second_child: {";
                for(int i=0; i<arr.size(); i++){
                    std::cout<< second_child[i]<<" ,";
                }
                std::cout<<"}"<<std::endl;
            new_population.push_back(first_child);
            new_population.push_back(second_child);
            first_child.clear();
            second_child.clear();
            first_parent.clear();
            second_parent.clear();

        }
        for(int j=0; j<arr.size(); j++){
            last_in_population.insert(last_in_population.begin()+j, population[arr.size()-1][j]);
        }
        new_population.push_back(last_in_population);
        population.clear();
        last_in_population.clear();
        population = new_population;
        new_population.clear();

    }

}





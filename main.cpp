// CPP program to find all subsets by backtracking.
#include <bits/stdc++.h>
#include <algorithm>
#include <random>
#include <chrono>
#include <iostream>
#include <vector>
#include <numeric>

void create_combinations(std::vector<int>& arr, std::vector<std::vector<int> >& res,
                 std::vector<int>& subset, int index);
std::vector<std::vector<int> > subsets_combinations(std::vector<int>& arr);
void subsets_shuffle(std::vector<std::vector<int> > & vect);
void create_random_array(std::vector<int>& arr, int arr_size, int start_index, int end_index);
void hill_climbing(std::vector<std::vector<int> > & vect, int iter, int sum_to_find);
int generate_random_number( int start_index, int end_index);


int main()
{

    std::vector<int> array = {1, 2, 3, 4, 5, 7 };
    std::vector<int> array2;
    create_random_array(array2,5,1,100);
    for(int i=0;i<5;i++){
        std::cout<<" "<<array2[i];
    }
    std::vector<std::vector<int> > vect = subsets_combinations(array2);

    /*for (int i = 0; i < vect.size(); i++) {
        cout <<"[";
        for (int j = 0; j < vect[i].size(); j++){
            cout << vect[i][j]<< ", ";
        }
        cout <<"]";
        cout << endl;
    }*/
    std::cout << std::endl;
    std::cout << std::endl;
    for (std::vector<int> vect1D : vect)
    {
        std::cout <<"{";
        for (int x : vect1D)
        {
            std::cout << x << ", ";
        }
        std::cout <<"}";
        std::cout << std::endl;
    }

    std::cout << std::endl;
    std::cout << std::endl;
    //shuffle vector
    hill_climbing(vect,1,2);
   /* subsets_shuffle(vect);

    for (std::vector<int> vect1D : vect)
    {
        std::cout <<"{";
        for (int x : vect1D)
        {
            std::cout << x << ", ";
        }
        std::cout <<"}";
        std::cout << std::endl;
    }
    std::cout<<std::endl;*/


    return 0;
}

//the function to create combinations of subsets from arr
void create_combinations(std::vector<int>& arr, std::vector<std::vector<int> >& res,
                 std::vector<int>& subset, int index)
{

    for (int i = index; i < arr.size(); i++) {

        subset.push_back(arr[i]);
        res.push_back(subset);

       // cout<<"prev i: "<<i<<"     A[i]: "<<arr[i]<<endl;

        create_combinations(arr, res, subset, i + 1);

        //cout<<"after i: "<<i<<"    A[i]: "<<arr[i]<<endl;
        subset.pop_back();
    }

    return;
}

//the function to create combinations of subsets from arr
std::vector<std::vector<int> > subsets_combinations(std::vector<int>& arr)
{
    std::vector<int> subset;
    std::vector<std::vector<int> > res;
    int index = 0;
    create_combinations(arr, res, subset, index);


    return res;
}

//shuffle subsets in vector
void subsets_shuffle(std::vector<std::vector<int> > & vect)
{
     unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(vect.begin(),vect.end(), std::default_random_engine(seed));
}

//create array with random values
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

//function generate random integer;
int generate_random_number( int start_index, int end_index)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(start_index, end_index);

    int random_num = dis(gen);
    return random_num;
}

//hill climbing
void hill_climbing(std::vector<std::vector<int> > & vect, int iter,int sum_to_find )
{
    //shuffle subsets
    subsets_shuffle(vect);
    int mid_neigbor = generate_random_number(10,12);
    int left_neigbor = mid_neigbor-1;
    int right_neigbor = mid_neigbor+1;



    for(int i=0; i < iter; i++){
        int sum_of_elements_mid_neigbor = std::accumulate(vect[mid_neigbor].begin(), vect[mid_neigbor ].end(), 0);
        int sum_of_elements_left_neigbor  = std::accumulate(vect[left_neigbor ].begin(), vect[left_neigbor  ].end(), 0);
        int sum_of_elements_right_neigbor = std::accumulate(vect[right_neigbor].begin(), vect[right_neigbor ].end(), 0);
        std::cout<<"mid : "<<mid_neigbor<<" left: "<<left_neigbor<<" right: "<<right_neigbor<<std::endl;
        int mid_neigbor_points = sum_to_find-sum_of_elements_mid_neigbor;
        int left_neigbor_points = sum_to_find-sum_of_elements_left_neigbor;
        int right_neigbor_points = sum_to_find-sum_of_elements_right_neigbor;
        std::vector<int> solution ;
        solution = vect[mid_neigbor];
        if(mid_neigbor_points < 0){
            mid_neigbor_points *= -1;
        }
        if(left_neigbor_points< 0){
           left_neigbor_points *= -1;
        }
        if(right_neigbor_points  < 0){
            right_neigbor_points  *= -1;
        }

        if((mid_neigbor_points < left_neigbor_points)&&(mid_neigbor_points < right_neigbor_points )){
            solution = vect[mid_neigbor];
        }
        else if((left_neigbor_points < mid_neigbor_points)&&(left_neigbor_points <  right_neigbor_points )){
            solution = vect[left_neigbor_points];
        }
        else if((right_neigbor_points  < left_neigbor_points)&&(right_neigbor_points <  mid_neigbor_points)){
            solution = vect[right_neigbor_points];
        }
        std::cout<<"{ ";
        for (int i=0 ; i<solution.size(); i++){
            std::cout<<" "<<solution[i];
        }
        std::cout<<" }";
        std::cout<<std::endl;
        std::cout<<"mid points: "<<mid_neigbor_points<<" left points: "<<left_neigbor_points<<" right points: "<<right_neigbor_points<<std::endl;

    }
    // index to start hill climbing

     for (std::vector<int> vect1D : vect)
    {
        std::cout <<"{";
        for (int x : vect1D)
        {
            std::cout << x << ", ";
        }
        std::cout <<"}";
        std::cout << std::endl;
    }
    std::cout<<std::endl;
    std::cout<<std::endl;




    // unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
   // shuffle(vect.begin(),vect.end(), std::default_random_engine(seed));
}


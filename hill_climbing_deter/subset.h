#ifndef SUBSET_HILL_DETER
#define SUBSET_HILL_DETER
void display_subset(std::vector<int>& vect);

void print_vector2d_values(std::vector<std::vector<int> >& vect);

void iter_create_binary(std::vector<int>& arr, std::vector<std::vector<int> >& vect_vect);

void create_binary(int byte,std::vector<int>& arr, std::vector<std::vector<int> >& vect_vect);

void convert_binary_to_decimal(std::vector<std::vector<int> >& vect, std::vector<int>& arr);

int create_random_number_arr(int size);

int create_random_number(int start_index,int end_index);


void create_neighbors_best_subset(std::vector<int>& best_subset, std::vector<int>& arr, std::vector<std::vector<int> >& vect_all_neighbors_of_subsetj);

void random_susbset(int random_number, std::vector<std::vector<int> >& vect, std::vector<int>& random_subset, std::vector<int>& arr);

void create_start_subset(int size,std::vector<int>& start_subset);

void goal_function( std::vector<std::vector<int> >& vect_all_neighbors_of_subset, std::vector<int>& best_subset, std::vector<int>& arr, int sum_to_find);
#endif

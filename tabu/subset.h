void display_subset(std::vector<int>& vect);

void print_vector2d_values(std::vector<std::vector<int> >& vect);

void iter_create_binary(std::vector<int>& arr, std::vector<std::vector<int> >& vect_vect);

void create_binary(int byte,std::vector<int>& arr, std::vector<std::vector<int> >& vect_vect);

void convert_binary_to_decimal(std::vector<std::vector<int> >& vect, std::vector<int>& arr);

int create_random_number_arr(int size);

int create_random_number(int start_index,int end_index);

void vector2d_remove_all(std::vector<std::vector<int> >& vect);

void create_neighbors_best_subset(std::vector<int>& best_subset, std::vector<int>& arr, std::vector<std::vector<int> >& vect_all_neighbors_of_subsetj);

void random_susbset(int random_number, std::vector<std::vector<int> >& vect, std::vector<int>& random_subset, std::vector<int>& arr);

void goal_function_tabu( std::vector<std::vector<int> >& vect_all_neighbors_of_subset, std::vector<int>& best_subset, std::vector<int>& arr, int sum_to_find, std::vector<std::vector<int> >& tabu_list, bool& tabu_start,int tabu_size);


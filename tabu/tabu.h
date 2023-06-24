#ifndef TABU
#define TABU
void tabu(std::vector<int>& start_vector, std::vector<std::vector<int> >& vect_all_neighbors_of_subset,  std::vector<int>& arr, int sum_to_find, int tabu_size);
void check_best_global(std::vector<int>& best_subset, std::vector<int>& best_subset_global, std::vector<int>& arr,int sum_to_find);
#endif

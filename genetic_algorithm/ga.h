
void ga(int iter, int method, int population_size, std::vector<std::vector<int> >& vect_vect_all_combinations,std::vector<int>& arr, int sum_to_find);

void create_population(int population_size, std::vector<std::vector<int> >& vect_vect_all_combinations, std::vector<std::vector<int> >& population );

void ga_goal_function(std::vector<std::vector<int> >& population ,int population_size, std::vector<int>& arr, int sum_to_find, std::vector<int>& points_after_scale, bool& start);

void roulette(std::vector<std::vector<int> >& population, int population_size ,std::vector<int>& points_after_scale);

void cross_half(std::vector<std::vector<int> >& population, int population_size);

void choose_cross_method(int method, std::vector<std::vector<int> >& population, int population_size);

void mutation(std::vector<std::vector<int> >& population, int population_size);

void cross_random(std::vector<std::vector<int> >& population, int population_size);

#include <iostream>
//int tab[] = {11,-5,3,2,8,-1,-3,2,5,-8,1,0}
int tab[] = {5,3,-5,1,21,-3,2,-7,8,9,10};
int search_sum = 4;

using namespace std;

void goal_function(int [], int, int);

void hill_climbing(int [], int, int);

int main() {

    int arr_length2 = sizeof(tab) / sizeof(int);
//    goal_function(tab, 4, arr_length2);


    hill_climbing(tab, 4, 4);
    return 0;
}

void hill_climbing(int arr[], int arr_length, int goal) {
    int index = 4;
    int index_copy = index;
    int subset[] = {arr[index - 1], arr[index], arr[index + 1]};
    int left_subset[] = {arr[index - 2], arr[index - 1], arr[index]};
    int right_subset[] = {arr[index], arr[index + 1], arr[index + 2]};
    int subset_sum = 0;
    int left_neighbor_sum = 0;
    int right_neighbor_sum = 0;
    int subset_goal_points = 0;
    int left_neighbor_goal_points = 0;
    int right_neighbor_goal_points = 0;


    for (int i = 0; i < 3; i++) {
        cout << subset[i] << " ";
        subset_sum += subset[i];
    }

    subset_goal_points = subset_sum - goal;

    if (subset_goal_points < 0) {
        subset_goal_points = subset_goal_points * (-1);
    }
    cout << "subset_sum: " << subset_sum << " subset_goal_points: " << subset_goal_points << "\n";

    for (int i = 0; i < 3; i++) {
        cout << left_subset[i] << " ";
        left_neighbor_sum += left_subset[i];
    }

    left_neighbor_goal_points = left_neighbor_sum - goal;

    if (left_neighbor_goal_points < 0) {
        left_neighbor_goal_points = left_neighbor_goal_points * (-1);
    }
    cout << "left_neighbor_sum: " << left_neighbor_sum << " left_neighbor_goal_points : " << left_neighbor_goal_points
         << "\n";

    for (int i = 0; i < 3; i++) {
        cout << right_subset[i] << " ";
        right_neighbor_sum += right_subset[i];
    }
    right_neighbor_goal_points = right_neighbor_sum - goal;
    if (right_neighbor_goal_points < 0) {
        right_neighbor_goal_points = right_neighbor_goal_points * (-1);
    }

    cout << "right_neighbor_sum: " << right_neighbor_sum << " right_neighbor_goal_points: "
         << right_neighbor_goal_points << "\n";

    for (int i = 0; i < 3; i++) {
        if ((left_neighbor_goal_points < subset_goal_points) and
            (left_neighbor_goal_points < right_neighbor_goal_points)) {
            index_copy -= 2;
            int index_to_iter_subset = index_copy;
            int index_to_iter_left_subset = index_copy - 1;
            int index_to_iter__right_subset = index_copy + 1;
            for (int i = 0; i < 3; i++) {
                subset[i] = arr[index_to_iter_subset];
                index_to_iter_subset++;
            }
            for (int i = 0; i < 3; i++) {
                left_subset[i] = arr[index_to_iter_left_subset];
                index_to_iter_left_subset++;
            }
            for (int i = 0; i < 3; i++) {
                right_subset[i] = arr[index_to_iter__right_subset];
                index_to_iter__right_subset++;
            }
            index_copy++;
            cout << "index copy: " << index_copy << "\n";


        }
         else if ((right_neighbor_goal_points < subset_goal_points) and
            (right_neighbor_goal_points < left_neighbor_goal_points)) {

            int index_to_iter_subset = index_copy;
            int index_to_iter_left_subset = index_copy - 1;
            int index_to_iter__right_subset = index_copy + 1;
            for (int i = 0; i < 3; i++) {
                subset[i] = arr[index_to_iter_subset];
                index_to_iter_subset++;
            }
            for (int i = 0; i < 3; i++) {
                left_subset[i] = arr[index_to_iter_left_subset];
                index_to_iter_left_subset++;
            }
            for (int i = 0; i < 3; i++) {
                right_subset[i] = arr[index_to_iter__right_subset];
                index_to_iter__right_subset++;
            }
            index_copy +=1;
            cout << "index copy: " << index_copy << "\n";


        }

        subset_sum = 0;
        left_neighbor_sum = 0;
        right_neighbor_sum = 0;
        subset_goal_points = 0;
        left_neighbor_goal_points = 0;
        right_neighbor_goal_points = 0;
        cout << "\n";
        cout << "\n";

        for (int i = 0; i < 3; i++) {
            cout << subset[i] << " ";
            subset_sum += subset[i];
        }
        subset_goal_points = subset_sum - goal;
        if (subset_goal_points < 0) {
            subset_goal_points = subset_goal_points * (-1);
        }
        cout << "subset_sum: " << subset_sum << " subset_goal_points: " << subset_goal_points << "\n";

        for (int i = 0; i < 3; i++) {
            cout << left_subset[i] << " ";
            left_neighbor_sum += left_subset[i];
        }
        left_neighbor_goal_points = left_neighbor_sum - goal;
        if (left_neighbor_goal_points < 0) {
            left_neighbor_goal_points = left_neighbor_goal_points * (-1);
        }
        cout << "left_neighbor_sum: " << left_neighbor_sum << " left_neighbor_goal_points : "
             << left_neighbor_goal_points << "\n";

        for (int i = 0; i < 3; i++) {
            cout << right_subset[i] << " ";
            right_neighbor_sum += right_subset[i];
        }

        right_neighbor_goal_points = right_neighbor_sum - goal;
        if (right_neighbor_goal_points < 0) {
            right_neighbor_goal_points = right_neighbor_goal_points * (-1);
        }
        cout << "right_neighbor_sum: " << right_neighbor_sum << " right_neighbor_goal_points: "
             << right_neighbor_goal_points << "\n";


    }


}

//void goal_function(int arr[], int search_value, int arr_length) {
//    srand((unsigned) time(NULL));
//    int subset_sum = 0;
//    int random = 1 + (rand() % arr_length - 1);
//    int random_subset[3] = {arr[random - 1], tab[random], tab[random + 1]};
//    cout << "arr lent " << arr_length << "\n";
//    for (int i = 0; i < 3; i++) {
//        cout << random_subset[i] << "\n";
//        subset_sum += random_subset[i];
//    }
//    int goal_points = subset_sum - search_value;
//    if (goal_points < 0) {
//        goal_points = goal_points * (-1);
//    }
//    cout << "subset sum " << subset_sum << "\n";
//    cout << "goal points " << goal_points << "\n";
//    cout << "\n";;
//
//
//}






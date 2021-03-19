#include <bits/stdc++.h>
using namespace std;


int knapsack(int profit[], int weight[], int i, int capacity, int p, int collected){
    if (capacity < p){
        return 0;
    }
    if (capacity == p){
        return collected;
    }
    if (i < 0){
        return 0;
    }
    i--;
    return max(max(collected, knapsack(profit, weight, i, capacity, p+weight[i], collected+profit[i])), max(collected, knapsack(profit, weight, i, capacity, p, collected)));
}




int main(){
    int capacity = 8;
    int profit[] = {1, 2, 5, 6};
    int weight[] = {2, 7, 4, 3};
    cout << knapsack(profit, weight, 4, capacity, 0, 0);
}
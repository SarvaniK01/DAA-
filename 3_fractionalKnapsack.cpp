#include<bits/stdc++.h>

using namespace std;

struct Item{
    int value;
    int weight;
};

bool compare(struct Item A, struct Item B){
    double r1 = (double)A.value / (double)A.weight;

    double r2 = (double)B.value / (double)B.weight;

    return r1 > r2;
}

double fractionalKnapsack(struct Item arr[], int N, int size){
    
    int currentWeight = 0;

    double finalValue = 0.0;

    for(int i = 0; i<size; i++){
        if(currentWeight + arr[i].weight <= N){
            currentWeight += arr[i].weight;
            finalValue += arr[i].value;
        }

        else{
            double remaining = N - currentWeight;
            finalValue += arr[i].value * ((double)remaining / arr[i].weight);

            break;
        }
    }

    return finalValue;
}

int main(){
    int N = 60;

    Item arr[] = {
        {100, 10},
        {280, 40},
        {120, 20},
        {120, 24}
    };

    int size = sizeof(arr) / sizeof(arr[0]);
    // cout<<"size:"<<size<<endl;
    // cout<<"sizeof(arr):"<<sizeof(arr)<<endl;
    // cout<<"sizeof(arr[0]):"<<sizeof(arr[0])<<endl;

    double value = fractionalKnapsack(arr, N, size);

    cout<<"Maximum profit earned is:"<<value;
}
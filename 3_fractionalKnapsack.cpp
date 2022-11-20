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
    int N;
    cout<<"Enter the max capacity of Knapsack:";
    cin>>N;
    
    cout<<endl;
    
    int n;
    cout<<"Enter the number of items:";
    cin>>n;
    cout<<endl;
    
    struct Item arr[n];
    
    cout<<endl<<"Enter the values/profits of items:"<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i].value;
    }
    
    
    cout<<endl<<"Enter the weights of items:"<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i].weight;
    }

    double value = fractionalKnapsack(arr, N, n);

    cout<<endl<<"Maximum profit earned is:"<<value;
}

// Input for user:
// Enter the max capacity of Knapsack:60

// Enter the number of items:4


// Enter the values/profits of items:
// 100
// 280
// 120
// 120

// Enter the weights of items:
// 10
// 40
// 20
// 24


// Output:
// Maximum profit earned is:440

//inputs taken from gfg
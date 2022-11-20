#include<iostream>

using namespace std;

int main(){
    int capacity;
    cout<<"Enter the maximum capacity of the knapsack:";
    cin>>capacity;

    int items;
    cout<<"Enter the number of items:";
    cin>>items;

    int n = items+1;

    int value[n];
    value[0] = 0;
    cout<<"Enter the value/price of the items:"<<endl;
    for(int i =1; i<=items; i++){
        cin>>value[i];
    }

    cout<<endl;

    int weight[n];
    weight[0] = 0; 
    cout<<"Enter the weight of the items:"<<endl;
    for(int i =1; i<=items; i++){
        cin>>weight[i];
    }
    cout<<endl;

    int V[items + 1][capacity + 1];

    for(int i=0; i<=items; i++){
        for(int j = 0; j<=capacity; j++){

            if(i == 0 || j == 0){
                V[i][j] = 0;
            }

            else if(weight[i] <= j){
                V[i][j] = max(V[i-1][j] , V[i-1][j - weight[i]] + value[i]);
            }

            else{
                V[i][j] = V[i-1][j];
            }
        }
    }

    cout<<"Maximum profit earned is:"<<V[items][capacity]<<endl;
}

// Input for user to check:
// Enter the maximum capacity of the knapsack:50
// Enter the number of items:3
// Enter the value/price of the items:
// 60
// 100
// 120

// Enter the weight of the items:
// 10
// 20
// 30

// Output:
// Maximum profit earned is:220

//inputs taken from gfg
#include<iostream>

using namespace std;

int main(){
    //predefined inputs
    // int capacity = 10;
    // int items = 4;
    
    // int value[items + 1] = {0, 3, 7, 2, 9};
    // int weight[items + 1] = {0, 2, 2, 4, 5};

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
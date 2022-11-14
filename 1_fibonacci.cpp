#include<iostream>

using namespace std;

//Fibonacci series (Non recursion)
void fibonacciNR(int n){
    int t1 = 0; 
    int t2 = 1;
    int nextTerm = 0;

    for(int i = 0; i<n; i++){
        if(i == 0){
            cout<<t1<<" ";
        }

        if(i == 1){
            cout<<t2<<" ";
        }

        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;

        cout<<nextTerm<<" ";
    }
    cout<<endl;
}

void fibonacciR(int n){
    int t1 = 0;
    int t2 = 1;
    int nextTerm = 0;

    // base function
    cout<<t1<<" "<<t2<<" ";

    for(int i=0; i<n; i++){
        nextTerm = t1 + t2;

        cout<<nextTerm<<" ";

        t1 = t2;
        t2 = nextTerm;
    }
}

int main(){
    int n;
    cout<<"Enter the value of n:";
    cin>>n;

    //Non recursive
    cout<<"Non Recursive:"<<endl;
    fibonacciNR(n);

    cout<<endl;

    //Recursive
    cout<<"Recursive:"<<endl;
    fibonacciR(n);
}
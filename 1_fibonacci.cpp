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
            continue;
        }

        if(i == 1){
            cout<<t2<<" ";
            continue;
        }

        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;

        cout<<nextTerm<<" ";
    }
    cout<<endl;
}

int fibonacciR(int n){

    int nextTerm = 0;

    if(n==0 || n==1){
        return n;
    }

    nextTerm = fibonacciR(n-1) + fibonacciR(n-2);
    return nextTerm;
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
    for(int i = 0; i<n; i++){
        cout<<fibonacciR(i)<<" ";
    }
}
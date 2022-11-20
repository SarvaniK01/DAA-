// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    
    int n;
    cout<<"Enter the value of n:";
    cin>>n;
    
    clock_t start, end;

    int t1 = 0; 
    int t2 = 1;
    int nextTerm = 0;

    start = clock();
    
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
    
    end = clock();

    double timeRequired = double(end - start);
    cout<<"Time Required for iterative function:"  <<fixed<<setprecision(5)<<timeRequired<<" secs";
    return 0;
}

//Analysis
// The Iteration method would be the prefer and faster approach to solving our problem because we are storing the first two of our Fibonacci numbers in two variables (previouspreviousNumber, previousNumber) and using "CurrentNumber" to store our Fibonacci number. Storing these values prevent us from constantly using memory space in the Stack. Thus giving us a time complexity of O(n).

//try passing n = 15 for both recursive and non recursive programs and you can clearly see the difference in time required by both the codes
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int fibonacciR(int n){

    int nextTerm = 0;

    if(n==0 || n==1){
        return n;
    }

    nextTerm = fibonacciR(n-1) + fibonacciR(n-2);
    
    return nextTerm;
    
}

int main(){
    time_t start, end;
    time(&start);
    
    int n;
    cout<<"Enter the value of n:";
    cin>>n;

    //Recursive
    cout<<"Recursive:"<<endl;
    for(int i = 0; i<n; i++){
        cout<<fibonacciR(i)<<" ";
    }
    
    time(&end);
    double timeRequired = double(end - start);
    cout<<endl<<"Time Required for recursive function:"<<fixed<<setprecision(5)<<timeRequired<<endl;
}

//Analysis
// what happens if we pass higher numbers like 50, 67, 100. Well if you try to run the function with the given numbers in you're IDE. You will begin to notice how much longer it takes for this method gives us our Fibonacci number. Now trying to run a Space Complexity analysis will be a tricky thing to do because of a lot of things are happening behind the scenes of this recursive function. The reason for the poor performance is heavy push-pop of the stack memory in each recursive call.

//try passing n = 15 for both recursive and non recursive programs and you can clearly see the difference in time required by both the codes
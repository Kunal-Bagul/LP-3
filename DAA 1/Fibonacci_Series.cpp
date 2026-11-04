#include <iostream>
using namespace std;


int RecursiveFibonacci(int n){
    if(n<=1) return n;
    return RecursiveFibonacci(n - 1) + RecursiveFibonacci(n - 2);
}

int iterativeFibonacci(int n){
    
    if(n<=1) return n;

    int a= 0, b=1,c;
    cout<<a<<" "<<b<<" ";
    for (int i =2;i<=n;i++){
        c=a+b;
        cout<<c<<" ";
        a=b;
        b=c;
    }
    return c;
}

int main(){
    int n;
    cout<<"Enter the number of terms: ";
    cin>>n;
    cout<<"Fibonacci series using recursion: ";
    for(int i =0;i<=n;i++){
        cout<<RecursiveFibonacci(i)<<" ";
    }
    cout<<endl;
    cout<<"Fibonacci series using iteration: ";
    iterativeFibonacci(n);
    cout<<endl;
}
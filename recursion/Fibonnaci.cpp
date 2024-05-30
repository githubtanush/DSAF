#include<iostream>
using namespace std;
int fib(int n){
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    //recursive call
    int fibo = fib(n-1)+fib(n-2);
    return fibo;
}
int main(){
    int n;
    cout<<"Enter the number for which u find sequence : ";
    cin>>n;
    int ans = fib(7);
    cout<<"Answer is : "<<ans<<endl;
    return 0;
}
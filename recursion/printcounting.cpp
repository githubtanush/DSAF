#include<iostream>
using namespace std;
void printN(int n){
    if(n==1){
        cout<<1;
        return;
    }
    //processing
    cout<<n<<" ";
    //recursion call
    //tail recursion
    printN(n-1);
}
void printtN(int n){
    if(n==1){
        cout<<1<<" ";
        return ;
    }
    //recursion call
    //head recursion
    printtN(n-1);
    //processing
    cout<<n<<" ";
}
int main(){ 
    printN(5);
    cout<<endl;
    printtN(10);
    return 0;
}
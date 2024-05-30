#include<iostream>
using namespace std;
int factorial(int n){
    //base case 
    if(n==0 || n==1){
        return 1;
    }
    //processing

    //recursive relation
    int recursion = factorial(n-1);
    int finalans = n * recursion;
    return finalans;

    //processing
}
int main(){
    int n;
    cout<<"Enter the number for which u find factorial : ";
    cin>>n;
    int ans = factorial(n);
    cout<<"The answer for this factorial is : "<<ans;
    return 0;

}
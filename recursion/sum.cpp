#include<iostream>
using namespace std;
int sum(int n){
    //base case
    if(n==1)
        return 1;
    int ans = n + sum(n-1);
    return ans;
}
int main(){
    int n;
    cout<<"Enter the number for which till you find the sum :";
    cin>>n;
    int ans = sum(n);
    cout<<"Answer is : "<<ans<<endl;


    return 0;
}
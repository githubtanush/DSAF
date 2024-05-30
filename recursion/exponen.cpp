#include<iostream>
using namespace std;
int getexpo(int n){
    if(n==0)
        return 1;
    //recursive call 
    int ans = 2 * getexpo(n-1);
    return ans;
}
int main(){
    int n;
    cout<<"for which power of 2 u find the exponent : ";
    cin>>n;
    int ans =  getexpo(n);
    cout<<"Answer is : "<<ans<<endl;
    return 0;
}
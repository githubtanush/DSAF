#include<iostream>
using namespace std;
int getpaintways(int n,int k){
    //base case 
    if(n==1)
        return k;
    if(n==2)
        return k + k*(k-1);
    
    int ans = (k-1) * (getpaintways(n-1,k)+getpaintways(n-2,k));
    return ans;
}

int main(){
    int n = 3;
    int k = 3;
    int ans = getpaintways(n,k);
    cout<<ans<<endl; 

    return 0;
}
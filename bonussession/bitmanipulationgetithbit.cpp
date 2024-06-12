#include<iostream>
using namespace std;
void getIthbit(int n,int i){
    int mask = (1<<i);
    int ans = n & mask;
    if(ans==0){
        cout<<"bit -> 0"<<endl;
    }
    else{
        cout<<"bit->1"<<endl;
    }
}
void setithbit(int n,int i){
    int mask = 1 << i;
    n = n | mask;
    cout<<"Updated number : "<<n<<endl;
}
void clearithbit(int n,int i){
    int mask = ~(1 << i);
    n = n & mask;
    cout<<"Updated number : "<<n<<endl;
}
int main(){
    int n = 10;
    int i = 3;
    getIthbit(10,3);
    setithbit(10,2);
    clearithbit(10,1);
    return 0;
}
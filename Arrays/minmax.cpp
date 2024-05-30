#include<iostream>
#include<limits.h>
using namespace std;
void inputArray(int arr[],int n){
    for(int i = 0 ;  i < n;i++){
        cin>>arr[i];
    }
}
int minnumber(int arr[],int n){
    int minAns = INT_MAX;
    for(int i =  0 ;  i < n;i++){
        if(minAns>arr[i]){
            minAns = arr[i];
        }
    }
    return minAns;
}
int maxnumber(int arr[],int n){
    int maxAns = INT_MIN;
    for(int i =  0 ;  i < n;i++){
        if(maxAns<arr[i]){
            maxAns = arr[i];
        }
    }
    return maxAns;
}
int main(){
    int arr[1000];
    int n;
    cout<< "Enter the length of the array that how many big array you want to print : "<<endl;
    cin>>n;
    inputArray(arr,n);
    int minimum = minnumber(arr,n);
    cout<<"The minimum number occur in the array is : "<<minimum<<endl;
    int maximum = maxnumber(arr,n);
    cout<<"The maximum number occur in the array is : "<<maximum<<endl;
    return 0;
}

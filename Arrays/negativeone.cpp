#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    //Assumption - order does not matter
    int arr[8]={-12,-19,24,34,84,39,4,-9};
    int n = 8;
    //for finding size of array => int n = sizeof(arr)/sizeof(int);
    //1st solution
    // sort(arr,arr+n);
    //2nd 
    //Dutch National Flag algorithm
    int left = 0;
    int right = n -1;
    while(left<right){
        if(arr[left]<0){
            left++;
        }
        else if(arr[right]>0){
            right--;
        }
        else{
            swap(arr[left],arr[right]);
        }
    }
    

    for(int i = 0; i< n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
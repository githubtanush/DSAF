#include<iostream>
using namespace std;
int findmin(int arr[],int size,int index,int target){
    //base case
    if(index>=size)
        return -1;

    //processing
    if(arr[index]==target)
        return index;
    

    //recursion call
    return findmin(arr,size,index+1,target);
}
int main(){
    int arr[6] = {10,20,30,40,50,60};
    int size = 6;
    int index = 0;
    int target = 60;
    cout<<findmin(arr,size,index,target);

    return 0;
}
#include<iostream>
using namespace std;
int binSearch(int arr[],int s,int e,int target){
    //base case
    if(s>e){
        //element not found
        return -1; 
    }
    //processing - 1 case khud solve krdo 
    int mid = s+(e-s)/2;
    if(arr[mid]== target){
        return mid;
    }

    ///baki recursion sambhal lega
    if(target<arr[mid]){
        bool aagakaans = binSearch(arr,mid+1,e,target);
        return aagakaans;
    }
    else{
        bool pichehaians = binSearch(arr,0,mid-1,target);
        return pichehaians;
    }

}
int main(){
    int arr[] = {10,20,30,40,50};
    int n = 5;
    int s = 0;
    int e = n - 1;
    int target = 30;
    cout<<binSearch(arr,s,e,target);
    return 0;
     
}
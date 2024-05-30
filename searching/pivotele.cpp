//smallest element = pivot
//larget element = pivot
//we assume the maximum element to the pivot element
#include<iostream>
using namespace std;
void inputarray(int arr[1000],int n){
    for(int i = 0; i < n;i++){
        cin>>arr[i];
    }
}
void outputarray(int arr[1000],int n){
    for(int i = 0; i < n;i++){
        cout<<arr[i]<<" ";
    }
}
int findpivotIndex(int arr[],int n){
    int s = 0, e = n - 1;
    int mid = s + (e-s)/2;
    while(s<=e){
        if(s==e) return s;//corner case
        if(arr[mid]<arr[mid-1])
            return mid-1;
        else if(arr[mid]>arr[mid+1])
            return mid;
        else if(arr[s]>arr[mid])
            e = mid - 1;
        else 
            s = mid + 1;
        mid = s + (e - s)/2;
    }
    return -1;
}
int main(){
    int arr[1000];
    int n;
    cout<<"Enter the size of tha array : ";
    cin>>n;
    inputarray(arr,n);
    int index = findpivotIndex(arr,n);
    cout<<"The element is found at index : "<<index<<endl;
    outputarray(arr,n);
    return 0;
}
//binary search applies only on monotonic functions
//monotonic function - always increasing or always decreasing
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
int binarysearch(int arr[1000],int n,int target){
    int s = 0;
    int e = n - 1;
    int mid = s + (e-s)/2;
    while(s<=e){
        if(arr[mid]==target){
            return mid;
        }
        else if(target<arr[mid]){
                e = mid - 1;
        }
        else if(target>arr[mid]){
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    return -1;
}
int main(){
    int arr[1000];
    int n;
    cout<<"Enter the size of tha array : ";
    cin>>n;
    inputarray(arr,n);
    int target;
    cout<<"Enter the targeted value : ";
    cin>>target;
    int index =  binarysearch(arr,n,target);
    cout<<"The element is found at index : "<<index<<endl;
    outputarray(arr,n);
    return 0;
}
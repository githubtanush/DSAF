#include<iostream>
using namespace std;
void inputArray(int arr[],int n){
    for(int i = 0 ;  i < n;i++){
        cin>>arr[i];
    }
}
int linearSearch(int arr[],int n,int target){
    for(int i = 0; i < n;i++){
        if(arr[i]==target){
            return i;
        }
    }
    return -1;
}
void outputArray(int arr[],int n){
    for(int i = 0; i < n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[1000];
    int n;
    cout<< "Enter the length of the array that how many big array you want to print : "<<endl;
    cin>>n;
    inputArray(arr,n);
   int target;
   cout<<"Enter the element for which u find in the Array : "<<endl;
   cin>>target;
   int ans = linearSearch(arr,n,target);
   cout<<"The element for which u find in the array is located at the position "<<ans<<endl;
    // outputArray(arr,n);
    return 0;
}
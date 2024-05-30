#include<iostream>
using namespace std;
void inputArray(int arr[],int n){
    for(int i = 0 ;  i < n;i++){
        cin>>arr[i];
    }
}
void reverseArray(int arr[],int n){
    //1st way 
    // for(int i  = n-1; i>=0;i--){
    //     cout<<arr[i]<<" ";
    // }

    //2nd way swap - two pointer approach
    int left = 0;
    int right = n - 1;
    while(left<right){
        swap(arr[left],arr[right]);
        left++;
        right--;
    }
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
    outputArray(arr,n);
    cout<<endl;
    reverseArray(arr,n);
    outputArray(arr,n);
    return 0;
}
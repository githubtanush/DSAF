#include<iostream>
using namespace std;
void inputArray(int arr[],int n){
    for(int i = 0 ;  i < n;i++){
        cin>>arr[i];
    }
}
void outputArray(int arr[],int n){
    for(int i = 0; i < n;i++){
        cout<<arr[i]<<" ";
    }
}
void shiftelebyk(int arr[],int n,int k){
    // int temp[n];
    // for(int i = 0; i < n;i++){
    //     int newIndex = (i+k)%n;
    //     temp[newIndex] = arr[i];
    // }
    // for(int i = 0; i < n;i++){
    // arr[i] = temp[i];
    // }
    // k = k % n;
    // if(k==0) return ;

    int temp[k];
    for(int i = 0; i < k;i++){
        temp[i] = arr[n-k+i];
    }
   for(int i = n - 1  ; i >= k ; i--){
    arr[i] = arr[i-k];
   }
   for(int i  = 0; i < k ; i++){
        arr[i] = temp[i];
   }
}
int main(){
    int arr[1000];
    int n;
    cout<< "Enter the length of the array that how many big array you want to print : "<<endl;
    cin>>n;
    inputArray(arr,n);
    int k ;
    cout<<"Enter how many rotations you want : ";
    cin>>k;
    shiftelebyk(arr,n,k);
    outputArray(arr,n);
    cout<<endl;

    outputArray(arr,n);
    return 0;
}
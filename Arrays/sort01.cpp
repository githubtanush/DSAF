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
void sortzerone(int arr[],int n){
    // 1st approach  = counting
    // int zeroCount = 0;
    // int oneCount = 0;
    // for(int i = 0; i < n ;i++){
    //     if(arr[i]==0){
    //         zeroCount++;
    //     }
    //     if(arr[i]==1){
    //         oneCount++;
    //     }
    // }
    // for(int i = 0; i < zeroCount;i++){
    //     arr[i]=0;
    // }
    // for(int i = zeroCount; i < n;i++){
    //     arr[i] = 1;
    // }

    //2nd approach = two pointer
    // int left = 0;
    // int right = n - 1;
    // while(left < right){
    //     if(arr[left]==0){
    //         left++;
    //     }
    //     else if(arr[right]==1){
    //         right--;
    //     }
    //     else{
    //         swap(arr[left],arr[right]);
    //         left++;
    //         right--;
    //     }
    // }
    

    //3rd = sort()
    sort(arr,arr+n);
}
int main(){
    int arr[1000];
    int n;
    cout<< "Enter the length of the array that how many big array you want to print : "<<endl;
    cin>>n;
    inputArray(arr,n);
    outputArray(arr,n);
    cout<<endl;
    sortzerone(arr,n);
    outputArray(arr,n);
    return 0;
}
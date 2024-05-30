//find missing element in a sorted array 
#include<iostream>
using namespace std;
void inputarray(int arr[1000],int n){
    for(int i = 0; i < n;i++){
        cin>>arr[i];
    }
}
void outputarray(int arr[1000],int n){
    for(int i = 0; i < n;i++){
        cout<<arr[i];
    }
}
int missingele(int arr[1000],int n){
    int s = 0;
    int e = n - 1;
    int mid  = s + (e - s)/2;
    int ans = -1; 
    while(s<=e){
        int diff = arr[mid] - mid;
        if(diff==1){
            s = mid + 1;
        }
        else{
            ans = mid ;
            e = mid - 1;
        }
        mid = s + (e - s)/2;
    }
    //hw find that solution that we prevent from writing this extra conditon
    if(ans+1==0)
        return n+1;

    return ans+1;
}
int main(){
    int arr[1000];
    int n;
    cout<<"Enter the size of tha array : ";
    cin>>n;
    inputarray(arr,n);
    int index =  missingele(arr,n);
    cout<<"Missing element is : "<<index<<endl;
    outputarray(arr,n);
    return 0;
}
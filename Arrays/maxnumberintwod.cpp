#include<iostream>
#include<limits.h>
using namespace std;
void inputArray(int arr[][1000],int row,int col){
    for(int i = 0; i < row;i++){
        for(int j = 0; j < col ; j++){
           cin>>arr[i][j];
        }
    }
}
void printArray(int arr[][1000],int row,int col){
    for(int i = 0; i < row;i++){
        for(int j = 0; j < col ; j++){
           cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
int maximumnumber(int arr[][1000],int row,int col){
    int maxi = INT_MIN;
    for(int i = 0; i < row; i++){
        for(int j = 0 ;  j < col;j++){
            if(maxi<arr[i][j]){
                maxi = arr[i][j];
            }
        }
    }
    return maxi;
}
int main(){
    int arr[1000][1000];
    int row;
    cout<<"Enter the row that how many rows you want in the matrix : ";
    cin>>row;
    int col;
    cout<<"Enter the col that how many cols you want in the matrix : ";
    cin>>col;
    inputArray(arr,row,col);
    printArray(arr,row,col);
    int maximumnumb = maximumnumber(arr,row,col);
    cout<<"The maximum number in the array is : "<<maximumnumb<<endl;
    return 0;
}
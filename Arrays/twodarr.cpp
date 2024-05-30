#include<iostream>
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
           cout<<arr[i][j]<<"       ";
        }
        cout<<endl;
    }
}
void colwiseAccess(int arr[][1000],int row,int col){
    for(int i = 0; i < col;i++){
        for(int j = 0; j < row ; j++){
           cout<<arr[j][i]<<" ";
        }
        cout<<endl;
    }
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
    cout<<endl<<endl;
    colwiseAccess(arr,row,col);
    return 0;
}
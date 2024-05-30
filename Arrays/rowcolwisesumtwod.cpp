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
           cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
void rowwisesum(int arr[][1000],int row,int col){
    for(int i = 0; i < row;i++){
        int sum = 0;
        for(int j = 0; j < col;j++){
            sum = sum + arr[i][j];
        }
        cout<<"row wise sum for "<<i+1<<"row is : "<<sum<<endl;
    }
}
void colwisesum(int arr[][1000],int row,int col){
    for(int i = 0; i < col;i++){
        int sum = 0;
        for(int j = 0; j < row;j++){
            sum = sum + arr[j][i];
        }
        cout<<"col wise sum for "<<i+1<<"col is : "<<sum<<endl;
    }
}
void diagonalwisesum(int arr[][1000],int row ,int col){
        int sum = 0;
     for(int i = 0; i < row;i++){
        sum = sum + arr[i][i];
    }
    cout<<"diagonal wise sum is: "<<sum<<endl;
}
void ultadiagonal(int arr[][1000],int row,int col){
    int sum = 0;
    for(int i = 0 ; i < row;i++){
        col--;
        sum = sum + arr[i][col];
        // col--;
    }
    cout<<"ulta diagonal ka sum is : "<<sum<<endl;
}
void transposeofmatrix(int arr[][1000],int row,int col){
    for(int i = 0 ; i < row; i++){
        for(int j = i; j < col;j++){
            swap(arr[i][j],arr[j][i]);
        }
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
    rowwisesum(arr,row,col);
    colwisesum(arr,row,col);
    diagonalwisesum(arr,row,col);
    ultadiagonal(arr,row,col);
    transposeofmatrix(arr,row,col);
    printArray(arr,row,col);
    return 0;
}

//for making 2d vector
//vector<vector<int> > arr(5,vector<int>(10,0))
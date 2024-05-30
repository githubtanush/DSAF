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
bool searching(int arr[][1000],int row,int col,int target){
    for(int i = 0; i < row;i++){
        for(int j = 0 ; j < col;j++){
            if(arr[i][j] == target){
                return true;
            } 
        }
    }
    return false;
}
int main(){
    int arr[1000][1000];
    int row;
    cout<<"Enter the row that how many rows you want in the matrix : ";
    cin>>row;
    int col;
    cout<<"Enter the col that how many cols you want in the matrix : ";
    cin>>col;
    int target;
    cout<<"select your targeted value : ";
    cin>>target;
    inputArray(arr,row,col);
    printArray(arr,row,col);
    int ans = searching(arr,row,col,target);
    if(ans==1){
        cout<<"The target value is found ";
    }
    else{
        cout<<"The target value does not found";
    }
    return 0;
}
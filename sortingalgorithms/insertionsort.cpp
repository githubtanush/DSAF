#include<iostream>
#include<vector>
using namespace std;
void inputarray(vector<int> &v,int n){
    for(int i = 0; i < n;i++){
        int data;
        cin>>data;
        v.push_back(data);
    }
}
void outputarray(vector<int> &v){
    int n = v.size();
    for(int i = 0; i < n;i++){
        cout<<v[i]<<" ";
    }
}
void insertionsort(vector<int> &v){
    int n = v.size();
    //i = 0 ke liye chor do
    for(int i = 1;i < n;i++){
        int key = v[i];
        int j = i - 1;
        //Move elements of arr[0,....,i-1] that are greater than 
        // key to one position ahead of their current position
        while(j>=0 && v[j] > key){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = key;//insertion
    }
}
int main(){
    int arr[1000];
    int n;
    cout<<"Enter the size of tha array : ";
    cin>>n;
    vector<int> v;
    inputarray(v,n);
  insertionsort(v);
    outputarray(v);
    return 0;
}
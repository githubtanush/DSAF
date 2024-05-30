#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
// void inputarray(vector<int> &v,int n){
//     for(int i = 0; i < n;i++){
//         int data;
//         cin>>data;
//         v.push_back(data);
//     }
// }
// void outputarray(vector<int> &v){
//     int n = v.size();
//     for(int i = 0; i < n;i++){
//         cout<<v[i]<<" ";
//     }
// }
// bool mycomp(int &a,int &b){
//     // return a<b; //inc. order sorting
//     return a>b;//dec. order sorting
// }

bool mycompfor1stindex(vector<int> &a,vector<int> &b){//very very very good practice to take comparator by refrence because phir cpu ko asani milegi
return a[1]<b[1];
}

int main(){
    // int arr[1000];
    // int n;
    // cout<<"Enter the size of tha array : ";
    // cin>>n;
    // vector<int> v;
    // inputarray(v,n);
    // //increasing order sorting
    // sort(v.begin(),v.end());//merge sort/heapsort/quicksort mishran
    // //decreasing order sorting
    // sort(v.begin(),v.end(),mycomp);//mycomp return type always bool
    // outputarray(v);





    //vector of vector sorting
    vector<vector<int> > v;
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    for(int i = 0; i < n;i++){
        int a,b;
        cout<<"Enter a : ";
        cin>>a;
        cout<<"Enter b : ";
        cin>>b;
        vector<int> temp;
        temp.push_back(a);
        temp.push_back(b);
        v.push_back(temp);
    }
    cout<<endl;
    for(int i = 0;i < v.size();i++){
        vector<int>&temp = v[i];
        int a = temp[0];
        int b = temp[1];
        cout<<a<<" "<<b<<endl; 
    }
    sort(v.begin(),v.end());//sort by 0th index
    cout<<endl;
    sort(v.begin(),v.end(),mycompfor1stindex);
    cout<<endl;
        for(int i = 0;i < v.size();i++){
        vector<int>&temp = v[i];
        int a = temp[0];
        int b = temp[1];
        cout<<a<<" "<<b<<endl; 
    }
    cout<<endl;
    return 0;
}
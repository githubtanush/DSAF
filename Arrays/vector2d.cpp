#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<vector<int> >arr(5,vector<int>(10,-1));
    // row = arr ka size arr.size();
    for(int i = 0; i < arr.size();i++){
        for(int j = 0; j < arr[i].size();j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    //jagged array
    vector<vector<int> > brr;

    vector<int> vec1(10,0);
    vector<int> vec2(5,1);
    vector<int> vec3(7,0);
    vector<int> vec4(8,9);
    vector<int> vec5(20,0);
    brr.push_back(vec1);
    brr.push_back(vec2);
    brr.push_back(vec3);
    brr.push_back(vec4);
    brr.push_back(vec5);
    for(int i = 0; i < brr.size();i++){
        for(int j = 0; j < brr[i].size();j++){
            cout<<brr[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}
//vector 2d jagged array we create 
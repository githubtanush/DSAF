#include<iostream>
#include<vector>
using namespace std;
void rotate(vector<int> &nums,int k ){
    int n = nums.size();
    vector<int> ans(n);
    for(int index = 0; index < n;index++){
        int newIndex = (index+k)%n;
        ans[newIndex] = nums[index];
    }
    nums = ans;
}
int main(){
    vector<int> nums;
    int n ;
    cout<<"Enter the numbers that how many elements you want to insert : ";
    cin>>n;
    for(int i = 0; i < n;i++){
        int data;
        cin>>data;
        nums.push_back(data);
    }
    int k ;
    cout<<"how many rotations do you want : ";
    cin>>k;
    rotate(nums,k);
    for(int i = 0; i < n;i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}
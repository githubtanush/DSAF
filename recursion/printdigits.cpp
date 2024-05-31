#include<iostream>
#include<vector>
using namespace std;
void printnum(int num,vector<int> &ans ){
    if(num==0)
        return;
    
    int digit = num % 10;
    num = num/10;

    printnum(num,ans);
    ans.push_back(digit);

}
int main(){
    int num = 4217;
    vector<int> ans;
    cout<<"Printing digits : ";
    printnum(num,ans);
    int n = ans.size();
    for(int i = 0; i < n;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
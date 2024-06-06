#include<iostream>
#include<vector>
using namespace std;
void findSubsequence(string str,string output,int index,vector<string> &ans){
    if(index>=str.length()){
        //ans jo hai vo output string mein print ho chuka hai 
        //print krdo 
        ans.push_back(output);
        return ;
    }
    char ch = str[index];
    // //exclude
    // findSubsequence(str,output,index+1);

    // //include
    // output.push_back(ch);
    // findSubsequence(str,output,index+1);


    //firstly include then exclude
    //include
    output.push_back(ch);
    findSubsequence(str,output,index+1,ans);
    //exclude
    output.pop_back();
    findSubsequence(str,output,index+1,ans);
}
int main(){
    string str = "abc";
    string output="";
    int index = 0;
    vector<string> ans;
    findSubsequence(str,output,index,ans);
    cout<<"Printing the subsequences of vector : "<<endl;
    int n = ans.size();
    for(int i = 0; i < n;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
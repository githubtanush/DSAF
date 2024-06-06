#include<iostream>
using namespace std;
void findSubsequence(string str,string output,int index){
    if(index>=str.length()){
        //ans jo hai vo output string mein print ho chuka hai 
        //print krdo 
        cout<<"->"<<output<<endl;
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
    findSubsequence(str,output,index+1);
    //exclude
    output.pop_back();
    findSubsequence(str,output,index+1);
}
int main(){
    string str = "abc";
    string output="";
    int index = 0;
    findSubsequence(str,output,index);
    return 0;
}
#include<iostream>
using namespace std;
//by refrence pass krne se yeh answer glt ho rah hai aisa kyyu ? string ki copy par answer shi lekin jab pass by refrence kiya
//actual string mein change kiya to glt kyu ho rah hai 
void solve(string &str,int index){
    //base case
    if(index>=str.length()){
        cout<<str<<" ";
        return;
    }
    for(int j = index;j < str.length();j++){
            swap(str[index],str[j]);
             //recursion chacha
        solve(str,index+1);
        //backtracking = It is a simple recursion bss recursive call se vaapis aata hua kuch operation perform krne hota hai
        swap(str[index],str[j]);
    }
}
int main(){
    string str = "abc";
    int index = 0;
    solve(str,index);
    return 0;
}
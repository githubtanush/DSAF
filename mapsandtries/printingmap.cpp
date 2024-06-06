#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
//if u convert like this then it is in the form of sorted order if u write simple map
//and if u write unordered map then it will convert it into unsorted order
void countcharacters(map<char,int>& mapping,string str){
    for(int i = 0; i <str.length(); i++){
        char ch = str[i];
        mapping[ch]++;
    }
}
int main(){
    string str = "Tanush Arora";
    map<char,int> mapping;
    countcharacters(mapping,str);
    for(auto i = mapping.begin() ; i != mapping.end();i++){
        cout<<i->first<<"->"<<i->second<<endl;
    }
    return 0;
}
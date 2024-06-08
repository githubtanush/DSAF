#include<iostream>
#include<queue>
using namespace std;
int main(){
    string str = "ababc";
    queue<char> q;
    int freq[26] = {0};

    for(int i = 0; i < str.length();i++){
        char ch = str[i];
        freq[ch-'a']++;
        q.push(ch);

    //answer find
        while(!q.empty()){
            char frontcharacter = q.front();
            if(freq[frontcharacter-'a']>1){
                //yaani yeh answer nhi hai 
                q.pop();
            }
            else{
                //==1 wala case
                //yhi answer hai 
                cout<<frontcharacter<<"->";
                break;
            }
        }
        if(q.empty()){
            //koi answer nhi nikla
            cout<<"#"<<"->";
        }
    }
    return 0;
}
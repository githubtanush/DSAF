#include<iostream>
#include<stack>
using namespace std;
bool checkredundant(string str){
    stack<char> st;
    for(int i = 0; i<str.length();i++){
        char ch = str[i];
        if(ch=='('|| ch=='+'||ch=='-'||ch=='*'||ch=='/'|| ch=='%')
            st.push(ch);
        else if(ch==')'){
            int operatorCount = 0;
            while(!st.empty() && st.top()!='('){
                char temp = st.top();
                if(temp=='+'|| temp=='-'||temp=='*'||temp=='/'){
                    operatorCount++;
                }
                st.pop();
            }
            //yaah par tab hi phunchoga agr stack ke top par ek opening bracket hoga
            st.pop();
            if(operatorCount==0){
                return true;
            }
        }
    }
    //agr mein yaah tak phuncha hu eska matlab har ek bracket ke pair ke bich mein ek operator pkka mila hoga
    return false;
}
int main(){
    string str = "(((a+b)*(c+d)))";
    bool ans = checkredundant(str);
    if(ans==1){
        cout<<"Redundant bracket is present"<<endl;
    }
    else{
        cout<<"Redundant bracket is not present"<<endl;
    }
    return 0;
}
#include<iostream>
using namespace std;
bool isPalindrome(char ch[],int n ){
    int left = 0;
    int right = n - 1;
    while(left<right){
        if(ch[left]!=ch[right]){
            return false;
        }
        left++;
        right--;
    }
    return true;
}
int findlength(char ch[],int size){
    int length = 0;
    for(int i = 0; i < size;i++){
        if(ch[i]=='\0'){
            break;
        }
        else{
            length++;
        }
    }
    return length;
}
int main(){
    char ch[1000];
    cin.getline(ch,1000);
    int len = findlength(ch,1000); 
    bool co = isPalindrome(ch,len);
    if(co==1){
        cout<<"The valid string is palindromic string"<<endl;
    }
    else{
        cout<<"The valid string is not a palindromic string"<<endl;
    }
    return 0;
}
#include<iostream>
using namespace std;
//char array by default by refrence like integer array 
void reverse(char ch[],int size){
   int left = 0;
   int right = size - 1;
   while(left<right){
    swap(ch[left],ch[right]);
    left++;
    right--;
   }
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
void uppercase(char ch[],int n){
    int i = 0;
    while(ch[i]!='\0'){
        char curr = ch[i];
        //check if lowercase then convert it to uppercase
        if(curr>='a' && curr<='z'){
            ch[i] = curr - 'a'+'A';
        }
        i++;
    }
}
void lowercase(char ch[],int n){
    int i = 0;
    while(ch[i]!='\0'){
        char curr = ch[i];
        //check if lowercase then convert it to uppercase
        if(curr>='A' && curr<='Z'){
            ch[i] = curr - 'A'+'a';
        }
        i++;
    }
}
void replace(char ch[],int n){
    int i = 0;
    while(ch[i] != '\0'){
        char curr = ch[i];
        //check @ symbol
        if(curr=='@'){
            ch[i] = ' ';
        }
        i++;
    }
}
int main(){
    char ch[100];
    cin.getline(ch,100);
    cout<<ch<<endl;
    int len = findlength(ch,100); 
    //reverse(ch,100) by this they did not print because left at 0 and right at 99 so at 99 to all right there is always
    //written a null character that was why u must pass the length instead of 100 , 200
    reverse(ch,len);
    cout<<ch<<endl;
    //enka andar to hm length 100 vali bhi daal skta hai
    uppercase(ch,len);
    cout<<ch<<endl;
    lowercase(ch,len);
    cout<<ch<<endl;
    replace(ch,len);
    cout<<ch<<endl;
    return 0;
}
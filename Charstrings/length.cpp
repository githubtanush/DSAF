#include<iostream>
#include<string>
using namespace std;
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
    char ch[100];
    //take input for character array 
    cin.getline(ch,100);
    int len = findlength(ch,100); 
    cout<<"The length of the string is : "<<len<<endl;
    cout<<"The length by the inbuilt function is : "<<strlen(ch)<<endl;

    return 0;
}
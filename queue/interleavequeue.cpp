#include<iostream>
#include<queue>
using namespace std;
void interleaveQueue(queue<int>& first){
    queue<int> second;
    //push the first half of firt queue in second queue
    int size = first.size();
    for(int i = 0; i < size/2;i++){
        int temp = first.front();
        first.pop();
        second.push(temp);
    }
    //Merge both the halves
    //into the original array queue - named as first
    for(int i = 0; i< size/2;i++){
        int temp = second.front();
        second.pop();
        first.push(temp);
        temp = first.front();
        first.pop();
        first.push(temp);
    }
}
int main(){
        queue<int> q;
        q.push(10);
        q.push(20);
        q.push(30);
        q.push(40);
        q.push(50);
        q.push(60);
       interleaveQueue(q);
       while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
       }
    return 0;
}
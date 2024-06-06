#include<iostream>
#include<vector> 
using namespace std;
bool isSafe(int srcx,int srcy,int newx,int newy,int maze[][4],int row,int col,vector<vector<bool> >& visited){
    if(newx>=0 && newx<row && newy>=0 && newy < col && maze[newx][newy]==1 && visited[newx][newy]== false){
        return true;
    }
    else{
        return false;  
    }
}
void printAllpath(int maze[][4],int row ,int col,int srcx,int srcy,string &output,vector<vector<bool> >& visited){
        //base case 
        //destination coordinates are : [row-1][col-1]
        if(srcx == row-1 && srcy == col-1){
            //reached destination
            cout<<output<<endl;
            return ; 
        }
        //1 case solve kro and baaki recursion sambhal lega
        //UP
        //possibility hai - i.)path closed
        //ii.)out of bound
        ///iii.) jo already position visit hogyi hai vaah phir nhi jaana
        //inshort visited place par dobara nhi jaana
        //1.) case solve kro baaki recursion sambhal lega
        int newx = srcx-1;
        int newy = srcy;
        if(isSafe(srcx,srcy,newx,newy,maze,row,col,visited)){
            //mark visited
            visited[newx][newy] = true;
            //call recursion
            output.push_back('U');
            printAllpath(maze,row,col,newx,newy,output,visited);
            //backtracking
            output.pop_back();
            visited[newx][newy] = false;

        }


        //Right
        newx = srcx;
        newy = srcy+1;
        if(isSafe(srcx,srcy,newx,newy,maze,row,col,visited)){
            //mark visited
            visited[newx][newy] = true;
            //call recursion
            output.push_back('R');
            printAllpath(maze,row,col,newx,newy,output,visited);
            //backtracking
            output.pop_back();
            visited[newx][newy] = false;

        }

        //Down 
         newx = srcx+1;
         newy = srcy;
        if(isSafe(srcx,srcy,newx,newy,maze,row,col,visited)){
            //mark visited
            visited[newx][newy] = true;
            //call recursion
            output.push_back('D');
            printAllpath(maze,row,col,newx,newy,output,visited);
            //backtracking
            output.pop_back();
            visited[newx][newy] = false;

        }

        //Left
        newx = srcx;
         newy = srcy-1;
        if(isSafe(srcx,srcy,newx,newy,maze,row,col,visited)){
            //mark visited
            visited[newx][newy] = true;
            //call recursion
            output.push_back('L');
            printAllpath(maze,row,col,newx,newy,output,visited);
            //backtracking
            output.pop_back();
            visited[newx][newy] = false;

        }

}
int main(){
    int maze[4][4] = {
        {1,0,0,0},
        {1,1,0,0},
        {1,1,1,0},
        {1,1,1,1}
        };
    int row = 4;
    int col = 4;
    int srcx = 0;
    int srcy = 0;
    string output= "";
    //create visited 2D array 
    vector<vector<bool> >visited(row,vector<bool>(col,false));
    if(maze[0][0] == 0){
        //chuhiyan cannot move,as starting position is closed
        cout<<"No path exists"<<endl;
    }
    else{
        visited[srcx][srcy] = true;
         printAllpath(maze,row,col,srcx,srcy,output,visited);
    }
    return 0;
}
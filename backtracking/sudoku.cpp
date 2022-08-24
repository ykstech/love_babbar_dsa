#include<bits/stdc++.h>
using namespace std;

void print_2d_vector(vector<vector<int>> ans)
{
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}


bool isSafe(int row,int col,vector<vector<int>> board,int val){

for(int i=0;i<board.size();i++){

if(board[row][i]==val){
    return false;
}

if(board[i][col]==val){
    return false;
}

//3*3 matrix check//
if(board[3*(row/3) + i/3][3*(col/3)+ i%3]==val){
    return false;
}

}
return true;

}

bool solve(vector<vector<int>> &board){

    int n= board[0].size();
    for(int row=0;row<n;row++){
       for(int col=0;col<n;col++){

        //cell empty//
        if(board[row][col]==0){
            for(int val=1;val<=9;val++){
                  if(isSafe(row,col,board,val)){
                    board[row][col]=val;
                    bool safe_to_proceed= solve(board);
                    if(safe_to_proceed){
                        return true;
                    }else{
                        //backtrack//
                        board[row][col]=0;
                    }
                  }
            }
            return false;
        }
       }
    }
    return true;
}

int main(){

vector<vector<int>> sudoku= {
{3, 0, 6, 5, 0, 8, 4, 0, 0},
{5, 2, 0, 0, 0, 0, 0, 0, 0},
{0, 8, 7, 0, 0, 0, 0, 3, 1},
{0, 0, 3, 0, 1, 0, 0, 8, 0},
{9, 0, 0, 8, 6, 3, 0, 0, 5},
{0, 5, 0, 0, 9, 0, 6, 0, 0},
{1, 3, 0, 0, 0, 0, 2, 5, 0},
{0, 0, 0, 0, 0, 0, 0, 7, 4},
{0, 0, 5, 2, 0, 6, 3, 0, 0}
};
cout<<"question"<<endl;
print_2d_vector(sudoku);
solve(sudoku);
cout<<"\nsolution"<<endl;
print_2d_vector(sudoku);
cout<<endl;



}
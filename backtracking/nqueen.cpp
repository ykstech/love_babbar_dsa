#include <bits/stdc++.h>
using namespace std;

int count_m=0;
int count_m2=0;
int ld[30] = { 0 };   //not require for un optimise
int rd[30] = { 0 };  //not require for un optimise
int cl[30] = { 0 };  //not require for un optimise
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
//issafe require for un optimise//
bool isSafe(int row, int col, vector<vector<int>> &board, int n)
{

    int x = row;
    int y = col;

    // check for same row/
    while (y >= 0)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        y--;
    }

    x = row;
    y = col;
    while (x >= 0 && y >= 0)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        y--;
        x--;
    }

    x = row;
    y = col;
    while (x < n && y >= 0)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        y--;
        x++;
    }
    return true;
}

void optimise_solve(int col,  vector<vector<int>> &board, int n)
{
    if (col == n)
    { 
      //  cout<<"\n  ans "<<endl;
        count_m2++;
      //  print_2d_vector(board);
      //  cout<<endl;
        return;
    }


    // solve 1st case row swipping//
    for (int row = 0; row < n; row++)
    {
        if(col==0){
       //     cout<<"--------------------"<<endl;
        cout<<(row*100)/n<<"% ";
        }

    
        if((ld[row - col + n - 1] != 1 && rd[row + col] != 1) && cl[row] != 1)    //optimise if con//
       
        {    board[row][col] = 1;

            ld[row - col + n - 1] = rd[row + col] = cl[row] = 1; //not require for un optimise
         //   cout<<"for "<<row<<" "<<col<<endl;
            optimise_solve(col + 1, board, n);
            // backtrack
        //    cout<<"back "<<row<<" "<<col<<endl;
            board[row][col] = 0;
            ld[row - col + n - 1] = rd[row + col] = cl[row] = 0;  //not require for un optimise
        
        }
    }
}

void unoptimise_solve(int col,  vector<vector<int>> &board, int n){
      if (col == n)
    { 
      //  cout<<"\n  ans "<<endl;
        count_m++;
      //  print_2d_vector(board);
      //  cout<<endl;
        return;
    }


    // solve 1st case row swipping//
    for (int row = 0; row < n; row++)
    {
        if(col==0){
       //     cout<<"--------------------"<<endl;
        cout<<(row*100)/n<<"% ";
        }

        if (isSafe(row, col, board, n)) //un optimise takes big O(n*2) space// unoptimise if con//
        
        {    board[row][col] = 1;

         //   cout<<"for "<<row<<" "<<col<<endl;
            unoptimise_solve(col + 1, board, n);
            // backtrack
        //    cout<<"back "<<row<<" "<<col<<endl;
            board[row][col] = 0;
        
        }
    }

}

void unoptimise_nqueen(int n)
{

    vector<vector<int>> board(n, vector<int>(n, 0));
    

    unoptimise_solve(0,  board, n);

}


void optimise_nqueen(int n)
{

    vector<vector<int>> board(n, vector<int>(n, 0));
    

    optimise_solve(0,  board, n);

}

void optimisefn(int j,int k){
//optimised//

  for( j;j<=k;j++){
     
    cout<<"\n \n \n";
    count_m2=0;
    ld[30] = { 0 };   //not require for un optimise
    rd[30] = { 0 };  //not require for un optimise
    cl[30] = { 0 };  

     optimise_nqueen(j);
    
     cout<<"100% \n \npossible ways to place "<<j<<" queens in " <<j<<"x"<<j<<" matrix : "<<count_m2<<endl;
     cout<<"\nTime complexity big O("<<j<<")";
     cout<<"\noptimise Space complexity big O("<<j<<")\n";
     cout<<"----------------------------------"<<endl;
  }

}

void unoptimisefn(int i,int n){
 //unoptimised//
  
  for( i;i<=n;i++){
     
    cout<<"\n \n \n";
    count_m=0;

     unoptimise_nqueen(i);
    
     cout<<"100% \n \npossible ways to place "<<i<<" queens in " <<i<<"x"<<i<<" matrix : "<<count_m<<endl;
     cout<<"\nTime complexity big O("<<i<<"!)";
     cout<<"\nUnoptimise Space complexity big O("<<i<<"*"<<i<<")\n";
     cout<<"----------------------------------"<<endl;
  }
}

int main()
{
    
    optimisefn(1,5);

    unoptimisefn(1,5);
   


    cout<<"\n \n \n";
}
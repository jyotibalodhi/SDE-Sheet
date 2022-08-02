#include<bits/stdc++.h>   

bool isValid(vector<vector<int>> &b,int row, int col, int c){
        
        for(int i=0;i<9;i++){
            if(b[row][i]==c) return false;
            if(b[i][col]==c) return false;
            
           if (b[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) 
               return false;
        }
        
        return true;
    }
 bool solve(vector<vector<int>> &b){
     
        for(int i=0;i<b.size();i++){
            for(int j=0;j<b[0].size();j++){
                
                if(b[i][j]==0){
                    
                     for(int c=1;c<=9;c++){
                     if(isValid(b,i,j,c)){
                         
                         b[i][j]=c;
                         if(solve(b)){
                             return true;
                         }
                         else
                            b[i][j]=0;
                     }
                 }
                    
                    return false;
               }
            }
        }
        
        return true;  
    }
    

bool isItSudoku(int matrix[9][9]) {
    vector<vector<int>> board (9,vector<int> (9,0));
    
    for(int i =0;i<9;i++){
        for(int j=0;j<9;j++){
            board[i][j] = matrix[i][j];
        }
    }
   return solve(board);
}

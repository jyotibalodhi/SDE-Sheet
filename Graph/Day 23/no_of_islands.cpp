#include<bits/stdc++.h>

    void dfs(int** grid, int x, int y, int n, int m){

           if(x<0 || x>=n || y<0 || y>=m)
               return;
           if(grid[x][y]!=1)
               return;
        
           grid[x][y]=0;
           dfs(grid,x,y+1,n,m); // East
           dfs(grid,x,y-1,n,m); // West
           dfs(grid,x-1,y,n,m); // North
           dfs(grid,x+1,y,n,m); // South
           dfs(grid,x-1,y-1,n,m); // NorthWest
           dfs(grid,x+1,y-1,n,m); // SouthWest
           dfs(grid,x-1,y+1,n,m); // NorthEast
           dfs(grid,x+1,y+1,n,m); // SouthEast
    }
    

int getTotalIslands(int** arr, int n, int m)
{
        int cnt = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(arr[i][j]==1){
                    cnt++;
                    dfs(arr,i,j,n,m);
                }    
            }
        }
        return cnt;
}

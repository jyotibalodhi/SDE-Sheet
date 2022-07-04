  void dfs(vector<vector<int>>& image, int i, int j, int color, int parColor) {
        if(i<0 || i>=image.size() || j<0 || j>=image[0].size()) return;
        if(image[i][j]==parColor) {
            image[i][j]=color;
            
            
            dfs(image, i-1, j, color, parColor);
            dfs(image, i+1, j, color, parColor);
            dfs(image, i, j-1, color, parColor);
            dfs(image, i, j+1, color, parColor);
        }
        return;
    }

vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int color)
{
     if(image[x][y] == color) return image;
        dfs(image, x, y, color, image[x][y]);
        return image;
}
class Solution {    
    final int diff[][]={{0,-1},{0,1},{-1,0},{1,0}};
     private void dfs(char grid[][],int R,int C, int row, int col){
        grid[row][col]='0';
        for(int i=0;i<4;i++){
            int newRow=row+diff[i][0];
            int newCol=col+diff[i][1];
            if(newRow>=0 && newRow<R && newCol>=0 && newCol<C && grid[newRow][newCol]=='1')
                dfs(grid,R,C,newRow,newCol);
        }
    }
    public int numIslands(char[][] grid) {
        int R=grid.length;
        int C=grid[0].length;
        int count=0;
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(grid[i][j]=='1'){
                    count++;
                    dfs(grid,R,C,i,j);
                }
            }
        }
        return count;
    }
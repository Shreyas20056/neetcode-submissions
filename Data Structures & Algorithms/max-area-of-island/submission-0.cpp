class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int area=dfs(grid,i,j,m,n);
                    maxArea=max(maxArea,area);
                }
            }
        }
        return maxArea;
    }
    int dfs(vector<vector<int>> &grid,int i,int j,int m,int n){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]==0){
            return 0;
        }
        grid[i][j]=0;
        int res=1;
        res+=dfs(grid,i-1,j,m,n);
        res+=dfs(grid,i+1,j,m,n);
        res+=dfs(grid,i,j-1,m,n);
        res+=dfs(grid,i,j+1,m,n);
        return res;
    }
};

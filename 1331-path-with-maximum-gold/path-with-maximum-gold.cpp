class Solution {
    int solve(int i,int j,int n,int m,vector<vector<int>> &grid)
    {
        if(i>=n || j>=m || i<0 || j<0 || grid[i][j]==0) return 0;

        int orry=grid[i][j];
        grid[i][j]=0;
        int ans=INT_MIN;
        ans=max(max(solve(i+1,j,n,m,grid),solve(i-1,j,n,m,grid)),max(solve(i,j+1,n,m,grid),solve(i,j-1,n,m,grid)));

        grid[i][j]=orry;

        return ans+orry;
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]!=0) ans=max(ans,solve(i,j,n,m,grid));
            }
        }
        
        return ans;
    }
};
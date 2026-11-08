class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int> row(n,0),col(m,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j])
                {
                    row[i]++;
                    col[j]++;
                }
            }
        }
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            if(row[i]>1)
            {
                for(int j=0;j<m;j++) {
                    if(grid[i][j]) vis[i][j]=1;
                }
            }
        }
        for(int j=0;j<m;j++)
        {
            if(col[j]>1)
            {
                for(int i=0;i<n;i++) {
                    if(grid[i][j]) vis[i][j]=1;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ans+=vis[i][j];
            }
        }
        return ans;
    }
};
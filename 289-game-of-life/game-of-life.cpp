class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]) board[i][j]=3;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int live=0;
                int died=0;
                int dr[8]={-1,-1,-1,0,0,1,1,1};
                int dc[8]={-1,0,1,-1,1,-1,0,1};
                for(int k=0;k<8;k++)
                {
                    int r=i+dr[k];
                    int c=j+dc[k];
                    if(r>=0 && c>=0 && r<n && c<m)
                    {
                        if(board[r][c]>0) live++;
                        else died++;
                    } 
                }
                if(board[i][j]>0)
                {
                    if(live<2) board[i][j]=1;
                    else if(live==2 || live==3) board[i][j]=3;
                    else board[i][j]=1;
                }
                else
                {
                    if(live==3) board[i][j]=-1;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==1) board[i][j]=0;
                else if(board[i][j]==-1 || board[i][j]==3) board[i][j]=1;
                
            }
        }
    }
};
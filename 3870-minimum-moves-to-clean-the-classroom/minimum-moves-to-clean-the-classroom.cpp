class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {

        int m = classroom.size();
        int n = classroom[0].size();

        int sx = 0, sy = 0;
        int k = 0;

        vector<vector<int>> id(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (classroom[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }

                if (classroom[i][j] == 'L') {
                    id[i][j] = k++;
                }
            }
        }

        int target = (1 << k) - 1;

        // vis[x][y][mask] = max energy seen
        vector<vector<vector<int>>> vis(
            m, vector<vector<int>>(n, vector<int>((1 << k), -1)));

        queue<vector<int>> q;

        q.push({sx, sy, 0, energy, 0}); // x,y,mask,energy,moves

        vis[sx][sy][0] = energy;

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        while (!q.empty()) {

            auto cur = q.front();
            q.pop();

            int x = cur[0];
            int y = cur[1];
            int mask = cur[2];
            int e = cur[3];
            int moves = cur[4];

            if (mask == target)
                return moves;

            for (int d = 0; d < 4; d++) {

                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                    continue;

                if (classroom[nx][ny] == 'X')
                    continue;

                if (e == 0)
                    continue;

                int ne = e - 1;
                int nmask = mask;

                if (classroom[nx][ny] == 'R')
                    ne = energy;

                if (classroom[nx][ny] == 'L')
                    nmask |= (1 << id[nx][ny]);

                // already reached with better/equal energy
                if (vis[nx][ny][nmask] >= ne)
                    continue;

                vis[nx][ny][nmask] = ne;

                q.push({nx, ny, nmask, ne, moves + 1});
            }
        }

        return -1;
    }
};
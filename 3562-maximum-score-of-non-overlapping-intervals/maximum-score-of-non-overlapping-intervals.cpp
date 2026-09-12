class Solution {
public:
    struct Node {
        long long sum;
        vector<int> idx;

        Node(long long s = 0, vector<int> v = {}) : sum(s), idx(move(v)) {}
    };

    vector<vector<long long>> vis;
    vector<vector<Node>> memo;

    vector<vector<int>> arr;
    vector<int> starts;
    vector<int> nxt;
    int n;

    Node better(const Node& a, const Node& b) {
        if (a.sum != b.sum)
            return (a.sum > b.sum ? a : b);

        return (a.idx < b.idx ? a : b);
    }

    Node dfs(int i, int rem) {
        if (i == n || rem == 0)
            return Node();

        if (vis[i][rem])
            return memo[i][rem];

        vis[i][rem] = 1;

        Node skip = dfs(i + 1, rem);

        Node take = dfs(nxt[i], rem - 1);
        take.sum += arr[i][2];
        take.idx.push_back(arr[i][3]);

        sort(take.idx.begin(), take.idx.end());

        memo[i][rem] = better(skip, take);
        return memo[i][rem];
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        n = intervals.size();

        arr.clear();

        for (int i = 0; i < n; i++) {
            arr.push_back(
                {intervals[i][0], intervals[i][1], intervals[i][2], i});
        }

        sort(arr.begin(), arr.end());

        starts.resize(n);
        for (int i = 0; i < n; i++)
            starts[i] = arr[i][0];

        nxt.resize(n);

        for (int i = 0; i < n; i++) {
            nxt[i] = lower_bound(starts.begin(), starts.end(), arr[i][1] + 1) -
                     starts.begin();
        }

        vis.assign(n + 1, vector<long long>(5, 0));
        memo.assign(n + 1, vector<Node>(5));

        return dfs(0, 4).idx;
    }
};
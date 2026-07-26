class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1,
                                            vector<vector<int>>& series2) {

        set<int> st;

        for (auto &x : series1)
            st.insert(x[0]);

        for (auto &x : series2)
            st.insert(x[0]);

        vector<vector<int>> ans;

        for (int t : st) {

            int v1 = 0;
            int v2 = 0;

            auto it1 = lower_bound(series1.begin(), series1.end(),
                                   vector<int>{t, INT_MIN});

            if (it1 != series1.end())
                v1 = (*it1)[1];

            auto it2 = lower_bound(series2.begin(), series2.end(),
                                   vector<int>{t, INT_MIN});

            if (it2 != series2.end())
                v2 = (*it2)[1];

            ans.push_back({t, v1 + v2});
        }

        return ans;
    }
};
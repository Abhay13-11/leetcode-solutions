class Solution {
    void solve(int ind, string& s, vector<string>& ans, int n) {
        if (ind == n) {
            ans.push_back(s);
            return;
        }

        if (s.empty() || s.back()!='0') {
            s += '0';
            solve(ind + 1, s, ans, n);
            s.pop_back();
        }


      s += '1';
        solve(ind + 1, s, ans, n);
        s.pop_back();

      
    }

public:
    vector<string> validStrings(int n) {
        vector<string> ans;
        string s = "";
        solve(0, s, ans, n);
        return ans;
    }
};
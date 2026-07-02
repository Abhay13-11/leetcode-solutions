class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
            return "1";
        int i;
        string s = "1";
        string ans = "";
        for (int j = 0; j < n - 1; j++) {
            int count = 1;
            for (i = 0; i < s.size() - 1; i++) {
                if (s[i] == s[i + 1])
                    count++;
                else {
                    ans += to_string(count);
                    ans += s[i];

                    count = 1;
                }
            }
            ans += to_string(count);
            ans += s[i];
            count = 1;

            s = ans;
            ans = "";
        }
    
    return s;
}
}
;
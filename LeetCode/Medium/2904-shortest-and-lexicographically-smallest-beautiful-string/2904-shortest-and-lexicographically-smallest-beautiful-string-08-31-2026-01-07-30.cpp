class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        // Base case
        if (count(s.begin(), s.end(), '1') < k) return "";

        string ans = s;
        int left = 0, cnt = left, n = s.size();
    
        for (int right = 0; right < n; ++right) {
            cnt += s[right] - 48;

            while (s[left] == '0' || cnt > k) {
                cnt -= s[left++] - 48;
            }

            if (cnt == k) {
                string t = s.substr(left, right - left + 1);
                if (t.size() < ans.size() || ((t.size() == ans.size()) && (t < ans))) ans = move(t);
            }
        }

        return ans;
    }
};
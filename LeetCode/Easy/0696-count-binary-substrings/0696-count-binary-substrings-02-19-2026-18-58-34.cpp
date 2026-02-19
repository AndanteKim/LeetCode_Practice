class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> groups {1};

        for (int i = 1; i < s.size(); ++i) {
            if (s[i - 1] != s[i]) groups.push_back(1);
            else ++groups.back();
        }
        
        int ans = 0;
        for (int i = 1; i < groups.size(); ++i) {
            ans += min(groups[i - 1], groups[i]);
        }
        
        return ans;
    }
};
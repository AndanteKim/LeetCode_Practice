class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> first(26, -1), last(26, -1);

        for (int i = 0; i < s.size(); ++i){
            if (first[s[i] - 97] == -1)
                first[s[i] - 97] = i;
            last[s[i] - 97] = i;
        }

        int ans = 0;
        for (int i = 0; i < 26; ++i){
            if (first[i] == -1) continue;

            unordered_set<char> between;
            for (int j = first[i] + 1; j < last[i]; ++j)
                between.insert(s[j]);
            ans += between.size();
        }

        return ans;
    }
};
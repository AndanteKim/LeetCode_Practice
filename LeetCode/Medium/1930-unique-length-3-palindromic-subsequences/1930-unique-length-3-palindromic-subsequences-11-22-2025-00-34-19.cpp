class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<int> first(26, -1), last(26, -1);
        
        for (int i = 0; i < n; ++i){
            int curr = s[i] - 'a';
            if (first[curr] == -1) first[curr] = i;

            last[curr] = i;
        }

        int ans = 0;

        for (int i = 0; i < 26; ++i) {
            if (first[i] == -1) continue;
            
            unordered_set<char> between;

            for (int j = first[i] + 1; j < last[i]; ++j)
                between.insert(s[j]);
            
            ans += between.size();
        }

        return ans;
    }
};
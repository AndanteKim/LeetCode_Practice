class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> counts;
        for (char& c : s) ++counts[c];
        int ans = 0;
        
        for (auto& [key, val] : counts){
            ans += (val / 2) * 2;
            if (val % 2 && !(ans % 2)) ++ans;
        }
        return ans;
    }
};
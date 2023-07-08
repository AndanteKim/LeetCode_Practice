class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int ans = 0, n = s.size();
        unordered_map<char, int> count;
        
        for (int right = 0; right < n; ++right){
            ++count[s[right]];
            if (count.size() <= k) ++ans;
            else{
                --count[s[right - ans]];
                if (count[s[right - ans]] == 0) count.erase(s[right - ans]);
            }
        }
        
        return ans;
    }
};
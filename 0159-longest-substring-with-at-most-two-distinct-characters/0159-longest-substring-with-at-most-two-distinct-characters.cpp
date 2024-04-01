class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char, int> freq;
        int left = 0, ans = 0;
        
        for (int right = 0; right < s.size(); ++right){
            ++freq[s[right]];
            
            while (freq.size() > 2 && left < right){
                --freq[s[left]];
                if (freq[s[left]] == 0) freq.erase(s[left]);
                ++left;
            }
            
            ans = max(ans, right - left + 1);
        }
        
        return ans;
    }
};
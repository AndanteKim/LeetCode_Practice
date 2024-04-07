class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, ans = 0;
        unordered_map<char, int> chars;
        for (int right = 0; right < s.size(); ++right){
            ++chars[s[right]];
            while (chars[s[right]] > 1 && left <= right){
                --chars[s[left++]];
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
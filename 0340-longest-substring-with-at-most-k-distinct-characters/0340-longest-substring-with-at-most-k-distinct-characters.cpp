class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int ans = 0, curr = 0, left = 0, n = s.size();
        unordered_map<char, int> count;
        
        for (int right = 0; right < n; ++right){
            char add = s[right];
            if (count.find(add) == count.end()) ++curr;
            ++count[add];
            while (count.size() > k){
                --count[s[left]];
                if (count[s[left]] == 0) count.erase(s[left]);
                ++left;
            }
            
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
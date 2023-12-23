class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n = s.size();
        if (n < 3)
            return n;
        
        // sliding window left and right pointers
        int left = 0, right = 0, maxLen = 2;
        // hashmap character -> its rightmost position
        // in the sliding window
        unordered_map<char, int> hashmap;
        
        while (right < n){
            // when the sliding window contains less than 3 characters
            hashmap[s[right]] = right;
            ++right;
            
            // sliding window contains 3 characters
            if (hashmap.size() == 3){
                auto[_, delIdx] = *min_element(hashmap.begin(), hashmap.end(), [](auto& l, auto& r){return l.second < r.second;});
                // delete the leftmost character
                hashmap.erase(s[delIdx]);
                left = delIdx + 1;
            }
            
            maxLen = max(maxLen, right - left);
        }
        
        return maxLen;
    }
};
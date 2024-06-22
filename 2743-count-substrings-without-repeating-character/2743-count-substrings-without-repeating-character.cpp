class Solution {
public:
    int numberOfSpecialSubstrings(string s) {
        vector<int> chars(26);
        int ans = 0, start = 0;
        
        for (int end = 0; end < s.size(); ++end){
            while (chars[s[end] - 97] == 1 && start <= end)
                --chars[s[start++] - 97];
            
            ++chars[s[end] - 97];
            ans += end - start + 1;
        }
        
        return ans;
    }
};
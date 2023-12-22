class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        vector<int> smallChars(26), capitalChars(26);
        unordered_set<char> twoChars;
        int n = s.size(), left = 0, ans = 0;
        
        for (int right = 0; right < n; ++right){
            if (twoChars.find(s[right]) == twoChars.end()){
                while (twoChars.size() >= 2 && left < right){
                    if (0 <= s[left] - 65 && s[left] - 65 < 26){
                        --capitalChars[s[left] - 65];
                        if (capitalChars[s[left] - 65] == 0)
                            twoChars.erase(s[left]);
                    }
                    else{
                        --smallChars[s[left] - 97];
                        if (smallChars[s[left] - 97] == 0)
                            twoChars.erase(s[left]);
                    }
                    ++left;
                }
                twoChars.insert(s[right]);
            }
            
            if (0 <= s[right] - 65 && s[right] - 65 < 26)
                ++capitalChars[s[right] - 65];
            else
                ++smallChars[s[right] - 97];
            int longest = 0;
            for (int i = 0; i < 26; ++i){
                longest += smallChars[i];
                longest += capitalChars[i];
            }
            
            ans = max(ans, longest);
        }
        
        return ans;
    }
};
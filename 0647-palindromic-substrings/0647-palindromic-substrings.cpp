class Solution {
private:
    int countPalindromesAroundCenter(string& ss, int lo, int hi){
        int ans = 0;
        
        while (lo >= 0 && hi < ss.size()){
            // check the first and last characters don't match and expand around the center
            if (ss[lo--] != ss[hi++])
                break;
            
            ++ans;
        }
        
        return ans;
    }
    
public:
    int countSubstrings(string s) {
        int ans = 0;
        
        for (int i = 0; i < s.size(); ++i){
            // odd-length of palindromes, single character center
            ans += countPalindromesAroundCenter(s, i, i);
            
            // even-length of palindromes, consecutive characters center
            ans += countPalindromesAroundCenter(s, i, i + 1);
        }
        
        return ans;
    }
};
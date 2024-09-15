class Solution {
public:
    int findTheLongestSubstring(string s) {
        // XOR bitmasking
        int prefixXOR = 0, ans = 0;
        
        // Consider max of mp would be 31 and count the just one character if any of vowels are odd.
        vector<int> charMap(26, 0), mp(32, -1);
        charMap['a' - 97] = 1;
        charMap['e' - 97] = 2;
        charMap['i' - 97] = 4;
        charMap['o' - 97] = 8;
        charMap['u' - 97] = 16;
        
        for (int i = 0; i < s.size(); ++i){
            prefixXOR ^= charMap[s[i] - 97];
            
            // If one of vowels is odd and there's no updated in mp
            if (mp[prefixXOR] == -1 && prefixXOR != 0)
                mp[prefixXOR] = i;
            
            ans = max(ans, i - mp[prefixXOR]);
        }
        
        return ans;
    }
};
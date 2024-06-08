class Solution {
public:
    long long numberOfSubstrings(string s) {
        long long ans = 0;
        vector<int> prefixCount(26);
        
        for (char& c:s){
            // Increment the number of times we encountered the current letter so far.
            ++prefixCount[c - 'a'];
            
            // Current letter can be paired with all the occurrences of it that
            // comes before, including itself, to form a valid substring.
            ans += prefixCount[c - 'a'];
        }
        
        return ans;
    }
};
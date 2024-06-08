class Solution {
public:
    long long numberOfSubstrings(string s) {
        long long ans = 0;
        vector<int> freqCount(26);
        
        // Count the frequency of each character in the string.
        for (char& c:s){
            ++freqCount[c - 'a'];
        }
        
        // Calculate the total number of valid substrings.
        for (int currCount:freqCount){
            // Using (currCount + 1) choose 2 to calcualte valid substrings
            // for the current letter.
            ans += (long long)currCount * (currCount + 1) >> 1;
        }
        
        return ans;
    }
};
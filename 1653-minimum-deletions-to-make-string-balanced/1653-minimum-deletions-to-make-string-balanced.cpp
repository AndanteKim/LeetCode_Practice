class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size(), aCount = count(s.begin(), s.end(), 'a'), bCount = 0;
        int minDeletions = n;
        
        // Second pass: Iterate through the string to compute minimum deletions
        for (int i = 0; i < n; ++i){
            if (s[i] == 'a') --aCount;
            minDeletions = min(minDeletions, aCount + bCount);
            if (s[i] == 'b') ++bCount;
        }
        
        return minDeletions;
    }
};
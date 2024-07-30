class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size(), bCount = 0;
        
        // MinDeletions variable represents dp[i]
        int minDeletions = 0;
        
        for (int i = 0; i < n; ++i){
            if (s[i] == 'b')
                ++bCount;
            else
                // Two cases: Remove 'a' or keep 'a'
                minDeletions = min(minDeletions + 1, bCount);
        }
        
        return minDeletions;
    }
};
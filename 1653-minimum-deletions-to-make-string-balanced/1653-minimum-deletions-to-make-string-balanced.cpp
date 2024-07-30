class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> countA(n), countB(n);
        
        int bCount = 0;
        // First pass: Compute bCount storing the number of 
        // 'b' characters to the left of current position.
        for (int i = 0; i < n; ++i){
            countB[i] = bCount;
            if (s[i] == 'b')
                ++bCount;
        }
        
        int aCount = 0;
        // Second pass: Compute aCount storing the number of 
        // 'a' characters to the right of current position.
        for (int i = n - 1; i >= 0; --i){
            countA[i] = aCount;
            if (s[i] == 'a')
                ++aCount;
        }
        
        int minDeletions = n;
        // Third pass: Iterate through the string to find the minimum deletions
        for (int i = 0; i < n; ++i)
            minDeletions = min(minDeletions, countA[i] + countB[i]);
        
        return minDeletions;
    }
};
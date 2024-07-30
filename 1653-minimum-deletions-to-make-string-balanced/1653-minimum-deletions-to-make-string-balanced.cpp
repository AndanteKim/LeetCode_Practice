class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> countA(n);
        int aCount = 0;
        
        // First pass: Compute countA storing the number of 
        // 'a' character to the right of the current position
        for (int i = n - 1; i >= 0; --i){
            countA[i] = aCount;
            if (s[i] == 'a')
                ++aCount;
        }
        
        // Second pass: Compute minimum deletions on the fly
        int bCount = 0, minDeletions = n;
        for (int i = 0; i < n; ++i){
            minDeletions = min(minDeletions, countA[i] + bCount);
            if (s[i] == 'b') ++bCount;
        }
        
        return minDeletions;
    }
};
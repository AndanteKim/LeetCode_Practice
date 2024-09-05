class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size(), needed = mean * (m + n);
        
        for (int roll : rolls)
            needed -= roll;
        
        // Base case
        if (n > needed || 6 * n < needed)
            return vector<int>{};
        
        int nAverage = needed / n, remain = needed - (nAverage * n), i = 0;
        vector<int> missing(n, nAverage);
        
        while (remain > 0){
            if (missing[i % n] >= 1 && missing[i % n] < 6){
                ++missing[i % n];
                --remain;
            }
            ++i;
        }
        
        return missing;
    }
};
class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sumRolls = accumulate(rolls.begin(), rolls.end(), 0);
        
        // Find the remaining sum.
        int remainingSum = mean * (rolls.size() + n) - sumRolls;
        
        // Check the valid sum or not
        if (n > remainingSum || 6 * n < remainingSum)
            return vector<int>{};
        
        int distributeMean = remainingSum / n;
        int mod = remainingSum % n;
        
        // Distribute the remaining mod elements in nElements list.
        vector<int> nElements(n, distributeMean);
        for (int i = 0; i < mod; ++i)
            ++nElements[i];
        
        return nElements;
    }
};
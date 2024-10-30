class Solution {
private:
    int n;
    void longestSubsequence(vector<int>& v, vector<int>& LS){
        LS.resize(n, 1);
        vector<int> lis{v[0]};
        
        for (int i = 1; i < n; ++i){
            // Index of the first element which is equal to or greater than
            // v[i].
            int index = lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin();
            
            // Add to the list if v[i] is greater than the last element.
            if (index == lis.size())
                lis.push_back(v[i]);
            else
                // Assign the value v[i] to the returned index as it's going to
                // smaller than or equal to the existing element.
                lis[index] = v[i];
            
            LS[i] = lis.size();
        }
    }
    
public:
    int minimumMountainRemovals(vector<int>& nums) {
        this -> n = nums.size();
        vector<int> LISLength, LDSLength;
        longestSubsequence(nums, LISLength);
        reverse(nums.begin(), nums.end());
        longestSubsequence(nums, LDSLength);
        // Reverse the length array to correctly depict the length of longest
        // decreasing subsequence for each index.
        reverse(LDSLength.begin(), LDSLength.end());
        
        int minRemovals = INT_MAX;
        
        for (int i = 0; i < n; ++i){
            if (LISLength[i] > 1 && LDSLength[i] > 1)
                minRemovals = min(minRemovals, n - (LISLength[i] + LDSLength[i] - 1));
        }
            
        return minRemovals;
    }
};
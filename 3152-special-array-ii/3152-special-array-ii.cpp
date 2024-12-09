class Solution {
private:
    bool binarySearch(int start, int end, vector<int>& violatingIndices){
        int left = 0, right = violatingIndices.size() - 1;
        
        while (left <= right){
            int mid = left + ((right - left) >> 1);
            int violatingIndex = violatingIndices[mid];
            
            if (violatingIndex < start)
                // Check the right half
                left = mid + 1;
            
            else if (violatingIndex > end)
                // Check the left half
                right = mid - 1;
            
            else
                // violatingIndex falls in between start and end
                return true;
            
        }
        
        return false;
    }
    
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), q = queries.size();
        vector<int> violatingIndices;
        
        for (int i = 1; i < n; ++i)
            // same parity, found violating index
            if (nums[i] % 2 == nums[i - 1] % 2)
                violatingIndices.push_back(i);
        
        
        vector<bool> ans(q, false);
        for (int i = 0; i < q; ++i){
            int start = queries[i][0], end = queries[i][1];
            
            bool foundViolatingIndex = binarySearch(start + 1, end, violatingIndices);
            
            if (foundViolatingIndex)
                ans[i] = false;
            else
                ans[i] = true;
        }
        
        return ans;
    }
};
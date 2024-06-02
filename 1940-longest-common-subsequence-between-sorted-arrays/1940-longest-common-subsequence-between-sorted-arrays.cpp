class Solution {
private:
    bool binarySearch(int target, const vector<int>& nums){
        int left = 0, right = nums.size() - 1;
        
        while (left <= right){
            int mid = (left + right) >> 1;
            if (nums[mid] > target)
                right = mid - 1;
            else if (nums[mid] < target)
                left = mid + 1;
            else
                return true;
        }
        
        return false;
    }
    
public:
    vector<int> longestCommonSubsequence(vector<vector<int>>& arrays) {
        vector<int> shortestArrays = arrays[0];
        
        for (const vector<int>& arr : arrays)
            if (shortestArrays.size() > arr.size())
                shortestArrays = arr;
        
        vector<int> longestCommonSubseq = shortestArrays;
        for (const vector<int>& arr : arrays){
            // There are no elements that are common to all of the arrays
            if (longestCommonSubseq.empty()) return longestCommonSubseq;
            
            // Remove any elements from the longest common subsequence
            // that are not in current array
            vector<int> uncommon;
            for (int num : shortestArrays)
                if (!binarySearch(num, arr))
                    uncommon.push_back(num);
            
            for (int num : uncommon){
                longestCommonSubseq.erase(remove(longestCommonSubseq.begin(), longestCommonSubseq.end(), num),
                                         longestCommonSubseq.end());
            }
        }
        
        return longestCommonSubseq;
    }
};
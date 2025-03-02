class Solution {
private:
    int countNums(vector<vector<int>>& nums){
        int count = 0;
        for (const auto& num : nums)
            count = max(count, num[0]);
        
        return count + 1;
    }

    void merge(vector<int>& rows, vector<vector<int>>& nums){
        for (const auto& num : nums){
            int id = num[0], val = num[1];
            rows[id] += val;
        }
    }

public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int maxCount = countNums(nums1);
        maxCount = max(maxCount, countNums(nums2));

        vector<int> rows(maxCount);

        merge(rows, nums1);
        merge(rows, nums2);
        
        vector<vector<int>> ans;

        for (int i = 0; i < rows.size(); ++i){
            if (rows[i] > 0)
                ans.push_back({i, rows[i]});
        }
        return ans;
    }
};
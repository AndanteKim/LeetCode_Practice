class Solution {
    void counting_sort(vector<int>& nums){
        unordered_map<int, int> counts;
        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());
        for (int num : nums) ++counts[num];
        
        int index = 0;
        for (int val = minVal; val <= maxVal; ++val){
            while(counts[val] > 0){
                nums[index] = val;
                --counts[val];
                ++index;
            }
        }
    }
    
public:
    vector<int> sortArray(vector<int>& nums) {
        counting_sort(nums);
        return nums;
    }
};
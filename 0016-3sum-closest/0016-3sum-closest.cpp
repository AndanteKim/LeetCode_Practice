class Solution {
private:
    int n;
    int twoSum(vector<int>& nums, int startIndex, int target){
        int left = startIndex, right = n - 1, curr = nums[left] + nums[right];
        
        while (left < right){
            if (nums[left] + nums[right] == target) return target;
            else if (nums[left] + nums[right] < target){
                if (abs(curr - target) > abs(nums[left] + nums[right] - target))
                    curr = nums[left] + nums[right];
                ++left;
            }
            else{
                if (abs(curr - target) > abs(nums[left] + nums[right] - target))
                    curr = nums[left] + nums[right];
                --right;
            }
        }
        
        return curr;
    }
    
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = 100'000;
        this -> n = nums.size();
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 2; ++i){
            int curr = nums[i] + twoSum(nums, i + 1, target - nums[i]);
            if (abs(ans - target) > abs(curr - target)) ans = curr;
        }
        
        return ans;
    }
};
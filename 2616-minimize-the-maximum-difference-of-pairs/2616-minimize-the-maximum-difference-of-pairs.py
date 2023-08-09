class Solution {
private:
    int n;
    int countValidPairs(int threshold, vector<int>& nums){
        int count = 0, index = 0;
        while (index < n - 1){
            if (nums[index + 1] - nums[index] <= threshold){
                ++count;
                ++index;
            }
            ++index;
        }
        return count;
    }
    
public:
    int minimizeMax(vector<int>& nums, int p) {
        this -> n = nums.size();
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.back();
        while (left < right){
            int mid = left + ((right - left) >> 1);
            if (countValidPairs(mid, nums) >= p)
                right = mid;
            else
                left = mid + 1;
        }
        
        return left;
    }
};
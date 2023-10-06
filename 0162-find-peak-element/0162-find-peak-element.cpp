class Solution {
private:
    int search(vector<int>& nums, int left, int right){
        if (left == right)
            return left;
        
        int mid = left + ((right - left) >> 1);
        if (nums[mid] > nums[mid + 1])
            return search(nums, left, mid);
        return search(nums, mid + 1, right);
    }
    
public:
    int findPeakElement(vector<int>& nums) {
        return search(nums, 0, nums.size() - 1);
    }
};
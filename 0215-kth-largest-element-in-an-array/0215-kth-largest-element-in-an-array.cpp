class Solution {
    int partition(int left, int right, int pivot_index, vector<int>& nums){
        int pivot = nums[pivot_index];
        swap(nums[pivot_index], nums[right]);
        
        int store_index = left;
        for (int i = left; i <= right; ++i){
            if (nums[i] < pivot){
                swap(nums[store_index], nums[i]);
                ++store_index;
            }
        }
        
        swap(nums[right], nums[store_index]);
        return store_index;
    }
    
    int select(int left, int right, int k_smallest, vector<int>& nums){
        if (left == right) return nums[left];
        int pivot_index = (rand() % (right - left)) + left;
        pivot_index = partition(left, right, pivot_index, nums);
        
        if (k_smallest == pivot_index) return nums[k_smallest];
        else if (k_smallest < pivot_index) return select(left, pivot_index - 1, k_smallest, nums);
        else return select(pivot_index + 1, right, k_smallest, nums);
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        return select(0, nums.size() - 1, nums.size() - k, nums);
    }
};
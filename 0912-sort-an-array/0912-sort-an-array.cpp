class Solution {
    void heapify(vector<int>& nums, int n, int i){
        int largest = i, left = 2 * i + 1, right = 2 * i + 2;
        if (left < n && nums[left] > nums[largest]) largest = left;
        if (right < n && nums[right] > nums[largest]) largest = right;
        
        if (largest != i){
            swap(nums[i], nums[largest]);
            heapify(nums, n, largest);
        }
    }
    
    void heapSort(vector<int>& nums){
        int n = nums.size();
        for (int i = n / 2 - 1; i >= 0; --i) heapify(nums, n, i);
        for (int i = n - 1; i >= 0; --i) {
            swap(nums[0], nums[i]);
            heapify(nums, i, 0);
        }
    }
    
public:
    vector<int> sortArray(vector<int>& nums) {
        heapSort(nums);
        return nums;
    }
};
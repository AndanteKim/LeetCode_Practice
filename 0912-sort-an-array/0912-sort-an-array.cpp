class Solution {
    void merge(vector<int>& nums, int left, int mid, int right, vector<int>& tempArr){
        int start1 = left, start2 = mid + 1;
        int n1 = mid - left + 1, n2 = right - mid;
        
        for (int i = 0; i < n1; ++i) tempArr[start1 + i] = nums[start1 + i];
        for (int i = 0; i < n2; ++i) tempArr[start2 + i] = nums[start2 + i];
        
        int i = 0, j = 0, k = left;
        
        while (i < n1 && j < n2){
            if (tempArr[start1 + i] <= tempArr[start2 + j]) {
                nums[k] = tempArr[start1 + i];
                ++i;
            }
            else {
                nums[k] = tempArr[start2 + j];
                ++j;
            }
            ++k;
        }
        
        while (i < n1){
            nums[k] = tempArr[start1 + i];
            ++i;
            ++k;
        }
        
        while (j < n2){
            nums[k] = tempArr[start2 + j];
            ++j;
            ++k;
        }
    }
    
    void mergeSort(vector<int>& nums, int left, int right, vector<int>& tempArr){
        if (left >= right) return;
        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid, tempArr);
        mergeSort(nums, mid + 1, right, tempArr);
        merge(nums, left, mid, right, tempArr);
    }
    
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> tempArray(nums.size());
        mergeSort(nums, 0, nums.size() - 1, tempArray);
        return nums;
    }
};
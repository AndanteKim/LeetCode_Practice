class Solution {
private:
    bool compare(int firstNum, int secondNum){
        // Compare concatenated strings to decide the order
        return to_string(firstNum) + to_string(secondNum) > to_string(secondNum) + to_string(firstNum);
    }
    
    int partition(vector<int>& nums, int left, int right){
        int pivot = nums[right];
        int lowIndex = left;
        
        // Rearrange elements, so that those greater than the pivot are on the left
        for (int i = left; i < right; ++i){
            if (compare(nums[i], pivot)){
                swap(nums[i], nums[lowIndex++]);
            }
        }
        
        // Place the pivot in its correct position
        swap(nums[lowIndex], nums[right]);
        return lowIndex;
    }
    
    void quickSort(vector<int>& nums, int left, int right){
        // Base case: If the range has one or no elements, it's already sorted
        if (left >= right) return;
        
        // Partition the array and get the pivot index
        int pivot = partition(nums, left, right);
        
        // Recursively sort the sub-arrays
        quickSort(nums, left, pivot - 1);
        quickSort(nums, pivot + 1, right);
    }
    
public:
    string largestNumber(vector<int>& nums) {
        // Sort the numbers using Quick Sort
        quickSort(nums, 0, nums.size() - 1);
        
        // Concatenated sorted numbers to form the largest number
        string ans = "";
        for (int num : nums)
            ans += to_string(num);
        
        // Handle the case where the largest number is zero
        return ans[0] == '0'? "0" : ans;
    }
};
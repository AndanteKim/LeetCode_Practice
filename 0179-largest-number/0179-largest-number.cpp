class Solution {
private:
    const int RUN = 32;
    static bool compare(int firstNumber, int secondNumber){
        return to_string(firstNumber) + to_string(secondNumber) > to_string(secondNumber) + to_string(firstNumber);
    }
    
    void insertionSort(vector<int>& nums, int left, int right){
        for (int i = left + 1; i <= right; ++i){
            int temp = nums[i], j = i - 1;
            while (j >= left && compare(temp, nums[j])){
                nums[j + 1] = nums[j];
                --j;
            }
            
            nums[j + 1] = temp;
        }
    }
    
    void mergeSort(vector<int>& nums, int left, int mid, int right){
        vector<int> leftArr(nums.begin() + left, nums.begin() + mid + 1), rightArr(nums.begin() + mid + 1, nums.begin() + right + 1);
        
        int i = 0, j = 0, k = left;
        while (i < leftArr.size() && j < rightArr.size()){
            if (compare(leftArr[i], rightArr[j]))
                nums[k++] = leftArr[i++];
            else
                nums[k++] = rightArr[j++];
        }
        
        for (;i < leftArr.size(); ++i){
            nums[k++] = leftArr[i];
        }
        
        for (;j < rightArr.size(); ++j){
            nums[k++] = rightArr[j];
        }
    }
    
    void timSort(vector<int>& nums){
        int n = nums.size();
        // Sort small runs with insertion sort
        for (int i = 0; i < n; i += RUN)
            insertionSort(nums, i, min(i + RUN - 1, n - 1));
        
        // Merge sorted runs
        for (int size = RUN; size < n; size *= 2){
            for (int left = 0; left < n; left += 2 * size){
                int mid = left + size - 1;
                int right = min(left + 2 * size - 1, n - 1);
                if (mid < right)
                    mergeSort(nums, left, mid, right);
            }
        }
    }
    
public:
    string largestNumber(vector<int>& nums) {
        // Sort the numbers using Tim Sort
        timSort(nums);
        
        // Concatenate sorted numbers to form the largest number
        string ans = "";
        
        for (int num : nums){
            ans += to_string(num);
        }
        
        // Handle the case where the largest number is zero
        return ans[0] == '0'? "0" : ans;
    }
};
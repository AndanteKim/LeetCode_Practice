class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(), nums.end()), right = accumulate(nums.begin(), nums.end(), 0), ans = 0;
        
        while (left <= right){
            int currSum = 0, maxSplit = 0;
            int mid = left + (right - left) / 2;
            for (int num : nums){
                if (currSum + num <= mid){
                    currSum += num;
                }
                else{
                    currSum = num;
                    ++maxSplit;
                }
            }
            
            if (maxSplit + 1 <= k){
                right = mid - 1;
                ans = mid;
            }
            else{
                left = mid + 1;
            }
        }
        
        return ans;
    }
};
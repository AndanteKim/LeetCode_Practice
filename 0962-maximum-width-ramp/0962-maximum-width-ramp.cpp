class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int> rightMax(n);
        
        // Fill the rightMax array with maximum value from the right
        rightMax.back() = nums.back();
        for (int i = n - 2; i >= 0; --i)
            rightMax[i] = max(rightMax[i + 1], nums[i]);
        
        int left = 0, right = 0, maxWidth = 0;
        
        // Traverse the array using left and right pointers
        while (right < n){
            // Move the left pointer forward if current left exceeds rightMax
            while (left < right && nums[left] > rightMax[right]){
                ++left;
            }
            
            maxWidth = max(maxWidth, right - left);
            ++right;
        }
        
        return maxWidth;
    }
};
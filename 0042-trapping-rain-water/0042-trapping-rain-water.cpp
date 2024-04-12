class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size(), leftMax = 0, rightMax = 0;
        int ans = 0, left = 0, right = size - 1;
        
        // sum up ans as vertical with two pointers
        while (left < right){
            if (height[left] < height[right]){
                (height[left] >= leftMax)? leftMax = height[left] : ans += leftMax - height[left];
                ++left;
            }
            else{
                (height[right] >= rightMax)? rightMax = height[right] : ans += rightMax - height[right];
                --right;
            }
        }
        
        return ans;
    }
};
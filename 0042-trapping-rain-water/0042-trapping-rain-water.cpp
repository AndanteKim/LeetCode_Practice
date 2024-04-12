class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size(), ans = 0;
        vector<int> leftMax(size), rightMax(size);
        
        leftMax[0] = height[0];
        // Search the left part for max bar size
        for (int i = 1; i < size; ++i)
            leftMax[i] = max(leftMax[i - 1], height[i]);
            
        rightMax.back() = height.back();
        // Search the right part for max bar size
        for (int i = size - 2; i >= 0; --i)
            rightMax[i] = max(rightMax[i + 1], height[i]);
        
        // find the overlap of both sides
        for (int i = 1; i < size - 1; ++i)
            ans += min(leftMax[i], rightMax[i]) - height[i];
        
        return ans;
    }
};
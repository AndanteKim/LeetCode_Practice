class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty())
            return 0;
        
        int ans = 0, n = height.size();
        vector<int> leftMax(n), rightMax(n);
        leftMax[0] = height[0];
        rightMax.back() = height.back();
        
        // Find the left max height for each index of elevation map
        for (int i = 1; i < n; ++i)
            leftMax[i] = max(leftMax[i - 1], height[i]);
        
        // Find the right max height for each index of elevation map
        for (int i = n - 2; i >= 0; --i)
            rightMax[i] = max(rightMax[i + 1], height[i]);
        
        // Find the intersection of area between leftMax[i] and rightMax[i]
        for (int i = 1; i < n - 1; ++i)
            ans += min(leftMax[i], rightMax[i]) - height[i];
        
        return ans;
    }
};
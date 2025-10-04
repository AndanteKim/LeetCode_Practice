class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0, left = 0, right = height.size() - 1, minHeight;

        while (left < right){
            minHeight = min(height[left], height[right]);
            ans = max(ans, minHeight * (right - left));

            if (height[left] < height[right]) ++left;
            else --right; 
        }

        return ans;
    }
};
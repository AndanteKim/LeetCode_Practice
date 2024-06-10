class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> sortedHeights = heights;
        sort(sortedHeights.begin(), sortedHeights.end());
        
        int ans = 0;
        for (int i = 0; i < heights.size(); ++i)
            if (sortedHeights[i] != heights[i])
                ++ans;
        
        return ans;
    }
};
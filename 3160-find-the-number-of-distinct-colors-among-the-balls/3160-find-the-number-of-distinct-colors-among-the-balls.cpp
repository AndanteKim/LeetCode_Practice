class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        unordered_map<int, int> colorMap, ballMap;
        vector<int> ans(n);

        // Iterate through queries
        for (int i = 0; i < n; ++i){
            // Extract ball label and color from query
            int ball = queries[i][0], color = queries[i][1];
            
            // Check if ball is already covered
            if (ballMap.count(ball)){
                // Decrement count of the previous color on the ball
                int prevColor = ballMap[ball];
                --colorMap[prevColor];

                // If there are no balls with previous color left, remove color
                // from color map
                if (colorMap[prevColor] == 0)
                    colorMap.erase(prevColor);
            }

            // Increment the count of the new color
            ++colorMap[color];

            // Set color of ball to the new color
            ballMap[ball] = color;
            ans[i] = colorMap.size();
        }

        return ans;
    }
};
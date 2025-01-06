class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size(), j;
        int ballsToLeft = 0, movesToLeft = 0;
        int ballsToRight = 0, movesToRight = 0;
        vector<int> ans(n);

        // Single pass: Calculate both left and right
        for (int i = 0; i < n; ++i){
            // Left pass
            ans[i] += movesToLeft;
            ballsToLeft += boxes[i] - 48;
            movesToLeft += ballsToLeft;

            // Right pass
            j = n - 1 - i;
            ans[j] += movesToRight;
            ballsToRight += boxes[j] - 48;
            movesToRight += ballsToRight;
        }

        return ans;
    }
};
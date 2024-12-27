class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size(), maxScore = 0;

        // Initialize a vector to store the maximum left scores up to each index.
        vector<int> maxLeftScores(n, 0);

        // The left score at the first index is just the value of the first element.
        maxLeftScores[0] = values[0];

        for (int i = 1; i < n; ++i){
            int currentRightScore = values[i] - i, currentLeftScore = values[i] + i;

            // Update the maximum score by combining the best left score so far
            // with the current right score.
            maxScore = max(maxScore, maxLeftScores[i - 1] + currentRightScore);

            // Update the maximum left score up to the current index.
            maxLeftScores[i] = max(maxLeftScores[i - 1], currentLeftScore);
        }
        
        return maxScore;
    }
};
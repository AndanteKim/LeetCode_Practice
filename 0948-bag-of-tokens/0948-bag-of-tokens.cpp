class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int low = 0, high = tokens.size() - 1, score = 0;
        sort(tokens.begin(), tokens.end());
        
        while (low <= high){
            // When we've enough power, play the lowest token face-up
            if (power >= tokens[low]){
                ++score;
                power -= tokens[low++];
            }
            // We don't have enough power to play a token face-up
            // if there is at least one token remaining,
            // and we've enough score, play the highest token face-down
            else if (low < high && score > 0){
                --score;
                power += tokens[high--];
            }
            
            // We don't have enough score, power, or tokens
            // to play face-up or down and increase our score
            else
                return score;
        }
        
        return score;
    }
};
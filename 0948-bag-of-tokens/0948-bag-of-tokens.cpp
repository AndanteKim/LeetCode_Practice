class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score = 0;
        sort(tokens.begin(), tokens.end());
        deque<int> dq(tokens.begin(), tokens.end());
        
        while (!dq.empty()){
            // When we're enough power, play token face-up.
            if (power >= dq.front()){
                power -= dq.front();
                dq.pop_front();
                ++score;
            }
            
            // We don't have enough power to play a token face-up
            // When there at least one token remaining, and we've enough score
            // play token face-down
            else if (dq.size() > 1 && score > 0){
                --score;
                power += dq.back();
                dq.pop_back();
            }
            
            // We don't have enough score, power, or tokens
            // to play face-up or down and increase our score
            else
                return score;
        }
        
        return score;
    }
};
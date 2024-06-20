class Solution {
private:
    // Check if we can place 'm' balls at 'position'
    // with each ball having at least 'x' gap.
    bool canPlaceBalls(int x, vector<int>& position, int m){
        // Place the first ball at the first position.
        int ballPlaced = 1, prevPos = position[0];
        
        // Iterate on each 'position' and place a ball there if we place it.
        for (int i = 1; i < position.size(); ++i){
            int currPos = position[i];
            // Check if we can place the ball at the current position.
            if (currPos - prevPos >= x){
                ++ballPlaced;
                prevPos = currPos;
            }
            
            // If all 'm' balls are placed, return 'true'
            if (ballPlaced == m)
                return true;
        }
        
        return false;
    }
    
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int ans = 0, low = 1, high = position.back() / (m - 1) + 1;
        
        while (low <= high){
            int mid = low + ((high - low) >> 1);
            // If we can place all balls having a gap at least 'mid',
            if (canPlaceBalls(mid, position, m)){
                // then 'mid' can be our answer
                // and discard the left half search space.
                low = mid + 1;
                ans = mid;
            }
            else
                // Discard the right half search space.
                high = mid - 1;
        }
        
        return ans;
    }
};
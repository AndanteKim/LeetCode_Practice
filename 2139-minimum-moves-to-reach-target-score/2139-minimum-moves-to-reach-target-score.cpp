class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int ans = 0;
        
        while (target > 1 && maxDoubles > 0){
            ans += 1 + target % 2;
            --maxDoubles;
            target >>= 1;
        }
        
        return target - 1 + ans;
    }
};
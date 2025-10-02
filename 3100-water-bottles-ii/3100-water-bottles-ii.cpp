class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = 0, full = numBottles, empty = 0;

        while (full > 0){
            ans += full;
            empty += full;
            full = 0;

            while (empty >= numExchange){
                full += 1;
                empty -= (numExchange++);
            }
        }

        return ans;
    }
};
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0, remain = numBottles, empty = 0;

        while (remain > 0){
            ans += remain;
            empty += remain;
            remain = empty / numExchange;
            empty -= (remain * numExchange);
        }

        return ans;
    }
};
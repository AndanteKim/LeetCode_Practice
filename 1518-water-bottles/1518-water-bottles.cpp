class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        // Mathematical formula
        return numBottles + ((numBottles - 1) / (numExchange - 1));
    }
};
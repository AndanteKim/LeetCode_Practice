class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int maxWeight = *max_element(stones.begin(), stones.end());
        
        vector<int> buckets(maxWeight + 1, 0);
        
        for (int weight : stones)
            ++buckets[weight];
        
        int biggestWeight = 0, currentWeight = maxWeight;
        
        while (currentWeight > 0){
            if (buckets[currentWeight] == 0) --currentWeight;
            else if (biggestWeight == 0) {
                buckets[currentWeight] %= 2;
                if (buckets[currentWeight] == 1) biggestWeight = currentWeight;
                --currentWeight;
            }
            else{
                --buckets[currentWeight];
                if (biggestWeight - currentWeight <= currentWeight){
                    ++buckets[biggestWeight - currentWeight];
                    biggestWeight = 0;
                }
                else biggestWeight -= currentWeight;
            }
        }
        
        return biggestWeight;
    }
};
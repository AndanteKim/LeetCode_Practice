class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long, vector<long>, greater<long>> minHeap;
        minHeap.push(1);
        unordered_set<long> seen;
        seen.insert(1);
        vector<int> primeFactors{2, 3, 5};
        long minNum;
        
        for (int i = 0; i < n; ++i){
            minNum = minHeap.top();
            minHeap.pop();
            
            for (int prime : primeFactors){
                long next = prime * minNum;
                if (!seen.count(next)){
                    minHeap.push(next);
                    seen.insert(next);
                }
            }
        }
        
        return static_cast<int>(minNum);
    }
};
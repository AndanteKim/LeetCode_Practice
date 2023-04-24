class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        int x, y;
        while (!pq.empty()){
            if (pq.size() == 1) return pq.top();
            y = pq.top();
            pq.pop();
            x = pq.top();
            pq.pop();
            if (y > x) pq.push(y - x);
        }
        return 0;
    }
};
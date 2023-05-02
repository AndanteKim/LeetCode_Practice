class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int stick : sticks) pq.push(stick);
        int ans = 0;
        while (pq.size() > 1){
            int curr = 0;
            curr += pq.top();
            pq.pop();
            curr += pq.top();
            pq.pop();
            ans += curr;
            pq.push(curr);
        }
        
        return ans;
    }
};
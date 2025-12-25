class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans = 0;
        int notHappy = 0;
        priority_queue<int, vector<int>> pq;
        for (const int h : happiness) pq.push(h);

        for (int i = 0; i < k; ++i) {
            long long h = pq.top(); pq.pop();
            ans += max(0LL, h - (notHappy++));
        }
        
        return ans;
    }
};
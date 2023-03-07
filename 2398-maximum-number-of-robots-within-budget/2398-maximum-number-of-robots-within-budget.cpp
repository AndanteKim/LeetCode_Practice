class Solution {
    int remove_stale(priority_queue<pair<int, int>>& pq, int& left){
        while (!pq.empty() && pq.top().second <= left) pq.pop();
        return !pq.empty()? pq.top().first : 0; 
    }
    
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int ans = 0, left = -1;
        long long total_run = 0;
        priority_queue<pair<int, int>> pq;
        
        for (int right = 0; right < runningCosts.size(); ++right){
            total_run += runningCosts[right];
            pq.push(make_pair(chargeTimes[right], right));
            while (total_run * (right - left) + 1LL * remove_stale(pq, left) > budget)
                total_run -= runningCosts[++left];
            cout << right - left << endl;
            ans = max(ans, right - left);
        }
        
        return ans;
    }
};
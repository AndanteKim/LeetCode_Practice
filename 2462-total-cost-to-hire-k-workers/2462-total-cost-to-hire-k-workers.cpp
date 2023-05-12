#define ll long long

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<int>> headWorkers, tailWorkers;
        for (int i = 0; i < candidates; ++i) headWorkers.push(costs[i]);
        for (int i = max(candidates, (int)(costs.size() - candidates)); i < costs.size(); ++i)
            tailWorkers.push(costs[i]);
        ll ans = 0;
        int nextHead = candidates, nextTail = costs.size() - 1 - candidates;
        
        for (int i = 0; i < k; ++i){
            if (tailWorkers.empty() || !headWorkers.empty() && headWorkers.top() <= tailWorkers.top()){
                ans += headWorkers.top();
                headWorkers.pop();
                if (nextHead <= nextTail){
                    headWorkers.push(costs[nextHead]);
                    ++nextHead;
                }
            }
            else{
                ans += tailWorkers.top();
                tailWorkers.pop();
                if (nextHead <= nextTail){
                    tailWorkers.push(costs[nextTail]);
                    --nextTail;
                }
            }
        }
        
        return ans;
    }
};
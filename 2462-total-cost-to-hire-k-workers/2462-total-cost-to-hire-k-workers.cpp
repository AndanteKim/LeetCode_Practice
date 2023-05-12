#define ll long long

class Solution {
    struct compare{
        bool operator()(pair<int, int>& a, pair<int, int>& b){
            if (a.first == b.first)
                return a.second > b.second;
            return a.first > b.first;
        }
    };
    
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
        for (int i = 0; i < candidates; ++i) pq.push({costs[i], 0});
        for (int i = max(candidates, (int)costs.size() - candidates); i < costs.size(); ++i) pq.push({costs[i], 1});
        
        ll ans = 0;
        int nextHead = candidates, nextTail = (int)costs.size() - 1 - candidates;
        for (int i = 0; i < k; ++i){
            auto [curCost, curSectionID] = pq.top();
            pq.pop();
            ans += curCost;
            if (nextHead <= nextTail){
                if (curSectionID == 0){
                    pq.push({costs[nextHead], 0});
                    ++nextHead;
                }
                else{
                    pq.push({costs[nextTail], 1});
                    --nextTail;
                }
            }
        }
        
        return ans;
    }
};
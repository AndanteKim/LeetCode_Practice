typedef long long ll;

class Solution {
public:
    vector<long long> minimumCosts(vector<int>& regular, vector<int>& express, int expressCost) {
        int n = regular.size();
        vector<ll> ans;
        ll prevRegularLane = 0, prevExpressLane = expressCost;
        
        for (int i = 1; i <= n; ++i){
            ll costRegularLane = regular[i - 1] + min(prevRegularLane, prevExpressLane);
            ll costExpressLane = express[i - 1] + min(prevRegularLane + expressCost, prevExpressLane);
            ans.push_back(min(costRegularLane, costExpressLane));
            prevRegularLane = costRegularLane;
            prevExpressLane = costExpressLane;
        }
        
        return ans;
    }
};
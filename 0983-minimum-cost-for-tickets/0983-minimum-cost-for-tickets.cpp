class Solution {
    vector<int> costs, memo;
    set<int> dayset;
    int dp(int i){
        if (i > 365) return 0;
        if (memo[i] != NULL) return memo[i];
        int ans;
        if (dayset.find(i) != dayset.end()){
            ans = min(dp(i+1) + costs[0], dp(i+7) + costs[1]);
            ans = min(ans, dp(i+30) + costs[2]);
        }
        else ans = dp(i + 1);
        
        memo[i] = ans;
        return ans;
    }
    
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        this -> costs = costs;
        memo.resize(366);
        for (int d : days) dayset.insert(d);
        return dp(1);
    }
};
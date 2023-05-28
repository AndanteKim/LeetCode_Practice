class Solution {
private:
    int cost(int left, int right, vector<int>& cuts, vector<vector<int>>& memo){
        if (left > right)
            return 0;
        
        if (memo[left][right] != -1)
            return memo[left][right];
        
        int ans = INT_MAX;
        for (int mid = left; mid <= right; ++mid){
            int c = cuts[right + 1] - cuts[left - 1] + cost(left, mid - 1, cuts, memo) + cost(mid + 1, right, cuts, memo);
            ans = min(ans, c);
        }
            
        return memo[left][right] = ans;
    }
    
public:
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        
        vector<vector<int>> memo(c + 1, vector<int>(c + 1, -1));
        
        return cost(1, c, cuts, memo);
    }
};
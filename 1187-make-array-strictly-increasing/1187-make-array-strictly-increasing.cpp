typedef long l;

class Solution {
private:
    l dfs(int i, int prev, map<pair<int, int>, l>& dp, vector<int>& arr1, vector<int>& arr2){
        if (i == arr1.size()) return 0;
        if (dp.find({i, prev}) != dp.end()) return dp[{i, prev}];
        
        long cost = INT_MAX;
        if (arr1[i] > prev) cost = dfs(i + 1, arr1[i], dp, arr1, arr2);
        int idx = upper_bound(arr2.begin(), arr2.end(), prev) - arr2.begin();
        if (idx < arr2.size()) cost = min(cost, 1 + dfs(i + 1, arr2[idx], dp, arr1, arr2));
        
        return dp[{i, prev}] = cost;
    }
    
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        map<pair<int, int>, l> dp;
        int ans = dfs(0, -1, dp, arr1, arr2);
        return (ans < INT_MAX)? ans : -1;
    }
};
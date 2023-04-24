class Solution {
    int dfs(int i, vector<int>& manager, vector<int>& informTime){
        if (manager[i] != -1){
            informTime[i] += dfs(manager[i], manager, informTime);
            manager[i] = -1;
        }
        
        return informTime[i];
    }
    
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int ans = 0;
        for (int i = 0; i < n; ++i){
            ans = max(ans, dfs(i, manager, informTime));
        }
        return ans;
    }
};
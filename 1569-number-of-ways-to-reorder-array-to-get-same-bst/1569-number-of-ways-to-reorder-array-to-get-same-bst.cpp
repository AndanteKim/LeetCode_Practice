typedef long long ll;

class Solution {
private:
    vector<vector<ll>> table;
    ll mod = 1e9 + 7;
    
    ll dfs(vector<int> &nums){
        int m = nums.size();
        if (m < 3) return 1;
        
        vector<int> leftNodes, rightNodes;
        for (int i = 1; i < m; ++i){
            if (nums[i] < nums[0]) leftNodes.push_back(nums[i]);
            else rightNodes.push_back(nums[i]);
        }
        
        ll leftWays = dfs(leftNodes) % mod, rightWays = dfs(rightNodes) % mod;
        return (((leftWays * rightWays) % mod) * table[m - 1][leftNodes.size()]) % mod;
    }
    
public:
    int numOfWays(vector<int>& nums) {
        int m = nums.size();
        table.resize(m + 1);
        for (int i = 0; i < m + 1; ++i){
            table[i] = vector<ll>(i + 1, 1);
            for (int j = 1; j < i; ++j){
                table[i][j] = (table[i - 1][j - 1] + table[i - 1][j]) % mod;
            }
        }
        
        return (dfs(nums) - 1) % mod;
    }
};
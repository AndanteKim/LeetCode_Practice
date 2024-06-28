class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> degree(n);
        
        for (auto& road : roads){
            ++degree[road[0]];
            ++degree[road[1]];
        }
        
        sort(degree.begin(), degree.end());
        long long ans = 0, val = 1;
        for (int d : degree)
            ans += d * (val++);
        
        return ans;
    }
};
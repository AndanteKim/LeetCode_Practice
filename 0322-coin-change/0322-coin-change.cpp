class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // BFS
        queue<pair<int, int>> queue;
        queue.push({amount, 0});
        unordered_set<int> seen;
        
        while (!queue.empty()){
            auto [remain, currCoins] = queue.front();
            queue.pop();
            
            if (remain == 0)
                return currCoins;
            
            for (int coin : coins){
                if (remain - coin >= 0 && !seen.count(remain - coin)){
                    seen.insert(remain - coin);
                    queue.push({remain - coin, currCoins + 1});
                }
            }
        }
        
        return -1;
    }
};
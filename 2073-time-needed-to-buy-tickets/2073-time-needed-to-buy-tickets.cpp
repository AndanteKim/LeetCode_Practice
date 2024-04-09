class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int, bool>> q;
        for (int i = 0; i < tickets.size(); ++i){
            if (i == k) q.push({tickets[i], true});
            else q.push({tickets[i], false});
        }
        
        int time = 0;
        while (!q.empty()){
            auto [left, kthTurn] = q.front(); q.pop();
            
            --left;
            ++time;
            if (left > 0) q.push({left, kthTurn});
            else if (kthTurn) return time;
        }
            
        return -1;
    }
};
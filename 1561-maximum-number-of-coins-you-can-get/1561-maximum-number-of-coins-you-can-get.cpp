class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        deque<int> dq(piles.begin(), piles.end());
        int ans = 0;
        
        while (!dq.empty()){
            // Alice
            dq.pop_back();
            
            // I
            ans += dq.back();
            dq.pop_back();
            
            // Bob
            dq.pop_front();
        }
        
        return ans;
    }
};
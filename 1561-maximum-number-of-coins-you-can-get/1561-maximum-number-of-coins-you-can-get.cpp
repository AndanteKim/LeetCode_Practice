class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        deque<int> dq(piles.begin(), piles.end());
        vector<tuple<int, int, int>> triplets;
        int ans = 0;
        
        while (!dq.empty()){
            int Alice = dq.back();
            dq.pop_back();
            int I = dq.back();
            dq.pop_back();
            int Bob = dq.front();
            dq.pop_front();
            
            triplets.push_back({Alice, I, Bob});
        }
        
        for (tuple<int, int, int>& triplet : triplets){
            ans += get<1>(triplet);
        }
        
        return ans;
    }
};
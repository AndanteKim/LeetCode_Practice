class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for (int num : nums) pq.push(num);
        
        for (int i = 0; i < k; ++i){
            int num = pq.top(); pq.pop();
            pq.push(num + 1);
        }
        
        constexpr int MOD = 1'000'000'007;
        long long ans = 1;
        while (!pq.empty()){
            ans = (ans * pq.top()) % MOD;
            pq.pop();
        }
        
        return ans;
    }
};
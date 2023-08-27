class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        int ans = 1;
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for (int num : nums) pq.push(num);
        while (k > 0){
            int elem = pq.top();
            pq.pop();
            --k;
            ++elem;
            pq.push(elem);
        }
        
        while (!pq.empty()){
            ans = ((long long)ans * pq.top()) % (1'000'000'007);
            pq.pop();
        }
        return ans;
    }
};
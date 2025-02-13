typedef long long ll;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<ll, vector<ll>, greater<ll>> minHeap(nums.begin(), nums.end());

        int ans = 0;
        while (minHeap.top() < k){
            ll x = minHeap.top(); minHeap.pop();
            ll y = minHeap.top(); minHeap.pop();
            minHeap.push(min(x, y) * 2 + max(x, y));
            ++ans;
        }

        return ans;
    }
};
typedef long long ll;

class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        priority_queue<tuple<ll, ll, int>, vector<tuple<ll, ll, int>>, greater<>> minHeap;
        for (int w : workerTimes) minHeap.push({w, 2 * w, w});

        for (int i = 0; i < mountainHeight; ++i) {
            auto [time, nextTerm, base] = minHeap.top();
            minHeap.pop();
            minHeap.push({time + nextTerm, nextTerm + base, base});
        }

        ll ans = 0;
        while (!minHeap.empty()) {
            auto [time, nextTerm, base] = minHeap.top();
            minHeap.pop();
            ans = max(ans, time - nextTerm + base);
        }

        return ans;
    }
};
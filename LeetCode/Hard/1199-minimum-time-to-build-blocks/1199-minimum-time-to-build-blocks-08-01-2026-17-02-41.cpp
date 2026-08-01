class Solution {
public:
    int minBuildTime(vector<int>& blocks, int split) {
        priority_queue<int, vector<int>, greater<>> minHeap(blocks.begin(), blocks.end());

        while (minHeap.size() > 1) {
            int x = minHeap.top(); minHeap.pop();
            int y = minHeap.top(); minHeap.pop();

            minHeap.push(split + y);
        }

        return minHeap.top();
    }
};
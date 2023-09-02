class Solution {
public:
    int minBuildTime(vector<int>& blocks, int split) {
        // heapify heap of building time
        priority_queue<int, vector<int>, greater<int>> pq(blocks.begin(), blocks.end());
        
        // make sibling blocks until we are left with
        // only one root node
        while (pq.size() > 1){
            // pop two minimum the time of the abstracted sub-root
            // will be split + max(x, y) which split + y
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            pq.push(split + y);
        }
        // Time of final root node
        return pq.top();
    }
};
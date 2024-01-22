class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        if (sticks.size() <= 1)
            return 0;
        
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int n:sticks)
            minHeap.push(n);
        
        int ans = 0, connect;
        while (minHeap.size() > 1){
            connect = minHeap.top();
            minHeap.pop();
            connect += minHeap.top();
            minHeap.pop();
            ans += connect;
            minHeap.push(connect);
        }
        
        return ans;
    }
};
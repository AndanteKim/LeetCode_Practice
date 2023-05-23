class Solution {
public:
    int maxNumberOfApples(vector<int>& weight) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int w : weight) minHeap.push(w);
        
        int ans = 0, units = 0;
        
        while (minHeap.size() > 0 && units + minHeap.top() <= 5000){
            ++ans;
            units += minHeap.top();
            minHeap.pop();
        }
        
        return ans;
    }
};
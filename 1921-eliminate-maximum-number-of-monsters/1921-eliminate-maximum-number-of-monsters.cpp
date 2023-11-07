class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        priority_queue<float, vector<float>, greater<float>> minHeap;
        for (int i = 0; i < dist.size(); ++i)
            minHeap.push((float)dist[i] / speed[i]);
        
        int ans = 0;
        while (!minHeap.empty()){
            if (minHeap.top() <= ans)
                break;
            minHeap.pop();
            ++ans;
        }
        
        return ans;
    }
};
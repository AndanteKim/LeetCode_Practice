class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        priority_queue<pair<int, int>, vector<pair<int, int>>> maxHeap;
        
        for (int i = 0; i < arrays.size(); ++i){
            minHeap.push({arrays[i][0], i});
            maxHeap.push({arrays[i].back(), i});
        }
        
        int min = INT_MAX, max = INT_MIN, idx1 = -1, idx2 = -1;
        while (!minHeap.empty() && !maxHeap.empty()){
            if (min == INT_MAX && idx1 == -1){
                min = minHeap.top().first;
                idx1 = minHeap.top().second;
                minHeap.pop();
            }
                
            if (max == INT_MIN && idx2 == -1){
                max = maxHeap.top().first;
                idx2 = maxHeap.top().second;
                maxHeap.pop();
            }
            
            if (idx1 == idx2){
                if (abs(min - minHeap.top().first) < abs(max - maxHeap.top().first)){
                    min = INT_MAX;
                    idx1 = -1;
                }
                else{
                    max = INT_MIN;
                    idx2 = -1;
                }
            }
            else
                return max - min;
        }
        
        return -1;
    }
};
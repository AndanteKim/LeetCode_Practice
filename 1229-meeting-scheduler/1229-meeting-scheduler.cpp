class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        // Build up a min heap containing time slots lasting longer than duration
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        
        for (const auto& slot1 : slots1){
            if (slot1[1] - slot1[0] >= duration)
                minHeap.push({slot1[0], slot1[1]});
        }
        
        for (const auto& slot2 : slots2){
            if (slot2[1] - slot2[0] >= duration)
                minHeap.push({slot2[0], slot2[1]});
        }
        
        while (minHeap.size() > 1){
            auto [s1, e1] = minHeap.top(); minHeap.pop();
            auto [s2, e2] = minHeap.top();
            
            if (e1 >= s2 + duration)
                return vector<int>{s2, s2 + duration};
        }
        
        return vector<int>{};
    }
};
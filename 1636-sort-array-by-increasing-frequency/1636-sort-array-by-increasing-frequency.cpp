class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int, int> counter;
        for (int num : nums)
            ++counter[num];
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        vector<int> ans;
        
        for (auto& [n, freq] : counter)
            minHeap.push({freq, -n});
        
        while (!minHeap.empty()){
            for (int i = 0; i < minHeap.top().first; ++i)
                ans.push_back(-minHeap.top().second);
            minHeap.pop();
        }
        
        return ans;
    }
};
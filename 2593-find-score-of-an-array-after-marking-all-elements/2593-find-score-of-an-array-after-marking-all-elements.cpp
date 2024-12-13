class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long score = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
            minHeap.push({nums[i], i});
        
        unordered_set<int> marked;
        while(!minHeap.empty()){
            auto [num, index] = minHeap.top(); minHeap.pop();
            
            if (marked.count(index))
                continue;
            
            score += num;
            marked.insert(index);
            if (index == 0)
                marked.insert(index + 1);
            else if (index == n - 1)
                marked.insert(index - 1);
            else{
                marked.insert(index + 1);
                marked.insert(index - 1);
            }
        }
        
        return score;
    }
};
class Solution {
    struct compare{
        bool operator()(pair<int, pair<int, int>>& a, pair<int, pair<int, int>>& b){
            if (a.first == b.first){
                if (a.second.first == b.second.first) return a.second.second > b.second.second;
                return a.second.first > b.second.first;
            }
            return a.first > b.first;
        }
    };
    
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, compare> pq;
        int maxVal = 0;
        for (int i = 0; i < nums.size(); ++i){
            pq.push({nums[i][0], {i, 0}});
            maxVal = max(maxVal, nums[i][0]);
        }
        vector<int> ans{pq.top().first, maxVal};
        
        while(true){
            auto [_, mat] = pq.top();
            auto [row, col] = mat;
            pq.pop();
            
            if (col == nums[row].size() - 1) break;
            int nextNum = nums[row][col + 1];
            pq.push({nextNum, {row, col + 1}});
            maxVal = max(maxVal, nextNum);
            if (maxVal - pq.top().first < ans[1] - ans[0])
                ans = {pq.top().first, maxVal};
        }
        
        return ans;
    }
};
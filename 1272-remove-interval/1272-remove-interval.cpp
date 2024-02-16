class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        vector<vector<int>> ans;
        
        for (vector<int>& interval:intervals){
            int start = interval[0], end = interval[1];
            
            if (toBeRemoved[0] <= start && end <= toBeRemoved[1])
                continue;
            else if (start > toBeRemoved[1] || end < toBeRemoved[0])
                ans.push_back({start, end});
            else if (start < toBeRemoved[0] && end > toBeRemoved[0]){
                ans.push_back({start, toBeRemoved[0]});
                if (end > toBeRemoved[1]) ans.push_back({toBeRemoved[1], end});
            }
            else{
                if (start < toBeRemoved[0])
                    ans.push_back({start, toBeRemoved[0]});
                ans.push_back({toBeRemoved[1], end});
            }
            
        }
        
        return ans;
    }
};
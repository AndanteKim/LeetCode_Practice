class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        int removeStart = toBeRemoved[0], removeEnd = toBeRemoved[1];
        vector<vector<int>> ans;
        
        for (vector<int>& interval:intervals){
            int start = interval[0], end = interval[1];
            // If there are no overlaps, add the interval to the list intervals
            if (start > removeEnd || end < removeStart)
                ans.push_back({start, end});
            else{
                // Is there a left interval we need to keep?
                if (start < removeStart)
                    ans.push_back({start, removeStart});
                
                // Is there a right interval we need to keep?
                if (end > removeEnd)
                    ans.push_back({removeEnd, end});
            }
        }
        
        return ans;
    }
};
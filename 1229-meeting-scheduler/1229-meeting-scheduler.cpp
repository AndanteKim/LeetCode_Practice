class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());
        
        int i = 0, j = 0, m = slots1.size(), n = slots2.size();
        
        while (i < m && j < n){
            int intersectRight = min(slots1[i][1], slots2[j][1]);
            int intersectLeft = max(slots1[i][0], slots2[j][0]);
            
            // Find the boundaries of the intersection, or the common slot
            if (intersectRight - intersectLeft >= duration)
                return vector<int>{intersectLeft, intersectLeft + duration};
            
            // Always move the one ending earlier
            if (slots1[i][1] < slots2[j][1])
                ++i;
            else
                ++j;
        }
        
        return vector<int>{};
    }
};
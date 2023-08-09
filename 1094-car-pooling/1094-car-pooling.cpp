class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), [](vector<int>& a, vector<int>& b){return a[2] < b[2];});
        
        vector<int> status(trips.back()[2] + 1);
        
        for (vector<int>& trip : trips){
            int n = trip[0], start = trip[1], end = trip[2];
            
            for (int day = start; day < end; ++day){
                if (status[day] + n > capacity) return false;
                status[day] += n;
            }
        }
        
        return true;
    }
};
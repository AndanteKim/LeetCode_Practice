class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return (a[0] == b[0])? a[1] > b[1] : a[0] < b[0];});

        int ans = 0;
        vector<int> todo(intervals.size(), 2);

        while (!intervals.empty()) {
            auto x = intervals.back(); intervals.pop_back();
            int t = todo.back(); todo.pop_back();
            int s = x[0], e = x[1];

            for (int p = s; p < s + t; ++p) {
                for (int i = 0; i < intervals.size(); ++i) {
                    int s0 = intervals[i][0], e0 = intervals[i][1];
                    if (todo[i] > 0 && p <= e0)
                        --todo[i];
                }
                ++ans;
            }
            
        }

        return ans;
    }
};
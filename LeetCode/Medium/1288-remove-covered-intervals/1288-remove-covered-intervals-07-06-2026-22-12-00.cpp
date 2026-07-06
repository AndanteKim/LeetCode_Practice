class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] != b[0]? a[0] < b[0] : b[1] < a[1];
        });

        int ans = 0, prevEnd = 0;
        for (vector<int>& interval : intervals) {
            int end = interval[1];
            cout << end << endl;

            if (end > prevEnd) {
                ++ans;
                prevEnd = end;
            }
        }

        return ans;
    }
};
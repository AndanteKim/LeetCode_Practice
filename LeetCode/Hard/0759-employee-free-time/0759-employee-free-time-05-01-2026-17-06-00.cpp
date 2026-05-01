/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<vector<int>> times;

        for (const auto& s : schedule) {
            for (const auto& it : s) {
                times.push_back({it.start, it.end});
            }
        }

        sort(times.begin(), times.end());

        vector<Interval> ans;
        int prevE = -1;
        for (const auto& time : times) {
            int s = time[0], e = time[1];
            if (prevE != -1 && prevE < s) ans.push_back(Interval(prevE, s));
            prevE = max(prevE, e);
        }
        
        return ans;
    }
};
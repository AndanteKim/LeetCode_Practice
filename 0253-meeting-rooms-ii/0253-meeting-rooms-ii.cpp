class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){return a[0] < b[0];});
        priority_queue<int, vector<int>, greater<int>> heap;
        heap.push(intervals[0][1]);
        
        for (int i = 1; i < intervals.size(); ++i){
            if (heap.top() <= intervals[i][0]) heap.pop();
            heap.push(intervals[i][1]);
        }
        
        return heap.size();
    }
};
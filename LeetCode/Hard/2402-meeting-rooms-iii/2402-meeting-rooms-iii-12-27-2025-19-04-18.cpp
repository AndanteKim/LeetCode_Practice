class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> usedRooms;
        priority_queue<int, vector<int>, greater<>> unusedRooms;
        for (int i = 0; i < n; ++i) unusedRooms.push(i);
        vector<int> meetingCount(n);
        sort(meetings.begin(), meetings.end());

        for (const auto& meeting : meetings) {
            int start = meeting[0], end = meeting[1];

            while (!usedRooms.empty() && usedRooms.top().first <= start) {
                auto [_, room] = usedRooms.top(); usedRooms.pop();
                unusedRooms.push(room);
            }

            if (!unusedRooms.empty()) {
                const int room = unusedRooms.top(); unusedRooms.pop();
                usedRooms.push({end, room});
                ++meetingCount[room];
            }
            else {
                const auto [e, room] = usedRooms.top(); usedRooms.pop();
                usedRooms.push({e + end - start, room});
                ++meetingCount[room];
            }

        }

        int ans = std::numeric_limits<int>::max(), maxCount = 0;
        for (int i = 0; i < n; ++i) {
            if (maxCount < meetingCount[i]) {
                ans = i;
                maxCount = meetingCount[i];
            }
        }

        return ans;
    }
};
class Solution {
private:
    int n;
    int dp(int i, int cnt, vector<vector<int>>& events, vector<vector<int>>& memo) {
        // Base case
        if (cnt == 2 || i == n) return 0;

        if (memo[i][cnt] == -1) {
            int mid, lo = i + 1, hi = n - 1;
            int end = events[i][1], val = events[i][2];
            while (lo < hi) {
                mid = lo + ((hi - lo) >> 1);

                if (events[mid][0] > end)
                    hi = mid;
                else
                    lo = mid + 1;
            }

            int include = val + ((lo < n && events[lo][0] > end)? dp(lo, cnt + 1, events, memo) : 0);
            int exclude = dp(i + 1, cnt, events, memo);
            memo[i][cnt] = max(include, exclude);
        }

        return memo[i][cnt];
    }

public:
    int maxTwoEvents(vector<vector<int>>& events) {
        this -> n = events.size();
        vector memo(n, vector<int>(3, -1));
        sort(events.begin(), events.end());
        return dp(0, 0, events, memo);
    }
};
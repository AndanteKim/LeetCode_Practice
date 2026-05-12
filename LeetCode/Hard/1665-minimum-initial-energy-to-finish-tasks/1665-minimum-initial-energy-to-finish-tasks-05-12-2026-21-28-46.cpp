class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](vector<int>& a, vector<int>& b) {return (a[1] - a[0]) > (b[1] - b[0]);});

        int ans = 0, remain = 0;
        for (const auto& task : tasks) {
            if (task[1] > remain) ans += task[1] - remain;

            remain = max(remain - task[0], task[1] - task[0]);
        }

        return ans;
    }
};
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> idle, busy;
        vector<int> ans(tasks.size());
        for (int i = 0; i < servers.size(); ++i) {
            idle.push({servers[i], i});
        }

        long long ts = 0;
        auto release = [&]() -> void {
            while (!busy.empty() && busy.top().first <= ts) {
                auto [_, idx] = busy.top();
                busy.pop();
                idle.push({servers[idx], idx});
            }

            return;
        };

        for (int i = 0; i < tasks.size(); ++i) {
            ts = max(ts, static_cast<long long>(i));
            release();

            if (idle.empty()) {
                ts = busy.top().first;
                release();
            }

            auto [_, idx] = idle.top(); idle.pop();
            ans[i] = idx;
            busy.push({ts + tasks[i], idx});
        }
        
        return ans;
    }
};
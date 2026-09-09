class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        map<int, priority_queue<int, vector<int>>> records;

        for (const auto& item : items) {
            records[item[0]].push(item[1]);
        }

        vector<vector<int>> ans;
        for (auto& [id, scores] : records) {
            int avg = 0, sz = scores.size();
            for (int i = 0; i < min(sz, 5); ++i) {
                avg += scores.top();
                scores.pop();
            }
            avg /= 5;
            ans.push_back({id, avg});
        }

        return ans;
    }
};
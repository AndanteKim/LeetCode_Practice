class Solution {
private:
    int search(int height, vector<pair<int, int>>& monoStack){
        int ans = -1, left = 0, right = monoStack.size() - 1;
        while (left <= right){
            int mid = left + ((right - left) >> 1);

            if (monoStack[mid].first > height){
                ans = max(ans, mid);
                left = mid + 1;
            }
            else
                right = mid - 1;
        }
        return ans;
    }

public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int m = heights.size(), n = queries.size();
        vector<vector<pair<int, int>>> newQueries(m);
        vector<int> ans(n, -1);

        for (int i = 0; i < n; ++i){
            int a = queries[i][0], b = queries[i][1];
            if (a > b) swap(a, b);
            if (a == b || heights[a] < heights[b])
                ans[i] = b;
            else
                newQueries[b].push_back({heights[a], i});
        }

        vector<pair<int, int>> monoStack;
        for (int i = m - 1; i >= 0; --i){
            int monoStackSize = monoStack.size();
            for (auto& [a, b] : newQueries[i]){
                int pos = search(a, monoStack);
                if (pos >= 0 && pos < monoStack.size())
                    ans[b] = monoStack[pos].second;
            }
            while (!monoStack.empty() && monoStack.back().first <= heights[i])
                monoStack.pop_back();

            monoStack.push_back({heights[i], i});
        }
        return ans;
    }
};
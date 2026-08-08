class Solution {
private:
    vector<string> fetchPaths(unordered_map<string, string>& ancestors, string& r) {
        vector<string> paths{r};

        while (ancestors.contains(r)) {
            string parent = ancestors[r];
            paths.push_back(parent);
            r = parent;
        }

        reverse(paths.begin(), paths.end());

        return paths;
    }

public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        unordered_map<string, string> ancestors;

        for (const auto& region : regions) {
            string parent = region[0];
            for (int i = 1; i < region.size(); ++i)
                ancestors[region[i]] = parent;
        }

        vector<string> path1 = fetchPaths(ancestors, region1), path2 = fetchPaths(ancestors, region2);
        int i = 0, j = 0;
        string ans = "";
        while (i < path1.size() && j < path2.size() && path1[i] == path2[j]) {
            cout << path1[i] << endl;
            ans = path1[i];
            ++i; ++j;
        }

        return ans;
    }
};
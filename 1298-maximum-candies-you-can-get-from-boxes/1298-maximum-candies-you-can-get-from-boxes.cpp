class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size(), ans = 0;
        vector<bool> hasBox(n, false), canOpen(n, false), used(n, false);
        for (int i = 0; i < n; ++i){
            canOpen[i] = (status[i] == 1);
        }

        queue<int> q;
        for (int box : initialBoxes){
            hasBox[box] = true;
            if (canOpen[box]){
                used[box] = true;
                ans += candies[box];
                q.push(box);
            }
        }

        while (!q.empty()){
            int bigBox = q.front(); q.pop();

            for (int key : keys[bigBox]){
                canOpen[key] = true;
                if (!used[key] && hasBox[key]){
                    used[key] = true;
                    ans += candies[key];
                    q.push(key);
                }
            }

            for (int box : containedBoxes[bigBox]){
                hasBox[box] = true;
                if (!used[box] && canOpen[box]){
                    used[box] = true;
                    ans += candies[box];
                    q.push(box);
                }
            }
        }

        return ans;
    }
};
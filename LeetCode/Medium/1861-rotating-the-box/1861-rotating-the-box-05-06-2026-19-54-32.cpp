class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size(), n = boxGrid[0].size();
        vector<vector<char>> ans(n, vector<char>(m, '.'));

        for (int i = 0; i < m; ++i) {
            stack<char> st;
            for (int j = 0; j < n; ++j) {
                if (boxGrid[i][j] == '#') st.push('#');
                else if (boxGrid[i][j] == '*') {
                    ans[j][i] = '*';
                    int k = j - 1;
                    while (!st.empty()) {
                        ans[k--][i] = st.top();
                        st.pop();
                    }
                }
            }

            int j = n - 1;

            while (!st.empty()) {
                ans[j--][i] = st.top();
                st.pop();
            }
        }

        for (int i = 0; i < n; ++i) reverse(ans[i].begin(), ans[i].end());

        return ans;
    }
};
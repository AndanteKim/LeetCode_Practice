class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans(seq.size());
        int cnt = 0;

        for (int i = 0; i < seq.size(); ++i) {
            if (seq[i] == '(') {
                ++cnt;
                ans[i] = cnt % 2;
            }
            else if (seq[i] == ')') {
                ans[i] = cnt % 2;
                --cnt;
            }
        }

        return ans;
    }
};
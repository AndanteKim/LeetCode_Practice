class Solution {
public:
    struct Item {
        int val, left, right;
    };
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<Item> st;

        for (int i = 0; i < n; ++i) {
            Item curr = {nums[i], i, i};

            while (!st.empty() && st.back().val > nums[i]) {
                Item top = st.back();
                st.pop_back();
                curr.val = max(curr.val, top.val);
                curr.left = top.left;
            }

            st.push_back(curr);
        }

        for (size_t i = 0; i < st.size(); ++i) {
            for (int j = st[i].left; j <= st[i].right; ++j) ans[j] = st[i].val;
        }

        return ans;
    }
};
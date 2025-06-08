class Solution {
private:
    int n;
    void backtrack(int curr, vector<int>& ans){
        if (curr > n) return;

        ans.push_back(curr);

        for (int i = 0; i < 10; ++i)
            backtrack(curr * 10 + i, ans);
    }

public:
    vector<int> lexicalOrder(int n) {
        this -> n = n;
        vector<int> ans;
        for (int i = 1; i < 10; ++i)
            backtrack(i, ans);

        return ans;
    }
};
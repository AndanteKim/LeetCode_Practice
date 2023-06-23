class Solution {
private:
    int n, k;
    int backtrack(int i, int zeroCount, vector<int>& curr, vector<int>& cookies){
        if (n - i < zeroCount) return INT_MAX;
        if (i == n) return *max_element(curr.begin(), curr.end());
        int ans = INT_MAX;
        for (int j = 0; j < k; ++j){
            zeroCount -= int(curr[j] == 0);
            curr[j] += cookies[i];
            ans = min(ans, backtrack(i + 1, zeroCount, curr, cookies));
            curr[j] -= cookies[i];
            zeroCount += int(curr[j] == 0);
        }
        
        return ans;
    }
    
public:
    int distributeCookies(vector<int>& cookies, int k) {
        n = cookies.size(), this -> k = k;
        vector<int> curr(k, 0);
        return backtrack(0, k, curr, cookies);
    }
};
class Solution {
public:
    long long maximumBooks(vector<int>& books) {
        int n = books.size();
        
        auto calculateSum = [&](int l, int r){
            long long cnt = min(books[r], r - l + 1);
            return (2 * books[r] - (cnt - 1)) * cnt / 2;
        };
        
        stack<int> s;
        vector<long long> dp(n);
        for (int i = 0; i < n; ++i){
            // while we cannot push i, we pop from the stack
            while (!s.empty() && books[s.top()] - s.top() >= books[i] - i)
                s.pop();
            
            // compute dp[i]
            if (s.empty())
                dp[i] = calculateSum(0, i);
            else
                dp[i] = dp[s.top()] + calculateSum(s.top() + 1, i);
            
            // push the current index onto the stack
            s.push(i);
        }
        
        // return the maximum element in dp array
        return *max_element(dp.begin(), dp.end());
    }
};
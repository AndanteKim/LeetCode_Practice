typedef long long ll;

class Solution {
private:
    ll calculateSum(int left, int right, vector<int>& books){
        ll cnt = min(books[right], right - left + 1);
        return (2 * books[right] - cnt + 1) * cnt / 2;
    }
    
public:
    long long maximumBooks(vector<int>& books) {
        int n = books.size();
        vector<ll> dp(n);
        stack<int> stack;
        
        for (int i = 0; i < n; ++i){
            // while we can't push i, we pop from the stack
            while (!stack.empty() && books[stack.top()] - stack.top() >= books[i] - i)
                stack.pop();
            
            // compute dp[i]
            if (stack.empty())
                dp[i] = calculateSum(0, i, books);
            else
                dp[i] = dp[stack.top()] + calculateSum(stack.top() + 1, i, books);
            
            stack.push(i);
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};
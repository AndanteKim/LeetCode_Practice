class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string low = to_string(start), high = to_string(finish);
        int n = high.size();
        low = string(n - low.size(), '0') + low;    // Align digits
        int preLen = n - s.size();                  // prefix length

        vector<long long> memo(n, -1);
        function<long long(int, bool, bool)> dfs = 
            [&](int i, bool limitLow, bool limitHigh) -> long long{
                // Recursive boundary
                if (i == n) return 1;

                if (!limitLow && !limitHigh && memo[i] != -1) return memo[i];

                int lo = limitLow? low[i] - '0' : 0;
                int hi = limitHigh? high[i] - '0' : 9;

                long long ans = 0;
                if (i < preLen){
                    for (int digit = lo; digit <= min(hi, limit); ++digit){
                        ans += dfs(i + 1, limitLow && digit == lo, limitHigh && digit == hi);
                    }
                }
                else{
                    int x = s[i - preLen] - '0';
                    if (lo <= x && x <= min(hi, limit))
                    ans = dfs(i + 1, limitLow && x == lo, limitHigh && x == hi);
                }

                if (!limitLow && !limitHigh) memo[i] = ans;

                return ans;
        };

        return dfs(0, true, true);
    }
};
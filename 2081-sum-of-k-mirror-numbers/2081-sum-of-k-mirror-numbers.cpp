class Solution {
private:
    int digit[100];

public:
    long long kMirror(int k, int n) {
        auto isPalindrome = [&](long long x) -> bool{
            int length = -1;
            while (x){
                digit[++length] = x % k;
                x /= k;
            }

            for (int i = 0, j = length; i < j; ++i, --j){
                if (digit[i] != digit[j]) return false;
            }

            return true;
        };

        int left = 1, cnt = 0;
        long long ans = 0;

        while (cnt < n){
            int right = left * 10;
            // Op = 0 indicates enumerating odd-length palindromes
            // Op = 1 indicates enumerating even-length palindromes
            for (int op = 0; op < 2; ++op){
                for (int i = left; i < right && cnt < n; ++i){
                    long long combined = i;
                    int x = (op == 0)? i / 10 : i;
                    while (x){
                        combined = combined * 10 + x % 10;
                        x /= 10;
                    }
                    if (isPalindrome(combined)){
                        ++cnt;
                        ans += combined;
                    }
                }
            }
            left = right;
        }

        return ans;
    }
};
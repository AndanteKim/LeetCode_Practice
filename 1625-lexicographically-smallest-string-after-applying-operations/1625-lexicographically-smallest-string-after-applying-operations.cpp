class Solution {
private:
    int gcd(int n1, int n2){
        while (n2 > 0){
            n1 %= n2;
            swap(n1, n2);
        }
        return n1;
    }

public:
    string findLexSmallestString(string s, int a, int b) {
        string t, ans = s;
        int n = s.size(), g = gcd(n, b);
        s.append(s);

        auto add = [&](string& t, int start){
            int minVal = 10, times = 0;
            for (int i = 0; i < 10; ++i){
                int added = ((t[start] - '0') + i * a) % 10;
                if (added < minVal){
                    minVal = added;
                    times = i;
                }
            }

            for (int i = start; i < n; i += 2) t[i] = '0' + ((t[i] - '0') + times * a) % 10;
        };

        for (int i = 0; i < n; i += g){
            t = s.substr(i, n);
            add(t, 1);

            if (b % 2) add(t, 0);
            ans = min(ans, t);
        }

        return ans;
    }
};
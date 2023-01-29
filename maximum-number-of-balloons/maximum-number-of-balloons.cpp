class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> counter;
        for (const char& c: text) ++counter[c];
        int ans = 0;
        while(counter['b'] >= 1 && counter['a'] >= 1 && counter['l'] >= 2 && counter['o'] >= 2 \
              && counter['n'] >= 1) {
            ++ans; --counter['b']; --counter['a'];
            counter['l'] -= 2;
            counter['o'] -= 2;
            --counter['n'];
        }
        return ans;
    }
};
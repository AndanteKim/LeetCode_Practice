class Solution {
private:
    static constexpr int mod = 1'000'000'007;

public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int knowCnt = 1, shareCnt = 0;
        queue<pair<int, int>> know, share;
        know.push({1, 1});

        for (int i = 2; i <= n; ++i){
            if (know.front().first == i - delay){
                knowCnt = (knowCnt - know.front().second + mod) % mod;
                shareCnt = (shareCnt + know.front().second) % mod;
                share.push(know.front());
                know.pop();
            }

            if (share.front().first == i - forget){
                shareCnt = (shareCnt - share.front().second + mod) % mod;
                share.pop();
            }

            if (!share.empty()){
                knowCnt = (knowCnt + shareCnt ) % mod;
                know.push({i, shareCnt});
            }
        }

        return (knowCnt + shareCnt) % 1'000'000'007;
    }
};
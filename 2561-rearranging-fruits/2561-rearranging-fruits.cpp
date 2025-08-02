class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int m = std::numeric_limits<int>::max();
        unordered_map<int, int> freq;
        for (int b1 : basket1){
            ++freq[b1];
            m = min(m, b1);
        }

        for (int b2 : basket2){
            --freq[b2];
            m = min(m, b2);
        }

        vector<int> merge;
        for (auto [k, c] : freq){
            if (c % 2) return -1;
            for (int i = 0; i < (abs(c) >> 1); ++i) merge.push_back(k);
        }

        nth_element(merge.begin(), merge.begin() + (merge.size() >> 1), merge.end());
        return accumulate(merge.begin(), merge.begin() + (merge.size() >> 1), 0LL,\
        [&](long long res, int x) -> long long {
            return res + min(2 * m, x);
        });
    }
};
class Solution {
public:
    int maxPartitionsAfterOperations(string s, int k) {
        int n = s.size();
        vector<vector<int>> left(n, vector<int>(3, 0)), right(n, vector<int>(3, 0));

        int num = 0, mask = 0, count = 0, binary;
        for (int i = 0; i < n - 1; ++i){
            binary = 1 << (s[i] - 'a');

            if (!(mask & binary)){
                ++count;
                if (count <= k){
                    mask |= binary;
                }
                else{
                    ++num;
                    mask = binary;
                    count = 1;
                }
            }

            left[i + 1][0] = num;
            left[i + 1][1] = mask;
            left[i + 1][2] = count;
        }

        num = 0, mask = 0, count = 0;
        for (int i = n - 1; i > 0; --i){
            binary = 1 << (s[i] - 'a');

            if (!(mask & binary)){
                ++count;
                if (count <= k){
                    mask |= binary;
                }
                else{
                    ++num;
                    mask = binary;
                    count = 1;
                }
            }

            right[i - 1][0] = num;
            right[i - 1][1] = mask;
            right[i - 1][2] = count;
        }

        int maxVal = 0, seg, totCount;
        for (int i = 0; i < n; ++i){
            seg = left[i][0] + right[i][0] + 2;
            totCount = __builtin_popcount(left[i][1] | right[i][1]);


            if (left[i][2] == k && right[i][2] == k && totCount < 26)
                ++seg;
            else if (min(totCount + 1, 26) <= k)
                --seg;
            maxVal = max(maxVal, seg);
        }

        return maxVal;
    }
};
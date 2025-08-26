class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int ans = 0, l, w;
        double d = 0.0, maxD = 0.0;

        for (vector<int>& dimension : dimensions){
            l = dimension[0], w = dimension[1];
            d = pow(l * l + w * w, 0.5);
            if (d >= maxD){
                if (d == maxD) ans = max(ans, l * w);
                else {
                    ans = l * w;
                    maxD = d;
                }
            }
        }

        return ans;
    }
};
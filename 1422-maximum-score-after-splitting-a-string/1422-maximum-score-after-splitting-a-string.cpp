class Solution {
public:
    int maxScore(string s) {
        int leftZeros = (s[0] == '0')? 1 : 0, rightOnes = (s[0] == '1')? count(s.begin(), s.end(), '1') - 1 :\
        count(s.begin(), s.end(), '1');
        int n = s.size(), ans = leftZeros + rightOnes;

        for (int i = 1; i < n - 1; ++i){
            if (s[i] == '0')
                ++leftZeros;

            if (s[i] == '1')
                --rightOnes;
            
            ans = max(ans, leftZeros + rightOnes);
        }

        return ans;
    }
};
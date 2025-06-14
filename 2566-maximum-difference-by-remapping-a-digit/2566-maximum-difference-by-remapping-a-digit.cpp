class Solution {
public:
    int minMaxDifference(int num) {
        int n = num, mx = std::numeric_limits<int>::min(), mn = std::numeric_limits<int>::max();
        unordered_map<int, int> count;
        while (n > 0){
            ++count[n % 10];
            n /= 10;
        }

        for (const auto& [digit, _] : count){
            n = num;
            int currMax = 0, currMin = 0, decimal = 1;

            while (n > 0){
                int curr = n % 10;
                if (curr == digit){
                    currMax += 9 * decimal;
                }
                else{
                    currMax += curr * decimal;
                    currMin += curr * decimal;
                }
                decimal *= 10;
                n /= 10;
            }
            
            mx = max(mx, currMax);
            mn = min(mn, currMin);
        }
        

        return mx - mn;
    }
};
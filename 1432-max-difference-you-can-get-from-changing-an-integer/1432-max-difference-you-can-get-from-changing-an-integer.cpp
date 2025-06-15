class Solution {
public:
    int maxDiff(int num) {
        auto change = [&](int x, int y){
            string numS = to_string(num);
            for (char& digit : numS){
                if (digit - '0' == x)
                    digit = '0' + y;
            }
            return numS;
        };

        int minNum = num, maxNum = num;

        for (int x = 0; x < 10; ++x){
            for (int y = 0; y < 10; ++y){
                string res = change(x, y);

                // Check if there are leading zeros
                if (res[0] != '0'){
                    int resInt = stoi(res);
                    minNum = min(minNum, resInt);
                    maxNum = max(maxNum, resInt);
                }
            }
        }

        return maxNum - minNum;
    }
};
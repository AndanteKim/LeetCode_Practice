class Solution {
public:
    int maxDiff(int num) {
        auto replace = [](string& s, char x, char y){
            for (char& digit : s){
                if (digit == x) digit = y;
            }
        };


        string minNum = to_string(num), maxNum = to_string(num);
        int n = minNum.size();

        // Find a high position and replace it with 9.
        for (char digit : maxNum){
            if (digit != '9'){
                replace(maxNum, digit, '9');
                break;
            }
        }

        // Replace the most significant bit with 1
        // Or find a high-order digit that is not equal to the highest digit and replace it with 0.
        for (int i = 0; i < n; ++i){
            char digit = minNum[i];
            if (i == 0){
                if (digit != '1'){
                    replace(minNum, digit, '1');
                    break;
                }
            }
            else{
                if (digit != '0' && digit != minNum[0]){
                    replace(minNum, digit, '0');
                    break;
                }
            }
        }
        return stoi(maxNum) - stoi(minNum);
    }
};
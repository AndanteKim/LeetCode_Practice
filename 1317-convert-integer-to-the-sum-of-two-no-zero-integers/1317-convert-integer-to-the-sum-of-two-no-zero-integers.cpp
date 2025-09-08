class Solution {
private:
    bool isValid(int num){
        while (num > 0){
            if (num % 10 == 0) return false;
            num /= 10;
        }

        return true;
    }

public:
    vector<int> getNoZeroIntegers(int n) {
        for (int a = 1; a < n; ++a){
            int b = n - a;
            bool validA = isValid(a), validB = isValid(b);
            if (validA && validB) return {a, b};
        }

        return {-1, -1};
    }
};
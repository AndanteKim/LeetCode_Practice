class Solution {
private:
    int limit;
    long long calculate(string& x, string& s){
        if (x.size() < s.size()) return 0;

        if (x.size() == s.size()) return (x >= s)? 1 : 0;

        long long count = 0;
        int preLen = x.size() - s.size();
        string suffix = x.substr(x.size() - s.size());

        for (int i = 0; i < preLen; ++i){
            if (limit < (x[i] - '0')){
                count += pow(limit + 1, preLen - i);
                return count;
            }
            count += (x[i] - '0') * (long)pow(limit + 1, preLen - i - 1);
        }

        if (suffix >= s) ++count;

        return count;
    }


public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string start_ = to_string(start - 1), finish_ = to_string(finish);
        this -> limit = limit;
        return calculate(finish_, s) - calculate(start_, s);
    }
};
class Solution {
private:
    int n;
    string recursive(int i, string curr){
        // Base case
        if (i == n) return curr;

        string next = "";
        char currNum = '\0';
        int count = 0;

        for (const char& c : curr){
            if (currNum == '\0' || currNum == c){
                ++count;
            }
            else{
                next += to_string(count) + currNum;
                count = 1;
            }
            currNum = c;
        }

        next += to_string(count) + currNum;

        return recursive(i + 1, next);
    }

public:
    string countAndSay(int n) {
        this -> n = n;
        return recursive(1, "1");
    }
};
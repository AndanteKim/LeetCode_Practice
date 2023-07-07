class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int maxSize = 0, n = answerKey.size();
        unordered_map<char, int> count;
        
        for (int right = 0; right < n; ++right){
            ++count[answerKey[right]];
            int minor = min(count['T'], count['F']);
            if (minor <= k) {
                ++maxSize;
            }
            else{
                --count[answerKey[right - maxSize]];
            }
        }
        
        return maxSize;
    }
};
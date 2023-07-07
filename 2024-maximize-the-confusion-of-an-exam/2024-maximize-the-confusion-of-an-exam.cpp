class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int ans = 0, n = answerKey.size();
        
        int left = 0, offsetF = k;
        for (int right = 0; right < n; ++right){
            if (answerKey[right] == 'F'){
                if (offsetF > 0) --offsetF;
                else{
                    while (answerKey[left] == 'T') ++left;
                    ++left;
                }
            }
            
            ans = max(ans, right - left + 1);
        }
        
        left = 0;
        int offsetT = k;
        for (int right = 0; right < n; ++right){
            if (answerKey[right] == 'T'){
                if (offsetT > 0) --offsetT;
                else{
                    while (answerKey[left] == 'F') ++left;
                    ++left;
                }
            }
            
            ans = max(ans, right - left + 1);
        }
        
        return ans;
    }
};
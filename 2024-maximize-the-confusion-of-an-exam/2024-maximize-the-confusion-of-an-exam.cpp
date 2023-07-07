class Solution {
private:
    int n, k;
    bool isValid(int size, string& answerKey){
        unordered_map<char, int> counter;
        for (int i = 0; i < size; ++i) ++counter[answerKey[i]];
        if (min(counter['T'], counter['F']) <= k) return true;
        for (int i = size; i < n; ++i){
            ++counter[answerKey[i]];
            --counter[answerKey[i - size]];
            
            if (min(counter['T'], counter['F']) <= k) return true;
        }
        
        return false;
    }
    
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        n = answerKey.size(), this -> k = k;
        int left = k, right = n;
        
        while (left < right){
            int mid = left + ((right - left + 1) >> 1);
            if (isValid(mid, answerKey)){
                left = mid;
            }
            else right = mid - 1;
        }
        
        return left;
    }
};
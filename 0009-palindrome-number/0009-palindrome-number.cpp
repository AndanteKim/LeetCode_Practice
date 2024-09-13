class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        
        vector<int> elems;
        while (x > 0){
            elems.push_back(x % 10);
            x /= 10;
        }
        
        int left = 0, right = elems.size() - 1;
        while (left < right){
            if (elems[left] != elems[right])
                return false;
            ++left;
            --right;
        }
        
        return true;
    }
};
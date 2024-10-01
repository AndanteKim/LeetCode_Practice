class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        // Custom comparator to sort based on mod values
        sort(arr.begin(), arr.end(), [k](int a, int b){return (k + a % k) % k < (k + b % k) % k;});
        
        // Assign the pairs with modulo first
        int start = 0, end = arr.size() - 1;
        
        while (start < end){
            if (arr[start] % k)
                break;
            
            if (arr[start + 1] % k)
                return false;
            
            start += 2;
        }
        
        // Now, pick one element from the beginning and one element from the end.
        while (start < end){
            if ((arr[start++] + arr[end--]) % k)
                return false;
        }
        
        return true;
    }
};
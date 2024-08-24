typedef long long ll;

class Solution {
private:
    // Create candidates of palindrome
    ll halfToPalindrome(int left, bool even){
        ll cand = left;
        if (!even) left /= 10;
        
        while (left > 0){
            cand = cand * 10 + left % 10;
            left /= 10;
        }
        
        return cand;
    }
    
public:
    string nearestPalindromic(string n) {
        int length = n.size();
        int i = (length % 2 == 0)? (length >> 1) - 1: (length >> 1);
        ll firstHalf = stoll(n.substr(0, i + 1));
        
        /*
            Generate all possible palindromic candidates.
            1. Create a palindrome by mirroring the first half.
            2. Create a palindrome by mirroring the first half increment by 1
            3. Create a palindrome by mirroring the first half decrement by 1
            4. Handle edge cases by considering palindromes of the form 999...
               and 100...001 (smallest and largest n-digit palindromes).
        */
        vector<ll> possibilities;
        possibilities.push_back(halfToPalindrome(firstHalf, length % 2 == 0));
        possibilities.push_back(halfToPalindrome(firstHalf + 1, length % 2 == 0));
        possibilities.push_back(halfToPalindrome(firstHalf - 1, length % 2 == 0));
        possibilities.push_back(pow(10, length - 1) - 1);
        possibilities.push_back(pow(10, length) + 1);
        
        ll ans = 0, diff = LLONG_MAX, num = stoll(n);
        for (ll cand : possibilities){
            if (cand == num)
                continue;
            if (abs(cand - num) < diff){
                diff = abs(cand - num);
                ans = cand;
            }
            else if (abs(cand - num) == diff)
                ans = min(ans, cand);
        }
        
        return to_string(ans);
    }
};
class Solution {
private:
    int n;

    bool isPossible(vector<int>& candies, int size, long long k){
        // Initialize the total number of children that can be served
        long long piles = 0;

        for (int candy : candies){
            piles += candy / size;  // Add the number of children this pile can serve
        }

        return piles >= k;
    }

public:
    int maximumCandies(vector<int>& candies, long long k) {
        // Find the maximum number of candies in any pile
        this -> n = candies.size();
        
        // Set the initial search range for binary search
        int left = 0, right = *max_element(candies.begin(), candies.end());

        // Binary search to find the maximum number of candies each child can get
        while (left < right){
            // Calculate the middle value of the current range
            int mid = (left + right + 1) >> 1;

            // Check if it's possible to allocate candies so that each child
            // gets 'middle' candies
            if (isPossible(candies, mid, k))
                // If possible, move to the upper half to search for a larger number
                left = mid;
            else
                // Otherwise, move to the lower ball
                right = mid - 1;
        }

        return left;
    }
};
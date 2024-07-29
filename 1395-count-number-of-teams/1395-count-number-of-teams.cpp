class Solution {
private:
    // Update the Binary Indexed Tree
    void updateBIT(vector<int>& BIT, int index, int value){
        while (index < BIT.size()){
            BIT[index] += value;
            index += index & (-index);  // Move on to the next relevant index in BIT
        }
    }
    
    // Get the sum of all elements up to the given index in the BIT
    int getPrefixSum(vector<int>& BIT, int index){
        int sum = 0;
        while (index > 0){
            sum += BIT[index];
            index -= index & (-index);  // Move to the parent node in BIT
        }
        
        return sum;
    }
    
public:
    int numTeams(vector<int>& rating) {
        // Find the maximum string
        int maxRating = *max_element(rating.begin(), rating.end());
        
        // Initialize Binary Indexed Trees for left and right sides
        vector<int> leftBIT(maxRating + 1), rightBIT(maxRating + 1);
        
        // Populate the right BIT with all ratings initially
        for (int r : rating)
            updateBIT(rightBIT, r, 1);
        
        int teams = 0;
        for (int curr : rating){
            // Remove current rating from right BIT
            updateBIT(rightBIT, curr, -1);
            
            // Count soldiers with smaller and larger ratings on both sides
            int leftSmallest = getPrefixSum(leftBIT, curr - 1), rightSmallest = getPrefixSum(rightBIT, curr - 1);
            int leftLargest = getPrefixSum(leftBIT, maxRating) - getPrefixSum(leftBIT, curr);
            int rightLargest = getPrefixSum(rightBIT, maxRating) - getPrefixSum(rightBIT, curr);
            
            // Count increasing and decreasing sequences
            teams += leftSmallest * rightLargest + leftLargest * rightSmallest;
            
            // Add current rating to left BIT
            updateBIT(leftBIT, curr, 1);
        }
        
        return teams;
    }
};
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size(), teams = 0;
        
        // Iterate through each soldier as the middle soldier
        for (int mid = 0; mid < n; ++mid){
            int leftSmaller = 0, rightLarger = 0;
            
            // Count soldiers with smaller ratings on the left side of the current soldier
            for (int left = mid - 1; left >= 0; --left){
                if (rating[left] < rating[mid])
                    ++leftSmaller;
            }
            
            // Count soldiers with larger ratings on the right side of the current soldier
            for (int right = mid + 1; right < n; ++right){
                if (rating[mid] < rating[right])
                    ++rightLarger;
            }
            
            // Calculate and add the number of ascending rating teams(small-mid-larger)
            teams += leftSmaller * rightLarger;
            
            // Calculate solders with larger ratings on the left and smaller ratings on the right
            int leftLarger = mid - leftSmaller, rightSmaller = n - 1 - mid - rightLarger;
            
            // Calculate and add the number of descending rating teams (large-mid-small)
            teams += leftLarger * rightSmaller;
        }
        
        // Return the total number of valid teams
        return teams;
    }
};
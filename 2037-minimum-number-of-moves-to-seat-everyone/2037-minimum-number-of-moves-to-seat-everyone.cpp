class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        // Find the max position in the arrays
        int mx = max(*max_element(seats.begin(), seats.end()), *max_element(students.begin(), students.end()));
        
        // Stores difference between number of seats and students at each
        // position
        vector<int> diff(mx);
        
        // Count the available seats at each position
        for (int pos : seats)
            ++diff[pos - 1];
        
        // Remove the seats from students at that position
        for (int pos : students)
            --diff[pos - 1];
        
        // Calculate the number of moves needed to seat the students
        int ans = 0, unmatched = 0;
        for (int d : diff){
            ans += abs(unmatched);
            unmatched -= d;
        }
        
        return ans;
    }
};
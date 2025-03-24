class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        map<int, int> dayMap;
        int prefixSum = 0, prevDay = days;
        int freeDays = 0;

        for (const auto& meeting : meetings){
            // Set first day of meetings
            prevDay = min(prevDay, meeting[0]);
            
            // Process start and end of meeting
            ++dayMap[meeting[0]];
            --dayMap[meeting[1] + 1];
        }

        // Add all days before the first day of meetings
        freeDays += prevDay - 1;
        for (const auto& [currDay, _] : dayMap){
            // Add current range of days without a meeting
            if (prefixSum == 0)
                freeDays += currDay - prevDay;
            prefixSum += dayMap[currDay];
            prevDay = currDay;

        }

        // Add all days after the last day of meetings
        freeDays += days - prevDay + 1;
        return freeDays;
    }
};
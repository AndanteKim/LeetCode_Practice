class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        # If we have iterated over travel days, return 0.
        def solve(curr_day: int) -> int:
            # If we have iterated over travel days, return 0.
            if curr_day > days[-1]:
                return 0

            # If we don't need to travel on this day, move on to next day.
            if curr_day not in is_travel_needed:
                return solve(curr_day + 1)
            
            # If already calculated, return from here with the stored answer.
            if dp[curr_day] != -1:
                return dp[curr_day]

            one_day, seven_days = costs[0] + solve(curr_day + 1), costs[1] + solve(curr_day + 7)
            thirty_days = costs[2] + solve(curr_day + 30)

            # Store the cost with the minimum of the three options.
            dp[curr_day] = min(one_day, seven_days, thirty_days)
            return dp[curr_day]
        
        # The last day on which we need to travel
        is_travel_needed, last_day = set(), days[-1]
        dp = [-1] * (last_day + 1)

        # Mark the days on which we need to travel.
        for day in days:
            is_travel_needed.add(day)

        return solve(1)
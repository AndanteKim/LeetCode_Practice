class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        n = len(temperatures)
        hottest = 0
        ans = [0] * n
        
        for curr_day in range(n - 1, -1, -1):
            curr_temp = temperatures[curr_day]
            if curr_temp >= hottest:
                hottest = curr_temp
                continue
            
            days = 1
            
            while temperatures[curr_day + days] <= curr_temp:
                # use information from answer to search for the next warmer day
                days += ans[curr_day + days]
            ans[curr_day] = days
        
        return ans
        
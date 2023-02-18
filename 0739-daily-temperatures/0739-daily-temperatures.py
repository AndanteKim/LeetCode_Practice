class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        n, hottest = len(temperatures), 0
        ans = [0] * n
        
        for curr_day in range(n-1, -1, -1):
            current_temp = temperatures[curr_day]
            if current_temp >= hottest:
                hottest = current_temp
                continue
                
            days = 1
            while temperatures[curr_day + days] <= current_temp:
                days += ans[curr_day + days]
            ans[curr_day] = days
        
        return ans
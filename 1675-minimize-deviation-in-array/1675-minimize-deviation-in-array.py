class Solution:
    def minimumDeviation(self, nums: List[int]) -> int:
        n = len(nums)
        possible = []
        for i, num in enumerate(nums):
            if num % 2 == 0:
                temp = num
                possible.append((temp, i))
                while temp % 2 == 0:
                    temp //= 2
                    possible.append((temp, i))
            else:
                possible.append((num, i))
                possible.append((num * 2 ,i))
        
        possible.sort()
        
        min_deviation = float('inf')
        need_include = {i: 1 for i in range(n)}
        not_included, current_start = n, 0
        
        for current_value, current_item in possible:
            need_include[current_item] -= 1
            if need_include[current_item] == 0:
                not_included -= 1
            
            if not_included == 0:
                while need_include[possible[current_start][1]] < 0:
                    need_include[possible[current_start][1]] += 1
                    current_start += 1
            
                if min_deviation > current_value - possible[current_start][0]:
                    min_deviation = current_value - possible[current_start][0]
            
                need_include[possible[current_start][1]] += 1
                current_start += 1
                not_included += 1
        
        return min_deviation
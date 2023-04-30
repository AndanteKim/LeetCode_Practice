class Solution:
    def medianSlidingWindow(self, nums: List[int], k: int) -> List[float]:
        ans, hash_table = [], defaultdict(int)
        lo, hi = [], []
        i = 0
        while i < k:
            heappush(lo, -nums[i])
            i += 1
        
        for j in range(k // 2):
            heappush(hi, -heappop(lo));
        print(lo)
        print(hi)
        
        while True:
            if k & 1:
                ans.append(float(-lo[0]))
            else:
                ans.append((-lo[0] + hi[0]) * 0.5)
            if i >= len(nums):
                break
            outNum, inNum, balance = nums[i - k], nums[i], 0
            i += 1
            balance += -1 if outNum <= -lo[0] else 1
            hash_table[outNum] += 1
            
            if lo and inNum <= -lo[0]:
                balance += 1
                heappush(lo, -inNum)
            else:
                balance -= 1
                heappush(hi, inNum)
                
            if balance < 0:
                heappush(lo, -heappop(hi))
                balance += 1
            
            if balance > 0:
                heappush(hi, -heappop(lo))
                balance -= 1
            
            while hash_table[-lo[0]]:
                hash_table[-heappop(lo)] -= 1
            
            while hi and hash_table[hi[0]]:
                hash_table[heappop(hi)] -= 1
        return ans
                
        
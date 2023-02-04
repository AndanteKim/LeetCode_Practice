class Solution:
    # nC2
    def comb(self, cases: int, k : int) -> int:
        if k == 0:
            return 1
        elif n < k:
            return 0
        return comb(cases - 1, k - 1) + comb(cases - 1, k)
    
    def numIdenticalPairs(self, nums: List[int]) -> int:
        
        dic = defaultdict(list)
        for i in range(len(nums)):
            dic[nums[i]].append(i)
        
        ans = 0
        for val in dic.values():
            ans += comb(len(val), 2)
        
        return ans
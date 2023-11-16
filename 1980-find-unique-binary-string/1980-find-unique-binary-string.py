class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        integers = set()
        for num in nums:
            integers.add(int(num, 2))
            
        ans = int(nums[0], 2)
        n = len(nums)
        
        while ans in integers:
            ans = random.randrange(0, 2 ** n)
        
        s = bin(ans)[2:]
        return "0" * (n - len(s)) + s
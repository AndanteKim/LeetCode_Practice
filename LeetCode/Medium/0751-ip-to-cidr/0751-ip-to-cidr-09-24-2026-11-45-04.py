class Solution:
    def ip2number(self, ip: str) -> int:
        nums = list(map(int, ip.split(".")))
        n = (nums[0] << 24) + (nums[1] << 16) + (nums[2] << 8) + nums[3]
        return n
    
    def num2ip(self, n: int) -> str:
        return ".".join([str(n >> 24 & 255), str(n >> 16 & 255), str(n >> 8 & 255), str(n & 255)])
    
    def ilowbit(self, x: int) -> int:
        for i in range(32):
            if x & (1 << i):
                return i
        return 32
    
    def lowbit(self, x: int) -> int:
        return 1 << self.ilowbit(x)

    def ipToCIDR(self, ip: str, n: int) -> list[str]:
        ans, nums = [], self.ip2number(ip)

        while n > 0:
            lb = self.lowbit(nums)

            while lb > n:
                lb >>= 1
            
            n -= lb

            ans.append(self.num2ip(nums) + "/" + str(32 - self.ilowbit(lb)))
            nums += lb
        
        return ans
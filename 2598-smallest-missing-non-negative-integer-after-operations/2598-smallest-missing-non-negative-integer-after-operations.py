class Solution:
    def findSmallestInteger(self, nums: List[int], value: int) -> int:
        mod_freq = dict()

        for num in nums:
            mod = num % value
            mod_freq[mod] = mod_freq.get(mod, 0) + 1
        
        missing = 0
        while True:
            target = missing % value
            if target not in mod_freq or mod_freq[target] == 0:
                return missing

            mod_freq[target] -= 1
            missing += 1

        return ans
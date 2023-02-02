class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        k_lookup = defaultdict(int)
        
        for i in range(0, len(nums)):
            if nums[i] in k_lookup and abs(i - k_lookup[nums[i]]) <= k:
                return True
            k_lookup[nums[i]] = i 
                
        return False
                    
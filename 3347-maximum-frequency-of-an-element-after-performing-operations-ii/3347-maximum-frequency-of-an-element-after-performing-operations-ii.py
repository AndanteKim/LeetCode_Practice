class Solution:
    def maxFrequency(self, nums: List[int], k: int, numOperations: int) -> int:
        def add_mode(value: int) -> None:
            modes.add(value)
            if value - k >= nums[0]:
                modes.add(value - k)
            
            if value + k <= nums[-1]:
                modes.add(value + k)
        
        
        modes, freqs = set(), defaultdict(int)
        nums.sort()
        ans, n = 0, len(nums)
        last_num_idx = 0
        for i in range(n):
            if nums[i] != nums[last_num_idx]:
                freqs[nums[last_num_idx]] = i - last_num_idx
                ans = max(ans, i - last_num_idx)
                add_mode(nums[last_num_idx])
                last_num_idx = i
        
        freqs[nums[last_num_idx]] = n - last_num_idx
        ans = max(ans, n - last_num_idx)
        add_mode(nums[last_num_idx])

        for mode in sorted(modes):
            left = bisect_left(nums, mode - k)
            right = bisect_right(nums, mode + k)

            curr = min(right - left, freqs.get(mode, 0) + numOperations)
            ans = max(ans, curr)

        return ans
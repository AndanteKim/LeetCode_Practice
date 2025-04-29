class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        n = len(nums)
        ans, start, mx_elem, mx_elems_in_window = 0, 0, max(nums), 0

        for end in range(n):
            if nums[end] == mx_elem:
                mx_elems_in_window += 1
            
            while mx_elems_in_window == k:
                if nums[start] == mx_elem:
                    mx_elems_in_window -= 1
                start += 1

            ans += start

        return ans  
class Solution:
    def maxValue(self, nums: List[int]) -> List[int]:
        n = len(nums)
        # [val, l, r]
        ans, st = [0] * n, []

        for i in range(n):
            curr_val = nums[i]
            curr_left = curr_right = i 

            while st and st[-1][0] > nums[i]:
                top_val, top_left, top_right = st.pop()
                curr_val = max(curr_val, top_val)
                curr_left = top_left

            st.append((curr_val, curr_left, curr_right))

        for i in range(len(st)):
            for j in range(st[i][1], st[i][2] + 1):
                ans[j] = st[i][0]

        return ans
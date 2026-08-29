class Solution:
    def lexicographicallySmallestArray(self, nums: List[int], limit: int) -> List[int]:
        sorted_nums = sorted(nums)
        curr_grp, num_to_grp = 0, dict()
        num_to_grp[sorted_nums[0]] = curr_grp

        grp_to_list, n = dict(), len(nums)
        grp_to_list[curr_grp] = deque([sorted_nums[0]])

        for i in range(1, n):
            if abs(sorted_nums[i] - sorted_nums[i - 1]) > limit:
                curr_grp += 1
            
            num_to_grp[sorted_nums[i]] = curr_grp

            if curr_grp not in grp_to_list:
                grp_to_list[curr_grp] = deque()
            grp_to_list[curr_grp].append(sorted_nums[i])

        for i in range(n):
            grp = num_to_grp[nums[i]]
            nums[i] = grp_to_list[grp].popleft()

        return nums
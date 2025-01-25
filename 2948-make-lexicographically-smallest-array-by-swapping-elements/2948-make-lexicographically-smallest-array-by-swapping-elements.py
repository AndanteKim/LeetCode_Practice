class Solution:
    def lexicographicallySmallestArray(self, nums: List[int], limit: int) -> List[int]:
        n, nums_sorted = len(nums), sorted(nums)

        curr_group, num_to_group, group_to_list = 0, dict(), dict()
        num_to_group[nums_sorted[0]] = curr_group
        group_to_list[curr_group] = deque([nums_sorted[0]])

        for i in range(1, n):
            if abs(nums_sorted[i] - nums_sorted[i - 1]) > limit:
                # new group
                curr_group += 1
            
            # Assign current element to group
            num_to_group[nums_sorted[i]] = curr_group

            # Add element to sorted group deque
            if curr_group not in group_to_list:
                group_to_list[curr_group] = deque()
            group_to_list[curr_group].append(nums_sorted[i])

        # Iterate through input and overwrite each element with the next element in its corresponding group
        for i in range(n):
            num = nums[i]
            group = num_to_group[num]
            nums[i] = group_to_list[group].popleft()

        return nums
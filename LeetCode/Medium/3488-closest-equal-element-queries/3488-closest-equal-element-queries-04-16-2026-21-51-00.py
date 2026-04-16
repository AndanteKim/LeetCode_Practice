class Solution:
    def solveQueries(self, nums: List[int], queries: List[int]) -> List[int]:
        indices, n = defaultdict(list), len(nums)

        for i, num in enumerate(nums):
            indices[num].append(i)

        for pos in indices.values():
            x = pos[0]
            pos.insert(0, pos[-1] - n)
            pos.append(x + n)

        ans = [-1] * len(queries)
        for i, query in enumerate(queries):
            if len(indices[nums[query]]) == 3:
                continue
            pos_list = indices[nums[query]]
            pos, length = bisect_left(pos_list, query), len(pos_list)
            ans[i] = min(abs(pos_list[pos - 1] - pos_list[pos]), abs(pos_list[pos] - pos_list[pos + 1]))

        return ans
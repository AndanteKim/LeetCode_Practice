class Solution:
    def pivotArray(self, nums: List[int], pivot: int) -> List[int]:
        def merge(ans: List[int], elems: Deque[int]) -> None:
            while elems:
                ans.append(elems.popleft())
        
        left_side, center, right_side = deque(), deque(), deque()

        for num in nums:
            if num == pivot:
                center.append(num)
            elif num < pivot:
                left_side.append(num)
            else:
                right_side.append(num)

        ans = []
        merge(ans, left_side)
        merge(ans, center)
        merge(ans, right_side)

        return ans
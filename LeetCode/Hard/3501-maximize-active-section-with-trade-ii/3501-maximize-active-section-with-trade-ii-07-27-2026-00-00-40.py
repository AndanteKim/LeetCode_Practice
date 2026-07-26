class SegmentTree:
    def __init__(self, arr: List[int]):
        self.n = len(arr)
        self.arr = arr
        self.seg = [0] * (self.n << 2)
        
        if self.n:
            self.build(1, 0, self.n - 1)
    
    def build(self, p: int, l: int, r: int) -> None:
        if l == r:
            self.seg[p] = self.arr[l]
            return
        
        mid = (l + r) >> 1
        self.build(p << 1, l, mid)
        self.build(p << 1 | 1, mid + 1, r)

        self.seg[p] = max(self.seg[p << 1], self.seg[p << 1 | 1])

    def query(self, L: int, R: int) -> int:
        if L > R:
            return 0

        def _query(p: int, l: int, r: int) -> int:
            if L <= l and r <= R:
                return self.seg[p]
            
            mid = (l + r) >> 1
            ans = 0

            if L <= mid:
                ans = max(ans, _query(p << 1, l, mid))
            
            if R > mid:
                ans = max(ans, _query(p << 1 | 1, mid + 1, r))
            
            return ans
        
        return _query(1, 0 , self.n - 1)

class Solution:
    def maxActiveSectionsAfterTrade(self, s: str, queries: List[List[int]]) -> List[int]:
        n, cnt1 = len(s), s.count('1')

        zero_blocks = []
        block_left, block_right = [], []
        
        i = 0

        while i < n:
            st = i

            while i < n and s[i] == s[st]:
                i += 1
            
            if s[st] == '0':
                zero_blocks.append(i - st)
                block_left.append(st)
                block_right.append(i - 1)
        
        m = len(zero_blocks)

        if m < 2:
            return [cnt1] * len(queries)

        tmp_sum = [zero_blocks[i] + zero_blocks[i + 1] for i in range(m - 1)]
        seg, ans = SegmentTree(tmp_sum), []

        for l, r in queries:
            i, j = bisect_left(block_right, l), bisect_right(block_left, r) - 1

            if i > m - 1 or j < 0 or i >= j:
                ans.append(cnt1)
                continue
            
            first_len = block_right[i] - max(block_left[i], l) + 1

            last_len = min(block_right[j], r) - block_left[j] + 1

            if i + 1 == j:
                best_gain = first_len + last_len
                ans.append(cnt1 + best_gain)
                continue
            
            val1 = first_len +  zero_blocks[i + 1]
            val2 = zero_blocks[j - 1] + last_len
            val3 = seg.query(i + 1, j - 2)

            best_gain = max(val1, val2, val3)
            ans.append(cnt1 + best_gain)
        
        return ans
        
        
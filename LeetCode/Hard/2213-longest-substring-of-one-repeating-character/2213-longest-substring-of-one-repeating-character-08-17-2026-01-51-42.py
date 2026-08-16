class Solution:
    def longestRepeating(self, s: str, queryCharacters: str, queryIndices: List[int]) -> List[int]:
        n = len(s)
        pre, suf, max_len = [0] * (4 * n), [0] * (4 * n), [0] * (4 * n)
        left_ch, right_ch = [""] * (4 * n), [""] * (4 * n)

        def build(u: int, l: int, r: int) -> None:
            if l == r:
                pre[u], suf[u], max_len[u] = 1, 1, 1
                left_ch[u], right_ch[u] = s[l], s[l]
                return

            mid = (l + r) >> 1
            build(u << 1, l, mid)
            build(u << 1 | 1, mid + 1, r)
            push_up(u, l, r)
        
        def push_up(u: int, l: int, r: int) -> None:
            mid = (l + r) >> 1
            left_len, right_len = mid - l + 1, r - mid
            left, right = u << 1, u << 1 | 1
            left_ch[u], right_ch[u] = left_ch[left], right_ch[right]
            pre[u] = pre[left]

            if pre[left] == left_len and right_ch[left] == left_ch[right]:
                pre[u] = pre[left] + pre[right]
            suf[u] = suf[right]
            if suf[right] == right_len and right_ch[left] == left_ch[right]:
                suf[u] = suf[right] + suf[left]
            
            max_len[u] = max(max_len[left], max_len[right])
            if right_ch[left] == left_ch[right]:
                max_len[u] = max(max_len[u], suf[left] + pre[right])

        def update(u: int, l: int, r: int, pos: int, ch: str) -> None:
            if l == r:
                left_ch[u], right_ch[u] = ch, ch
                return

            mid = (l + r) >> 1
            if pos <= mid:
                update(u << 1, l, mid, pos, ch)
            else:
                update(u << 1 | 1, mid + 1, r, pos, ch)
            
            push_up(u, l, r)

        build(1, 0, n - 1)
        k, ans = len(queryIndices), []
        for i in range(k):
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i])
            ans.append(max_len[1])

        return ans
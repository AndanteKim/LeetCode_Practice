class Seg:
    def __init__(self, left: int = -1, right: int = -1):
        self.left, self.right = left, right

    def __lt__(self, rhs: int) -> bool:
        return (
            self.left > rhs.left
            if self.right == rhs.right
            else self.right < rhs.right
        )

class Solution:
    def maxNumOfSubstrings(self, s: str) -> list[str]:
        seg = [Seg() for _ in range(26)]

        # Preprocess the left and right endpoints.
        for i in range(len(s)):
            ch_idx = ord(s[i]) - 97
            if seg[ch_idx].left == -1:
                seg[ch_idx].left = seg[ch_idx].right = i
            else:
                seg[ch_idx].right = i
        
        for i in range(26):
            if seg[i].left != -1:
                j = seg[i].left
                while j <= seg[i].right:
                    ch_idx = ord(s[j]) - 97
                    if (
                        seg[i].left <= seg[ch_idx].left
                        and seg[ch_idx].right <= seg[i].right
                    ):
                        pass
                    else:
                        seg[i].left = min(seg[i].left, seg[ch_idx].left)
                        seg[i].right = max(seg[i].right, seg[ch_idx].right)
                        j = seg[i].left
                    j += 1
        
        # Greedily select intervals
        seg.sort()
        ans, end = list(), -1

        for se in seg:
            left, right = se.left, se.right
            if left == -1:
                continue
            
            if end == -1 or left > end:
                end = right
                ans.append(s[left : right + 1])

        return ans
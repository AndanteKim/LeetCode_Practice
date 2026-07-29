class Solution:
    def smallestPalindrome(self, s: str, k: int) -> str:
        def comb(n: int, m: int, k_lim: int) -> int:
            ans = 1
            m = min(m, n - m)

            for i in range(1, m + 1):
                ans = ans * (n - i + 1) // i
                if ans > k_lim:
                    return k_lim + 1
            
            return ans
        
        def permutations(rem: int) -> int:
            ways = 1
            for i in range(26):
                if bucket[i] == 0:
                    continue
                
                ways *= comb(rem, bucket[i], k)
                if ways > k:
                    break
                rem -= bucket[i]
            return ways

        partition, bucket = len(s) >> 1, [0] * 26

        for i in range(partition):
            bucket[ord(s[i]) - 97] += 1

        left_chars, start_idx = [], 1

        for pos in range(partition):
            for i in range(26):
                if bucket[i] == 0:
                    continue

                bucket[i] -= 1

                ways = permutations(partition - pos - 1)
                if start_idx + ways > k:
                    left_chars.append(chr(i + 97))
                    break
                
                bucket[i] += 1
                start_idx += ways
        
        if len(left_chars) < partition:
            return ""
        
        mid = s[partition] if len(s) % 2 else ""
        left_str = "".join(left_chars)
        right_str = left_str[::-1]
        return left_str + mid + right_str
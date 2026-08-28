class Solution:
    def lexPalindromicPermutation(self, s: str, target: str) -> str:
        def check(c: chr) -> str:
            left = prefix.copy()
            left.append(c)
            for i in range(25, -1, -1):
                left.extend([chr(97 + i)] * cnt[i])
            
            palindrome = left + [odd_ch] + left[::-1]
            return "".join(palindrome) > target

        n = len(s)
        if n == 1:
            return s if s > target else ""

        cnt = [0] * 26
        for c in s:
            cnt[ord(c) - 97] += 1

        odd_ch = ""
        for i in range(26):
            if cnt[i] % 2:
                if odd_ch != "":
                    return ""
                odd_ch = chr(97 + i)
            cnt[i] >>= 1

        prefix = []
        for i in range(n >> 1):
            is_found = False

            for j in range(26):
                if cnt[j] == 0:
                    continue
                cnt[j] -= 1
                if check(chr(97 + j)):
                    prefix.append(chr(97 + j))
                    is_found = True
                    break
                else:
                    cnt[j] += 1
            
            if not is_found:
                return ""
            
            if prefix[i] > target[i]:
                left = prefix[:]
                for j in range(26):
                    left.extend([chr(97 + j)] * cnt[j])
                palindrome = left + [odd_ch] + left[::-1]
                return "".join(palindrome)
        
        ans = prefix + [odd_ch] + prefix[::-1]
        return "".join(ans)
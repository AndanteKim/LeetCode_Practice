class Solution:
    def survivedRobotsHealths(self, positions: List[int], healths: List[int], directions: str) -> List[int]:
        pairs = [(pos, hp, sign) for pos, hp, sign in zip(positions, healths, directions)]
        pairs.sort()
        pos_idx, idx_hp = dict(), [0] * len(positions)
        for i in range(len(positions)):
            pos_idx[positions[i]] = i
            idx_hp[i] = healths[i]
        
        stack = []
        for pos, hp, sign in pairs:
            
            broken = False
            while not broken and stack and ((stack[-1][0] == pos and stack[-1][2] == sign) or \
                                            (stack[-1][2] == 'R' and sign == 'L')):
                if stack[-1][1] >= hp:
                    broken = True
                    prev_pos, prev_hp, prev_sign = stack.pop()
                    if prev_hp > hp:
                        prev_hp -= 1
                        idx_hp[pos_idx[prev_pos]] = prev_hp
                        stack.append((prev_pos, prev_hp, prev_sign))
                    else:
                        idx_hp[pos_idx[prev_pos]] = 0
                    idx_hp[pos_idx[pos]] = 0
                
                else:
                    hp -= 1
                    idx_hp[pos_idx[pos]] = hp
                    prev_pos, _, _ = stack.pop()
                    idx_hp[pos_idx[prev_pos]] = 0
            
            if not broken:
                stack.append((pos, hp, sign))
        
        ans = []
        for hp in idx_hp:
            if hp == 0:
                continue
            ans.append(hp)
        
        return ans
class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        list1 = list(range(1,n+1))
        perm = list(permutations(list1))
        target = perm[k-1]
        return "".join(map(str,target))

        
        
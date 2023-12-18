class Solution:
    def distributeCandies(self, candyType: List[int]) -> int:
        typeMap = {}
        for t in candyType:
            typeMap[t] = True
        return min(len(candyType) // 2, len(typeMap))
        
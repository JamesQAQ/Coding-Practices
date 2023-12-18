class Solution:
    def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        minVal = 10 ** 5
        ans = []
        indexes = {}
        for idx, s in enumerate(list1):
            indexes[s] = idx
        for idx, s in enumerate(list2):
            if s in indexes:
                v = idx + indexes[s]
                if v < minVal:
                    minVal = v
                    ans = [s]
                elif v == minVal:
                    ans.append(s)
        return ans
        
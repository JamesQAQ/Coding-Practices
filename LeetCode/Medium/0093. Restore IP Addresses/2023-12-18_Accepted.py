class Solution:
  def restoreIpAddresses(self, s: str) -> List[str]:
    result = []
    self._dfs(s, [], result)
    return result

  def _dfs(self, s: str, byte_list: List[int], result: List[str]):
    if not s or len(byte_list) == 4:
      if not s and len(byte_list) == 4:
        result.append('.'.join(byte_list))
      return

    for l in range(1, min(len(s) + 1, 4)):
      sliced = s[:l]
      if sliced[0] == '0' and len(sliced) > 1:
        continue
      if 0 <= int(sliced) and int(sliced) < 256:
        byte_list_copy = byte_list.copy()
        byte_list_copy.append(sliced)
        self._dfs(s[l:], byte_list_copy, result)

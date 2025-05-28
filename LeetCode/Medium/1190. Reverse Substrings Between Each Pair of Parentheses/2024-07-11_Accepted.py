class Solution:
  def reverseParentheses(self, s: str) -> str:
    st = []
    for ch in s:
      if ch != ')':
        st.append(ch)
      else:
        left_idx = len(st) - 1
        while st[left_idx] != '(':
          left_idx -= 1
        org_str = ''.join(st[left_idx + 1:])
        st = st[:left_idx]
        st.append(org_str[::-1])
    return ''.join(st)

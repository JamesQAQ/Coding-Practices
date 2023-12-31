class Solution:
  def daysBetweenDates(self, date1: str, date2: str) -> int:
    from datetime import datetime
    delta = datetime.strptime(
        date1, '%Y-%m-%d') - datetime.strptime(date2, '%Y-%m-%d')
    return abs(delta.days)

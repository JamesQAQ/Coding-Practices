class Solution:
  def dayOfYear(self, date: str) -> int:
    d = datetime.datetime.strptime(date, '%Y-%m-%d')
    return (d - datetime.datetime(year=d.year, month=1, day=1)).days + 1

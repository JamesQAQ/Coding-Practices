n = int(raw_input())
student_map = {}
for _ in xrange(n):
    inputs = raw_input().split(' ')
    name = inputs[0]
    score_sum = 0.0
    for score in inputs[1:]:
        score_sum += float(score)
    if len(inputs) - 1 > 0:
        student_map[name] = "%.2f" % (score_sum / (len(inputs) - 1))
    else:
        student_map[name] = None
query_name = raw_input()
print student_map[query_name]

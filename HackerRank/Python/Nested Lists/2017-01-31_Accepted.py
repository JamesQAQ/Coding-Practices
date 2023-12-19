if __name__ == '__main__':
    score_set = set()
    student_list = []
    for _ in range(int(input())):
        name = input()
        score = float(input())
        student_list.append((name, score))
        score_set.add(score)
    second_lowest_score = sorted(score_set)[1]
    name_list = [student[0] for student in student_list if student[1] == second_lowest_score]
    for name in sorted(name_list):
        print(name)

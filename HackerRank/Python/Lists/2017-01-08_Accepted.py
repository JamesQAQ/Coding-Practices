if __name__ == '__main__':
    arr = []
    N = int(input())
    for i in range(N):
        cmd = input()
        cmd += ')' if cmd.find(' ') >= 0 else '()'
        cmd = cmd.replace(' ', '(', 1)
        cmd = cmd.replace(' ', ',')

        if cmd == 'print()':
            print(arr)
        else:
            eval('arr.%s' % cmd)

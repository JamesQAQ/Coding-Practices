if __name__ == '__main__':
    n = int(input())
    print(hash(tuple([int(e) for e in input().split(' ')])))

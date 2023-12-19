import itertools

if __name__ == '__main__':
    x = int(input())
    y = int(input())
    z = int(input())
    n = int(input())
    print([[i, j, k] for (i, j, k) in itertools.product(range(x + 1), range(y + 1), range(z + 1)) if i + j + k != n])

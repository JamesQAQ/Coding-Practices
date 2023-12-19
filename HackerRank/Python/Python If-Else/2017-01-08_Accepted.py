if __name__ == '__main__':
    n = int(input())
    print('Weird' if n % 2 == 1 or n in range(6, 21) else 'Not Weird')

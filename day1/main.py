import numpy as np

def main(filename='numbers.txt'):
    arr = np.loadtxt(filename, dtype='int')
    # Answer 1
    answer1 = np.prod(arr[np.argwhere((arr + arr[:,None]) == 2020)[0]])
    print('answer 1:', answer1)
    # Answer 2
    answer2 = np.prod(arr[np.argwhere((arr + arr[:,None] + arr[:,None, None]) == 2020)[0]])
    print('answer 2:', answer2)

if __name__ == '__main__':
    main()

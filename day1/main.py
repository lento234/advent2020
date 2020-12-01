import numpy as np

def main(filename='numbers.txt'):
    arr = np.loadtxt(filename, dtype='int')
    answer = np.prod(arr[np.argwhere((arr + arr[:,None]) == 2020)[0]])
    print('answer:', answer)

if __name__ == '__main__':
    main()

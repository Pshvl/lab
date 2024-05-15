import sys
sys.setrecursionlimit(5)
def body():
    flag = True
    while flag:
        print('Input a filename>', end='')
        file_name = input()

        try:
            file = open(file_name, 'rt')
        except FileNotFoundError:
            print('FileNotFoundError')
            body()
        else:
            flag = False


    data = file.read()
    print('Input a string to find>', end='')
    word_to_find = input()
    print('Input a string to replace>', end='')
    word_to_replace = input()
    data = data.replace(word_to_find, word_to_replace)
    file.close()
    file = open(file_name, 'wt')
    file.write(data)
    file.close()

    print('Operation has been completed successfully')


def censorship():
    print('Censorship')
    body()
    print('Continue? (Y/N) >', end='')
    answer_YorN = input()
    while answer_YorN == 'Y':
        body()
        print('Continue? (Y/N) >', end='')
        answer_YorN = input()
    else:
        while answer_YorN != 'N':
            print('Continue? (Y/N) >', end='')
            answer_YorN = input()
        else:
            return 0


if __name__ == "__main__":
    censorship()

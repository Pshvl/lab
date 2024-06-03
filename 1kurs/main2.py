def function():
    print('Input a filename>', end='')
    file_name = input()
    file = open(file_name, 'rt')
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
    function()
    print('Continue? (Y/N) >', end='')
    answer_YorN = input()

    while answer_YorN == 'Y':
        function()
        print('Continue? (Y/N) >', end='')
        answer_YorN = input()
    else:
        exit()


censorship()

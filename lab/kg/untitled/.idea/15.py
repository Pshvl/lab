for a in range(0,300):
    count  = 0 #счетчик
    for x in range(0,300):
        for y in range(0,300):
            if (3*x + 4*y !=70) or (a>x) or (a>y):
                count+=1

    if count == 90000:  #проверяем для всех ли пар (х.у) выполняется условие
        print(a)
        break
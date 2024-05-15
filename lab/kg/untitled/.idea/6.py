import turtle
t=turtle.Turtle()
t.reset() #сброс
t.seth(90) #вертикально
t.width(2) #толщина 2
t.speed(100)
k = 10 #коэффициент для увеличения масштаба
t.right(180)
t.forward(5*k) #вперед 5 с коэф
t.right(90)
t.forward(50*k)
t.right(90)
t.forward(5*k)
#дуга!
for i in range(5): #5 повторов
    t.seth(90)
    t.circle(-5*k,180) # дуга 180 с радиусом -5к против часовой!!!!!
t.penup() #без следов
for x in range(0,-14,-1): #ставим точки
    for y in range(-5,8):
        t.goto(x*k , y*k ) #позиция черепахи
        t.dot(5) #точки
turtle.mainloop() #бесконечный цикл для окна,
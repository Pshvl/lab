import numpy as np
import math
from PIL import Image, ImageOps


# черный
# image_matrix = np.zeros((300, 400), dtype=np.uint8)
# img = Image.fromarray(image_matrix, mode='L')
# # img.save('im.png')
# for i in range(0, 300):
#     for j in range(0, 400): #бели
#         image_matrix[i, j] = 255
#
# # img.save('im2.png')
#
# # image_matrix2 = np.full((300, 400, 3), (255, 0, 0), dtype=np.uint8)
# # img = Image.fromarray(image_matrix2, mode='RGB')
# # # img.save('red.png')
#
# image_matrix2 = np.zeros((300, 400, 3), dtype=np.uint8)
#
# for i in range(0,300):
#     for j in range(0,400):
#         image_matrix2[i, j] = [(i + j) % 256, (i + j) % 256, (i + j) % 256]
# img = Image.fromarray(image_matrix2, mode='RGB')
# img.save('grad.png')


# def dotted_line(image, x0, y0, x1, y1, color):
#     count = math.sqrt((x0 - x1) ** 2 + (y0 - y1) ** 2)
#     step = 1.0 / count
#     for t in np.arange(0, 1, step):
#         x = round((1.0 - t) * x0 + t * x1)
#         y = round((1.0 - t) * y0 + t * y1)
#         image[y, x] = color
#
#
# image_matrix = np.matrix = np.zeros((200, 200), dtype=np.uint8)
# for i in range(13):
#     a = 2 * np.pi * i / 13
#     x0, y0 = 100, 100
#     x1, y1 = (int(100 + 95 * np.cos(a)), int(100 + 95 * np.sin(a)))
#     dotted_line(image_matrix, x0, y0, x1, y1, 255)
#     x_loop_line(image_matrix, x0, y0, x1, y1, 255)
#
# img = Image.fromarray(image_matrix, mode='L')
# img.save('line.png')


# 1 способ
# def dotted_line(image, x0, y0, x1, y1, count, color):
#     step = 1.0 / count
#     for t in np.arange(0, 1, step):
#         x = round((1.0 - t) * x0 + t * x1)
#         y = round((1.0 - t) * y0 + t * y1)
#         image[y, x] = color


# 2 способ
# def dotted_line(image, x0, y0, x1, y1, count, color):
#     count = math.sqrt((x0 - x1)**2 + (y0 -y1)**2)
#     step = 1.0/count
#     for t in np.arange (0, 1, step):
#         x = round ((1.0 - t)*x0 + t*x1)
#         y = round ((1.0 - t)*y0 + t*y1)
#         image[y, x] = color


# 3 cпособ
# def x_loop_line(image, x0, y0, x1, y1,color):
#
#     xchange = False
#     if (abs(x0 -x1) < abs(y0 - y1)):
#         x0, y0 = y0, x0
#         x1, y1 = y1, x1
#         xchange = True
#
#     if (x0 > x1):
#         x0, x1 = x1, x0
#         y0, y1 = y1, y0
#
#     for x in range (x0, x1):
#         t = (x-x0)/(x1 - x0)
#         y = round ((1.0 - t)*y0 + t*y1)
#
#         if (xchange):
#             image[x, y] = color
#         else:
#             image[y, x] = color


# 4 cпособ
# def x_loop_line(image, x0, y0, x1, y1, color):
#     xchange = False
#     if (abs(x0 - x1) < abs(y0 - y1)):
#         x0, y0 = y0, x0
#         x1, y1 = y1, x1
#         xchange = True
#
#     if (x0 > x1):
#         x0, x1 = x1, x0
#         y0, y1 = y1, y0
#
#     y = y0
#     dy = 2.0 * (x1 - x0) * abs(y1 - y0) / (x1 - x0)
#     derror = 0.0
#     y_update = 1 if y1 > y0 else -1
#
#     for x in range(x0, x1):
#         if (xchange):
#             image[x, y] = color
#         else:
#             image[y, x] = color
#         derror += dy
#         if (derror > 2.0 * (x1 - x0) * 0.5):
#             derror -= 2.0 * (x1 - x0) * 1.0
#             y += y_update


# Алгоритм Брезенхема
# def x_loop_line(image, x0, y0, x1, y1,color):
#
#     xchange = False
#     if (abs(x0 -x1) < abs(y0 - y1)):
#         x0, y0 = y0, x0
#         x1, y1 = y1, x1
#         xchange = True
#
#     if (x0 > x1):
#         x0, x1 = x1, x0
#         y0, y1 = y1, y0
#
#     y = y0
#     dy = 2*abs(y1 - y0)
#     derror = 0.0
#     y_update = 1 if y1 > y0 else -1
#
#     for x in range (x0, x1):
#         if (xchange):
#             image[x, y] = color
#         else:
#             image[y, x] = color
#         derror += dy
#         if (derror > (x1 - x0)):
#           derror -= 2*(x1 - x0)
#           y += y_update


# image_matrix = np.zeros((800, 800), dtype=np.uint8)
#
# for i in range(13):
#     a = 2 * np.pi * i / 13
#     x0, y0 = 400, 400
#     x1, y1 = (int(400 + 300 * np.cos(a)), int(400 + 300 * np.sin(a)))
#     # dotted_line(image_matrix, x0, y0, x1, y1, 90, 255)
#     x_loop_line(image_matrix, x0, y0, x1, y1, 255)
#
#
# img = Image.fromarray(image_matrix, mode='L')
# img.save('line4.png')

f = open('model_1.obj')

ar = []
for s in f:
    splitted = s.split()
    if (splitted[0] == 'v'):
        x = float(splitted[1])
        y = float(splitted[2])
        z = float(splitted[3])
        ar.append([x, y, z])
print(ar)

image_matrix = np.zeros((2000, 2000, 3), dtype=np.uint8)

for i in range(len(ar)):
    x = int(5000 * ar[i][0]) + 1000
    y = int(5000 * ar[i][1]) + 1000
    image_matrix[y, x] = [249, 66, 66]

img = Image.fromarray(image_matrix, mode='RGB')
img = ImageOps.flip(img)
img.save('img1.png')



# Алгоритм Брезенхема2
def drawline(x0, y0, x1, y1):
    xchange = False

    if (abs(x0 - x1) < abs(y0 - y1)):
        x0, y0 = y0, x0
        x1, y1 = y1, x1
        xchange = True

    if (x0 > x1):
        x0, x1 = x1, x0
        y0, y1 = y1, y0

    dx = x1 - x0
    dy = y1 - y0

    derror = 0
    if (dx != 0):
        derror = abs(dy / dx)
    error = 0.0
    y = int(y0)

    for x in range(int(x0), int(x1)):
        if (xchange):
            image_matrix[1000 - y, 1000 - x]  = [249, 66, 66] #перевертыш
        else:
            image_matrix[1000 - x, 1000 - y] = [249, 66, 66]
        error += derror
        if (error > 0.5):
            if (y1 > y0):
                y += 1
            else:
                y -= 1
            error -= 1
    return


def drawpolygonLine(points):
    #точки
    l1 = lines[int(points[0]) - 1]
    l2 = lines[int(points[1]) - 1]
    l3 = lines[int(points[2]) - 1]
    #соединяем точки
    drawline(l1[0], l1[1], l2[0], l2[1])
    drawline(l2[0], l2[1], l3[0], l3[1])
    drawline(l3[0], l3[1], l1[0], l1[1])


with open("model_1.obj", 'r') as f:
    # image_matrix = np.full((10000, 10000), 255, dtype=np.uint8)
    image_matrix = np.zeros((10000, 10000, 3), dtype=np.uint8)
    data = f.readlines()

    coordinates = []
    polygons = []

    for line in data:
      if (line[0] == 'f') : #строка с ф
            coordinates.append(line[2:-1])


    for line in coordinates:
        xyz = line.split()
        numbers = []
        for i in xyz:
            numbers.append(i.split('/')[0]) #добавляем без слеша
        polygons.append(numbers)


    coordinates = []
    lines = []

    for line in data:
        if (line[0] == 'v'):
            coordinates.append(line[2:-1])
    for line in coordinates:
        xyz = line.split()
        x = int(50000 * float(xyz[1]) + 5000)
        y = int(50000 * float(xyz[0]) + 5000)
        lines.append([x, y])

    for i in polygons:
        drawpolygonLine(i)

    image = Image.fromarray(image_matrix, 'RGB')
    image.save("img2.jpg")

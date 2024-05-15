import numpy as np
import random
from random import randint
from PIL import Image

width=2000
height=2000
#7
def barycentric_coordinates(x, y, x0, y0, x1, y1, x2, y2):
    lambda0 = ((x - x2) * (y1 - y2) - (x1 - x2) * (y - y2)) / ((x0 - x2) * (y1 - y2) - (x1 - x2) * (y0 - y2))
    lambda1 = ((x0 - x2) * (y - y2) - (x - x2) * (y0 - y2)) / ((x0 - x2) * (y1 - y2) - (x1 - x2) * (y0 - y2))
    lambda2 = 1.0 - lambda0 - lambda1
    return lambda0, lambda1, lambda2
#8.1-2
def get_random_color():
    return tuple(random.randint(0, 255) for _ in range(3))
def triugol(image_matrix, x0, y0, x1, y1, x2, y2):
    if ((x0 - x2) * (y1 - y2) - (x1 - x2) * (y0 - y2)) == 0: return
    xmin = min(x0, x1, x2)
    ymin = min(y0, y1, y2)
    xmax = max(x0, x1, x2)
    ymax = max(y0, y1, y2)

    # Учитываем границы изображения
    if xmin < 0:
        xmin = 0
    if ymin < 0:
        ymin = 0

    if xmax >= width:
       xmax = width - 1
    if ymax >= height:
       ymax = height - 1

    color=get_random_color()
    for y in range(ymin, ymax+1):
        for x in range(xmin, xmax+1):

            lambda0, lambda1, lambda2 = barycentric_coordinates(x, y, x0, y0, x1, y1, x2, y2)
            if lambda0 >= 0 and lambda1 >= 0 and lambda2 >= 0:
               image_matrix[y, x] = color

def normal(x0, y0, z0, x1, y1, z1, x2, y2, z2):
    normal_x = (y1 - y2) * (z1 - z0) - (z1 - z2) * (y1 - y0)
    normal_y = (z1 - z2) * (x1 - x0) - (x1 - x2) * (z1 - z0)
    normal_z = (x1 - x2) * (y1 - y0) - (y1 - y2) * (x1 - x0)

    return normal_x, normal_y, normal_z


def cos(normal_x, normal_y, normal_z):
    light_direction = np.array([0, 0, 1])
    normal_vector = np.array([normal_x, normal_y, normal_z])

    cos = np.dot(normal_vector, light_direction) / (np.linalg.norm(normal_vector) * np.linalg.norm(light_direction))

    return cos

with open("model_1.obj", 'r') as f:
    # image_matrix = np.full((10000, 10000), 255, dtype=np.uint8)
    image_matrix = np.zeros((width, height, 3), dtype=np.uint8)
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
        x = int(10000 * float(xyz[0]) + 1000)
        y = int(-10000 * float(xyz[1]) + 1000)
        lines.append([x, y])

    for i in polygons:
        l1 = lines[int(i[0]) - 1]
        l2 = lines[int(i[1]) - 1]
        l3 = lines[int(i[2]) - 1]
        triugol(image_matrix, l1[0], l1[1], l2[0], l2[1], l3[0], l3[1])

    image = Image.fromarray(image_matrix, 'RGB')
    image.save("img4.jpg")
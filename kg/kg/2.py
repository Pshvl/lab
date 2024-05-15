import numpy as np
import random
from random import randint
from PIL import Image

width=2000
height=2000
z_buffer = np.full((2000, 2000), np.inf)
#7
def barycentric_coordinates(x, y, x0, y0, x1, y1, x2, y2,z):
    lambda0 = ((x - x2) * (y1 - y2) - (x1 - x2) * (y - y2)) / ((x0 - x2) * (y1 - y2) - (x1 - x2) * (y0 - y2))
    lambda1 = ((x0 - x2) * (y - y2) - (x - x2) * (y0 - y2)) / ((x0 - x2) * (y1 - y2) - (x1 - x2) * (y0 - y2))
    lambda2 = 1.0 - lambda0 - lambda1

    z_coord = lambda0 * z[0] + lambda1 * z[1] + lambda2 * z[2]
    x_index, y_index = np.round(x).astype(int), np.round(y).astype(int)

    if lambda0 >= 0 and lambda1 >= 0 and lambda2 >= 0:
        if z_coord < z_buffer[y_index, x_index]:
            z_buffer[y_index, x_index] = z_coord
            return True

    return False
#8.1-2
def get_random_color():
    return tuple(random.randint(0, 255) for _ in range(3))
def triugol(image_matrix, x0, y0, x1, y1, x2, y2,color):
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


    for y in range(ymin, ymax+1):
        for x in range(xmin, xmax+1):

            if barycentric_coordinates(x, y, x0, y0, x1, y1, x2, y2, [l1[2], l2[2], l3[2]]):
                image_matrix[y, x] = color

def calculate_normal(x0, y0, z0, x1, y1, z1, x2, y2, z2):
    v1 = np.array([x1 - x0, y1 - y0, z1 - z0])
    v2 = np.array([x2 - x0, y2 - y0, z2 - z0])
    normal = np.cross(v1, v2)
    return normal[0], normal[1], normal[2]


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
    lines2 = []

    for line in data:
        if (line[0] == 'v' and line[1] == ' '):
            coordinates.append(line[2:-1])

    for line in coordinates:
        xyz = line.split()

        x = float(xyz[0])
        y = float(xyz[1])
        z = float(xyz[2])
        lines2.append([x, y,z])

        x = int(10000 * float(xyz[0]) + 1000)
        y = int(-10000 * float(xyz[1]) + 1000)
        z = int(10000 * float(xyz[2]) + 1000)
        lines.append([x, y,z])

    for i in polygons:
        l1 = lines[int(i[0]) - 1]
        l2 = lines[int(i[1]) - 1]
        l3 = lines[int(i[2]) - 1]

        l11 = lines2[int(i[0]) - 1]
        l22 = lines2[int(i[1]) - 1]
        l33 = lines2[int(i[2]) - 1]


        normal_x, normal_y, normal_z = calculate_normal(l11[0], l11[1], l11[2], l22[0], l22[1], l22[2], l33[0], l33[1], l33[2])

        cosin=cos(normal_x, normal_y, normal_z)

        if cosin < 0:
           color=(-255*cosin,10,200)
           triugol(image_matrix, l1[0], l1[1], l2[0], l2[1], l3[0], l3[1],color)
    image = Image.fromarray(image_matrix, 'RGB')
    image.save("img8.jpg")
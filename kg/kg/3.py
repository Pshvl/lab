import numpy as np
from PIL import Image
import math

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
# #8.1-2
# def get_random_color():
#     return tuple(random.randint(0, 255) for _ in range(3))
def triugol(image_matrix, x0, y0,z0, x1, y1,z1, x2, y2,z2,color,u0, v0, Ax, Ay):
    if ((x0 - x2) * (y1 - y2) - (x1 - x2) * (y0 - y2)) == 0: return

    ux0 = u0 + (Ax * x0)/z0
    uy0 = v0 - (Ay * y0)/z0

    ux1 = u0 + (Ax * x1)/z1
    uy1 = v0 - (Ay * y1)/z1

    ux2 = u0 + (Ax * x2)/z2
    uy2 = v0 - (Ay * y2)/z2

    xmin = math.floor(min(ux0, ux1, ux2))
    ymin =math.floor( min(uy0, uy1, uy2))
    xmax = math.ceil(max(ux0, ux1, ux2))
    ymax = math.ceil(max(uy0, uy1, uy2))

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

            if barycentric_coordinates(x, y, ux0, uy0, ux1, uy1, ux2, uy2, [l1[2], l2[2], l3[2]]):
                image_matrix[y, x] = color

def calculate_normal(x0, y0, z0, x1, y1, z1, x2, y2, z2):
    v1 = np.array([x1 - x0, y1 - y0, z1 - z0])
    v2 = np.array([x2 - x0, y2 - y0, z2 - z0])
    normal = np.cross(v1, v2)
    return normal[0], normal[1], normal[2]


def calculate_vertex_normals(vertices, polygons):
    vertex_normals = np.zeros_like(vertices)
    for polygon in polygons:
        v0, v1, v2 = vertices[polygon]
        normal = calculate_normal(v0, v1, v2)
        vertex_normals[polygon] += normal
    vertex_normals /= np.linalg.norm(vertex_normals, axis=1, keepdims=True)
    return vertex_normals

def cos(normal_x, normal_y, normal_z):
    light_direction = np.array([0, 0, 1])
    normal_vector = np.array([normal_x, normal_y, normal_z])

    cos = np.dot(normal_vector, light_direction) / (np.linalg.norm(normal_vector) * np.linalg.norm(light_direction))

    return cos

with open("model_1.obj", 'r') as f:
    # image_matrix = np.full((10000, 10000), 255, dtype=np.uint8)
    image_matrix = np.full((width, height, 3),(183,168,145), dtype=np.uint8)
    data = f.readlines()

    coordinates = []
    polygons = []


    Ax = 1000
    Ay = 1000

    #центр изображения
    u0 = 1000
    v0 = 1000

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
    alpha = np.radians(20)
    beta = np.radians(200)
    gamma = np.radians(0)

    R = np.array([[1, 0, 0],[0, np.cos(alpha), np.sin(alpha)],[0, -np.sin(alpha), np.cos(alpha)]]) @ np.array([[np.cos(beta), 0, np.sin(beta)],[0, 1, 0], [-np.sin(beta), 0, np.cos(beta)]]) @ np.array([[np.cos(gamma), np.sin(gamma), 0],[-np.sin(gamma), np.cos(gamma), 0],[0, 0, 1]])
    t = np.array([0, -0.04, 0.1])

    for line in data:
        if (line[0] == 'v' and line[1] == ' '):
            coordinates.append(line[2:-1])

    for line in coordinates:
        xyz = line.split()

        x = float(xyz[0])
        y = float(xyz[1])
        z = float(xyz[2])
        lines.append( (R @ [x, y, z]) + t)

    vertex_normals = calculate_vertex_normals(lines, polygons)
    for i in polygons:
        l1 = lines[int(i[0]) - 1]
        l2 = lines[int(i[1]) - 1]
        l3 = lines[int(i[2]) - 1]


        normal_x, normal_y, normal_z = calculate_normal(l1[0], l1[1], l1[2], l2[0], l2[1], l2[2], l3[0], l3[1], l3[2])

        cosin=cos(normal_x, normal_y, normal_z)

        if cosin < 0:
            color=(-255*cosin,58,10)
    #         triugol(image_matrix, int(10000 * l1[0] + 1000), int(-10000 * l1[1] + 1000), int(10000 * l1[2] + 1000), int(10000 * l2[0] + 1000),
    #                 int(-10000 * l2[1] + 1000), int(10000 * l2[2] + 1000), int(10000 * l3[0] + 1000), int(-10000 * l3[1] + 1000), int(10000 * l3[2] + 1000),color,u0, v0, Ax, Ay)
            triugol(image_matrix,  l1[0] , l1[1], l1[2], l2[0],l2[1],  l2[2] ,l3[0] , l3[1], l3[2],color,u0, v0, Ax, Ay)

    image = Image.fromarray(image_matrix, 'RGB')
    image.save("img9.jpg")
import numpy as np
from PIL import Image, ImageOps
import math

width=2000
height=2000
z_buffer = np.full((2000, 2000), np.inf)
texture = np.array(ImageOps.flip(Image.open("pic/tex.jpg")))
#7
def barycentric_coordinates(x, y, x0, y0, x1, y1, x2, y2):
    lambda0 = ((x - x2) * (y1 - y2) - (x1 - x2) * (y - y2)) / ((x0 - x2) * (y1 - y2) - (x1 - x2) * (y0 - y2))
    lambda1 = ((x0 - x2) * (y - y2) - (x - x2) * (y0 - y2)) / ((x0 - x2) * (y1 - y2) - (x1 - x2) * (y0 - y2))
    lambda2 = 1.0 - lambda0 - lambda1
    return lambda0, lambda1, lambda2

def triugol(image_matrix, x0, y0,z0, x1, y1,z1, x2, y2,z2,u0, v0, Ax, Ay, I0, I1, I2,texture, vt0, vt1, vt2):
    # if ((x0 - x2) * (y1 - y2) - (x1 - x2) * (y0 - y2)) == 0: return

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

    if xmax > width:
        xmax = width
    if ymax > height:
        ymax = height


    for y in range(ymin, ymax):
        for x in range(xmin, xmax):
            lambda0, lambda1, lambda2 = barycentric_coordinates(x, y, ux0, uy0, ux1, uy1, ux2, uy2)
            z_coord = lambda0 * z0 + lambda1 * z1 + lambda2 * z2
            #x_index, y_index = np.round(x).astype(int), np.round(y).astype(int)

            if lambda0 >= 0 and lambda1 >= 0 and lambda2 >= 0:
                #color = (lambda0 * I0 + lambda1 * I1 + lambda2 * I2)
                color = texture[int(1024 * (vt0[1] * lambda0 + vt1[1] * lambda1 + vt2[1] * lambda2))][int(1024 * (vt0[0] * lambda0 + vt1[0] * lambda1 + vt2[0] * lambda2))]
                # if (color > 0): color = 0
                if z_coord < z_buffer[y, x]:
                    z_buffer[y, x] = z_coord
                    # image_matrix[y, x] =  int(-255* color)
                    image_matrix[y, x] = color



def norm(x0, y0, z0, x1, y1, z1, x2, y2, z2): #нормаль к поверхности треугольника
    v1 = np.array([x1-x2, y1-y2, z1-z2])
    v2 = np.array([x1-x0, y1-y0, z1-z0])
    n = np.cross(v1, v2)
    return n
# def per(x, y, z):
#     coordinates_eq = np.array([x / z, y / z, 1])
#     scale = np.array([[1000, 0, 1000], [0, 1000, 1000], [0, 0, 1]])
#     persp_coordinates = scale @ coordinates_eq
#     return persp_coordinates[0], persp_coordinates[1]

def calculate_normal(x0, y0, z0, x1, y1, z1, x2, y2, z2):
    v1 = np.array([x1 - x0, y1 - y0, z1 - z0])
    v2 = np.array([x2 - x0, y2 - y0, z2 - z0])
    normal = np.cross(v1, v2)
    return normal


# def calculate_vertex_normals(vertices, polygons):
#     vertex_normals = np.zeros_like(vertices)
#     for polygon in polygons:
#         v0, v1, v2 = vertices[polygon]
#         normal = (v0, v1, v2)
#         vertex_normals[polygon] += normal
#     vertex_normals /= np.linalg.norm(vertex_normals, axis=1, keepdims=True)
#     return vertex_normals

def cos(normal):
    light_direction = np.array([0, 0, 1])
    cos = np.dot(normal, light_direction) / (np.linalg.norm(normal) * np.linalg.norm(light_direction))

    return cos

with open("model_1.obj", 'r') as f:
    # image_matrix = np.full((10000, 10000), 255, dtype=np.uint8)
    image_matrix = np.full((width, height, 3),(183,168,145), dtype=np.uint8)
    data = f.readlines()

    textureList = []
    textureNums = []
    vt0 = []
    vt1 = []
    vt2 = []

    coordinates = []
    polygons = []
    lines = []
    alpha = np.radians(20)
    beta = np.radians(180)
    gamma = np.radians(0)

    R = np.array([[1, 0, 0],[0, np.cos(alpha), np.sin(alpha)],[0, -np.sin(alpha), np.cos(alpha)]]) @ np.array([[np.cos(beta), 0, np.sin(beta)],[0, 1, 0], [-np.sin(beta), 0, np.cos(beta)]]) @ np.array([[np.cos(gamma), np.sin(gamma), 0],[-np.sin(gamma), np.cos(gamma), 0],[0, 0, 1]])
    t = np.array([0, -0.04, 0.1])
#масштаб
    Ax = 1000
    Ay = 1000

    #центр изображения
    u0 = 1000
    v0 = 1000

    for line in data:
        if (line[0] == 'v' and line[1] == ' '):
            coordinates.append(line[2:-1])
    for line in coordinates:
        xyz = line.split()

        x = float(xyz[0])
        y = float(xyz[1])
        z = float(xyz[2])
        lines.append( (R @ [x, y, z]) + t)



    for line in data:
        splitted = line.split()
        if (splitted[0] == 'f'):
           poly1 = splitted[1].split('/')
           n1 = poly1[0]
           tex1 = int(poly1[1])
           poly2 = splitted[2].split('/')
           n2 = poly2[0]
           tex2 = int(poly2[1])
           poly3 = splitted[3].split('/')
           n3 = poly3[0]
           tex3 = int(poly3[1])
           polygons.append([n1, n2, n3])
           textureNums.append([tex1, tex2, tex3])
    all_norms = np.zeros((len(polygons), 3), dtype=float)
    f.seek(0)
    for s in f:
        splitted = s.split()
        if splitted[0] == "vt":
            textureList.append([float(x) for x in splitted[1:3]])






    # vertex_normals = calculate_vertex_normals(lines, polygons)
    for i in range(len(polygons)):
        x0 = lines[int(polygons[i][0]) - 1][0]
        y0 = lines[int(polygons[i][0]) - 1][1]
        z0 = lines[int(polygons[i][0]) - 1][2]

        x1 = lines[int(polygons[i][1]) - 1][0]
        y1 = lines[int(polygons[i][1]) - 1][1]
        z1 = lines[int(polygons[i][1]) - 1][2]

        x2 = lines[int(polygons[i][2]) - 1][0]
        y2 = lines[int(polygons[i][2]) - 1][1]
        z2 = lines[int(polygons[i][2]) - 1][2]

        n = norm(x0, y0, z0, x1, y1, z1, x2, y2, z2)

        all_norms[int(polygons[i][0]) - 1] += n
        all_norms[int(polygons[i][1]) - 1] += n
        all_norms[int(polygons[i][2]) - 1] += n

    for i in range(len(polygons)):
        # l1 = lines[i]
        # l2 = lines[i+1]
        # l3 = lines[i+2]

        x0 = lines[int(polygons[i][0]) - 1][0]
        y0 = lines[int(polygons[i][0]) - 1][1]
        z0 = lines[int(polygons[i][0]) - 1][2]

        x1 = lines[int(polygons[i][1]) - 1][0]
        y1 = lines[int(polygons[i][1]) - 1][1]
        z1 = lines[int(polygons[i][1]) - 1][2]

        x2 = lines[int(polygons[i][2]) - 1][0]
        y2 = lines[int(polygons[i][2]) - 1][1]
        z2 = lines[int(polygons[i][2]) - 1][2]

        vt0 = [textureList[int(textureNums[i][0] - 1)][0], textureList[int(textureNums[i][0] - 1)][1]]
        vt1 = [textureList[int(textureNums[i][1] - 1)][0], textureList[int(textureNums[i][1] - 1)][1]]
        vt2 = [textureList[int(textureNums[i][2] - 1)][0], textureList[int(textureNums[i][2] - 1)][1]]

        normal = norm(x0, y0, z0, x1, y1, z1, x2, y2, z2)

        cosin=cos(normal)

        I0 = cos(all_norms[int(polygons[i][0]) - 1])
        I1 = cos(all_norms[int(polygons[i][1]) - 1])
        I2 = cos(all_norms[int(polygons[i][2]) - 1])

        if cosin < 0:
            # color=(-255*cosin,58,10)
             triugol(image_matrix,x0, y0, z0, x1, y1, z1, x2, y2, z2, u0, v0, Ax, Ay, I0, I1, I2, texture, vt0, vt1, vt2)


    image = Image.fromarray(image_matrix, 'RGB')
    image.save("img11 .jpg")
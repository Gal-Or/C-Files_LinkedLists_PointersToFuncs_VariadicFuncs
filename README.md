# C-Files_LinkedLists_PointersToFuncs_VariadicFuncs

The third exercise in a C programming course. 
The exercise involves files, linked lists, pointers to functions and variadic Functions.

## Description

In this exercise a number of operations have to be performed on files describing shapes of three-dimensional bodies in space. Use these files in the field of 3D printing, virtual reality display and more.
Several companies have developed applications for creating three-dimensional bodies in virtual space. Most of them define the body as a collection of polygons that "envelop" it. For this purpose, a large number of points (vertexes) are defined on the body, and in addition, the poles (faces) are defined whose vertices are from the collection of points defined earlier.
In this exercise we will refer to objects defined in OBJ format.

The file in this format is a text file that contains information required for the visualization of an object, including information about vertexes and faces.
* Each line in the file that begins with the letter v with three numbers describes a point in space (x, y, z), for example : v   5.3674   0.607756   6.01734 describes a point in place (5.3674, 0.60775, 6 6.01734). For each point, vertex has a serial number that is equal to the number of points defined in the file before the point P plus 1. This number is used in the face definition.
* Each line that begins with the letter f and is followed by integers depicts a particular polygon (face) using its vertex data. Some data may not appear, but a vertex serial number always appears (appears in bold in the examples below). For example, a triangle with vertices at points whose serial numbers are 1842, 1841, 1835, can take one of the following forms:
f   1835/1966/1855    1842/1976/1865    1841/1974/1863
f   1835/1966         1842/1976             1841/1974
f   1835//1855        1842//1865            1841//1863
f   1835              1842                      1841




## How To Run 
This project runing on visual studio.

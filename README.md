# C-Files_LinkedLists_PointersToFuncs_VariadicFuncs

The third exercise in a C programming course. 
The exercise involves files, linked lists, pointers to functions and variadic Functions.

## Description

In this exercise a number of operations have to be performed on files describing shapes of three-dimensional bodies in space. Use these files in the field of 3D printing, virtual reality display and more.
Several companies have developed applications for creating three-dimensional bodies in virtual space. Most of them define the body as a collection of polygons that "envelop" it. For this purpose, a large number of points (vertexes) are defined on the body, and in addition, the poles (faces) are defined whose vertices are from the collection of points defined earlier.
In this exercise we will refer to objects defined in OBJ format.

* For example, the cube with side size 1 can be set as follows:

![image](https://user-images.githubusercontent.com/74857750/149569267-9d085588-8fbc-44cc-b7f4-17b0b22730ee.png)

* The faces of the cube, in each row there are serial numbers of the points in the vertex of the polygon:
![image](https://user-images.githubusercontent.com/74857750/149569474-55bd0c07-3ad3-4864-9e86-a3c59f6cccae.png)

* In most cases the polygonal queue will use triangles and thus achieve the required accuracy and detail.
* ![image](https://user-images.githubusercontent.com/74857750/149569586-96705764-91c1-4d33-ad7f-e9ad7c66681f.png)


### File Details
The file in this format is a text file that contains information required for the visualization of an object, including information about vertexes and faces.
* Each line in the file that begins with the letter v with three numbers describes a point in space (x, y, z), for example : v   5.3674   0.607756   6.01734 describes a point in place (5.3674, 0.60775, 6 6.01734). For each point, vertex has a serial number that is equal to the number of points defined in the file before the point P plus 1. This number is used in the face definition.
* Each line that begins with the letter f and is followed by integers depicts a particular polygon (face) using its vertex data. Some data may not appear, but a vertex serial number always appears (appears in bold in the examples below). For example, a triangle with vertices at points whose serial numbers are 1842, 1841, 1835, can take one of the following forms:
![image](https://user-images.githubusercontent.com/74857750/149567993-970dc5d9-552a-4964-a80d-8619b92207ac.png)

Definition: A collection of objects is called a Scene. For the purpose of the exercise it is required to realize the collection with the help of a one-way linked list.
For the purpose of solving the exercise we will define the following structures:
![image](https://user-images.githubusercontent.com/74857750/149568222-1c67f5f4-bc18-4d34-a571-d1cfbd638f6b.png)

## Tasks:
1. Write a function void transformObject (char * originalObjectFileName, char * deformedObjectFileName); The function transforms on a given Obj file. It gets names of two files in OBJ format. The original and the one that will contain the object after transformation on any Vertex defined in the original file according to the following validity: x1 = 0.3*x y1=y z1=z .
2. Write a function that gets the name of an OBJ format file and builds an Object structure accordingly. Object * createObject (char * filename).
3. Write a function that constructs a Scene structure consisting of several objects as a linked list. Scene * createScene (char * fileName, ...); The function that receives an unknown number of pointers for file names, in each OBJ format object definition file. The last parameter is NULL. The function creates and returns a Scene structure that contains a one-way linked list of all objects.
4. Write functions that perform various actions on the object. The uniform signature of the functions will help in generic writing in the next section.
    * function that accepts the pointer to the Object and calculates the number of faces of the object that have three Vertexes -> void printFaces (Object * ptr, void *          numberOfTriangularFaces)
    * A function that receives the pointer on the Object returns the number of vertexes of the object -> void printVertexes (Object * ptr, void * numberOfVertexes).
    * A function that accepts the pointer to the Object calculates the total area of all the faces of the object that have three Vertexes -> void getTotalArea (Object * ptr,   void * totalAreaOfTriangularFaces)
5. Write a function that receives, Scene points to a function of the type defined in section 4, a string that specifies the type of the print variable, and points to a string. The perform function goes through all the objects in the Scene and performs a reading with the help of the pointer to the function. At the end it prints the string and the sum of all the results. Possible print type INT, DOUBLE, STR, CHAR.
6. Write functions that save / upload the Scene in a file / text file or binary of the user's choice. There is no specific requirement for the file format as long as reading the saved file produces a proper Scene Back -> void saveScene (Scene * scene, char * fileName, enum FileType type); Scene * loadScene (char * fileName, enum FileType type); . In the loadScene function all the required memory allocations were made in creating all the new structures that make up the newly created scene.
7. Write a function that frees up all the memory allocated during the construction of the scene -> void freeScene (Scene * scene).
8. Add valid tests so that the program does not fly if, for example - the obj file is not found.

## How To Run 
This project runing on visual studio.

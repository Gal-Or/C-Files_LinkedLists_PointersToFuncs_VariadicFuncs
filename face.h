#pragma once
#include "vertex.h"
typedef struct {
	int size;	// Number of vertexes of the face	
	int* vertex;	// Array of Ids of the vertexes
} Face;

double getArea(Vertex v1, Vertex v2, Vertex v3);

double calcSide(Vertex v1, Vertex v2);

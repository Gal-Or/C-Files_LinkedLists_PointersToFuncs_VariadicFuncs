#pragma once

typedef struct {
	float x; // Coordinates of Vertex
	float y;
	float z;
} Vertex;

int countVertexInLine(char* line);
void copyTransformVertex(FILE* fdst, char* line);

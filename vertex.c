#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "vertex.h"

int countVertexInLine(char* line)
{// count the number of vertexex on one line of the face
	int count = 0;
	for (int i = 0; i < strlen(line); i++)
		if (line[i] == ' ')
			count++;

	return count;
}

void copyTransformVertex(FILE* fdst, char* line)
{//copy vertex after transformation
	float x, y, z;
	int r = sscanf(line, "%*c %f %f %f", &x, &y, &z);

	x *= 0.3;
	fprintf(fdst, "%c %f %f %f\n", line[0], x, y, z);

}
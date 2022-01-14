#pragma once
#include <stdio.h>
#include "vertex.h"
#include "face.h"

typedef struct {
	// Array of all Vertexes
	int numberOfVertexes;
	Vertex* vertexes;
	// Array of all Faces
	int  numberOfFaces;
	Face* faces;
} Object;

void transformObject(char* originalObjectFileName, char* deformedObjectFileName);
Object* createObject(char* filename);
void countVF(Object* o, FILE* f);
void addVertexesAndFaces(Object* o, FILE* f);
void blank(char* sentence);
void addFace(char* line, Object* o, int count);
void saveBinObject(Object* ob, FILE* f);
Object* loadBinObject(FILE* f);
void printFaces(Object* ptr, void* numberOfTriangularFaces);
void printVertexes(Object* ptr, void* numberOfVertexes);
void getTotalArea(Object* ptr, void* totalAreaOfTriangularFaces);
void freeObject(Object* ob);
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "scene.h"
#include "object.h"
#include "vertex.h"////////////////
#include "face.h"////////////////


Scene* createScene(char* fileName, ...) // creat scene from the files
{
	Scene* scene = (Scene*)malloc(sizeof(Scene));
	if(!scene)
		return NULL;
	scene->list = (List*)malloc(sizeof(List));
	if (!scene->list)
		return NULL;
	BOOL b= L_init(scene->list);
	if(!b)
		return NULL;
	
	va_list files;
	va_start(files, fileName);
	Object* o = createObject(fileName);
	
	Node* pNode =L_insert(&scene->list->head, o);
	if(!pNode)
		return NULL;
	
	char* curFile = va_arg(files, char*);
	while (curFile && o && pNode)
	{
		o = createObject(curFile);
		pNode = L_insert(pNode, o);
		curFile = va_arg(files, char*);
	}
	return scene;
}

void perform(Scene* scene, void(*ptrFunction)(Object*, void*), char* type, char* str)
{// get function pointer and calculte what asked for.

	printf("%s ", str);
	Node* n = scene->list->head.next;
	void* numPtr;
	void* tempSum;
	char c;
	switch (*type)
	{
	case 'I':
		numPtr = (int*)calloc(sizeof(int));
		tempSum = (int*)calloc(sizeof(int));
		break;
	case 'D':
		numPtr = (double*)calloc(sizeof(double));
		tempSum = (double*)calloc(sizeof(double));
		break;
	
	default:
		numPtr = (double*)calloc(sizeof(double));
		tempSum = (double*)calloc(sizeof(double));
		break;

	}
	if (!numPtr || !tempSum)
		return NULL;
	while (n)
	{
		ptrFunction(n->value, numPtr);
		if (*type == 'I')
			*(int*)tempSum += *(int*)numPtr;
			
		else if(*type == 'D')
			*(double*)tempSum += *(double*)numPtr;
		n = n->next;
	}
	if (*type == 'I')
		printf("%d\n", *(int*)tempSum);
	else if (*type == 'D')
		printf("%lf\n", *(double*)tempSum);
		
	free(numPtr);
	free(tempSum);

	}

void saveScene(Scene* scene, char* fileName, enum FileType type)
{// save the scene to file by option. text or binary.
	int count = countObjects(scene);
	int sucsses = 0;
	if (type == 1)
		sucsses = saveBinFormat(scene, fileName, count);
	else
		sucsses = saveTxtFormat(scene, fileName, count);

	if (sucsses == 0)
		printf("faild save scene to file..\n");

}

int saveBinFormat(Scene* scene, char* fileName, int count)
{//save the scene to file in binary format.
	FILE* f = fopen(fileName, "wb");
	if (!f)
		return 0;

	Node* n = scene->list->head.next;

	fwrite(&count, sizeof(int), 1, f);

	for (int i = 0; i < count; i++)
	{
		saveBinObject(n->value, f);
		n = n->next;
	}
	fclose(f);
	return 1;
}

int saveTxtFormat(Scene* scene, char* fileName, int count)
{//save the scene to file in text format.
	FILE* f = fopen(fileName, "w");
	if (!f)
		return 0;

	Node* n = scene->list->head.next;
	fprintf(f, "%d\n", count);
	
	for (int i = 0; i < count; i++)
	{
		fprintf(f, "%d\n", n->value->numberOfVertexes);
		for (int i = 0; i < n->value->numberOfVertexes; i++)
			fprintf(f, "%f %f %f\n", n->value->vertexes[i].x, n->value->vertexes[i].y, n->value->vertexes[i].z);
		fprintf(f, "%d\n", n->value->numberOfFaces);
		for (int i = 0; i < n->value->numberOfFaces; i++) {
			fprintf(f, "%d\n", n->value->faces[i].size);
			for (int j = 0; j < n->value->faces[i].size; j++) {
				fprintf(f, "%d\n", n->value->faces[i].vertex[j]);
			}
		}
		n = n->next;
	}
	fclose(f);
	return 1;
}

Scene* loadScene(char* fileName, enum FileType type)
{ // load scene by option. text or binary format
	Scene* scene = (Scene*)malloc(sizeof(Scene));
	if (!scene)
		return NULL;
	scene->list = (List*)malloc(sizeof(List));
	if (!scene->list)
		return NULL;
	BOOL b = L_init(scene->list);
	if (!b)
		return NULL;

	if (type == 1)
		scene = loadBinFormat(fileName, scene);

	else
		scene = loadTxtFormat(fileName, scene);
	
	if(scene == NULL)
		printf("faild load scene from file..\n");
	
	return scene;
}

Scene* loadTxtFormat(char* fileName, Scene * scene)
{//load scene from text file format
	Object* ob;
	Node* n = &scene->list->head;
	FILE* f = fopen(fileName, "r");
	if (!f)
		return NULL;
	int count, num;

	num =fscanf(f, "%d", &count);
	
	for (int i = 0; i < count; i++)
	{
		ob = (Object*)malloc(sizeof(Object));
		num = fscanf(f, "%d", &ob->numberOfVertexes);
		ob->vertexes = (Vertex*)malloc(ob->numberOfVertexes * sizeof(Vertex));
		if (!ob->vertexes) return NULL;

		for (int i = 0; i < ob->numberOfVertexes; i++)
		{
			num = fscanf(f, "%f", &ob->vertexes[i].x);
			num = fscanf(f, "%f", &ob->vertexes[i].y);
			num = fscanf(f, "%f", &ob->vertexes[i].z);
		}
		num = fscanf(f, "%d", &ob->numberOfFaces);
		ob->faces = (Face*)malloc(sizeof(Face)* ob->numberOfFaces);
		if (!ob->faces) return NULL;
	
		for (int i = 0; i < ob->numberOfFaces; i++)
		{
			num = fscanf(f, "%d", &ob->faces[i].size);
			ob->faces[i].vertex = (int*)malloc(ob->faces[i].size * sizeof(int));
			if (!ob->faces[i].vertex) return NULL;
			
			for (int j = 0; j < ob->faces[i].size; j++)
				num = fscanf(f, "%d", &ob->faces[i].vertex[j]);
		}
		n = L_insert(n, ob);
	}
	fclose(f);
	return scene;
} 

Scene* loadBinFormat(char* fileName, Scene* scene)
{//load scene from binary file format
	FILE* f = fopen(fileName, "rb");
	if (!f)
		return NULL;
	int count;
	Object* ob;
	Node* n = &scene->list->head;

	fread(&count, sizeof(int), 1, f);
	for (int i = 0; i < count; i++)
	{
		ob = loadBinObject(f);
		n = L_insert(n, ob);
	}

	fclose(f);
	return scene;
}

int countObjects(Scene* scene)
{// count the number of objects that in the scene 
	int count = 0;
	Node* n = scene->list->head.next;
	while (n) {
		count++;
		n = n->next;
	}
	return count;
}

void freeScene(Scene* scene)
{// free all memory of the scene

	int count = countObjects(scene);
	Node* n = scene->list->head.next;
	
	for (int i = 0; i < count; i++)
	{
		freeObject(n->value);
		n = n->next;
		
	}
	L_free(scene->list);
	free(scene);
}

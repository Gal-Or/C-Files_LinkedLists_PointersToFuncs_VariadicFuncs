#pragma once

#include "object.h"
#include "linkedList.h"
typedef struct {
	// This structure contains a Single Direction Linked List of all objects in the Scene
	
	List* list;

} Scene;

enum FileType { TextFormat, BinaryFormat };
Scene* createScene(char* fileName, ...);
void perform(Scene* scene, void(*ptrFunction)(Object*, void*), char* type, char* str);
void saveScene(Scene* scene, char* fileName, enum FileType type);
int saveTxtFormat(Scene* scene, char* fileName, int count);
int saveBinFormat(Scene* scene, char* fileName, int count);
Scene* loadScene(char* fileName, enum FileType type);
Scene* loadTxtFormat(char* fileName, Scene* scene);
Scene* loadBinFormat(char* fileName, Scene* scene);
int countObjects(Scene* scene);
void freeScene(Scene* scene);





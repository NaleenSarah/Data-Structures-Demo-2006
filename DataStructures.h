#pragma once

#include "includes.h"
#include "Employee.h"

void LinkedList(Employee List[]);
void B0Tree(Employee List[]);
int InsertB(int Value, Employee List[], int CurrentNode, Employee inZert); //Insert

void AVLTreeE(Employee List[]);
int InsertE(int Value, Employee List[], int CurrentNode, Employee inZert); //Insert

void AVLTreeR(Employee List[]);
int InsertR(int Value, Employee List[], int CurrentNode, Employee inZert); //Insert

void SearchE(int ValueI, Employee List[], int pParent);
void SearchR(char ValueC, int ValueI, Employee List[], int pParent);
//int Insert(Employee Insc, Employee List, int SUME); //Insert

void PreOrderB(Employee List[], int pParent, char Type);
void InOrderB(Employee List[], int pParent, char Type);
void PostOrderB(Employee List[], int pParent, char Type);

int LeftR(Employee List[], int pCurrentNode); //LeftRotation

int RightR(Employee List[], int pCurrentNode); //RightRotation

int Balance(Employee List[], int pParent, int pChild);
int Height(Employee List[], int pParent);
int MaxVal(int Value1, int Value2);
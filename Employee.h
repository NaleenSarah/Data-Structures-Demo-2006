#pragma once
#include "Includes.h"

class Employee
{
private:
	int Left; int Right; 
		
	int NextL, NextLE;
	int Parent;

	int EXT;
	int ENum;
	
	string FName;
	string SName;
	string Room;
	char c_Room;
	int i_Room;
	int ival;

	int HeightL, HeightR, iHeight, iDepth, iBalance;
	double index;
protected:
		
public:
	int EsInRoom[5];
	Employee(void); // Constructor
	Employee(int L, int R, int NL, int NLE, int PA, int ext, int num, string FN, string SN, string RN);
	~Employee(void); // DConstructor

	//Sets
	void setLeft(int);
	void setRight(int);
	void setNextL(int);
	void setNextLE(int);
	void setParent(int PA);
	
	void setEXT(int);
	void setENum(int);

	void setFName(string FN);
	void setSName(string SN);
	void setRoom(string RN);
	void setRoom(char c_RN, int i_RN);
	
	void setiVal(int ArrayVal);
	void setRoomAsI();

	void setHeightL(int in_Height);
	void setHeightR(int in_Height);
	void setHeight(int in_Height);
	void setHeight(void);
	void setDepth(int in_Depth);
	void setiBalance(void);

	//Gets
	int getLeft(void);
	int getRight(void);
	int getNextL(void);
	int getNextLE(void);
	int getParent(void);
	
	int getEXT(void);
	int getENum(void);

	string getFName(void);
	string getSName(void);
	string getRoom(void);
	char getc_Room(void);
	int geti_Room(void);
	

	int getiVal(void);
	int getRoomAsI(void);
	
	int getHeight(void);
	int getDepth(void);
	int getiBalance(void);
	//Other Funcs
	
	bool isFree;


};
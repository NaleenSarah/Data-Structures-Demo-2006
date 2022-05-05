#include "Employee.h"

Employee::Employee(void)
{
	this->Left = -1;
	this->Right = -1;
	
	this->NextL = -1;
	this->NextLE = 0;
	this->Parent = -1;
	this->EXT = 0;
	this->ENum = 0;
	this->FName = "";
	this->SName = "";
	this->Room = "";

	this->HeightL = 0;
	this->HeightR = 0;
	this->iHeight = 0;
	this->iDepth = 0;
	this->iBalance = 0;
	for(int i = 0 ; i < 5 ; i++)
		this->EsInRoom[i] = -1;
	this->isFree = true;
} // Constructor Default
Employee::Employee(int L, int R, int NL, int NLE, int PA , int ext, int num, string FN, string SN, string RN)
{
	this->Left = L;
	this->Right = R;
	this->NextL = NL;
	this->NextLE = NLE;
	this->Parent = PA;
	this->EXT = ext;
	this->ENum = num;
	this->FName = FN;
	this->SName = SN;
	this->Room = RN;

	this->HeightL = 0;
	this->HeightR = 0;
	this->iHeight = 0;
	this->iDepth = 0;
	this->iBalance = 0;
	for(int i = 0 ; i < 5 ; i++)
		this->EsInRoom[i] = -1;
	this->isFree = true;

} // Constructor Predef
Employee::~Employee(void)
{
	//cout << "Class Obliterated\n";
	//system("PAUSE");
} // DConstructor

//Sets Aray
void Employee::setLeft(int L)
{
	this->Left = L;
}
void Employee::setRight(int R)
{
	this->Right = R;
}
void Employee::setNextL(int NL)
{
	this->NextL = NL;
}
void Employee::setNextLE(int NLE)
{
	this->NextLE = NLE;
}
void Employee::setParent(int PA)
{
	this->Parent = PA;
}
//ints
void Employee::setEXT(int ext)
{
	this->EXT = ext;
}
void Employee::setENum(int num)
{
	this->ENum = num;
}
//chars
void Employee::setFName(string FN)
{
	this->FName = FN;
}
void Employee::setSName(string SN)
{
	this->SName = SN;
}
void Employee::setRoom(string RN)
{
	this->Room = RN;
}
void Employee::setRoom(char c_RN, int i_RN)
{
	this->c_Room = c_RN;
	this->i_Room = i_RN;
	setRoomAsI();
}
void Employee::setiVal(int ArrayVal)
{
	this->ival = ArrayVal;
}
void Employee::setRoomAsI()
{
	// convert to Integer
	this->index = ((int)c_Room * 100000) + (i_Room);
}
void Employee::setHeightL(int in_Height)
{
	this->HeightL = in_Height;
}
void Employee::setHeightR(int in_Height)
{
	this->HeightR = in_Height;
}
void Employee::setHeight(int in_Height)
{
	this->iHeight = in_Height;
}
void Employee::setHeight(void)
{
	int Value1 = abs(this->HeightL);
	int Value2 = abs(this->HeightR);
	this->iHeight = Value1 > Value2 ? Value1 : Value2;
	this->setiBalance();
}
void Employee::setDepth(int in_Depth)
{
	this->iDepth = in_Depth;
}
void Employee::setiBalance(void)
{
	this->iBalance = this->HeightL + this->HeightR;
}
//Gets Aray Data
int Employee::getLeft(void)
{
	return this->Left;
}
int Employee::getRight(void)
{
	return this->Right;
}
int Employee::getNextL(void)
{
	return this->NextL;
}
int Employee::getNextLE(void)
{
	return this->NextLE;
}
int Employee::getParent(void)
{
	return this->Parent;
}
// Employee info 1 ints
int Employee::getEXT(void)
{
	return this->EXT;
}
int Employee::getENum(void)
{
	return this->ENum;
}
// Employee info 2 chars
string Employee::getFName(void)
{
	return this->FName;
}
string Employee::getSName(void)
{
	return this->SName;
}
string Employee::getRoom(void)
{
	return this->Room;
}
char Employee::getc_Room(void)
{
	return this->c_Room;
}
int Employee::geti_Room(void)
{
	return this->i_Room;
}

int Employee::getiVal(void)
{
	return this->ival;
}
int Employee::getRoomAsI(void)
{
	return this->index;
}
int Employee::getHeight(void)
{
	return this->iHeight;
}
int Employee::getDepth(void)
{
	return this->iDepth;
}
int Employee::getiBalance(void)
{
	return this->iBalance;
}
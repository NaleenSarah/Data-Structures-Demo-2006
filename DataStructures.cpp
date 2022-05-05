#include "DataStructures.h"
#include "ClearScr.h"


int LoadedZ = 0, FreeZtaff = 0;
int LoadedR = 0, FreeRtaff = 0;
int LoadedB = 0, FreeBtaff = 0;
int XFree = 0;
int pTopNodeR = 0; int pTopNodeE = 0; int pTopNodeB = 0;

void LinkedList(Employee List[])
{
	int LLIst = 0, Loaded = 0;
	int Lt = 0; int Rt = 0; int NL = 0; int NLE = 0 ; int Pa = 0; int ext = 0; int num = 0;
	string FN = ""; string SN = ""; char c_RN = 'c'; int i_RN = -1;

	int temp_E = 0, temp_P = 0;

	while(LLIst < 10)
	{
		
		cout << "Linked List Menu!\n";
		cout << "1 - Load Data\n";
		cout << "2 - Sort by Rooms\n";
		cout << "3 - Display\n";

		cout << "8 - Exit: ";
		cin >> LLIst;
		switch(LLIst)
		{
		case 0:
			break;
		case 1:
		{
			//Load
			clear_screen();

			std::fstream loadFile;
			loadFile.open("Mems.txt",std::ios::in);
			Loaded = 0;

			if(loadFile.is_open())
			{
				while(!loadFile.eof() && Loaded < 49)
				{
					loadFile >> ext;
					loadFile >> FN;
					loadFile >> SN;
					loadFile >> num;			
					loadFile >> c_RN;
					loadFile >> i_RN;
				
					List[Loaded].setEXT(ext);
					List[Loaded].setFName(FN);
					List[Loaded].setSName(SN);
					List[Loaded].setENum(num);
					List[Loaded].setRoom(c_RN, i_RN);


					for (int j = 0 ; j < Loaded ; j++)
						List[j].setNextLE(Loaded+1);

					List[Loaded].setNextL(Loaded+1);
					List[Loaded].setParent(Loaded-1);
				
					Loaded++;
					//system("PAUSE");
				}
				loadFile.close();
			}
			else cout << "Unable to open file";
			cout << Loaded << " Satff Loaded to database" << endl;

			break;
		}
		case 2:
		{
			clear_screen();

			if(Loaded > 0)
			{
				int j = 0, i ;
				bool swap = true;
				while (swap)
				{
					j++;
					swap = false;
					for(i = 0; i < Loaded-j; i++)
					{
						if(List[i].geti_Room() > List[List[i].getNextL()].geti_Room())
						{
							temp_E = List[i].getNextL();
							//Staff[i].setParent(Staff[Staff[i].getNextL()].getParent());
							List[i].setNextL(List[List[i].getNextL()].getNextL());
							List[List[i].getNextL()].setNextL(temp_E);
							swap = true;
						}
					}
				}
			}
			else
				cout << "No sorting done\n";
			system("PAUSE");
			clear_screen();
			break;
		}
		case 3:
		{
			clear_screen();
			if(Loaded > 0)
			{
				for(int j = 0 ; j < Loaded ; j++)
				{
					cout << "ID:\t\t "<< j << endl;
					cout << "Ext:\t\t " << List[j].getEXT() << endl;
					cout << "FN:\t\t " << List[j].getFName() << endl;
					cout << "SN:\t\t " << List[j].getSName() << endl;
					cout << "ENum:\t\t " << List[j].getENum() << endl;
					cout << "Room:\t\t " << List[j].getc_Room() << List[j].geti_Room() << endl;
					cout << "Next Empty Loc:\t\t" << List[j].getNextLE() << endl;
					cout << "Next Linear Node:\t" << List[j].getNextL() << endl;
					cout << "Parent: \t\t" << List[j].getParent() << endl << endl;
				}
			}
			else
				cout << "No Data.\n";

			system("PAUSE");
			clear_screen();
				
			break;
		}
		case 8:
		{
			LLIst = 10;
			//clear array data
			break;
		}
		default:
			break;
		}
		cout << "LinkTest\n";
	}
}


void B0Tree(Employee List[])
{
	int BTM = 0;
	//Employee Staff[NMAXRECORDS];
	Employee Zert;
	Employee FoundList[50];
	
	int Lt = 0; int Rt = 0; int NL = 0; int NLE = 0; int Pa = 0; int ext = 0; int num = 0;
	string FN = ""; string SN = ""; char c_RN = 'c'; int i_RN = -1;
	LoadedB = 0;
	
	while(BTM < 10)
	{
		
		cout << "B Menu!\n";
		cout << "1 - Load Data\n";
		cout << "2 - Display\n";
		cout << "3 - Save\n";
		cout << "4 - Pre\n";
		cout << "5 - In\n";
		cout << "6 - Post\n";
		cout << "8 - Exit: ";
		cin >> BTM;
		switch(BTM-1)
		{
		case 0:
			{
				clear_screen();

				std::fstream loadFile;
				loadFile.open("Mems.txt",std::ios::in);
			
				if(loadFile.is_open())
				{
					while(!loadFile.eof() && LoadedB < NMAXRECORDS-1)
					{
						loadFile >> num;
						loadFile >> FN;
						loadFile >> SN;
						loadFile >> ext;			
						loadFile >> c_RN;
						loadFile >> i_RN;
				
						Zert.setEXT(ext);
						Zert.setFName(FN);
						Zert.setSName(SN);
						Zert.setENum(num);
						Zert.setRoom(c_RN, i_RN);
						Zert.setNextLE(FreeZtaff);
						Zert.setLeft(-1);
						Zert.setRight(-1);
						Zert.setParent(-1);
					
						//cout << Zert.getParent();
						if(LoadedB == 0)
						{
							Zert.setParent(-2);
						}

						InsertB(Zert.getRoomAsI(), List, pTopNodeB, Zert);
						LoadedB++;

					}
					loadFile.close();
				}
				else cout << "Unable to open file";
				cout << LoadedB << " Staff Loaded to database" << endl;
			
				break;
			}
		case 1:
			if(LoadedB > 0)
			{
				cout << "ID\t" << "Room\t" << "Empty\t" << "Left#\t" << "Right#\t" << "Height\t" << "P " << endl;
				for(int j = 0 ; j < LoadedB ; j++)
				{
					cout << j << '\t' <<
					List[j].getc_Room() << List[j].geti_Room() << '\t' <<
					List[j].getNextLE() << '\t' <<
					List[j].getLeft() << '\t' <<
					List[j].getRight() << '\t' <<
					
					List[j].getHeight() << '\t' <<
					List[j].getParent() << endl;
				}
			}
			break;
		case 2:
			{
				std::fstream writeItem;

				writeItem.open("Bine.txt",std::ios::out);
				if(writeItem.is_open())
				{
					writeItem << "Index\t" << "Parent\t" << "Left#\t" << "Right#\t" << "Room#\t" << "Room##" << endl;
						//ListOfItems::iterator iter = itemList.begin();
					for(int i = 0; i < 50; i++) 
					{
				
						/*writeItem << std::endl << std::endl;
						writeItem << "Index : " << List[i].getiVal() << std::endl;
						writeItem << "Parent: " << List[i].getParent() << std::endl;
						writeItem << "Left #: " << List[i].getLeft() << std::endl;
						writeItem << "Right#: " << List[i].getRight() << std::endl;
						writeItem << "Room #: " << List[i].getc_Room() << List[i].geti_Room() << std::endl;
						writeItem << "Room##: " << List[i].getRoomAsI() << std::endl;*/
						writeItem << List[i].getiVal() << '\t' << 
							List[i].getParent() << '\t' << 
							List[i].getLeft() << '\t' <<  
							List[i].getRight() << '\t' <<  
							List[i].getc_Room() << List[i].geti_Room() << '\t' << 
							List[i].getRoomAsI() << endl;

					}writeItem.close();
				}
				else std::cout << "Unable to Save\n";
			

			}
			break;
		case 3: //Traversal PRE
			{
				PreOrderB(List , 0, 'R');
				break;
			}
		case 4: //Traversal IN
			{
				InOrderB(List, 0, 'R');
				break;
			}
		case 5: //Traversal POST
			{
				PostOrderB(List , 0, 'R');
				break;
			}
		case 6: //Traversal POST
			{
//				Search('j',208,List,0, FoundList);
				break;
			}
		case 7:
		{
			BTM = 10;
			//clear array data
			break;
		}

		default:
			break;
		}
		cout << "BTTest\n";
	}
}
int InsertB(int Value, Employee List[], int CurrentNode, Employee inZert)
{
	Employee LeftChild, RightChild , thisParent;
	int pLeft, pRight, NextEmpty, ParentValue, pParent;
	
	pLeft =  List[CurrentNode].getLeft();
	pRight = List[CurrentNode].getRight();
	pParent = List[CurrentNode].getParent();
	NextEmpty = List[CurrentNode].getNextLE();
	ParentValue = List[CurrentNode].getRoomAsI();

	//values
	LeftChild = List[List[CurrentNode].getLeft()];
	RightChild = List[List[CurrentNode].getRight()];

	if(inZert.getParent() == -2)
	{
		FreeBtaff = 1;
		List[0] = inZert;
		List[0].setParent(-1);
		List[0].setiVal(0);
		List[0].setNextLE(FreeBtaff);
		List[0].isFree = false;
		List[0].setLeft(-1);
		List[0].setRight(-1);
		
	}
	else if (Value <= ParentValue)
	{	
		//if(BStaff[PLeft].isFree)
		if(pLeft == -1)
		{
			//insert node left
			List[NextEmpty] = inZert;
			List[NextEmpty].setParent(CurrentNode);
			List[NextEmpty].setiVal(NextEmpty);
			List[NextEmpty].isFree = false;

			//update parent pointers
			List[pParent].setLeft(NextEmpty);

			//next free++
			FreeBtaff++;
			for (int j = 0 ; j < LoadedB+1 ; j++)
				List[j].setNextLE(FreeBtaff);
		}
		else
		{
			// parent = left node
			CurrentNode = List[pLeft].getiVal();
			// insert()
			InsertB(Value, List, CurrentNode, inZert);
		}
	}
	else if (Value > ParentValue)
	{
		//the new node is greater, check whether the right sub-tree is empty or not
		//if(BStaff[PRight].isFree)
		if(pRight == -1)
		{
			//insert node right
			List[NextEmpty] = inZert;
			List[NextEmpty].setParent(CurrentNode);
			List[NextEmpty].setiVal(NextEmpty);
			List[NextEmpty].isFree = false;
			
			//update parent pointers
			List[CurrentNode].setRight(NextEmpty);

			//next free ++
			FreeBtaff++;
			for (int j = 0 ; j < LoadedB+1 ; j++)
				List[j].setNextLE(FreeBtaff);
		}
		else
		{
			// parent = right node
			CurrentNode = List[pRight].getiVal();		
			// insert()
			InsertB(Value, List, CurrentNode, inZert);
		}
	}
	return 1;
}


void PreOrderB(Employee List[], int pParent, char Type)
{
	if(pParent != -1)
	{
		if(Type == 'E')
			cout << "Pointer: " << List[pParent].getiVal() << "\t " << List[pParent].getENum() << endl;
		if(Type == 'R')
			cout << "Pointer: " << List[pParent].getiVal() << "\t " << List[pParent].getc_Room() << List[pParent].geti_Room() << endl;
		PreOrderB(List, List[pParent].getLeft(), Type);
		PreOrderB(List, List[pParent].getRight(), Type );
	}
}
void InOrderB(Employee List[], int pParent, char Type)
{
	if(pParent != -1)
	{
		InOrderB(List, List[pParent].getLeft(), Type );
		if(Type == 'E')
		{
			cout << List[pParent].getc_Room() << List[pParent].geti_Room() << " Name: " << List[pParent].getFName() << " " << List[pParent].getSName() 
				<< "\tENum: " << List[pParent].getENum() << "\t\tPointer: " << List[pParent].getiVal() << endl;
		}
		if(Type == 'R')
		{
			 cout << List[pParent].getc_Room() << List[pParent].geti_Room() << "\n";
			 for(int i = pParent; i != -1;)
			 {
				 cout << "\t" << List[i].getiVal() << " Name: " << List[i].getFName() << " " << List[i].getSName() << endl;
				 i = List[i].getNextL();
			 }
			 cout << endl;
		}
		InOrderB(List, List[pParent].getRight() , Type);
	}
}
void PostOrderB(Employee List[], int pParent, char Type)
{
	if(pParent != -1)
	{
		PostOrderB(List, List[pParent].getLeft() , Type);
		PostOrderB(List, List[pParent].getRight() , Type);
		if(Type == 'E')
			cout << "Pointer: " << List[pParent].getiVal() << "\t " << List[pParent].getENum() << endl;
		if(Type == 'R')
			cout << "Pointer: " << List[pParent].getiVal() << "\t " << List[pParent].getc_Room() << List[pParent].geti_Room() << endl;
		
	}
}


void AVLTreeE(Employee List[])
{
	int AVLT = 0;
	//Employee Staff[NMAXRECORDS];
	Employee Zert;

	int LLIst = 0, Loaded = 0; string Ncapt = "";
	
	int Lt = 0; int Rt = 0; int NL = 0; int NLE = 0; int Pa = 0; int ext = 0; int num = 0;
	string FN = ""; string SN = ""; char c_RN = 'c'; int i_RN = -1;

	while(AVLT < 10)
	{
		
		cout << "AVLe Menu!\n";
		cout << "1 - Load Data\n";
		cout << "2 - Display\n";
		cout << "3 - Pre:\n";
		cout << "4 - In:\n";
		cout << "5 - Post:\n";
		cout << "6 - Save:\n";
		cout << "7 - Search\n";
		cout << "8 - Exit:\n";
		cin >> AVLT;
		switch(AVLT)
		{
		case 0:
			break;
		case 1:
		{
			clear_screen();

			std::fstream loadFile;
			loadFile.open("Mems.txt",std::ios::in);
			
			if(loadFile.is_open())
			{
				while(!loadFile.eof() && Loaded < NMAXRECORDS-1)
				{
					loadFile >> num;
					loadFile >> FN;
					loadFile >> SN;
					loadFile >> ext;			
					loadFile >> c_RN;
					loadFile >> i_RN;
				
					Zert.setEXT(ext);
					Zert.setFName(FN);
					Zert.setSName(SN);
					Zert.setENum(num);
					Zert.setRoom(c_RN, i_RN);
					Zert.setNextLE(FreeZtaff);
					Zert.setLeft(-1);
					Zert.setRight(-1);
					Zert.setParent(-1);
					
					if(LoadedZ == 0)
					{
						Zert.setParent(-2);
					}


					//////////////////////////
					//pTopNode = Insert(Zert.getRoomAsI(), List, pTopNode, Zert);
					pTopNodeE = InsertE(Zert.getENum(), List, pTopNodeE, Zert);
					
					LoadedZ++;

				}
				loadFile.close();
			}
			else cout << "Unable to open file";
			cout << LoadedZ << " Staff Loaded to database" << endl;
			
			break;
		}
		case 2:
		clear_screen();
		if(LoadedZ > 0)
		{
			cout << "ID\t" << "ENum\t" << "Empty\t" << "Left#\t" << "Right#\t" << "Height\t" << "P " << endl;
			for(int j = 0 ; j < LoadedZ ; j++)
			{
				cout << j << '\t' <<
				//List[j].getc_Room() << List[j].geti_Room() << '\t' <<
				List[j].getENum() << '\t' <<
				List[j].getNextLE() << '\t' <<
				List[j].getLeft() << '\t' <<
				List[j].getRight() << '\t' <<
				List[j].getHeight() << '\t' <<
				List[j].getParent() << endl;
			}
		}
		break;
		case 3:
		{
			clear_screen();
			PreOrderB(List , pTopNodeE, 'E');
			
			break;
		}
		case 4:
		{
			clear_screen();
			InOrderB(List , pTopNodeE, 'E');
			system("PAUSE");
			break;
		}
		case 5:
		{
			clear_screen();
			PostOrderB(List , pTopNodeE, 'E');
			break;
		}
		
		case 6:
		{
			clear_screen();
			std::fstream writeItem;

			writeItem.open("AVLe.txt",std::ios::out);
			if(writeItem.is_open())
			{
				writeItem << "Index\t" << "Parent\t" << "Left#\t" << "Right#\t" << "Roll#\t" << "Room#\t" << "Room##\t\t" << "H" << endl;
				for(int i = 0; i < 50; i++) 
				{
					writeItem << List[i].getiVal() << '\t' << 
						List[i].getParent() << '\t' << 
						List[i].getLeft() << '\t' <<  
						List[i].getRight() << '\t' <<  
						List[i].getENum() << '\t' <<  
						List[i].getc_Room() << List[i].geti_Room() << '\t';
					if(List[i].getRoomAsI() < 10000000)
					{
						writeItem <<
						List[i].getRoomAsI() << "\t\t";
					}
					else
					{
						writeItem <<
						List[i].getRoomAsI() << "\t";
					}
					writeItem <<
						List[i].getHeight() << endl;

				}writeItem.close();
			}
			else std::cout << "Unable to Save\n";
		break;

		}
		case 7:
		{
			//Search
			int Beta;
			clear_screen();
			cout << "\nEnter Eployee Number: ";
			cin >> Beta;
			SearchE(Beta, List, pTopNodeE);
			break;
		}
		case 8:
		{
			AVLT = 99;
			//clear array data
			break;
		}
			

		default:
			break;
		}
		cout << "AVLTest\n";
	}
}
int InsertE(int Value, Employee List[], int CurrentNode, Employee inZert)
{
	Employee LeftChild, RightChild , thisParent;
	int pLeft, pRight, NextEmpty, ParentValue, pParent;
	
	pLeft =  List[CurrentNode].getLeft();
	pRight = List[CurrentNode].getRight();
	pParent = List[CurrentNode].getiVal();
	NextEmpty = List[CurrentNode].getNextLE();
	
	//ParentValue = List[CurrentNode].getRoomAsI();
	ParentValue = List[CurrentNode].getENum();

	LeftChild = List[List[CurrentNode].getLeft()];
	RightChild = List[List[CurrentNode].getRight()];

	
	if(inZert.getParent() == -2)
	{
		FreeZtaff = 1;
		List[0] = inZert;
		List[0].setParent(-1);
		List[0].setiVal(0);
		List[0].setNextLE(FreeZtaff);
		List[0].isFree = false;
		List[0].setLeft(-1);
		List[0].setRight(-1);
		List[0].setHeight(0);
		List[0].setDepth(0);
		//cout << "root\n";
	}
	else if (Value < ParentValue)
	{	
		if(pLeft == -1)
		{
			//insert node left
			List[NextEmpty] = inZert;
			List[NextEmpty].setParent(pParent);
			List[NextEmpty].setiVal(NextEmpty);
			List[NextEmpty].isFree = false;
			
			List[NextEmpty].setDepth(List[pParent].getDepth() + 1);
			//update parent pointers
			List[CurrentNode].setLeft(NextEmpty);

			//next free++
			FreeZtaff++;
			for (int j = 0 ; j < LoadedZ+1 ; j++)
				List[j].setNextLE(FreeZtaff);

			pTopNodeE = Balance(List, CurrentNode, NextEmpty);			
		}
		else
		{
			// parent = left node
			CurrentNode = List[pLeft].getiVal();
			// insert()
			pTopNodeE = InsertE(Value, List, CurrentNode , inZert);
		}
	}
	else if (Value > ParentValue)
	{
		if(pRight == -1)
		{
			//insert node right
			List[NextEmpty] = inZert;
			List[NextEmpty].setParent(pParent);
			List[NextEmpty].setiVal(NextEmpty);
			List[NextEmpty].isFree = false;
			List[NextEmpty].setDepth(List[pParent].getDepth() + 1);
			//update parent pointers
			List[CurrentNode].setRight(NextEmpty);

			//next free ++
			FreeZtaff++;
			for (int j = 0 ; j < LoadedZ+1 ; j++)
				List[j].setNextLE(FreeZtaff);

			pTopNodeE = Balance(List, CurrentNode, NextEmpty);
			
		}
		else
		{
			// parent = right node
			CurrentNode = List[pRight].getiVal();	
			// insert()
			pTopNodeE = InsertE(Value, List, CurrentNode, inZert);
		}
	}

	return pTopNodeE;
}

void AVLTreeR(Employee List[])
{
	int AVLT = 0;
	//Employee Staff[NMAXRECORDS];
	Employee Zert;

	int LLIst = 0, Loaded = 0; string Ncapt = "";
	
	int Lt = 0; int Rt = 0; int NL = 0; int NLE = 0; int Pa = 0; int ext = 0; int num = 0;
	string FN = ""; string SN = ""; char c_RN = 'c'; int i_RN = -1;
	int topNode = 0;

	while(AVLT < 90)
	{
		
		cout << "AVLr Menu!\n";
		cout << "1 - Load Data\n";
		cout << "2 - Display\n";
		cout << "3 - Pre:\n";
		cout << "4 - In:\n";
		cout << "5 - Post:\n";
		cout << "6 - Save:\n";
		cout << "7 - Search:\n";
		cout << "8 - Exit:\n";
		cin >> AVLT;
		switch(AVLT)
		{
		case 0:
			break;
		case 1: // Load
		{
			clear_screen();

			std::fstream loadFile;
			loadFile.open("Mems.txt",std::ios::in);
			
			if(loadFile.is_open())
			{
				while(!loadFile.eof() && Loaded < NMAXRECORDS-1)
				{
					loadFile >> num;
					loadFile >> FN;
					loadFile >> SN;
					loadFile >> ext;			
					loadFile >> c_RN;
					loadFile >> i_RN;
				
					Zert.setEXT(ext);
					Zert.setFName(FN);
					Zert.setSName(SN);
					Zert.setENum(num);
					Zert.setRoom(c_RN, i_RN);
					Zert.setNextLE(FreeRtaff);
					Zert.setLeft(-1);
					Zert.setRight(-1);
					Zert.setParent(-1);
					
					if(LoadedR == 0)
					{
						Zert.setParent(-2);
					}


					//////////////////////////
					//pTopNode = Insert(Zert.getRoomAsI(), List, pTopNode, Zert);
					pTopNodeR = InsertR(Zert.getRoomAsI(), List, pTopNodeR, Zert);
					
					LoadedR++;
					//cout << "FileIn";

				}
				loadFile.close();
			}
			else cout << "Unable to open file";
			cout << LoadedR << " Staff Loaded to database" << endl;
			
			break;
		}
		case 2:
		clear_screen();
		if(LoadedR > 0)
		{
			cout << "ID\t" << "Room\t" << "Empty\t" << "Left#\t" << "Right#\t" << "Height\t" << "P " << endl;
			for(int j = 0 ; j < LoadedR ; j++)
			{
				cout << j << '\t' <<
				List[j].getc_Room() << List[j].geti_Room() << '\t' <<
				List[j].getNextLE() << '\t' <<
				List[j].getLeft() << '\t' <<
				List[j].getRight() << '\t' <<
				List[j].getHeight() << '\t' <<
				List[j].getParent() << endl;
			}
		}
		break;
		case 3:
		{
			clear_screen();
			PreOrderB(List , pTopNodeR, 'R');
			break;
		}
		case 4:
		{
			clear_screen();
			InOrderB(List , pTopNodeR, 'R');
			break;
		}
		case 5:
		{
			clear_screen();
			PostOrderB(List , pTopNodeR, 'R');
			break;
		}
		case 6:
		{
			clear_screen();
			std::fstream writeItem;

			writeItem.open("AVLr.txt",std::ios::out);
			if(writeItem.is_open())
			{
				writeItem << "Index\t" << "Parent\t" << "Left#\t" << "Right#\t" << "Roll#\t" << "Room#\t" << "Room##\t\t" << "H" << endl;
				for(int i = 0; i < 50; i++) 
				{
					writeItem << List[i].getiVal() << '\t' << 
						List[i].getParent() << '\t' << 
						List[i].getLeft() << '\t' <<  
						List[i].getRight() << '\t' <<  
						List[i].getENum() << '\t' <<  
						List[i].getc_Room() << List[i].geti_Room() << '\t';
					if(List[i].getRoomAsI() < 10000000)
					{
						writeItem <<
						List[i].getRoomAsI() << "\t\t";
					}
					else
					{
						writeItem <<
						List[i].getRoomAsI() << "\t";
					}
					writeItem <<
						List[i].getHeight() << endl;

				}writeItem.close();
			}
			else std::cout << "Unable to Save\n";
			
			break;
		}
		case 7:
		{
			//Search
			char Alpha;
			int Beta;
			clear_screen();
			cout << "\nEnter room letter: ";
			cin >> Alpha;
			cout << "\nEnter room number: ";
			cin >> Beta;
			SearchR(Alpha, Beta, List, pTopNodeR);
			break;
		}
		case 8:
		{
			AVLT = 90;
			break;
		}

		default:
			break;
		}
		cout << "AVLTest\n";
	}
}
int InsertR(int Value, Employee List[], int CurrentNode, Employee inZert)
{
	Employee LeftChild, RightChild , thisParent;
	int pLeft, pRight, NextEmpty, ParentValue, pParent, newTopNode = 0;
	
	pLeft =  List[CurrentNode].getLeft();
	pRight = List[CurrentNode].getRight();
	pParent = List[CurrentNode].getiVal();
	NextEmpty = List[CurrentNode].getNextLE();
	ParentValue = List[CurrentNode].getRoomAsI();
	LeftChild = List[List[CurrentNode].getLeft()];
	RightChild = List[List[CurrentNode].getRight()];

	if(inZert.getParent() == -2)
	{
		FreeRtaff = 1;
		List[0] = inZert;
		List[0].setParent(-1);
		List[0].setiVal(0);
		List[0].setNextLE(FreeRtaff);
		List[0].isFree = false;
		List[0].setLeft(-1);
		List[0].setRight(-1);
		List[0].setHeight(0);
		List[0].setDepth(0);
		//cout << "root\n";
	}
	else if (Value == ParentValue)
	{
		List[NextEmpty] = inZert;
		List[NextEmpty].setParent(pParent);
		List[NextEmpty].setiVal(NextEmpty);
		List[NextEmpty].isFree = false;
		for(int i = CurrentNode; i != -1;)
		{
			CurrentNode = i;
			i = List[i].getNextL();
		}
		List[CurrentNode].setNextL(NextEmpty);
		//List[NextEmpty].setParent(CurrentNode);

		FreeRtaff++;
		for (int j = 0 ; j < LoadedR+1 ; j++)
			List[j].setNextLE(FreeRtaff);
	}
	else if (Value < ParentValue)
	{	
		if(pLeft == -1)
		{
			//insert node left
			List[NextEmpty] = inZert;
			List[NextEmpty].setParent(pParent);
			List[NextEmpty].setiVal(NextEmpty);
			List[NextEmpty].isFree = false;
			List[NextEmpty].setDepth(List[pParent].getDepth() + 1);
			//update parent pointers
			List[CurrentNode].setLeft(NextEmpty);

			//next free++
			FreeRtaff++;
			for (int j = 0 ; j < LoadedR+1 ; j++)
				List[j].setNextLE(FreeRtaff);
			newTopNode = Balance(List, CurrentNode, NextEmpty);
		}
		else
		{
			// parent = left node
			CurrentNode = List[pLeft].getiVal();
			newTopNode = InsertR(Value, List, CurrentNode , inZert);
		}
	}
	else if (Value > ParentValue)
	{
		if(pRight == -1)
		{
			//insert node right
			List[NextEmpty] = inZert;
			List[NextEmpty].setParent(pParent);
			List[NextEmpty].setiVal(NextEmpty);
			List[NextEmpty].isFree = false;
			List[NextEmpty].setDepth(List[pParent].getDepth() + 1);
			//update parent pointers
			List[CurrentNode].setRight(NextEmpty);
			//next free ++
			FreeRtaff++;
			for (int j = 0 ; j < LoadedR+1 ; j++)
				List[j].setNextLE(FreeRtaff);
			newTopNode = Balance(List, CurrentNode, NextEmpty);
		}
		else
		{
			// parent = right node
			CurrentNode = List[pRight].getiVal();
			newTopNode = InsertR(Value, List, CurrentNode, inZert);
		}
	}
	return newTopNode;
}

void SearchE(int ValueI, Employee List[], int pParent)
{
	Employee LeftChild, RightChild , thisParent;
	int pLeft, pRight, ParentValue, Value = 0;
	
	if(pParent >= 0)
	{
		pLeft =  List[pParent].getLeft();
		pRight = List[pParent].getRight(); 
		pParent = List[pParent].getiVal();

		ParentValue = List[pParent].getENum();
	
		if(ValueI == ParentValue)	
		{
			cout << "P: " << pParent << " " << List[pParent].getFName() << " " << List[pParent].getSName()
				<< " EXT: " << List[pParent].getEXT() << " E#: " << List[pParent].getENum() << " R#: " << List[pParent].getc_Room() << List[pParent].geti_Room() << endl;
			cout << endl;
		}
		else if(ValueI < ParentValue)
		{
			pParent = pLeft;
			SearchE(ValueI, List, pParent);
		}
		else if(ValueI > ParentValue)
		{
			pParent = pRight;
			SearchE(ValueI, List, pParent);
		}
	}
	else
	{
		clear_screen();
		cout << "!!Not Found!!";
		system("PAUSE");
	}

}
void SearchR(char ValueC, int ValueI, Employee List[], int pParent)
{
	Employee LeftChild, RightChild , thisParent;
	int pLeft, pRight, ParentValue, pNextL, Value = 0;

	Value = ((int)ValueC * 100000) + (ValueI);
	
	if(pParent >= 0)
	{
		pLeft =  List[pParent].getLeft();
		pRight = List[pParent].getRight(); 
		pParent = List[pParent].getiVal();
		pNextL =  List[pParent].getNextL();

		ParentValue = List[pParent].getRoomAsI();
	
		if(Value == ParentValue)	
		{
			cout << "P: " << pParent << " " << List[pParent].getFName() << " " << List[pParent].getSName()
				<< " EXT: " << List[pParent].getEXT() << " E#: " << List[pParent].getENum();
			pNextL = List[pParent].getNextL();
			while(pNextL != -1)
			{
				cout << "\nP: " << pNextL << " " << List[pNextL].getFName() << " " << List[pNextL].getSName()
				<< " EXT: " << List[pNextL].getEXT() << " E#: " << List[pNextL].getENum() << " R#: " << List[pParent].getc_Room() << List[pParent].geti_Room();
				pNextL = List[pNextL].getNextL();
			}
			cout << endl;
		}
		else if(Value < ParentValue)
		{
			pParent = pLeft;
			SearchR(ValueC, ValueI, List, pParent);
		}
		else if(Value > ParentValue)
		{
			pParent = pRight;
			SearchR(ValueC, ValueI, List, pParent);
		}
	}
	else
	{
		clear_screen();
		cout << "!!Not Found!!";
		system("PAUSE");
	}
	

	/*int FoundV = 0;
	while(Value != ParentValue && FoundV == false)
	{
		if(Value < ParentValue)
			pParent = List[pLeft].getiVal();

		if(Value > ParentValue)
			pParent = List[pRight].getiVal();

	}*/

}

int LeftR(Employee List[], int pCurrentNode)//LeftRotation
{
	
	/*
	1 current
		3 child
			4 cchild

		3
	1		4
	*/
	
	int pParent = List[pCurrentNode].getParent();
	int NodeMoveUP = -1;

	/*
				1	NodeLeft						pParent
		0				3 <---- NodeMoveUP			Current
					2		4 NodeRight // 0		pParent.Right // pChild
								5					pcChild
				to
				3 <----
		1				4
	0		2				5

	*/
	int Zero, One, Two, Three, Four, Five;
	
	One = pCurrentNode;
	pParent = List[One].getParent();
	Three = List[pCurrentNode].getRight();
	Zero = List[pCurrentNode].getLeft();
	Two = List[Three].getLeft();
	Four = List[Three].getRight();
	Five = List[Four].getRight();
		
	//if dog leg
		if( List[Three].getLeft() != -1   &&   List[Three].getRight() != -1)
		{
			List[One].setRight(Two);
			List[One].setParent(Three);
			List[Two].setParent(One);
			List[Three].setLeft(One);
			List[Three].setParent(pParent);

			List[One].setHeightR(1);
			List[One].setHeight();

			List[Three].setHeightL( -1 -List[One].getHeight() );
			List[Three].setHeight();

			if(pParent >= 0)
			{
				if(List[pParent].getRight() == One)
					List[pParent].setRight(Three);
				else if(List[pParent].getLeft() == One)
					List[pParent].setLeft(Three);
			}

			NodeMoveUP = Three;

		}
		else
		{
			
			List[Three].setLeft(One);
			List[Three].setParent(pParent);
			List[One].setParent(Three);
			List[One].setRight( 1 );//+List[Two].getHeight());
			List[One].setHeightR(0);
			List[One].setHeight();
			List[Three].setHeightL( -1 -List[One].getHeight() );
			List[Three].setHeight();


			if(pParent >= 0)
			{
				if(List[pParent].getRight() == One)
					List[pParent].setRight(Three);
				else if(List[pParent].getLeft() == One)
					List[pParent].setLeft(Three);
			}

			NodeMoveUP = Three;

			//normal
		}

	return NodeMoveUP;
}
int RightR(Employee List[], int pCurrentNode)//RightRotation
{
	int pParent = List[pCurrentNode].getParent();
	int NodeMoveUP = -1;
	/*
				4	
		2				5 
	1		3				
0				
				to
				2		 <----
		1				4
	0				3		5
*/

	int Zero, One, Two, Three, Four, Five;
	
	Four = pCurrentNode;					//  1
	pParent = List[Four].getParent();		
	Five = List[pCurrentNode].getRight();	//  3
	Two = List[pCurrentNode].getLeft();		//  0
	Three = List[Two].getRight();			//  2
	One = List[Two].getLeft();				//  4
	Zero = List[One].getLeft();				//  5

	// Double
		if( List[Two].getRight() != -1   &&   List[Two].getLeft() != -1)
		{
			List[Four].setLeft(Three);
			List[Four].setParent(Two);
			List[Three].setParent(Four);

			List[Two].setRight(Four);
			List[Two].setParent(pParent);

			List[Four].setHeightL(-1 );//-List[Three].getHeight());
			List[Four].setHeight();

			List[Two].setHeightR( 1 +List[Four].getHeight() );
			List[Two].setHeight();

			if(pParent >= 0)
			{
				if(List[pParent].getLeft() == Four)
					List[pParent].setLeft(Two);
				else if(List[pParent].getRight() == Four)
					List[pParent].setRight(Two);
			}

			NodeMoveUP = Two;

		}
		else //Single
		{
			
			List[Two].setRight(Four);
			List[Two].setParent(pParent);
			List[Four].setParent(Two);
			List[Four].setLeft(-1);
			List[Four].setHeightL(0);
			List[Four].setHeight();
			List[Two].setHeightR( +1 +List[Four].getHeight() );
			List[Two].setHeight();


			if(pParent >= 0)
			{
				if(List[pParent].getLeft() == Four)
					List[pParent].setLeft(Two);
				else if(List[pParent].getRight() == Four)
					List[pParent].setRight(Two);
			}

			NodeMoveUP = Two;

			//normal
		}

	return NodeMoveUP;
}
/*
IF tree is right heavy
{
  IF tree's right subtree is left heavy
  {
     Perform Double Left rotation 
  }
  ELSE
  {
     Perform Single Left rotation
  }
}
ELSE IF tree is left heavy
{
  IF tree's left subtree is right heavy
  {
     Perform Double Right rotation
  }
  ELSE
  {
     Perform Single Right rotation
  }
}

*/

int Balance(Employee List[], int pParent, int pChild)
{
	int newCurrent = 0;
	
	while(pParent >= 0)
	{
		int CurrentNode = pParent;
		newCurrent = CurrentNode;
		//newCurrent = pParent;
		int tempH = 0;
		
		if( pChild == List[CurrentNode].getLeft() )
		{
			List[CurrentNode].setHeightL( -1 - List[pChild].getHeight() );
		}
		if( pChild == List[CurrentNode].getRight() )
		{
			List[CurrentNode].setHeightR( +1 + List[pChild].getHeight() );
		}
		List[CurrentNode].setHeight();
		
		int Balance = List[CurrentNode].getiBalance();

		if(Balance == 2)
		{
			newCurrent = LeftR(List, CurrentNode);
		}
		else if(Balance == -2)
		{
			newCurrent = RightR(List, CurrentNode);
		}
		
		pChild = newCurrent;
		pParent = List[pChild].getParent();
	}

	return newCurrent;
}

int Height(Employee List[], int pParent)
{
	if(List[pParent].getParent() < 0)
		return 0;
	else
		return List[pParent].getHeight();
}
int MaxVal(int Value1, int Value2)
{
	return Value1 > Value2 ? Value1 : Value2;
}
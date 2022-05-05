#include "includes.h"
#include "Employee.h"
#include "DataStructures.h"
#include "ClearScr.h"

Employee Staff[NMAXRECORDS];
Employee Ztaff[NMAXRECORDS];
Employee Rtaff[NMAXRECORDS];
Employee BStaff[NMAXRECORDS];

void main()
{
	int Exit = 0, DStype = 0;

	LPCSTR CName = ( LPCSTR )"Data Structs Demo" ;
	SetConsoleTitleA( CName );
	while( DStype < 5)
	{
		//clear_screen();
		cout << "Choose Data Structure Type!\n";
		cout << "1 - Linked List\n";
		cout << "2 - Binary Tree\n";
		cout << "3 - AVLe\n";
		cout << "4 - AVLr\n";
		cout << "5 - Exit: ";
		cin >> DStype;
		switch(DStype-1)
		{
		case 0:
		{
			clear_screen();
			LinkedList(Staff);
				
			break;
		} 
		case 1:
		{
			clear_screen();
			B0Tree(BStaff);

			break;
		}
		case 2:
		{
			clear_screen();
			AVLTreeE(Ztaff);
				
			break;
		}
		case 3:
		{
			clear_screen();
			AVLTreeR(Rtaff);
				
			break;
		}
		case 4:
		{
			DStype = 10;
			clear_screen();
			break;
		}
		default:
			break;
		}

	}
}



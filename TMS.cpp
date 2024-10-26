#include <iostream>
using namespace std;

void Q1()
{
	// hihihi
}

void Q2()
{

}

void Q3()
{

}

void Q4() 
{

}

void Q5()
{

}

int main()
{
	char prog_choice;

	do {
		cout << "\n\n";
		cout << "Welcome Message designed by your group" << endl;
		cout << "---------------------------------------" << endl;
		cout << "*** Main Menu ***" << endl;
		cout << "[1] Load Starting Data" << endl;
		cout << "[2] Show User Records" << endl;
		cout << "[3] Edit Users" << endl;
		cout << "[4] Enter User View" << endl;
		cout << "[5] Show System Usage Summary" << endl;
		cout << "[6] Credits and Exit" << endl;
		cout << "*****************" << endl;
		cout << "Option (1 - 6): ";
		cin >> prog_choice;
		cout << "\n\n";

		switch (prog_choice) {
		case '1': Q1(); break;
		case '2': Q2(); break;
		case '3': Q3(); break;
		case '4': Q4(); break;
		case '5': Q5(); break;
		case '6': break;
		default:
			cout << "No such Option " << prog_choice << endl;
			break;
		}
	} while (prog_choice != '6');

	cout << "Program terminates. Good bye!" << endl;
	return 0;
}
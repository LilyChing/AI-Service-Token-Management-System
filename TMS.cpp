#include <iostream>
#include <iomanip>
using namespace std;


class User
{
public:
	User();

	bool checkBoolFromUser();

private:

};

class Transaction
{
public:
	Transaction();


private:

};
void Q1()
{
	// Lily Lily Lily
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

bool checkBoolFromUser(const char input) {

	if (input == 'Y' || input == 'y') {
		return true;
	}

	else if (input == 'N' || input == 'n') {
		return false;
	}

	else {
		cout << "Wrong input. Only Y/N is accepted. Please retry." << endl;
		cin.clear();
		cin.ignore(1000000, '\n');
	}
}


void Q6() //Credits and Exit
{
	char userInput;

	cout << "Show the credit? (Y / N)" << endl;
	cin >> userInput;

		bool result = checkBoolFromUser(userInput);
		if (result) { 
			cout << setw(12) <<"Credit" << endl;
			cout << "CHING Yan Lee" << setw(5) << "24050083S 102" << endl;
			cout << "LEE Cheuk Him" << setw(5) << "24076812S 102" << endl;
			cout << "FUNG Ho Ming" << setw(6) << "24059970S 102" << endl;
			cout << "AU-YEUNG Wing Lam" << setw(1) << "24063299S 102" << endl;
			cout << "LAM Wai Ha" << setw(8) <<"24049348S 102" << endl;
			cout << "WONG Sze Wun"<<setw(6) <<"24059631S 102" << endl;
		}

		else {
			return;
		}
}


int main()
{
	char prog_choice;

	do {
		cout << "\n\n";
		cout << "~ Welcome To AI Service Token Management System ~" << endl;
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
		case '6': Q6(); break;
		case '7': break;
		default:
			cout << "No such Option " << prog_choice << endl;
			break;
		}
	} while (prog_choice != '6');

	cout << "Program terminates. Good bye!" << endl;
	return 0;
}

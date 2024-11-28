#include <iostream>
#include <iomanip>
using namespace std;


class User
{
public:
	User(char uid, int u_type, int u_tokenBalance, int u_autoTopUp) {
		userID = uid;
		type = u_type; // 0 refers to Trial , 1 refers to Full, 2 refers to Student
		tokenBalance = u_tokenBalance;
		autoTopup = u_autoTopUp; // autoTopUp 0 refers to No, 1 refers to include auto top up
		isDeleted = 0; //isDeleted  0 refers to exists, 1 refers to deleted
		money = 100;
	}

	//Getter & Setter
	char[] getUserID() { // How to return char array
		return userID;
	}

	int getType() {
		return type;
	}

	int getTokenBalance() {
		return tokenBalance;

	}

	int getAutoTopup() {
		return autoTopup;
	}

	int getIsDeleted() {
		return isDeleted;
	}

	int getMoney() {
		return money;
	}

	void credit(int amount) {
		money += amount;
	}

	void debit(int amount) {
		money -= amount;
	}

	void setType(int accType) {
		type = accType;
	}

	void setAutoTopup(int topup) {
		autoTopup = topup;
	}

	void deleteUser() {
		isDeleted = 1;
	}

	void purchaseToken(int token) {
		if (money > token * 2) {
			//add Token
			tokenBalanace += token;
			// money -= token * 2;
			debit(token * 2);
		}
		else {
			cout << "insufficient cash. Please come back after top up." << endl;
		}
	}






private:
	char userID[50];
	int type;
	int tokenBalance;
	int autoTopup;
	int isDeleted;
	int money; // cash balance
	bool endProgram;
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
	char action;

	do{
	cout << "\n\n";
	cout << "Action for User ID : " << endl; // user name variable is tbc
	cout << "*****User View Menu*****" << endl;
	cout << "[1] Select AI Service" << endl;
	cout << "[2] Purchase Tokens" << endl;
	cout << "[3] Edit Profile" << endl;
	cout << "[4] Show Transaction History" << endl;
	cout << "[5] Return to Main Menu" << endl;
	cout << "**************************" << endl;
	cout << "Option(1 - 5) :";
	cin >> action;
	cout << "\n\n";

	
	switch (action) { //function name for ACTION need to revise
	case '1': Q1(); break;
	case '2': Q2(); break;
	case '3': Q3(); break;
	case '4': Q4(); break;
	case '5':endProgram = true;
		break;
		default:
		cout << "No such Option " << action << "\n\n";
		break;
	}
	}while (action != '5' || !endProgram);
	return;
}

void Q5()
{

}

bool endProgram = false;

void Q6() //Credits and Exit
{
	char userInput;

	while (true) {
		cout << "Show the credit? (Y / N) ";
		cin >> userInput;

		if (userInput == 'y' || userInput == 'Y') {
			cout << endl<< setw(24) << "~ Credit ~" << endl;
			cout << left << setw(18) << "Name:" << "\tStudent ID:\tClass:" << endl << endl;
			cout << left << setw(18) << "CHING Yan Lee" << "\t24050083S\t102" << endl;
			cout << left << setw(18) << "LEE Cheuk Him" << "\t24076812S\t102" << endl;
			cout << left << setw(18) << "FUNG Ho Ming" << "\t24059970S\t102" << endl;
			cout << left << setw(18) << "AU-YEUNG Wing Lam" << "\t24063299S\t102" << endl;
			cout << left << setw(18) << "LAM Wai Ha" << "\t24049348S\t102" << endl;
			cout << left << setw(18) << "WONG Sze Wun" << "\t24059631S\t102" << endl << endl;
		}

		else if (userInput == 'n' || userInput == 'N') {
			return;
		}

		else {
			cout << endl << "Wrong input. Only Y/N is accepted. Please retry." << "\n\n";
			cin.clear();
			cin.ignore(1000000, '\n');
		}
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
			if (!endProgram) {
			continue;
			}
		case '7': break;
		default:
			cout << "No such Option " << prog_choice << endl;
			break;
		}
	} while (prog_choice != '6'|| !endProgram);

	cout << "System terminates. Good bye!" << endl;
	return 0;
}

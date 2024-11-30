#include <iostream>
#include <string>
#include <sstream>
using namespace std;



void predictiveAnalysis() {

	// call UserID - token balance - acct type - autoTopup
	int tokenbal = 20; // to be changed, eg user.tokenbal or use for loop to check in transaction
	char acctType = 'T'; // to be changed , eg user.acctType or use for loop to check in user profile
	bool withoutAutoTopup = true; // same as above


	int price = 10;
	int task = 0;
	int autoToptoken = 0; // no. of token under auto Top-up

	cout << "Thank you for using the Predictive Analysis!\n";
	cout << "Price : 10 tokens per prediction task\n";

	for (int i = 0; i < 3; i++) { // 3 chances to input

		cout << "Please enter the number of prediction task:";
		cin >> task;

		// check any invalid input: (1) check input type; (2) out of range; (3)not enough token but Auto Topup; (4) no enough token and no auto Top-up

		// (1) need to check if any non-integer input after 1st integer input, to find any function to checked if char after integer input
		if (cin.fail()) {
			cout << "Invalid input." << endl;
			cin.clear(); // Clear the error state
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the line
			continue;
		}


		// checking (2)
		if (task <= 0)
		{
			cout << "Invalid input. Please input again.";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}

		// checking (3) & (4)

		if (tokenbal < task * 10) {

			if (withoutAutoTopup) {
				cout << "Insuffient token." << endl;
				cout << "Remaining token: " << tokenbal << endl;
				cout << "Please try again after purchasing for more tokens.";
				break; // & return to User view menu
			}
			else {

				((task * 10 - tokenbal) % 10) == 0 ? autoToptoken = (task * 10 - tokenbal)/10 : autoToptoken = (task * 10 - tokenbal) / 10 + 10;

				cout << "Insuffient token. $" << autoToptoken * 2 << "have been charged for auto top-up " << autoToptoken << " tokens." << endl;
				cout << "Remaining: " << tokenbal + autoToptoken - task * 10 << " token(s)." << endl;
				// transfer info to transaction acct
				break;
			}
		}
		else {

			cout << task * 10 << " tokens have been deducted. Remaining: " << tokenbal - task * 10 << "tokens" << endl;
			// transfer into to transaction acct
			break; // & return to user view menu
		}
	}
}

	int main(){

	predictiveAnalysis();


	return 0;
}
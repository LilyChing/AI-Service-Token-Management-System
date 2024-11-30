#include <iostream>
#include <string>
#include <sstream>
using namespace std;



void nlp() {

	// call UserID - token balance - acct type - autoTopup
	int tokenbal = 20; // to be changed, eg user.tokenbal or use for loop to check in transaction
	char acctType = 'T'; // to be changed , eg user.acctType or use for loop to check in user profile
	bool withoutAutoTopup = true; // same as above


	int numberText = 0;
	int autoToptoken = 0; // no. of token under auto Top-up

	cout << "Thank you for using the Natural Language Processing!\n";
	cout << "Price : 1 token for every 500 characters \n";

	for (int i = 0; i < 3; i++) { // 3 chances to input

		cout << "Please enter the length of text (Max. 2500 characters for trial account):";
		cin >> numberText;

		// check any invalid input: (1) check input type; (2) out of range; (2a) Trial account and over 2500 char; (3)not enough token but Auto Topup; (4) no enough token and no auto Top-up

		// (1) need to check if any non-integer input after 1st integer input, to find any function to checked if char after integer input
		if (cin.fail()) {
			cout << "Invalid input." << endl;
			cin.clear(); // Clear the error state
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the line
			continue;
		}


		// checking (2)
		if (numberText <= 0)
		{
			cout << "Invalid input." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}


		// checking (2a)
		if (numberText > 2500 && acctType == 'T')
		{
			cout << "Invalid input. Max. 2500 for trial account." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}




		// checking (3) & (4)

		int totalcost = 0;
		
		numberText % 500 == 0 ? (totalcost = numberText / 500) : (totalcost = numberText / 500 + 1);

		if (tokenbal < totalcost) {

			if (withoutAutoTopup) {
				cout << "Insuffient token." << endl;
				cout << "Remaining token: " << tokenbal << endl;
				cout << "Please try again after purchasing for more tokens." << endl;
				break; // & return to User view menu
			}
			else {

				((totalcost - tokenbal) % 10) == 0 ? autoToptoken = (totalcost - tokenbal)/10 : autoToptoken = (totalcost - tokenbal) / 10 + 10;

				cout << "Insuffient token. $" << autoToptoken * 2 << "have been charged for auto top-up " << autoToptoken << " tokens." << endl;
				cout << "Remaining: " << tokenbal + autoToptoken - totalcost << " token(s)." << endl;
				// transfer info to transaction acct
				break;
			}
		}
		else {

			cout << totalcost << " tokens have been deducted. Remaining: " << tokenbal - totalcost << " tokens." << endl;
			// transfer into to transaction acct
			break; // & return to user view menu
		}
	}

	// return to user view menu
}

	int main(){

	nlp();


	return 0;
}
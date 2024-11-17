#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// check if the input is valid (pure integer)
bool isPureInteger(string input, int& output) {
	stringstream ss(input);

	if (ss >> output) {
		// Check for any remaining characters
		return ss.eof(); // Return true if the entire input was consumed
	}
	return false; // Not a valid integer
}







// select AI Service 3
void aiService3(int& tokenBal, char autoTopup) {

	// to be confirmed>>> the availability of Auto Top-up service ... outside or inside this function...?

	string num;
	int numChecked = 0;

	cout << "Thanks for choosing the Predictive Analysis!\n";
	// the following green cout to be considered as introduction of service
	//cout << "This is an incerdible AI service forecasting future event by using historical data, algorithms and machine learning!\n";
	cout << "Price : 10 tokens per prediction task\n";
	cout << "Please input the number of prediction task required (integer only) : ";
	cin >> num;

	int change = 0; // change of balance

	if (isPureInteger(num, numChecked)) {

		if (tokenBal < 10 * numChecked) {
			if (autoTopup == 'Y') {

				int extraToken = (10 * numChecked - tokenBal);
				int autoUpAmt = 0;

				(extraToken % 10 == 0) ? autoUpAmt = 2 * extraToken : autoUpAmt = 2 * (extraToken + (10 - extraToken % 10));


				cout << endl << "Not enough tokens for purchasing the service. $" << autoUpAmt << " has been charged for injecting " << autoUpAmt / 2 << " tokens in your account." << endl << endl;
				cout << "Your subscription to the predictive analysis service has been successfully activated. You can now access valuable insights and forecasts that will help inform your decision-making processes." << endl << endl;
				change = 10 * numChecked - autoUpAmt / 2;
				tokenBal = tokenBal % 10;

			}
			else
				cout << endl << "The balance of token in your account is not enough for the service. Please top up the amount of token or enable the auto-up service for this incerdible service." << endl << endl;
		}

		if (tokenBal >= 10 * numChecked)
		{
			change = -(10 * numChecked);
			tokenBal = tokenBal + change;
			cout << endl << "Your subscription to the predictive analysis service has been successfully activated. You can now access valuable insights and forecasts that will help inform your decision-making processes." << endl << endl;
		}
	}
	else
		cout << "The input is invalid.";

	cout << "The change of the balance of token(s) in your account is " << change << "." << endl << "The current balance of token(s) in your balance is " << tokenBal << "." << endl;

	// Call the User View Menu
}





















int main() {
	// all rows in main() is for testing only, to be deleted 
	int bal;
	cout << "enter any int as balance of token: ";
	cin >> bal;
	cout << "enter Y or N if the auto Top up is enabled: ";
	char autoTopup;
	cin >> autoTopup;
	cout << "enter Y or N if trial acct or not: ";
	char trialAcct;
	cin >> trialAcct;

	cout << endl;

	aiService3(bal, autoTopup);

	cout << endl;



	cin.get();

	return 0;
}
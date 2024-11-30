#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


class User
{
public:
	User() {
		userID = "";
		isDeleted = 0; //isDeleted  0 refers to exists, 1 refers to deleted
		endProgram = false;
	}
	User(string uid, int u_type, int u_tokenBalance, int u_autoTopUp) {
		userID = uid;
		type = u_type; // 0 refers to Trial , 1 refers to Full, 2 refers to Student
		tokenBalance = u_tokenBalance;
		autoTopup = u_autoTopUp; // autoTopUp 0 refers to No, 1 refers to include auto top up
		isDeleted = 0; //isDeleted  0 refers to exists, 1 refers to deleted
		money = 100;
		endProgram = false;
	}

	//Getter & Setter
	string getUserID() { // How to return char array
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
			tokenBalance += token;
			// money -= token * 2;
			debit(token * 2);
		}
		else {
			cout << "insufficient cash. Please come back after top up." << endl;
		}
	}






private:
	string userID;
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
	//Transaction();


private:



};

bool endProgram = false;
vector<User> userList;

void initializeUser()
{
	const string userID[] = { "SkyWalker", "Ocean123", "Forest99", "Valley777", "Desert2022", "River456", "Blaze2023", "Meadow888", "Galaxy", "Storn2024" };
	const int type[] = { 0, 0, 0, 1, 1, 1, 1, 2, 2, 2 };
	const int tokenBalance[]{ 20, 35, 6, 10, 25, 20, 100, 40, 15, 30 };
	const int autoTopup[]{ 0, 0, 1, 1, 0, 1, 0, 1, 1, 0 };

	for (int i = 0; i < 10; i++) {
		userList.push_back(User(userID[i], type[i], tokenBalance[i], autoTopup[i]));
	}
}

const int rows = 100;
const int cols = 4;

string userInfo[rows][cols] = {
       /*{"SkyWalker","T","20","N"},
{ "Ocean123","T","35","N" },
{ "Forest99","T","6","Y" },
{ "Valley777","F","10","Y" },
{ "Desert2022","F","25","N" },
{ "River456","F","20","Y" },
{ "Blaze2023","F","100","N" },
{ "Meadow888","S","40","Y" },
{ "Galaxy","S","15","Y" },
{ "Storm2024","S","30","N" }*/

};

void bubbleSort2D(string arr[rows][cols], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j][0] > arr[j + 1][0]) {
                // Swap rows arr[j] and arr[j + 1]
                for (int k = 0; k < cols; ++k) {
                    string temp = arr[j][k];
                    arr[j][k] = arr[j + 1][k];
                    arr[j + 1][k] = temp;
                }
            }
        }
    }
}

void displayData(const string arr[rows][cols], int n) {
    cout << "\nShow User Records:" << endl;
    cout << left << setw(50)<<"User ID"<< left << setw(10)<<"Type" << left << setw(15) << "Token Balance"<< left << setw(10) << "Auto Top - up" << endl;
    for (int i = 0; i < n; ++i) {
        if (arr[i][0] != "") { // Only print non-empty rows
            for (int j = 0; j < 1; ++j) {
                cout << left << setw(50)<< arr[i][0] << left << setw(10) << arr[i][1] << left << setw(15) << arr[i][2] << left << setw(10) << arr[i][3];
            }
            cout << endl;
        }
    }
}

void Q3()
{
    vector<string> userList = {"1", "2", "3"};
    string targetID;

    cout << "Enter the ID to search for: ";
    cin >> targetID;

    // Use std::find to search for targetID in userList
    auto it = find(userList.begin(), userList.end(), targetID);

    // Check if the ID was found
    if (it != userList.end()) {
        cout << "I find it and gonna delete it." << endl;
        // Optionally, you can remove the ID from the list
        userList.erase(it); // Remove the found ID
    } else {
        cout << "I can't find??" << endl;
    }
}

void imageRecognition()
{
	// The 2D array refers to the charges according to different scenario
	// [0] refers to Under 3MB
	// [1] refers to Over 3MB
	int charges[2][3] = { {5, 5, 4}, {-1, 8, 7} };
	double imgSize = 0.0;

	// 假設用家資料
	int userType = 0;  // 0 refers to trial, 1 refers to Full Account, 2 refers to Student Account
	int autoTopUp = 1; // 0 refers to false 1 refers to true
	int testUserToken = 0;
	// Code to implement
	cout << "Thank you for using Image Recognition!" << endl;
	cout << "Please enter the expected Image Size you would like to recognize: ";
	cin >> imgSize;
	if (imgSize <= 0)
	{
		cout << "\nInvalid Input: Please enter a positive number." << endl;
		return;
	}
	int serviceType = imgSize <= 3.0 ? 0 : 1;
	int payment = charges[serviceType][userType];
	// Check account Type
	if (serviceType == 1 && userType == 0)
	{
		cout << "\nYou have no access for using Image Recognition for more than 3MB. \nPlease contact the administrator for upgrading your account." << endl;
		return;
	}
	if (autoTopUp == 0)
	{
		if (testUserToken < payment)
		{
			cout << "\nInsufficient Token." << endl;
			cout << "Remaining token: " << testUserToken << endl;
			cout << "Please try again after purchasing for more tokens." << endl;
			return;
		}
	}
	if (testUserToken < payment)
	{
		int diff = payment - testUserToken;
		int topUp = diff % 20 == 0 ? diff / 20 : diff / 20 + 1; // topUp refers to times of top up 20 token
		// autoTopUp
		// code to implement
	}
	testUserToken -= payment;
	cout << "\nImage has been recognized successfully." << endl;
	cout << "Thank you for using AI Service - Image Recognition" << endl;
	cout << "Remaining Token: " << testUserToken << endl
		<< endl;
	cout << "Enter \'q\' to return to user interface: ";
	char operation;
	cin >> operation;
	return;
}

void speechToText()
{
	// The 2D array refers to the charges according to different scenario
	// [0] refers to fee for first 3 minutes
	// [1] refers to fee for after 3 minutes
	int charges[2] = { 2, 3 };
	int audioLength;

	// 假設用家資料
	int userType = 0;  // 0 refers to trial, 1 refers to Full Account, 2 refers to Student Account
	int autoTopUp = 1; // 0 refers to false 1 refers to true
	int testUserToken = 0;
	// Code to implement
	cout << "Thank you for using Sppech to Text Transcription!" << endl;
	cout << "Please enter the audio length of your speech: ";
	cin >> audioLength;
	if (audioLength <= 0)
	{
		cout << "\nInvalid Input: Please enter a positive integer." << endl;
		return;
	}
	int payment;
	if (audioLength <= 3)
	{
		payment = audioLength * charges[0];
	}
	else
	{
		payment = 3 * charges[0] + (audioLength - 3) * charges[1];
	}

	if (autoTopUp == 0)
	{
		if (testUserToken < payment)
		{
			cout << "\nInsufficient Token." << endl;
			cout << "Remaining token: " << testUserToken << endl;
			cout << "Please try again after purchasing for more tokens." << endl;
			return;
		}
	}
	if (testUserToken < payment)
	{
		int diff = payment - testUserToken;
		int topUp = diff % 20 == 0 ? diff / 20 : diff / 20 + 1; // topUp refers to times of top up 20 token
		// autoTopUp
		// code to implement
	}
	testUserToken -= payment;
	cout << "\nText has been generated successfully." << endl;
	cout << "Thank you for using AI Service - Speech to Text Transcription!" << endl;
	cout << "Remaining Token: " << testUserToken << endl
		<< endl;
	cout << "Enter \'q\' to return to user interface: ";
	char operation;
	cin >> operation;
	return;
}

void aiServiceMenu()
{
	char action;

	do {
		cout << "\n\n";
		cout << "Select AI Service : " << endl; // user name variable is tbc
		cout << "*****AI Service Menu*****" << endl;
		cout << "[1] Image Recognition" << endl;
		cout << "[2] Speech-to-text transcription" << endl;
		cout << "[3] Predictive Analysis" << endl;
		cout << "[4] Natural Language Processing (NLP)" << endl;
		cout << "[5] Return to User View Menu" << endl;
		cout << "**************************" << endl;
		cout << "Option(1 - 5) :";
		cin >> action;
		cout << "\n\n";


		switch (action) { //function name for ACTION need to revise
		case '1': imageRecognition(); break;
		case '2': speechToText(); break;
		case '3': Q3(); break;
		//case '4': Q4(); break;
		case '5':endProgram = true;
			break;
		default:
			cout << "No such Option " << action << "\n\n";
			break;
		}
	} while (action != '5' || !endProgram);
	return;
}

void Q5()
{

}


void credits() //Credits and Exit
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
		case '1': initializeUser(); break;
		case '2': bubbleSort2D(); 
			  displayData();
			  break;
		case '3': Q3(); break;
		//case '4': Q4(); break;
		case '5': Q5(); break;
		case '6': credits(); break;
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

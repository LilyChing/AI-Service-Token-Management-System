#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
// #include <algorithm>
using namespace std;

class Transaction
{
public:
	Transaction(int currentToken) {
		originalToken = currentToken;
		TokenchangeAmount = 0;
		moneySpent = 0;
		TokenUsage = "default";
	}

	Transaction(int currentToken, int Tokenchange, int money, string usage) {
		originalToken = currentToken;
		TokenchangeAmount = Tokenchange;
		moneySpent = money;
		TokenUsage = usage;
	}

private:
	int originalToken;
	int TokenchangeAmount;
	int moneySpent;
	string TokenUsage;
};

class User
{
public:
	User(string uid, int u_type, int u_tokenBalance, int u_autoTopUp)
	{
		userID = uid;
		type = u_type; // 0 refers to Trial , 1 refers to Full, 2 refers to Student
		tokenBalance = u_tokenBalance;
		autoTopup = u_autoTopUp; // autoTopUp 0 refers to No, 1 refers to include auto top up
		isDeleted = 0;					 // isDeleted  0 refers to exists, 1 refers to deleted
		money = 100;
		transactionHistory.push_back(Transaction(u_tokenBalance));
		endProgram = false;
	}

	// Getter & Setter
	string getUserID()
	{ // How to return char array
		return userID;
	}

	int getType()
	{
		return type;
	}

	int getTokenBalance()
	{
		return tokenBalance;
	}

	int getAutoTopup()
	{
		return autoTopup;
	}

	int getIsDeleted()
	{
		return isDeleted;
	}

	int getMoney()
	{
		return money;
	}

	void credit(int amount)
	{
		money += amount;
	}

	void debit(int amount)
	{
		money -= amount;
	}

	void setType(int accType)
	{
		type = accType;
	}

	void setAutoTopup(int topup)
	{
		autoTopup = topup;
	}

	void deleteUser()
	{
		isDeleted = 1;
	}

	void purchaseToken(int token)
	{
		if (money > token * 2)
		{
			setTransactionHistory(tokenBalance, token, token * 2, "Purchase Tokens");
			// add Token
			tokenBalance += token;
			// money -= token * 2;
			debit(token * 2);
		}
		else
		{
			cout << "insufficient cash. Please come back after top up." << endl;
		}
	}

	void displayDeleteInfo() {
    cout << "User ID: " << getUserID() << "\n"
        << "User Type: " << getType() << "\n"
        << "Token Balance: " << getTokenBalance() << "\n"
        << "Auto Top-up: " << (getAutoTopup() ? "Yes" : "No") << "\n";
	}

	void setTransactionHistory(int currentToken, int Tokenchange, int money, string usage) {
		transactionHistory.push_back(Transaction(currentToken, Tokenchange, money, usage));
	}

	vector<Transaction> getTransactionHistory() {
		return transactionHistory;
	}

private:
	string userID;
	int type;
	int tokenBalance;
	int autoTopup;
	int isDeleted;
	int money; // cash balance
	int totalMoneyPaidForTokens;
	vector<Transaction> transactionHistory;
	bool endProgram;
};

bool isValidUserType(int userType) {
	return userType >= 0 && userType <= 2; // Assuming valid types are 0, 1, or 2
}
bool isValidTokenBalance(int balance) {
	return balance >= 0; // Assuming token balance cannot be negative
}
bool isValidAutoTopup(int topup) {
	return topup == 0 || topup == 1; // Assuming valid top-up values are 0 or 1
}

bool endProgram = false;
vector<User> userList;

void displayData(vector<User> array)
{
	cout << "\nShow User Records:" << endl;
	cout << left << setw(50) << "User ID " << setw(10) << "Type" << setw(15) << "Token Balance" << setw(10) << "Auto Top-up" << endl;
	for (int i = 0; i < array.size(); i++)
	{
		cout << left << setw(50) << array[i].getUserID() << setw(10) << array[i].getType() << setw(15) << array[i].getTokenBalance() << setw(10) << array[i].getAutoTopup() << endl;
	}
}

void initializeUser()
{
	const string userID[] = {"SkyWalker", "Ocean123", "Forest99", "Valley777", "Desert2022", "River456", "Blaze2023", "Meadow888", "Galaxy", "Storn2024"};
	const int type[] = {0, 0, 0, 1, 1, 1, 1, 2, 2, 2};
	const int tokenBalance[]{20, 35, 6, 10, 25, 20, 100, 40, 15, 30};
	const int autoTopup[]{0, 0, 1, 1, 0, 1, 0, 1, 1, 0};

	for (int i = 0; i < 10; i++)
	{
		userList.push_back(User(userID[i], type[i], tokenBalance[i], autoTopup[i]));
	}
	displayData(userList);
}

void swap(string &a, string &b)
{
	string temp = a;
	a = b;
	b = temp;
}

void showUserRecords()
{
	if (userList.empty())
	{
		cout << "You have not yet load starting data! Returning to menu...";
		return;
	}

	for (size_t i = 0; i < userList.size(); ++i)
	{
		for (size_t j = 0; j < userList.size() - 1; ++j)
		{
			if (userList[j].getUserID() > userList[j + 1].getUserID())
			{
				swap(userList[j], userList[j + 1]);
			}
		}
	}
	displayData(userList);
}

void editUser(){
	if (userList.empty()){
		cout << "You have not yet load starting data! Returning to menu...";
		return;
	}
    string targetID;

    cout << "Enter the ID to search for: ";
    cin >> targetID;

    bool found = false;

    // Iterate through the userList to find the targetID
for (int i = 0; i < userList.size(); i++) {
        if (userList[i].getUserID() == targetID) {
            found = true;
            cout << "User found:\n";
            userList[i].displayDeleteInfo(); // Display user information

            // Confirm deletion
            string confirmation;
            cout << "Do you really want to delete this user? (yes/no): ";
            cin >> confirmation;

            if (confirmation == "yes" || confirmation == "Yes" || confirmation == "Y"|| confirmation == "y") {
                userList.erase(userList.begin() + i); // Remove the found user
                cout << "User deleted successfully." << endl;
            } else if(confirmation == "no" || confirmation == "No" || confirmation == "N"|| confirmation == "n"){
                cout << "Deletion cancelled." << endl;
            } else{
				cout << "Please input again." << endl;
			}
            return; // Exit the function after handling deletion
        }
    }

    if (!found) {
        // Prompt for new user details with retry mechanism
        int newType, newBalance, newTopup;
        int attempts = 0;

        while (attempts < 3) {
            cout << "User not found. Please enter details for this user." << endl;

            cout << "Enter user type (0, 1, 2): ";
            cin >> newType;
            if (!isValidUserType(newType)) {
                cout << "Invalid user type. Please enter a value between 0 and 2." << endl;
                attempts++;
                continue; // Retry without incrementing attempts further
            }

            cout << "Enter token balance: ";
            cin >> newBalance;
            if (!isValidTokenBalance(newBalance)) {
                cout << "Invalid token balance. It cannot be negative." << endl;
                attempts++;
                continue; // Retry without incrementing attempts further
            }

            cout << "Enter auto top-up (0 or 1): ";
            cin >> newTopup;
            if (!isValidAutoTopup(newTopup)) {
                cout << "Invalid auto top-up value. Please enter 0 or 1." << endl;
                attempts++;
                continue; // Retry without incrementing attempts further
            }

            // If all inputs are valid, create a new User and add to userList
            userList.push_back(User(targetID, newType, newBalance, newTopup));
            cout << "New user created with ID: " << targetID << endl;
            return; // Exit after successful creation
        }

        // If reached here, it means 3 attempts failed
        cout << "Too many invalid attempts. No user added." << endl;
	}
}

void imageRecognition(User user)
{
	// The 2D array refers to the charges according to different scenario
	// [0] refers to Under 3MB
	// [1] refers to Over 3MB
	int charges[2][3] = {{5, 5, 4}, {-1, 8, 7}};
	double imgSize = 0.0;

	// 假設用家資料
	int userType = user.getType();			 // 0 refers to trial, 1 refers to Full Account, 2 refers to Student Account
	int autoTopUp = user.getAutoTopup(); // 0 refers to false 1 refers to true
	int userToken = user.getTokenBalance();
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
		if (userToken < payment)
		{
			cout << "\nInsufficient Token." << endl;
			cout << "Remaining token: " << userToken << endl;
			cout << "Please try again after purchasing for more tokens." << endl;
			return;
		}
	}
	if (userToken < payment)
	{
		int diff = payment - userToken;
		int topUp = diff % 20 == 0 ? diff / 20 : diff / 20 + 1; // topUp refers to times of top up 20 token
																														// autoTopUp
																														// code to implement
	}
	userToken -= payment;
	cout << "\nImage has been recognized successfully." << endl;
	cout << "Thank you for using AI Service - Image Recognition" << endl;
	cout << "Remaining Token: " << userToken << endl
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
	int charges[2] = {2, 3};
	int audioLength;

	// 假設用家資料
	int userType = 0;	 // 0 refers to trial, 1 refers to Full Account, 2 refers to Student Account
	int autoTopUp = 1; // 0 refers to false 1 refers to true
	int userToken = 0;
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
		if (userToken < payment)
		{
			cout << "\nInsufficient Token." << endl;
			cout << "Remaining token: " << userToken << endl;
			cout << "Please try again after purchasing for more tokens." << endl;
			return;
		}
	}
	if (userToken < payment)
	{
		int diff = payment - userToken;
		int topUp = diff % 20 == 0 ? diff / 20 : diff / 20 + 1; // topUp refers to times of top up 20 token
																														// autoTopUp
																														// code to implement
	}
	userToken -= payment;
	cout << "\nText has been generated successfully." << endl;
	cout << "Thank you for using AI Service - Speech to Text Transcription!" << endl;
	cout << "Remaining Token: " << userToken << endl
			 << endl;
	cout << "Enter \'q\' to return to user interface: ";
	char operation;
	cin >> operation;
	return;
}

void aiServiceMenu()
{
	char action;

	do
	{
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

		switch (action)
		{ // function name for ACTION need to revise
		case '1':
			//imageRecognition();
			break;
		case '2':
			speechToText();
			break;
		// case '3':
		//	aiServiceMenu();
		//	break;
		// case '4': Q4(); break;
		case '5':
			endProgram = true;
			break;
		default:
			cout << "No such Option " << action << "\n\n";
			break;
		}
	} while (action != '5' || !endProgram);
	return;
}

void Q2(){}
void Q3(){}

string findUserID(const string& userID) {
    // Iterate through the userList to find the targetID
    for (int i = 0; i < userList.size(); i++) {
        if (userList[i].getUserID() == userID) {
            cout << "User found: " << userID << endl;
            return userID;
        }
    }
    cout << "User not found: " << userID << endl;
    return "false";
}

void Q4()
{
	char action;
	string targetID;
	if (userList.empty())
	{
		cout << "You have not yet load starting data! Returning to menu...";
		return;
	}

	cout << "Enter the your User ID: ";
    cin >> targetID;

	do{
    string userCheck = findUserID(targetID);
    if (userCheck == "false") {
        cout << "User not found! Exiting to menu..." << endl;
        endProgram = true;
        return;
    } else {
		cout << "\n\n";
        cout << "Action for User ID:" << userCheck << endl;
    }

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

	
	switch (action) {
	case '1': aiServiceMenu(); break;
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

void credits() // Credits and Exit
{
	char userInput;

	while (true)
	{
		cout << "Show the credit? (Y / N) ";
		cin >> userInput;

		if (userInput == 'y' || userInput == 'Y')
		{
			cout << endl
					 << setw(24) << "~ Credit ~" << endl;
			cout << left << setw(18) << "Name:" << "\tStudent ID:\tClass:" << endl
					 << endl;
			cout << left << setw(18) << "CHING Yan Lee" << "\t24050083S\t102" << endl;
			cout << left << setw(18) << "LEE Cheuk Him" << "\t24076812S\t102" << endl;
			cout << left << setw(18) << "FUNG Ho Ming" << "\t24059970S\t102" << endl;
			cout << left << setw(18) << "AU-YEUNG Wing Lam" << "\t24063299S\t102" << endl;
			cout << left << setw(18) << "LAM Wai Ha" << "\t24049348S\t102" << endl;
			cout << left << setw(18) << "WONG Sze Wun" << "\t24059631S\t102" << endl
					 << endl;
		}

		else if (userInput == 'n' || userInput == 'N')
		{
			return;
		}

		else
		{
			cout << endl
					 << "Wrong input. Only Y/N is accepted. Please retry." << "\n\n";
			cin.clear();
			cin.ignore(1000000, '\n');
		}
	}
}

int main()
{
	char prog_choice;

	do
	{
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

		switch (prog_choice)
		{
		case '1':
			initializeUser();
			break;
		case '2':
			showUserRecords();
			break;
		case '3':
			editUser();
			break;
		case '4': Q4(); break;
		case '5':
			Q5();
			break;
		case '6':
			credits();
			break;
			if (!endProgram)
			{
				continue;
			}
		case '7':
			break;
		default:
			cout << "No such Option " << prog_choice << endl;
			break;
		}
	} while (prog_choice != '6' || !endProgram);

	cout << "System terminates. Good bye!" << endl;
	return 0;
}

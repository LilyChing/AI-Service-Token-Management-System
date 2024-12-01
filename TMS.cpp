#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>
#include <limits>

using namespace std;

/* -------------------- Class --------------------*/
class Transaction
{
public:
	Transaction()
	{
		TokenchangeAmount = 0;
		moneySpent = 0;
		TokenUsage = -1;
	}

	Transaction(int tokenchange, int usage)
	{

		TokenchangeAmount = tokenchange;
		moneySpent = tokenchange * 2;
		TokenUsage = usage;
	}

	int getTokenchange()
	{
		return TokenchangeAmount;
	}

	int getMoneySpent()
	{
		return moneySpent;
	}

	int getTokenUsage()
	{
		return TokenUsage;
	}

private:
	int TokenchangeAmount;
	int moneySpent;
	int TokenUsage; // 0:Purchase Tokens; 1: Image Recognition; 2: Speech-to-text transcription; 3: Predictive Analysis; 4: Natural Language Processing(NLP); 5: Auto top-up
};

class User
{
public:
	User(string uid, int u_type, int u_tokenBalance, int u_autoTopUp)
	{
		userID = uid;
		type = u_type; // 0 refers to Trial , 1 refers to Full, 2 refers to Student
		tokenBalance = u_tokenBalance;
		originalToken = u_tokenBalance;
		autoTopup = u_autoTopUp; // autoTopUp 0 refers to No, 1 refers to include auto top up
		isDeleted = 0;					 // isDeleted  0 refers to exists, 1 refers to deleted
		money = 100;
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

	void setType(string userID, int accType)
	{
		userID = userID;
		type = accType;
	}

	void setAutoTopup(string userID, int topup)
	{
		userID = userID;
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
			setTransactionHistory(token, 0);
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

	void useToken(int token)
	{
		if (tokenBalance < token)
		{
			cout << "Insufficient token!!";
		}
		else
		{
			tokenBalance -= token;
		}
	}

	void displayDeleteInfo()
	{
		cout << "User ID: " << getUserID() << "\n"
				 << "User Type: " << getType() << "\n"
				 << "Token Balance: " << getTokenBalance() << "\n"
				 << "Auto Top-up: " << (getAutoTopup() ? "Yes" : "No") << "\n";
	}

	void setTransactionHistory(int tokenchange, int usage)
	{
		transactionHistory.push_back(Transaction(tokenchange, usage));
	}

	vector<Transaction> getTransactionHistory()
	{
		return transactionHistory;
	}

private:
	string userID;
	int type;
	int tokenBalance;
	int autoTopup;
	int isDeleted;
	int money; // cash balance
	int originalToken;
	int totalMoneyPaidForTokens;
	vector<Transaction> transactionHistory;
	bool endProgram;
};

/* -------------------- Class --------------------*/
bool endProgram = false;
vector<User> userList;
/* -------------------- Checking Function --------------------*/

bool isValidUserType(int userType)
{
	return userType >= 0 && userType <= 2; // Assuming valid types are 0, 1, or 2
}

bool isValidTokenBalance(int balance)
{
	return balance >= 0; // Assuming token balance cannot be negative
}

bool isValidAutoTopup(int topup)
{
	return topup == 0 || topup == 1; // Assuming valid top-up values are 0 or 1
}

void swap(string &a, string &b)
{
	string temp = a;
	a = b;
	b = temp;
}

void displayData(vector<User> array)
{
	cout << "\nShow User Records:" << endl;
	cout << left << setw(50) << "User ID " << setw(10) << "Type" << setw(15) << "Token Balance" << setw(10) << "Auto Top-up" << endl;
	for (int i = 0; i < array.size(); i++)
	{
		cout << left << setw(50) << array[i].getUserID() << setw(10) << array[i].getType() << setw(15) << array[i].getTokenBalance() << setw(10) << array[i].getAutoTopup() << endl;
	}
}

string findUserID(const string &userID)
{
	// Iterate through the userList to find the targetID
	for (int i = 0; i < userList.size(); i++)
	{
		if (userList[i].getUserID() == userID)
		{
			return userID;
		}
	}
	cout << "User not found: " << userID << endl;
	return "false";
}

int findUserIndex(string userID)
{
	// Iterate through the userList to find the targetID
	for (int i = 0; i < userList.size(); i++)
	{
		if (userList[i].getUserID() == userID)
		{
			return i;
		}
	}
	cout << "User not found: " << userID << endl;
	return 0;
}
/* -------------------- Checking Function --------------------*/

/* -------------------- Main Function --------------------*/

// [1]
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

// [2]
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

// [3]
void editUser()
{
	if (userList.empty())
	{
		cout << "You have not yet load starting data! Returning to menu...";
		return;
	}
	string targetID;

	cout << "Enter the ID to search for: ";
	cin >> targetID;

	bool found = false;

	// Iterate through the userList to find the targetID
	for (int i = 0; i < userList.size(); i++)
	{
		if (userList[i].getUserID() == targetID)
		{
			found = true;
			cout << "User found:\n";
			userList[i].displayDeleteInfo(); // Display user information

			// Confirm deletion
			string confirmation;
			cout << "Do you really want to delete this user? (yes/no): ";
			cin >> confirmation;

			if (confirmation == "yes" || confirmation == "Yes" || confirmation == "Y" || confirmation == "y")
			{
				userList.erase(userList.begin() + i); // Remove the found user
				cout << "User deleted successfully." << endl;
			}
			else if (confirmation == "no" || confirmation == "No" || confirmation == "N" || confirmation == "n")
			{
				cout << "Deletion cancelled." << endl;
			}
			else
			{
				cout << "Please input again." << endl;
			}
			return; // Exit the function after handling deletion
		}
	}

	if (!found)
	{
		// Prompt for new user details with retry mechanism
		int newType, newBalance, newTopup;
		int attempts = 0;

		while (attempts < 3)
		{
			cout << "User not found. Please enter details for this user." << endl;

			cout << "Enter user type (0, 1, 2): ";
			cin >> newType;
			if (!isValidUserType(newType))
			{
				cout << "Invalid user type. Please enter a value between 0 and 2." << endl;
				attempts++;
				continue; // Retry without incrementing attempts further
			}

			cout << "Enter token balance: ";
			cin >> newBalance;
			if (!isValidTokenBalance(newBalance))
			{
				cout << "Invalid token balance. It cannot be negative." << endl;
				attempts++;
				continue; // Retry without incrementing attempts further
			}

			cout << "Enter auto top-up (0 or 1): ";
			cin >> newTopup;
			if (!isValidAutoTopup(newTopup))
			{
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

// [4.1.1]
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
		int topUp = diff % 10 == 0 ? diff : diff / 10 * 10 + 10; // topUp refers to times of top up 10 token
		user.purchaseToken(topUp);
		user.setTransactionHistory(topUp, 5); // autoTopUp
																					// code to implement
	}
	user.useToken(payment);
	cout << "\nImage has been recognized successfully." << endl;
	cout << "Thank you for using AI Service - Image Recognition" << endl;
	cout << "Remaining Token: " << userToken << endl;

	user.setTransactionHistory(payment, 1);

	cout << "Enter \'q\' to return to user interface: ";
	char operation;
	cin >> operation;
	return;
}

// [4.1.2]
void speechToText(User user)
{
	// The 2D array refers to the charges according to different scenario
	// [0] refers to fee for first 3 minutes
	// [1] refers to fee for after 3 minutes
	int charges[2] = {2, 3};
	int audioLength;

	// 假設用家資料
	int userType = user.getType();			 // 0 refers to trial, 1 refers to Full Account, 2 refers to Student Account
	int autoTopUp = user.getAutoTopup(); // 0 refers to false 1 refers to true
	int userToken = user.getTokenBalance();
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
		int topUp = diff % 10 == 0 ? diff : diff / 10 * 10 + 10; // topUp refers to times of top up 20 token
		user.purchaseToken(topUp);
		user.setTransactionHistory(topUp, 5); // autoTopUp
																					// code to implement
	}
	user.useToken(payment);
	user.setTransactionHistory(payment, 2);

	cout << "\nText has been generated successfully." << endl;
	cout << "Thank you for using AI Service - Speech to Text Transcription!" << endl;
	cout << "Remaining Token: " << userToken << endl;
	cout << "Enter \'q\' to return to user interface: ";
	char operation;
	cin >> operation;
	return;
}

// [4.1.3]
void predictiveAnalysis(User user)
{

	// call User information
	int userType = user.getType();			 // 0 refers to trial, 1 refers to Full Account, 2 refers to Student Account
	int autoTopUp = user.getAutoTopup(); // 0 refers to false 1 refers to true
	int userToken = user.getTokenBalance();

	int price = 10;
	int task = 0;

	cout << "Thank you for using the Predictive Analysis!\n";
	cout << "Price : 10 tokens per prediction task\n";
	cout << "Please enter the number of prediction task:";
	cin >> task;

	// check any invalid input: (1) check input type; (2) out of range; (3)not enough token but Auto Topup; (4) no enough token and no auto Top-up

	// (1) need to check if any non-integer input after 1st integer input, to find any function to checked if char after integer input
	if (cin.fail())
	{
		cout << "Invalid input." << endl;
		cin.clear();																				 // Clear the error state
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the line
		return;
	}

	// checking (2)
	if (task <= 0)
	{
		cout << "Invalid input. Please input again.";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return;
	}

	// checking (3) & (4)

	if (userToken < task * 10)
	{

		if (autoTopUp == 0)
		{
			cout << "Insuffient token." << endl;
			cout << "Remaining token: " << userToken << endl;
			cout << "Please try again after purchasing for more tokens.";
			return;
		}
		else
		{

			int extraToken = (10 * task - userToken);
			int autoUpAmt = 0;

			(extraToken % 10 == 0) ? autoUpAmt = extraToken : autoUpAmt = extraToken + (10 - extraToken % 10);
			user.setTransactionHistory(autoUpAmt, 5);

			cout << "Insuffient token. $" << autoUpAmt * 2 << "have been charged for auto top-up " << autoUpAmt << " tokens." << endl;
			cout << "Remaining: " << userToken + autoUpAmt - task * 10 << " token(s)." << endl;
			// transfer info to transaction acct
			user.setTransactionHistory(autoUpAmt, 5);
			user.setTransactionHistory(10 * task, 3);
			return;
		}
	}
	else
	{

		cout << "Your subscription to the predictive analysis service has been successfully activated." << endl;
		cout << "Thank you for using AI Service - Predictive Analysis!" << endl;
		cout << task * 10 << " tokens have been deducted." << endl;
		cout << "Remaining: " << userToken - task * 10 << "tokens" << endl;

		// transfer info to transaction acct
		user.setTransactionHistory(10 * task, 3);

		cout << "Press any button to return to the User View Menu.";
		cin.get();
		return; // & return to user view menu
	}
}

// [4.1.4]
void nlp(User user)
{

	int userType = user.getType();			 // 0 refers to trial, 1 refers to Full Account, 2 refers to Student Account
	int autoTopUp = user.getAutoTopup(); // 0 refers to false 1 refers to true
	int userToken = user.getTokenBalance();

	int numberText = 0;
	int autoToptoken = 0; // no. of token under auto Top-up

	cout << "Thank you for using the Natural Language Processing!\n";
	cout << "Price : 1 token for every 500 characters \n";
	cout << "Please enter the length of text (Max. 2500 characters for trial account):";
	cin >> numberText;

	// check any invalid input: (1) check input type; (2) out of range; (2a) Trial account and over 2500 char; (3)not enough token but Auto Topup; (4) no enough token and no auto Top-up

	// (1) need to check if any non-integer input after 1st integer input, to find any function to checked if char after integer input
	if (cin.fail())
	{
		cout << "Invalid input." << endl;
		cin.clear();																				 // Clear the error state
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the line
		return;
	}

	// checking (2)
	if (numberText <= 0)
	{
		cout << "Invalid input." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return;
	}

	// checking (2a)
	if (numberText > 2500 && userType == 0)
	{
		cout << "Invalid input. Max. 2500 for trial account." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return;
	}

	// checking (3) & (4)

	int totalcost = 0;

	numberText % 500 == 0 ? (totalcost = numberText / 500) : (totalcost = numberText / 500 + 1);

	if (userToken < totalcost)
	{

		if (autoTopUp == 0)
		{
			cout << "Insuffient token." << endl;
			cout << "Remaining token: " << userToken << endl;
			cout << "Please try again after purchasing for more tokens." << endl;
			return; // & return to User view menu
		}
		else
		{
			((totalcost - userToken) % 10) == 0 ? autoToptoken = (totalcost - userToken) / 10 : autoToptoken = (totalcost - userToken) / 10 + 10;
			cout << "Insuffient token. $" << autoToptoken * 2 << "have been charged for auto top-up " << autoToptoken << " tokens." << endl;
			cout << "Remaining: " << userToken + autoToptoken - totalcost << " token(s)." << endl;

			user.setTransactionHistory(autoToptoken, 5);
			user.setTransactionHistory(totalcost, 4);

			return;
		}
	}
	else
	{

		cout << totalcost << " tokens have been deducted. Remaining: " << userToken - totalcost << " tokens." << endl;
		user.setTransactionHistory(totalcost, 4);
		return;
	}
}

// [4.1] AI Menu
void aiServiceMenu(int userIndex)
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
			imageRecognition(userList[userIndex]);
			break;
		case '2':
			speechToText(userList[userIndex]);
			break;
		case '3':
			predictiveAnalysis(userList[userIndex]);
			break;
		case '4':
			nlp(userList[userIndex]);
			break;
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

// [4.2]
void Q2() {}

// [4.3]
void editProfile(string actionUser)
{
	for (int i = 0; i < userList.size(); i++)
	{
		if (userList[i].getUserID() == actionUser)
		{
			int newType, newBalance, newTopup;
			int attempts = 0;
			while (attempts < 3)
			{
				cout << "Change Your Setting" << endl;
				cout << "Enter your type - 0(Trial), 1(Full), 2(Student): ";
				cin >> newType;

				if (!isValidUserType(newType))
				{
					cout << "Invalid user type. Please enter a value between 0 and 2." << endl;
					attempts++;
					continue; // Retry without incrementing attempts further
				}
				userList[i].setType(actionUser, newType);

				cout << "Enter auto top-up - 0(Inactive) or 1(Active): ";
				cin >> newTopup;
				if (!isValidAutoTopup(newTopup))
				{
					cout << "Invalid auto top-up value. Please enter 0 or 1." << endl;
					attempts++;
					continue; // Retry without incrementing attempts further
				}
				userList[i].setAutoTopup(actionUser, newTopup);
				cout << "Your data have been updated.";
				return;
			}
		}
	}
}

//[4.4]
void Q4() {}

// [4] User Menu
void enterUserView()
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

	do
	{
		string actionUser = findUserID(targetID); // actionUser -> UserID
		int userIndex = findUserIndex(targetID);	// userIndex -> Index

		if (actionUser == "false")
		{
			cout << "User not found! Exiting to menu..." << endl;
			endProgram = true;
			return;
		}
		else
		{
			cout << "\n\n";
			cout << "Action for User ID:" << actionUser << endl;
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

		switch (action)
		{
		case '1':
			aiServiceMenu(userIndex);
			break;
		case '2':
			Q2();
			break;
		case '3':
			editProfile(actionUser);
			break;
		case '4':
			Q4();
			break;
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

// [5]
void showSystemUsageSummary()
{
	if (userList.empty())
	{
		cout << "You have not yet load starting data! Returning to menu...";
		return;
	}

	int freq[6] = {0, 0, 0, 0, 0, 0};
	for (int i = 0; i < userList.size(); i++)
	{
		vector<Transaction> tran = userList[i].getTransactionHistory();
		for (int j = 0; j < tran.size(); j++)
		{
			for (int freqIndex = 0; freqIndex < sizeof(freq); freqIndex++)
			{
				if (tran[j].getTokenUsage() == freqIndex)
				{
					freq[freqIndex] += tran[j].getTokenchange();
				}
			}
		}
	}

	int totalTokensSpentOnAllAI = 0;
	// Show the number of tokens spent on each of the AI service by all users

	for (int freqIndex = 1; freqIndex <= 4; freqIndex++) {
		switch (freqIndex) {
		case 1:
			cout << left << setw(80) << "The total tokens spent on Image Recognition: ";
			break;
		case 2:
			cout << left << setw(80) << "The total tokens spent on Speech-to-text transcription: ";
			break;
		case 3:
			cout << left << setw(80) << "The total tokens spent on Predictive Analysis: ";
			break;
		case 4:
			cout << left << setw(80) << "The total tokens spent on Natural Language Processing: ";
			break;
		default:
			break;
		}
		cout << setw(20) << freq[freqIndex] << endl;
		totalTokensSpentOnAllAI += freq[freqIndex];
	}

	//the total number of tokens spent on all AI services by all users
	cout << left << setw(80) << "The total tokens spent on all AI services:" << setw(20) << totalTokensSpentOnAllAI << endl;

	//the total amount of money paid for buying tokens (including auto top-up)
	cout << left << setw(80) << "The total money paid for buying tokens:" << setw(20) << (freq[0] + freq[5]) * 2 << endl;
}

// [6]
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

/* -------------------- Main Function --------------------*/

/* -------------------- Main Menu --------------------*/
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
		case '4':
			enterUserView();
			break;
		case '5':
			showSystemUsageSummary();
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

/* -------------------- Main Menu --------------------*/

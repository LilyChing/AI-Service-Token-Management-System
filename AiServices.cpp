#include <iostream>
#include <iomanip>
using namespace std;

void imageRecognition()
{
  // The 2D array refers to the charges according to different scenario
  // [0] refers to Under 3MB
  // [1] refers to Over 3MB
  int charges[2][3] = {{5, 5, 4}, {-1, 8, 7}};
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
  int charges[2] = {2, 3};
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

void predictiveAnalysis()
{
  int charges = 10; // token per prediction task
  int tasks = 0;

  // 假設用家資料
  int userType = 0;  // 0 refers to trial, 1 refers to Full Account, 2 refers to Student Account
  int autoTopUp = 1; // 0 refers to false 1 refers to true
  int testUserToken = 0;
  // Code to implement
  cout << "Thank you for using Predictive Analysis!" << endl;
  cout << "Please enter the Number of prediction tasks: ";
  cin >> tasks;
  if (tasks <= 0)
  {
    cout << "\nInvalid Input: Please enter a positive integer." << endl;
    return;
  }
  int payment = tasks * charges;

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
  cout << "\nPredicitive Analysis has been generated successfully." << endl;
  cout << fixed << setw(12) << left << "Task ID" << "Predictive Analysis" << endl;
  for (int i = 1; i <= tasks; i++)
  {
    cout << "Task " << setw(7) << left << i << "True" << endl;
  }
  cout << "Thank you for using AI Service - Predictive Analysis!" << endl;
  cout << "Remaining Token: " << testUserToken << endl
       << endl;
  cout << "Enter \'q\' to return to user interface: ";
  char operation;
  cin >> operation;
  return;
}

void NLP()
{
  int w_count = 0;

  // 假設用家資料
  int userType = 0;  // 0 refers to trial, 1 refers to Full Account, 2 refers to Student Account
  int autoTopUp = 1; // 0 refers to false 1 refers to true
  int testUserToken = 0;
  // Code to implement
  cout << "Thank you for using Predictive Analysis!" << endl;
  cout << "Please enter the word count: ";
  cin >> w_count;
  if (w_count <= 0)
  {
    cout << "\nInvalid Input: Please enter a positive integer." << endl;
    return;
  }

  if (userType == 0 && w_count > 2500)
  {
    cout << "\nYou have no access for using Natural Language Processing for more than 2500 words. \nPlease contact the administrator for upgrading your account." << endl;
    return;
  }

  int payment = w_count % 500 == 0 ? w_count / 500 : w_count / 500 + 1;

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
  cout << "\nNatural Language Processing has been generated successfully." << endl;
  cout << "Thank you for using AI Service - Natural Language Processing!" << endl;
  cout << "Remaining Token: " << testUserToken << endl
       << endl;
  cout << "Enter \'q\' to return to user interface: ";
  char operation;
  cin >> operation;
  return;
}

int main()
{
  imageRecognition();
  speechToText();
  predictiveAnalysis();
  NLP();
  return 0;
}
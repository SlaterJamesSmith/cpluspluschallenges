/***************************************************/
/* Slater Smith                                    */
/*                                                 */
/* This is a simple program that will calculate    */
/* membership cost and discount for a fictional    */
/* fitness club.                                   */
/*                                                 */
/* Written for practice using Void functions       */
/* Sources: None. This is solely my work.          */
/***************************************************/

#include<iostream>
#include<iomanip>
using namespace std;

// program custom functions below
char mainMenu(); // for showing menu options and collecting input
void information(); // for for showing information to user
void getInfo(bool &senior, int &months, int &personal); // user input collection
double calcCost(bool senior, int months, int personal); // cost calculation
// program function end

int main()
{
  bool senior; // storage for age used in discount calculation
  int months, personal; // storage for subscription length and training sessions
  double cost; // storage for final cost calculation
  char menu; // storage for output of mainMenu function

  cout << endl;
  cout << "This program calculates your cost for joining a ";
  cout << "fitness club, including applicable discounts." << endl << endl;

  menu = mainMenu();

  while (menu == 'a' || menu == 'A')
  {
    information();
    getInfo(senior, months, personal);
    cost = calcCost(senior, months, personal);
    cout << endl << endl << "Your total projected cost is $";
    cout << fixed << setprecision(2) << cost << endl << endl;
    menu = mainMenu();
  }

  return 0;
}

char mainMenu() {
  char input;
  cout << "Main menu (enter 'a' or 'b')" << endl;
  cout << "a. Calculate membership costs." << endl;
  cout << "b. Quit this program." << endl;
  cin >> input;
  while (input != 'a' && input != 'A' && input != 'b' && input != 'B')
  {
    char catchInput;
    cout << "Please enter either 'a' or 'b' only." << endl;
    cin >> catchInput;
    input = catchInput;
  }
  return input;
}

void information()
{
  cout << endl;
  cout << "The cost to become a member of a fitness center is as follows:" << endl;
  cout << "• the membership fee per month is $50.00" << endl;
  cout << "• the personal training session fee is $30.00" << endl;
  cout << "• the senior citizens discount is 30%" << endl;
  cout << "• if the membership is bought and paid for 12 ";
  cout << "or more months, the discount is 15%" << endl;
  cout << "• if more than five personal training sessions ";
  cout << "are bought and paid for, the discount ";
  cout << "on each session is 20%." << endl << endl;
}

void getInfo(bool &senior, int &months, int &personal)
{
  char yesOrNo = 'n';
  senior = 0;
  months = 0;
  personal = 0;

  cout << "Are you a senior citizen? (y/n) ";
  cin >> yesOrNo;
  while (yesOrNo != 'y' && yesOrNo != 'n')
  {
    char catchInput;
    cout << "Please enter either 'y' for 'yes' or 'n' for 'no' only." << endl;
    cin >> catchInput;
    yesOrNo = catchInput;
  }
  if (yesOrNo == 'y') {
    senior = 1;
    yesOrNo = 0;
  };

  cout << endl << "How many months are you purchasing?" << endl;
  cout << "(Enter a number) ";
  cin >> months;
  while (months <= 0) {
    cout << endl << "Please enter a positive integer: ";
    cin >> months;
  }
  cout << endl << "Would your like to sign up for one or more personal ";
  cout << "training sessions? (y/n) ";
  cin >> yesOrNo;
  while (yesOrNo != 'y' && yesOrNo != 'n')
  {
    char catchInput;
    cout << "Please enter either 'y' for 'yes' or 'n' for 'no' only." << endl;
    cin >> catchInput;
    yesOrNo = catchInput;
  }

  if (yesOrNo == 'y') {
    cout << endl << "How many sessions would you like to purchase? ";
    cin >> personal;
    while (personal <= 0) {
      cout << endl << "Please enter a positive integer: ";
      cin >> personal;
    }
  };
}

double calcCost(bool senior, int months, int personal) {
  double monthCost = months * 50.00;
  double seshCost = personal * 30.00;
  double totalCost;

  if (months > 11)
    monthCost *= 0.85;
  if (personal > 5)
    seshCost *= 0.8;
  totalCost = monthCost + seshCost;
  if (senior)
    totalCost *= 0.7;

  return totalCost;
}

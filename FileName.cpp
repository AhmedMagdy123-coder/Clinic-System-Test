#include <iostream>
using namespace std;
int main()
{
	double fare, dis;
	char time,choice ;
	do {
		cout << "enter distance travelled (in km): ";
		cin >> dis;
	
		cout << "enter time for trip (D for day / M for midnight):  ";
		cin >> time;
		if (time == 'D')
		{
			fare = (2 * dis) + 5;
		}
		else if (time == 'M')
		{
			((2 * dis) + 5) + (.1 * ((2 * dis) + 5));

		}
		cout <<"\n" << "total fare is " << fare;

		cout << "do you want to calculator more? ";
		cin >> choice;



	} while (choice == 'y' || choice == 'Y');


	cout << "thank you for using our application have a good day";



	return 0;





}
#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

class Time{
	public:
		int hour, minute, second, day;

		void displayDays();
		string weekName(int day);			// member function for changing the days after 24 hours
		void tick();						// member function for changing the time in Hours, minutes and seconds
};

void Time::displayDays(){
	cout << " ___________________________ " << endl;
	cout << "|                           |" << endl;
	cout << "|       Days list           |" << endl;
	cout << "|___________________________|" << endl;
	cout << "|                           |" << endl;
	cout << "|  [1]. Monday              |" << endl;
	cout << "|  [2]. Tuesday             |" << endl;
	cout << "|  [3]. Wednesday           |" << endl;
	cout << "|  [4]. Thursday            |" << endl;
	cout << "|  [5]. Friday              |" << endl;
	cout << "|  [6]. Saturday            |" << endl;
	cout << "|  [7]. Sunday              |" << endl;
	cout << "|___________________________|" << endl << endl;
}

string Time::weekName(int day)
{
	string day_name;

	switch(day)
	{
		case 1:	day_name = "Monday"; break;
		case 2: day_name = "Tueday"; break;
		case 3: day_name = "Wednesday"; break;
		case 4: day_name = "Thursday"; break;
		case 5: day_name = "Friday"; break;
		case 6: day_name = "Saturday"; break;
		case 7: day_name = "Sunday"; break;
	}
	return day_name;
}

void Time::tick()
{
	cout<< "\n-----------------------------------------------------------------------------\n";
	cout<<"\t    < Week Days >    < Standard Time >     < Universal Time > \n";
	cout<< "-----------------------------------------------------------------------------\n";
	
	while(true){
		for(int hr=hour; hr<24;hr++){
			for(int min=minute;min<60;min++){
				for(int sec=second;sec<60;sec++){
					if((hr)>=12){
						Sleep(1000);
						cout<<"\t\t"<< weekName(day) << "\t\t" << hr-12 << " : " << min << " : " << sec << " PM" 
							<<"\t\t" << hr << " : " << min << " : " << sec << endl;
					} else {
						Sleep(1000);
						cout<<"\t\t"<< weekName(day) << "\t\t" << hr << " : " << min << " : " << sec << " AM" 
							<<"\t\t" << hr << " : " << min << " : " << sec << endl;
					}
					second=0;
				}
				minute=0;
			}
			hour=0;
		}
		day++;

		if(day > 7){
			day = 1;
		}
	}
}

// Driver code
int main()
{
	Time obj;

	obj.displayDays();

	while(true){
		cout<<"Enter any day number: ";
		cin>>obj.day;
		if(obj.day > 0 && obj.day < 8){
			cout << "You choose " << obj.weekName(obj.day) << ". Great!" << endl << endl;
			break;
		}
		else{
			cout << "Invalid input! Please enter a valid day number." << endl << endl;
		}

	}

	cout << "------------- Universal time -------------" << endl;
	while(true){
		cout << "Choose hour between 1 to 23 :  ";
		cin >> obj.hour;
		if(obj.hour > 0 && obj.hour < 24){
			break;
		}
		else{
			cout << "Invalid input! Please enter a valid hour." << endl << endl;
		}

	}
	while(true){
		cout << "Choose minute between 1 to 59 :  ";
		cin >> obj.minute;
		if(obj.minute >= 0 && obj.minute < 60){
			break;
		}
		else{
			cout << "Invalid input! Please enter a valid minute." << endl << endl;
		}

	}
	while(true){
		cout << "Choose second between 1 to 59 :  ";
		cin >> obj.second;
		if(obj.second >= 0 && obj.second < 60){
			break;
		}
		else{
			cout << "Invalid input! Please enter a valid second." << endl << endl;
		}

	}
	cout << "-------------------------------------------" << endl;

	obj.tick();

	return 0;
}
#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
using namespace std;

//Struct
struct StudentRecord
{
	string name;
	string f_name;
	string roll_no;
	string ph_no;
	string programme;
	string section;
};

//Array
StudentRecord arr[200];

//Global Variables
int total = 0;
string Path = "time_table.txt";

//Function Prototypes
void profile();

void fee();
void time_table();
void cgpa();
void enter();
void remove();

void role_validation(char &choice);
void admin_validation(char &opt);
void student_validation(char &option);
void degree_validation(char &Choice);

int main ()
{
	HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
	bool flag=true;
	
	while(flag==true)
	{
		SetConsoleTextAttribute(color,3);
		cout << "~~~~~~~~~~~~~~ STUDENT MANAGEMENT SYSTEM ~~~~~~~~~~~~~~" << endl << endl;
		cout << "                      a. ADMIN                         " << endl;
		cout << "                      b. STUDENT                       " << endl;
		cout << "                      c. QUIT                          " << endl << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
		
		char choice;
		
		SetConsoleTextAttribute(color,7);
		cout << "Enter your Role/Posiion: ";
		cin  >> choice;
		
		role_validation(choice);
		system("cls");
		cout << endl;
		
		if(choice=='a' || choice=='A' )
		{
			bool chk=true;
			while(chk==true)
			{
				SetConsoleTextAttribute(color,3);
				cout << "~~~~~~~~~~~~~~~~~~~~ SELECT OPTION ~~~~~~~~~~~~~~~~~~~~" << endl << endl;
				cout << "               1. Enter Student Record                 " << endl;
				cout << "               2. Delete Students Record               " << endl;
				cout << "               3. Back                                 " << endl << endl;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
				
				char opt;
				SetConsoleTextAttribute(color,7);
				cout << "Enter option: ";
				cin  >> opt;
				
				admin_validation(opt);
				
				system("cls");
				switch(opt)
				{
					case '1':
						//Enter Student Record 
						enter();
						
						cout << endl;
						cin.ignore();
						cout << "Press any key to Return.... ";
						cin.get();
						
						system("cls");
						
						break;
					
					case '2':
						//Delete Students Record
						remove();
						
						cout << endl;
						cin.ignore();
						cout << "Press any key to Return.... ";
						cin.get();
						
						system("cls");
						
						break;
					
					case '3':
						//Back
						
						system("cls");
						
						cout << endl;
						chk=false;
						break;
				}
			}
		}
		else if (choice=='b' || choice=='B')
		{
			SetConsoleTextAttribute(color,7);
			string name, roll_no;
			cin.ignore();
			cout << "ENTER YOUR NAME: ";
			getline(cin,name);
			
			cout << "\nENTER YOUR ROLL NUMBER: ";
			getline(cin,roll_no);
			cout << endl;
			system("cls");
			bool check=true;
			while(check==true)
			{
				SetConsoleTextAttribute(color,3);
				cout << "~~~~~~~~~~~~~~~~~~~~ SELECT OPTION ~~~~~~~~~~~~~~~~~~~~" << endl << endl;
				cout << "                    1. Profile                         " << endl;
				cout << "                    2. Fee                             " << endl;
				cout << "                    3. Time Table                      " << endl;
				cout << "                    4. CGPA Calculator                 " << endl;
				cout << "                    5. Back                            " << endl << endl;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
				
				char option;
				
				SetConsoleTextAttribute(color,7);
				cout << "Enter option: ";
				cin  >> option;
				
				student_validation(option);
				
				system("cls");
				switch(option)
				{
					case '1':
						//Profile
						profile();
						
						cout << endl;
						cin.ignore();
						cout << "Press any key to Return.... ";
						cin.get();
						
						system("cls");
						
						break;
					
					case '2':
						//Fee
						fee();
						
						cin.ignore();
						cout << "Press any key to Return.... ";
						cin.get();
						
						system("cls");
						
						break;
					
					case '3':
						//Timetable
						time_table();
						
						cout << endl;
						cin.ignore();
						cout << "Press any key to Return.... ";
						cin.get();
						
						system("cls");
						
						break;
						
					case '4':
						//CGPA Calculator
						cgpa();
						
						cout << endl;
						cin.ignore();
						cout << "Press any key to Return.... ";
						cin.get();
						
						system("cls");
					
						break;
					
					case '5':
						//Back
						
						system("cls");
						
						check=false;
					
				}
			}
		}
		else
		{
			SetConsoleTextAttribute(color,9);
			cout << "\n..........(; I AM SORRY IT ENDED LIKE THIS (;..........\n" << endl;
			cout << endl;
			flag=false;
		}
	}
	return 0;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//Admin Options
void enter()
{
	
	int students_enter = 0;
	
	HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
	
	SetConsoleTextAttribute(color,7);
	cout << "How many students you want to enter: ";
	cin  >> students_enter;
	
	if (total == 0)
	{
		total+=students_enter;
		for (int i = 0; i < students_enter; i++)
		{
			cout<<"\nEnter the Data of student " << i+1 << endl << endl;
			
			cout << "Enter Name: ";
			cin.ignore();
			getline(cin, arr[i].name);
			
			cout << "Enter Father Name: ";
			getline(cin, arr[i].f_name);
			
			cout << "Enter Roll Number: ";
			cin  >> arr[i].roll_no;
			
			cout << "Enter Phone Number: ";
			cin  >> arr[i].ph_no;
			
			cout << "Enter Programme: ";
			cin  >> arr[i].programme;
			
			cout << "Enter Section: ";
			cin  >> arr[i].section;
			
			cout << endl;
		}
		SetConsoleTextAttribute(color,2);
		cout << "Record Entered Successfully!\n";
		SetConsoleTextAttribute(color,7);
	}
	else
	{
		for (int i = total; i < total + students_enter; i++)
		{
			cout<<"\nEnter the Data of student "<<i+1<<endl<<endl;
			
			cout << "Enter Name: ";
			cin.ignore();
			getline(cin, arr[i].name);
			
			cout << "Enter Father Name: ";
			getline(cin, arr[i].f_name);
			
			cout << "Enter Roll Number: ";
			cin  >> arr[i].roll_no;
			
			cout << "Enter Phone Number: ";
			cin  >> arr[i].ph_no;
			
			cout << "Enter Programme: ";
			cin  >> arr[i].programme;
			
			cout << "Enter Section: ";
			cin  >> arr[i].section;
			
			cout << endl;
		}
		SetConsoleTextAttribute(color,2);
		cout << "Record Entered Successfully!" << endl;
		SetConsoleTextAttribute(color,7);
		
		total+=students_enter;
	}
}

void remove()
{
	HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
	if(total==0)
	{
		SetConsoleTextAttribute(color,4);
		cout << "NO RECORD EXISTS " << endl;
	}
	else
	{
		string rollNo;
		cout << "\nEnter the roll number you want to remove: ";
		cin >> rollNo;
		bool flag=false;
		for(int d=0; d<total ; d++)
		{
			if(rollNo==arr[d].roll_no)	
			{
				for(int w=d; w<total; w++)
				{
					arr[w].name=arr[w+1].name;
					arr[w].f_name=arr[w+1].f_name;
					arr[w].roll_no=arr[w+1].roll_no;
					arr[w].ph_no=arr[w+1].ph_no;
					arr[w].programme=arr[w+1].programme;
					arr[w].section=arr[w+1].section;
				}
				total--;
				SetConsoleTextAttribute(color,2);
				cout << "\nRecord is Deleted Sucessfully!" << endl;
				SetConsoleTextAttribute(color,7);
				flag=true;
			}
		}
		if(flag==false)
			{
				SetConsoleTextAttribute(color,4);
				cout << "\nRoll Number does not Exists!" << endl;
				SetConsoleTextAttribute(color,7);
			}
	}
}

//Student Options
void profile()
{
	HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
	
	int chk=1;
	if(total==0)
	{
		SetConsoleTextAttribute(color,4);
		cout << "NO RECORD EXISTS " << endl;
	}
	else
	{
		SetConsoleTextAttribute(color,7);
		string rollNo;
		cout << "Enter the roll number you want to view profile of: ";
		cin >> rollNo;
		
		cout << endl;
		
		for(int r=0; r<total; r++)
		{
			if(rollNo==arr[r].roll_no)
			{
				cout << "Student Name = " << arr[r].name      << endl;
				cout << "Father Name  = " << arr[r].f_name    << endl;
				cout << "Roll Number  = " << arr[r].roll_no   << endl;
				cout << "Contact No   = " << arr[r].ph_no     << endl;
				cout << "Programme    = " << arr[r].programme << endl;
				cout << "Section      = " << arr[r].section   << endl;
				chk=0;
			}

		}
		if(chk==1)
		{
			SetConsoleTextAttribute(color,4);
			cout << "NO RECORD MATCHED #-#" << endl;
			SetConsoleTextAttribute(color,7);
		}
	}
}

void fee()
{
	
	int fee;
	float concession, actual_fee;
	
	HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
	
	SetConsoleTextAttribute(color,3);
	cout << " ___________ SELECT OPTION ___________ " << endl;
	cout << "|            1. BACHELORS             |" << endl;
	cout << "|            2. MA                    |" << endl;
	cout << "|            3. MPhil                 |" << endl;
	cout << "|            4. PHD                   |" << endl;
	cout << "|            5. Back                  |" << endl;
	cout << "|_____________________________________|" << endl << endl;
	
	char Choice;
	SetConsoleTextAttribute(color,7);
	cout << "Enter Your Degree: " ;
	cin >> Choice;
	
	degree_validation(Choice);
	
	SetConsoleTextAttribute(color,7);
	if(Choice=='5')
	{
		return;
	}
	cout << "Enter Your Concession: ";
	cin >> concession;
	float perc=concession/100;
	if(Choice=='1')
	{
	fee=362250;
	actual_fee=fee-(perc*fee);
	cout << "Your Payable Fee: Rs." << actual_fee << endl;
	}
	if(Choice=='2')
	{
	fee=249500;
	actual_fee=fee-(perc*fee);
	cout << "Your Payable Fee: Rs." << actual_fee << endl;
	}
	if(Choice=='3')
	{
	fee=274500;
	actual_fee=fee-(perc*fee);
	cout << "Your Payable Fee: Rs." << actual_fee << endl;
	}		
	if(Choice=='4')
	{
	fee=199667;
	actual_fee=fee-(perc*fee);
	cout << "Your Payable Fee: Rs." << actual_fee << endl;
	}
	cout << endl;
}

void time_table()
{
	ifstream file_TT;
	string line;
	file_TT.open(Path); 
	while (getline(file_TT,line))
	{
		
		cout << line << endl;
	}
	file_TT.close();
}

void cgpa()
{
	float gpa;
	float sem;
	float cgpa;
	float tgpa=0.0;
	
	HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
	
	cout << "Enter number of Semesters: ";
	cin  >> sem;
	while(sem<1 || sem>8)
	{
		SetConsoleTextAttribute(color,4);
		cout << "Invalid Semesters -_- Enter Again: ";
		cin  >> sem;
	}
	
	cout << endl;
	SetConsoleTextAttribute(color,7);
	
	for(int i=1; i<=sem; i++)
	{
		cout << "Enter GPA for semester " << i << " : ";
		cin  >> gpa;
		while(gpa<1 || gpa>4)
		{
			SetConsoleTextAttribute(color,4);
			cout << "Invalid GPA -_- Enter again: ";
			cin  >> gpa;
		}
		SetConsoleTextAttribute(color,7);
		tgpa+=gpa;
	}
	cgpa = tgpa/sem;
	
	cout << endl;
	
	cout << "CGPA:" << cgpa << endl;
}

//Validations
void role_validation(char &choice)
{
	HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
	while(!(choice=='a' || choice=='A' || choice=='b' || choice=='B' || choice=='c' || choice=='C' ))
	{
		SetConsoleTextAttribute(color,4);
		cout << "Invalid Choice -_- Enter Again: ";
		cin >> choice;
	}
}
void admin_validation(char &opt)
{
	HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
	while(( opt<'1' || opt>'3'))
	{
		SetConsoleTextAttribute(color,4);
		cout << "INVALID OPTION -_- Enter again: ";
		cin  >> opt;
	}
}
void student_validation(char &option)
{
	HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
	while( option<'1' || option>'5')
	{
		SetConsoleTextAttribute(color,4);
		cout << "INVALID OPTION -_- Enter again: ";
		cin  >> option;
	}
}
void degree_validation(char &Choice)
{
	HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
	while(Choice<'1' || Choice>'5')
	{
		SetConsoleTextAttribute(color,4);
		cout << "Re-Enter Your Degree(1-5): ";
		cin >> Choice;
	}
}

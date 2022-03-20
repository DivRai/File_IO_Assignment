// Assignment question 5

#include <fstream>
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
using namespace std;

class student
{
	public:
	     int ID; string name; string Location; string Branch;
	     void getdata()
	     {
	     	cout << "Enter ID: ";
	     	cin>>ID;
	     	cout << "Enter Name: ";
	     	cin>>name;
	     	cout << "Enter Location: ";
	     	cin>>Location;
	     	cout<<"Enter Branch: ";
	     	cin>>Branch;
	     }
	     void AddRecord()
	     {
	     	fstream f;
	     	student stu;
	     	f.open("student.txt", ios::app);
	     	stu.getdata();
	     	f << stu.ID << " " << stu.name << " " << stu.Location << " "<< stu.Branch << endl;
	     	f.close();
	     }
	     void display()
	     {
	     	int id1;
	     	int count = 0;
	     	int flag = 1;
	     	int num;
	     	string buf,str;
	     	fstream f1;
	     	student s;
	     	cout<< "Enter student ID: ";
	     	cin >> id1;
	     	f1.open("student.txt", ios::in);
	     	while(getline(f1,buf))
		{
			stringstream ss(buf);
			while(getline(ss,str,' '))
	     		{
		     		if(count == 0)
		     		{
		     			  stringstream obj;  
					  obj << str;  
					  obj >> num;  
					  if(num == id1)
					  {
					  	flag = 0;
					  	getline(ss,str,' ');
					  	cout << "\n----------------------------------------------";
					  	cout << endl << "Name: " << str << "  ";
					  	getline(ss,str,' ');
					  	cout << "Location: " << str << "  ";
					  	getline(ss,str,' ');
					  	cout << "Branch: " << str << "  ";
					  	cout << "\n----------------------------------------------" << endl;
					  	cout <<"\n\n";
					  	break;
					  }
		     		}
		     		count++;
	     		}
	     		count = 0;
	     	}
	     	if(flag)
	     	{
	     		cout << "\nStudent ID is not found" << endl;
	     	}
	     	f1.close();
	     }
};

int main()
{
	student s1;
	fstream f;
	int ch;
	f.open("student.txt", ios::app); 
	while(1)
	{
		cout << "\n----------Menu----------\n";
		cout << "1. Enter student detail \n2. Find student \n3. Exit\n"; 
		cout << "Enter your choice: ";
		cin >> ch;
		if(ch == 1)
		{
			s1.AddRecord();
			cout<<"\nUpdated!!!"<<endl;
		}
		else if(ch == 2)
		{
			student s2;
			s2.display();
		}		
		else 
		{
			break;
		}
	}
	cout << "Thank you" << endl;
	return 0;
}

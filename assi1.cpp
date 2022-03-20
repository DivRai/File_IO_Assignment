// Assignment question 1

#include<fstream>
#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	fstream file;
	string str;
	int size;
	int count = 0;
	string f = "data.txt";
	string cmp = "the";
	file.open(f,ios::in);
	if(!file)
	{
		cout << "The file cannot open" << endl; 
	}
	else
	{		
		while(file >> str)
		{
			if(str.compare(cmp)==0)
			{
				count++;
			}		
		}
	}
	cout << "Total number of time the word \"the\" is present in the file " << f << " is " << count << endl;
	return 0;
}



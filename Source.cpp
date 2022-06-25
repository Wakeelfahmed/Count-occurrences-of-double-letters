#include<iostream>
#include<fstream>
using namespace std;
char* toLower(char*);
void writeInFile(char, int);
int main()
{
	char x;

	int test = 0;
	int counter = 0;
	char mystring[] = "Dbouble bubble dBBeep in the sea of tooth with teeth and meet with riddle oo AAHda OOOO.";
	cout << mystring << endl;
	const int length = strlen(mystring);
	char* mystringlower = toLower(mystring);
	cout << mystringlower << endl;
	for (int i = 0; i <= length; i++)
	{
		counter = 0, test = false;

		if (mystringlower[i] == mystringlower[i + 1])
		{

			counter++;
			x = mystringlower[i];

			for (int testloop = 0; testloop < (i); testloop++)
			{
				if (x == mystringlower[testloop] && mystringlower[testloop + 1] == x)
				{
					test = 1;	//true means found previously
				}
			}
			if (test != 1)
			{
				for (int j = (i + 2); j <= length; j++)
				{
					if (x == mystringlower[j] && mystringlower[j + 1] == x)
					{
						counter++;
					}
				}
				cout << mystringlower[i] << mystringlower[(i + 1)] << " " << counter << endl;
				writeInFile(x, counter);
			}
		}
	}
}
char* toLower(char* string)
{
	int len = strlen(string);
	for (int index = 0; index < len; index++)
	{
		if (string[index] >= 65 && string[index] <= 90)
			string[index] += 32;
	}
	return string;
}
void writeInFile(char data, int times)
{
	ofstream myFile;
	myFile.open("Example1.txt", ios::app);
	myFile << data << data << " " << times << endl;
	myFile.close();
}
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
fstream file;
void convertbinary(char c)
{
	unsigned number; number = c;	unsigned mask;
	mask = (1 << 6); char s[7]; char o[11]; int counter1 = 0,counter2=0,counter3=0,counter4=0;
	cout << "The ascii equivalent of"<<"  " << c <<"  "<< "is " << "   ";
	for (int k = 0; k < 7; k++)
	{
		cout << ((number & mask) ? '1' : '0') ;
		s[k] = ((number & mask) ? '1' : '0');
		number <<= 1;
	}
	cout <<"  "<< "The strring copied is " << "  ";
	for (int i = 0; i < 7; i++)
	{
		cout << s[i];
	}
	cout << " ";
	
	o[2] = s[0]; o[4] = s[1]; o[5] = s[2]; o[6] = s[3]; o[8] = s[4]; o[9] = s[5]; o[10] = s[6];
	if (s[0] == '1') { counter1 = counter1 + 1; }
	if (s[1] == '1') { counter1 = counter1 + 1; }
	if (s[3] == '1') { counter1 = counter1 + 1; }
	if (s[4] == '1') { counter1 = counter1 + 1; }
	if (s[6] == '1') { counter1 = counter1 + 1; }
	if (counter1 % 2 == 0) { o[0] = '0'; }
	else { o[0] = '1'; }
	if (s[0] == '1') { counter2 = counter2 + 1; }
	if (s[2] == '1') { counter2 = counter2 + 1; }
	if (s[3] == '1') { counter2 = counter2 + 1;; }
	if (s[5] == '1') { counter2 = counter2 + 1; }
	if (s[6] == '1') { counter2 = counter2 + 1; }
	if (counter2 % 2 == 0) { o[1] = '0'; }
	else { o[1] = '1'; }

	if (s[1] == '1') { counter3 = counter3 + 1; }
	if (s[2] == '1') { counter3 = counter3 + 1; }
	if (s[3] == '1') { counter3 = counter3 + 1; }
	if (counter3 % 2 == 0) { o[3] = '0'; }
	else { o[3] = '1'; }

	if (s[4] == '1') { counter4 = counter4 + 1; }
	if (s[5] == '1') { counter4 = counter4 + 1; }
	if (s[6] == '1') { counter4 = counter4 + 1; }
	if (counter4 % 2 == 0) { o[7] = '0'; }
	else { o[7] = '1'; }
	cout << "CODE WORD IS " << "  ";
	for (int k = 0; k < 11; k++)
	{
		cout << o[k];
	}
	cout << endl;
	if (!file.is_open())
	{
		cout << "error file opening" << endl;
	}
	else
	{

		for (int i = 0; i < 11; i++)
		{

			file << o[i];
		}
	}
	file << endl;

}
int main()
{
	string input;
	cout << "Enter the string" << endl;
	getline(cin, input);
	file.open("Transmitted.txt", ios::out);
	for (int i = 0; i < input.length(); i++)
	{
		convertbinary(input[i]);

	}
	file.close();
	cout << "Transmitted code words are written in the file Transmitted.txt" << endl;
	return 1;
}
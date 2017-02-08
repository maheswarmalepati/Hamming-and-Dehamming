#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;
void print(string);
void check(string name1)
{
	int parity1 = 0, parity2 = 0, parity3 = 0, parity4 = 0, megacounter = 0;
	if (name1[0] == '1') { parity1 = parity1 + 1; }
	if (name1[2] == '1') { parity1 = parity1 + 1; }
	if (name1[4] == '1') { parity1 = parity1 + 1; }
	if (name1[6] == '1') { parity1 = parity1 + 1; }
	if (name1[8] == '1') { parity1 = parity1 + 1; }
	if (name1[10] == '1') { parity1 = parity1 + 1; }
	if (parity1 % 2 == 0) { parity1 = 0; }
	else { parity1 = 1; }

	if (name1[1] == '1') { parity2 = parity2 + 1; }
	if (name1[2] == '1') { parity2 = parity2 + 1; }
	if (name1[5] == '1') { parity2 = parity2 + 1; }
	if (name1[6] == '1') { parity2 = parity2 + 1; }
	if (name1[9] == '1') { parity2 = parity2 + 1; }
	if (name1[10] == '1') { parity2 = parity2 + 1; }
	if (parity2 % 2 == 0) { parity2 = 0; }
	else { parity2 = 1; }

	if (name1[3] == '1') { parity3 = parity3 + 1; }
	if (name1[4] == '1') { parity3 = parity3 + 1; }
	if (name1[5] == '1') { parity3 = parity3 + 1; }
	if (name1[6] == '1') { parity3 = parity3 + 1; }
	if (parity3 % 2 == 0) { parity3 = 0; }
	else { parity3 = 1; }

	if (name1[7] == '1') { parity4 = parity4 + 1; }
	if (name1[8] == '1') { parity4 = parity4 + 1; }
	if (name1[9] == '1') { parity4 = parity4 + 1; }
	if (name1[10] == '1') { parity4 = parity4 + 1; }
	if (parity4 % 2 == 0) { parity4 = 0; }
	else { parity4 = 1; }
	cout << "parities are" <<"  "<< parity1 << "   " << parity2 << "   " << parity3 << "  " << parity4 << " ";
	
	if ((parity1== 0)&&(parity2==0)&&(parity3==0)&&(parity4==0))
	{
		cout << "There is no error and the original letter is  ";
		print(name1);
	}
	else
	{
		megacounter = (1 * parity1) + (2 * parity2) + (4 * parity3) + (8 * parity4);
		cout << "   The error is in " << megacounter << "  " << "position so changing the value in that position  ";
		if (name1[megacounter-1] == '1') { name1[megacounter-1] = '0'; }
		else {	name1[megacounter-1] = '1';	}
		cout << name1<<" ";
		print(name1);
	}

}
int main()
{
	ifstream file1;
	file1.open("Received.txt", ios::in);

	if (!file1.is_open())
	{
		cerr << "problem with reading the file" << endl;
	}
	else
	{
		string name1; char c[11];
		while (!file1.eof())
		{
			getline(file1, name1);
			cout << name1<<" ";
			check(name1);
		}
	}
	file1.close();
	return 1;
}

void print(string name1)
{
	int name2[7]; int ascii;//converting takes 49 and 48 so subtracting 48 gives either 1 or 0
	name2[0] = name1[2] - 48; name2[1] = name1[4] - 48; name2[2] = name1[5] - 48; name2[3] = name1[6] - 48; name2[4] = name1[8] - 48;
	name2[5] = name1[9] - 48; name2[6] = name1[10] - 48;
	for (int i = 0; i < 7; i++)
	{
		ascii = (name2[6] * 1) + (name2[5] * 2) + (name2[4] * 4) + (name2[3] * 8) + (name2[2] * 16) + (name2[1] * 32) + (name2[0] * 64);

	}
	cout << "The equivalent ascii number is " << ascii << "  " << "and the character is ";
	char c = ascii;
	cout <<c << endl;
}
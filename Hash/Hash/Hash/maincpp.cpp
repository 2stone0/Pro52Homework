#include "HashTable.h"

#include <fstream>

using namespace std;

void LoadFile(HashTable& table)
{
	fstream file;
	string word, t, q, filename;
	filename = "../english3.txt";
	file.open(filename.c_str());
	while (file >> word)
	{
		table.InsertData(word);
	}
	cout << "���� �ε� �Ϸ�!" << endl;
}

// stl hash ����
void LoadFile(HashTable& table)
{
	fstream file;
	string word, t, q, filename;
	filename = "../english3.txt";
	file.open(filename.c_str());
	while (file >> word)
	{
		table.InsertData(word);
	}
	cout << "���� �ε� �Ϸ�!" << endl;
}

int main()
{
	HashTable myHash;
	LoadFile(myHash);

}
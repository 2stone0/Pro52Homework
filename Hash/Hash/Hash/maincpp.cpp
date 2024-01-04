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
	cout << "파일 로드 완료!" << endl;
}

// stl hash 쓰기
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
	cout << "파일 로드 완료!" << endl;
}

int main()
{
	HashTable myHash;
	LoadFile(myHash);

}
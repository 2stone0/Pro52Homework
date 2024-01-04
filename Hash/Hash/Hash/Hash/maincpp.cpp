#include "HashTable.h"
#include "Timer.h"

#include <fstream>

using namespace std;

void LoadFile(HashTable& table)
{
	vector<string> words;
	fstream file;
	string word, t, q, filename;
	filename = "../english3.txt";
	file.open(filename.c_str());
	while (file >> word)
	{
		words.push_back(word);
	}

	for (const auto& _word : words)
		table.InsertData(_word);

	cout << "���� �ε� �Ϸ�!" << endl;
}

//// stl hash ����
//void LoadFile(HashTable& table)
//{
//	fstream file;
//	string word, t, q, filename;
//	filename = "../english3.txt";
//	file.open(filename.c_str());
//	while (file >> word)
//	{
//		table.InsertData(word);
//	}
//	cout << "���� �ε� �Ϸ�!" << endl;
//}

int main()
{
	HashTable myHash;
	LoadFile(myHash);
	
	Timer timer;
	timer.Start();
	myHash.FindData("uncatered");
	timer.End();
	timer.GetElaspedTime();


	return 0;

}
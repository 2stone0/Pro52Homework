#include "HashTable.h"
#include "Timer.h"

#include <fstream>
#include <unordered_map>

using namespace std;


std::unordered_map<std::string, int> hashMap;

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
void LoadFile()
{
	fstream file;
	string word, t, q, filename;
	filename = "../english3.txt";
	file.open(filename.c_str());
	while (file >> word)
	{
		int value = 0;

		for (char ch : word) {
			value += static_cast<size_t>(ch);
		}

		hashMap[word] = value;
	}
	cout << "파일 로드 완료!" << endl;
}

int main()
{
	HashTable myHash;
	Timer timer;

	LoadFile(myHash);
	LoadFile();
	
	timer.Start();
	myHash.FindData("scytheman");
	timer.End();

	timer.GetElaspedTime();

	timer.Start();
	std::string key = "scytheman";
	if (hashMap.find(key) != hashMap.end()) {
		std::cout << "찾은 데이터 : " << key << std::endl;
	}
	else {
		std::cout << "데이터가 없습니다." << std::endl;
	}
	timer.End();

	timer.GetElaspedTime();

	return 0;
}
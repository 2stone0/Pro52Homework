#pragma once
#include <iostream>
#include <vector>

#define SIZE 10000;

using namespace std;

struct Node
{
	int Value=-1;
	string Key;
	Node* next;
};

class HashTable
{
	vector<Node> m_HashTable;
	int m_Size=0;

	int HashFunction(string key);

public:
	HashTable() = default;
	~HashTable() = default;

	void FindData(string key);
	void InsertData(string key);
	void DeleteData(string key);
};


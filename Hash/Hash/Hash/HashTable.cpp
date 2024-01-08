#include "HashTable.h"

int HashTable::HashFunction(string key)
{
	int value=0;
	
	for (char ch : key) {
		value += static_cast<size_t>(ch);
	}

	return value-1;
}


void HashTable::FindData(string key)
{
	int value = HashFunction(key);

	if (value == 712)
		int a = 2;

	Node& node = m_HashTable[value];
	while (node.Key != key)
	{
		if (node.next != nullptr)
			node = *node.next;
		else
		{
			cout << "해당 데이터가 없습니다." << endl;
			return;
		}
	}

	cout << "찾은 데이터 :" << node.Key << endl;
}

void HashTable::InsertData(string key)
{
	int value = HashFunction(key);

	Node newNode;
	newNode.Key = key;
	newNode.Value = value;

	if (value > m_Size) // 다시 확인
	{
		m_HashTable.resize(value+1);
		m_Size = value + 1;
	}

	if (m_HashTable[value].Value == -1)
		m_HashTable[value] = newNode;
	else
	{
		//Todo
		Node* move=new Node;
		move->Key = m_HashTable[value].Key;
		move->Value = m_HashTable[value].Value;
		move->next = m_HashTable[value].next;

		m_HashTable[value] = newNode;
		m_HashTable[value].next = move;
	}
}

void HashTable::DeleteData(string key)
{
	//Todo

	int value = HashFunction(key);

	Node& node = m_HashTable[value];
	while (node.Key != key)
	{
		if (node.next != nullptr)
			node = *node.next;
		else
		{
			cout << "해당 데이터가 없습니다." << endl;
			break;
		}
	}
}

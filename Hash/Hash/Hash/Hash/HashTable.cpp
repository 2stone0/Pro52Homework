#include "HashTable.h"

int HashTable::HashFunction(string key)
{

	int hashValue = 0;
	for (char ch : key) {
		hashValue += static_cast<unsigned int>(ch);
	}

	if (hashValue < 0)
		hashValue *= -1;

	return hashValue-1;

}

void HashTable::FindData(string key)
{
	cout << "ã������ ������ : " << key << endl;
	int value = HashFunction(key);

	if (value < 0)
	{
		cout << "�����Ͱ� �����ϴ�." << endl;
		return;
	}
	Node& node = m_HashTable[value];
	while (node.Key != key)
	{
		if (node.next != nullptr)
			node = *node.next;
		else
		{
			cout << "�ش� �����Ͱ� �����ϴ�." << endl;
			return;
		}
	}

	cout << "ã�� ������ :" << node.Key << endl;
}

void HashTable::InsertData(string key)
{
	int value = HashFunction(key);

	if (value == 954)
		int a = 1;

	Node* newNode=new Node;
	newNode->Key = key;
	newNode->Value = value;

	if (value > m_Size) {
		m_HashTable.resize(value+1);
		m_Size = value + 1;
	}


	if (m_HashTable[value].Value == -1)
		m_HashTable[value] = *newNode;
	else
	{
		//Todo
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
			cout << "�ش� �����Ͱ� �����ϴ�." << endl;
			break;
		}
	}
}

#include "HashTable.h"

int HashTable::HashFunction(string key)
{
	int value;

	return value;
}


void HashTable::FindData(string key)
{
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

	cout << "ã�� ������ :" << node.Key << endl;
}

void HashTable::InsertData(string key)
{
	int value = HashFunction(key);

	Node newNode;
	newNode.Key = key;
	newNode.Value = value;

	if (value > m_Size) // �ٽ� Ȯ��
		m_HashTable.reserve(value);

	if (m_HashTable[value].Value == -1)
		m_HashTable[value] = newNode;
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

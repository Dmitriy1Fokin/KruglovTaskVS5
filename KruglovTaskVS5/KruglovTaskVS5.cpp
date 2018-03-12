// KruglovTaskVS5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

using namespace std;

typedef struct DataStruct
{
	int key1;
	int key2;
	string  str;

	bool operator < (const DataStruct& ds)
	{
		if (key1 == ds.key1)
		{
			if (key2 == ds.key2)
			{
				return str.length() < ds.str.length();
			}
			else
			{
				return key2 < ds.key2;
			}
		}
		else
		{
			return key1 < ds.key1;
		}
		
	}
};

vector<DataStruct> addStruct(int amountOfElements)
{
	vector<DataStruct> vStruct;
	DataStruct temp_struct;
	string stringArr[10] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten" };
	int temp_key1, temp_key2;
	string temp_str;
	srand(time(0));

	for (int i = 0; i < amountOfElements; i++)
	{
		temp_key1 = (rand() % 11) - 5;
		temp_key2 = (rand() % 11) - 5;
		temp_str = stringArr[rand() % 10];
		temp_struct.key1 = temp_key1;
		temp_struct.key2 = temp_key2;
		temp_struct.str = temp_str;
		vStruct.push_back(temp_struct);
	}

	return vStruct;
}

void show(vector<DataStruct> &vec)
{
	for (int i = 0; i < vec.size(); i++)
		cout << i << ". Str: " << vec[i].str << ".\t Key1: " << vec[i].key1 << ".\t Key2: " << vec[i].key2 << endl;
}

int main()
{
	vector<DataStruct> vectorMain;
	vector<DataStruct>::iterator first, last;


	vectorMain = addStruct(20);
	first = vectorMain.begin();
	last = vectorMain.end();
	cout << "Unsorted:\n";
	show(vectorMain);
	
	sort(first, last);
	cout << "\nSorted:\n";
	show(vectorMain);
	//for_each(first, last, cout << i)

	_getch();
    return 0;
}


#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <stack>	
using namespace std;
struct Node // ������ ������ "���� ������"
{
	int data;
	string num; // ����� ����
	Node *l = nullptr, *r = nullptr; //������ �� ������ � ������ �������;
};

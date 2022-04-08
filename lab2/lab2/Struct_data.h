#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <stack>	
using namespace std;
struct Node // шаблон класса "узел дерева"
{
	int data;
	string num; // номер узла
	Node *l = nullptr, *r = nullptr; //ссылки на левого и праого сыновей;
};

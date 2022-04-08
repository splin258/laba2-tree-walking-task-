#pragma once
#include"Struct_data.h"

template <typename T>
class Tree // шаблон класса "дерево"
{
private:
	size_t size = 0;
public:
	Node * root = nullptr;
	//Инициализация дерева
	void push_of_file(T _data, string _num, Node *current)
	{
		if (size == 0)
		{									//добавление корня
			Node *newNode = new Node;
			newNode->data = _data;
			newNode->num = _num;
			root = newNode;
			current = root;
			size++;
		}
		else
		{									//добавление нового узла
			if (_num.length() >= current->num.length())
			{
				if (_num[current->num.length()] == '0' && current->l == nullptr)
				{
					Node *newNode = new Node;
					newNode->data = _data;
					newNode->num = _num;
					current->l = newNode;
					size++;
					return;
				}

				else
				{
					if (_num[current->num.length()] == '1' && current->r == nullptr)
					{
						Node *newNode = new Node;
						newNode->data = _data;
						newNode->num = _num;
						current->r = newNode;
						size++;
						return;
					}

				}
			}
			if (_num > current->num)
			{
				if (_num[current->num.length()] == '0' && current->l != nullptr)
				{
					push_of_file(_data, _num, current->l);
				}
				else
				{
					push_of_file(_data, _num, current->r);
				}
			}
		}

	}
	//Проверка на сортировку дерева
	bool sort(Node *current, bool flag)
	{


		if (current->l)
		{
			if (current->data >= current->l->data)
			{
				flag = sort(current->l, flag);
			}
			else
			{
				return flag = true;
			}
		}
		if (flag == true)
		{
			return flag;
		}
		else if (current->r)
		{
			if (current->data < current->r->data)
			{
				flag = sort(current->r, flag);
			}
			else
			{
				return flag = true;
			}
		}
		return flag;
	}
	//Вывод дерева на экран
	void print(Node *root, int u)
	{

		cout << root->num << "	" << root->data << endl;
		u--;
		if (root->l)
		{
			print(root->l, ++u);
		}
		if (root->r)
		{
			print(root->r, ++u);
		}
	}
	//Удаление узлов дерева 
	void tree_clearing(Node *current)
	{

		if (current->l)
		{
			tree_clearing(current->l);
		}

		if (current->r)
		{
			tree_clearing(current->r);
		}
		delete current;
		current = nullptr;
		size--;
	}

};
#pragma once
#include "Struct_data.h"

template <typename T>
class Tree_no_recursion // шаблон класса "дерево"
{
private:
	size_t size = 0;

public:
	Node *root = nullptr;
	//Инициализация дерева
	void push_of_file_no_recursion(T _data, string _num, Node *current)
	{

		for (int i = 0; i <= size; i++)
		{
			if (size == 0)
			{									//добавление корня
				Node *newNode = new Node;
				newNode->data = _data;
				newNode->num = _num;
				root = newNode;
				current = root;
				size++;
				break;
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
						current = current->l;
					}
					else
					{
						current = current->r;
					}
				}
			}
		}

	}
	//Проверка на сортировку дерева
	bool sort_no_recursion(Node *current, bool flag)
	{
		stack<Node *> s;  // Создаем стек
		s.push(current);  // Вставляем корень в стек
		Node *parent;
		while (s.empty() == false)
		{
			// Извлекаем вершину стека и печатаем
			Node *temp = s.top();
			s.pop();
			//cout << temp->data << " ";
			parent = temp;
			if (temp->r)
			{
				s.push(temp->r);// Вставляем в стек правого потомка
				if (parent->data > temp->r->data)
				{
					return flag = true;
				}
			}
			if (temp->l)
			{
				s.push(temp->l);  // Вставляем в стек левого потомка
				if (parent->data < temp->l->data)
				{
					return flag = true;
				}
			}
		}
		return flag;
	}
	//Вывод дерева на экран
	void print_no_recursion(Node *root, int u)
	{

		stack<Node *> s;  // Создаем стек
		s.push(root);  // Вставляем корень в стек
		while (s.empty() == false)
		{
			// Извлекаем вершину стека и печатаем
			Node *temp = s.top();
			s.pop();
			cout << temp->num << "	" << temp->data << endl;

			if (temp->r)
			{
				s.push(temp->r);// Вставляем в стек правого потомка
			}
			if (temp->l)
			{
				s.push(temp->l);  // Вставляем в стек левого потомка
			}
		}
	}
	//Удаление узлов дерева 
	void tree_clearing_no_recursion(Node *root)
	{
		stack<Node *> s;  // Создаем стек
		s.push(root);  // Вставляем корень в стек
		while (s.empty() == false)
		{
			// Извлекаем вершину стека и печатаем
			Node *temp = s.top();
			s.pop();

			if (temp->r)
			{
				s.push(temp->r);// Вставляем в стек правого потомка
			}
			if (temp->l)
			{
				s.push(temp->l);  // Вставляем в стек левого потомка
			}
			delete temp;
			temp = nullptr;
		}
	}

};
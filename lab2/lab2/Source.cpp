#include "Tree_rec.h"
#include "Tree_rec.h"
#include"Tree_no_rec.h"
#include "menu.h"
 
/*struct Node // шаблон класса "узел дерева"
{
	int data; 
	string num; // номер узла
	Node *l = nullptr, *r = nullptr; //ссылки на левого и праого сыновей;
};


template <typename T>
class Tree // шаблон класса "дерево"
{
private:
	size_t size = 0;
public:
	Node *root = nullptr;
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
	
		if (root->l)
		{
			print(root->l, ++u);                   
		}
		cout  << root->num << "	"<< root->data << endl;            
		u--;
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
*/
/*
template <typename T>
class Tree_no_recursion // шаблон класса "дерево"
{
private:
	size_t size = 0;
	
public:
	vector<string> _num;
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
			//cout << temp->num << "	" << temp->data << endl;
			
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
*/


int main()
{
	int k = 0;
	do
	{
		cout << "Choose how to bypass the tree." << endl << "1) No recursive bypass. " << endl << "2) Recursive bypass." << endl << "3) Exit." << endl << endl;
		while (true)
		{
			cin >> k;
			if (cin.peek() == '\n') {
				break;
			}
			else {
				cout << "Input error (integer expected):" << endl;
				cin.clear();
				cin.ignore(cin.rdbuf()->in_avail());
			}
		}
		cout << endl;
		switch (k)
		{
		case 1:
		{
			system("cls");
			/*do
			Tree_no_recursion<int> tree_no_rec;
			int data_no_rec;
			string num_no_rec;
			int j = 0;
			{
				cout << "Select the number of the action." << endl << "1) Read tree from file. " << endl << "2) To check the tree to sort." << endl << "3) Display the tree on the screen." << endl << "4) Tree cleanup." << endl << "5) Exit." << endl << endl;
				while (true)
				{
					cin >> j;
					if (cin.peek() == '\n') {
						break;
					}
					else {
						cout << "Input error (integer expected):" << endl;
						cin.clear();
						cin.ignore(cin.rdbuf()->in_avail());
					}
				}
				cout << endl;
				switch (j)
				{
				case 1:
				{
					if (tree_no_rec.root == nullptr)
					{
						string filename;
						cout << "Enter file name:" << endl;
						cin >> filename;
						fstream fin(filename, ios::in);
						if (!fin.is_open())
						{
							cout << "Wrong file name." << endl << endl;
							break;
						}
						while (fin >> num_no_rec >> data_no_rec)
						{
							tree_no_rec.push_of_file_no_recursion(data_no_rec, num_no_rec, tree_no_rec.root);
						}
						cout << "tree successfully read." << endl << endl;
						fin.close();
					}
					else
					{
						cout << "Clear the tree to write a new tree." << endl << endl;
					}
					break;
				}
				case 2:
				{
					if (tree_no_rec.root != nullptr)
					{
						bool flag = false;
						if (tree_no_rec.sort_no_recursion(tree_no_rec.root, flag))
						{
							cout << "Not sorted." << endl << endl;
						}
						else
						{
							cout << "Sorted." << endl << endl;
						}

					}
					else
					{
						cout << "Read tree from file." << endl << endl;
					}
					break;
				}
				case 3:
				{
					if (tree_no_rec.root != nullptr)
					{
						tree_no_rec.print_no_recursion(tree_no_rec.root, 0);
						cout << endl;
					}
					else
					{
						cout << "Read tree from file." << endl << endl;
					}
					break;
				}
				case 4:
				{
					if (tree_no_rec.root != nullptr)
					{
						tree_no_rec.tree_clearing_no_recursion(tree_no_rec.root);
						tree_no_rec.root = nullptr;
						cout << "Tree cleanup successful." << endl << endl;
					}
					else
					{
						cout << "Read tree from file." << endl << endl;
					}
					break;
				}
				case 5:
				{
					break;
				}
				default:
				{
					cout << "there is no such action number. Try again" << endl;
				}
				}
			} while (j != 5);
			if (tree_no_rec.root != nullptr)
			{
				tree_no_rec.tree_clearing_no_recursion(tree_no_rec.root);
				tree_no_rec.root = nullptr;
				cout << "You forgot to clean the tree, so we did it for you." << endl << endl;
			}*/
			menu_no_rec();
			break;
		}
		case 2:
		{
			system("cls");
			/*
			Tree<int> tree;
			string num;
			int data;
			int i = 0;
			do
			{
				cout << "Select the number of the action." << endl << "1) Read tree from file. " << endl << "2) To check the tree to sort." << endl << "3) Display the tree on the screen." << endl << "4) Tree cleanup." << endl << "5) Exit." << endl << endl;
				while (true)
				{
					cin >> i;
					if (cin.peek() == '\n') {
						break;
					}
					else {
						cout << "Input error (integer expected):" << endl;
						cin.clear();
						cin.ignore(cin.rdbuf()->in_avail());
					}
				}
				cout << endl;
				switch (i)
				{
				case 1:
				{
					if (tree.root == nullptr)
					{
						string filename;
						cout << "Enter file name:" << endl;
						cin >> filename;
						fstream fin(filename, ios::in);
						if (!fin.is_open())
						{
							cout << "Wrong file name." << endl << endl;
							break;
						}
						while (fin >> num >> data)
						{
							tree.push_of_file(data, num, tree.root);
						}
						cout << "tree successfully read." << endl << endl;
						fin.close();
					}
					else
					{
						cout << "Clear the tree to write a new tree." << endl << endl;
					}
					break;
				}
				case 2:
				{
					if (tree.root != nullptr)
					{
						bool flag = false;
						if (tree.sort(tree.root, flag))
						{
							cout << "Not sorted." << endl << endl;
						}
						else
						{
							cout << "Sorted." << endl << endl;
						}

					}
					else
					{
						cout << "Read tree from file." << endl << endl;
					}
					break;
				}
				case 3:
				{
					if (tree.root != nullptr)
					{
						tree.print(tree.root, 0);
						cout << endl;
					}
					else
					{
						cout << "Read tree from file." << endl << endl;
					}
					break;
				}
				case 4:
				{
					if (tree.root != nullptr)
					{
						tree.tree_clearing(tree.root);
						tree.root = nullptr;
						cout << "Tree cleanup successful." << endl << endl;
					}
					else
					{
						cout << "Read tree from file." << endl << endl;
					}
					break;
				}
				case 5:
				{
					break;
				}
				default:
				{
					cout << "there is no such action number. Try again" << endl;
				}
				}
			} while (i != 5);
			if (tree.root != nullptr)
			{
				tree.tree_clearing(tree.root);
				tree.root = nullptr;
				cout << "You forgot to clean the tree, so we did it for you." << endl << endl;
			}*/
			menu_rec();
			break;
		}

		case 3:
		{
			break;
		}
		}
	} while (k != 3);
	return 0;
}
#include"menu.h"
void menu_rec()
{

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
			system("cls");
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
	}
}

void menu_no_rec()
{
	Tree_no_recursion<int> tree_no_rec;
	int data_no_rec;
	string num_no_rec;
	int j = 0;
	do
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
			system("cls");
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
	}
}
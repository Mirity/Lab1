#define COUNT_OF_CASES 10
#include <iostream>
#include "interface.h"

Interface::~Interface()
{
	delete[] _names;
	delete[] _cases;
}

Interface::Interface()
{
	_names = new std::string[COUNT_OF_CASES];
	_cases = new Rectangle[COUNT_OF_CASES];
}
int Interface::GetIndex(const std::string name) const
{
	for (int i = 0; i < COUNT_OF_CASES; i++)
	{
		if (name == _names[i])
		{
			return i;
		}
	}
	return -1;
}
void Interface::EditRectangle() const
{
	Point* cords = new Point[COUNT_OF_SIDES];
	int cord = 0;
	std::string name;
	std::cout << "Enter name of rectangle to edit\n>> ";
	std::cin >> name;
	int index = GetIndex(name);
	if (index != -1)
	{

		std::cout << "Enter new cords (x,y)\n1------2\n-       -\n-       -\n-       -\n4------3\n";
		try
		{
			for (int i = 0; i < COUNT_OF_SIDES; i++)
			{
				std::cin >> cords[i].x;
				std::cin >> cords[i].y;
			}

			Rectangle temp(cords);

			_cases[index] = temp;
			std::cout << "Complete\n";
		}
		catch (const std::logic_error& err)
		{
			std::cout << err.what() << "\n";
		}
		delete[] cords;
	}
	else
	{
		std::cout << "Wrong name\n";
	}
}
	void Interface::CreateRectangle() const
	{
		Point* cords = new Point[COUNT_OF_SIDES];
			
				
				std::string name; bool isEnoughtSpace = false; int index;

				std::cout << "Enter cords (x,y)\n1------2\n-      -\n-      -\n-      -\n4------3\n";

				for (int i = 0; i < COUNT_OF_SIDES; i++)
				{
					std::cin >> cords[i].x;
					std::cin >> cords[i].y;
				}
				std::cout << "Enter name of rectangle\n>> ";
				std::cin >> name;

				for (int i = 0; i < COUNT_OF_CASES; i++)
				{
					if (_names[i].empty())
					{
						isEnoughtSpace = true;
						index = i;
					}
				}

				if (isEnoughtSpace)
				{
					try
					{
						Rectangle temp(cords);
						_names[index] = name;
						_cases[index] = temp;
						std::cout << "Complete\n";
					}
					catch (const std::logic_error& err)
					{
						std::cout << err.what() << "\n";
					}
					
				}
				else
				{
					std::cout << "You don't have enought space, if you want delete something press '1', else press '2'\n";
					int choice = 0;
					std::cin >> choice;
					if (choice == 1)
					{
						DelRectangle();
						try 
						{
							Rectangle temp(cords);
							_names[index] = name;
							_cases[index] = temp;
							std::cout << "Complete\n";
						}
						catch (const std::logic_error& err)
						{
							std::cout << err.what() << "\n";
						}

					}
					if (choice == 2)
					{
						std::cout << "Okay\n";
					}
					else
					{
						std::cout << "It is not 1 or 2\n";
					}
				}
			
			delete[] cords;
	}

	void Interface::DeleteRectangle(const std::string name) const
	{
		int index = GetIndex(name);

		if (index == -1)
		{
			std::cout << "Can't find rectangle with this name\n";
		}
		else
		{
			_names[index] = "";
		}
	}

	void Interface::PrintRectangle() const
	{
		std::string name;
		std::cout << "Enter name of rectangle to print\n>> ";
		std::cin >> name;
		int index = GetIndex(name);
		if (index != -1)
		{
			std::cout << _cases[index].ToString();
		}
		else
		{
			std::cout << "Wrong name\n";
		}
	}
	void Interface::PrintAllRec() const
	{
		for (int i = 0; i < COUNT_OF_CASES; i++)
		{
			if (_names[i].empty())
			{
				std::cout << i + 1 << ":\n" << "Empty\n\n";
			}
			else
			{
				std::cout << i+1 << ":\n";
				std::cout <<"Name:"<< _names[i] << '\n';
				std::cout << _cases[i].ToString();
				std::cout << "\n\n";
			}

		}
	}

	void Interface::Area() const
	{
		std::string name;
		std::cout << "Enter name of rectangle to get area\n>> ";
		std::cin >> name;
		if (GetIndex(name) != -1)
		{
			std::cout << _cases[GetIndex(name)].Area() << "\n";
		}
		else
		{
			std::cout << "Wrong name\n";
		}
		
	}

	void Interface::Move() const
	{
		std::string name;
		char route;
		int scale = 0;
		bool correct1 = true;
		bool correct = true;
		std::cout << "Enter name of rectangle to move\n>> ";
		std::cin >> name;
		if (GetIndex(name) != -1)
		{
			std::cout << "Enter route\n r=right\n l=left\n u=up\n d=down\n";
			std::cin >> route;
			
			while (correct)
			{
				if (route == 'r' || route == 'l' || route == 'u' || route == 'd')
				{
					correct = false;
				}
				else
				{
					std::cout << "Enter correct route\n";
					std::cin >> route;
				}
			}

			std::cout << "Enter scale\n";
			std::cin >> scale;

			while (correct1)
			{
				if (scale >= 0)
				{
					correct1 = false;
					_cases[GetIndex(name)].Move(route, scale);
				}
				else
				{
					std::cout << "Enter positive scale\n";
					std::cin >> scale;
				}
			}
			
		}
		else
		{
			std::cout << "Wrong name\n";
		}
	}

	void Interface::Build() const
	{
		std::string name;
		std::string name1;
		int arg;
		std::cout << "Enter name of first rectangle\n>> ";
		std::cin >> name;
		std::cout << "Enter name of second rectangle\n>> ";
		std::cin >> name1;
		if (GetIndex(name) != -1 && GetIndex(name1) != -1)
		{
			Point* cords = new Point[COUNT_OF_SIDES];
			std::string name2; bool isEnoughtSpace = false; int index;
			std::cout << "Enter name of new build rectangle\n>> ";
			std::cin >> name2;

			for (int i = 0; i < COUNT_OF_CASES; i++)
			{
				if (_names[i].empty())
				{
					isEnoughtSpace = true;
					index = i;
				}
			}

			if (isEnoughtSpace)
			{
				Rectangle temp;
				try 
				{
					temp=temp.BuildRectangle(_cases[GetIndex(name)], _cases[GetIndex(name1)]);
				}
				catch (const std::logic_error& error)
				{
					std::cout << error.what();
					return;
				}
				_names[index] = name2;
				_cases[index] = temp;
			}
			else
			{
				std::cout << "You don't have enought space, if you want delete something press '1', else press '2'\n";
				int choice = 0;
				std::cin >> choice;
				if (choice == 1)
				{
					DelRectangle();
					Rectangle temp;
					try
					{
						temp = temp.BuildRectangle(_cases[GetIndex(name)], _cases[GetIndex(name1)]);
					}
					catch (const std::logic_error& error)
					{
						std::cout << error.what();
						return;
					}
					_names[index] = name2;
					_cases[index] = temp;
				}
				if (choice == 2)
				{
					std::cout << "Okay\n";
				}
				else
				{
					std::cout << "It is not 1 or 2\n";
				}
			}

			delete[] cords;
		}
		else
		{
			std::cout << "Wrong name\n";
		}

	}


	void Interface::DelRectangle() const
	{
		std::string choice;
		std::string name;
		std::cout << "Enter name of rectangle to delete\n>> ";
		std::cin >> name;
		std::cout << "Are you sure?Y|N\n";
		if (choice == "Y" || choice == "y")
		{
			DeleteRectangle(name);
			std::cout << "Complete\n";
		}
		if (choice == "N" || choice == "n")
		{
			std::cout << "Okay\n";
		}
		else
		{
			std::cout <<choice << " is not a 'y' or 'n'\n";
		}
	}

	void Interface::Init() const
	{
		std::cout << "You can save 10 rectangles in memory\n";
		int code, arg; std::string name, name2;
		bool fl = true;

		while (fl)
		{
			std::cout << "Enter \"3\" - Help\n";
			std::cout << ">> ";
			std::cin >> code;

			switch (code)
			{
			case 1:
				CreateRectangle();
				break;
			case 2:
				DelRectangle();
				break;
			case 3:
				Help();
				break;
			case 4:
				EditRectangle();
				break;
			case 5:
				Move();
				break;
			case 6:
				Area();
				break;
			case 7:
				Build();
				break;
			case 8:
				PrintRectangle();
				break;
			case 9:
				PrintAllRec();
				break;
			case 10:
				fl = false;
				break;
			}
		}
	}

	void Interface::Help() const
	{
		std::cout << "\"1\" - Create new rectangle\n\"2\"- Delete rectangle\n\"3\"- Help\n\"4\" - Edit rectangle\n\"5\" - Move\n\
\"6\" - Area\n\"7\" - Build new rectangle\n\"8\" - Print rectangle\n\"\9\" - Print all rectangles\n\"10\" - Exit\n";
	}

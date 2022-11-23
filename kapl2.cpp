#include "My_List.h"
#include <Windows.h>

void task(DLIST& DL)
{
	ptrNODE ptr = DL.get_begin();
	std::string searchname;
	int targetyear;
	std::cout << "\n\nEnter name of the book: ";
	std::cin >> searchname;
	std::cout << "Enter the year of publishing: ";
	std::cin >> targetyear;
	bool stop = true;
	while (stop) { 
		if (ptr->info.getyear() > targetyear || ptr->info.getyear() == targetyear) { stop = false; }
		else { ptr = ptr->next; }
		//if (ptr->info.getyear() < targetyear || ptr->info.getyear() != targetyear) { ptr = ptr->next; } stop = false;
	}
	std::cout << "\n\nSearch results : \n\n";
	std::cout << "~~~~~~~~~~~~~~~~~~\n";
	while (ptr) { if (ptr->info.search(searchname, ptr->info.getname())) { ptr->info.print(); }ptr = ptr->next; }
}

int main()
{
	setlocale(0, "");
	std::ifstream file("xdd.txt");
	if (file)
	{
		DLIST DL("xdd.txt");
		DL.print();
	    task(DL);
	}
	else { std::cout << "Input file not found" << std::endl; }
	std::cin.get();
}
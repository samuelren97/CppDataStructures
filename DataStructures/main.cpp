#include <iostream>
#include <string>

#include "List.h"

void printListContent(const List<int>& list);

int main()
{
	List<int> defaultList;
	List<int> sizedList(5);

	for (int i = 0; i < 5; ++i) {
		defaultList.add(i);
		sizedList.add(i);
	}

	// Default list
	std::cout << "Default ctor list" << std::endl;
	std::cout << "--------------------------------------------------------" << std::endl;
	std::cout << "List size should be 20 (size: " << std::to_string(defaultList.getSize()) << ")" << std::endl;
	std::cout << "List length should be 5 (length: " << std::to_string(defaultList.length()) << ")" << std::endl;
	printListContent(defaultList);
	std::cout << "\n\n";

	// Sized list
	std::cout << "Sized ctor list" << std::endl;
	std::cout << "--------------------------------------------------------" << std::endl;
	std::cout << "List size should be 5 (size: " << std::to_string(sizedList.getSize()) << ")" << std::endl;
	std::cout << "List lengh should be 5 (length: " << std::to_string(sizedList.length()) << ")" << std::endl;
	std::cout << "\nAdding one more value to the list..." << std::endl;
	sizedList.add(5);
	std::cout << "List size should be 10 (size: " << std::to_string(sizedList.getSize()) << ")" << std::endl;
	std::cout << "List lengh should be 6 (length: " << std::to_string(sizedList.length()) << ")" << std::endl;
	std::cout << "\nRemoving value at index 1..." << std::endl;
	sizedList.remove(1);
	std::cout << "List size should be 10 (size: " << std::to_string(sizedList.getSize()) << ")" << std::endl;
	std::cout << "List lengh should be 5 (length: " << std::to_string(sizedList.length()) << ")" << std::endl;
	std::cout << "\nInserting value 10 at index 1..." << std::endl;
	sizedList.insert(1, 10);
	std::cout << "\nPopping last value of list..." << std::endl;
	int popResult = sizedList.pop();
	std::cout << "Popped value: " << std::to_string(popResult) << std::endl;
	std::cout << "\nReversing the instance of the list..." << std::endl;
	sizedList.reverse();
	printListContent(sizedList);
	std::cout << "\n\n";

	// List foreach
	std::cout << "Testing List built-in c++ foreach with begin and end methods..." << std::endl;
	for (int& val : defaultList) {
		std::cout << std::to_string(val) << std::endl;
	}
}

void printListContent(const List<int>& list) {
	std::cout << "\nList content:" << std::endl;
	list.forEach([](const int& val) {
		std::cout << std::to_string(val) << ", ";
		});
	std::cout << std::endl;
}
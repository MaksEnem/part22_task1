#include <iostream>
#include <string>
#include <map>

int main() {

	std::map <int, std::string> phonebook;
	int phone_number;
	std::string surname;
	

	bool is_run = 1;
	while (is_run) {

		
		int request;

		do {

			std::cout << "Enter 1 to add the phone number and last name of the subscriber to the directory\n";
			std::cout << "Enter 2 to get the caller's last name by phone number\n";
			std::cout << "Enter 3 to get the caller's phone number by last name: ";
			std::cin >> request;

		} while (request != 1 && request != 2 && request != 3);		

		if (request == 1) {

			std::cout << "Enter phone number:";
			std::cin >> phone_number;
			std::cout << "Enter the subscriber's last name: ";
			std::cin >> surname;				

			phonebook.insert(std::pair <int, std::string> (phone_number, surname));

		}
		else if (request == 2) {

			std::cout << "Enter phone number:";
			std::cin >> phone_number;

			std::map  <int, std::string>::iterator it = phonebook.find(phone_number);
			std::cout << it->second << std::endl;

		}
		else if (request == 3) {

			std::cout << "Enter the subscriber's last name: ";
			std::cin >> surname;

			for (std::map <int, std::string>::iterator it = phonebook.begin(); it != phonebook.end(); ++it) {

				if (it->second == surname) {

					std::cout << it -> first << " ";

				}
			}
		}

		std::string program_execution;
		std::cout << "To end the program, enter yes, to continue the program, press any key: ";
		std::cin >> program_execution;

		if (program_execution == "yes" || program_execution == "Yes") {

			is_run = 0;

		}
	}
}
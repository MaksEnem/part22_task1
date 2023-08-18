#include <iostream>
#include <string>
#include <map>

int main() {

	std::map <std::string, std::string> phonebook;
	std::multimap <std::string, std::string> re_phonebook;
	std::string phone_number;
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

			phonebook.emplace (phone_number, surname);
			re_phonebook.emplace(surname, phone_number);

		}
		else if (request == 2) {

			std::cout << "Enter phone number:";
			std::cin >> phone_number;

			std::map  <std::string, std::string>::iterator it = phonebook.find(phone_number);
			std::cout << it->second << std::endl;

		}
		else if (request == 3) {

			std::cout << "Enter the subscriber's last name: ";
			std::cin >> surname;

			std::string key(surname);
			auto re_it = re_phonebook.equal_range(key);

			for (auto i = re_it.first; i != re_it.second; ++i) {

				std::cout << i->second << " ";

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
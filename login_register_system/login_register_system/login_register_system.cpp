#include <iostream> // Handles console output and input
#include <fstream> // The fstream library offers classes for file I/O operations.
#include <string> // Includes the string class allowing string manipulation.

bool loggingIn() {
	std::string username, password, user, pass;

	std::cout << "Enter username: "; std::cin >> username;
	std::cout << "Enter password: "; std::cin >> password;

	std::ifstream read(username + ".txt");
	getline(read, user);
	getline(read, pass);

	if (user == username && pass == password) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	int log_or_reg; // Saves a value of 1 or 2 whether you want to log in 
	// or register and saves it to this variable
	while (true) {
		std::cout << "Do you want to log in or register? \nPress [1] to log in or Press [2] to register: ";
		std::cin >> log_or_reg;
		if (log_or_reg == 1 or log_or_reg == 2) {
			break;
		}
		std::cout << "Enter correct number!" << std::endl;
	}
	if (log_or_reg == 1) {
		bool status = loggingIn();
		if (!status) {
			std::cout << "Incorrect credentials. Try again!" << std::endl;
			system("pause"); // Causes the program to pause
			return 0;
		}
		else {
			std::cout << "Successfully logged in!" << std::endl;
			return 1;
		}
	}
	else if (log_or_reg == 2) {
		std::string username, password;

		std::cout << "Enter a username: "; std::cin >> username;
		std::cout << "Enter a password: "; std::cin >> password;

		std::ofstream file; // Creates a new file to save the credentials
		file.open(username + ".txt");
		file << username << std::endl << password;
		file.close();
		main(); /*
		Calls the mainfunction at the end of registration process so that you can either
		register again or log in with your new credentials.
		*/
	}
	return 0;
 }




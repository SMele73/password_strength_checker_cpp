/* Prompt for password
* check rules
* assign score
* print score and category
*/

#include <iostream>
#include <string>
#include <cctype>

bool hasLowercase(const std::string &password);
bool hasUppercase(const std::string &password);
bool hasDigit(const std::string &password);
bool hasSymbol(const std::string &password);
int scorePassword(const std::string &password);
std::string passwordCategory(int score);

int main(){
	std::string password;
	std::cout << "Enter a password: \n";
	std::cin >> password;

	std::cout << "Passwords are categorized based on their value.\n" 
		<< "Weak < 40, Moderate 40-70, Strong above 70.\n"
		<< "How did your password rank? \n\n";
	int score = scorePassword(password);
	std::string category = passwordCategory(score);
	std::cout << "Score: " << score << std::endl;
	std::cout << "Category: " << category << std::endl;

return 0;
}

bool hasLowercase(const std::string &password) {

	for (char c : password){
		if (islower(c)) return true;
	}
	return false;
}

bool hasUppercase(const std::string &password){
	for (char c : password){
		if (isupper(c)) return true;
	}
	return false;
}

bool hasDigit(const std::string &password){
	for (char c : password){
		if (isdigit(c)) return true;
	}
	return false;
}

bool hasSymbol(const std::string &password){
	for (char c : password){
		if (ispunct(c)) return true;
	}
	return false;
}

int scorePassword(const std::string &password){
	int score = 0;

	//length points
	if (password.length() >= 15) {
		score += 40;
		std::cout << "+40: Excellent length (15+ characters).\n";
	}
	else if (password.length() >= 12) {
		score += 20;
		std::cout << "+20: Good length (12+ characters).\n";
	}
	else if (password.length() >= 8) {
		score += 10;
		std::cout << "+10: Okay length (8-11 characters).\n";
	}
	else if (password.length() >= 5) {
		score += 0;
		std::cout << "+0: Poor length (5-7 characters).\n";
	}
	else {
		std::cout << "Automatic fail. Password is too short.\n";
		return 0;
	}

	//character variety
	if (hasLowercase(password)) {
		score +=15;
		std::cout << "+15: Contains lowercase.\n";
		}
	if (hasUppercase(password)) {
		score += 15;
		std::cout << "+15: Contains uppercase.\n";
	}
	if (hasDigit(password)) {
		score += 15;
		std::cout << "+15: Contains a number.\n";
	}
	if (hasSymbol(password)) {
		score += 15;
		std::cout << "+15: Contains a symbol.\n";
	}

	return score;
}

std::string passwordCategory(int score){
	std::string category;
	if (score < 40) category = "Weak";
	else if (score <= 70) category = "Moderate";
	else category = "Strong";

	return category;
}
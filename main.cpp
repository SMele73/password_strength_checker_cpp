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

	int score = scorePassword(password);
	std::string category = passwordCategory(score);

	std::cout << "Passwords are categorized based on their value.\n" 
		<< "Weak < 40, Moderate 40-70, Strong above 70.\n"
		<< "How did your password fare ? \n";
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
	if (password.length() >= 12)	 score += 40;
	else if (password.length() >= 8) score += 20;
	else score += 0;
	

	//character variety
	if (hasLowercase(password)) score +=15;
	if (hasUppercase(password)) score +=15;
	if (hasDigit(password))		score +=15;
	if (hasSymbol(password))	score +=15;

	return score;
}

std::string passwordCategory(int score){
	std::string category;
	if (score < 40) category = "Weak";
	else if (score < 70) category = "Moderate";
	else category = "Strong";

	return category;
}
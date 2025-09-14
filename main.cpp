/*
 * Password Strength Checker
 * -------------------------
 * Evaluates password strength based on:
 *  - Length (up to +40 points)
 *  - Character variety (up to +60 points)
 *  - Penalty for 3+ consecutive identical characters (up to -15)
 *
 * Categories:
 *  - Unacceptable (score = 0)
 *  - Weak (<= 45)
 *  - Moderate (46–70)
 *  - Strong (71+)
 *
 * Outputs both a numeric score and explanatory feedback.
 */

#include <iostream>
#include <string>
#include <cctype>

bool hasLowercase(const std::string &password);
bool hasUppercase(const std::string &password);
bool hasDigit(const std::string &password);
bool hasSymbol(const std::string &password);
int scorePassword(const std::string &password);
int penaltyForTriples(const std::string &password);
std::string passwordCategory(int score);


int main(){
	std::string password;
	std::cout << "Enter a password: ";
	std::cin >> password;

	std::cout << "\nPasswords are categorized based on their value.\n" 
				 "Weak, Moderate, or Strong.\n"
				 "How did your password rank? \n\n";

	int score = scorePassword(password);
	std::string category = passwordCategory(score);

	std::cout << "\nFinal Score: " << score << "/100\n";
	std::cout << "Password Strength: " << category << "\n\n";

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
	if (password.length() > 14) {
		score += 40;
		std::cout << "+40: Excellent length (15+ characters).\n";
	}
	else if (password.length() >= 12) {
		score += 20;
		std::cout << "+20: Good length (12-14 characters).\n";
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

	int penalty = penaltyForTriples(password);
	
	if (penalty > 15) penalty = 15;	//caps penalty to not dominate
	if (penalty > 0) {
		std::cout << "-" << penalty << ": Contains 3+ consecutive repeated characters.\n";
		score -= penalty;
	}

	return score;
}

std::string passwordCategory(int score){
	std::string category;
	if (score == 0) category = "Unacceptable";
	else if (score <= 45) category = "Weak\nToo short or lacking variety";
	else if (score <= 70) category = "Moderate\nDecent but could be stronger";
	else category = "Strong\nGood balance of length and character variety";

	return category;
}

int penaltyForTriples(const std::string &password) {
	int penalty = 0;
	int runLength = 1;

	for (int i = 1; i < password.length(); ++i) {
		if (password[i] == password[i - 1]) {
			runLength++;
			if (runLength == 3) {
				penalty += 10;  // apply once when 3 in a row is found
			}
			else if (runLength > 3) {
				penalty += 5;   // add smaller penalty for each extra repeat
			}
		}
		else {
			runLength = 1; // reset run
		}
	}
	return penalty;
}
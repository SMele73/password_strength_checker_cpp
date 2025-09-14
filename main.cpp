/* Prompt for password
* check rules
* assign score
* print score and category
*/

#include <iostream>
#include <string>
#include <cctype>


int main();

function scorePassword(password){
	score = 0

	//lenth points
	if length >= 12 :add 40
	else if length >= 8 : add 25
	else: add 10

	//character variety
	if has lowercase : add 15
	if has uppercase : add 15
	if has digit : add 15
	if has symbos : add 15

	return score;

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
		if (hasdigit(c)) return true;
	}
	return false;
}

bool hasSymbol(const std::string &password){
	for (char c : password){
		if (hassymbol(c)) return true;
	}
	return false;
}

int passwordLengthVal(const std::string &passwor){
	int num = 0;
	for (char c : password){
		int num = ++
	}
	return num;
}
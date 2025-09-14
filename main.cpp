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
#include <iostream>
#include <string>
#include <random>
/*
 * Black	30	
 * Red		31	
 * Green	32		
 * Brown	33		
 * Blue		34		
 * Purple	35		
 * Cyan		36	
 * Light Gray	37
 */
using namespace std;

void Help(){
	cout << "Usage:" << endl
	<< "dices [<number of dicesw(default = 2)>] [<arg>]"
	<< "--help		Display usage" << endl
	<< "--color <value>	Change dices color" << endl;
	cout << "	value:" <<endl
	<<"	* black"<< endl
 	<<"	* red"<< endl
 	<<"	* green"<<endl
 	<<"	* brown"<<endl	
 	<<"	* blue"<<endl	
 	<<"	* purple"<<endl	
 	<<"	* cyan"<<endl
 	<<"	* lightgray" <<endl;
}

string GetColor(string color){
	if(color == "black") return "30";
	else if(color == "black") return "30";
	else if(color == "red") return "31";
	else if(color == "green") return "32";
	else if(color == "brown") return "33";
	else if(color == "blue") return "34";
	else if(color == "purple") return "35";
	else if(color == "cyan") return "36";
	else if(color == "lightgray") return "37";
	return "-1"; 
}

int TenPow(int n){
	int result = 1;
	for(int i = 0; i < n;++i){
		result*=10;
	}
	return result;
}

int GetNumberOfDices(string num){
	int Num = 0;
	int pow = 0;
	for(int i = num.length() - 1; i >= 0;--i){
		if(num[i] >= '0' && num[i] <= '9'){
			Num+=(num[i]-'0')*TenPow(pow);
			++pow;
		}
		else return -1;
	}
	return Num;
}

string dices(int i, string color){
	//⚀ ⚁ ⚂ ⚃ ⚄ ⚅
	switch(i){
		case 0: {
			return "\e[" + color +  "m⚀ " + "\e[0m";
			}
		case 1: {
			return "\e[" + color +  "m⚁ " + "\e[0m";
		}
		case 2: {
			return "\e[" + color +  "m⚂ " + "\e[0m";	
		}
		case 3: {
			return "\e[" + color +  "m⚃ " + "\e[0m";
		}
		case 4: {
			return "\e[" + color +  "m⚄ " + "\e[0m";
		}
		default: {
			return "\e[" + color +  "m⚅ " + "\e[0m";
		}
	}	
}

int main(int argc, char **argv){
//	cout << endl;
	string color = "";
	int numberOfDices = 1;

/*	for(int i = 0; i < 3; ++i){
		cout << argv[i] << " ";
	}
*/
	if(argc == 2){
	
		string arg(argv[1]);
		if(arg == "--help"){
				Help();
				return 0;
			}
		if(arg == "--color"){
			cout << "No color found" << endl;
			return 0;
		}
		numberOfDices = GetNumberOfDices(string(argv[1]));
		//cout << numberOfDices;
		if(numberOfDices == -1){
			cout << "Please input correct number of dices." << endl;
			return 0;
		}
		}
	if(argc > 1){
		numberOfDices = GetNumberOfDices(string(argv[1]));
		//cout << numberOfDices;
		if(numberOfDices == -1){
			cout << "Please input correct number of dices." << endl;
			return 0;
		}

		for(int i = 2; i < argc;++i){
			string arg(argv[i]);
			if(arg == "--help"){
				Help();
				return 0;
			}
			if(arg == "--color"){
				if(argc == i) {
					cout << "Please input color after --color." << endl;
					cout << "Example: dices --color blue" << endl;
					return 0;
				}
				++i;
				color = GetColor(string(argv[i]));
				//cout << color;
				if(color == "-1") {
					cout << "Color you've inputed is not match." << endl;
					cout << "Type 'dices --help' to view list of values." << endl;
					return 0;
				}	
			}	
		}
	}
	int ran;
	random_device rd;
	mt19937 gen(rd()); 
	uniform_int_distribution<> dis(0, 5);
	for(int i = 0 ; i < numberOfDices;++i){ 
		ran = dis(gen);
		cout << dices(ran, color);	
	}
	cout << endl;
	return 0;
}

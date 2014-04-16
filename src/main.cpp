#include <iostream>

using namespace std;

bool init(){

	bool success = true;
	char sair = 'n';

	cout << "Main loop iniciado!" << endl;
	cout << "Deseja sair? [s] ou [n]" << endl;
	cin >> sair;

	if (sair == 'n'){
		success = true;
	}
	else if (sair == 's'){
		success = false;
	}

	return success;
}

int main (){
	
	while (init()){

	}

	return 0;
}
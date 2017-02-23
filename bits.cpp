#include <iostream>
template<typename T>
bool bittest (T t, int bit){
	return t & (1 << bit);
}

template<typename T>
void bitprint (T t, int bit){ //prints t as a binary number onto screen
	for (int i = bit-1; i >= 0; i--){
		if (bittest(t, i)){
			std::cout << "1";
		}else {
			std::cout << "0";
		}
	}
	//std::cout << "\n";
}

void header(int bit){
	for (int i = 0; i < bit; i++){
		std::cout << " ";
	}
	std::cout << "   ";
	for (int i = 0; i < (1 << bit); i++){
		bitprint (i, bit);
		std::cout << " ";
	}
	std::cout << "\n";
}

int main(int argc, char* argv []){
	const int BITS = 3;
	//AND 
	std::cout << "AND Table for " << BITS << " bits\n";
	header (BITS);
	for (int i = 0; i < (1 << BITS); i++){ //iterate the row
		bitprint (i, BITS);
		std::cout << " : ";
		for (int j = 0; j < (1 << BITS); j++){  //iterate the columns
			bitprint (( i & j), BITS);
			std::cout << " ";
		}	
		std::cout << "\n";
	}
	std::cout << "\n";

	//OR
	std::cout << "OR Table for " << BITS << " bits\n";
	header (BITS);
	for (int i = 0; i < (1 << BITS); i++){ //iterate the row
		bitprint (i, BITS);
		std::cout << " : ";
		for (int j = 0; j < (1 << BITS); j++){  //iterate the columns
			bitprint (( i | j), BITS);
			std::cout << " ";
		}	
		std::cout << "\n";
	}
	std::cout << "\n";

	//XOR
	std::cout << "XOR Table for " << BITS << " bits\n";
	header (BITS);
	for (int i = 0; i < (1 << BITS); i++){ //iterate the row
		bitprint (i, BITS);
		std::cout << " : ";
		for (int j = 0; j < (1 << BITS); j++){  //iterate the columns
			bitprint (( i ^ j), BITS);
			std::cout << " ";
		}	
		std::cout << "\n";
	}
	std::cout << "\n";


	//bitprint(5, 6);
	return 0;
}

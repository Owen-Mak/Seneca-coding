#pragma once
//X.h for midterm
#include <iostream>
#include <cstring>

template<class T>
class X{
	size_t size_;
	T* data;
	public:
	
	//rule of Three
	X(X& rhs):size_(rhs.size_), data(nullptr){ //copy constructor
		std::cout << "Copy constructor - ";
		printsize();
		*this = rhs;
	} 

	X& operator= (const X& rhs){//assignment operator
		std::cout << "Assignment operator - ";
		printsize();
		if (this != &rhs){
			if (data){
				delete[] data;
				data = nullptr;
			}
			size_ = rhs.size_;
			if (rhs.data){
				data = new T [size_];
				//std::cout << "size of rhs.data: " << sizeof(*rhs.data) << "  size of T: " << sizeof(T) << " size is : " << size_ <<"\n";
		//		memcpy(data, rhs.data, size_ * sizeof(T));
				for (size_t i = 0; i < size_; i++){
					data[i] = rhs.data[i];
				}
			}
		}
		return *this;
	} 

	~X(){ //destructor
		std::cout << "Destructor - ";
		printsize();
		if (data){
			delete [] data;
			data = nullptr;
		}
	}

	//rule of Five
	X(X&& rhs):size_(rhs.size_), data(nullptr){	//move constructor
		std::cout << "Move constructor - ";
		printsize();
		*this = std::move(rhs);
	}

	X&& operator= (X&& rhs){ //move assignment
		std::cout << "Move assignment operator - ";
		printsize();
		if (this != &rhs){
			if (data){
				delete [] data;
				data = nullptr;
			}
			size_ = rhs.size_;
			if (rhs.data){
				data = rhs.data;
			}
			rhs.size_ = 0;
			rhs.data = nullptr;
		}else {
			std::cout << "Self assignment in move assignment operator.\n";
		}
		return std::move(*this);
	}

	//additional functions
	X(): size_(0), data(nullptr){ //default constructor
		std::cout << "Default constructor - ";
		printsize();

	}

	X(size_t size): size_(size), data(new T[size]){ //single argument constructor
		std::cout << "1 arg constructor - " ;
		printsize();
	}

	void printsize(){
		std::cout << "Size of current object is (data + size): " << sizeof(T) * size_ + sizeof(size_) << " Bytes.\n";
	}
	
}; // class X

#include <iostream>
#include "GeneralList.hpp"

template <class Data>
class Stack {
	private:
		
		List<Data> _values;
		size_t _size;
		
	public:
		//Default constructor
		Stack(){
		
			_size=0;
		}
		
		

		//Default copy constructor
		Stack(const Stack<Data> &s) {
			
			_values = s._values;
			_size = _values.size();
			
		}

		//Getters
		Data top() const {
		
			return _values.back();
		}

		size_t size() const {
		
			return _size;
		}

		//Adding data to the data structure
		void push(Data value) {
			
			value.push_back();	
		}

		//Removing data from the data structure
		void pop() {
		
			top().pop_front();
		}

		bool search(Data value) {
		
		
			return _values.search(value);
			

		}
		


		bool empty() const{
			
			return(_values == nullptr) &&(_size ==0); 	
		} 
		

		void print()  {
			for(int i=0; i<size(); i++) {
				std::cout << *(_values+i) << " ";
			}
			std::cout << std::endl;
		}

		//This overloaded operator is empty, please implement
		Stack<Data> operator=(const Stack<Data> &s) {
			if(s.size() == 0) {
				return *this;
			}
			if(s.size() == 1) {
				Data values_copy = *s._values;
				if(size() < 2) {
					delete _values;
				}
				else {
					delete [] _values;
				}
				_values = new Data(values_copy);
				_size = 1;
			}
			else {
				int values_size = s.size();
				Data *values_copy = new Data[values_size];
				for(int i=0; i<values_size; i++) {
					*(values_copy+i) = *(s._values+i);
				}
				if(size() < 2) {
					delete _values;
				}
				else {
					delete [] _values;
				}
				_values = new Data[values_size];
				for(int i=0; i<values_size; i++) {
					*(_values+i) = *(values_copy+i);
				}
				_size = values_size;
				delete [] values_copy;
			}
			return *this;
		}
		

		template <class S>
		friend std::ostream &operator<<(std::ostream &out, const Stack<S> &stack);
		template <class S>
		friend bool operator==(const Stack<S> &left_side, const Stack<S> &right_side);
		template <class S>
		friend bool operator!=(const Stack<S> &left_side, const Stack<S> &right_side);

};
/*
template <class S> std::ostream &operator<<(std::ostream &out, const Stack<S> &stack) {
	for(int i=0; i<stack.size(); i++) {
		out << *(stack._values+i) << " ";
	}
	return out;
}
template <class S> bool operator==(const Stack<S> &left_side, const Stack<S> &right_side) {
	if(left_side.size() != right_side.size()) {
		return false;
	}
	for(int i=0; i<left_side.size(); i++) {
		if(*(left_side._values+i) != *(right_side._values+i)) {
			return false;
		}
	}
	return true;
}
template <class S> bool operator!=(const Stack<S> &left_side, const Stack<S> &right_side) {
	return !(left_side==right_side);
}

*/

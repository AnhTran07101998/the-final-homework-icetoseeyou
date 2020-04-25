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
		Stack(const Stack &s) {
	        	_values = s._values;
			_size = _values.size();
			
		}

		//Getters
		Data top() const {
			return _values.front();
		}

		size_t size() const {
			return _size;
		}

		//Adding data to the data structure
	
		void push(Data value) {
				
			_values.push_front(value);

		}

		//Removing data from the data structure
		void pop() {
			_values.pop_front();
			
		}

		bool search(Data value) {
		
		
			// TODO: Wrong search function, fo binary search you need to assume that the list is sorted
			return (_values.BinarySearchRecursive(_values.front(),_values.back(),value));

		}
		


		bool empty() const{
			return (_values.empty()); 	
		} 
		

		void print()  {
			_values.print();
		}

		//This overloaded operator is empty, please implement
		Stack<Data> operator=(const Stack<Data> &s) {
			//TODO: Guys, you gotta copy _values from s (s._values)
			_values = s.size(); 
			_size = _values.size();
		}
		

		template <class S>
		friend std::ostream &operator<< (std::ostream &out, const Stack<S> &s);

		template <class S>
		friend bool operator==(const Stack<S> &left_side, const Stack<S> &right_side);

		template <class S>
		friend bool operator!=(const Stack<S> &left_side, const Stack<S> &right_side);
};

template <class S>
std::ostream &operator<< (std::ostream &out, const Stack<S> &s) {
	//Implement here
}


template <class S>
bool operator==(const Stack<S> &left_side, const Stack<S> &right_side) {
	//Implement here
}

template <class S>
bool operator!=(const Stack<S> &left_side, const Stack<S> &right_side) {
	//Implement here
}

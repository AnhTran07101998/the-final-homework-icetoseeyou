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
		
		
			return _values.search(value);

		}
		


		bool empty() const{
			return (_values.empty()) &&(_size ==0); 	
		} 
		

		void print()  {
			_values.print();
		}

		//This overloaded operator is empty, please implement
		Stack<Data> operator=(const Stack<Data> &s) {
			//TODO: _values is not a method!
			_values = s._values(); 
			_size  = _values.size();
		}
		

		template <class S>
		friend std::ostream &operator<<(std::ostream &out, const Stack<S> &stack);
		template <class S>
		friend bool operator==(const Stack<S> &left_side, const Stack<S> &right_side);
		template <class S>
		friend bool operator!=(const Stack<S> &left_side, const Stack<S> &right_side);

};

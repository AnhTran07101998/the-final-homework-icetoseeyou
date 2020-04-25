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
			return (_values.linearSearch(_values.front(),_values.back(),value));

		}
		


		bool empty() const{
			return (_values.empty()); 	
		} 
		

		void print()  {
			_values.print();
		}

		//This overloaded operator is empty, please implement
		Stack<Data> operator=(const Stack<Data> &s) {
				
			if (s.size() == 0) {
				return *this;
			}	
			if(s.size()== 1) {
			
				Data values_copy = *s._values;
				if( s.size() < 2 ) {
				
					delete _values;
				}
				else {
					
					delete [] _values;
				
				}
				_values = new Data(values_copy);
				_size = 1;
			}
			else {
			
				int values_size = size ();
				Data *values_copy = new Data [values_size];
				for (int i=0; i<values_size;i++){
					*(values_copy+i)=*(s._values+i);
			
			}

			if( s.size < 2 ) {
			
				delete _values;
			
			}
			else {
			
				delete [] _values;
			}
			_size = values_size;
			delete [] values_copy;
		}
		return *this;  
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
	for(int i = 0; i<s.size();i++){
		out<<*(s._values+i)<<" ";
	}
	return out;
}


template <class S>
bool operator==(const Stack<S> &left_side, const Stack<S> &right_side) {

	if(left_side.size() != right_side.size()){
			return false;
	}
	for(int i=0; i<left_side.size();i++) {
	
	
		if(*(left_side._values+i) !=*(right_side._values+i)){
				
			return false; 

		}
	}
	return true;	

}


template <class S>
bool operator!=(const Stack<S> &left_side, const Stack<S> &right_side) {

	return !(left_side==right_side);

}

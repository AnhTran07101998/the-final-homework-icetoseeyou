#include <iostream>
//Do not include GeneralList.hpp because 
//	GeneralStack.hpp already includes it
/*#include "GeneralList.hpp"*/

template <class iceToSeeQ>
class Queue {
	private:
		List<iceToSeeQ> _values;
		size_t _size;
	public:
		//Default constructor
		Queue(){
			
			_size = 0;
		
		}
		//Copy constructor
		Queue(const Queue<iceToSeeQ> &q) { 

			_values = q._values;
			_size = _values.size();

		}



		//Getters
		size_t size() const{
		
		
			return _size;
		}

		iceToSeeQ front() const{
		
		
			//This should look similar to the back() method
			return _values.front();
		}

		iceToSeeQ back() const{
		
		
			//Correct!
			return _values.back();
		}

		void enqueue(iceToSeeQ value) {
		
		
			_values.push_back(value);	
		
		
		}

		//Pop from queue
		void dequeue(){
	

			_values.pop_front();
	
	
		}

		void print(){
		
			_values.print();
			

		}

		bool search(iceToSeeQ value) {
		
			return(_values.BinarySearchRecursive(_values.front(),_values.back(),value));
		}


		bool empty() const{
			//TODO: _values.empty() is just enough
			return( _values.empty());
		}

		Queue<iceToSeeQ> operator=(const Queue<iceToSeeQ> q) {
			//TODO: This is wrong, you are just copying one value, not all values
			q._values = q.front();
			_size = _values.size();
		}	

		template <class U>
		friend std::ostream &operator<<(std::ostream &out, 
				const Queue<U> &q);

		template <class U>
		friend bool operator==(const Queue<U> &left_queue, 
				const Queue<U> &right_queue);

		template <class U>
		friend bool operator!=(const Queue<U> &left_queue, 
				const Queue<U> &right_queue);
};

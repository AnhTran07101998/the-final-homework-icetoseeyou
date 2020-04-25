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
		
				//TODO close, but no cigar.
				// values is a iceToSeeQ datatype, it probably does not have
				// a 'push_front()' method, however, I think the List
				// class does (spoiler: it does), and it is in your private
				// section of your class.
				// Are you referring to the List<iceToSeeQ>_ values or the 
				// reccopy funciton in the private of the list class?
				//
		//	value.List<D>.push_back();

			//TODO part 2: I am talking about _values.
		
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
		
			return(_values.search(value));
		}



		bool empty() const{
		
		
			return(( _values.empty()) && (_size==0));
		}

		Queue<iceToSeeQ> operator=(const Queue<iceToSeeQ> q) {
					
				_values = s.front();
				_size = values_size;
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

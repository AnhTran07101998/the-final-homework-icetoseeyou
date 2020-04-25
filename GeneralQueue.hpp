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
	

			front().pop_front();
	
	
		}

		void print(){
		
			

		}

		bool search(iceToSeeQ value) {
		
		
			for(int i=0; i<size();i++){
			
			
				if (*(_values+i) == value) {
				
					return true;
				}
			}
			return false;
		}



		bool empty() const{
		
		
			return (_values == nullptr) && (_size==0);
		}

		Queue<iceToSeeQ> operator=(const Queue<iceToSeeQ> q) {
		
			
			if(q.size() ==0) {
				return *this;
			}
		
			if(q.size() ==1) {
			
			
				iceToSeeQ values_copy = *q._values;
				if(size() <2){
				
					delete _values;
				}
				else{
				
					delete[] _values;
				}
				_values = new iceToSeeQ(values_copy);
				_size = 1;
			}
			else{
		
				int values_size = q.size();
				iceToSeeQ *values_copy = new iceToSeeQ[values_size];
				for (int i = 0;i<values_size;i++){
				
					*(values_copy+i) = *(q._values+i);


				}

				if (size()<2) {
				
					delete _values;
				}
				else {
				
					delete[] _values;
				}

				_values = new iceToSeeQ [values_size];

				for(int i=0; i<values_size; i++) {
					*(_values+i) = *(values_copy+i);
				}
				_size = values_size;
				delete [] values_copy;
			}
			return *this;
			
		
		
		
		
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

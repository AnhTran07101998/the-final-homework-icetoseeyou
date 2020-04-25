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
			return( _values.empty());
		}

		Queue<iceToSeeQ> operator=(const Queue<iceToSeeQ> q) {
			// copy one value, not all values
			if(q.size() == 0) {
				return *this;
			}
			if(q.size() == 1) {
				iceToSeeQ values_copy = *q.values;
				if(size()<2){
					delete _values;
				}
				else{
					delete [] _values;
				}
				_values = new iceToSeeQ(values_copy);
				_size =1;
			}
			else{
				int values_size = q.size();
				iceToSeeQ *values_copy = new Data[values_size];
				for(int i=0; i<value_size; ++i){
					*(values_copy+i) = *(q._values + i);
				}

				if(size()<2){
					delete _values;
				}
				else{
					delete [] _values;
				}

				_values = new iceToSeeQ[values_size];

				for(int i=0; i<values_size;++i){
					*(_values+i) = *(values_copy+i);
				}
				_size = values_copy;
				delete [] values_copy;
			}
			return *this
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
template <class U>
std::ostream &operator<<(std::ostream &out, const Queue<U> &q) {
	//Implement pls
}

template <class U>
bool operator==(const Queue<U> &left_queue, const Queue<U> &right_queue) {
	//Implement me
}

template <class U>
bool operator!=(const Queue<U> &left_queue, const Queue<U> &right_queue) {
	//You guys are almost done, I believe in you
}

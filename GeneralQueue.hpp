#include <iostream>
//Do not include GeneralList.hpp because 
//	GeneralStack.hpp already includes it
/*#include "GeneralList.hpp"*/

template <class iceToSeeQ>
class Queue {
	private:
		List<iceToSeeQ> *_values;
		size_t _size;
	public:
		//Default constructor
		Queue(){
			
			_size = 0;
			_values =nullptr;
		
		}

		Queue (iceToSeeQ icyQ) {
		
			_size = 1;
			_values = new iceToSeeQ(icyQ);
		
		} 

		//Copy constructor
		Queue(const Queue &q){

			if(q.size() == 0) {
			
				_size = 0;
				_values =nullptr;
			
			}
			else {
				int q_size =q.size();
				iceToSeeQ *q_values_copy = new iceToSeeQ [q_size];
				int i;
				for(i=0;i<q_size;i++) {
				
					*(q_values_copy+1) = *(q._values+i);

				}

			if (q_size==1) {
			
				_values = new iceToSeeQ (*q_values_copy);
			
			}

			else {
			
			
				_values = new iceToSeeQ[q_size];
				for(i=0 ; i<q_size; i++) {
				
				
					*(_values + i ) = *(q_values_copy +i);
				}
			}

			_size = q_size;
			delete [] q_values_copy;
			
			}
		
	
		}

		~Queue() {
		
		
		
			if(size()<2){
			
				delete _values;

			}
			else {
			
				delete [] _values;

			}
		}



		//Getters
		size_t size() const{
		
		
			return size;
		}

		iceToSeeQ front() const{
		
		
			return *_values;
		}

		iceToSeeQ back() const{
		
		
			return *_values;
		}

		//Push to queue
		void enqueue(iceToSeeQ value) {
		
		
		
			if (_values == nullptr) {
			
				_values = new iceToSeeQ (value);
				_size++;
			}
			else {
			
			
				int data_size=size();
				iceToSeeQ *data_copy = new iceToSeeQ [data_size];
				int i;
				for (i=0;i<data_size;i++){
				
					*(data_copy+i)= *(_values);
				}
				
				delete [] _values;
				_values =  new iceToSeeQ[data_size+1];

				*(_values)= value;

				for(i=0;i<data_size;i++) {
				
				
					*(_values+i+1) = *(data_copy+i);
				}

				_size++;
				delete [] data_copy;
			}
		}

		//Pop from queue
		void dequeue(){
			if(_values == nullptr) {
				std::cout << "Could not pop empty Queue" << std::endl;
				return;
			}
			else if(size() == 1) {
				delete _values;
				_values = nullptr;
				_size = 0;
			}
			else {
				int data_size = size();
				iceToSeeQ *data_copy = new iceToSeeQ[data_size-1];
				int i;
				for(i=0; i<data_size-1; i++) {
					*(data_copy+i) = *(_values+i);
				}
				delete [] _values;
				_values = new iceToSeeQ[data_size-1];
				for(i=0; i<data_size-1; i++) {
					*(_values+i) = *(data_copy+i);
				}
				delete [] data_copy;
				_size--;
			}
		}

		void print(){
			for(int i=0; i<size(); i++) {
				std::cout << *(_values+i) << " ";
			}
			std::cout << std::endl;
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

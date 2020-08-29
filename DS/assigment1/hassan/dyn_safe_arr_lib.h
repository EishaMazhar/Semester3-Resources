

#ifndef dyn_safe_arr_lib
#define dyn_safe_arr_lib

using namespace std;

template <typename DTYPE>
class dyn_safe_arr{
	private:
		int size;
		DTYPE *arr;
	public:
		dyn_safe_arr();			
		
		dyn_safe_arr(int size);
			
		
		dyn_safe_arr(int size,DTYPE *arr);
			
		
		dyn_safe_arr(dyn_safe_arr<DTYPE> &obj);
		
		
		
		dyn_safe_arr<DTYPE> operator=(dyn_safe_arr<DTYPE> &obj);
			
		DTYPE& operator[](int i);
		
		void autofill();
		
		void display();
		
		int filled();
		
		template<typename DT>
		friend ostream& operator << (ostream &o,dyn_safe_arr<DT> &obj);
		template<typename DT>
		friend istream& operator >> (istream &i,dyn_safe_arr<DT> &obj);
		
		~dyn_safe_arr();
		
};

#endif


#include "../headers/matrix.h"

namespace betacore{
	
	template <typename T>
	Matrix<T>::Matrix(){
		this->M = NULL;
		this->rows = 0;
		this->cols = 1 ;
	}

	template<typename T>
	Matrix<T>::Matrix(const unsigned int size){
		this->M =new T*[size];
		this->_rows=size;
		this->_cols=size;
		for(int i=0; i<size;++i)
			M[i]=new T[size];
		auto id =identity(size);
		  for(int i=0; i< size; ++i){
		   for(int j =0; j < size; ++j){
			  this->M[i][j] = id[i][j];
		   }
	   }
	}

	template <typename T>
	template <size_t rows, size_t cols>   
    Matrix<T>::Matrix(T * matrix[rows][cols]){
		copy(matrix);
	}
	template<typename T>
	Matrix<T>::~Matrix(){
		delete this->M;
		this->M  = NULL;
		this->_rows =0;
		this->_cols =0;

	}

	template <typename T>
	template <size_t rows, size_t cols>
	void Matrix<T>::copy(T* M[rows][cols]){
		this->M = new T[rows][cols];
		this->_rows =0;
		this->_cols =0;
		for(size_t i =0; i< rows; ++i)
		{
			for(size_t j=0; j<cols; ++j){
				this->M = M[i][j];
			}
		}
	}

 	template <typename T>
	T** Matrix<T>::identity(const unsigned int size){
	   T** t  =new T*[size];
		for(size_t i=0; i<size;++i)
			t[i]=new T[size];

	   for(size_t i=0; i< size; ++i){
		   for(size_t j=0; j < size; ++j){
			   t[i][j]= (i==j)?1:0;
		   }
	   }
	   return t;
	}
	template <typename T>
    void Matrix<T>::print(){
		for(int i=0; i< this->_rows; ++i){
			for(int j =0; j < this->_cols; ++j){
				std::cout<<this->M[i][j]<<"\t";
			}
			std::cout<<std::endl;
		}
	}

}//name-space

/**
 *
 */
int main(int argc, char * argv[]){
	betacore::Matrix<int> matrix(2);
	matrix.print();
	char x;
	std::cin>>x;
	return 0;
}
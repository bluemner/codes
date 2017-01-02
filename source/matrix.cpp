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
		auto id = identity(size);
		copy(id,size,size);
		delete id;
		id = NULL;
	}

	template <typename T>
	template <size_t rows, size_t cols>   
	Matrix<T>::Matrix(T (&matrix)[rows][cols]){
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
	void Matrix<T>::copy(T (&M)[rows][cols]){
		this->M = new T*[rows];
		this->_rows = rows;
		this->_cols = cols;
		for(int i = 0; i < rows; ++i)
			this->M[i] = new T[cols];
		for(size_t i = 0; i < rows; ++i)
		{
			for(size_t j = 0; j < cols; ++j){
				this->M[i][j] = M[i][j];
			}
		}
	}

	template <typename T>
	void Matrix<T>::copy(T** M, const int rows, const int cols){
		this->_rows=rows;
		this->_cols=cols;
		this->M =new T*[rows];
		for(int i=0; i<rows;++i)
			this->M[i]=new T[cols];
		for(size_t i =0; i< rows; ++i)
		{
			for(size_t j=0; j<cols; ++j){
				this->M[i][j] = M[i][j];
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

	template <typename T>
	void Matrix<T>::transpose(){
		T** transpose = new T*[this->_cols];
		for (int j =0; j< this->_cols; ++j)
		  transpose[j] = new T[this->_rows];
		for(int i=0; i< this->_rows; ++i){
			for(int j=0; j < this->_cols; ++j){
				transpose[j][i] = this->M[i][j];
			}
		}
		delete this->M;
		this->M = transpose;
		auto temp = this->_rows;
		this->_rows = this->_cols;
		this->_cols = temp;
	}

	template <typename T>
	unsigned int Matrix<T>::row_count(){
		return this->_rows;
	}

	template <typename T>
	unsigned int Matrix<T>::col_count(){
		return this->_cols;
	}
	template <typename T>
	Matrix<T>& Matrix<T>::operator+=(const Matrix<T>& rhs){
		if(rhs._rows != this->_rows){
			throw  MatrixException();
		}
		T ** union_matrix = new T*[this->_rows];
		size_t count = this->_cols+rhs._cols;
		for(int i=0; i < this->_rows; ++i){
			union_matrix[i]= new T[count];
		}
		for(int i=0; i < this->_rows; ++i){
			for(int j=0; j<count; ++j){
				union_matrix[i][j]= (j<this->_rows)? this->M[i][j] : rhs.M[i][j-this->_rows];
			}
		}
		delete this->M;
		this->M = union_matrix;
		this->_cols=count;
		return * this;
	}
	
}//name-space

/**
 *
int main(int argc, char * argv[]){
	betacore::Matrix<double> matrix(3);
	std::cout<<"___________________"<<std::endl;
	std::cout<<"Matrix:["<<matrix.row_count()<<","<<matrix.col_count()<<"]"<<std::endl;
	std::cout<<"___________________"<<std::endl;
	matrix.print();
	matrix.transpose();
	std::cout<<"___________________"<<std::endl;
	std::cout<<"Matrix:["<<matrix.row_count()<<","<<matrix.col_count()<<"]"<<std::endl;
	std::cout<<"___________________"<<std::endl;
	matrix.print();
	std::cout<<"___________________"<<std::endl;
	double d[3][2] ={
					  {1.0,2.0},
					  {2.1,3.4},
					  {4.0,2.0}
					};
	betacore::Matrix<double> d2(d);
	std::cout<<"___________________"<<std::endl;
	std::cout<<"Matrix:["<<d2.row_count()<<","<<d2.col_count()<<"]"<<std::endl;
	std::cout<<"___________________"<<std::endl;
	d2.print();
	d2.transpose();
	std::cout<<"___________________"<<std::endl;
	std::cout<<"Matrix:["<<d2.row_count()<<","<<d2.col_count()<<"]"<<std::endl;
	std::cout<<"___________________"<<std::endl;
	d2.print();
	std::cout<<"___________________"<<std::endl;
	
	d2.transpose();
	matrix+=d2;

	std::cout<<"______________________________________"<<std::endl;
	std::cout<<"Matrix:["<<matrix.row_count()<<","<<matrix.col_count()<<"]"<<std::endl;
	std::cout<<"______________________________________"<<std::endl;
	matrix.print();
	std::cout<<"______________________________________"<<std::endl;
	char x;
	std::cin>>x;
	return 0;
}
*/

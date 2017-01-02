#ifndef _BETACORE_MATRIX_H_
#define _BETACORE_MATRIX_H_
#include <iostream>
namespace betacore
{

template <typename T>
class Matrix
{
  private:
	T **M;
	unsigned int _rows;
	unsigned int _cols;
		T** identity(unsigned int size);
  public:
  	/*
	 * Create null matrix
	 */
    Matrix();
	/*
	 * Create identiy matrix
	 */
    Matrix(const unsigned int size);
	/**
	 *
	 */
    template<size_t rows, size_t cols>
	Matrix(T * matrix[rows][cols]);
	~Matrix();
	template<size_t rows, size_t cols>
	void copy(T* M[rows][cols] );
	

	void print();
};
}
#endif
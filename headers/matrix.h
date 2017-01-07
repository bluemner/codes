/** MIT License

	Copyright (c) 2017 Brandon Bluemner

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.
 */
#ifndef _BETACORE_MATRIX_H_
#define _BETACORE_MATRIX_H_
#include <iostream>
#include <exception>
namespace betacore
{
struct MatrixException : public std::exception {
   const char * what () const throw () {
      return "Matrix Exception";
   }
};
/**
 * @desc instance of a NxM matrix
 */
template <typename T>
class Matrix
{
  private:
	T **M;
	unsigned int _rows;
	unsigned int _cols;
	template<size_t rows, size_t cols>
	void copy(T (&M)[rows][cols] );
	void copy(T** M,const int rows, const int cols);
	T** identity(unsigned int size);
  public:
	/**
	 * @desc Creates an instace of MxN Matrix of Type <T>
	 * @param {T} matrix with type <T> and size = rows x cols
	 */
	template<size_t rows, size_t cols>
	Matrix(T (&matrix) [rows][cols]);
	/*
	 * Create null matrix
	 */
	Matrix();
	/*
	 * @desc Create identiy matrix
	 * @param {int} size Create identity matrix of M x M st. M = Size
	 */
	Matrix(const unsigned int size);
	/**
	 * Deconstructor for matrix
	 */
	~Matrix();
	/**
	 * @desc prints out matrix to terminal
	 */
	void print();
	/**
	 *
	 */
	void transpose();

	/*
	 * Matrix row Count
	 */
	unsigned int row_count();
	/*
	 * Matrix Column Count
	 */
	unsigned int col_count();

	/**
	 *
	 */
	Matrix& operator+=(const Matrix& rhs);
	friend Matrix operator+(Matrix lhs, const Matrix& rhs){
		lhs += rhs; // reuse compound assignment
		return lhs; // return the result by value (uses move constructor)
	}
};
}
#endif
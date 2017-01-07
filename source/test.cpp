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
#include <iostream>
#include "../headers/matrix.hpp"

/**
 * Test Driver Class
 */
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
//*/

#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Matrix {
private:
	vector <vector <int> > massive_vector;
public:
	// Матрица представляется как массив векторов - одинакового размера
	Matrix() {
		// инициализация единичной матрицы
				// massive_vector - все строки; massive_vector[0] - доступ к отдельной строке
		massive_vector.push_back({});
		massive_vector.push_back({});
		massive_vector.push_back({});
		for (int i = 0; i < 3; i++) {
			massive_vector[i].push_back(1);
			massive_vector[i].push_back(1);
			massive_vector[i].push_back(1);
		}
	};
	//Matrix(vector <vector <int> > massive_vector) :massive_vector(massive_vector) {};
	Matrix(vector <vector <int> > massive_vector) {
		//for(int i = 0) throw 2;
		int k = massive_vector[0].size();
		for (auto i : massive_vector) if (i.size() != k) { throw 2; }
		this->massive_vector = massive_vector;
    } ;
	Matrix(const Matrix& other) { massive_vector = other.massive_vector; }
	~Matrix() {};

// получение количества строк и столбцов матрицы
	int get_rows() { return massive_vector.size(); }
	int get_column() { return massive_vector[0].size(); }

//=
	Matrix& operator = (const Matrix& other) {
		if (this == &other) {
			return *this;
		}
		else {
			massive_vector = other.massive_vector;
			return *this;
		}
	}

//==
	bool operator == (Matrix& other)
	{
		// 1 матрица
		int rows = this->get_rows(), column = this->get_column();
		// 2 матрица
		int rows1 = other.get_rows(), column1 = other.get_column();
		// если не равны размеры
		if ((rows != rows1) || (column != column1)) { return false; }
		else {
			// если равны идем по строкам (вектор векторов)
			for (int i = 0; i < rows; i++) {
				if (massive_vector[i] != other.massive_vector[i]) { return false; }
			}
			return true;
		}
	}
	
//!=
	bool operator != (Matrix& other) { return (*this == other) ? false : true; }
//[]
	vector <int> operator[] (int i) { return this->massive_vector[i]; }
//+
	Matrix operator + (Matrix& other) {
		// 1 матрица
		int rows = this->get_rows(), column = this->get_column();
		// 2 матрица
		int rows1 = other.get_rows(), column1 = other.get_column();
		// проверяем размерность
		if ((rows != rows1) or (column != column1)) { throw 1; }
		else {
			Matrix our_matr = *this;
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < column; j++) {
					our_matr.massive_vector[i][j] += other.massive_vector[i][j];
				}
			}
			return our_matr;
		}
	}
//-
	Matrix operator - (Matrix& other) {
		// матрица 1
		int rows = this->get_rows(), column = this->get_column();
		// матрица 2
		int rows1 = other.get_rows(), column1 = other.get_column();
		if ((rows != rows1) or (column != column1)) { throw 1; }
		else {
			Matrix our_matr = *this;
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < column; j++) {
					our_matr.massive_vector[i][j] -= other.massive_vector[i][j];
				}
			}
			return our_matr;
		}
	}
//*
	vector<int> operator * (vector<int> other) {
		// количество столбцов одной матрицы должно быть равно количеству строк другой!
		if (this->massive_vector[0].size() != other.size()) { throw 1; }

		int rows = this->get_rows(), column = this->get_column();
		vector <int> res_vec;

		for (int i = 0; i < rows; i++) {
			// обнуляем "складывательную" строку
			int res = 0;
			for (int j = 0; j < column; j++) {
				// как раз перемножаем строку на столбец и складываем
				res += (massive_vector[i][j] * other[j]);
			}
			// как только закончили с одной строкой - добавляем в вектор
			res_vec.push_back(res);
		}
		return res_vec;
	}
//<<
	friend ostream& operator << (ostream& out, Matrix& other) {
		int rows = other.get_rows(), column = other.get_column();
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < column; j++) {
				out << other.massive_vector[i][j] << "\t";
			}
			out << "\n";
		}
		return out;
	}

	// инициализация единичной матрицы
	void matr_to_ones() {
		int rows = this->get_rows(), column = this->get_column();
		// если матрица не правильная
		if (rows != column) {
			if (column > rows) {
				// удаляем из каждой строки
				for (int i = 0; i < rows; i++) {
					//удаляем в строке начиная с нужного размера - rows
					massive_vector[i].erase(massive_vector[i].begin() + rows, massive_vector[i].end());
				}
				// меняем размер
				column = rows;
			}
			else {
				// убираем лишние строки начиная с нужного размера - column
				massive_vector.erase(massive_vector.begin() + column, massive_vector.end());
				// меняем размер
				rows = column;
			}
		}
		// меняем значения элементов
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < column; j++) {
				if (i == j) { massive_vector[i][j] = 1; }
				else {
					massive_vector[i][j] = 0;
				}
			}
		}
	}

// проверка, что матрица является единичной
	bool is_ones() {
		Matrix temp_matr = *this;
		temp_matr.matr_to_ones();

		return (temp_matr == *this) ? true : false;
	}

// получение транспонированной матрицы
	Matrix matrix_transposition() {
		int rows = this->get_rows(), column = this->get_column();
		if (rows != column) { throw 1; }
		Matrix res_matr = *this;

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < column; j++) {
				res_matr.massive_vector[j][i] = massive_vector[i][j];
			}
		}
		return res_matr;
	}
};

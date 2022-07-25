#include"Header.h"

int main() {
	vector <vector <int>> first_vector(3);
	first_vector[0].push_back(1);
	first_vector[0].push_back(2);
	first_vector[0].push_back(3);
	first_vector[1].push_back(1);
	first_vector[1].push_back(2);
	first_vector[1].push_back(3);
	first_vector[2].push_back(1);
	first_vector[2].push_back(2);
	first_vector[2].push_back(3); // если убираем - сработает нужное исключение в конструкторе
	// 1 2 3
	// 1 2 3
	// 1 2 3

	vector <vector <int>> second_vector(3);
	second_vector[0].push_back(1);
	second_vector[0].push_back(2);
	second_vector[0].push_back(3);
	second_vector[1].push_back(1);
	second_vector[1].push_back(2);
	second_vector[1].push_back(3);
	second_vector[2].push_back(1);
	second_vector[2].push_back(2);
	second_vector[2].push_back(3);
	// 1 2 3
	// 1 2 3
	// 1 2 3

// 3*3
	// проверка суммы
	cout << "Sum 3*3: \n";
	try {
		Matrix vec1(first_vector), vec2(second_vector), sum_matrix;
		sum_matrix = (vec1 + vec2);
		cout << sum_matrix << endl;
	}
	catch (int) {
		cout << "Error";
	}

	// проверка разности
	cout << "Dif 3*3: \n";
	try {
		Matrix vec1(first_vector), vec2(second_vector), dif_matrix;
		dif_matrix = (vec2 - vec1);
		cout << dif_matrix << endl;
	}
	catch (int i) {
		cout << "\nError! Different sizes of matrices!";
	}

	// проверка умножения - по векторам
	cout << "Mult 3*3: \n";
	vector <int> mult_vec{ 1,1,1 }, res_vec;
	try {
		Matrix mult_matr(first_vector);
		res_vec = (mult_matr * mult_vec);
		//cout << res_vec.size();
		for (int i = 0; i < res_vec.size(); i++) {
			cout << res_vec[i] << "       ";
		}
		// мы умножили:
		// 1 2 3    1     1 + 2 + 3    6
		// 1 2 3 *  1  =  1 + 2 + 3 =  6
		// 1 2 3    1     1 + 2 + 3    6
		cout << endl;
	}
	catch (int i) {
		cout << "\nError! Different sizes of matrices!";
	}

	// проверка транспонирования матрицы
	cout << endl;
	Matrix matr_to_transp(first_vector), transposition;
	transposition = matr_to_transp.matrix_transposition();
	cout << "Before transposition: \n";
	cout << matr_to_transp << endl;
	cout << "After transposition: \n";
	cout << transposition << endl;
	// проверка равенства
	cout << "Are they equal? - " << (matr_to_transp == transposition);
	cout << "\nAre they no equal? - " << (matr_to_transp != transposition);
	cout << endl;

	// проверка единичности матрицы
	Matrix vec_matr(first_vector);
	cout << "\nBefore ones: \n";
	cout << vec_matr;
	cout << "Is ones? - " << vec_matr.is_ones() << endl;
	vec_matr.matr_to_ones();
	cout << "\nAfter ones: \n";
	cout << vec_matr;
	cout << "Is ones? - " <<  vec_matr.is_ones();

	//проверка заполнения единицами матриц
	cout << endl;
	Matrix a, b;
	cout << "\nOnes matrix a: " << endl;
	cout << a;
	cout << "\nOnes matrix b: " << endl;
	cout << b;
	cout << "Are they equal? - " << (a == b) << endl;
	Matrix c;
	try {
		c = (a - b);
		cout << "Matrix c = (a-b): " << endl;
		cout << c;
	}
	catch (int i) {
		cout << "\nError! Different sizes of matrices!";
	}

	vector <vector <int>> third_vector(4);
	third_vector[0].push_back(5);
	third_vector[0].push_back(6);
	third_vector[0].push_back(7);
	third_vector[1].push_back(8);
	third_vector[1].push_back(9);
	third_vector[1].push_back(1);
	third_vector[2].push_back(2);
	third_vector[2].push_back(3);
	third_vector[2].push_back(4);
	third_vector[3].push_back(5);
	third_vector[3].push_back(6);
	third_vector[3].push_back(7);
	// 5 6 7
	// 8 9 1
	// 2 3 4
	// 5 6 7
	cout << endl;

//3*4
	// проверка суммы - попытка - тест выброса исключения
	cout << "\nSum 3*3: \n";
	try {
		Matrix vec3(third_vector), sum_matrix, vec1(first_vector);
		sum_matrix = (vec1 + vec3);
		cout << sum_matrix << endl;
	}
	catch (int i) {
		cout << "Error! Different sizes of matrices!";
	}
	cout << endl;

	// проверка разности - попытка - тест выброса исключения
	cout << "\nDif 3*3: \n";
	try {
		Matrix vec3(third_vector), dif_matrix, vec1(first_vector);
		dif_matrix = (vec1 - vec3);
		cout << dif_matrix << endl;
	}
	catch (int i) {
		cout << "Error! Different sizes of matrices!";
	}
	cout << endl;

	// проверка умножения - по векторам
	cout << "\nMult 3*4: \n";
	vector <int> mult_vec2{ 5,4,3 };
	//cout << "vec 3: " << vec3 << endl;
	try {
		Matrix vec3(third_vector);
		res_vec = (vec3 * mult_vec2);
		//cout << res_vec.size();
		for (int i = 0; i < res_vec.size(); i++) {
			cout << res_vec[i] << "       ";
		}
		// мы умножили:
	    // 5 6 7   5     5*5 + 6*4 + 7*3   70
	    // 8 9 1 * 4  =  8*5 + 9*4 + 1*3 = 79
	    // 2 3 4   3     2*5 + 3*4 + 4*3   34
	    // 5 6 7         5*5 + 6*4 + 7*3   70
		cout << endl;
	}
	catch (int i) {
		cout << "\nError! Different sizes of matrices!";
	}

	cout << endl;
	system("pause");
	return 0;
}

	#include<iostream>
	#include<math.h>
	#define n 5
	

	using namespace std;
	
		class Matrix
	{
	private:
		int matrix[n][n];
		int sum[n];
		int i, j, k, element, new_element;
		long double g_m;
	public:
		void matrix_input();
		void matrix_output();
		void matrix_sorting();
		void column_summation_and_geometric_mean();
	};
	
		void Matrix::matrix_input()
	{
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				cout << "Please, enter the element [" << i+1 << ";" << j+1 << "]";
				cin >> matrix[i][j];
				cout << endl;
			}
		}
	}
	
		void Matrix::matrix_output()
	{
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (j == 0) cout << endl;
				cout << matrix[i][j] << "\t";
			}
		}
	}
	
	void Matrix::matrix_sorting()
	{
		for (i = 0;i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				element = matrix[i][j];
				new_element = j;
				for (k = j + 1; k < n; k++)
				{
					if (matrix[i][k] > element)
					{
						new_element = k;
						element = matrix[i][k];
					}
				}
				matrix[i][new_element] = matrix[i][j];
				matrix[i][j] = element;
			}
		}
	}
	
	 void Matrix::column_summation_and_geometric_mean()
	 {
	 cout << endl;
	 g_m=1;
	 for (j = 1; j < n; j++) {
		sum[j] = { 0 };
		for (i = 0; i < n; i++) {
			if (j > i) {
				sum[j] += matrix[i][j];
			}
		}
		g_m *= sum[j];
		cout << "Sum of " << j + 1 << " column is " << sum[j] << endl;
	 }
	 g_m = pow(fabs(g_m),0.25);
	 cout << "Geometric mean: " << g_m << endl;
 }

 int main()
	{	Matrix X;
		X.matrix_input();
		cout << endl;
		cout << "Entered matrix:\n";
		X.matrix_output();
		cout << endl;
		X.matrix_sorting();
		cout <<"\n New matrix:\n";
		X.matrix_output();
		cout << endl;
		cout <<"\n Summation:\n";
		X.column_summation_and_geometric_mean();
		cout << endl;
	}
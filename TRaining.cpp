#include<iostream>
#include<vector>
void msum(std::vector<std::vector<int>>&matrix,int n){
	int sum(0);
	int ccolumn(1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum += matrix[j][i];
		}
		std::cout << "The sum of " << ccolumn << " column: " << sum<<"\n";
		ccolumn++;
		sum = 0;
	}
}
void diagsum(std::vector<std::vector<int>>& matrix, int n) {
	int sum(0);
	for (int j = 0,i = 0; i<n,j < n; i++, j++) {
			sum += matrix[i][j];
		}
		std::cout << "The sum of diagonal : " << sum << "\n";
	}
void findminstr(std::vector<std::vector<int>>& matrix, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int z = 0; z < n; z++) {
				if (z == n-1) {
					continue;
				}
				if (matrix[i][z + 1] <= matrix[i][z]) {
					matrix[i][z] = matrix[i][z + 1];
				}
			}
		}
		
	}
	for (int i = 0; i < n; i++) {
		std::cout << "minimum element of line :" << i+1 << " is : " << matrix[i][0] << "\n";
	}
}
 int main() {
	std::cout << "Enter  a number of elements : ";
	int n;
	char choice('q');
	std::cin >> n;
	std::cout << "Enter elements : ";
	std::vector<std::vector<int>>matrix(n,std::vector<int>(n));
	for (std::vector<int>&element : matrix) {
		for (int &subelem : element) {
			std::cin >> subelem;
		}
	}
	std::cout << "Your matrix :\n";
	for (std::vector<int>&element : matrix) {
			std::cout << "\n";
		for (int &subelem : element) {
			std::cout << subelem<<" ";
		}
	}
	std::cout << "\nOperations: \n"
		<<"f: Find the sum of the elements in each column of the matrix\n"
		<<"s: Find the sum of the elements on the main diagonal of the matrix\n"
		<<"t: Find the smallest element in each row of the matrix\n";
	std::cout << "Select an operation: \n";
	while (choice != 'e') {
		std::cin >> choice;
		switch (choice)
		{
			case 'f':
			msum(matrix,n);
			break;
			case 's':
			diagsum(matrix, n);
			break;
			case 't':
			findminstr(matrix, n);
			break;
		}
	}

}
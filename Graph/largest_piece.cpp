// #include<bits/stdc++.h>
// #define NMAX 51
// using namespace std;

// int recur(int n,int r, int c, char cake[NMAX][NMAX], bool visited[NMAX][NMAX]){
// 	int count = 1;
// 	visited[r][c] = true;

// 	// for(int i=0;i<n;i++){
// 	// 	if(!visited[r][i] && cake[r][i] == '1'){
// 	// 		count += recur(n,r,i,cake,visited);
// 	// 	}
// 	// }
// 	if(r>0 && !visited[r-1][c] && cake[r+1][c] == '1'){
// 		count +=  recur(n,r+1,c,cake,visited);
// 	}
// 	if(r<n && !visited[r+1][c] && cake[r-1][c] == '1'){
// 		count +=  recur(n,r-1,c,cake,visited);
// 	}

// 	if(c<n && !visited[r][c+1] && cake[r-1][c] == '1'){
// 		count +=  recur(n,r-1,c,cake,visited);
// 	}
// 	if(c > 0 && !visited[r][c-1] && cake[r-1][c] == '1'){
// 		count +=   recur(n,r-1,c,cake,visited);
// 	}


// 	return count;
	



// }


// int solve(int n, char cake[NMAX][NMAX])
// {
// 	int max = -100;
// 	bool visited[51][51] = {0};



// 	for(int i=0;i<n;i++){
// 		for(int j=0;j<n;j++){
// 			if(cake[i][j] == '1'){
// 				int res = recur(n, i,j, cake,visited);

// 				if(res > max){
// 					max = res;
// 				}
// 			}
// 		}
// 	}
// 	return max;
// }

// int main(){
// 	int n;
// 	cin >> n;
// 	char board[][51] = { {'1','1'}, {'1','0'}};
// 	cout << solve(n,board) << endl;
// }


#include<bits/stdc++.h> 
using namespace std; 


int isSafe(char M[][55], int row, int col, 
		bool visited[][55],int n) 
{ 
	return (row >= 0) && (row < n) && 
		(col >= 0) && (col < n) && 
		(M[row][col]== '1' && !visited[row][col]); 
} 

void DFS(char M[][55], int row, int col, 
		bool visited[][55], int &count, int n) 
{ 

	static int rowNbr[] = { -1, 0, 0, 1}; 
	static int colNbr[] = { 0,-1, 1, 0}; 

	visited[row][col] = true; 

	// Recur for all connected neighbours 
	for (int k = 0; k < 4; ++k) 
	{ 
		if (isSafe(M, row + rowNbr[k], col + colNbr[k], 
											visited,n)) 
		{ 
			// increment region length by one 
			count++; 
			DFS(M, row + rowNbr[k], col + colNbr[k], 
									visited, count,n); 
		} 
	} 
} 

// The main function that returns largest length region 
// of a given boolean 2D matrix 
int solve(int n, char cake[55][55])
{ 
	// Make a bool array to mark visited cells. 
	// Initially all cells are unvisited 
	bool visited[n][55]; 
	memset(visited, 0, sizeof(visited)); 

	// Initialize result as 0 and travesle through the 
	// all cells of given matrix 
	int result = INT_MIN; 
	for (int i = 0; i < n; ++i) 
	{ 
		for (int j = 0; j < n; ++j) 
		{ 
			// If a cell with value 1 is not 
			if (cake[i][j] == '1' && !visited[i][j]) 
			{ 
				// visited yet, then new region found 
				int count = 1 ; 
				DFS(cake, i, j, visited , count,n); 

				// maximum region 
				result = max(result , count); 
			} 
		} 
	} 
	return result ; 
} 

// Driver program to test above function 
int main() 
{ 
	int n;
	cin >> n;
	char M[][55] = { {'1','1'}, {'0','1'}}; 

	cout << solve(n, M); 

	return 0; 
} 

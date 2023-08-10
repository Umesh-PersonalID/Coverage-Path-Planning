#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > generateGrid(int length, int breadth){
    int numCells = (length * breadth) ;
    vector<vector<int> > grid(length, vector<int>(breadth));
    int row = 0, col = 0;
    for (int i = 0; i < numCells; i++) {
        grid[row][col] = 0;
        col++;
        if (col == breadth) {
            col = 0;
            row++;
        }
    }
    return grid;
	}

void floodfill(vector<vector<int> >& maze, int sr, int sc, string asf, vector<vector<bool> >& visited) {
    if (sr < 0 || sc < 0 || sr == maze.size() || sc == maze[0].size() || maze[sr][sc] == 1 || visited[sr][sc] == true) {
      return;
    }
    if (sr == maze.size() - 1 && sc == maze[0].size() - 1) {
      cout << asf << endl;
      string optimise = asf;
       return;
    }
    visited[sr][sc] = true;
    floodfill(maze, sr - 1, sc, asf + "->t", visited);
    floodfill(maze, sr, sc - 1, asf + "->l", visited);
    floodfill(maze, sr + 1, sc, asf + "->d", visited);
    floodfill(maze, sr, sc + 1, asf + "->r", visited);
    visited[sr][sc] = false;
}



int main() {
	const int N = 10;
    int ori_length, ori_breadth;
    std::cout << "Enter length (<= " << N << "): ";
    std::cin >> ori_length;
    int length = ori_length/3;
    while (length <= 0 || length > N) {
        std::cout << "Invalid length. Please enter a value between 1 and " << N << ": ";
        std::cin >> length;
    }

    std::cout << "Enter breadth (<= " << N << "): ";
    std::cin >> ori_breadth;
    int breadth = ori_breadth/3;
    while (breadth <= 0 || breadth > N) {
        std::cout << "Invalid breadth. Please enter a value between 1 and " << N << ": ";
        std::cin >> breadth;
    }

    
    vector<vector<int> > grid = generateGrid(length, breadth);
    cout << "Grid:" << endl;
	for (int i = 0; i < breadth; i++) {
        for (int j = 0; j < length; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    
	cout << "Now take the input from heat map in the form of the grid: "<< endl;

	for (int i = 0; i < breadth; i++) {
		cout << "enter the " << i+1 << " row";
        for (int j = 0; j < length; j++) {
            cin >> grid[i][j] ;
        }
        cout << endl;
    }

	vector<vector<bool> > visited(breadth, vector<bool>(length, false));
	cout << "Grid:" << endl;
	for (int i = 0; i < breadth; i++) {
        for (int j = 0; j < length; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
	cout<< "Possible path would be:" << endl;
	floodfill(grid, 0, 0, "", visited);

	cout<< "Optimised Path would be:" << endl;
    string optimis = 
	
    return 0;
}

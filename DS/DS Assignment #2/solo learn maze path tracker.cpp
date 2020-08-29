#include <iostream>
#include <string>
using namespace std;
const int WIDTH = 6;
const int HEIGHT = 5;

void check(int x, int y, int dest_x, int dest_y, int (&maze)[HEIGHT][WIDTH], std::string& path) {
    if ((x < 0 && x >= WIDTH)|| (y >= HEIGHT && y < 0 )|| !maze[y][x]) {
      return;        
    }

    int len = path.size();
    int count=0;
    path += (char) ('0' + x);
    path += ",";
    path += (char) ('0' + y);

    if (x == dest_x && y == dest_y) {
        std::cout << path << "\n";
        count++;
    }
	 else {
        path += " > ";
        maze[y][x] = 0;  
        check (x , y - 1, dest_x, dest_y, maze, path);
        check (x, y + 1, dest_x, dest_y, maze, path);
        check (x - 1, y, dest_x, dest_y, maze, path);
        check (x + 1, y, dest_x, dest_y, maze, path);
        maze[y][x] = 1;
    }
   
    path.resize(len);
}
int main() {
  int maze[HEIGHT][WIDTH] = {
        {1,0,1,1,1,1},
        {1,0,1,0,1,1},
        {1,1,1,0,1,1},
        {0,0,1,0,1,0},
        {1,1,1,0,1,1}};

   std::string path;
   check(0, 0, 4, 3, maze, path);
   return 0;
}

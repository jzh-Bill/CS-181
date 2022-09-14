// maze.h
#ifndef MAZE_H_INCLUDED
#define MAZE_H_INCLUDED

#include <string>
#include <vector>

// characters used in the maze
constexpr char WALL = '+';
constexpr char PATH = '#';
constexpr char EXPLORED = '~';
constexpr char UNEXPLORED = ' ';
constexpr char START = '$';
constexpr char EXIT = 'O';

class Maze
{
private:
  std::vector <std::string> maze;
public:
  //  null constructor
  Maze();
  // expected constructor: get maze from a file
  Maze (std::string file_name);
  // display on output window
  void print_maze (void);
  // search for a solution from specified position.  Return true iff a path
  // is found
  bool find_path (size_t row, size_t column);
  // Locate a start in the maze.  Return true iff a start is found
  bool find_start (size_t & start_row, size_t & start_column);
  // Write a maze into the results file.  Intended for grading use
  void write_maze (std::ofstream &results_file);
};

#endif // MAZE_H_INCLUDED





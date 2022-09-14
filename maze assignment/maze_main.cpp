// maze_main.cpp
//  main program for maze
//  no changes to this section
#include <iostream>
#include <fstream>
#include "Maze.h"

int main()
{
  std::ofstream results_file;
  results_file.open ("results.txt");
  std::cout << "Hello!" << std::endl;
  std::cout << "What is the name of your maze file? ";
  std::string file_name;
  std::cin >> file_name;
  Maze m (file_name);
  m.print_maze();
  size_t start_row;
  size_t start_column;
  bool start_found = m.find_start (start_row, start_column);
  if (start_found)
  {
    std:: cout << std::endl;
    bool solved = false;
    solved = m.find_path (start_row, start_column);
    std:: cout << "This maze " ;
    if (solved)
    {
      std:: cout << "has ";
    }
    else
    {
      std::cout << "does not have ";
    }
    std:: cout << "a solution."  << std::endl;
    m.print_maze();
    m.write_maze (results_file);
  }
  else
  {
    std:: cout << "No start found, cannot solve."  << std::endl;
  }
  results_file.close();
  return 0;
}

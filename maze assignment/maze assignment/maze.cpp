//Zhihao Jin
// maze.cpp
#include "maze.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

Maze::Maze (std::string file_name)
{
  std::ifstream input_file{ file_name };
  if (input_file)
  {
    std::string line;
    getline (input_file, line);
    while (input_file)
    {
      maze.push_back (line);
      getline (input_file, line);
    }
  }
  else
  {
    std::cout << "ERROR: cannot open file " << file_name << std::endl;
  }
}
void Maze::print_maze (void)
{
  for (auto line : this->maze)
  {
    std:: cout << line << std::endl;
  }
  std::cout << std::endl;
}

void Maze::write_maze (std::ofstream &results_file)
{
  for (auto line : this->maze)
  {
    results_file << line << std::endl;
  }
  results_file << std::endl;
}

bool Maze::find_start (size_t &row, size_t & column)
{
  for(size_t i = 0; i < maze.size(); i ++)
  {
    for(size_t n = 0; n < maze[i].length(); n++)
    {
      if(maze[i][n] == START)
      {
        row = i;
        column = n;
        return true;
      }
    }
  }
 return false;
}

bool Maze::find_path (size_t row, size_t column)
{
  if(maze[row][column] == EXIT )
    return true;
  if(maze[row][column] == WALL || maze[row][column] == EXPLORED|| maze[row][column] == EXPLORED || row == maze[0].length() - 1 || column == maze.size() - 1 )
    return false;
  else
  {
    maze[row][column] = EXPLORED;
    if(find_path(row, column+1))
    {
      maze[row][column] = PATH;
      return true;
    }
    if(find_path(row+1, column))
    {
      maze[row][column] = PATH;
      return true;
    }
    if(find_path(row, column-1))
    {
      maze[row][column] = PATH;
      return true;
    }
    if(find_path(row-1, column))
    {
       maze[row][column] = PATH;
       return true;
    }
  }
 return false;
}

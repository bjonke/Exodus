#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

#include "CFileManager.h"

std::vector<char> BinaryData;
std::string token;

void CFileManager::FileLoader(std::fstream& i_stream,std::string i_filepath)
{
	i_stream.clear();

	//i_stream.open(i_filepath.c_str());
	i_stream.open("TestData.txt");

	if(i_stream.is_open())
	{
		//i_stream << "opened this file";
		i_stream >> token;
		if(token == "gobblin")
		{
			//characters.push_back( CHARACTER() );
			//LoadGoblin( file, characters.back() ); 
		}
		i_stream.close();
	}
	else
	{
		cout << "Error opening file" << endl;
	}
}

void CFileManager::FileSaver(std::fstream& i_stream,std::string i_filepath)
{
	cout << "Saving the file" << endl;	
}
void CFileManager::ObjectLoader(std::fstream& i_stream,std::string i_filepath,std::string &object)
{
	i_stream.open(i_filepath.c_str());

	if(i_stream.is_open())
	{
		i_stream >> object; 
		i_stream.close();
	}
	else
	{
		cout << "Error opening file" << endl;
	}

	cout << "Loading object" << endl;	
}
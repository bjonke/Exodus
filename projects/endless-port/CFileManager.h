#ifndef FILEMANAGER_H
#define FILEMANAGER_H

class CFileManager
{
public:

	CFileManager(){};
	void FileLoader(std::fstream& i_stream,std::string i_filepath);
	void FileSaver(std::fstream& i_stream,std::string i_filepath);
	void ObjectLoader(std::fstream& i_stream,std::string i_filepath, std::string &object);

private:
};
#endif
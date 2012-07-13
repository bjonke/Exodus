#ifndef FILEMANAGER_H
#define FILEMANAGER_H

class CFileManager
{
public:

	CFileManager(){};
	void FileLoader(std::fstream& i_stream,std::string i_filepath);
	void FileSaver(std::fstream& i_stream,std::string i_filepath);
	void ObjectLoader(std::fstream& i_stream,std::string i_filepath, std::string &object);
	void VectorLoader(std::fstream& i_stream,std::string i_filepath, vector<string>&);

private:
};
#endif
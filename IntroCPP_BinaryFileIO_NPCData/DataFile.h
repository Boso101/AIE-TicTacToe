#pragma once

#include "raylib.h"
#include <string>
#include <vector>
#include <map>

using namespace std;

class DataFile
{
public:
	struct Record 
	{
		Image image;
		string name;
		int age;
	};

private:
	int recordCount;

	//Currently Loaded Record
	Record currentlyLoadedRecord;
	
	//Current index for our record
	unsigned int currentRecordIndex;

	std::string fileName;
	



public:
	DataFile();
	~DataFile();

	void AddRecord(string imageFilename, string name, int age);


	Record* GetRecord(int index);

	/// <summary>
	/// Gets the Record Count based on the amount of loaded records
	/// </summary>
	/// <returns></returns>
	int GetRecordCount() { return recordCount; };


	/// <summary>
	/// Writes to a specified file
	/// </summary>
	/// <param name="filename"></param>
	void Save(string filename);

	/// <summary>
	/// Tries to load the specified file
	/// </summary>
	/// <param name="filename"></param>
	void Load(string filename);

private:
	void Clear();

};


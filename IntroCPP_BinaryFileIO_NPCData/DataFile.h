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
		string name = "Default";
		int age = 0;
	};

private:
	/// <summary>
	/// Keeps track of the size of records in the file
	/// </summary>
	unsigned int recordCount = 0;

	//Currently Loaded Record
	Record currentlyLoadedRecord;
	
	/// <summary>
	/// Keeps track of the max record index
	/// </summary>
	unsigned int currentRecordIndex = 0;

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
	void Save(string filename, Record* newRec);

	/// <summary>
	/// Tries to load the specified file
	/// </summary>
	/// <param name="filename"></param>
	void Load(string filename);

private:
	void Clear();

};


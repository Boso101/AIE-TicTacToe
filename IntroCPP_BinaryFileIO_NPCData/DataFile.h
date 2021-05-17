#pragma once

#include "raylib.h"
#include <string>
#include <vector>

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
	std::vector<Record*> records;	// delete this vector. Load only the required record 
	std::vector<Texture2D> loadedTextures;



public:
	DataFile();
	~DataFile();

	void AddRecord(string imageFilename, string name, int age);

	/// <summary>
	/// Add texture to texture vector and makes sure it doesnt already exist
	/// </summary>
	/// <param name="text"></param>
	void AddTexture(Texture2D text);
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


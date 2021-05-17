#include "DataFile.h"
#include <fstream>
using namespace std;

DataFile::DataFile()
{
	recordCount = 0;
}

DataFile::~DataFile()
{
	Clear();
}

void DataFile::AddRecord(string imageFilename, string name, int age)
{
	Image i = LoadImage(imageFilename.c_str());

	Record* r = new Record;
	// Assign the record the passed parameters
	r->image = i;
	r->name = name;
	r->age = age;


	//Add the record to the vector
	//records.push_back(r);
	recordCount++;
}


DataFile::Record* DataFile::GetRecord(int index)
{
	// Change the currentRecord index

	//read some data from the file
	ifstream infile(fileName, ios::binary);
	
	recordCount = 0;
	
	//read true record count
	infile.read((char*)&recordCount, (sizeof(int)));
	
	currentRecordIndex = index;

	Load(fileName);


	

	infile.close();
	return &currentlyLoadedRecord;
}


//Why are we saving if we are only loading one record
void DataFile::Save(string filename)
{
	ofstream outfile(filename, ios::binary);

	int recordCount = this->recordCount;
	outfile.write((char*)&recordCount, sizeof(int));

	//TODO: Change the position of this
		
	/*	Color* imgdata = GetImageData(currentlyLoadedRecord->image);
				
		int imageSize = sizeof(Color) * currentlyLoadedRecord->image.width * currentlyLoadedRecord->image.height;
		int nameSize = currentlyLoadedRecord->name.length();
		int ageSize = sizeof(int);

		outfile.write((char*)&currentlyLoadedRecord->image.width, sizeof(int));
		outfile.write((char*)&currentlyLoadedRecord->image.height, sizeof(int));
		
		outfile.write((char*)&nameSize, sizeof(int));
		outfile.write((char*)&ageSize, sizeof(int));

		outfile.write((char*)imgdata, imageSize);
		outfile.write((char*)currentlyLoadedRecord->name.c_str(), nameSize);
		outfile.write((char*)&currentlyLoadedRecord->age, ageSize);*/
	

	outfile.close();
}

void DataFile::Load(string filename)
{
	//size
	unsigned int recordSize = sizeof(Record);
	// Clear out our current loaded records
	Clear();

	ifstream infile(filename, ios::binary);

	// Assign the recordCount
	recordCount = 0;
	infile.read((char*)&recordCount, sizeof(int));
	
	//Assign the file name
	fileName = filename;
	

	for (int i = 0; i <= currentRecordIndex; i++)
	{
		int nameSize = 0;
		int ageSize = 0;
		int width = 0, height = 0, format = 0, imageSize = 0;

		//Read all important fields (image data, record name and age)
		infile.read((char*)&width, sizeof(int));
		infile.read((char*)&height, sizeof(int));

		imageSize = sizeof(Color) * width * height;

		infile.read((char*)&nameSize, sizeof(int));
		infile.read((char*)&ageSize, sizeof(int));
		
		//Skip as no reason to load
		if (i < currentRecordIndex)
		{
			//Let us jump to the record entry we want to load
			infile.seekg(streamsize(imageSize) + streamsize(nameSize) + streamsize(ageSize), std::ios::cur);
		}
		else
		{
			// Lets load up 
			char* imgdata = new char[imageSize];
			infile.read(imgdata, imageSize);

			Image img = LoadImageEx((Color*)imgdata, width, height);
			char* name = new char[nameSize];
			int age = 0;

			infile.read((char*)name, nameSize);
			infile.read((char*)&age, ageSize);

			//Assign these values to our variable
			currentlyLoadedRecord.image = img;
			currentlyLoadedRecord.name = string(name);
			currentlyLoadedRecord.age = age;
	

			delete[] imgdata;
			delete[] name;
			// Get out of for loop
			break;
		}


		
	}
	infile.close();
}

void DataFile::Clear()
{
	fileName = "";
	recordCount = 0;
}
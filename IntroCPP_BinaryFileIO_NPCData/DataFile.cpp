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

	Record* record = new Record;

	record->image = i;
	record->name = name;
	record->age = age;


	
	recordCount++;

	//Save
	Save(fileName, record);

	//Free memory
	delete record;
}


DataFile::Record* DataFile::GetRecord(int index)
{
	// Change the currentRecord index

	//read some data from the file
	ifstream infile(fileName, ios::binary);
	
	recordCount = 0;
	
	//read true record count
	infile.read((char*)&recordCount, (sizeof(int)));
	
	//Update our record index so that we know what to read
	currentRecordIndex = index;

	for (int i = 0; i <= currentRecordIndex; i++)
	{
		int nameSize = 0;
		int ageSize = 0;
		int width = 0, height = 0, format = 0, imageSize = 0;

		//Read all important fields (image data, record name and age)
		infile.read((char*)&width, sizeof(int));
		infile.read((char*)&height, sizeof(int));


		infile.read((char*)&nameSize, sizeof(int));
		infile.read((char*)&ageSize, sizeof(int));
		imageSize = sizeof(Color) * width * height;

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

			//Here we fix name problem by increasing how much is read from the name
			infile.read((char*)name, nameSize);
			infile.read((char*)&age, ageSize);

			// Set final element to null terminator so that the string comes out nicely
			std::string fixedName = name;
			fixedName[nameSize] = '\0';
			

			//Assign these values to our variable
			currentlyLoadedRecord.image = img;
			currentlyLoadedRecord.name = fixedName.c_str();
			currentlyLoadedRecord.age = age;

			//Free up some memory
			delete[] imgdata;
			delete[] name;

			// Get out of for loop
			break;
		}



	}


	

	infile.close();
	return &currentlyLoadedRecord;
}



void DataFile::Save(string filename, Record* newRecord)
{
	ofstream outfile(filename, ios::binary | fstream::in | fstream::out);

	int recordCount = this->recordCount;

	//Write out the new record count

	//Offset 0 of file is the record count
	outfile.write((char*)&recordCount, sizeof(int));


	// Here we take from our passed character
	Color* imgdata = GetImageData(newRecord->image);

	int imageSize = sizeof(Color) * newRecord->image.width * newRecord->image.height;
	int nameSize = newRecord->name.length();
	int ageSize = sizeof(int);
	int currIndex = 0;
	
	
	while (currIndex != recordCount)
	{
		//Let us jump to the record entry we want to load
		outfile.seekp(streamsize(imageSize) + streamsize(nameSize) + streamsize(ageSize), std::ios::cur);
		currIndex++;
	}
	//Jump one more time
	outfile.seekp(streamsize(imageSize) + streamsize(nameSize) + streamsize(ageSize), std::ios::cur);

			//We are at the final element
			// New Space for the new entry
		//	outfile.seekp(streamsize(imageSize) + streamsize(nameSize) + streamsize(ageSize), std::ios::cur);
			// Writing the data

			outfile.write((char*)&newRecord->image.width, sizeof(int));
			outfile.write((char*)&newRecord->image.height, sizeof(int));

			outfile.write((char*)&nameSize, sizeof(int));
			outfile.write((char*)&ageSize, sizeof(int));

			outfile.write((char*)imgdata, imageSize);
			outfile.write((char*)newRecord->name.c_str(), nameSize);
			outfile.write((char*)&newRecord->age, ageSize);

		
	

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

	
	infile.close();
}

void DataFile::Clear()
{
	fileName = "";
	recordCount = 0;
}
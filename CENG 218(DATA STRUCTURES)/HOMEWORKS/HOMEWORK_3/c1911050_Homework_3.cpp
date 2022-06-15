#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class File{
	protected:
		string filename;
		double filesize;
	public:
		
		File()
		{
			filename = " ";
			filesize = 0;
		}
		
		File(string filename, int filesize)
		{
			this->filename = filename;
			this->filesize = filesize;
		}
		
		virtual void print()
		{
			
			
		}
};

class ImageFile : public File{
	private:
		int width;
		int height;
	public:
		
		ImageFile()
		{
			width = 0;
			height = 0;
		}
				
		ImageFile(string filename, int filesize, int width, int height) :File(filename , filesize)
		{
			this->width = width;
			this->height = height;
		}
		
		void print()
		{
			
			double kb = 1;
			double mb = kb * 1024;
			double gb = mb * 1024;
			
			if (filesize >= 1024)
			{
				//MB
				filesize = filesize / mb;
				cout << filename << " is a " << width << "x" << height << " image file " << "(" << filesize << " " <<  " MB)" << endl; 
			}
			
			else if (filesize >= gb)
			{
				//GB
				filesize = filesize / gb;
				cout << filename << " is a " << width << "x" << height << " image file " << "(" << filesize << " " <<  " GB)" << endl;
			}
			
			else 
			{
				cout << filename << " is a " << width << "x" << height << " image file " << "(" << filesize << " " <<  " KB)" << endl; 
			}
			
			
		}
};

class AudioFile : public File{
	private:
		int duration;
	public:
		
		AudioFile()
		{
			duration = 0;
		}
		
		AudioFile(string filename, int filesize, int duration) : File(filename, filesize)
		{
			this->duration = duration;
		}
		
		void print()
		{
			
		}
};

class DocumentFile : public File{
	private:
		int nrOfWords;
	public:
		
		DocumentFile()
		{
			nrOfWords = 0;
		}
		
		DocumentFile(string filename, int filesize, int nrOfWords) : File(filename, filesize)
		{
			this->nrOfWords = nrOfWords;
		}
		
		void print()
		{
			
		}
};

class Mp4 : public File {
	private:
		int duration;
};

class FileType {
	private:
		string filetype;	
	public:
		FileType()
		{
			
		}
			
		void print ()
		{
			cout << "Enter what type of file do you want to search." << endl;
			cout << "1. Audio" << endl;
			cout << "2. Image" << endl;
			cout << "3. Document" << endl;
			cout << "4. Exit" << endl;
		}
};


int main()
{
	FileType filetypes;
	int choose;
	
	filetypes.print();
	cin >> choose;
	
	if(choose == 2)
	{
		
		cout << "These are the image files we have." << endl << "Select one for file information." << endl;
		string d;
		ifstream file;
		file.open("filelist.txt");
		for(int i = 0; i < 30; i++)
		{
			file >> d;
			if(d == "homework.pdf" || d == "94929 " || d == "1658" || d == "announcement.odt" || d == "243830 " || d == "27" || d == "song1.mp3" || d == "6285757" || d == "190" || d == "song2.mp3" || d == "4388992" || d == "182" || d == "song3.mp3" ||d == "5658890" || d == "235" || d == "ceng200.doc" || d == "210768" || d == "2172")
			{
				i++;
			}
			cout << d;
		}
		
	}
	
	else if(choose == 3)
	{
		cout << "These are the document files we have." << endl << "Select one for file information." << endl;
		
	}
	
	else if(choose == 1)
	{
		cout << "These are the audio files we have." << endl << "Select one for file information." << endl;
		
	}
	
	else if (choose == 4)
	{
		cout << "Bye!" << endl;
		return 0;	
	}
	
	else
	{
		cout << "Please enter a valid number!" << endl;
	}
}

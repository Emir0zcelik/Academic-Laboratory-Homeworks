#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class File{
	protected:
		string filename;
		int filesize;
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
		
		void set_filename(string filename)
		{
			this->filename = filename;
		}
		
		void set_filesize(int filesize)
		{
			this->filesize = filesize;
		}
		
		string get_filename()
		{
			return filename;
		}
		
		int get_filesize()
		{
			return filesize;
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
		
		ImageFile(string filename, int filesize, int width, int height) : File(filename, filesize)
		{
			this->width = width;
			this->height = height;
		}
		
		void set_width(int width)
		{
			this->width = width;
		}
		
		void set_height(int height)
		{
			this->height = height;
		}
		
		int get_height()
		{
			return height;
		}
		
		int get_width()
		{
			this->width = width;
		}
		
		virtual void Print()
		{
			fstream my_file;
			my_file.open("filelist.txt");
			if(!my_file.is_open())
			{
				cout << "No file" << endl;
			}
			
			else {
				string ch;
				int size;
				while(!my_file.eof())
				{	
					my_file >> ch;
					size = ch.size();
					if(ch.at(size - 1) == 'g' && ch.at(size - 2) == 'p' && ch.at(size - 3) == 'j' && ch.at(size - 4) == '.' || ch.at(size - 1) == 'g' && ch.at(size - 2) == 'n' && ch.at(size - 3) == 'p' && ch.at(size - 4) == '.')
					{
						for (int i = 0; i < 4; i++)
						{
							cout << ch;
							if(i == 0)
							{
								cout << " is a (";
							}
							
							else if(i == 1)
							{
								cout << ") ";
							}
							
							else if(i == 2)
							{
								cout << "x";
							}
							
							else if(i == 3)
							{
								cout << " image file";
							}
							my_file >> ch;
						}
						cout << endl;
					}
				}		
			}
			my_file.close();
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
		
		AudioFile(string filename, int filesize, int duration) : File (filename, filesize)
		{
			this->duration = duration;
		}
		
		virtual void Print()
		{
			fstream my_file;
			my_file.open("filelist.txt");
			if(!my_file.is_open())
			{
				cout << "No file" << endl;
			}
			
			else {
				string ch;
				int size;
				while(!my_file.eof())
				{	
					my_file >> ch;
					size = ch.size();
					if(ch.at(size - 1) == '3' && ch.at(size - 2) == 'p' && ch.at(size - 3) == 'm' && ch.at(size - 4) == '.')
					{
						
						for (int i = 0; i < 4; i++)
						{
							cout << ch;
							if(i == 0)
							{
								cout << " (";
								my_file>> ch;
							}
							
							else if(i == 1)
							{
								cout << ") is a ";
								my_file>> ch;
							}
										
							else if(i == 2)
							{
								cout << " seconds long audio file";
								break;	
							}
						}
						cout << endl;
					}
				}		
			}
			my_file.close();
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
		
		DocumentFile(string filename, int filesize, int nrOfWords) : File(filename , filesize)
		{
			this->nrOfWords = nrOfWords;		
		}
		
		virtual void Print()
		{
			fstream my_file;
			my_file.open("filelist.txt");
			if(!my_file.is_open())
			{
				cout << "No file" << endl;
			}
			
			else {
				string ch;
				int size;
				while(!my_file.eof())
				{	
					my_file >> ch;
					size = ch.size();
					if(ch.at(size - 1) == 'c' && ch.at(size - 2) == 'o' && ch.at(size - 3) == 'd' && ch.at(size - 4) == '.' || ch.at(size - 1) == 't' && ch.at(size - 2) == 'd' && ch.at(size - 3) == 'o' && ch.at(size - 4) == '.' || ch.at(size - 1) == 'f' && ch.at(size - 2) == 'd' && ch.at(size - 3) == 'p' && ch.at(size - 4) == '.')
					{
						
						for (int i = 0; i < 4; i++)
						{
							cout << ch;
							if(i == 0)
							{
								cout << " (";
								my_file>> ch;
							}
							
							else if(i == 1)
							{
								cout << ") is a ";
								my_file>> ch;
							}
										
							else if(i == 2)
							{
								cout << " words long document file";
								break;	
							}
						}
						cout << endl;
					}
				}		
			}
			my_file.close();
		}
};

int main()
{
	File file;
	ImageFile image;
	AudioFile audio;
	DocumentFile document;
	
	image.Print();
	audio.Print();
	document.Print();
}

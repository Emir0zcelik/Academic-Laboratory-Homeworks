class Song
{
private:
	string title;
	int min;
	int sec;
	
	

public:
Song ()
{
	string title = "";
	int min = 0;
	int  sec = 0;
}
Song(string title)
{
this -> title = title;
int min = 0;
int sec = 0;
	
}


Song(string title, int min2, int sec2)
{
	this -> title = title;
	min = min2;
	sec = sec2;
	
}


void settitle(string title2)
{
	this -> title = title2;
	
}
void setmin(int min2)
{
	min = min2;
	
}

void setsec(int sec2)
{
	sec = sec2;
}


string gettitle()
{
	return title;
	
}
int getmin()
{
	return min;
}

int getsec()
{
	return sec;
}

~Song()
{
	
}

};


void Total(int *min, int *sec){
	
	if(*sec >= 60){
		*min += (*sec) / 60;
		*sec = *sec % 60;		
	}
	
	
}







int main()
{
	int total{0};
	Song music[3];
	string title;
	int min;
	int sec;
	int totalmin = 0;
	int totalsec = 0;
	for(int i = 0; i < 3; i++)
	{
		
		cout<<"Enter title and duration of "<<i + 1<<". song:";
		cin >> baslik >> dak >> san;
		music[i].settitle(title);
		music[i].setmin(min);
		music[i].setsec(sec);
		totalmin += min;
		totalsec += sec;
		
	}
	
	cout << "Your Playlist : " << endl;
	
	for(int i = 0; i < 3; i++)
	{
	
	cout << "! "<< music[i].gettitle() << "  " << music[i].getmin() << ":" << music[i].getsec() <<endl;
	
	}

	Total(&totalmin, &totalsec);
	cout <<"Total duration: " << totalmin << "minutes" << totalsec << " seconds " << endl;
}

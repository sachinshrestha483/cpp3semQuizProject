#include <iostream>
#include<fstream>
#include<string>
using namespace std;

class QuizTitle{
	int id;
	char title[200];
	int individualMarks;
	char description[500];
	
	public:
		void AddTitle()
		{
			cout<<"Enter Title Name:";
			cin.getline(title,200);
			cout<<"Enter Title Description:";
			cin.getline(description,500);
			cout<<"Enter Title individualMarks:";
		    cin>>individualMarks;
		    
		    id=1;
		    
		    ofstream writeTitle;
			writeTitle.open("quizTitle.dat",ios::app|ios::binary);
			writeTitle.write((char*)this,sizeof(*this));
		}
		
		void ShowTitle(int index)
		{
			ifstream readTitle;
			readTitle.open("quizTitle.dat");
		    readTitle.seekg(index*sizeof(QuizTitle));
			readTitle.read((char*)this,sizeof(*this));
		    
			cout<<"Id:"<<id<<endl;
			cout<<"Title Name:"<<title<<endl;
			
			
		    cout<<"Enter Title Description:"<<description<<endl;
			
			cout<<"Enter T individualMarks:"<<individualMarks<<endl<<endl;
		    
		    
		}
		
		
		
};
int main()
{
	
	int count=0;
     QuizTitle q1;

 
     //q1.AddTitle();
	cout<<endl<<"Record From BinaryFile"<<endl<<endl;
   
       q1.ShowTitle(0);	
       cout<<endl<<endl;

	
}

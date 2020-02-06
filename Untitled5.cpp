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
		    
		   
		    
		    fstream writeTitle;
		    
			writeTitle.open("quizTitle.dat",ios::app|ios::binary);
			writeTitle.seekg(0,ios::end);
			id =writeTitle.tellg()/sizeof(QuizTitle)+1;
			
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
			
			cout<<"Enter Title individualMarks:"<<individualMarks<<endl<<endl;
		    
		    
		}
		int NumberOftitles()
		{
			fstream writeTitle;
			writeTitle.open("quizTitle.dat",ios::app|ios::binary|ios::in);
			writeTitle.seekg(0,ios::end);
			int count =writeTitle.tellg()/sizeof(QuizTitle);
			return count;
		}
		
		void SelectTitle()
		{
		}
		
		
		
};
int main()
{
	

     QuizTitle q1;

 
  //q1.AddTitle();
	cout<<endl<<"Record From BinaryFile"<<endl<<endl;
   
   int TotalTitle= q1.NumberOftitles();

cout<<"Number of Titles:"<<TotalTitle<<endl<<endl;
int count=0;
while(count<TotalTitle)
{
	q1.ShowTitle(count);
	count++;
}

int choice;
cout<<"Insert The Id No Of  The Quiz You Want To Attend:";
cin>>choice;
if()

   //while(point<=count)
   //{
     //   q1.ShowTitle(1);	
       // cout<<endl<<endl;	
   	    //point++;
  // }
   

	
}

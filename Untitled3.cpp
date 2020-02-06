#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class QuizTitle {
		int id;
		string title;
		int eachQuestionMarks;
		string description;
	public:
		void NewQuizTitle( ) {

			cout<<"Enter Title Name:";
			getline(cin,title);

			cout<<"Enter Question Description:";
			getline(cin,description);

			cout<<"Enter Each Question Marks:";
			cin>>eachQuestionMarks;

			id=1;
			ofstream title;
			title.open("title.dat",ios::app|ios::binary);
			title.write((char*)this,sizeof(*this));
       }
		void  ShowQuizTitle(int index) {
			ifstream readTitle;
			readTitle.open("title.dat");
			readTitle.seekg(index*sizeof(QuizTitle));
			readTitle.read((char*)this,sizeof(*this));
			cout<<endl<<"Title:"<<title<<endl<<"Question MArks:"<<eachQuestionMarks<<endl<<"Description:"<<description;
		}
		void ReadFile(int index)
		{
			ifstream readStudent;
			readStudent.open("title.dat");
			readStudent.seekg(index*sizeof(QuizTitle));
			readStudent.read((char*)this,sizeof(*this));
		    	cout<<endl<<"Title:"<<title<<endl<<"Question MArks:"<<eachQuestionMarks<<endl<<"Description:"<<description;
		}
		void Show()
		{
			 	cout<<endl<<"Title:"<<title<<endl<<"Question MArks:"<<eachQuestionMarks<<endl<<"Description:"<<description;
		}

};


int main() {

	//quiz1.NewQuizTitle();

	QuizTitle q;
	q.NewQuizTitle();
	ifstream Fin;
	Fin.open("title.dat");
while(Fin.read((char*)&q,sizeof(q)))
{
	q.Show();
}
	return 0;
}

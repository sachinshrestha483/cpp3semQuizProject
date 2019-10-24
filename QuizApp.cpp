#include <iostream>
#include<fstream>
#include<string.h>
using namespace std;



class User
{
	
	char Name[50];
	char Role[50];
	char Password[20];
	int age;
	bool isLoggedin;
	
	
	public:
		int id;
		void CreateUser(){
			char temppassword1[20];
			char temppassword2[20];
	
			User user;
			
			cout<<"Enter  Name:";
			cin>>user.Name;
			cout<<"Enter Age:";
			cin>>user.age;
			cout<<"Enter PassWord:";
			cin>>temppassword1;
			cout<<"Conform PassWord:";
			cin>>temppassword2;
			int isPasswordsame= strcmp(temppassword1,temppassword2);
		
			if(isPasswordsame==0)
			{
				strcpy(user.Password, temppassword1); 
	           
	         //  strcpy(user.Role,"ADMIN");
			 strcpy(user.Role,"USER");
			
			    fstream userFile;
				userFile.open("UsersTable.dat",ios::binary|ios::app);
			    userFile.write((char*)&user,sizeof(user) );
			    userFile.close();
			   cout<<endl<<"User Created"<<endl<<endl;
			}
			else {
				cout<<endl<<"Error  Password and Confirm Password Dont Match!!"<<endl;
			}
		
		}
		void Login(){
			char temppassword[20];
			char userName[20];
			cout<<"User Name:";
			cin>>userName;
			cout<<"Password:";
			cin>>temppassword;
			User user;
			fstream userFile;
			userFile.open("UsersTable.dat",ios::binary|ios::in);
			while(userFile.read((char*)&user,sizeof(user)))
			{
				int isNameSame=strcmp(user.Name,userName);
				int isPasswordSame=strcmp(user.Password,temppassword);
				if(isNameSame==0&&isPasswordSame==0)
				{
				  cout<<"You Are Logged in "<<endl;
				  this->isLoggedin=true;
				  
				  break;
				}
				else{
					continue;
				
				}
				
			}
			if(this->isLoggedin==false)
			{
					cout<<endl<<"Id or Password Dont Match"<<endl;
					user.Login();
			}
			
		
		}
		
		void AdminLogin()
	     {
	     	char temppassword[20];
			char userName[20];
			cout<<"User Name:";
			cin>>userName;
			cout<<"Password:";
			cin>>temppassword;
			User user;
			fstream userFile;
			userFile.open("UsersTable.dat",ios::binary|ios::in);
			while(userFile.read((char*)&user,sizeof(user)))
			{
				int isNameSame=strcmp(user.Name,userName);
				int isPasswordSame=strcmp(user.Password,temppassword);
			    int isSameRole=strcmp("ADMIN",user.Role);
				if(isNameSame==0&&isPasswordSame==0)
				{
	
				if(isSameRole==0)
				{
				
				  cout<<endl<<"Welcome Admin!! "<<endl;
				  this->isLoggedin=true;
				  break;
			    }
			    continue;
				}
				else{
					continue;
					
				
				}
				
			}
			if(this->isLoggedin==false)
			{
					cout<<"Id or Password Dont Match"<<endl;
					this->Login();
			}

	     	
		 }
		 
		
		
	
};

class QuizTitle{

	char title[200];
	
	char description[500];
	
	public:
			int id;
			int individualMarks;
		void AddTitle()
		{
					cin.getline(title,200);
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
		
		void AllQTitle()
		{
			QuizTitle qt;
		    fstream readTitle;
			readTitle.open("quizTitle.dat",ios::in);
			while(readTitle.read((char*)&qt,sizeof(qt)))
			{
				cout<<endl<<endl;
				cout<<"Id:"<<qt.id<<endl;
				cout<<"Quiz Title:"<<qt.title<<endl;
				cout<<"Quiz Description:"<<qt.description<<endl;
			    cout<<"Quiz Question Individual Marks:"<<qt.individualMarks<<endl;
				
			}
		}
		
		void AllQTitleWithQuestions()
		{
			
			
			QuizTitle qt;
		    fstream readTitle;
			readTitle.open("quizTitle.dat",ios::in);
			while(readTitle.read((char*)&qt,sizeof(qt)))
			{
				cout<<endl<<endl;
				cout<<"Id:"<<qt.id<<endl;
				cout<<"Quiz Title:"<<qt.title<<endl;
				cout<<"Quiz Description:"<<qt.description<<endl;
			    cout<<"Quiz Question Individual Marks:"<<qt.individualMarks<<endl;
			    //
			    //qn.ShowQTitle(qt.id);
				//
			}
		}
		void ShowQTitle(int index)
		{
			ifstream readTitle;
			readTitle.open("quizTitle.dat");
		    readTitle.seekg(index*sizeof(QuizTitle));
			readTitle.read((char*)this,sizeof(*this));
		    
			
			cout<<title<<endl;
			
		}
		int NumberOftitles()
		{
			fstream writeTitle;
			writeTitle.open("quizTitle.dat",ios::app|ios::binary|ios::in);
			writeTitle.seekg(0,ios::end);
			int count =writeTitle.tellg()/sizeof(QuizTitle);
			return count;
		}
		
		void SelectTitle(){
			int choice;
			int choiceQuizIndex;
            cout<<"Insert The Id No Of  The Quiz You Want To Attend:";
            cin>>choice;
            if(choice<=this->NumberOftitles()&&choice>=0)
            {
            	choiceQuizIndex=choice-1;
            	//cout<<"You have Selected Quiz :";
            	
        
			}
			else{
				this->SelectTitle();
			}
			

		}
		
		
		
		
		
		
};

class QuizQuestion{
	int id;
	int qtid;
	char question[800];
	char option1[400];
	char option2[400];
	char option3[400];
	char option4[400];
	int correctOptionNumber;
	
	public:
		void AddQuestion()
		{
			int numberOfQuestions;
			int tid;
			cout<<"Enter Quiz Id:";
			cin>>tid;
			qtid=tid;
			int index=tid-1;
			cout<<"Enter Number Of Questions:";
			cin>>numberOfQuestions;
			int i=1;
			while(i<=numberOfQuestions)
			{
				cout<<endl;
				cout<<"";
				cin.getline(question,800);
		      cout<<endl;
		      cout<<"Enter Question:";
		      cin.getline(question,800);
		      cout<<endl;
		      cout<<"Enter option 1:";
		      cin.getline(option1,400);
		      cout<<endl;
		      
			cout<<"Enter option 2:";
		      cin.getline(option2,400);
		      cout<<endl;
			  cout<<"Enter option 3:";
		      cin.getline(option3,400);
		      cout<<endl;
			  cout<<"Enter option 4:";
		      cin.getline(option4,400);	
		      cout<<endl;		
		      cout<<"Enter correct Option Number:";
		      cin>>correctOptionNumber;
		      cout<<endl;
		       fstream writeQuestion;
		    
			writeQuestion.open("quizQuestion.dat",ios::app|ios::binary);
			writeQuestion.seekg(0,ios::end);
			id =writeQuestion.tellg()/sizeof(QuizQuestion)+1;
			
			writeQuestion.write((char*)this,sizeof(*this));
			writeQuestion.close();
		      i++;
			}
			cout<<i-1<<" Questions Added Sucessfully";
		
			
		}
		void ShowQQuestion(int id)
		{
			int choice;
			int individualpoint;
			int totalpoints=0;
			int numberOfquestions=1;
			
			ifstream readpoints;
			QuizTitle qt;
			readpoints.open("quizTitle.dat");
			while(readpoints.read((char*)&qt,sizeof(qt)))
			{
				if(qt.id==id)
				{
					individualpoint=qt.individualMarks;
				}
			}
			
			
			ifstream readTitle;
			QuizQuestion qQ1;
			readTitle.open("quizQuestion.dat");
			int count=0;
			while(readTitle.read((char*)&qQ1,sizeof(qQ1)))
		    {
		    	if(qQ1.qtid==id)
		    	{
		    		cout<<endl;
		    	cout<<"Question: "<<qQ1.question<<endl;
		    	cout<<"option 1:"<<qQ1.option1<<endl;
		    	cout<<"option 2:"<<qQ1.option2<<endl;
		    	cout<<"option 3:"<<qQ1.option3<<endl;
		    	cout<<"option 4:"<<qQ1.option4<<endl;
		    	
		    cout<<endl<<endl;
		    	
				cout<<"Enter Correct Option Number:";
		    	cin>>choice;
		    	cout<<endl;
		    	if(choice<=4)
		    	{
		    	
		    		if(choice==qQ1.correctOptionNumber)
		    		{
		    			totalpoints=totalpoints+individualpoint;
		    			cout<<"Correct Answer";
		    			
		    			
					}
					else 
					{
						cout<<"Wrong  Answer";
					    
					}
						cout<<endl<<endl<<endl;
		    	
					
				}
			
				else{
					cout<<"Please Enter  Valid Option Number"<<endl;	
					cout<<endl;
				}
				count++;
			
			
				}
		    	
		    	else{
		    		
				}
				
				
				
				
			}
			cout<<"Number of Questions Attempted:"<<count<<endl;
			cout<<"Total Points:"<<totalpoints<<endl;
			cout<<"Correct:"<<totalpoints/individualpoint<<endl;
			cout<<"Wrong:"<<count-totalpoints/individualpoint<<endl;
			
		    
			
		
			
		}
	
		
		
		void AllQuestions()
		{
			fstream readQuestion;
			QuizQuestion qQ1;
			readQuestion.open("quizQuestion.dat",ios::in);
			
			while(readQuestion.read((char*)&qQ1,sizeof(qQ1)))
			{
				
				cout<<endl;
				cout<<"Id: "<<qQ1.id<<endl;
		    	cout<<"Question: "<<qQ1.question<<endl;
		    	cout<<"option 1:"<<qQ1.option1<<endl;
		    	cout<<"option 2:"<<qQ1.option2<<endl;
		    	cout<<"option 3:"<<qQ1.option3<<endl;
		    	cout<<"option 4:"<<qQ1.option4<<endl;
		    	cout<<"Quiz Title Id:"<<qQ1.qtid<<endl;
		    	cout<<endl<<endl;
			}
		    
		}
		
};

	void UserView(User u)
			{
				
				QuizQuestion qq1;
				int choice;
				cout<<"Here Are The Avaliable Quizes"<<endl<<endl;
				QuizTitle qt;
				cout<<endl;
				qt.AllQTitle();
				cout<<endl;
				qt.SelectTitle();
				cout<<"Enter Quiz Want To Attend:";
				cin>>choice;
				qq1.ShowQQuestion(choice);
			} 
			
	void AdminView(QuizTitle qt)
	{
		
		int input;
		cout<<endl<<"Hi Admin!!"<<endl;
		cout<<"Enter 1  for Adding  Quiz Title"<<endl;
		cout<<"Enter 2 for Adding Questions To Title:"<<endl;
		cout<<"Enter 3 for Seeing Quiz Title And Corresponding Quiz Questions"<<endl;
		cout<<"Enter 4 For  Logout"<<endl;
		cout<<"Enter Desired Option:";
		cin>>input;
		if(input==1)
		{
			qt.AddTitle();
		}
		else if(input==2)
		{
			QuizQuestion qq1;
			 qt.AllQTitle();
			 qq1.AddQuestion();
			 
			//qt.SelectTitle();
		}
		else if(input==3)
		{
			QuizQuestion qq1;
			qt.AllQTitle();
			qq1.AllQuestions();
			
			//qt.SelectTitle();
		}
		else if(input==4){
			return;
		}
		
		
	}	
	
	
	void indexpage()
	{
		User u1;
	QuizTitle qt;
	int choice;
	cout<<"Welcome To The C++ Quiz App"<<endl;
	
	cout<<"Enter 1 for Admin Login"<<endl;
	cout<<"Enter 2  for  User Login"<<endl;
    cout<<"Enter 3  for  User SignUp"<<endl;

	
	
	cout<<"Enter Your Choice:";
	cin>>choice;
	if(choice==1)
	{
		cout<<"Admin Login"<<endl<<endl;
		u1.AdminLogin();
		AdminView(qt);
	}
	else if(choice==2)
	{
		cout<<"User Login"<<endl<<endl;
		u1.Login();
		UserView(u1);
		
	
		
	}
	else if(choice==3)
	{
		cout<<"User SignUp"<<endl<<endl;
		u1.CreateUser();
		
		
	}
	else{
		cout<<"Choose Correct Option";
	}

		
	}	
int main()
{
	indexpage();
	

	
}

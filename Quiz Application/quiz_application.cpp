#include<iostream>
#include<string>
using namespace std;

void showquestion(string question,string a,string b,string c,string d,char correctanswer,int &score,int &lives)
{
	char answer;
	cout<<"\n------------------------------\n";
	cout<<question<<endl;
	cout<<"A. "<<a<<endl;
	cout<<"B. "<<b<<endl;
	cout<<"C. "<<c<<endl;
	cout<<"D. "<<d<<endl;
	cout<<"--------------------------------";
	cout<<"Your answer : ";
	cin>>answer;
	answer=toupper(answer);
	if(answer==correctanswer)
	{
		cout<<"Correct! +1 point\n";
		score++;
	}
	else
	{
		cout<<"Wrong answer!!\n";
		cout<<"Correct answer was: "<<correctanswer<<endl;
		lives--;
		cout<<"Lives remaining: "<<lives<<endl;
	}
}

void showresult(string name,int score,int lives)
{
	cout<<"\n==============================\n";
	cout<<"          QUIZ RESULT\n";
	cout<<"\n==============================\n";
	
	cout<<"Player: "<<name<<endl;
	cout<<"Score: "<<score<<endl;
	cout<<"Lives remaining: "<<lives<<endl;
	
	if(score==5)
	{
		cout<<"Perfect Score! Amazing!"<<endl;
	}
	else if(score>=3)
	{
		cout<<"Good Job!!"<<endl;
	}
	else
	{
		cout<<"Keep Practicing!!"<<endl;
		
	}
	cout<<"=====================================\n";
}

int main()
{
	string name;
	char choice;
	do
	{
		
		int score=0;
		int lives=3;
		cout<<"==============================="<<endl;
		cout<<"       WELCOME TO QUIZ"<<endl;
		cout<<"==============================="<<endl;
		
		cout<<"Enter your name: "<<endl;
		cin>>name;
		cout<<"Hello, "<<name<<endl;
		cout<<"You have 3 lives."<<endl;
		cout<<"Each correct answer earns you 1 point."<<endl;
		cout<<"Good Luck!"<<endl;
		cout<<"\nPress Y to start."<<endl;
		cin>>choice;
		
		if(choice=='y' || choice=='Y')
		{
			showquestion("1. Which language is C++ based on?","Python","C","Java","HTML",'B',score,lives);
			if(lives>0)
			showquestion("2. Which keyword is used to create a class?","object","create","class","new",'C',score,lives);
			if(lives>0)
			showquestion("3. Which symbol ends a C++ statement?",".",":",";",",",'C',score,lives);
			if(lives>0)
			showquestion("4. Which function is starting point of a C++ program?","start()","main()","begin()","run()",'B',score,lives);
			if(lives>0)
			showquestion("5. Which concept means one name with many forms?","Inheritance","Encapsulation","Polymorphism","Abstraction",'C',score,lives);
			showresult(name,score,lives);
			
		}
		
		cout<<"Do you want to play again? (Y/N)"<<endl;
		cin>>choice;
		
		
   }while(choice=='Y' || choice=='y');
   
   cout<<"Thanks for playing, "<<name<<"!"<<endl;
}
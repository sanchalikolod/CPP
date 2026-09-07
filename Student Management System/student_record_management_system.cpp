#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct student
{
	int rollno;
	string name;
	int age;
	string course;
	float marks;
};

student students[100];
int totalstudents=0;

void savetofile()
{
	ofstream file("students.txt");
	if(!file.is_open())
	{
		cout<<"Error opening file."<<endl;
		return;
	}
	
	for(int i=0;i<totalstudents;i++)
	{
		file<<students[i].rollno<<endl;
		file<<students[i].name<<endl;
		file<<students[i].age<<endl;
		file<<students[i].course<<endl;
		file<<students[i].marks<<endl;
	}
	
	file.close();
}

void loadfromfile()
{
	ifstream file("students.txt");
	if(!file.is_open())
	return;
	totalstudents=0;
	
	while(totalstudents<100)
	{
		student temp;
		if(!(file>>temp.rollno))
		break;
		file.ignore();
		getline(file,temp.name);
		file>>temp.age;
		file.ignore();
		getline(file,temp.course);
		file>>temp.marks;
		file.ignore();
		students[totalstudents]=temp;
		totalstudents++;
		
		
	}
	file.close();
}

void add()
{
	if (totalstudents>=100)
	{
		cout<<"\nStudent Limit Reached!!\n";
		return;
	}
	student temp;
	
	cout<<"\n---Add Student---\n";
	cout<<"Enter Roll Number: "<<endl;
	cin>>temp.rollno;
	cin.ignore();
	cout<<"Enter Name: "<<endl;
	getline(cin, temp.name);
	cout<<"Enter Age: "<<endl;
	cin>>temp.age;
	cin.ignore();
	cout<<"Enter Course: "<<endl;
	getline(cin,temp.course);
	cout<<"Enter Marks: "<<endl;
	cin>>temp.marks;
	students[totalstudents]=temp;
	
	totalstudents++;
	savetofile();
	cout<<"\nStudent Added Successfully !!"<<endl;
	
}

void display()
{
	if(totalstudents==0)
	{
		cout<<"\nNo Student Records Found!!\n";
		return;
		
	}
	
	cout<<"\n---Student Records---"<<endl;
	
	for(int i=0;i<totalstudents;i++)
	{
		cout<<"Student : "<<i+1<<endl;
		cout<<"Roll Number : "<<students[i].rollno<<endl;
		cout<<"Name : "<<students[i].name<<endl;
		cout<<"Age : "<<students[i].age<<endl;
		cout<<"Course : "<<students[i].course<<endl;
		cout<<"Marks : "<<students[i].marks<<endl;
		
	}
}

void search()
{
	int rollno;
	int flag=0;
	cout<<"Enter roll number to search: "<<endl;
	cin>>rollno;
	
	for(int i=0;i<totalstudents;i++)
	{
		if(students[i].rollno==rollno)
		{
			cout<<"---Student Found---"<<endl;
			cout<<"Student : "<<i+1<<endl;
			cout<<"Roll Number : "<<students[i].rollno<<endl;
			cout<<"Name : "<<students[i].name<<endl;
			cout<<"Age : "<<students[i].age<<endl;
			cout<<"Course : "<<students[i].course<<endl;
			cout<<"Marks : "<<students[i].marks<<endl;
			
			flag=1;
			break;
		}
	}
	
	if(flag==0)
	cout<<"Student Not Found!!"<<endl;
}

void update()
{
	int rollno;
	int flag=0;
	cout<<"Enter roll number to update: "<<endl;
	cin>>rollno;
	
	for(int i=0;i<totalstudents;i++)
	{
		if(students[i].rollno==rollno)
		{
		
			cin.ignore();
			cout<<"Enter new name: "<<endl;
			getline(cin, students[i].name);
			cout<<"Enter new age: "<<endl;
			cin>>students[i].age;
			cin.ignore();
			cout<<"Enter new course: "<<endl;
			getline(cin, students[i].course);
			cout<<"Enter new marks: "<<endl;
			cin>>students[i].marks;
			savetofile();
			cout<<"\nStudents Details Updated Successfully!!"<<endl;
			flag=1;
			break;
		}
		
	}
	
	if(flag==0)
	{
		cout<<"\nStudent not found!!\n";
		return;
	}
}

void deletestudent()
{
	int rollno;
	int flag=0;
	cout<<"Enter roll number to delete: "<<endl;
	cin>>rollno;
	
	for(int i=0;i<totalstudents;i++)
	{
		if(students[i].rollno==rollno)
		{
			for(int j=i;j<totalstudents-1;j++)
			{
				students[j]=students[j+1];
			}
			
			totalstudents--;
			savetofile();
			cout<<"\nStudent Deleted Successfully!!\n";
			flag=1;
			break;
		}
	}
	
	if(flag==0)
	{
		cout<<"\nStudent not found!!\n";
		
	}
}


int main()
{
	int choice;
	loadfromfile();
	do{
	
	cout<<"\n=================================";
	cout<<"\n    STUDENT MANAGEMENT SYSTEM";
	cout<<"\n================================="<<endl;
	cout<<"1. Add Students"<<endl;
	cout<<"2. Display Students"<<endl;
	cout<<"3. Search Student"<<endl;
	cout<<"4. Update Student"<<endl;
	cout<<"5. Delete Student"<<endl;
	cout<<"6. Exit"<<endl;
	
	cout<<"Enter your choice: "<<endl;
	cin>>choice;
	switch(choice)
	{
		case 1:
			add();
			break;
		case 2:
			display();
			break;
		case 3:
			search();
			break;
		case 4:
			update();
			break;
		case 5:
			deletestudent();
			break;
		case 6:
			cout<<"\nThank you for using the system!!"<<endl;
			break;
		default:
			cout<<"\nInvalid choice.Please try again!"<<endl;
		
	} 
}while(choice!=6);
	
}
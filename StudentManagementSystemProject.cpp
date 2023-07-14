#include<iostream>
#include<vector>
using namespace std;
class Student{
    private:
        int rollno,age;
        string name;
    public:
        Student(int stdRollno,string stdName,int stdAge){
            rollno = stdRollno;
            name = stdName;
            age = stdAge;
            
        }
        void setRollno(int stdRollno){
            rollno = stdRollno;
        }
        int getRollno(){
            return rollno;
        }
        void setName(string stdName){
            name = stdName;
        }
        string getName(){
            return name;
        }
        void setAge(int stdAge){
            age = stdAge;
        }
        int getAge(){
            return age;
        }
        void displayStudent(){
            cout<<"\t\tRoll No : "<<rollno<<endl;
            cout<<"\t\tName : "<<name<<endl;
            cout<<"\t\tAge : "<<age<<endl;
        }
};
void displayAllStudent(vector<Student>&students){
    if(students.empty()){
        cout<<"/t/t NO Student Found "<<endl;
        return;
    }
    for(int i=0;i<students.size();i++){
        students[i].displayStudent();
        cout<<endl;
    }

}
// create function to update student
void updateStudent(vector<Student>&students){
    string sname;
    bool found =false;
    int choice;

    cout<<"\t\tEnter Name to Update Record : ";
    cin.ignore();
    getline(cin,sname);

    for(int i=0;i<students.size();i++){
        if(students[i].getName()==sname){
            found = true;

            cout<<"\t\t----Student Found----\n";
            cout<<"\t\t 1. Update Rollno : \n";
            cout<<"\t\t 2. Update Name : \n";
            cout<<"\t\t 3. Update Age : \n";
            cout<<"\t\tEnter Your choice : ";
            cin>>choice;

            switch(choice){
                case 1:{
                    int rno;
                    cout<<"\t\tEnter New Rollno : ";
                    cin>>rno;
                    students[i].setRollno(rno);
                    break;
                }
                case 2:{
                    string name ;
                    cout<<"\t\tEnter New Name : ";
                    cin.ignore();
                    getline(cin,name);
                    students[i].setName(name);
                    break;
                }
                case 3:{
                    int age;
                    cout<<"\t\tEnter New Age : ";
                    cin>>age;
                    students[i].setAge(age);
                    break;
                }
                default:
                    cout<<"\t\tInvaid Number..."<<endl;

            }
        }
    }if(!found){
        cout<<"\t\tRecord Not found\n";
        return;
    }

}
// create function to search student in the list
void SearchStudent(vector<Student>&students){
    int rollno;
    cout<<"\t\tEnter Roll : ";
    cin>>rollno;
    for(int i=0;i<students.size();i++){
        if(students[i].getRollno() == rollno){
            cout<<"\t\t------------------Student Found------------------\n";
            students[i].displayStudent();
            return;
        }
    }
}
// create function to add new student in the list
void addNewStudents(vector<Student>&students){
    int rollno,age;
    string name;
    cout<<"\t\tEnter Rollno :";
    cin>>rollno;
    //check if already exit
    for(int i=0;i<students.size();i++){
        if(students[i].getRollno() == rollno){
            cout<<"\t\tStudent Already Exits..."<<endl;
            return;
        }
    }
    cout<<"\t\tEnter Name :  ";
    cin>>name;
    cout<<"\t\tEnter Age :  ";
    cin>>age;
    Student newStudents(rollno,name,age);
    students.push_back(newStudents);
    cout<<"\t\tStudent Add Successfully..."<<endl;

}
// create function to delete a student
void deleteStudent(vector<Student>&students){
    string name;
    cout<<"\t\tEnter Name To Delete : ";
    cin.ignore();
    getline(cin,name);
    for(int i=0;i<students.size();i++){
        if(students[i].getName() == name){
            students.erase(students.begin()+i);
            cout<<"\t\tStudent Remove Successfully\n";
        }
    }
}
int main(){
    vector<Student> student;
    student.push_back(Student(5,"mohit",23));
    
    char choice;
    do{
        system("cls");
        int op;
        cout<<"\n\t\t--------------------------------"<<endl; 
        cout<<"\n\t\tStudent Management System"<<endl;
        cout<<"\n\t\t--------------------------------"<<endl;
        cout<<"\t\t 1. Add New Student\n";
        cout<<"\t\t 2. Display All Student\n";
        cout<<"\t\t 3. Search Student\n";
        cout<<"\t\t 4. Update Student\n";
        cout<<"\t\t 5. Delete Student\n";
        cout<<"\t\t 6. Exit\n";
        cout<<"\t\tEnter Your Choice : ";
        cin>>op;
        switch(op){
            case 1:
                addNewStudents(student);
                break;
            case 2:
                displayAllStudent(student);
                break;
            case 3:
                SearchStudent(student);
                break;
            case 4:
                updateStudent(student);
                break;
            case 5:
                deleteStudent(student);
                break;
            case 6:
                exit(1);
            default:
                cout<<"\t\tInvaid Number..."<<endl;
        }cout<<"\t\tDo You Want to Continue [Yes / No] ? :";
        cin>>choice;
    }while(choice == 'Y' || choice == 'y');
    
    
}
#include <iostream>
#include <cstring>
using namespace std;

struct Student{
    int studID;
    string fname;
    string lname;
    string course;
    double gpa;
};

void addStudent(Student p[], int &count){
    cout<<"===ADDING A STUDENT==="<<endl;

    cout<<"Enter Student ID: ";
    cin>>p[count].studID;
    cout<<"Enter First Name: ";
    cin>>p[count].fname;
    cout<<"Enter Last Name: ";
    cin>>p[count].lname;
    cout<<"Enter course: ";
    cin>>p[count].course;
    cout<<"Enter previous semestral GPA: ";
    cin>>p[count].gpa;

    for(int i = 0; i < count; i++){
        while(p[count].studID == p[i].studID) {
            cout<<"\nStudent ID already existed..."<<endl;
            cout<<"Enter another ID: ";
            cin>>p[count].studID;
            i=-1;
        }
    }

    count++;
    cout<<"New student successfully added!!!"<<endl;
    cout<<endl;
}

void editStudent(Student p[], int count){
    if(count==0) {
        cout<<"No student to edit..."<<endl;
        return;
    }
    else{
        int editID;
        bool found = false;

        cout<<"===EDIT STUDENT DATA==="<<endl;
        cout<<"Enter student ID to edit: ";
        cin>>editID;

        for(int i = 0; i < count; i++){
            if(editID == p[i].studID){
                found = true;

                cout<<"\n===Student data found==="<<endl;
                cout<<"Student ID: " << p[i].studID<<endl;
                cout<<"First Name: " << p[i].fname<<endl;
                cout<<"Last Name: " << p[i].lname<<endl;
                cout<<"Course: " << p[i].course<<endl;
                cout<<"Previous sem GPA: " << p[i].gpa<<endl;

                cout<<"\n===Edit Data==="<<endl;
                cout<<"Enter new/current Student ID: ";
                cin>>p[i].studID;
                cout<<"Enter new/current First Name: ";
                cin>>p[i].fname;
                cout<<"Enter new/current Last Name: ";
                cin>>p[i].lname;
                cout<<"Enter new/current course: ";
                cin>>p[i].course;
                cout<<"Enter new/current previous sem GPA: ";
                cin>>p[i].gpa;

                for(int j=0; j<count; j++) {
                    while(p[i].studID == p[j].studID && i != j) {
                        cout<<"\nStudent ID already existed..."<<endl;
                        cout<<"Enter another ID: ";
                        cin>>p[i].studID;
                        j = -1;
                    }
                }

                cout<<"Student data has been updated..."<<endl;
                cout<<endl;
                return;
            }
        }

        if(!found){
            cout<<"Sorry, student not found..."<<endl;
        }
    }
}

void deleteStudent(Student p[], int &count){
    if(count==0){
        cout<<"No student record to delete..."<<endl;
    }

    else{

        int editID;
        bool found = false;

        cout<<"===DELETE STUDENT DATA==="<<endl;
        cout<<"Enter student ID to remove data: ";
        cin>>editID;

        for(int i=0; i<count; i++) {
            if(editID==p[i].studID) {
                found = true;

                cout<<"\nStudent data has been found..."<<endl;
                cout<<"Student ID: "<<p[i].studID<<endl;
                cout<<"First Name: "<<p[i].fname<<endl;
                cout<<"Last Name: "<<p[i].lname<<endl;
                cout<<"Course: "<<p[i].course<<endl;
                cout<<"Previous sem GPA: "<<p[i].gpa<<endl;

                cout<<"Are you sure you want to delete this data? [Y/N]: ";
                char del;
                cin>>del;

                if(del == 'Y' || del == 'y'){
                    for(int j = i; j < count - 1; j++) {
                        p[j] = p[j + 1];
                    }
                    count--;
                    cout<<"Student data has been deleted..." << endl;
                } 
                else{
                    cout<<"Student data has not been deleted..." << endl;
                }

                cout<<endl;
                return;
            }
        }

        if (!found) {
            cout<<"Student not found..."<<endl;
        }
    }
}

void viewStudent(Student p[], int count){
    if(count==0){
        cout<<"No student record to view..."<<endl;
        return;
    }
    else{
        int opt;
        cout<<"===VIEW STUDENT DATA==="<<endl;
        cout<<"Choose viewing option: "<<endl;
        cout<<"1] Alphabetically(Last Name)"<<endl;
        cout<<"2] GPA"<<endl;
        cout<<"Your option: ";
        cin>>opt;

        switch(opt){
            case 1:
                cout<<"\n===VIEWING STUDENT DATA ALPHABETICALLY===" << endl;
                for (int i=0; i<count-1; i++){
                    for (int j=i+1; j<count; j++){
                        if (p[i].lname>p[j].lname){
                            Student temp=p[i];
                            p[i]=p[j];
                            p[j]=temp;
                        }
                    }
                }
                break;

            case 2:
                cout<<"\n===VIEWING STUDENT DATA BY GPA==="<<endl;
                for(int i=0; i<count-1; i++){
                    for(int j=i+1; j<count; j++){
                        if(p[i].gpa<p[j].gpa){
                            Student temp=p[i];
                            p[i]=p[j];
                            p[j]=temp;
                        }
                    }
                }
                break;

            default:
                cout<<"Incorrect input, please try again."<<endl;
                return;
        }

        for (int i=0; i < count; i++) {
            cout<<"\nStudent ID: " << p[i].studID<<endl;
            cout<<"First Name: " << p[i].fname<<endl;
            cout<<"Last Name: " << p[i].lname<<endl;
            cout<<"Course: " << p[i].course<<endl;
            cout<<"Previous sem GPA: "<<p[i].gpa<<endl;
        }
        cout<<endl;
    }
}

int main(){
    int opt;
    int count = 0;
    Student p[1000];

    do {
        cout<<"===MENU==="<<endl;
        cout<<"1] Add Student"<<endl;
        cout<<"2] Edit Student"<<endl;
        cout<<"3] Delete Student"<<endl;
        cout<<"4] View Student"<<endl;
        cout<<"5] Exit Program"<<endl;
        cout<<"Enter Option: ";
        cin >> opt;

        system("cls");

        switch (opt) {
            case 1: addStudent(p, count); break;
            case 2: editStudent(p, count); break;
            case 3: deleteStudent(p, count); break;
            case 4: viewStudent(p, count); break;
            case 5: cout<<"Program has ended, Thank you!!!"<<endl; break;
            default: cout<<"Incorrect input, please try again."<<endl;
        }
    } while (opt!=5);
    return 0;
}
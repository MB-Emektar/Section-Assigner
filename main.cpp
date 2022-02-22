#include <iostream>
#include <fstream>
#include <string.h>

#include "Student.h"
#include "Section.h"
#include "Waiting.h"
using namespace std;

void searchQueue(Waiting<Student>* _que, Section<Student>* _wed, Section<Student>* _thu, Section<Student>* _fri){
    cout<<"///////////////"<<endl;
    int length = _que->QLength();
    char* prefs;
    Student* tempStu = new Student();

    while(length){cout<<"loop"<<endl;
        memset(prefs, 0, sizeof (prefs));   // clear the array

        *tempStu = _que->Qdelete();  // take a student from _queue
        prefs = tempStu->getPreferences();

        if(tempStu==NULL)continue;

        if(prefs[1] == 0){
                cout<<"1li "<<tempStu->getID()<<prefs <<" secs full?: "<<_wed->SectionFull()<<_thu->SectionFull()<<_fri->SectionFull()<<endl;
        _que->Qinsert(*tempStu);cout<<"placed"<<endl;
        }
        else if(prefs[2] == 0){
                cout<<"2li "<<tempStu->getID()<<prefs <<" secs full?: "<<_wed->SectionFull()<<_thu->SectionFull()<<_fri->SectionFull()<<endl;
            if(prefs[0] == 'W' && !_wed->SectionFull()){
                if(prefs[1] == 'T' && _thu->SectionFull())_wed->Push(*tempStu);
                else if(prefs[1] == 'F' && _fri->SectionFull())_wed->Push(*tempStu);
                else {_que->Qinsert(*tempStu);cout<<"placed"<<endl;}
            }
            else if(prefs[0] == 'T' && !_thu->SectionFull()){
                if(prefs[1] == 'W' && _wed->SectionFull())_thu->Push(*tempStu);
                else if(prefs[1] == 'F' && _fri->SectionFull())_thu->Push(*tempStu);
                else {_que->Qinsert(*tempStu);cout<<"placed"<<endl;}
            }
            else if(prefs[0] == 'F' && !_fri->SectionFull() ){
                if(prefs[1] == 'W' && _wed->SectionFull() )_fri->Push(*tempStu);
                else if(prefs[1] == 'T' && _thu->SectionFull() )_fri->Push(*tempStu);
                else {_que->Qinsert(*tempStu);cout<<"placed"<<endl;}
            }
            else if(prefs[0] == 'W' && _wed->SectionFull() ){
                if(prefs[1] == 'T' && !_thu->SectionFull() )_thu->Push(*tempStu);
                else if(prefs[1] == 'F' && !_fri->SectionFull() )_fri->Push(*tempStu);
                else {_que->Qinsert(*tempStu);cout<<"placed"<<endl;}
            }
            else if(prefs[0] == 'T' && _thu->SectionFull() ){
                if(prefs[1] == 'W' && !_wed->SectionFull() )_wed->Push(*tempStu);
                else if(prefs[1] == 'F' && !_fri->SectionFull() )_fri->Push(*tempStu);
                else {_que->Qinsert(*tempStu);cout<<"placed"<<endl;}
            }
            else if(prefs[0] == 'F' && _fri->SectionFull() ){
                if(prefs[1] == 'W' && !_wed->SectionFull() )_wed->Push(*tempStu);
                else if(prefs[1] == 'T' && !_thu->SectionFull() )_thu->Push(*tempStu);
                else {_que->Qinsert(*tempStu);cout<<"placed"<<endl;}
            }
        }
        else {
                cout<<"3lu "<<tempStu->getID()<<prefs<<" secs full?: "<<_wed->SectionFull()<<_thu->SectionFull()<<_fri->SectionFull()<<endl;
            if(prefs[0] == 'W' && !_wed->SectionFull() ){
                if(prefs[1] == 'T' && _thu->SectionFull() ){
                    if(prefs[2] == 'F' && _fri->SectionFull() )_wed->Push(*tempStu);
                    else {_que->Qinsert(*tempStu);cout<<"placed"<<endl;}}

                else if(prefs[1] == 'F' && _fri->SectionFull() ){
                    if(prefs[2] == 'T' && _thu->SectionFull() )_wed->Push(*tempStu);
                    else {_que->Qinsert(*tempStu);cout<<"placed"<<endl;}}
                else {_que->Qinsert(*tempStu);cout<<"placed"<<endl;}
            }
            else if(prefs[0] == 'T' && !_thu->SectionFull() ){
                if(prefs[1] == 'W' && _wed->SectionFull() ){
                    if(prefs[2] == 'F' && _fri->SectionFull() )_thu->Push(*tempStu);
                    else {_que->Qinsert(*tempStu);cout<<"placed"<<endl;}}
                else if(prefs[1] == 'F' && _fri->SectionFull() ){
                    if(prefs[2] == 'W' && _wed->SectionFull() )_thu->Push(*tempStu);
                    else {_que->Qinsert(*tempStu);cout<<"placed"<<endl;}}
                else {_que->Qinsert(*tempStu);cout<<"placed"<<endl;}
            }
            else if(prefs[0] == 'F' && !_fri->SectionFull() ){
                if(prefs[1] == 'W' && _wed->SectionFull() ){
                    if(prefs[2] == 'T' && _thu->SectionFull() )_fri->Push(*tempStu);
                    else {_que->Qinsert(*tempStu);cout<<"placed"<<endl;}}
                else if(prefs[1] == 'T' && _thu->SectionFull() ){
                    if(prefs[2] == 'W' && _wed->SectionFull() )_fri->Push(*tempStu);
                    else {_que->Qinsert(*tempStu);cout<<"placed"<<endl;}}
                else {_que->Qinsert(*tempStu);cout<<"placed"<<endl;}
            }

            else if(prefs[0] == 'W' && _wed->SectionFull() ){
                if(prefs[1] == 'T' && !_thu->SectionFull() ){
                    if(prefs[2] == 'F' && _fri->SectionFull() )_thu->Push(*tempStu);
                    else {_que->Qinsert(*tempStu);cout<<"placed"<<endl;}}
                else if(prefs[1] == 'F' && !_fri->SectionFull() ){
                    if(prefs[2] == 'T' && _thu->SectionFull() )_fri->Push(*tempStu);
                    else {_que->Qinsert(*tempStu);cout<<"placed"<<endl;}}
                else if(prefs[1] == 'T' && _thu->SectionFull() ){
                    if(prefs[2] == 'F' && !_fri->SectionFull() )_fri->Push(*tempStu);
                    else {_que->Qinsert(*tempStu);cout<<"placed"<<endl;}}
                else if(prefs[1] == 'F' && _fri->SectionFull() ){
                    if(prefs[2] == 'T' && !_thu->SectionFull() )_thu->Push(*tempStu);
                    else {_que->Qinsert(*tempStu);cout<<"placed"<<endl;}}
                else {_que->Qinsert(*tempStu);cout<<"placed"<<endl;}
            }
            else if(prefs[0] == 'T' && _thu->SectionFull() ){
                if(prefs[1] == 'W' && !_wed->SectionFull() ){
                    if(prefs[2] == 'F' && _fri->SectionFull() )_wed->Push(*tempStu);
                    else {_que->Qinsert(*tempStu);cout<<"placed"<<endl;}}
                else if(prefs[1] == 'F' && !_fri->SectionFull() ){
                    if(prefs[2] == 'W' && _wed->SectionFull() )_fri->Push(*tempStu);
                    else {_que->Qinsert(*tempStu);cout<<"placed"<<endl;}}
                else if(prefs[1] == 'W' && _wed->SectionFull() ){
                    if(prefs[2] == 'F' && !_fri->SectionFull() )_fri->Push(*tempStu);
                    else {_que->Qinsert(*tempStu);cout<<"placed"<<endl;}}
                else if(prefs[1] == 'F' && _fri->SectionFull() ){
                    if(prefs[2] == 'W' && !_wed->SectionFull() )_wed->Push(*tempStu);
                    else {_que->Qinsert(*tempStu);cout<<"placed"<<endl;}}
                else {_que->Qinsert(*tempStu);cout<<"placed"<<endl;}
            }
            else if(prefs[0] == 'F' && _fri->SectionFull() ){
                if(prefs[1] == 'W' && !_wed->SectionFull() ){
                    if(prefs[2] == 'T' && _thu->SectionFull() )_wed->Push(*tempStu);
                    else {_que->Qinsert(*tempStu);cout<<"placed"<<endl;}}
                else if(prefs[1] == 'T' && !_thu->SectionFull() ){
                    if(prefs[2] == 'W' && _wed->SectionFull() )_thu->Push(*tempStu);
                    else {_que->Qinsert(*tempStu);cout<<"placed"<<endl;}}
                else if(prefs[1] == 'W' && _wed->SectionFull() ){
                    if(prefs[2] == 'T' && !_thu->SectionFull() )_thu->Push(*tempStu);
                    else {_que->Qinsert(*tempStu);cout<<"placed"<<endl;}}
                else if(prefs[1] == 'T' && _thu->SectionFull() ){
                    if(prefs[2] == 'W' && !_wed->SectionFull() )_wed->Push(*tempStu);
                    else {_que->Qinsert(*tempStu);cout<<"placed"<<endl;}}
                else {_que->Qinsert(*tempStu);cout<<"placed"<<endl;}
            }
        }
        length--;
    }

}

int main()
{
///////////////////////////////////////////READING FILE/////////////////////////////////////////////
    ifstream prefstxt;                  //create and open the file
    prefstxt.open("preferences.txt");
    int wsize,tsize,fsize;
    char output[100],prefs[3]={0};      //create necessary variables
    int k=0,temp,ID;
    //int wsize,tsize,fsize;

    if (prefstxt.is_open()) {
              //in the first while loop, program extracts the sections and the their sizes
        while (!prefstxt.eof() && k<3) {
                   //catch the section sizes
                prefstxt >> output;
                if(output[0]=='W')wsize = (int)output[2]-48;    // -48 is due to ASCII
                else if(output[0]=='T')tsize = (int)output[2]-48;
                else if(output[0]=='F')fsize = (int)output[2]-48;
                k++;}}
    //create section instances with their sizes
    Section<Student>* wed = new Section<Student>(wsize);
    Section<Student>* thu = new Section<Student>(tsize);
    Section<Student>* fri = new Section<Student>(fsize);
    //create a waiting queue
    Waiting<Student>* que = new Waiting<Student>();

    if (prefstxt.is_open()) {
            //in the second while loop, the remaining students placed in the appropriate places
        while (!prefstxt.eof()) {
                prefstxt >> output;
                ID = ((int)output[0]- 48)*100+((int)output[1]- 48)*10+((int)output[2]- 48);
                prefs[0] = output[4];
                if(output[5]==',')prefs[1] = output[6];//if there is comma, that means there is also a section preference
                if(output[7]==',')prefs[2] = output[8];
                Student* stu = new Student(ID,prefs[0],prefs[1],prefs[2]);
                if(prefs[1]==0 && prefs[2]==0){ //if the student has only one preference, place it if sec is not full
                    if(prefs[0] == 'W' && wed->SectionFull()==0){
                        wed->Push(*stu);
                        searchQueue(que,wed,thu,fri);
                        }
                    else if(prefs[0] == 'T' && thu->SectionFull()==0){
                        thu->Push(*stu);
                        searchQueue(que,wed,thu,fri);
                        }
                    else if(prefs[0] == 'F' && fri->SectionFull()==0){
                        fri->Push(*stu);
                        searchQueue(que,wed,thu,fri);
                        }
                    else que->Qinsert(*stu);//even if the student has one preference,
                                            //if the sec. is full it is placed into queue
                }
                else{//if the student has more than one preference take it to the queue
                    que->Qinsert(*stu);
                }
                memset(prefs, 0, sizeof (prefs));   //the string library is included to clear char array
                memset(output, 0, sizeof (output)); //to avoid any unpredictable mistakes
        }
    }
        prefstxt.close();

///////////////////////////////////////PLACING REMANING STUDENTS/////////////////////////////////////////
        int length = que->QLength();    // get queue length for the while loop
    while(length){
        char* prefs;
        Student* tempStu = new Student();
        *tempStu = que->Qdelete();  // take a student from queue
        prefs = tempStu->getPreferences();
                                    //place him if there is any appropriate section
          if(prefs[0] == 'W' && wed->SectionFull()==0)wed->Push(*tempStu);
          else if(prefs[0] == 'T' && thu->SectionFull()==0)thu->Push(*tempStu);
          else if(prefs[0] == 'F' && fri->SectionFull()==0)fri->Push(*tempStu);
          else if(prefs[1] == 'W' && wed->SectionFull()==0)wed->Push(*tempStu);
          else if(prefs[1] == 'T' && thu->SectionFull()==0)thu->Push(*tempStu);
          else if(prefs[1] == 'F' && fri->SectionFull()==0)fri->Push(*tempStu);
          else if(prefs[2] == 'W' && wed->SectionFull()==0)wed->Push(*tempStu);
          else if(prefs[2] == 'T' && thu->SectionFull()==0)thu->Push(*tempStu);
          else if(prefs[2] == 'F' && fri->SectionFull()==0)fri->Push(*tempStu);
          else {que->Qinsert(*tempStu);}  // if there is not, then it turns back to queue

        memset(prefs, 0, sizeof (prefs));   // clear the array
        length--;
    }

///////////////////////////////////////////RESULTS/////////////////////////////////////////////
    Student* tempStu = new Student();
        ofstream resultstxt;
        resultstxt.open("results.txt");

        ////////////WEDNESDAY///////////
        resultstxt << "Wednesday:" << endl;
        while(!wed->SectionEmpty()){
            *tempStu = wed->Pop();
            resultstxt << tempStu->getID() << endl;
        }
        resultstxt << endl;
        ////////////THURSDAY///////////
        resultstxt << "Thursday:" << endl;
        while(!thu->SectionEmpty()){
            *tempStu = thu->Pop();
            resultstxt << tempStu->getID() << endl;
        }
        resultstxt << endl;
        ////////////WEDNESDAY///////////
        resultstxt << "Friday:" << endl;
        while(!fri->SectionEmpty()){
            *tempStu = fri->Pop();
            resultstxt << tempStu->getID() << endl;
        }
        resultstxt << endl;
        ////////////UNASSIGNED///////////
        resultstxt << "Unassigned:" << endl;
        while(!que->QEmpty()){
            *tempStu = que->Qdelete();
            resultstxt << tempStu->getID() << endl;
        }


        resultstxt.close();


    return 0;

}


#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED


class Student{
private:
  int mID ;
  char mPrefs[3];
public:
    //constructor
  Student(int ID=0, char pref0=0, char pref1=0, char pref2=0);

    //getter methods
  char* getPreferences();
  int getID();

    //setter methods
  void setPreferences(char *Prefs);
  void setID(int ID);

};
    //Constructor
Student::Student(int ID,char pref0,char pref1,char pref2){
    mID = ID;
    mPrefs[0]=pref0;
    mPrefs[1]=pref1;
    mPrefs[2]=pref2;
}
    //Getter functions
char* Student::getPreferences() {
    return mPrefs;
}
int Student::getID() {
    return mID;
}
    //Setter Functions
void Student::setPreferences(char*Prefs){
    mPrefs[0]=Prefs[0];
    mPrefs[1]=Prefs[1];
    mPrefs[2]=Prefs[2];
}
void  Student::setID(int ID) {
    mID=ID;
}

#endif // STUDENT_H_INCLUDED

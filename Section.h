#ifndef SECTION_H_INCLUDED
#define SECTION_H_INCLUDED
#include "Student.h"
using namespace std;

template <class T>
class Section{
    private:
        int mTop;
        int mSize;
        T* mStackList;
    public:
            //Constructor
        Section(int Size);
            //Modification Operators
        void Push(const T& student);
        T Pop(void);
            //To copy w/out changing
        T Peek(void) ;
            //
        int SectionEmpty(void);
        int SectionFull(void);


};
    //Constructor
template <class T>
Section<T>::Section(int Size){
    mTop = -1;
    mSize= Size;
    mStackList = new T[Size];
}
    //Push
template <class T>
void Section<T>::Push(const T& student){
    if (SectionFull()){
        cout<<"Section is FULL!"<<endl;
        exit(1);}
        mTop++;
        mStackList[mTop]=student;
}
    //Pop
template <class T>
T Section<T>::Pop(void){
    T temp;
    if (SectionEmpty()){
        cout<<"Section is EMPTY!"<<endl;
        exit(1);}
    temp = mStackList[mTop];
    mTop--;
    return temp;
}
    //Peek
template <class T>
T Section<T>::Peek(void){
    T temp;
    if (SectionEmpty()){
        cout<<"Section is EMPTY!"<<endl;
        exit(1);}
    temp = mStackList[mTop];
    return temp;
}
    //Is stack empty?
template <class T>
int Section<T>::SectionEmpty(void){
    return (mTop==-1);
}
    //Is stack full?
template <class T>
int Section<T>::SectionFull(void){
    return (mTop == (mSize-1));
}




#endif // SECTION_H_INCLUDED

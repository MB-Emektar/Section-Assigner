#ifndef WAITING_H_INCLUDED
#define WAITING_H_INCLUDED

using namespace std;
const int MaxQSize = 500;
template <class T>
class Waiting{
    private:
        int mFront, mRear, mCount;
        T mList[MaxQSize];
    public:
            //Constructor
        Waiting(void);//
            //Modification
        void Qinsert(const T& student);//
        T Qdelete(void);
        void ClearQueue(void);
            //Queue access
        T Qfront(void);
            //Test methods
        int QLength(void);//
        int QEmpty(void);//
        int QFull(void);//

};

template <class T>
Waiting<T>::Waiting(void):mFront(0), mRear(0), mCount(0){}

template <class T>
int Waiting<T>::QLength(void){
    return mCount;
}

template <class T>
int Waiting<T>::QEmpty(void){
return(mCount ==0);
}

template <class T>
int Waiting<T>::QFull(void){
return(mCount==MaxQSize);
}

template <class T>
void Waiting<T>::Qinsert(const T& student){
    if (QFull()){
        cout<<"Queue OVERFLOW!"<<endl;
        exit(1);
    }
    mCount++;
    mList[mRear]=student;
    mRear = (mRear+1)%MaxQSize;
}

template <class T>
T Waiting<T>::Qdelete(void){
    T temp;
    if (QEmpty()){
        cout<<"No item to delete!"<<endl;
        exit(1);
    }
    temp=mList[mFront];
    mCount--;
    mFront=(mFront+1)%MaxQSize;
    return temp;
}

template <class T>
T Waiting<T>::Qfront(void){
    return mList[mFront];
}
#endif // WAITING_H_INCLUDED

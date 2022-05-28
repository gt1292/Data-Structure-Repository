#include<iostream>

using namespace std;

class Number
{
    private:
        int iNO;    //characteristics


    public:
        void Accept()
        {
            cout<<"Enter the value :";
            cin>>this->iNO;
        }

        void display()
        {
            cout<<"Value is:"<<this->iNO<<endl;
        }

        int Factorial()
        {
            int iFact = 1;
            int iCnt = 0;

            for(iCnt =1; iCnt<=iNO; iCnt++)
            {
                iFact *= iCnt;   //iFact = iFact*iCnt;
            }
            return iFact;
        }
};

int main()
{
    Number nobj1;
    Number nobj2;

    int iRet = 0;

    nobj1.Accept();
    nobj1.display();
    iRet = nobj1.Factorial();
    cout<<"Factorial is :"<<iRet<<endl;

    nobj2.Accept();
    nobj2.display();
    iRet = nobj2.Factorial();
    cout<<"Factorial is :"<<iRet;

    return 0;
}
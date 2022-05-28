#include <iostream>

using namespace std;

class ArrayX
{
private:
    int *Arr;
    int iSize;

public:
    ArrayX(int iValue)  //step:2
    {
        this->iSize = iValue;  //initialisation
        Arr = new int[iSize]; // Allocate Resource
    }
    ~ArrayX() // Destructor
    {
        delete[] Arr; // Deallocate the resource
    }

    void Accept()   //Step:4
    {
        int iCnt = 0;

        cout << "Enter the elements :" << endl;
        for (iCnt = 0; iCnt < iSize; iCnt++)
        {
            cin >> Arr[iCnt];
        }
    }

    void Display()      //Step:6
    {
        int iCnt = 0;
        cout << "elements of array:" << endl;
        for (iCnt = 0; iCnt < iSize; iCnt++)
        {
            cout << Arr[iCnt] << endl;
        }
    }

    int Sumation()      //Step:8
    {
        int iSum = 0, iCnt = 0;

        for (iCnt = 0; iCnt < iSize; iCnt++)
        {
            iSum = iSum + Arr[iCnt];
        }
        return iSum;
    }
};

int main()
{
    int iRet = 0;

    ArrayX obj1(5);     //step:1

    obj1.Accept();      //Step:3 Accept(&obj1)
    obj1.Display();     //Step :5

    iRet = obj1.Sumation();     //step:7

    cout<<"Addition is :"<<iRet<<endl;

    return 0;
}
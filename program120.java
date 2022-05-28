/*

*       *       *       *
*       *       *       *
*       *       *       *
*       *       *       *

*/

class Pattern
{
    private int iRow,iCol;

    public Pattern(int a,int b)
    {
        iRow =a;
        iCol =b;
    }
    public void Display()
    {
        int i = 0, j = 0;

        for (i = 1; i <= iRow; i++)
        {
            for (j = 1; j <= iCol; j++)
            {
               System.out.print("*\t");
            }
            System.out.println();
        }
    }
}

public class program120 {
    public static void main(String[] args) {

        Pattern obj = new Pattern(4, 4);
        obj.Display();
    }
}

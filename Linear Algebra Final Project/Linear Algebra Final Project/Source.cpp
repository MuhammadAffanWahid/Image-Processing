#include<iostream>
#include<fstream>
#include<Windows.h>
#include<conio.h>
#include <math.h>
#include <stdio.h>

using namespace std;


#define SIN(x) sin(x * 3.141592653589 / 180)
#define COS(x) cos(x * 3.141592653589 / 180)

void getRowColbyLeftClick(int& rpos, int& cpos)
{
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    DWORD Events;
    INPUT_RECORD InputRecord;
    SetConsoleMode(hInput, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
    do
    {
        ReadConsoleInput(hInput, &InputRecord, 1, &Events);
        if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
        {
            cpos = InputRecord.Event.MouseEvent.dwMousePosition.X;
            rpos = InputRecord.Event.MouseEvent.dwMousePosition.Y;
            break;
        }
    } while (1);

    //cpos = cpos / 2;
}
void gotoRowCol(int rpos, int cpos)
{
    COORD scrn;
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = cpos;
    scrn.Y = rpos;
    SetConsoleCursorPosition(hOuput, scrn);
}
void color(int k)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, k);
}

//void swap(char* a, char* b)
//{
//    char temp = *a;
//    *a = *b;
//    *b = temp;
//}
void FlipRow(char* row)
{
    // A row is a simple one dimensional array
    // just swap item 0 with item n-1, 1 with n-2, ...
    for (int index = 0; index <= 61; index++)
    {
        swap(row[index], row[122-index]);
    }
}
void Horizontlerefliction(char** Matrix)
{
    for (int row = 0; row < 123; row++)
    {
        FlipRow(Matrix[row]);
    }
}
void Verticlerefliction(char** Matrix)
{
    char* temp;
    for (int col = 0; col < 61; col++)
    {
        swap(Matrix[col], Matrix[122 - col]);
    }
}
//1 2 3 4 5
//6 7 8 9 10      
// A[0]=
void read_file(char** Matrix)
{
    ifstream Rdr;
    Rdr.open("facebook.txt");
    int num;
    for (int i = 0; i < 123; i++)
    {
        for (int j = 0; j < 123; j++)
        {
            //Rdr.get(Matrix[i][j]);
            Rdr >> num;
            Matrix[i][j] = char(num);
        }
    }
    Rdr.close();
}
void write_file(char** Matrix)
{
    ofstream Wrt;
    Wrt.open("facebook.txt");
    for (int i = 0; i < 123; i++)
    {
        for (int j = 0; j < 123; j++)
        {
            Wrt << int(Matrix[i][j])<<" ";
        }
        Wrt << endl;
    }
    Wrt.close();
} 
void print_matrix(char** Matrix,int r,int c)
{
    for (int i = 0; i < 123; i++)
    {
        gotoRowCol(r + i, c);
        for (int j = 0; j < 123; j++)
        {
            cout<< Matrix[i][j];
        }
        cout << endl;
    }
}
void transpose(char** Matrix)
{

    char** transMatrix=new char*[123];
    for (int i = 0; i < 123; i++)
        transMatrix[i] = new char [123];

    for (int i = 0; i < 123; i++)
    {
        for (int j = 0; j < 123; j++) 
        {
            transMatrix[j][i] = Matrix[i][j];
        }
    }
    for (int i = 0; i < 123; i++)
    {
        for (int j = 0; j < 123; j++)
        {
            Matrix[i][j] = transMatrix[i][j];
        }
    }
}
void rotateMatrixAnticlockwise(char** Matrix)
{
    // Consider all squares one by one 
    for (int x = 0; x < 123 / 2; x++)
    {
        // Consider elements in group 
        // of 4 in current square 
        for (int y = x; y < 123 - x - 1; y++)
        {
            // Store current cell in 
            // temp variable 
            int temp = Matrix[x][y];

            // Move values from right to top 
            Matrix[x][y] = Matrix[y][123 - 1 - x];

            // Move values from bottom to right 
            Matrix[y][123 - 1 - x]
                = Matrix[123 - 1 - x][123 - 1 - y];

            // Move values from left to bottom 
            Matrix[123 - 1 - x][123 - 1 - y]
                = Matrix[123 - 1 - y][x];

            // Assign temp to left 
            Matrix[123 - 1 - y][x] = temp;
        }
    }
}
void rotateMatrixClockwise(char** Matrix)
{

    for (int i = 0; i < 123 / 2; i++) 
    {
        for (int j = i; j < 123 - i - 1; j++) 
        {

            int temp = Matrix[i][j];
            Matrix[i][j] = Matrix[123 - 1 - j][i];
            Matrix[123 - 1 - j][i] = Matrix[123 - 1 - i][123 - 1 - j];
            Matrix[123 - 1 - i][123 - 1 - j] = Matrix[j][123 - 1 - i];
            Matrix[j][123 - 1 - i] = temp;
        }
    }
}

int main()
{
    int r = 0, c = 0;
    char** Matrix = new char* [123];
    for (int i = 0; i < 123; i++)
        Matrix[i] = new char[123];

    read_file(Matrix);
    print_matrix(Matrix, 190, 300);

    while (true)
    {
        color(2);
        gotoRowCol(140, 0);
        cout<<"88888888ba                                                            ,ad8888ba,   88                           88                            88                         "<<endl;
        cout<<"88      `8b               ,d                   ,d                    d8`'    ``8b  88                           88                            ``                         "<<endl;
        cout<<"88      ,8P               88                   88                   d8'            88                           88                                                       "<<endl;
        cout<<"88aaaaaa8P'  ,adPPYba,  MM88MMM  ,adPPYYba,  MM88MMM  ,adPPYba,     88             88   ,adPPYba,    ,adPPYba,  88   ,d8  8b      db      d8  88  ,adPPYba,   ,adPPYba,  "<<endl;
        cout<<"88````88'   a8`     `8a   88     ``     `Y8    88    a8P_____88     88             88  a8`     `8a  a8`     ``  88 ,a8`   `8b    d88b    d8'  88  I8[    ``  a8P_____88  "<<endl;
        cout<<"88    `8b   8b       d8   88     ,adPPPPP88    88    8PP```````     Y8,            88  8b       d8  8b          8888[      `8b  d8'`8b  d8'   88   ``Y8ba,   8PP```````  "<<endl;
        cout<<"88     `8b  `8a,   ,a8`   88,    88,    ,88    88,   `8b,   ,aa      Y8a.    .a8P  88  `8a,   ,a8`  `8a,   ,aa  88``Yba,    `8bd8'  `8bd8'    88  aa    ]8I  `8b,   ,aa  "<<endl;
        cout<<"88      `8b  ``YbbdP`'    `Y888  ``8bbdP`Y8    `Y888  ``Ybbd8`'       ``Y8888Y`'   88   ``YbbdP`'    ``Ybbd8`'  88   `Y8a     YP      YP      88  ``YbbdP`'   ``Ybbd8`'  "<<endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;                                                                                                                                                                                                                    
        color(4);
        cout<<"88888888ba                                                                 db                              88              88                           88                            88                         "<<endl;
        cout<<"88      `8b               ,d                   ,d                         d88b                      ,d     ``              88                           88                            ``                         "<<endl;
        cout<<"88      ,8P               88                   88                        d8'`8b                     88                     88                           88                                                       "<<endl;
        cout<<"88aaaaaa8P'  ,adPPYba,  MM88MMM  ,adPPYYba,  MM88MMM  ,adPPYba,         d8'  `8b      8b,dPPYba,  MM88MMM  88   ,adPPYba,  88   ,adPPYba,    ,adPPYba,  88   ,d8  8b      db      d8  88  ,adPPYba,   ,adPPYba,  "<<endl;
        cout<<"88````88'   a8`     `8a   88     ``     `Y8    88    a8P_____88        d8YaaaaY8b     88P'   ``8a   88     88  a8`     ``  88  a8`     `8a  a8`     ``  88 ,a8`   `8b    d88b    d8'  88  I8[    ``  a8P_____88  "<<endl;
        cout<<"88    `8b   8b       d8   88     ,adPPPPP88    88    8PP```````       d8````````8b    88       88   88     88  8b          88  8b       d8  8b          8888[      `8b  d8'`8b  d8'   88   ``Y8ba,   8PP```````  "<<endl;
        cout<<"88     `8b  `8a,   ,a8`   88,    88,    ,88    88,   `8b,   ,aa      d8'        `8b   88       88   88,    88  `8a,   ,aa  88  `8a,   ,a8`  `8a,   ,aa  88``Yba,    `8bd8'  `8bd8'    88  aa    ]8I  `8b,   ,aa  "<<endl;
        cout<<"88      `8b  ``YbbdP`'    `Y888  ``8bbdP`Y8    `Y888  ``Ybbd8`'     d8'          `8b  88       88   `Y888  88   ``Ybbd8`'  88   ``YbbdP`'    ``Ybbd8`'  88   `Y8a     YP      YP      88  ``YbbdP`'   ``Ybbd8`'  "<<endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        color(5);
        cout<<"88888888ba                 ad88  88                                      8b           d8                                88                          88  88               "<<endl;
        cout<<"88      `8b               d8`    88                            ,d        `8b         d8'                         ,d     ``                          88  88               "<<endl;
        cout<<"88      ,8P               88     88                            88         `8b       d8'                          88                                 88  88               "<<endl;
        cout<<"88aaaaaa8P'  ,adPPYba,  MM88MMM  88   ,adPPYba,   ,adPPYba,  MM88MMM       `8b     d8'  ,adPPYba,  8b,dPPYba,  MM88MMM  88   ,adPPYba,  ,adPPYYba,  88  88  8b       d8  "<<endl;
        cout<<"88````88'   a8P_____88    88     88  a8P_____88  a8`     ``    88           `8b   d8'  a8P_____88  88P'   `Y8    88     88  a8`     ``  ``     `Y8  88  88  `8b     d8'  "<<endl;
        cout<<"88    `8b   8PP```````    88     88  8PP```````  8b            88            `8b d8'   8PP```````  88            88     88  8b          ,adPPPPP88  88  88   `8b   d8'   "<<endl;
        cout<<"88     `8b  `8b,   ,aa    88     88  `8b,   ,aa  `8a,   ,aa    88,            `888'    `8b,   ,aa  88            88,    88  `8a,   ,aa  88,    ,88  88  88    `8b,d8'    "<<endl;
        cout<<"88      `8b  ``Ybbd8`'    88     88   ``Ybbd8`'   ``Ybbd8`'    `Y888           `8'      ``Ybbd8`'  88            `Y888  88   ``Ybbd8`'  ``8bbdP`Y8  88  88      Y88'     "<<endl;
        cout<<"                                                                                                                                                                 d8'     "<<endl;
        cout<<"                                                                                                                                                                 d8'     "<<endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        color(9);
        cout << "88888888ba                 ad88  88                                      88        88                           88                                                           88  88               " << endl;
        cout << "88      `8b               d8`    88                            ,d        88        88                           ``                                        ,d                 88  88               " << endl;
        cout << "88      ,8P               88     88                            88        88        88                                                                     88                 88  88               " << endl;
        cout << "88aaaaaa8P'  ,adPPYba,  MM88MMM  88   ,adPPYba,   ,adPPYba,  MM88MMM     88aaaaaaaa88   ,adPPYba,   8b,dPPYba,  88  888888888   ,adPPYba,   8b,dPPYba,  MM88MMM  ,adPPYYba,  88  88  8b       d8  " << endl;
        cout << "88````88'   a8P_____88    88     88  a8P_____88  a8`     ``    88        88````````88  a8`     `8a  88P'   `Y8  88       a8P`  a8`     `8a  88P'   ``8a   88     ``     `Y8  88  88  `8b     d8'  " << endl;
        cout << "88    `8b   8PP```````    88     88  8PP```````  8b            88        88        88  8b       d8  88          88    ,d8P'    8b       d8  88       88   88     ,adPPPPP88  88  88   `8b   d8'   " << endl;
        cout << "88     `8b  `8b,   ,aa    88     88  `8b,   ,aa  `8a,   ,aa    88,       88        88  `8a,   ,a8`  88          88  ,d8`       `8a,   ,a8`  88       88   88,    88,    ,88  88  88    `8b,d8'    " << endl;
        cout << "88      `8b  ``Ybbd8`'    88     88   ``Ybbd8`'   ``Ybbd8`'    `Y888     88        88   ``YbbdP`'   88          88  888888888   ``YbbdP`'   88       88   `Y888  ``8bbdP`Y8  88  88      Y88'     " << endl;
        cout << "                                                                                                                                                                                          d8'     " << endl;
        cout << "                                                                                                                                                                                          d8'     " << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        color(12);
        cout << "888888888888                                                                                              " << endl;
        cout << "     88                                                                                                   " << endl;
        cout << "     88                                                                                                   " << endl;
        cout << "     88  8b,dPPYba,  ,adPPYYba,  8b,dPPYba,   ,adPPYba,  8b,dPPYba,    ,adPPYba,   ,adPPYba,   ,adPPYba,  " << endl;
        cout << "     88  88P'   `Y8  ``     `Y8  88P'   ``8a  I8[    ``  88P'    `8a  a8`     `8a  I8[    ``  a8P_____88  " << endl;
        cout << "     88  88          ,adPPPPP88  88       88   ``Y8ba,   88       d8  8b       d8   ``Y8ba,   8PP```````  " << endl;
        cout << "     88  88          88,    ,88  88       88  aa    ]8I  88b,   ,a8`  `8a,   ,a8`  aa    ]8I  `8b,   ,aa  " << endl;
        cout << "     88  88          ``8bbdP`Y8  88       88  ``YbbdP`'  88`YbbdP`'    ``YbbdP`'   ``YbbdP`'   ``Ybbd8`'  " << endl;
        cout << "                                                         88                                               " << endl;
        cout << "                                                         88                                               " << endl;
        color(10);
        getRowColbyLeftClick(r, c);
        cout << r << " " << c;
        if ((r >= 140 && r <= 147) && (c >= 0 && c <= 166))
        {
            rotateMatrixClockwise(Matrix);
            print_matrix(Matrix, 190, 300);
        }
        else if ((r >= 150 && r <= 167) && (c >= 0 && c <= 206))
        {
            rotateMatrixAnticlockwise(Matrix);
            print_matrix(Matrix, 190, 300);
        }
        else if ((r >= 166 && r <= 175) && (c >= 0 && c <= 166))
        {
            Verticlerefliction(Matrix);
            print_matrix(Matrix, 190, 300);
        }
        else if ((r >= 181 && r <= 190) && (c >= 0 && c <= 191))
        {
            Horizontlerefliction(Matrix);
            print_matrix(Matrix, 190, 300);
        }
        else if ((r >= 196 && r <= 205) && (c >= 0 && c <= 103))
        {
            transpose(Matrix);
            print_matrix(Matrix, 190, 300);
        }
    }

   // write_file(Matrix);
    return 0;
}



    //void Dabba(double a,double b)
//{
//    int y = round(a);
//    int x = round(b);
//    //gotoRowCol(x,y);
//    //cout << "#";
//    //gotoRowCol(x-1, y);
//    //cout << "#";
//    //gotoRowCol(x, y-1);
//    //cout << "#";
//    //gotoRowCol(x-1, y-1);
//    //cout << "#";
//    //gotoRowCol(x+1, y);
//    //cout << "#";
//    //gotoRowCol(x, y+1);
//    //cout << "#";
//    //gotoRowCol(x-1, y+1);
//    //cout << "#";
//    //gotoRowCol(x+1, y-1);
//    //cout << "#";
//    //gotoRowCol(x+1, y+1);
//    //cout << "#";
//
//        gotoRowCol(x, y);
//        cout << "88888888ba                                                       " << endl;
//        gotoRowCol(x+1, y);
//        cout << "88      `8b               ,d                   ,d                " << endl;
//        gotoRowCol(x+2, y);
//        cout << "88      ,8P               88                   88                " << endl;
//        gotoRowCol(x+3, y);
//        cout << "88aaaaaa8P'  ,adPPYba,  MM88MMM  ,adPPYYba,  MM88MMM  ,adPPYba,  " << endl;
//        gotoRowCol(x+4, y);
//        cout << "88````88'   a8`     `8a   88     ``     `Y8    88    a8P_____88  " << endl;
//        gotoRowCol(x+5, y);
//        cout << "88    `8b   8b       d8   88     ,adPPPPP88    88    8PP```````  " << endl;
//        gotoRowCol(x+6, y);
//        cout << "88     `8b  `8a,   ,a8`   88,    88,    ,88    88,   `8b,   ,aa  " << endl;
//        gotoRowCol(x+7, y);
//        cout << "88      `8b  ``YbbdP`'    `Y888  ``8bbdP`Y8    `Y888  ``Ybbd8`'  " << endl;
//
//}
//void Rotate(double& x, double& y,int theta)
//{
//    double  tempx=x* COS(theta) - y * SIN(theta);
//    double  tempy=x * (-SIN(theta)) - y * COS(theta);
//    x = tempx;
//    y = tempy;
//}
//void RotateDabba(double P_x, double P_y)
//{
//    double x=200, y=100;
//    double tempx=x, tempy=y;
//   // Dabba(x,y);
//    //system("cls");
//   /// y *= -1;
//    //x *= -1;
//    for (int i = 0; i < 360; i++)
//    {
//        Dabba(x, y);
//        x = x - P_x;
//        y = y - P_y;
//        y *= -1;
//
//        Rotate(x, y, 1);
//        x = x + P_x;
//        y = y + P_y;
//        _getch();
//        system("cls");
//        Dabba(x, y);
//        //system("cls");
//    }
//    Rotate(x,y, 30);
//    Dabba(x, y);
//}
//void RotateMatrix(char** Matrix)
//{
//    char** Rotated = new char* [123];
//    for (int i = 0; i < 123; i++)
//        Rotated[i] = new char[123];
//    for (int a = 0; a < 360; a++)
//    {
//        for (double i = 0; i < 123; i++)
//        {
//            for (double j = 0; j < 123; j++)
//            {
//                double tempi = i;
//                double tempj = j;
//                Rotate(tempj, tempi, a);
//                Rotated[int(tempi)][int(tempj)] = Matrix[int(i)][int(j)];
//            }
//        }
//        _getch();
//        system("cls");
//        print_matrix(Rotated, 40, 40);// e
//    }
//}

    //cout << "MMMMMdddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddM" << endl;
    //cout << "MMMMmyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyM" << endl;
    //cout << "MM123hyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyM" << endl;
    //cout << "MmyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyM" << endl;
    //cout << "MyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyM" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyysssooo+++++++++++oooooosssssssyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyso+/-..``                       ````...+yyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyys+:.`                                      /yyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyo:.                                           /yyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyys/.                                              /yyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyo-                                                 /yyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyys:                                                   /yyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy/`                                                    /yyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyys-                                                      /yyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyys.                                                       /yyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyys`                                                        /yyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy.                                                         /yyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy-                                                          /yyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyo                                                           /yyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy.                                        ```````````````````/yyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyo                                   .:+ossyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy:                                `/syyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy`                               -syyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy                               .yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyys                               oyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyo                              `yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyo                              .yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyo                              .yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyo                              .yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyo                              .yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyo                              .yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyo                              .yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyo                              .yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyo                              .yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyo                              .yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyo                              .yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyo                              .yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyys.........................`                               .............................oyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyys                                                                                      syyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyys                                                                                     .yyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyys                                                                                     :yyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyys                                                                                     +yyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyys                                                                                     syyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyys                                                                                    .yyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyys                                                                                    :yyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyys                                                                                    +yyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyys                                                                                    syyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyys                                                                                   .yyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyys                                                                                   :yyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyys                                                                                   +yyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyys                                                                                   syyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyys                                                                                  .yyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyy/////////////////////////:                              `/////////////////////////oyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyo                              .yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyo                              .yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyo                              .yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyo                              .yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyo                              .yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyo                              .yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyo                              .yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyo                              .yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyo                              .yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyo                              .yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyo                              .yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyo                              .yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyo                              .yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyo                              .yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyo                              .yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyo                              .yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyo                              .yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyo                              .yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyo                              .yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyo                              .yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyo                              .yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyo                              .yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyo                              .yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyo                              .yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyo                              .yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyo                              .yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyo                              .yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyo                              .yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyo                              .yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyo                              .yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyo                              .yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyo                              .yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyo                              .yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyo                              .yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "Myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyo                              .yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyM" << endl;
    //cout << "Mmyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyo                              .yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyM" << endl;
    //cout << "MM123hyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyo                              .yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyM" << endl;
    //cout << "MMMMmyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyo                              .yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyM" << endl;
    //cout << "MMMMMdddddddddddddddddddddddddddddddddddddddddddddy::::::::::::::::::::::::::::::+ddddddddddddddddddddddddddddddddddddddddM" << endl;
    //cout << "MMMMMdddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddM" << endl;
    //cout << "MMMMmyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyM" << endl;
    //cout << "MM123hyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyM" << endl;
    //cout << "MmyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyM" << endl;
    //cout << "MyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyM" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "MMMMMdddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddM" << endl;
    //cout << "MMMMmyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyM" << endl;
    //cout << "MM123hyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyM" << endl;
    //cout << "MmyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyM" << endl;
    //cout << "MyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyM" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyym" << endl;
    //cout << "MMMMMdddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddM" << endl;
    //cout << "MMMMmyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyM" << endl;
	                                                                                                                                                                                                                                                                                 
/*                                                                                                                                                                                                                                                                                 
                                                                                                                                                                                                                                                                                 
cout<<"                                                                            .I;,.                                                                                                                                                         "<<endl;
cout<<"                                                                            :/Q01I'                                                                                                                                                       "<<endl;
cout<<"                                                                            lc_moZ1l.                                                                                                                                                     "<<endl;
cout<<"                                                                           .!L<)wa*w1l'                                                                                                                                                   "<<endl;
cout<<"                                                                           .~Z[Ijwho#w(l'                                                                                                                                                 "<<endl;
cout<<"                                                                           '_Zf:_cmko*#q(!'                                                                                                                                               "<<endl;
cout<<"                                                                           '[qv>`[Ymkao*#q|!'                                      ':-f>`                                                                                                 "<<endl;
cout<<"                                                                           `1qX-`>}Jmkao*##w/i'                                 `l(c-Ozti.                                                                                                "<<endl;
cout<<"                                                                           `|dJ};`+)Jmbhao*##d/i`                            ^!rwul|k#rr!.                                                                                                "<<endl;
cout<<"                                                                           `xdQ|>`;_rJZbkao**#*df>`                      .`+cw0t!+Yhow|fI                                                                                                 "<<endl;
cout<<"                                                                           :ud0x_`'i-nUZdkaao*##*br-<~++<il;:,^^'.    ',?UpmY)ii/Oao*jt/;                                                                                                 "<<endl;
cout<<"                                                                           ;UdOc[I``>-uUOdbhao***o**********####qz{~>10dq0z1<l?zwaooa~n),                                                                                                 "<<endl;
cout<<"                                                                           IQdmY)<^.;<[vLdaoooooooooo*********####*kdpmLu1+!-/Jpaoo*O,c{`                                                                                                 "<<endl;
cout<<"                                                                          .!OdwJ/-``[Qaoooooooooooooooo********okddqOJx)_i_}cQbaooa#u`c]^                                                                                                 "<<endl;
cout<<"                                                                          .<qdwLUdaaaaaaaaoooooooooooooo****obbdpw0Ur(->+[tYOboooaob)`Y-`                                                                                                 "<<endl;
cout<<"                                                                          '-dhaaaaaaaaaaaaaaaaoooooooooooo*addqZQXr|]++[1vJwboooaaoZ-:z+'                                                                                                 "<<endl;
cout<<"                                                                        'Irhaaaaaaaaaaaaaaaaaaaaaaoooooooo*dwOQzr/[_+]{tYLpkoooaao*Ji>v<.                                                                                                 "<<endl;
cout<<"                                                                      .:uaaaaaaaaaahhhhhhhhhhhhhhaaaaaooooomCcxt}?_]{)vJ0dkoooaaaoar;[z~.                                                                                                 "<<endl;
cout<<"                                                                     ^?daaaaaahhhhhkkkkbbbbbbbkkkhhhaaaoooohnt1[?]{)jYCZbko*oaahaop/,/#X_^                                                                                                "<<endl;
cout<<"                                                                   'lJaaaaaahhhhkkbbddppppppdddbbkkkhhhaaoook([]{)/vULwbko*oaahha*m)`cWWq);.                                                                                              "<<endl;
cout<<"                                                 ..''^`,:;l!<-1(rcY0haaaaahhhkkbdppqqwwwwwwwwqqppddbbkkhhaaoooj(|rYJ0pbkoooaahkao*J1,LWWW*Ocr|[_>il;:,`^'..                                                                               "<<endl;
cout<<"                                      .^!~-[1txcJQZwpbkhkhkkkkkkkkkaaaaaahhkbddpqwmmZZZOOOOZZZmwwqqpdbbkhhaaoo*mzULOdbhoooaahkkaokz[:OWWWWW*oooooooooahbpw0);.                                                                            "<<endl;
cout<<"                                      ,f/>i?(rzYJCQ0OZmwwwwwqqqqqqhaaaahhkkbdpqwmZOO0QQQLLLQQQ00OZmwqpdbkhhaaooo*aqdbhoooaahkkhaoqv];hWWWWWW#******###MMWYc|l.                                                                            "<<endl;
cout<<"                                      .;[CbL|>`.'`:Il>-})/jxxnnuvwaaaahhkkbdpqwZO0QLCJUUYYYYUJCLQOZmwqddbkhhaaoo*******oaahkkkhaoZv?pWWWWWWMW#####MMMW#j|0|I.                                                                             "<<endl;
cout<<"                                        .;}0abOc)_l^. .'`^`,,:I!zaaaahhhkbdpwmZ0QCJYXzccccczXUJCLQOZmwpdbbkhaaooo***#####*akkkhoopoWWWWWWMMMMMMMMMW&bt}JY]`                                                                               "<<endl;
cout<<"                                          .I1mohbmLu([+I^.     `aaaaahhkbdpwmOQCJYzcvvvvvvcczXUUCL0OZmqpdbkkhaaoo****######MMMMMMMWWWWWWMM##***MWWw|1xmr>'                                                                                "<<endl;
cout<<"                                            'i(woahbw0Jn|{?~I`'LaaaaahkbdpwmOQCUYzccvvuuuvvvczXUJCQ0Omwqpdbkhaaoo***######MMMMMMMMWWWWW&M#*oaahaLt(fLQ(I.                                                                                 "<<endl;
cout<<"                                              'i/qoaakbwOQYx/))aaaaahhkbpqmO0LCUYzcvvuuunuuvvczYUJCQOZmqpdbkhaaoo****#####MMMMMMMWWWWWW&M*ohkbddUjXmX?`                                                                                   "<<endl;
cout<<"                                                `itdooahkbqmOLhaaaaahkbdpqmZ0QCUYXcvvuunnnuuvvzXYJCQOZwqpbkkhhkkkkhhhaao**MMMMMMMWWWWWW&&ohbpqmmwOmr>'                                                                                    "<<endl;
cout<<"                                                  ^<xkooaahkbhaaaaaahkkbpqwZOQLJYXzcvuunnnnuvczYUCQ0Zmqpdbkppdddbbkkhhaao***#MMMWWWWWW&&&obdwZO00px!                                                                                      "<<endl;
cout<<"                                                    ^~xboooaaaaaaaaahhkbdpwmO0LCUXzcvvuuuuvczXYJCQ0Omwqpdmmwwqqdddbbkhhaao*****MWWWWWW&&&#bqm0LJJQrl                                                                                      "<<endl;
cout<<"                                                      ^+uaooooaaaaaaahkbdpqmZ0QCJYXzcccczzzYUJCLQ0OmwqpqOOOOOmmwwpddbbkhaao****oMWWWWW&&&MdqZQJXzUv<.                                                                                     "<<endl;
cout<<"                                                        ,?XoooooaaaaahhkbdqwmO0QLCJJUYYUUUUJCLQ00ZmwqppO0000000OZmwqpdbkhhao***od#WWW&&&&&dqZLUzvYz+.                                                                                     "<<endl;
cout<<"                                                         .IfoooooaaaaahkbddpwmmZO0QQLCCLLLLQQ0OZZmwqpdmZO00QQQQQQQ0Omwpdbkhao**opCWW&&&&&8bqZLUzcUY_'                                                                                     "<<endl;
cout<<"                                                          ^|ooooooaaaahhkkbdpqqwmZZOO00000OOOZmmwqqddpmmmmZZO0QQLLLLLQOZqdbhao**qchW&&&&&8kpm0CUYJU?`                                                                                     "<<endl;
cout<<"                                                          ^)oooooooooaaahhkkbdppqqwwmmmmmmmmmwqqpdbbkdppppqqwmmZZO0QCCJCL0mdkao*qrq&&&&&&8adqZ0LCLJ]`                                                                                     "<<endl;
cout<<"                                                          `)ooooooooooaaahhhkkbddppqqqqqqqqpppdbbkkhhbbbdddddddpppqwmZOQCJUCOph*Z|d&&&&&&&akdqmO0OU_'                                                                                     "<<endl;
cout<<"                                                        .IvdhoooooooooooaaahhhkkbbbdddddddbbbkkkhhhaahkkkkkkkkkkkkkkbbbdddqmOCCpJv#&&&&&&&*akdpwmO0tI.                                                                                    "<<endl;
cout<<"                                                       ^}pdqOo*ooooooooooooaaahhhhkkkkkkkkkhhhhaaaaooohhhhhhhhhhaaaaaaaaaooooobLwd&&&&&&&W#oakbdbx|vc-`                                                                                   "<<endl;
cout<<"                                                     .iCdqOLvL**ooooooooooooooaaaaaaaaaaaaaaaaoooooo**oaaaooooooooooooooooabOvJqd&&&&&&&&WM#oahhkJj11vfi'                                                                                 "<<endl;
cout<<"                                                    ,tdpZLuf(]q*****oooooooooooooooooaooooooooooo****##oooooooooooooooaabwCccQqdW&&&&&&&&WM#**oa*WWkc1[u}:                                                                                "<<endl;
cout<<"                                                  `+ZpZCuf)]][}b****************oo*ooooooooo******######*ooooooooooaakdmCzvX0whWWWW&&&&&&WMM#*ooMWWWWWq/}j+`                                                                              "<<endl;
cout<<"                                                .;cdmLnf{[}1/jnv*****************************############M*oooooaahbdmLYczU0bWWWWWWWW&&&WWMM#*o*##MMMWWWWX|1I.                                                                            "<<endl;
cout<<"                                               ^{wwJn/{{(fruYLOmd#**************************##########MMMMMMM*aahbdm0JXcYZoMMMMMMMMWWWWWWMM#*odqpdbkaao##MWmj_^                                                                           "<<endl;
cout<<"                                             'iCwJx()/juXQZmqpbkh*##*****************###############MMMMMMMMMMMM#*aaho*#*****####MMMMMMMMM#*oJ|///////tfrnzUc};.                                                                          "<<endl;
cout<<"                                            ,fwYf(fnXQmwpbhhaaaooo################################MMMMMMMMMM###****oooooaaaaoooo**####M###*oL}(rzJLLYuj(}-<l:^.                                                                           "<<endl;
cout<<"                                          `~0ztrXQwpkhaaooooooooooo###########################MMMMMMMMMM####***ooaaahhkkkkkkhhhaaoo**###**okJf{-<!;``'.                                                                                   "<<endl;
cout<<"                                        .;xcc0dhaoooooooooooooooooooMM####################MMMMMMMMMMMM####**ooaahkkbbddpppppddbbkkhaoo**oo0(l.                                                                                            "<<endl;
cout<<"                                        ^jLwddbkkkkkkkkkkhhhhhhhhhhah*MMM###########M#M#hL|{<-|rJpo#M###**ooahkkbdppqwwmmmZmmmwqpdkhaaookc_^                                                                                              "<<endl;
cout<<"                                        .^:IIll!iiiiiiii><<~~~~~~~~+_{vaMM##########opZUj);^.';-/uQwdho*ooaahkbdpqmmZO0QQLLLQ0ZmqpbkhaaZt!.                                                                                               "<<endl;
cout<<"                                                                      `_Y*#########kbdmQx|l`.`;[fcZqbao*##*hbdpwmZ0QCJUYYYUJCL0Zwqdkhdc-`                                                                                                 "<<endl;
cout<<"                                                                       .:]Q#######*kbdwOu/!`'^l1rYwphoo##MWW#pwZ0LCUXXzzzXXYUCLOwdkpc[;.                                                                                                  "<<endl;
cout<<"                                                                         .;?ub#####hkbpZcf>,'`i(xQqbao*#MMWM#aZ0LCUYXzcccczXJQmpb0j_,.                                                                                                    "<<endl;
cout<<"                                                                            `i1Jo##okbdmYr<:``+/cZpho*##MWM#ahwOQLJYXzcczYC0mdabz+`                                                                                                       "<<endl;
cout<<"                                                                              .,~/0ahkbwLx-;`,?fUwbao##MWM*akdwZ0LJJJCLQOwq0paaq(,                                                                                                        "<<endl;
cout<<"                                                                                 .,_LkbpZn?I^:{r0qho*#MWM*abdppqwwwwqqZc)1fzwha0[^                                                                                                        "<<endl;
cout<<"                                                                                   '_bkdwc{l`I(cmba*#MWMohdhahhhaaakqOzr)}(nOhhU+'                                                                                                        "<<endl;
cout<<"                                                                                    ;vkbwX1l`>/Jqho#MWMokdwv|{)npooohdmXj}}tCkkni                                                                                                         "<<endl;
cout<<"                                                                                    '~qbpJti`_jOba*#MMabqv_^   `!1CaoakwYf[1zbdt;                                                                                                         "<<endl;
cout<<"                                                                                     ,tkd0j>,[zwh*#MMhdmt!.      .:-uboapJ/]jdZ{`                                                                                                         "<<endl;
cout<<"                                                                                     .>mbwv>:)Lbo#M#kpU},           ^>|OokL(1wC-'                                                                                                         "<<endl;
cout<<"                                                                                      `1bpz>!fma#M*dwn~`              'I[YkZ}0c>.                                                                                                         "<<endl;
cout<<"                                                                                       i0bJ+~zb*Mop0|I.                  ,+rLz)I                                                                                                          "<<endl;
cout<<"                                                                                       ^]d0~?0oMaqX]`                      `;I,.                                                                                                          "<<endl;
cout<<"                                                                                        lYw-/b#kZr>'                                                                                                                                      "<<endl;
cout<<"                                                                                        '+w?U*dL1;                                                                                                                                        "<<endl;
cout<<"                                                                                         ;u(bpv_^                                                                                                                                         "<<endl;
cout<<"                                                                                         'icu(!.                                                                                                                                          "<<endl;
cout<<"                                                                                          .`,`                                                                                                                                            "<<endl;
                                                                                                                                                                                 */                                                                                                



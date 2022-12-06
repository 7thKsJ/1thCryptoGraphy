#include <stdio.h>
#include <fstream>
using namespace std;
int a[15];
int arr1[3], arr2[3], arr3[3], arr4[3], arr5[3];
int temp, cor, a1num, a2num, a3num, k, a1, b1, c1;
char alpha[57] = { 0, 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z','a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}', '~'};
int k8[100][3] = { {1, 2, 3, },{1, 2, 4, },{1, 2, 5, },{1, 2, 6, },{1, 2, 7, },{1, 2, 8, },{1, 3, 4, },{1, 3, 5, },{1, 3, 6, },{1, 3, 7, },{1, 3, 8, },{1, 4, 5, },{1, 4, 6, },{1, 4, 7, },{1, 4, 8, },{1, 5, 6, },{1, 5, 7, },{1, 5, 8, },{1, 6, 7, },{1, 6, 8, },{1, 7, 8, },{2, 3, 4, },{2, 3, 5, },{2, 3, 6, },{2, 3, 7, },{2, 3, 8, },{2, 4, 5, },{2, 4, 6, },{2, 4, 7, },{2, 4, 8, },{2, 5, 6, },{2, 5, 7, },{2, 5, 8, },{2, 6, 7, },{2, 6, 8, },{2, 7, 8, },{3, 4, 5, },{3, 4, 6, },{3, 4, 7, },{3, 4, 8, },{3, 5, 6, },{3, 5, 7, },{3, 5, 8, },{3, 6, 7, },{3, 6, 8, },{3, 7, 8, },{4, 5, 6, },{4, 5, 7, },{4, 5, 8, },{4, 6, 7, },{4, 6, 8, },{4, 7, 8, },{5, 6, 7, },{5, 6, 8, },{5, 7, 8, },{6, 7, 8, } };

bool same(int a1[3], int a2[3])
{
    int cou = 0;
    for (int i = 0; i < 3; i++)
    {
        if (a1[i] == a2[i])
            cou++;
    }
    if (cou == 3)
        return 0;
    else
        return 1;
}
// 좌표가 같은지 판별
void correct1(int x)
{
    int cou = 0;
    if (!same(arr1, arr2) && !same(arr2, arr3))
    {
        cor = 2;
        if (arr2[2] == 1)
            arr2[2] = 0;
        else
            arr2[2] = 1;
        if (arr3[1] == 1)
            arr3[1] = 0;
        else
            arr3[1] = 1;
    }
    else if (!same(arr1, arr2))
    {
        cor = 3;
        if (arr2[2] == 1)
            arr2[2] = 0;
        else
            arr2[2] = 1;
        for (int i = 0; i < 3; i++)
        {
            if (arr2[i] == arr3[i])
                cou++;
        }
        if (cou == 3) {
            cor = 4;
            if (arr2[2] == 1)
                arr2[2] = 0;
            else
                arr2[2] = 1;
            if (arr2[1] == 1)
                arr2[1] = 0;
            else
                arr2[1] = 1;
        }
    }
    else if (!same(arr1, arr3))
    {
        cor = 5;
        if (arr3[2] == 1)
            arr3[2] = 0;
        else
            arr3[2] = 1;
        for (int i = 0; i < 3; i++)
        {
            if (arr2[i] == arr3[i])
                cou++;
        }
        if (cou == 3) {
            cor = 6;
            if (arr3[2] == 1)
                arr3[2] = 0;
            else
                arr3[2] = 1;
            if (arr3[1] == 1)
                arr3[1] = 0;
            else
                arr3[1] = 1;
        }
    }
    else if (!same(arr2, arr3))
    {
        cor = 7;
        if (arr3[2] == 1)
            arr3[2] = 0;
        else
            arr3[2] = 1;
        for (int i = 0; i < 3; i++)
        {
            if (arr1[i] == arr3[i])
                cou++;
        }
        if (cou == 3) {
            cor = 8;
            if (arr3[2] == 1)
                arr3[2] = 0;
            else
                arr3[2] = 1;
            if (arr3[1] == 1)
                arr3[1] = 0;
            else
                arr3[1] = 1;
        }
    }
    return;
}
// 123 블럭 좌표 다르게 하기
void correct2(int x)
{
    int cou = 0;
    if (!same(arr3, arr4) && !same(arr4, arr5))
    {
        cor = 2;
        if (arr4[2] == 1)
            arr4[2] = 0;
        else
            arr4[2] = 1;
        if (arr5[1] == 1)
            arr5[1] = 0;
        else
            arr5[1] = 1;
    }
    else if (!same(arr3, arr4))
    {
        cor = 3;
        if (arr4[2] == 1)
            arr4[2] = 0;
        else
            arr4[2] = 1;
        for (int i = 0; i < 3; i++)
        {
            if (arr4[i] == arr5[i])
                cou++;
        }
        if (cou == 3) {
            cor = 4;
            if (arr4[2] == 1)
                arr4[2] = 0;
            else
                arr4[2] = 1;
            if (arr4[1] == 1)
                arr4[1] = 0;
            else
                arr4[1] = 1;
        }
    }
    else if (!same(arr3, arr5))
    {
        cor = 5;
        if (arr5[2] == 1)
            arr5[2] = 0;
        else
            arr5[2] = 1;
        for (int i = 0; i < 3; i++)
        {
            if (arr4[i] == arr5[i])
                cou++;
        }
        if (cou == 3) {
            cor = 6;
            if (arr5[2] == 1)
                arr5[2] = 0;
            else
                arr5[2] = 1;
            if (arr5[1] == 1)
                arr5[1] = 0;
            else
                arr5[1] = 1;
        }
    }
    else if (!same(arr4, arr5))
    {
        cor = 7;
        if (arr5[2] == 1)
            arr5[2] = 0;
        else
            arr5[2] = 1;
        for (int i = 0; i < 3; i++)
        {
            if (arr3[i] == arr5[i])
                cou++;
        }
        if (cou == 3) {
            cor = 8;
            if (arr5[2] == 1)
                arr5[2] = 0;
            else
                arr5[2] = 1;
            if (arr5[1] == 1)
                arr5[1] = 0;
            else
                arr5[1] = 1;
        }
    }
    return;
}
// 345 블럭 좌표 다르게 하기
int Normal_vector(int a1[3], int a2[3], int a3[3])
{
    if (a1[0] == a2[0] && a2[0] == a3[0]) {
        temp = 1;
        return 100;
    }
    if (a1[1] == a2[1] && a2[1] == a3[1]) {
        temp = 2;
        return 10;
    }
    if (a1[2] == a2[2] && a2[2] == a3[2]) {
        temp = 3;
        return 1;
    }
    if ((a1[0] == a1[1]) && (a2[0] == a2[1]) && (a3[0] == a3[1])) {
        temp = 4;
        return 120;
    }
    if ((a1[0] == a1[2]) && (a2[0] == a2[2]) && (a3[0] == a3[2])) {
        temp = 5;
        return 102;
    }
    if ((a1[1] == a1[2]) && (a2[1] == a2[2]) && (a3[1] == a3[2])) {
        temp = 6;
        return 12;
    }
    if ((a1[0] + a1[1] == 1) && (a2[0] + a2[1] == 1) && (a3[0] + a3[1] == 1)) {
        temp = 7;
        return 110;
    }
    if ((a1[0] + a1[2] == 1) && (a2[0] + a2[2] == 1) && (a3[0] + a3[2] == 1)) {
        temp = 8;
        return 101;
    }
    if ((a1[1] + a1[2] == 1) && (a2[1] + a2[2] == 1) && (a3[1] + a3[2] == 1)) {
        temp = 9;
        return 11;
    }
    if (((a1[0] + a1[1] + a1[2]) == (a2[0] + a2[1] + a2[2])) && ((a3[0] + a3[1] + a3[2]) == (a2[0] + a2[1] + a2[2]))) {
        temp = 10;
        return 111;
    }
 
    if (((-1 * a1[0] + a1[1] + a1[2]) == (-1 * a2[0] + a2[1] + a2[2])) && ((-1 * a3[0] + a3[1] + a3[2]) == (-1 * a2[0] + a2[1] + a2[2]))) {
        temp = 11;
        return 211;
    }
    if (((a1[0] - a1[1] + a1[2]) == (a2[0] - a2[1] + a2[2])) && ((a3[0] - a3[1] + a3[2]) == (a2[0] - a2[1] + a2[2]))) {
        temp = 12;
        return 121;
    }
    if (((a1[0] + a1[1] - a1[2]) == (a2[0] + a2[1] - a2[2])) && ((a3[0] + a3[1] - a3[2]) == (a2[0] + a2[1] - a2[2]))) {
        temp = 13;
        return 112;
    }
}
// 법선벡터 출력
int numeric(int a1[3])
{
    if (a1[0] == 0)
    {
        if (a1[1] == 0)
        {
            if (a1[2] == 0) return 1;
            else return 2;
        }
        else
        {
            if (a1[2] == 0) return 3;
            else return 4;
        }
    }
    else
    {
        if (a1[1] == 0)
        {
            if (a1[2] == 1) return 6;
            else return 5;
        }
        else
        {
            if (a1[2] == 0) return 7;
            else return 8;
        }
    }
}
// 좌표 번호 출력
int position83(int x, int y, int z)
{
    {
        if (y < x && x < z)
        {
            int emp = x;
            x = y;
            y = emp;
        }
        else if (y < z && z < x)
        {
            int emp = x;
            x = y;
            y = z;
            z = emp;
        }
        else if (x < z && z < y)
        {
            int emp = y;
            y = z;
            z = emp;
        }
        else if (z < x && x < y)
        {
            int emp = x;
            x = z;
            z = y;
            y = emp;
        }
        else if (z < y && y < x)
        {
            int emp = x;
            x = z;
            z = emp;
        }
    }
    // 순서 정렬
    for (int i = 0; i < 100; i++)
    {
        if (k8[i][0] == x && k8[i][1] == y && k8[i][2] == z)
        {
            return i + 1;
        }
    }
}
// temp 1,2,3 일때의 포지션
int position43(int x, int y, int z)
{
    {
        if (y < x && x < z)
        {
            int emp = x;
            x = y;
            y = emp;
        }
        else if (y < z && z < x)
        {
            int emp = x;
            x = y;
            y = z;
            z = emp;
        }
        else if (x < z && z < y)
        {
            int emp = y;
            y = z;
            z = emp;
        }
        else if (z < x && x < y)
        {
            int emp = x;
            x = z;
            z = y;
            y = emp;
        }
        else if (z < y && y < x)
        {
            int emp = x;
            x = z;
            z = emp;
        }
    }
    // 순서 정렬
    if (temp == 4) // 1278
    {
        if (x != 1)
            return 4;
        else if (y != 2)
            return 3;
        else if (z != 7)
            return 2;
        return 1;
    }
    if (temp == 5) // 1368
    {
        if (x != 1)
            return 4;
        else if (y != 3)
            return 3;
        else if (z != 6)
            return 2;
        return 1;
    }
    if (temp == 6) // 1458
    {
        if (x != 1)
            return 4;
        else if (y != 4)
            return 3;
        else if (z != 5)
            return 2;
        return 1;
    }
    if (temp == 7) // 3456
    {
        if (x != 3)
            return 4;
        else if (y != 4)
            return 3;
        else if (z != 5)
            return 2;
        return 1;
    }
    if (temp == 8) // 2457
    {
        if (x != 2)
            return 4;
        else if (y != 4)
            return 3;
        else if (z != 5)
            return 2;
        return 1;
    }
    if (temp == 9) // 2367
    {
        if (x != 2)
            return 4;
        else if (y != 3)
            return 3;
        else if (z != 6)
            return 2;
        return 1;
    }
}
// temp 4,5,6,7,8,9 일때의 포지션
int position22(int x, int y, int z)
{
    {
        if (y < x && x < z)
        {
            int emp = x;
            x = y;
            y = emp;
        }
        else if (y < z && z < x)
        {
            int emp = x;
            x = y;
            y = z;
            z = emp;
        }
        else if (x < z && z < y)
        {
            int emp = y;
            y = z;
            z = emp;
        }
        else if (z < x && x < y)
        {
            int emp = x;
            x = z;
            z = y;
            y = emp;
        }
        else if (z < y && y < x)
        {
            int emp = x;
            x = z;
            z = emp;
        }
    }
    // 순서 정렬
    if (temp == 10) // 235, 467
    {
        if (x == 2)
            return 1;
        return 2;
    }
    if (temp == 11) // 167, 238
    {
        if (x == 1)
            return 1;
        return 2;
    }
    if (temp == 12) // 147, 258
    {
        if (x == 1)
            return 1;
        return 2;
    }
    if (temp == 13) // 146, 358
    {
        if (x == 1)
            return 1;
        return 2;
    }

}
// tmep 10, 11, 12, 13 일때의 포지션
bool cmp(int a1[3], int a2[3])
{
    if(a1[0]>a2[0])
        return 1;
    else if(a1[0]<a2[0])
        return 0;
    else {
        if(a1[1]>a2[1])
            return 1;
        else if(a1[1]<a2[1])
            return 0;
        else{
            if(a1[2]>a2[2])
                return 1;
            else if(a1[2]<a2[2])
                return 0;
        }
    }
}
// 좌표 순서 비교
int order(int a1[3], int a2[3], int a3[3])
{
    if (cmp(a1, a2))
    {
        if (cmp(a2, a3))
        {
            return 6; //321
        }
        else
        {
            if (cmp(a1, a3)) return 5;//231
            else return 3;//213
        }
    }
    else
    {
        if (cmp(a2, a3))
        {
            if (cmp(a1, a3)) return 4;//
            else return 2;
        }
        else
            return 1;
    }

    return 0;
}
// 점들의 순서

int main()
{
    int n;
    scanf("%d",&n);
    {
    int cou = 14;
    while (n > 0)
    {
        a[cou--] = (n % 2);
        n = n / 2;

    }
    // 이진수 만들기
    for(int i=0; i<=14; i++)
        printf("%d ", a[i]);
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        arr1[i] = a[i];
        arr2[i] = a[i + 3];
        arr3[i] = a[i + 6];
        arr4[i] = a[i + 9];
        arr5[i] = a[i + 12];
    }
    // 블럭 생성
    {
        cor = 1;

        if (!same(arr1, arr2) || !same(arr2, arr3) || !same(arr3, arr1)) {
            correct1(1);
        }

        int kxaer = Normal_vector(arr1,arr2,arr3);
        char kaxe[3];
        for(int i = 2; i >= 0; i--)
        {
            kaxe[i] = kxaer % 10+ '0';
            kxaer = kxaer / 10;
        }
        ofstream writeFile;
        writeFile.open("test1.txt");
        writeFile.write(kaxe,3);
        a1 = numeric(arr1), b1 = numeric(arr2), c1 = numeric(arr3);
        char ar1[3], ar2[3], ar3[3];
        for(int i = 0; i < 3; i++)
        {
            if(i == 0)
            {
                ar1[i] = alpha[position83(a1, b1, c1)];
                ar2[i] = alpha[position43(a1, b1, c1)] ;
                ar3[i] = alpha[position22(a1, b1, c1)];
            }
            else if( i ==1)
            {
                ar1[i] = ar2[i] = ar3[i] = alpha[order(arr1, arr2, arr3)];
            }
            else
            {
                ar1[i] = ar2[i] = ar3[i] = alpha[cor];
            }
        }
        if (temp == 1 || temp == 2 || temp == 3)
            writeFile.write(ar1,3);
        else if (temp >= 4 && temp <= 9)
            writeFile.write(ar2,3);
        else
            writeFile.write(ar3,3);
    writeFile.close();

    }
    // 123 블럭
    {
        if(cor==2){
            if(arr3[1]==1)
                arr3[1]=0;
            else
                arr3[1]=1;
        }
        if(cor==5){
            if(arr3[2]==1)
                arr3[2]=0;
            else
                arr3[2]=1;
        }
        if(cor==6){
            if(arr3[1]==1)
                arr3[1]=0;
            else
                arr3[1]=1;
        }
        if(cor==7){
            if(arr3[2]==1)
                arr3[2]=0;
            else
                arr3[2]=1;
        }
        if(cor==8){
            if(arr3[1]==1)
                arr3[1]=0;
            else
                arr3[1]=1;
        }
    }
    // correct 초기화
    {
        cor = 1;

        if (!same(arr3, arr4) || !same(arr4, arr5) || !same(arr5, arr3)) {
            correct2(1);
        }
        int kxaet = Normal_vector(arr3,arr4,arr5);
        char kax[3];
        for(int i = 2; i >= 0; i--)
        {
            kax[i] = kxaet % 10 + '0';
            kxaet = kxaet / 10;
        }
        ofstream writeFile;
        writeFile.open("test2.txt");
        writeFile.write(kax,3);        
        a1 = numeric(arr3), b1 = numeric(arr4), c1 = numeric(arr5);
        char ar1[3], ar2[3], ar3[3];
        for(int i = 0; i < 3; i++)
        {
            if(i == 0)
            {
                ar1[i] = alpha[position83(a1, b1, c1)];
                ar2[i] = alpha[position43(a1, b1, c1)];
                ar3[i] = alpha[position22(a1, b1, c1)];
            }
            else if( i ==1)
            {
                ar1[i] = ar2[i] = ar3[i] = alpha[order(arr3, arr4, arr5)];
            }
            else
            {
                ar1[i] = ar2[i] = ar3[i] = alpha[cor];
            }
        }
        if (temp == 1 || temp == 2 || temp == 3)
            writeFile.write(ar1,3);
        else if (temp >= 4 && temp <= 9)
            writeFile.write(ar2,3);
        else
            writeFile.write(ar3,3);
     writeFile.close();
    }
    }
    // 345 블럭
}

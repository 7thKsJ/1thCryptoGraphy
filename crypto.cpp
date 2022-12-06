#include <stdio.h>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;
 
struct ver { int x, y, z; };
int block1[4], block2[4];
char trans1[4], trans2[4];
int temp, a[4], b[4], td[16], d;
string k1;
ver ver1, ver2;
ver k8[100] = { {1, 2, 3, },{1, 2, 4, },{1, 2, 5, },{1, 2, 6, },{1, 2, 7, },{1, 2, 8, },{1, 3, 4, },{1, 3, 5, },{1, 3, 6, },{1, 3, 7, },{1, 3, 8, },{1, 4, 5, },{1, 4, 6, },{1, 4, 7, },{1, 4, 8, },{1, 5, 6, },{1, 5, 7, },{1, 5, 8, },{1, 6, 7, },{1, 6, 8, },{1, 7, 8, },{2, 3, 4, },{2, 3, 5, },{2, 3, 6, },{2, 3, 7, },{2, 3, 8, },{2, 4, 5, },{2, 4, 6, },{2, 4, 7, },{2, 4, 8, },{2, 5, 6, },{2, 5, 7, },{2, 5, 8, },{2, 6, 7, },{2, 6, 8, },{2, 7, 8, },{3, 4, 5, },{3, 4, 6, },{3, 4, 7, },{3, 4, 8, },{3, 5, 6, },{3, 5, 7, },{3, 5, 8, },{3, 6, 7, },{3, 6, 8, },{3, 7, 8, },{4, 5, 6, },{4, 5, 7, },{4, 5, 8, },{4, 6, 7, },{4, 6, 8, },{4, 7, 8, },{5, 6, 7, },{5, 6, 8, },{5, 7, 8, },{6, 7, 8, } };
int dot[9][3] = { {0,0,0}, {0,0,0}, {0,0,1}, {0,1,0}, {0,1,1}, {1,0,0}, {1,0,1}, {1,1,0}, {1,1,1} };

int findtemp1(int n) {
    if (block1[1] == 1 && block1[2] == 0 && block1[3] == 0)
        return 1;
    if (block1[1] == 0 && block1[2] == 1 && block1[3] == 0)
        return 2;
    if (block1[1] == 0 && block1[2] == 0 && block1[3] == 1)
        return 3;
    if (block1[1] == 1 && block1[2] == 2 && block1[3] == 0)
        return 4;
    if (block1[1] == 1 && block1[2] == 0 && block1[3] == 2)
        return 5;
    if (block1[1] == 0 && block1[2] == 1 && block1[3] == 2)
        return 6;
    if (block1[1] == 1 && block1[2] == 1 && block1[3] == 0)
        return 7;
    if (block1[1] == 1 && block1[2] == 0 && block1[3] == 1)
        return 8;
    if (block1[1] == 0 && block1[2] == 1 && block1[3] == 1)
        return 9;
    if (block1[1] == 1 && block1[2] == 1 && block1[3] == 1)
        return 10;
    if (block1[1] == 2 && block1[2] == 1 && block1[3] == 1)
        return 11;
    if (block1[1] == 1 && block1[2] == 2 && block1[3] == 1)
        return 12;
    if (block1[1] == 1 && block1[2] == 1 && block1[3] == 2)
        return 13;
}
int findtemp2(int n) {
    if (block2[1] == 1 && block2[2] == 0 && block2[3] == 0)
        return 1;
    if (block2[1] == 0 && block2[2] == 1 && block2[3] == 0)
        return 2;
    if (block2[1] == 0 && block2[2] == 0 && block2[3] == 1)
        return 3;
    if (block2[1] == 1 && block2[2] == 2 && block2[3] == 0)
        return 4;
    if (block2[1] == 1 && block2[2] == 0 && block2[3] == 2)
        return 5;
    if (block2[1] == 0 && block2[2] == 1 && block2[3] == 2)
        return 6;
    if (block2[1] == 1 && block2[2] == 1 && block2[3] == 0)
        return 7;
    if (block2[1] == 1 && block2[2] == 0 && block2[3] == 1)
        return 8;
    if (block2[1] == 0 && block2[2] == 1 && block2[3] == 1)
        return 9;
    if (block2[1] == 1 && block2[2] == 1 && block2[3] == 1)
        return 10;
    if (block2[1] == 2 && block2[2] == 1 && block2[3] == 1)
        return 11;
    if (block2[1] == 1 && block2[2] == 2 && block2[3] == 1)
        return 12;
    if (block2[1] == 1 && block2[2] == 1 && block2[3] == 2)
        return 13;
}
// 법선벡터에 해당하는 temp 찾기

ver findtri1(int tem) {
    if (tem == 1 || tem == 2 || tem == 3){
        if (trans1[1] - 'A' > 30)
            return k8[trans1[1] - 'A' - 6];
        return k8[trans1[1] - 'A'];
    }
    else if (tem == 4) {
        if (trans1[1] == 'A')
            return { 1,2,7 };
        else if (trans1[1] == 'B')
            return { 1,2,8 };
        else if (trans1[1] == 'C')
            return { 1,7,8 };
        else if (trans1[1] == 'D')
            return { 2,7,8 };
    }
    else if (temp == 5) {
        if (trans1[1] == 'A')
            return { 1,3,6 };
        else if (trans1[1] == 'B')
            return { 1,3,8 };
        else if (trans1[1] == 'C')
            return { 1,6,8 };
        else if (trans1[1] == 'D')
            return { 3,6,8 };
    }
    else if (temp == 6) {
        if (trans1[1] == 'A')
            return { 1,4,5 };
        else if (trans1[1] == 'B')
            return { 1,4,8 };
        else if (trans1[1] == 'C')
            return { 1,5,8 };
        else if (trans1[1] == 'D')
            return { 4,5,8 };
    }
    else if (temp == 7) {
        if (trans1[1] == 'A')
            return { 3,4,5 };
        else if (trans1[1] == 'B')
            return { 3,4,6 };
        else if (trans1[1] == 'C')
            return { 3,5,6 };
        else if (trans1[1] == 'D')
            return { 4,5,6 };
    }
    else if (temp == 8) {
        if (trans1[1] == 'A')
            return { 2,4,5 };
        else if (trans1[1] == 'B')
            return { 2,4,7 };
        else if (trans1[1] == 'C')
            return { 2,5,7 };
        else if (trans1[1] == 'D')
            return { 4,5,7 };
    }
    else if (temp == 9) {
        if (trans1[1] == 'A')
            return { 2,3,6 };
        else if (trans1[1] == 'B')
            return { 2,3,7 };
        else if (trans1[1] == 'C')
            return { 2,6,7 };
        else if (trans1[1] == 'D')
            return { 3,6,7 };
    }
    else if (temp == 10) {
        if (trans1[1] == 'A')
            return { 2,3,5 };
        else if (trans1[1] == 'B')
            return { 4,6,7 };
    }
    else if (temp == 11) {
        if (trans1[1] == 'A')
            return { 1,6,7 };
        else if (trans1[1] == 'B')
            return { 2,3,8 };
    }
    else if (temp == 12) {
        if (trans1[1] == 'A')
            return { 1,4,7 };
        else if (trans1[1] == 'B')
            return { 2,5,8 };
    }
    else if (temp == 13) {
        if (trans1[1] == 'A')
            return { 1,4,6 };
        else if (trans1[1] == 'B')
            return { 3,5,8 };
    }
}
ver findtri2(int tem) {
    if (tem == 1 || tem == 2 || tem == 3) {
        if (trans2[1] - 'A' > 30)
            return k8[trans2[1] - 'A' - 6];
        return k8[trans2[1] - 'A'];
    }
    else if (tem == 4) {
        if (trans2[1] == 'A')
            return { 1,2,7 };
        else if (trans2[1] == 'B')
            return { 1,2,8 };
        else if (trans2[1] == 'C')
            return { 1,7,8 };
        else if (trans2[1] == 'D')
            return { 2,7,8 };
    }
    else if (temp == 5) {
        if (trans2[1] == 'A')
            return { 1,3,6 };
        else if (trans2[1] == 'B')
            return { 1,3,8 };
        else if (trans2[1] == 'C')
            return { 1,6,8 };
        else if (trans2[1] == 'D')
            return { 3,6,8 };
    }
    else if (temp == 6) {
        if (trans2[1] == 'A')
            return { 1,4,5 };
        else if (trans2[1] == 'B')
            return { 1,4,8 };
        else if (trans2[1] == 'C')
            return { 1,5,8 };
        else if (trans2[1] == 'D')
            return { 4,5,8 };
    }
    else if (temp == 7) {
        if (trans2[1] == 'A')
            return { 3,4,5 };
        else if (trans2[1] == 'B')
            return { 3,4,6 };
        else if (trans2[1] == 'C')
            return { 3,5,6 };
        else if (trans2[1] == 'D')
            return { 4,5,6 };
    }
    else if (temp == 8) {
        if (trans2[1] == 'A')
            return { 2,4,5 };
        else if (trans2[1] == 'B')
            return { 2,4,7 };
        else if (trans2[1] == 'C')
            return { 2,5,7 };
        else if (trans2[1] == 'D')
            return { 4,5,7 };
    }
    else if (temp == 9) {
        if (trans2[1] == 'A')
            return { 2,3,6 };
        else if (trans2[1] == 'B')
            return { 2,3,7 };
        else if (trans2[1] == 'C')
            return { 2,6,7 };
        else if (trans2[1] == 'D')
            return { 3,6,7 };
    }
    else if (temp == 10) {
        if (trans2[1] == 'A')
            return { 2,3,5 };
        else if (trans2[1] == 'B')
            return { 4,6,7 };
    }
    else if (temp == 11) {
        if (trans2[1] == 'A')
            return { 1,6,7 };
        else if (trans2[1] == 'B')
            return { 2,3,8 };
    }
    else if (temp == 12) {
        if (trans2[1] == 'A')
            return { 1,4,7 };
        else if (trans2[1] == 'B')
            return { 2,5,8 };
    }
    else if (temp == 13) {
        if (trans2[1] == 'A')
            return { 1,4,6 };
        else if (trans2[1] == 'B')
            return { 3,5,8 };
    }
}
// 삼각형 찾기

void mix1(char e) {
    if (e == 'A') {
        return;
    }
    if (e == 'B') {
        d = a[2];
        a[2] = a[3];
        a[3] = d;
        return;
    }
    if (e == 'C') {
        d = a[1];
        a[1] = a[2];
        a[2] = d;
        return;
    }
    if (e == 'D') {
        d = a[1];
        a[1] = a[2];
        a[2] = a[3];
        a[3] = d;
        return;
    }
    if (e == 'E') {
        d = a[1];
        a[1] = a[3];
        a[3] = a[2];
        a[2] = d;
        return;
    }
    if (e == 'F') {
        d = a[1];
        a[1] = a[3];
        a[3] = d;
        return;
    }
}
void mix2(char e) {
    if (e == 'A') {
        return;
    }
    if (e == 'B') {
        d = b[2];
        b[2] = b[3];
        b[3] = d;
        return;
    }
    if (e == 'C') {
        d = b[1];
        b[1] = b[2];
        b[2] = d;
        return;
    }
    if (e == 'D') {
        d = b[1];
        b[1] = b[2];
        b[2] = b[3];
        b[3] = d;
        return;
    }
    if (e == 'E') {
        d = b[1];
        b[1] = b[3];
        b[3] = b[2];
        b[2] = d;
        return;
    }
    if (e == 'F') {
        d = b[1];
        b[1] = b[3];
        b[3] = d;
        return;
    }
}
// 꼭짓점의 순서 찾기
void correct1(char e) {
    if (e == 'B') { // 2-3 3-2
        if (td[6] == 1)
            td[6] = 0;
        else
            td[6] = 1;
        if (td[8] == 1)
            td[8] = 0;
        else
            td[8] = 1;
        return;
    }
    if (e == 'C') { // 2-3
        if (td[6] == 1)
            td[6] = 0;
        else
            td[6] = 1;
    }
    if (e == 'D') { // 2-2
        if (td[5] == 1)
            td[5] = 0;
        else
            td[5] = 1;
    }
    if (e == 'E') { // 3-3
        if (td[9] == 1)
            td[9] = 0;
        else
            td[9] = 1;
    }
    if (e == 'F') { // 3-2
        if (td[8] == 1)
            td[8] = 0;
        else
            td[8] = 1;
    }
    if (e == 'G') { // 3-3
        if (td[9] == 1)
            td[9] = 0;
        else
            td[9] = 1;
    }
    if (e == 'H') { // 3-2
        if (td[8] == 1)
            td[8] = 0;
        else
            td[8] = 1;
    }
    return;
}
void correct2(char e) {
    if (e == 'B') { // 2-3 3-2
        if (td[12] == 1)
            td[12] = 0;
        else
            td[12] = 1;
        if (td[14] == 1)
            td[14] = 0;
        else
            td[14] = 1;
        return;
    }
    if (e == 'C') { // 2-3
        if (td[12] == 1)
            td[12] = 0;
        else
            td[12] = 1;
    }
    if (e == 'D') { // 2-2
        if (td[11] == 1)
            td[11] = 0;
        else
            td[11] = 1;
    }
    if (e == 'E') { // 3-3
        if (td[15] == 1)
            td[15] = 0;
        else
            td[15] = 1;
    }
    if (e == 'F') { // 3-2
        if (td[14] == 1)
            td[14] = 0;
        else
            td[14] = 1;
    }
    if (e == 'G') { // 3-3
        if (td[15] == 1)
            td[15] = 0;
        else
            td[15] = 1;
    }
    if (e == 'H') { // 3-2
        if (td[14] == 1)
            td[14] = 0;
        else
            td[14] = 1;
    }
    return;
}

int main() {
    ifstream file("test1.txt");
    stringstream ss;
    
    ss<< file.rdbuf();
    k1 = ss.str();
    block1[1] = k1[0] - '0';
    block1[2] = k1[1] - '0';
    block1[3] = k1[2] - '0';
    trans1[1] = k1[3];
    trans1[2] = k1[4];
    trans1[3] = k1[5];
    file.close();
    file.open("test2.txt"); 
    stringstream st;
    
    st<< file.rdbuf();
    k1 = st.str();
    block2[1] = k1[0] - '0';
    block2[2] = k1[1] - '0';
    block2[3] = k1[2] - '0';
    trans2[1] = k1[3];
    trans2[2] = k1[4];
    trans2[3] = k1[5];
  printf("암호문 : %d%d%d%c%c%c%d%d%d%c%c%c\n",block1[1],block1[2],block1[3],trans1[1],trans1[2],trans1[3],block2[1],block2[2],block2[3],trans2[1],trans2[2],trans2[3] );
    {
        temp = findtemp1(1);
        ver1 = findtri1(temp);
        a[1] = ver1.x, a[2] = ver1.y, a[3] = ver1.z;
        mix1(trans1[2]);
        for (int i = 1; i <= 3; i++) {
            td[i * 3 - 2] = dot[a[i]][0];
            td[i * 3 - 1] = dot[a[i]][1];
            td[i * 3] = dot[a[i]][2];
        }

        if (trans1[3] != 'A') {
            correct1(trans1[3]);
        }
    }
    //앞 6개의 문자
    {
        temp = findtemp2(1);
        ver2 = findtri2(temp);
        b[1] = ver2.x, b[2] = ver2.y, b[3] = ver2.z;
        mix2(trans2[2]);
        for (int i = 2; i <= 3; i++) {
            td[i * 3 + 4] = dot[b[i]][0];
            td[i * 3 + 5] = dot[b[i]][1];
            td[i * 3 + 6] = dot[b[i]][2];
        }
        if (trans2[3] != 'A') {
            correct2(trans2[3]);
        }
    }
    //뒤 6개의 문자
    int t = 1, sum = 0;
    for (int i = 15; i > 0; i--) {
        sum += t * td[i];
        t = t * 2;
    } // 이진수를 십진수로 변환
    for (int i = 1; i <= 15; i++)
        printf("%d ", td[i]);
    printf("\n복호화된 암호문 : %04d\n", sum); // 십진수 출력
}

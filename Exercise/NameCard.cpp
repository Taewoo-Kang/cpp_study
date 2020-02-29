/* 문제 4-3, 5-1
===명함을 의미하는 NameCard 클래스 정의===
저장되어야 할 정보:
    - 성명
    - 회사이름
    - 전화번호
    - 직급
직급 정보를 제외한 나머지는 문자열의 형태로 저장, 동적할당으로
직급 정보는 int형 매개변수 사용하되,
enum {CLERK, SENIOR, ASSIST, MANAGER}; 활용
*/
#include <iostream>
#include <cstring>
using namespace std;

namespace COMP_POS
{
    enum {CLERK, SENIOR, ASSIST, MANAGER}; // enum을 활용한 직급 정보

    void ShowPositionInfo(int pos)
    {
        switch(pos)
        {
        case CLERK:
            cout << "사원" << endl;
            break;
        case SENIOR:
            cout << "주임" << endl;
            break;
        case ASSIST:
            cout << "대리" << endl;
            break;
        case MANAGER:
            cout << "과장" << endl;
        }
    }
}

class NameCard
{
private:
    char * name; // 동적할당
    char * company;
    char * phoneNum;
    int position;

public:
    // 생성자
    NameCard(const char * cardName, const char * cardComp, const char * cardPhone, int cardPos) : position(cardPos) // 멤버 이니셜라이저
    {
        name = new char[strlen(cardName)+1];
        company = new char[strlen(cardComp)+1];
        phoneNum = new char[strlen(cardPhone)+1];
        strcpy(name, cardName);
        strcpy(company, cardComp);
        strcpy(phoneNum, cardPhone);
    }

    void ShowNameCardInfo()
    {
        cout << "이름: " << name << endl;
        cout << "회사: " << company << endl;
        cout << "전화번호: " << phoneNum << endl;
        cout << "직급: "; COMP_POS::ShowPositionInfo(position);
        cout << endl;
    }
    
    // 소멸자 - 동적할당 해제!
    ~NameCard()
    {
        delete []name;
        delete []company;
        delete []phoneNum;
    }
};

int main(void)
{
    NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
    NameCard manSenior("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
    NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);
    manClerk.ShowNameCardInfo();
    manSenior.ShowNameCardInfo();
    manAssist.ShowNameCardInfo();
    return 0;
}
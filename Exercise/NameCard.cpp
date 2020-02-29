/* ���� 4-3, 5-1
===������ �ǹ��ϴ� NameCard Ŭ���� ����===
����Ǿ�� �� ����:
    - ����
    - ȸ���̸�
    - ��ȭ��ȣ
    - ����
���� ������ ������ �������� ���ڿ��� ���·� ����, �����Ҵ�����
���� ������ int�� �Ű����� ����ϵ�,
enum {CLERK, SENIOR, ASSIST, MANAGER}; Ȱ��
*/
#include <iostream>
#include <cstring>
using namespace std;

namespace COMP_POS
{
    enum {CLERK, SENIOR, ASSIST, MANAGER}; // enum�� Ȱ���� ���� ����

    void ShowPositionInfo(int pos)
    {
        switch(pos)
        {
        case CLERK:
            cout << "���" << endl;
            break;
        case SENIOR:
            cout << "����" << endl;
            break;
        case ASSIST:
            cout << "�븮" << endl;
            break;
        case MANAGER:
            cout << "����" << endl;
        }
    }
}

class NameCard
{
private:
    char * name; // �����Ҵ�
    char * company;
    char * phoneNum;
    int position;

public:
    // ������
    NameCard(const char * cardName, const char * cardComp, const char * cardPhone, int cardPos) : position(cardPos) // ��� �̴ϼȶ�����
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
        cout << "�̸�: " << name << endl;
        cout << "ȸ��: " << company << endl;
        cout << "��ȭ��ȣ: " << phoneNum << endl;
        cout << "����: "; COMP_POS::ShowPositionInfo(position);
        cout << endl;
    }
    
    // �Ҹ��� - �����Ҵ� ����!
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
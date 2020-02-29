/* OPP �ܰ躰 ������Ʈ 1�ܰ�
=======���α׷� ����=======
������ ���:
    ���1. ���°���
    ���2. �� ��
    ���3. �� ��
    ���4. ��ü���� �ܾ���ȸ

����:
    - ������ ���¹�ȣ�� �ߺ����� �ʴ´�.(�ߺ��˻縦 ���� �ʰڴٴ� ��)
    - �Ա� �� ��ݾ��� ������ 0���� ũ��.(�Ա� �� ��ݾ��� �����˻縦 ���� �ʰڴٴ� ��)
    - ������ ���������� ���¹�ȣ, �����̸�, ������ �ܾ� �̷��� �������� ���� �� �����Ѵ�.
    - �� �̻��� ���� ������ �����ϱ� ���ؼ� �迭�� ����Ѵ�.
    - ���¹�ȣ�� ������ �����̴�.
*/

#include <iostream>
#include <cstring>
using namespace std;

const int NAME_LEN = 20;

// �Լ����� ����
void ShowMenu(void);
void MakeAccount(void);
void DepositMoney(void);
void WithdrawMoney(void);
void ShowAllAccInfo(void);

enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

typedef struct
{
    int accID;    // ���¹�ȣ
    int balance;  // ��   ��
    char cusName[NAME_LEN]; // �����̸�
} Account;

Account accArr[100]; // Account ������ ���� �迭
int accNum = 0; // ����� Account ��

int main(void)
{
    int choice;

    while(1)
    {
        ShowMenu();
        cout << "����: ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case MAKE:
            MakeAccount();
            break;
        
        case DEPOSIT:
            DepositMoney();
            break;

        case WITHDRAW:
            WithdrawMoney();
            break;

        case INQUIRE:
            ShowAllAccInfo();
            break;

        case EXIT:
            return 0;

        default:
            cout << "Illegal selection.." << endl;
        }
    }
    return 0;
}

void ShowMenu(void)
{
    cout << "-----Menu-----" << endl;
    cout << "1. ���°���" << endl;
    cout << "2. ��   ��" << endl;
    cout << "3. ��   ��" << endl;
    cout << "4. ���¹�ȣ ��ü ���" << endl;
    cout << "5. ���α׷� ����" << endl;
}

void MakeAccount(void)
{
    int id;
    char name[NAME_LEN];
    int balance;

    cout << "[���°���]" << endl;
    cout << "����ID: "; cin >> id;
    cout << "��  ��: "; cin >> name;
    cout << "�Աݾ�: "; cin >> balance;
    cout << endl;

    accArr[accNum].accID = id;
    accArr[accNum].balance = balance;
    strcpy(accArr[accNum].cusName, name);
    accNum++;
}

void DepositMoney(void)
{
    int money;
    int id;
    cout << "[��   ��]" << endl;
    cout << "����ID: "; cin >> id;
    cout << "�Աݾ�: "; cin >> money;

    for(int i=0; i<accNum; i++)
    {
        if(accArr[i].accID == id)
        {
            accArr[i].balance += money;
            cout << "�ԱݿϷ�" << endl << endl;
            return;
        }
    }
    
    cout << "��ȿ���� ���� ID�Դϴ�." << endl << endl;
}

void WithdrawMoney(void)
{
    int money;
    int id;
    cout << "[��    ��]" << endl;
    cout << "����ID: "; cin >> id;
    cout << "��ݾ�: "; cin >> money;

    for(int i=0; i<accNum; i++)
    {
        if(accArr[i].accID == id)
        {
            if(accArr[i].balance < money)
            {
                cout << "�ܾ׺���" << endl << endl;
                return;
            }

            accArr[i].balance -= money;
            cout << "��ݿϷ�" << endl << endl;
            return;
        }
    }
    
    cout << "��ȿ���� ���� ID�Դϴ�." << endl << endl;
}

void ShowAllAccInfo(void)
{
    for(int i=0; i<accNum; i++)
    {
        cout << "����ID: " << accArr[i].accID << endl;
        cout << "��  ��: " << accArr[i].cusName << endl;
        cout << "��  ��: " << accArr[i].balance << endl << endl;
    }
}
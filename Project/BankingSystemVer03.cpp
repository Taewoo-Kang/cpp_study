/* OPP 단계별 프로젝트 3단계
- 깊은 복사를 진행하는 복사 생성자 정의
*/

#include <iostream>
#include <cstring>
using namespace std;

const int NAME_LEN = 20;
const int ACC_NUM = 100;

// 함수원형 선언
void ShowMenu(void);
void MakeAccount(void);
void DepositMoney(void);
void WithdrawMoney(void);
void ShowAllAccInfo(void);

enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

class Account
{
private:
    int accID;    // 계좌번호
    int balance;  // 잔   액
    char * cusName; // 고객이름 - 동적할당으로 변경

public:
    // 생성자 정의
    Account(int ID, int money, char * name) : accID(ID), balance(money) // 멤버 이니셜라이저
    {
        cusName = new char[strlen(name)+1];
        strcpy(cusName, name);
    }

    // 깊은 복사를 진행하는 복사 생성자 정의
    Account(const Account& copy) : accID(copy.accID), balance(copy.balance)
    {
        cusName = new char[strlen(copy.cusName)+1];
        strcpy(cusName, copy.cusName);
    }

    int GetAccID() { return accID; }; // 정보 은닉, 보호

    void Deposit(int money)
    {
        balance += money;
    }

    int Withdraw(int money)
    {
        if(balance < money)
            return 0;
        
        balance -= money;
        return money;
    }

    void ShowAccInfo()
    {
        cout << "계좌ID: " << accID << endl;
        cout << "이  름: " << cusName << endl;
        cout << "잔  액: " << balance << endl;
        cout << endl;
    }

    // 소멸자 정의
    ~Account()
    {
        delete []cusName;
    }
};

Account * accArr[ACC_NUM]; // 객체 포인터 배열
int accNum = 0;

int main(void)
{
    int choice;

    while(1)
    {
        ShowMenu();
        cout << "선택: ";
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
    cout << "1. 계좌개설" << endl;
    cout << "2. 입   금" << endl;
    cout << "3. 출   금" << endl;
    cout << "4. 계좌번호 전체 출력" << endl;
    cout << "5. 프로그램 종료" << endl;
}

void MakeAccount(void)
{
    int id;
    char name[NAME_LEN];
    int balance;

    cout << "[계좌개설]" << endl;
    cout << "계좌ID: "; cin >> id;
    cout << "이  름: "; cin >> name;
    cout << "입금액: "; cin >> balance;
    cout << endl;

    accArr[accNum] = new Account(id, balance, name);
    accNum++;
}

void DepositMoney(void)
{
    int money;
    int id;
    cout << "[입   금]" << endl;
    cout << "계좌ID: "; cin >> id;
    cout << "입금액: "; cin >> money;

    for(int i=0; i<accNum; i++)
    {
        if(accArr[i] -> GetAccID() == id)
        {
            accArr[i] -> Deposit(money);
            cout << "입금완료" << endl << endl;
            return;
        }
    }
    
    cout << "유효하지 않은 ID입니다." << endl << endl;
}

void WithdrawMoney(void)
{
    int money;
    int id;
    cout << "[출    금]" << endl;
    cout << "계좌ID: "; cin >> id;
    cout << "출금액: "; cin >> money;

    for(int i=0; i<accNum; i++)
    {
        if(accArr[i]->GetAccID() == id)
        {
            if(accArr[i] -> Withdraw(money) == 0)
            {
                cout << "잔액부족" << endl << endl;
                return;
            }
            
            cout << "출금완료" << endl << endl;
            return;
        }
    }
    
    cout << "유효하지 않은 ID입니다." << endl << endl;
}

void ShowAllAccInfo(void)
{
    for(int i=0; i<accNum; i++)
    {
        accArr[i]->ShowAccInfo();
    }
}
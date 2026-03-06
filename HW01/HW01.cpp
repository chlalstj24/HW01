#include <iostream>
using namespace std;

void setPotion(int count, int* p_HPPotion, int* p_MPPotion)
{
    *p_HPPotion = count;
    *p_MPPotion = count;
}

int main()
{
    int status[4] = { 0,0,0,0 };

    int hpPotion, mpPotion;

    setPotion(5, &hpPotion, &mpPotion);

    while (true)
    {
        cout << "HP와 MP를 입력하세요. 50 이상이어야 합니다. : ";
        cin >> status[0] >> status[1];

        if (status[0] <= 50 || status[1] <= 50)
        {
            cout << "HP나 MP가 50 이하입니다. 다시 입력하세요.\n";
        }
        else
        {
            break;
        }
    }

    // 공격력 / 방어력 입력 검사
    while (true)
    {
        cout << "공격력과 방어력을 입력하세요. 0은 안됩니다. : ";
        cin >> status[2] >> status[3];

        if (status[2] <= 0 || status[3] <= 0)
        {
            cout << "공격력이나 방어력이 0입니다. 다시 입력하세요.\n";
        }
        else
        {
            break;
        }
    }

    int choice;

    while (true)
    {
        cout << "\n1.HP UP / 2.MP UP / 3.공격력 UP / 4.방어력 UP / 5.현재 능력치 / 6.Level Up / 0.나가기\n";
        cout << "선택 : ";
        cin >> choice;

        if (choice == 1)
        {
            if (hpPotion > 0)
            {
                status[0] += 20;
                hpPotion--;
                cout << "HP가 20 증가했습니다.\n";
            }
            else
            {
                cout << "HP 포션이 없습니다.\n";
            }
        }
        else if (choice == 2)
        {
            if (mpPotion > 0)
            {
                status[1] += 20;
                mpPotion--;
                cout << "MP가 20 증가했습니다.\n";
            }
            else
            {
                cout << "MP 포션이 없습니다.\n";
            }
        }
        else if (choice == 3)
        {
            status[2] *= 2;
            cout << "공격력이 2배가 되었습니다.\n";
        }
        else if (choice == 4)
        {
            status[3] *= 2;
            cout << "방어력이 2배가 되었습니다.\n";
        }
        else if (choice == 5)
        {
            cout << "HP : " << status[0] << endl;
            cout << "MP : " << status[1] << endl;
            cout << "공격력 : " << status[2] << endl;
            cout << "방어력 : " << status[3] << endl;
            cout << "HP 포션 : " << hpPotion << endl;
            cout << "MP 포션 : " << mpPotion << endl;
        }
        else if (choice == 6)
        {
            hpPotion++;
            mpPotion++;
            cout << "Level Up! 포션이 1개씩 추가되었습니다.\n";
        }
        else if (choice == 0)
        {
            cout << "프로그램을 종료합니다.\n";
            break;
        }
        else
        {
            cout << "잘못된 입력입니다.\n";
        }
    }

    return 0;
}
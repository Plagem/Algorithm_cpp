#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Character;
class Board; class Monster; class Box; class Trap;

Board* Map[100][100];
string InputAction;
int N, M;
int GlobalTurn = 0;
int startX, startY;
int bossX, bossY;
bool bIsClear = false;

bool bGameEnd = false;

enum EBoardType
{
    BT_Blank,
    BT_Wall,
    BT_Box,
    BT_Trap,
    BT_Monster,
};

enum EBoxType
{
    Weapon,
    Armor,
    Accessory,
};

enum EAccessoryType
{
    None,
    HR,
    RE,
    CO,
    EX,
    DX,
    HU,
    CU,
};

void PrintMap(Character* Player);
void PrintStat(Character* Player);
void GameEnd(Character* Player, Board* DamageInstigator = nullptr);

class Character
{
    public:
    int CurX, CurY;
    int Atk, Def, MaxHp, CurrentHp;
    int Level, Exp;
    int Weapon, Armor;
    EAccessoryType Accessories[4];

    Character()
    {
        Atk = 2; Def = 2; MaxHp = 20; CurrentHp = 20; 
        Level = 1; Exp = 0;
        Weapon = 0; Armor = 0;
        for(int i = 0; i < 4; i++)
        {
            Accessories[i] = EAccessoryType::None;
        }
    }

    void CheckLevelUp()
    {
        if(Exp >= Level * 5)
        {
            Level++;
            MaxHp += 5; CurrentHp = MaxHp;
            Atk += 2; Def += 2;
            Exp = 0;
        }
    }

    int GetDamage() { return Atk + Weapon; }

    void PlayerDead(Board* DamageInstigator)
    {
        if(HasAccessory(EAccessoryType::RE))
        {
            for(int i = 0; i < 4; i++)
            {
                if(Accessories[i] == EAccessoryType::RE)
                {
                    Accessories[i] = EAccessoryType::None;
                    CurrentHp = MaxHp;
                    CurX = startX; CurY = startY;
                }
            }
        }
        else
        {
            GameEnd(this, DamageInstigator);
            // 게임 오버
        }
    }

    bool HasAccessory(EAccessoryType AccessoryType)
    {
        for(int i = 0; i < 4; i++)
        {
            if(Accessories[i] == AccessoryType) return true;
        }
        return false;
    }

    void TakeTurn(char Input);
};

class Board
{
    public:
    EBoardType BoardType;
    int BoardX, BoardY;

    virtual void Progress(Character* Player) {};

    Board()
    {
        BoardType = EBoardType::BT_Blank;
    }
};

class Monster : public Board
{
    public:
    string Name;
    int Atk, Def, CurrentHp, MaxHp, Exp;
    bool bIsBoss;

    Monster(string _Name, int _Atk, int _Def, int _Hp, int _Exp, bool _bIsBoss = false)
    {
        BoardType = EBoardType::BT_Monster;
        Name = _Name; Atk = _Atk; Def = _Def;
        MaxHp = _Hp; CurrentHp = _Hp; Exp = _Exp;
        bIsBoss = _bIsBoss;
    }

    virtual void Progress(Character* Player)
    {
        int Turn = 0;
        while(true)
        {
            // CO 악세사리 적용
            int PlayerDamage = Player->GetDamage();
            if(Turn == 0)
            {
                if(Player->HasAccessory(EAccessoryType::CO))
                {
                    if(Player->HasAccessory(EAccessoryType::DX)) // DX 세트효과 적용
                        PlayerDamage *= 3;
                    else
                        PlayerDamage *= 2;
                }
                if(bIsBoss && Player->HasAccessory(EAccessoryType::HU))
                {
                    Player->CurrentHp = Player->MaxHp;
                }
                
            }

            // 플레이어가 선공
            this->CurrentHp -= max(1, PlayerDamage - Def);
            if(CurrentHp <= 0) // 몬스터 사망 시
            {
                // HR 악세사리 적용
                if(Player->HasAccessory(EAccessoryType::HR))
                {
                    Player->CurrentHp = min(Player->MaxHp, Player->CurrentHp + 3);
                }
                // EX 악세사리 적용
                if(Player->HasAccessory(EAccessoryType::EX))
                {
                    this->Exp = int(Exp * 1.2); // 내림
                }

                Player->Exp += this->Exp;
                Player->CheckLevelUp();

                Map[BoardX][BoardY] = new Board();

                if(bIsBoss)
                {
                    bIsClear = true;
                    GameEnd(Player);
                }

                return;
            }

            // 몬스터가 후공
            if(bIsBoss && Turn == 0 && Player->HasAccessory(HU))
            {
                
            }
            else
            {
                Player->CurrentHp -= max(1, Atk - (Player->Def + Player->Armor));
            }
            if(Player->CurrentHp <= 0)
            {
                this->CurrentHp = this->MaxHp;
                Player->PlayerDead(this);
                return;
            }

            Turn++;
        }
    }
};

class Box : public Board
{
    public:
    EBoxType BoxType;
    EAccessoryType Ability;
    int Value;

    Box(EBoxType _BoxType, EAccessoryType _Ability)
    {
        BoardType = EBoardType::BT_Box;
        BoxType = _BoxType;
        Ability = _Ability;
    }

    Box(EBoxType _BoxType, int _Value)
    {
        BoardType = EBoardType::BT_Box;
        BoxType = _BoxType;
        Value = _Value;
    }

    virtual void Progress(Character* Player)
    {
        switch(BoxType)
        {
            case EBoxType::Weapon:
            {
                Player->Weapon = Value;
                break;
            }
            case EBoxType::Armor:
            {
                Player->Armor = Value;
                break;
            }
            case EBoxType::Accessory:
            {
                bool bAlreadyHave = false;
                int idx = -1;
                for(int i = 0; i < 4; i++)
                {
                    if(Player->Accessories[i] == EAccessoryType::None && idx == -1)
                        idx = i;
                    if(Player->Accessories[i] == Ability)
                        bAlreadyHave = true;
                }
                if(!bAlreadyHave && idx != -1) Player->Accessories[idx] = Ability;
                break;
            }
        }

        Map[BoardX][BoardY] = new Board();
    }
};

class Trap : public Board
{
    public:

    virtual void Progress(Character* Player)
    {
        int TrapDamage = 5;
        if(Player->HasAccessory(EAccessoryType::DX))
        {
            TrapDamage = 1;
        }

        Player->CurrentHp -= TrapDamage;
        if(Player->CurrentHp <= 0)
        {
            Player->PlayerDead(this);
        }
    }

    Trap()
    {
        BoardType = EBoardType::BT_Trap;
    }
};


void Character::TakeTurn(char Input)
{
    // 캐릭터 이동 가능한지 확인
    int nx = CurX, ny = CurY;

    switch(Input)
    {
        case 'L':
            ny--; break;
        case 'R':
            ny++; break;
        case 'U':
            nx--; break;
        case 'D':
            nx++; break;
    }

    if(0 <= nx && nx < N && 0 <= ny && ny < M && Map[nx][ny]->BoardType != EBoardType::BT_Wall)
    {
        CurX = nx; CurY = ny;
    }
    
    switch(Map[CurX][CurY]->BoardType)
    {
        case BT_Box:
        {
            Box* B = static_cast<Box*>(Map[CurX][CurY]);
            B->Progress(this); break;
        }
        case BT_Trap:
        {
            Trap* T = static_cast<Trap*>(Map[CurX][CurY]);
            T->Progress(this); break;
        }
        case BT_Monster:
        {
            Monster* M = static_cast<Monster*>(Map[CurX][CurY]);
            M->Progress(this); break;
        }
    }
}

void Input()
{
    int MonsterNum = 0, BoxNum = 0;
    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        string TString;
        cin >> TString;
        for(int j = 0; j < M; j++)
        {
            Map[i][j] = new Board();

            switch(TString[j])
            {
            case '@':
                startX = i; startY = j; break;
            case 'M':
                bossX = i; bossY = j; MonsterNum++; break;
            case '#':
                Map[i][j]->BoardType = EBoardType::BT_Wall; break;
            case '&':
                MonsterNum++; break;
            case 'B':
                BoxNum++; break;
            case '^':
                Trap* TempTrap = new Trap();
                TempTrap->BoardX = i; TempTrap->BoardY = j;
                Map[i][j] = TempTrap;
                break;
            }
        }
    }

    cin >> InputAction;

    for(int i = 0; i < MonsterNum; i++)
    {
        int R, C, W, A, H, E;
        string S;
        cin >> R >> C >> S >> W >> A >> H >> E;
        Monster* TMonster = new Monster(S, W, A, H, E);
        if(R-1 == bossX && C-1 == bossY)
        {
            TMonster->bIsBoss = true;
        }
        TMonster->BoardX = R-1; TMonster->BoardY = C-1;
        Map[R-1][C-1] = TMonster;
    }

    for(int i = 0; i < BoxNum; i++)
    {
        int R, C; char T;
        cin >> R >> C >> T;
        if(T == 'O')
        {
            EAccessoryType AT;
            string S;
            cin >> S;
            if(S == "HR") AT = EAccessoryType::HR;
            else if(S == "RE") AT = EAccessoryType::RE;
            else if(S == "CO") AT = EAccessoryType::CO;
            else if(S == "EX") AT = EAccessoryType::EX;
            else if(S == "DX") AT = EAccessoryType::DX;
            else if(S == "HU") AT = EAccessoryType::HU;
            else if(S == "CU") AT = EAccessoryType::CU;
            Box* TBox = new Box(EBoxType::Accessory, AT);
            TBox->BoardX = R-1; TBox->BoardY = C-1;
            Map[R-1][C-1] = TBox;
        }
        else
        {
            EBoxType BT;
            if(T == 'A') BT = EBoxType::Armor;
            else if(T == 'W') BT = EBoxType::Weapon;
            int S;
            cin >> S;
            Box* TBox = new Box(BT, S);
            TBox->BoardX = R-1; TBox->BoardY = C-1;
            Map[R-1][C-1] = TBox;
        }
    }
}

void PrintMap(Character* Player)
{
    char PrintMap[100][100];

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            switch(Map[i][j]->BoardType)
            {
            case EBoardType::BT_Blank:
                PrintMap[i][j] = '.'; break;
            case EBoardType::BT_Wall:
                PrintMap[i][j] = '#'; break;
            case EBoardType::BT_Box:
                PrintMap[i][j] = 'B'; break;
            case EBoardType::BT_Monster:
                PrintMap[i][j] = '&'; break;
            case EBoardType::BT_Trap:
                PrintMap[i][j] = '^'; break;
            }
        }
    }
    if(!bIsClear)
    {
        PrintMap[bossX][bossY] = 'M';
    }
    if(Player->CurrentHp > 0)
    {
        PrintMap[Player->CurX][Player->CurY] = '@';
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cout << PrintMap[i][j];
        }
        cout << "\n";
    }

    cout << "Passed Turns : " << GlobalTurn << "\n";
}

void PrintStat(Character* Player)
{
    cout << "LV : " << Player->Level << "\n";
    cout << "HP : " << max(0, Player->CurrentHp) << "/" << Player->MaxHp << "\n";
    cout << "ATT : " << Player->Atk << "+" << Player->Weapon << "\n";
    cout << "DEF : " << Player->Def << "+" << Player->Armor << "\n";
    cout << "EXP : " << Player->Exp << "/" << Player->Level * 5 << "\n";
}

void GameEnd(Character* Player, Board* DamageInstigator)
{
    PrintMap(Player);
    PrintStat(Player);
    
    bGameEnd = true;

    if(bIsClear)
    {
        cout << "YOU WIN!";
    }
    else
    {
        if(DamageInstigator)
        {
            if(DamageInstigator->BoardType == EBoardType::BT_Monster)
            {
                cout << "YOU HAVE BEEN KILLED BY " << static_cast<Monster*>(DamageInstigator)->Name << "..";
            }
            else
            {
                cout << "YOU HAVE BEEN KILLED BY SPIKE TRAP..";
            }
        }
        else
        {
            cout << "Press any key to continue.";
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    Input();

    Character* MyCharacter = new Character();
    MyCharacter->CurX = startX; MyCharacter->CurY = startY;
    
    for(int i = 0; i < InputAction.length(); i++)
    {
        GlobalTurn++;
        MyCharacter->TakeTurn(InputAction[i]);
        if(bGameEnd) break;
    }
    if(!bGameEnd)
    {
        GameEnd(MyCharacter);        
    }
}
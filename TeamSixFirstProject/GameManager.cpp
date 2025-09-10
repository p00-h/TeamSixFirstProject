#include "GameManager.h"

#include "Character.h"
#include "Monster.h"
#include "Golem.h"
#include "Imp.h"
#include "Orc.h"
#include "Slime.h"
#include "Kobold.h"
#include "Dragon.h"
#include "Battle.h"
#include "Shop.h"
#include "HealthPotion.h"
#include "AttackBoost.h"
#include "DefenseBoost.h"
#include "ManaPotion.h"
#include "MonsterArt.h"
#include "Color.h"


#include "Monster.h"
#include "Golem.h"
#include "Imp.h"


#include <iostream>
#include <limits>
#include <conio.h>   // _getch()
#include <fstream>
#include <iomanip>


#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;


void GameManager::SetColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void GameManager::SetColorDefault()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

static Item* CreateItemByName(const std::string& name) {
    { HealthPotion t;  if (t.GetName() == name) return new HealthPotion(); }
    { ManaPotion t;    if (t.GetName() == name) return new ManaPotion(); }
    { AttackBoost t;   if (t.GetName() == name) return new AttackBoost(); }
    { DefenseBoost t;  if (t.GetName() == name) return new DefenseBoost(); }
    return nullptr;
}

bool GameManager::SaveToFile(const Character& player, const std::string& path) {
    std::ofstream ofs(path);
    if (!ofs) return false;

    // 1줄: 이름
    ofs << player.GetName() << "\n";
    // 1줄: level exp hp maxhp mp maxmp atk def gold
    ofs << player.GetLevel() << ' '
        << player.GetExp() << ' '
        << player.GetHp() << ' '
        << player.GetMaxHp() << ' '
        << player.GetMp() << ' '
        << player.GetMaxMp() << ' '
        << player.GetAttack() << ' '
        << player.GetDefense() << ' '
        << player.GetGold() << "\n";

    const auto& inv = player.GetInventory(); 
    ofs << inv.size() << "\n";
    for (const auto& kv : inv) {
        Item* obj = kv.second.first;
        int   cnt = kv.second.second;
        // 이름을 반드시 실제 객체 이름으로 기록 + quoted로 감싸기
        ofs << std::quoted(obj->GetName()) << ' ' << cnt << "\n";  // 
    }
    return true;
}

bool GameManager::LoadFromFile(Character& player, const std::string& path) {
    std::ifstream ifs(path);
    if (!ifs) return false;

    // 기존 인벤토리 초기화(메모리 해제)
    {
        auto& inv = player.GetInventory();
        for (auto& kv : inv) delete kv.second.first;
        inv.clear();
    }

    // 1) 이름 (닉네임, 공백 허용)
    std::string name;
    if (!std::getline(ifs, name)) return false;

    // 2) 스탯
    int level, exp, hp, maxhp, mp, maxmp, atk, def, gold;
    if (!(ifs >> level >> exp >> hp >> maxhp >> mp >> maxmp >> atk >> def >> gold)) return false;
    ifs.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');

    // 3) 인벤토리 개수
    int n = 0;
    if (!(ifs >> n)) return false;
    ifs.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');

    // 4) 아이템들 (공백 안전하게 처리 quoted 사용)
    for (int i = 0; i < n; ++i) {
        std::string itemName;
        int count;
        if (!(ifs >> std::quoted(itemName) >> count)) break;

        if (Item* it = CreateItemByName(itemName)) {
            player.AddItem(it, count); // 내부에서 Clone/스택 처리
        }
    }

    // 5) 캐릭터 상태 반영
    player.SetName(name);
    player.SetLevel(level);
    player.SetExp(exp);
    player.SetHp(hp);
	player.SetMaxHp(maxhp);
    player.SetMp(mp);
	player.SetMaxMp(maxmp);
    player.SetAttack(atk);
    player.SetDefense(def);
    player.SetGold(gold);

    return true;
}


// lo~hi 사이의 랜덤 정수 반환
static int RandRange(int lo, int hi) {
    return lo + std::rand() % (hi - lo + 1);
}

GameManager::GameManager() {}

void GameManager::ClearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void GameManager::WaitForEnter() {
    system("pause");  // "Press any key to continue . . ." 메시지 출력
}


// 화살표 ↑↓로 이동하고 Enter로 확정하는 메뉴
int GameManager::ShowMenu() {
    const char* items[] = { "게임 시작하기","게임 이어하기", "    게임 종료"};
    const int count = 3;
    int sel = 0;

    while (true) {
        ClearScreen();
        ShowTitle(); // 타이틀 아트 출력

        for (int i = 0; i < count; ++i) {
            if (i == sel) {
                PlaySound(TEXT("Cursor2.wav"), NULL, SND_FILENAME | SND_ASYNC);
                SetColor(15);
                cout << "                                           -> " << items[i] << "\n";
                SetColorDefault();
            }
            else {
                SetColor(8);
                cout << "                                              " << items[i] << "\n";
                SetColorDefault();
            }
        }

        int key = _getch();
        if (key == 224) { // 화살표 키 입력
            key = _getch();
            if (key == 72) {          // ↑
                sel = (sel - 1 + count) % count;
            }
            else if (key == 80) {   // ↓
                sel = (sel + 1) % count;
            }
        }
        else if (key == 13) {       // Enter
            return sel;               // 0: 새게임, 1: 이어하기, 2: 종료
        }
        else if (key == 27) {       // ESC
            return 2;                 // 종료
        }
    }
}

// level에 따라 몬스터 생성
Monster* GameManager::CreateMonster(int level)
{
    Monster* monster = nullptr;

    if (level >= 10) {
        monster = new Dragon(level);
    }
    else {
        switch (RandRange(0, 4)) {
        case 0: monster = new Golem(level); break;
        case 1: monster = new Imp(level);    break;
        case 2: monster = new Kobold(level); break;
        case 3: monster = new Orc(level); break;
        case 4: monster = new Slime(level); break;
        }
    }

    const int hp = RandRange(level * 20, level * 30);
    const int atk = RandRange(level * 5, level * 10);
    monster->SetHP(hp);
    monster->SetAttack(atk);
	
    return monster;
}

void GameManager::OpenShop(Character& player)
{
    Shop shop;
    shop.VisitShop(&player);
}

int GameManager::ArrowMenu(const std::vector<std::string>& items, const Character& player)
{
    int sel = 0;
    const int n = static_cast<int>(items.size());

    while (true) {
        ClearScreen();

        // 상태/인벤토리 고정 표시
        player.ShowStatus();
        std::cout << "\n";
        player.ShowInventory();
        std::cout << "\n";

        // 메뉴 렌더링
        std::cout << "========================\n";
        for (int i = 0; i < n; ++i) {
            if (i == sel) {
                PlaySound(TEXT("Cursor2.wav"), NULL, SND_FILENAME | SND_ASYNC);
                SetColor(15);
                std::cout << "                 -> " << items[i] << "\n";
                SetColorDefault();
            }
            else {
                SetColor(8);
                std::cout << "                    " << items[i] << "\n";
                SetColorDefault();
            }          
        }

        // 입력 처리
        int key = _getch();
        if (key == 224) {           // 방향키 prefix
            key = _getch();
            if (key == 72) {        // ↑
                sel = (sel - 1 + n) % n;
            }
            else if (key == 80) { // ↓
                sel = (sel + 1) % n;
            }
        }
        else if (key == 13) {     // Enter
            return sel;
        }
        else if (key == 27) {     // ESC -> 마지막 항목(나가기)로 취급
            return n - 1;
        }
    }
}
    



// level에 따라 몬스터 생성
Monster* GameManager::CreateMonster(int level)
{
	Monster* monster = nullptr;

    switch (RandRange(0, 1)) {
    case 0: monster = new Golem(level); break;
    case 1: monster = new Imp(level);    break;
    }

    const int hp = RandRange(level * 20, level * 30);
    const int atk = RandRange(level * 5, level * 10);
    monster->SetHP(hp);
    monster->SetAttack(atk);
    return monster;
}
    


// 새 게임 시작
void GameManager::StartNewGame() {
    ClearScreen();
    ShowGameRules();
	WaitForEnter();
    ClearScreen();
    std::string name;
    while (true) {
        std::cout << "닉네임을 입력하세요: ";
        std::getline(std::cin, name);  // 공백 포함 입력 받음

        if (name.find(' ') != std::string::npos) {
            std::cout << "닉네임에 공백은 사용할 수 없습니다. 다시 입력하세요.\n";
            continue;
        }
        if (name.empty()) { // 엔터만 눌렀을 때
            std::cout << "닉네임은 비워둘 수 없습니다. 다시 입력하세요.\n";
            continue;
        }
        break;
    }
    Character player(name);

    PlayLoop(player);
}

void GameManager::PlayLoop(Character& player) {
    bool keepPlaying = true;
    bool didBattleOnce = false;

    while (keepPlaying && player.GetHp() > 0) {
        int sel = 0;
        if (!didBattleOnce) {
            sel = ArrowMenu({ "전투", "종료" }, player);
            if (sel == 1) {
                ClearScreen();
                std::cout << "게임을 저장중입니다.\n";
                SaveToFile(player);           // 실제 저장 호출
                break;
            }
        }
        else {
            sel = ArrowMenu({ "전투", "상점", "종료" }, player);
            if (sel == 2) {
                ClearScreen();
                std::cout << "게임을 저장중입니다.\n";
                SaveToFile(player);           // 실제 저장 호출
                break;
            }
            if (sel == 1) {
                OpenShop(player);
                didBattleOnce = false;
                continue;
            }
        }

        // ===== 전투 시작 =====
        GameManager gm;
        Monster* monster = gm.CreateMonster(player.GetLevel());

        if (player.GetLevel() >= 10) {
            ClearScreen();
            setColor(RED);
            std::cout << "보스 몬스터 [드래곤]이 나타났습니다!"
                << " HP: " << monster->GetHP() << ", Attack: " << monster->GetAttack() << "\n";
            PrintDragonArt();
            PlaySound(TEXT("Thunder9.wav"), NULL, SND_FILENAME | SND_ASYNC);
			WaitForEnter();
            setColor(BRIGHT_WHITE);
        }
        else {
            ClearScreen();
            std::cout << "몬스터가 생성되었습니다! 이름: " << monster->GetName()
                << ", HP: " << monster->GetHP() << ", Attack: " << monster->GetAttack() << "\n";
            if (monster->GetName() == "드래곤")       PrintDragonArt();
            else if (monster->GetName() == "골렘")    PrintGolemArt();
            else if (monster->GetName() == "임프")    PrintImpArt();
            else if (monster->GetName() == "코볼트")  PrintKoboldArt();
            else if (monster->GetName() == "오크")    PrintOrcArt();
            else if (monster->GetName() == "슬라임")  PrintSlimeArt();
			WaitForEnter();
        }

        Battle battle;
        int isLive = battle.StartBattle(&player, monster);
        
        if (isLive == 1) { // 승리
            if (player.GetLevel() >= 10 && monster->GetName() == "드래곤") {
                ClearScreen();
				PrintTheEnd();
                _getch();
                keepPlaying = false;
                delete monster;
                break;
            }
            else {
                didBattleOnce = true;


                player.SetExp(player.GetExp() + 50);
                player.AddGold(RandRange(10, 20));
                Sleep(1000);

                int tempHP = player.GetMaxHp();
				int tempAtk = player.GetAttack();
				int tempDef = player.GetDefense();
				int tempMp = player.GetMaxMp();

                ClearScreen();
                player.ShowStatus();

                bool isLevelUp = false;
                if (player.GetExp() >= 100) {
                    player.SetExp(0);
                    isLevelUp = true;
                }
            
                if (isLevelUp == true) {
                    cout << "플레이어가 승리했습니다! +EXP 50\n";
                    setColor(LIGHT_BLUE);
                    PlaySound(TEXT("Up1.wav"), NULL, SND_FILENAME | SND_ASYNC); 
                    player.ApplyLevelUp();
                    setColor(BRIGHT_WHITE);
                }
                else {
                    cout << "플레이어가 승리했습니다! +EXP 50\n";
                }


                if (RandRange(1, 100) <= 30) {
                    int dropType = RandRange(1, 4);
                    Item* dropped = nullptr;
                    switch (dropType) {
                    case 1: dropped = new HealthPotion();  break;
                    case 2: dropped = new ManaPotion();    break;
                    case 3: dropped = new AttackBoost();   break;
                    case 4: dropped = new DefenseBoost();  break;
                    }
                    player.AddItem(dropped);
                    Sleep(1000);
                    std::cout << "\n[전리품 획득]\n";
                    player.ShowInventory();
                }
                WaitForEnter();
                ClearScreen();
            }
        }
        else if (isLive == 2) { // 도망
            ClearScreen();
            player.ShowStatus();
            std::cout << "플레이어가 도망쳤습니다.\n";
            WaitForEnter();
            ClearScreen();
            didBattleOnce = true;
        }
        else { // 패배
            setColor(LIGHT_RED);
            ClearScreen();
            player.ShowStatus();
            PrintGameover();
            WaitForEnter();
            ClearScreen();
            setColor(BRIGHT_WHITE);
            keepPlaying = false;
        }

        delete monster;
    }

	GameManager gameManager;

	Monster* monster = gameManager.CreateMonster(1/*캐릭터 레벨*/);

    cout << "몬스터가 생성되었습니다! 이름: " << monster->GetName()
         << ", HP: " << monster->GetHP()
		<< ", Attack: " << monster->GetAttack() << "\n";

    // Battle Battle;


    WaitForEnter();
}




void GameManager::Run() {
    while (true) {
        int choice = ShowMenu();
        if (choice == 0) {
            StartNewGame();
        }
        else if (choice == 1) {
            // 이어하기: 임시 캐릭터에 로드 → 루프 진입
            Character player("unknown");
            if (LoadFromFile(player)) {
                PlayLoop(player);
            }
            else {
                std::cout << "\n세이브 파일이 없어 이어하기가 불가합니다. 새 게임을 시작합니다.\n";
                WaitForEnter();
                StartNewGame();
            }
        }
        else{
            cout << "\n게임을 종료합니다.\n";
            break;
        }
    }

}

void GameManager::ShowGameRules() {
    cout << "[게임 규칙 안내]\n";
    cout << "* 플레이어는 전투를 통해 경험치를 얻고 레벨을 올릴 수 있습니다.\n";
    cout << "* 10레벨에 도달하면 강력한 보스 몬스터 [드래곤]이 등장합니다.\n";
    cout << "* 드래곤과의 결투에서 승리하면 게임은 엔딩을 맞이하게 됩니다.\n";
    cout << "* 전투 중 행동은 3가지 중 하나를 선택할 수 있습니다.\n";
    cout << "    - 공격: 몬스터에게 직접 공격을 가합니다.\n";
    cout << "    - 아이템 사용: 인벤토리에서 아이템을 사용합니다.\n";
    cout << "    - 도망가기: 전투에서 도망칠 수 있습니다.\n";
    cout << "* 몬스터는 마나가 다 차오르면 강력한 스킬을 사용합니다.\n";
    cout << "* 상점은 전투를 최소 1회 이상 진행해야 활성화됩니다.\n";
    cout << "* 상점에서는 아이템 구매 및 판매가 가능합니다.\n";
    cout << "    - 구매: 골드를 소모해 아이템을 획득합니다.\n";
    cout << "    - 판매: 아이템을 판매하고 상점 구매가의 절반만큼의 골드를 획득합니다.\n\n";
    cout << "* 상점에 재방문하기 위해서는 전투를 1회 이상 진행해야합니다.\n";

}
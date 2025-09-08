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


#include <iostream>
#include <limits>
#include <conio.h>   // _getch()
#include <fstream>
#include <iomanip>

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;


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

    // 1��: �̸�
    ofs << player.GetName() << "\n";
    // 1��: level exp hp mp atk def gold
    ofs << player.GetLevel() << ' '
        << player.GetExp() << ' '
        << player.GetHp() << ' '
        << player.GetMp() << ' '
        << player.GetAttack() << ' '
        << player.GetDefense() << ' '
        << player.GetGold() << "\n";

    const auto& inv = player.GetInventory();  // map<string, pair<Item*, int>>  :contentReference[oaicite:0]{index=0}
    ofs << inv.size() << "\n";
    for (const auto& kv : inv) {
        Item* obj = kv.second.first;
        int   cnt = kv.second.second;
        // �� �̸��� �ݵ�� ���� ��ü �̸����� ��� + quoted�� ���α�
        ofs << std::quoted(obj->GetName()) << ' ' << cnt << "\n";  // 
    }
    return true;
}

bool GameManager::LoadFromFile(Character& player, const std::string& path) {
    std::ifstream ifs(path);
    if (!ifs) return false;

    // ���� �κ��丮 �ʱ�ȭ(�޸� ����)
    {
        auto& inv = player.GetInventory();
        for (auto& kv : inv) delete kv.second.first;
        inv.clear();
    }

    // 1) �̸� (�г���, ���� ���)
    std::string name;
    if (!std::getline(ifs, name)) return false;

    // 2) ����
    int level, exp, hp, mp, atk, def, gold;
    if (!(ifs >> level >> exp >> hp >> mp >> atk >> def >> gold)) return false;
    ifs.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');

    // 3) �κ��丮 ����
    int n = 0;
    if (!(ifs >> n)) return false;
    ifs.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');

    // 4) �����۵� (�̸��� ���� ���Ե� �� �����Ƿ� quoted ���)
    for (int i = 0; i < n; ++i) {
        std::string itemName;
        int count;
        if (!(ifs >> std::quoted(itemName) >> count)) break;

        if (Item* it = CreateItemByName(itemName)) {
            player.AddItem(it, count); // ���ο��� Clone/���� ó��
        }
    }

    // 5) ĳ���� ���� �ݿ�
    player.SetName(name);
    player.SetLevel(level);
    player.SetExp(exp);
    player.SetHp(hp);
    player.SetMp(mp);
    player.SetAttack(atk);
    player.SetDefense(def);
    player.SetGold(gold);

    return true;
}

// lo~hi ������ ���� ���� ��ȯ
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
    system("pause");  // "Press any key to continue . . ." �޽��� ���
}


// ȭ��ǥ ���� �̵��ϰ� Enter�� Ȯ���ϴ� �޴�
int GameManager::ShowMenu() {
    const char* items[] = { "���� �����ϱ�","���� �̾��ϱ�", "    ���� ����"};
    const int count = 3;
    int sel = 0;

    while (true) {
        ClearScreen();
        ShowTitle(); // Ÿ��Ʋ ��Ʈ ���

        for (int i = 0; i < count; ++i) {
            if (i == sel) cout << "                                           -> " << items[i] << "\n";
            else          cout << "                                              " << items[i] << "\n";
        }

        int key = _getch();
        if (key == 224) { // ȭ��ǥ Ű �Է�
            key = _getch();
            if (key == 72) {          // ��
                sel = (sel - 1 + count) % count;
            }
            else if (key == 80) {   // ��
                sel = (sel + 1) % count;
            }
        }
        else if (key == 13) {       // Enter
            return sel;               // 0: ������, 1: �̾��ϱ�, 2: ����
        }
        else if (key == 27) {       // ESC
            return 2;                 // ����
        }
    }
}

// level�� ���� ���� ����
Monster* GameManager::CreateMonster(int level)
{
    Monster* monster = nullptr;

    if (level >= 15) {
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

        // ����/�κ��丮 ���� ǥ��
        player.ShowStatus();
        std::cout << "\n";
        player.ShowInventory();
        std::cout << "\n";

        // �޴� ������
        std::cout << "========================\n";
        for (int i = 0; i < n; ++i) {
            if (i == sel) std::cout << "                 -> " << items[i] << "\n";
            else          std::cout << "                    " << items[i] << "\n";
        }

        // �Է� ó��
        int key = _getch();
        if (key == 224) {           // ����Ű prefix
            key = _getch();
            if (key == 72) {        // ��
                sel = (sel - 1 + n) % n;
            }
            else if (key == 80) { // ��
                sel = (sel + 1) % n;
            }
        }
        else if (key == 13) {     // Enter
            return sel;
        }
        else if (key == 27) {     // ESC -> ������ �׸�(������)�� ���
            return n - 1;
        }
    }
}
    

// �� ���� ����
void GameManager::StartNewGame() {
    ClearScreen();
    ShowGameRules();
	WaitForEnter();
    ClearScreen();
    std::cout << "* �г����� �Է����ּ���(���� �Ұ�): ";
    std::string name;
    while (true) {
        std::cin >> name; // ���� ���� �� ����
        if (name.find(' ') != std::string::npos) {
            std::cout << "�г��ӿ� ������ ����� �� �����ϴ�. �ٽ� �Է��ϼ���: ";
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
            sel = ArrowMenu({ "����", "����" }, player);
            if (sel == 1) {
                ClearScreen();
                std::cout << "������ �������Դϴ�.\n";
                SaveToFile(player);           // �� ���� ���� ȣ��
                break;
            }
        }
        else {
            sel = ArrowMenu({ "����", "����", "����" }, player);
            if (sel == 2) {
                ClearScreen();
                std::cout << "������ �������Դϴ�.\n";
                SaveToFile(player);           // �� ���� ���� ȣ��
                break;
            }
            if (sel == 1) {
                OpenShop(player);
                continue;
            }
        }

        // ===== ���� ���� =====
        GameManager gm;
        Monster* monster = gm.CreateMonster(player.GetLevel());

        if (player.GetLevel() >= 15) {
            std::cout << "���� ���� [�巡��]�� ��Ÿ�����ϴ�!"
                << " HP: " << monster->GetHP() << ", Attack: " << monster->GetAttack() << "\n";
        }
        else {
            std::cout << "���Ͱ� �����Ǿ����ϴ�! �̸�: " << monster->GetName()
                << ", HP: " << monster->GetHP() << ", Attack: " << monster->GetAttack() << "\n";
        }

        Battle battle;
        int isLive = battle.StartBattle(&player, monster);

        if (isLive == 1) { // �¸�
            if (player.GetLevel() >= 15 && monster->GetName() == "�巡��") {
                ClearScreen();
                player.ShowStatus();
                std::cout << "�÷��̾ �巡���� ����ġ�� ������ Ŭ�����߽��ϴ�! �����մϴ�!\n";
                keepPlaying = false;
                WaitForEnter();
                delete monster;
                break;
            }
            else {
                didBattleOnce = true;

                player.SetExp(player.GetExp() + 50);
                player.AddGold(RandRange(10, 20));

                bool isLevelUp = false;
                if (player.GetExp() >= 100) {
                    player.SetExp(0);
                    player.SetLevel(player.GetLevel() + 1);
                    isLevelUp = true;
                }

                ClearScreen();
                player.ShowStatus();
                std::cout << "�÷��̾ �¸��߽��ϴ�! " << (isLevelUp ? "���� ��! \n" : "\n");

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
                    std::cout << "\n[����ǰ ȹ��]\n";
                    player.ShowInventory();
                }
                WaitForEnter();
                ClearScreen();
            }
        }
        else if (isLive == 2) { // ����
            ClearScreen();
            player.ShowStatus();
            std::cout << "�÷��̾ �����ƽ��ϴ�.\n";
            WaitForEnter();
            ClearScreen();
            didBattleOnce = true;
        }
        else { // �й�
            ClearScreen();
            player.ShowStatus();
            std::cout << "�÷��̾ �й��߽��ϴ�.\n";
            WaitForEnter();
            ClearScreen();
            keepPlaying = false;
        }

        delete monster;
    }

    WaitForEnter();
}




void GameManager::Run() {
    while (true) {
        int choice = ShowMenu();
        if (choice == 0) {
            StartNewGame();
        }
        else if (choice == 1) {
            // �̾��ϱ�: �ӽ� ĳ���Ϳ� �ε� �� ���� ����
            Character player("unknown");
            if (LoadFromFile(player)) {
                PlayLoop(player);
            }
            else {
                std::cout << "\n���̺� ������ ���� �̾��ϱⰡ �Ұ��մϴ�. �� ������ �����մϴ�.\n";
                WaitForEnter();
                StartNewGame();
            }
        }
        else{
            cout << "\n������ �����մϴ�.\n";
            break;
        }
    }
}

void GameManager::ShowGameRules() {
    cout << "[���� ��Ģ �ȳ�]\n";
    cout << "* �÷��̾�� ������ ���� ����ġ�� ��� ������ �ø� �� �ֽ��ϴ�.\n";
    cout << "* 15������ �����ϸ� ������ ���� ���� [�巡��]�� �����մϴ�.\n";
    cout << "* �巡����� �������� �¸��ϸ� ������ ������ �����ϰ� �˴ϴ�.\n";
    cout << "* ���� �� �ൿ�� 3���� �� �ϳ��� ������ �� �ֽ��ϴ�.\n";
    cout << "    - ����: ���Ϳ��� ���� ������ ���մϴ�.\n";
    cout << "    - ������ ���: �κ��丮���� �������� ����մϴ�.\n";
    cout << "    - ��������: �������� ����ĥ �� �ֽ��ϴ�.\n";
    cout << "* ������ ������ �ּ� 1ȸ �̻� �����ؾ� Ȱ��ȭ�˴ϴ�.\n";
    cout << "* ���������� ������ ���� �� �ǸŰ� �����մϴ�.\n";
    cout << "    - ����: ��带 �Ҹ��� �������� ȹ���մϴ�.\n";
    cout << "    - �Ǹ�: �������� �Ǹ��ϰ� ���� ���Ű��� ���ݸ�ŭ�� ��带 ȹ���մϴ�.\n\n";
}
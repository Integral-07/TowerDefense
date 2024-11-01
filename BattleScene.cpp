#include "BattleScene.h"
#include "Chara.h"
#include "tower.h"
#include "Window.h"
#include "BGSpriteComponent.h"

BattleScene::BattleScene(class Game* game):mGame(game)
{
	game->SetGameState(Game::EPlay);
	game->SetScene(this);
	game->RemoveAllActors();

	auto p1 = new CharaProperty(game, "Knite", 300, 50, 100, 200);
	p1->SetImg(LoadGraph("./assets/chara/knite/walk1.png"));
	p1->SetImg(LoadGraph("./assets/chara/knite/walk2.png"));
	p1->SetImg(LoadGraph("./assets/chara/knite/walk1.png"));
	p1->SetImg(LoadGraph("./assets/chara/knite/walk3.png"));

	p1->SetImg(LoadGraph("./assets/chara/knite/attack1.png"));
	p1->SetImg(LoadGraph("./assets/chara/knite/attack2.png"));
	p1->SetImg(LoadGraph("./assets/chara/knite/attack3.png"));
	p1->SetImg(LoadGraph("./assets/chara/knite/attack4.png"));
	p1->SetImg(LoadGraph("./assets/chara/knite/attack5.png"));
	p1->SetImg(LoadGraph("./assets/chara/knite/attack6.png"));
	p1->SetImg(LoadGraph("./assets/chara/knite/attack5.png"));
	p1->SetImg(LoadGraph("./assets/chara/knite/attack4.png"));
	p1->SetImg(LoadGraph("./assets/chara/knite/attack3.png"));
	p1->SetImg(LoadGraph("./assets/chara/knite/attack2.png"));

	p1->SetAnimInterval_whenWalk(0.016f * 30);
	p1->SetAnimInterval_whenAttack(0.016f * 10);
	p1->SetDamageInterval(1);

	p1->SetAnim(0, 0, 0); //Wait
	p1->SetAnim(0, 3, 1); //Walk
	p1->SetAnim(4, 13, 1);//Attack
	p1->SetAnimSize(VECTOR2(480, 340));

	p1->SetRectSize(VECTOR2(300, 200));

	auto p2 = new CharaProperty(game, "Witch", 200, 80, 100, 300);
	p2->SetImg(LoadGraph("./assets/chara/witch/walk1.png"));
	p2->SetImg(LoadGraph("./assets/chara/witch/walk2.png"));
	p2->SetImg(LoadGraph("./assets/chara/witch/walk3.png"));
	p2->SetImg(LoadGraph("./assets/chara/witch/walk4.png"));
	p2->SetImg(LoadGraph("./assets/chara/witch/walk5.png"));
	p2->SetImg(LoadGraph("./assets/chara/witch/walk6.png"));
	p2->SetImg(LoadGraph("./assets/chara/witch/walk7.png"));

	p2->SetImg(LoadGraph("./assets/chara/witch/attack1.png"));
	p2->SetImg(LoadGraph("./assets/chara/witch/attack2.png"));
	p2->SetAnimInterval_whenWalk(0.016f * 30);
	p2->SetAnimInterval_whenAttack(0.016f * 30);
	p2->SetDamageInterval(1);

	p2->SetAnimSize(VECTOR2(250, 300));

	p2->SetAnim(0, 0, 0); //Wait
	p2->SetAnim(0, 6, 1); //Walk
	p2->SetAnim(7, 8, 1);//Attack

	p2->SetRectSize(VECTOR2(700, 200));

	auto p3 = new CharaProperty(game, "Shielder", 500, 0, 100, 200);
	p3->SetImg(LoadGraph("./assets/chara/shielder/walk1.png"));
	p3->SetImg(LoadGraph("./assets/chara/shielder/walk2.png"));
	p3->SetImg(LoadGraph("./assets/chara/shielder/walk3.png"));
	p3->SetImg(LoadGraph("./assets/chara/shielder/walk4.png"));
	p3->SetImg(LoadGraph("./assets/chara/shielder/walk5.png"));
	p3->SetImg(LoadGraph("./assets/chara/shielder/walk6.png"));
	p3->SetImg(LoadGraph("./assets/chara/shielder/walk7.png"));

	p3->SetImg(LoadGraph("./assets/chara/shielder/attack1.png"));

	p3->SetAnimInterval_whenWalk(0.016f * 30);
	p3->SetAnimInterval_whenAttack(0.016f * 30);
	p3->SetDamageInterval(1);

	p3->SetAnim(0, 0, 0); //Wait
	p3->SetAnim(0, 6, 1); //Walk
	p3->SetAnim(7, 7, 0); //Attack
	p3->SetAnimSize(VECTOR2(250, 300));

	p3->SetRectSize(VECTOR2(400, 200));

	auto p4 = new CharaProperty(game, "Slime", 200, 20, 100, 100);
	p4->SetImg(LoadGraph("./assets/chara/slime/walk1.png"));
	p4->SetImg(LoadGraph("./assets/chara/slime/walk2.png"));
	p4->SetImg(LoadGraph("./assets/chara/slime/walk3.png"));
	p4->SetImg(LoadGraph("./assets/chara/slime/walk4.png"));

	p4->SetImg(LoadGraph("./assets/chara/slime/attack1.png"));
	p4->SetImg(LoadGraph("./assets/chara/slime/attack2.png"));
	p4->SetImg(LoadGraph("./assets/chara/slime/attack3.png"));
	p4->SetImg(LoadGraph("./assets/chara/slime/attack4.png"));
	p4->SetImg(LoadGraph("./assets/chara/slime/attack5.png"));
	p4->SetImg(LoadGraph("./assets/chara/slime/attack6.png"));
	//p4->SetImg(LoadGraph("./assets/chara/slime/attack7.png"));

	p4->SetAnimInterval_whenWalk(0.016f * 10);
	p4->SetAnimInterval_whenAttack(0.016f * 10);
	p4->SetDamageInterval(1);

	p4->SetAnim(0, 0, 0); //Wait
	p4->SetAnim(0, 3, 1); //Walk
	p4->SetAnim(4, 9, 1);//Attack
	p4->SetAnimSize(VECTOR2(300, 450));

	p4->SetRectSize(VECTOR2(50, 200));

	auto a = new Actor(game);
	auto bgsc = new BGSpriteComponent(a, 100);
	bgsc->SetScrollSpeed(0);
	bgsc->AddImage(LoadGraph("./assets/bg.png"));

	//Ž©w
	auto b = new Tower(game, false);
	b->SetMaxHp(1000);
	b->SetPosition(VECTOR2(GameWidth - 600, GameHeight / 3 + 150));
	b->SetScale(VECTOR2(1417 / 2, 977 / 2));

	//“Gw
	b = new Tower(game, true);
	b->SetMaxHp(1000);
	b->SetPosition(VECTOR2(10, 50));
	b->SetScale(VECTOR2(379, 800));

	auto w = new Window(game, "./assets/chara/knite/panel_.png", VECTOR2(200, 200));
	w->SetPosition(VECTOR2(GameWidth / 3 * 1.9, GameHeight / 10 * 8.5));
	w->SetScale(w->GetRectSize());

	PlaySoundMem(game->GetBgmHandle(), DX_PLAYTYPE_LOOP);
}

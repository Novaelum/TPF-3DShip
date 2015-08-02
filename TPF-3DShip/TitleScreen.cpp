#include "TitleScreen.h"
#include "ShipRace.h"


TitleScreen::TitleScreen()
	: m_background(nullptr)
{
	Textures->LoadTexture(Texture::TitleScreen_ID, MakePath(spritePath, "TitleScreen.jpg"));
	m_background = new Sprite(Texture::TitleScreen_ID);
	m_background->SetPivot(D3DXVECTOR3((SCREEN_RES_W * 0.5), (SCREEN_RES_H * 0.5), 800.f));
	m_background->SetRotationDeg(180.f, 0.f, 180.f);
}


void TitleScreen::Update() {
	if (gDInput->keyDown(DIK_SPACE)) {
		new ShipRace();
		gEngine->DeleteComponent(this);
		gEngine->DeleteComponent(m_background);
	}
}

TitleScreen::~TitleScreen()
{

}

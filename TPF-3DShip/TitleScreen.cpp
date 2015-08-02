#include "TitleScreen.h"
#include "ShipRace.h"
#include "SceneManager.h"


TitleScreen::TitleScreen()
{
	m_background = new Sprite(Texture::TitleScreen_ID);
	m_background->SetPivot(D3DXVECTOR3((SCREEN_RES_W * 0.5), (SCREEN_RES_H * 0.5), 800.f));
	m_background->SetRotationDeg(180.f, 0.f, 180.f);
}


void TitleScreen::Update() {
	if (gDInput->keyDown(DIK_SPACE) || gDInput->keyDown(DIK_RETURN)) {
		g_sceneManager->GetRace()->SetAllActive();
		SetAllInactive();
	}
}

TitleScreen::~TitleScreen()
{
	// Handle by clear components
}

void TitleScreen::SetAllActive() {
	m_background->SetActive(true);
	this->SetActive(true);
}

void TitleScreen::SetAllInactive() {
	m_background->SetActive(false);
	this->SetActive(false);
}

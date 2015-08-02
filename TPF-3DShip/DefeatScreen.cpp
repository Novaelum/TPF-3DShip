#include "DefeatScreen.h"
#include "SceneManager.h"


DefeatScreen::DefeatScreen()
{
	m_background = new Sprite(Texture::DefeatScreen_ID);
	m_background->SetActive(false);
	m_background->SetRotationDeg(180.f, 0.f, 180.f);
	m_background->SetPivot(D3DXVECTOR3((SCREEN_RES_W * 0.5), (SCREEN_RES_H * 0.5), 800.f));
	m_soundtrack = Sounds->Get(Sound::DefeatTheme_ID);
}


DefeatScreen::~DefeatScreen()
{
	// Handle by clear components
}


void DefeatScreen::Update() {
	if (gDInput->keyDown(DIK_SPACE) || gDInput->keyDown(DIK_RETURN) || gDInput->keyDown(DIK_R)) {
		g_sceneManager->GetRace()->SetAllActive();
		SetAllInactive();
	}
}

void DefeatScreen::SetAllActive() {
	AudioSys->stopAllSounds();
	AudioSys->play2D(m_soundtrack);
	m_background->SetActive(true);
	this->SetActive(true);
	gEngine->GetCamera()->SetCamPos({ 0.f, 1.f, -20.f });
	gEngine->GetCamera()->SetCameraTarget({ 0, 1.f, 0 });
}

void DefeatScreen::SetAllInactive() {
	m_background->SetActive(false);
	this->SetActive(false);
}


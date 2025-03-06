#include "SceneManager.h"
#include <cassert>
#include "SceneTest.h"
#include "Pad.h"
#include "Mouse.h"

SceneManager::SceneManager()
{
	m_pScene = nullptr;
}
SceneManager::~SceneManager()
{

}

void SceneManager::Init()
{
	m_pScene = new SceneTest;
	m_pScene->Init();
}

void SceneManager::End()
{
	assert(m_pScene);
	if (!m_pScene)	return;

	m_pScene->End();
	delete m_pScene;
}

void SceneManager::Update()
{
	assert(m_pScene);
	if (!m_pScene)	return;

	Pad::update();
	Mouse::update();
	SceneBase* pScene = m_pScene->Update();
	if (pScene != m_pScene)
	{
		// 前のシーンの終了処理
		m_pScene->End();
		delete m_pScene;

		m_pScene = pScene;
		m_pScene->Init();
	}
}

void SceneManager::Draw()
{
	assert(m_pScene);
	if (!m_pScene)	return;

	m_pScene->Draw();
}
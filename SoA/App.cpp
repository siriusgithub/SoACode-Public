#include "stdafx.h"
#include "App.h"

#include <Vorb/ui/InputDispatcher.h>
#include <Vorb/ui/ScreenList.h>
#include <Vorb/graphics/SpriteBatch.h>

#include "DevScreen.h"
#include "GameManager.h"
#include "GamePlayScreen.h"
#include "InitScreen.h"
#include "LoadScreen.h"
#include "MainMenuScreen.h"
#include "MeshManager.h"
#include "Options.h"
#include "GamePlayScreen.h"
#include "SpaceSystem.h"
#include "TestBlockViewScreen.h"
#include "TestConsoleScreen.h"
#include "TestDeferredScreen.h"
#include "TestMappingScreen.h"
#include "TestGasGiantScreen.h"


void App::addScreens() {
    scrInit = new InitScreen(this);
    scrLoad = new LoadScreen(this);
    scrMainMenu = new MainMenuScreen(this, scrLoad);
    scrGamePlay = new GamePlayScreen(this, scrMainMenu);

    _screenList->addScreen(scrInit);
    _screenList->addScreen(scrLoad);
    _screenList->addScreen(scrMainMenu);
    _screenList->addScreen(scrGamePlay);

    // Add development screen
    scrDev = new DevScreen;
    scrDev->addScreen(VKEY_RETURN, scrInit);
    scrDev->addScreen(VKEY_SPACE, scrInit);
    _screenList->addScreen(scrDev);

    // Add test screens
    scrTests.push_back(new TestConsoleScreen);
    _screenList->addScreen(scrTests.back());
    scrDev->addScreen(VKEY_C, scrTests.back());
    scrTests.push_back(new TestMappingScreen);
    _screenList->addScreen(scrTests.back());
    scrDev->addScreen(VKEY_M, scrTests.back());
    scrTests.push_back(new TestDeferredScreen);
    _screenList->addScreen(scrTests.back());
    scrDev->addScreen(VKEY_D, scrTests.back());
    scrTests.push_back(new TestBlockView);
    _screenList->addScreen(scrTests.back());
    scrDev->addScreen(VKEY_B, scrTests.back());
    scrTests.push_back(new TestGasGiantScreen);
    _screenList->addScreen(scrTests.back());
    scrDev->addScreen(VKEY_G, scrTests.back());

    // Start from dev screen for convenience
    _screenList->setScreen(scrDev->getIndex());
}

void App::onInit() {
    
    // Load the graphical options
    loadOptions("Data/Options.yml");

    SamplerState::initPredefined();
}

void App::onExit() {
    // Delete cache if it exists

    SpriteBatch::disposeProgram();
}

App::~App() {

    delete scrInit;
    delete scrLoad;
    delete scrMainMenu;
    delete scrGamePlay;
    delete scrDev;
}
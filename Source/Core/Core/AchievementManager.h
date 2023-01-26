// Copyright 2023 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later
// 
// 13 JAN 2023 - Lilly Jade Katrin - lilly.kitty.1988@gmail.com
// Thanks to Stenzek and the PCSX2 project for inspiration, assistance and examples,
// and to TheFetishMachine and Infernum for encouragement and cheerleading

#pragma once
#include "Core/HW/Memmap.h"

#include "rcheevos/include/rc_runtime.h"
#include <rcheevos/include/rc_api_runtime.h>
#include <rcheevos/include/rc_api_user.h>

struct rc_api_achievement_definition_t;

namespace Achievements
{
enum State
{
  LOCKED,
  SOFTCORE,
  HARDCORE
};

void Init();
void Login();
std::string Login(std::string password);
void StartSession(Memory::MemoryManager* memmgr);
void FetchData();
void ActivateAM();
void ActivateUnofficialAM();

void DoFrame();
void DoState(PointerWrap& p);
void Award(unsigned int achievement_id);

rc_api_login_response_t* GetUserStatus();
const std::vector<u8>* GetUserIcon();
rc_api_fetch_user_unlocks_response_t* GetHardcoreGameProgress();
rc_api_fetch_user_unlocks_response_t* GetSoftcoreGameProgress();
const std::vector<u8>* GetGameIcon();
rc_api_fetch_game_data_response_t* GetGameData();
State GetAchievementStatus(unsigned int id);
const std::vector<u8>* GetAchievementBadge(unsigned int id, bool locked);
void GetAchievementProgress(unsigned int id, unsigned* value, unsigned* target);

void DeactivateAM();
void DeactivateUnofficialAM();
void EndSession();
void Logout();
void Shutdown();
} // namespace Achievements

// #ifdef ENABLE_RAINTEGRATION
namespace Achievements::RAIntegration
{
void ReinstallMemoryBanks();
void MainWindowChanged(void* new_handle);
void GameChanged(bool isWii);
std::vector<std::tuple<int, std::string, bool>> GetMenuItems();
void ActivateMenuItem(int item);
}  // namespace Achievements::RAIntegration
// #endif

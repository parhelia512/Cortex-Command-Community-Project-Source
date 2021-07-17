#ifndef _RTELUABINDACTIVITIES_
#define _RTELUABINDACTIVITIES_

#include "LuaMacros.h"

#include "Entity.h"
#include "Activity.h"
#include "GameActivity.h"

namespace RTE {

	/// <summary>
	/// 
	/// </summary>
	struct ActivityLuaBindings {

		LuaBindingRegisterFunctionForType(Activity) {
			return luabind::class_<Activity, Entity>("Activity")
				.enum_("Players")[
					luabind::value("PLAYER_NONE", Players::NoPlayer),
					luabind::value("PLAYER_1", Players::PlayerOne),
					luabind::value("PLAYER_2", Players::PlayerTwo),
					luabind::value("PLAYER_3", Players::PlayerThree),
					luabind::value("PLAYER_4", Players::PlayerFour),
					luabind::value("MAXPLAYERCOUNT", Players::MaxPlayerCount)
				]
				.enum_("ActivityState")[
					luabind::value("NOACTIVITY", Activity::ActivityState::NoActivity),
					luabind::value("NOTSTARTED", Activity::ActivityState::NotStarted),
					luabind::value("STARTING", Activity::ActivityState::Starting),
					luabind::value("EDITING", Activity::ActivityState::Editing),
					luabind::value("PREGAME", Activity::ActivityState::PreGame),
					luabind::value("RUNNING", Activity::ActivityState::Running),
					luabind::value("INERROR", Activity::ActivityState::HasError),
					luabind::value("OVER", Activity::ActivityState::Over)
				]
				.enum_("Team")[
					luabind::value("NOTEAM", Activity::Teams::NoTeam),
					luabind::value("TEAM_1", Activity::Teams::TeamOne),
					luabind::value("TEAM_2", Activity::Teams::TeamTwo),
					luabind::value("TEAM_3", Activity::Teams::TeamThree),
					luabind::value("TEAM_4", Activity::Teams::TeamFour),
					luabind::value("MAXTEAMCOUNT", Activity::Teams::MaxTeamCount)
				]
				.enum_("ViewState")[
					luabind::value("NORMAL", Activity::ViewState::Normal),
					luabind::value("OBSERVE", Activity::ViewState::Observe),
					luabind::value("DEATHWATCH", Activity::ViewState::DeathWatch),
					luabind::value("ACTORSELECT", Activity::ViewState::ActorSelect),
					luabind::value("AISENTRYPOINT", Activity::ViewState::AISentryPoint),
					luabind::value("AIPATROLPOINTS", Activity::ViewState::AIPatrolPoints),
					luabind::value("AIGOLDDIGPOINT", Activity::ViewState::AIGoldDigPoint),
					luabind::value("AIGOTOPOINT", Activity::ViewState::AIGoToPoint),
					luabind::value("LZSELECT", Activity::ViewState::LandingZoneSelect)
				]
				.enum_("DifficultySetting")[
					luabind::value("MINDIFFICULTY", Activity::DifficultySetting::MinDifficulty),
					luabind::value("CAKEDIFFICULTY", Activity::DifficultySetting::CakeDifficulty),
					luabind::value("EASYDIFFICULTY", Activity::DifficultySetting::EasyDifficulty),
					luabind::value("MEDIUMDIFFICULTY", Activity::DifficultySetting::MediumDifficulty),
					luabind::value("HARDDIFFICULTY", Activity::DifficultySetting::HardDifficulty),
					luabind::value("NUTSDIFFICULTY", Activity::DifficultySetting::NutsDifficulty),
					luabind::value("MAXDIFFICULTY", Activity::DifficultySetting::MaxDifficulty)
				]
				.enum_("AISkillSetting")[
					luabind::value("MINSKILL", Activity::AISkillSetting::MinSkill),
					luabind::value("INFERIORSKILL", Activity::AISkillSetting::InferiorSkill),
					luabind::value("DEFAULTSKILL", Activity::AISkillSetting::DefaultSkill),
					luabind::value("AVERAGESKILL", Activity::AISkillSetting::AverageSkill),
					luabind::value("GOODSKILL", Activity::AISkillSetting::GoodSkill),
					luabind::value("UNFAIRSKILL", Activity::AISkillSetting::UnfairSkill)
				]
				.def(luabind::constructor<>())
				.property("ClassName", &Activity::GetClassName)
				.property("Description", &Activity::GetDescription)
				.property("InCampaignStage", &Activity::GetInCampaignStage, &Activity::SetInCampaignStage)
				.property("ActivityState", &Activity::GetActivityState, &Activity::SetActivityState)
				.property("SceneName", &Activity::GetSceneName, &Activity::SetSceneName)
				.property("PlayerCount", &Activity::GetPlayerCount)
				.def("DeactivatePlayer", &Activity::DeactivatePlayer)
				.def("PlayerActive", &Activity::PlayerActive)
				.def("PlayerHuman", &Activity::PlayerHuman)
				.property("HumanCount", &Activity::GetHumanCount)
				.property("TeamCount", &Activity::GetTeamCount)
				.def("TeamActive", &Activity::TeamActive)
				.def("GetTeamOfPlayer", &Activity::GetTeamOfPlayer)
				.def("SetTeamOfPlayer", &Activity::SetTeamOfPlayer)
				.def("PlayersInTeamCount", &Activity::PlayersInTeamCount)
				.def("ScreenOfPlayer", &Activity::ScreenOfPlayer)
				.def("GetViewState", &Activity::GetViewState)
				.def("SetViewState", &Activity::SetViewState)
				.def("GetPlayerBrain", &Activity::GetPlayerBrain)
				.def("SetPlayerBrain", &Activity::SetPlayerBrain)
				.def("PlayerHadBrain", &Activity::PlayerHadBrain)
				.def("SetBrainEvacuated", &Activity::SetBrainEvacuated)
				.def("BrainWasEvacuated", &Activity::BrainWasEvacuated)
				.def("IsAssignedBrain", &Activity::IsAssignedBrain)
				.def("IsBrainOfWhichPlayer", &Activity::IsBrainOfWhichPlayer)
				.def("IsOtherPlayerBrain", &Activity::IsOtherPlayerBrain)
				.def("HumanBrainCount", &Activity::HumanBrainCount)
				.def("AIBrainCount", &Activity::AIBrainCount)
				.def("GetControlledActor", &Activity::GetControlledActor)
				.def("SetTeamFunds", &Activity::SetTeamFunds)
				.def("GetTeamFunds", &Activity::GetTeamFunds)
				.def("SetTeamAISkill", &Activity::SetTeamAISkill)
				.def("GetTeamAISkill", &Activity::GetTeamAISkill)
				.def("ChangeTeamFunds", &Activity::ChangeTeamFunds)
				.def("TeamFundsChanged", &Activity::TeamFundsChanged)
				.def("ReportDeath", &Activity::ReportDeath)
				.def("GetTeamDeathCount", &Activity::GetTeamDeathCount)
				.def("Running", &Activity::IsRunning)
				.def("Paused", &Activity::IsPaused)
				.def("ActivityOver", &Activity::IsOver)
				.def("EnteredOrbit", &Activity::EnteredOrbit)
				.def("SwitchToActor", &Activity::SwitchToActor)
				.def("SwitchToNextActor", &Activity::SwitchToNextActor)
				.def("SwitchToPrevActor", &Activity::SwitchToPrevActor)
				.property("Difficulty", &Activity::GetDifficulty, &Activity::SetDifficulty)
				.def("IsHumanTeam", &Activity::IsHumanTeam)
				.def("ResetMessageTimer", &Activity::ResetMessageTimer);
		}

		LuaBindingRegisterFunctionForType(GameActivity) {
			return luabind::class_<GameActivity, Activity>("GameActivity")
				.enum_("ObjectiveArrowDir")[
					luabind::value("ARROWDOWN", GameActivity::ObjectiveArrowDir::ARROWDOWN),
					luabind::value("ARROWLEFT", GameActivity::ObjectiveArrowDir::ARROWLEFT),
					luabind::value("ARROWRIGHT", GameActivity::ObjectiveArrowDir::ARROWRIGHT),
					luabind::value("ARROWUP", GameActivity::ObjectiveArrowDir::ARROWUP)
				]
				.def(luabind::constructor<>())
				.def("SetObservationTarget", &GameActivity::SetObservationTarget)
				.def("SetDeathViewTarget", &GameActivity::SetDeathViewTarget)
				.def("SetLandingZone", &GameActivity::SetLandingZone)
				.def("GetLandingZone", &GameActivity::GetLandingZone)
				.def("SetActorSelectCursor", &GameActivity::SetActorSelectCursor)
				.def("GetBuyGUI", &GameActivity::GetBuyGUI)
				.def("GetEditorGUI", &GameActivity::GetEditorGUI)
				.property("WinnerTeam", &GameActivity::GetWinnerTeam, &GameActivity::SetWinnerTeam)
				.property("CPUTeam", &GameActivity::GetCPUTeam, &GameActivity::SetCPUTeam)
				//.def_readwrite("ActorCursor", &GameActivity::m_ActorCursor)
				.def_readwrite("CursorTimer", &GameActivity::m_CursorTimer)
				.def_readwrite("GameTimer", &GameActivity::m_GameTimer)
				.def_readwrite("GameOverTimer", &GameActivity::m_GameOverTimer)
				.def_readwrite("GameOverPeriod", &GameActivity::m_GameOverPeriod)
				.def("OtherTeam", &GameActivity::OtherTeam)
				.def("OneOrNoneTeamsLeft", &GameActivity::OneOrNoneTeamsLeft)
				.def("WhichTeamLeft", &GameActivity::WhichTeamLeft)
				.def("NoTeamLeft", &GameActivity::NoTeamLeft)
				// Backwards compat
				.def("OnlyOneTeamLeft", &GameActivity::OneOrNoneTeamsLeft)
				.def("GetBanner", &GameActivity::GetBanner)
				.def("SetLZArea", &GameActivity::SetLZArea)
				.def("GetLZArea", &GameActivity::GetLZArea)
				.def("SetBrainLZWidth", &GameActivity::SetBrainLZWidth)
				.def("GetBrainLZWidth", &GameActivity::GetBrainLZWidth)
				.def("GetActiveCPUTeamCount", &GameActivity::GetActiveCPUTeamCount)
				.def("GetActiveHumanTeamCount", &GameActivity::GetActiveHumanTeamCount)
				.def("AddObjectivePoint", &GameActivity::AddObjectivePoint)
				.def("YSortObjectivePoints", &GameActivity::YSortObjectivePoints)
				.def("ClearObjectivePoints", &GameActivity::ClearObjectivePoints)
				.def("AddOverridePurchase", &GameActivity::AddOverridePurchase)
				.def("SetOverridePurchaseList", (int (GameActivity::*)(const Loadout *, int))&GameActivity::SetOverridePurchaseList)
				.def("SetOverridePurchaseList", (int (GameActivity::*)(std::string, int))&GameActivity::SetOverridePurchaseList)
				.def("ClearOverridePurchase", &GameActivity::ClearOverridePurchase)
				.def("CreateDelivery", (bool (GameActivity::*)(int))&GameActivity::CreateDelivery)
				.def("CreateDelivery", (bool (GameActivity::*)(int, int))&GameActivity::CreateDelivery)
				.def("CreateDelivery", (bool (GameActivity::*)(int, int, Vector&))&GameActivity::CreateDelivery)
				.def("CreateDelivery", (bool (GameActivity::*)(int, int, Actor*))&GameActivity::CreateDelivery)
				.def("GetDeliveryCount", &GameActivity::GetDeliveryCount)
				.property("DeliveryDelay", &GameActivity::GetDeliveryDelay, &GameActivity::SetDeliveryDelay)
				.def("GetTeamTech", &GameActivity::GetTeamTech)
				.def("SetTeamTech", &GameActivity::SetTeamTech)
				.def("GetCrabToHumanSpawnRatio", &GameActivity::GetCrabToHumanSpawnRatio)
				.property("BuyMenuEnabled", &GameActivity::GetBuyMenuEnabled, &GameActivity::SetBuyMenuEnabled)
				.property("CraftsOrbitAtTheEdge", &GameActivity::GetCraftOrbitAtTheEdge, &GameActivity::SetCraftOrbitAtTheEdge)
				.def("TeamIsCPU", &GameActivity::TeamIsCPU)
				.def("GetStartingGold", &GameActivity::GetStartingGold)
				.def("GetFogOfWarEnabled", &GameActivity::GetFogOfWarEnabled)
				.def("UpdateEditing", &GameActivity::UpdateEditing)
				.def("DisableAIs", &GameActivity::DisableAIs)
				.def("InitAIs", &GameActivity::InitAIs)
				.def("AddPieMenuSlice", &GameActivity::AddPieMenuSlice)
				.def("AlterPieMenuSlice", &GameActivity::AlterPieMenuSlice)
				.def("RemovePieMenuSlice", &GameActivity::RemovePieMenuSlice)
				.def_readwrite("PieMenuSlices", &GameActivity::m_CurrentPieMenuSlices, luabind::return_stl_iterator);
		}
	};
}
#endif
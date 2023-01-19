#pragma once
#include "Features/ScriptCamera.hpp"

namespace Callback
{
	bool m_GodMode = false;
	UFG::qVector3* m_pTeleport;
	char* m_Animation = nullptr;

	UFG::qSymbol m_VehicleHash = -1;

	void OnGameUpdate()
	{
		UFG::CSimCharacter* m_LocalPlayer = UFG::LocalPlayer::Get();

		static bool m_GodModeWasOn = false;
		if (m_GodMode || m_GodModeWasOn)
		{
			m_GodModeWasOn = m_GodMode;

			UFG::CHealthComponent* m_LocalPlayerHealth = m_LocalPlayer->GetHealth();
			if (m_LocalPlayerHealth)
			{
				m_LocalPlayerHealth->m_bIsTakingDamage = !m_GodMode;
				m_LocalPlayerHealth->SetHealth(static_cast<int>(m_LocalPlayerHealth->m_fMaxHealth));
			}
		}

		if (m_pTeleport)
		{
			UFG::SimObjectUtility::SetPosition(m_LocalPlayer, *m_pTeleport);

			delete m_pTeleport;
			m_pTeleport = nullptr;
		}

		if (m_Animation)
		{
			UFG::CActionController* m_ActionComponent = &m_LocalPlayer->GetActionTree()->mActionController;
			if (m_ActionComponent)
			{
				UFG::CActionNodePlayable* m_NodePlayable = UFG::ActionNode::FindNode(m_Animation);
				if (m_NodePlayable)
				{
					m_ActionComponent->Stop();
					m_ActionComponent->Play(m_NodePlayable);
					m_ActionComponent->Update(0.f);
				}
			}

			m_Animation = nullptr;
		}

		UFG::CBaseCameraComponent* m_Camera = UFG::Director::GetCurrentCamera();

		UFG::CScriptCameraComponent* m_ScriptCamera = m_Camera->GetScriptCamera();
		if (m_ScriptCamera)
			Feature::ScriptCamera.Update(m_LocalPlayer, m_ScriptCamera);

		if (m_VehicleHash != -1)
		{
			UFG::CSimObject* m_Vehicle = UFG::Sim::SpawnUniqueObject(UFG::Sim::GenerateActorName("dbg_car"), m_VehicleHash);
			if (m_Vehicle)
			{
				UFG::TSVehicle* m_VehicleActor = reinterpret_cast<UFG::TSVehicle*>(m_Vehicle->GetActor());
				if (m_VehicleActor)
					m_VehicleActor->UnlockDoors(true);

				UFG::qVector4 m_VehiclePosition = m_LocalPlayer->m_pTransformNodeComponent->mWorldTransform.v3;
				m_VehiclePosition.x += 5.f;

				UFG::SimObjectUtility::SetPosition(m_Vehicle, m_VehiclePosition);
			}

			m_VehicleHash = -1;
		}
	}
}
#pragma once

namespace Callback
{
	UFG::qSymbol m_VehicleHash = -1;
	UFG::qVector3* m_pTeleport;
	char* m_Animation = nullptr;

	bool m_ToggleScriptCamera = false;
	UFG::qVector3 m_ScriptCameraEye(0.f, 0.f, 0.f);
	UFG::qVector3 m_ScriptCameraLook(0.f, 0.f, 0.f);

	void OnGameUpdate()
	{
		UFG::CSimCharacter* m_LocalPlayer = UFG::LocalPlayer::Get();

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
		{
			if (m_ScriptCamera->mbScriptCameraOn)
			{
				if (m_ToggleScriptCamera)
				{
					m_ToggleScriptCamera = false;
					m_ScriptCamera->ReleaseCamera(false);

					UFG::SimObjectUtility::SetPosition(m_LocalPlayer, m_ScriptCameraEye);
				}
				else
				{
					UFG::qVector3 m_LookPos = m_ScriptCameraLook;
					m_LookPos.DegAngles2Vector();

					m_LookPos.x += m_ScriptCameraEye.x;
					m_LookPos.y += m_ScriptCameraEye.y;
					m_LookPos.z += m_ScriptCameraEye.z;

					m_ScriptCamera->SetDesiredEyeLook(&m_ScriptCameraEye, &m_LookPos);

					UFG::SimObjectUtility::SetPosition(m_LocalPlayer, m_ScriptCameraEye.x, m_ScriptCameraEye.y, m_ScriptCameraEye.z - 5.f);
				}
			}
			else if (m_ToggleScriptCamera)
			{
				m_ToggleScriptCamera = false;
				m_ScriptCamera->SwitchToScriptCam(false);

				m_ScriptCameraEye = m_LocalPlayer->m_pTransformNodeComponent->mWorldTransform.v3.ToVector3();
			}
		}
	}
}
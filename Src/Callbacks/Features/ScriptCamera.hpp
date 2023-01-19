#pragma once

namespace Feature
{
	struct ScriptCamera_t
	{
		bool m_Toggle = false;
		float m_MoveSpeed = 0.5f;
		float m_LookSpeed = 0.5f;

		UFG::qVector3 m_Eye;
		UFG::qVector3 m_Look;

		void UpdateMovement()
		{
			UFG::qVector2 m_LookInput(0.f, 0.f);

			if (UFG::Input::Gamepad::IsActive())
			{
				UFG::CInputActionData* m_LookInputData = UFG::Input::Gamepad::Get_CamMove();

				m_LookInput.x += m_LookInputData->mAxisPositionY * 2.5f;
				m_LookInput.y += m_LookInputData->mAxisPositionX * 2.5f;
			}
			else
			{
				UFG::CInputActionData* m_LookInputData = UFG::Input::Get_Mouse();

				m_LookInput.x += m_LookInputData->mAxisPositionY * 0.25f;
				m_LookInput.y += m_LookInputData->mAxisPositionX * 0.25f;
			}

			m_Look.x += (m_LookInput.x * -1.f) * m_LookSpeed;
			m_Look.y += (m_LookInput.y * -1.f) * m_LookSpeed;

			// Clamp Look
			if (m_Look.x < -79.f)
				m_Look.x = -79.f;
			if (m_Look.x > 79.f)
				m_Look.x = 79.f;

			while (m_Look.y < -180.f)
				m_Look.y += 360.f;
			while (m_Look.y > 180.f)
				m_Look.y -= 360.f;

			UFG::CInputActionData* m_MoveInputData = UFG::Input::Get_Move();
			float m_MoveAxis[3] = { m_MoveInputData->mAxisPositionX, m_MoveInputData->mAxisPositionY, 0.f };

			if (UFG::Input::Button::Get_L2_Repeat()->mActionTrue)
				m_MoveAxis[2] -= 0.5f;

			if (UFG::Input::Button::Get_R2_Repeat()->mActionTrue)
				m_MoveAxis[2] += 0.5f;

			UFG::qVector3 m_LookRad = m_Look;
			UFG::qVector3 m_LookForward, m_LookRight;

			m_LookRad.ConvertToRad();
			m_LookRad.AngleVectors(&m_LookForward, &m_LookRight, nullptr);

			float m_FinalMoveSpeed = (UFG::Input::Button::Get_L1_Repeat()->mActionTrue ? m_MoveSpeed * 0.5f : (UFG::Input::Button::Get_R1_Repeat()->mActionTrue ? m_MoveSpeed * 2.f : m_MoveSpeed));
			if (m_MoveAxis[0] != 0.f)
			{
				m_Eye.x += m_LookRight.x * m_FinalMoveSpeed * m_MoveAxis[0];
				m_Eye.y += m_LookRight.y * m_FinalMoveSpeed * m_MoveAxis[0];
			}

			if (m_MoveAxis[1] != 0.f)
			{
				m_Eye.x -= m_LookForward.x * m_FinalMoveSpeed * m_MoveAxis[1];
				m_Eye.y -= m_LookForward.y * m_FinalMoveSpeed * m_MoveAxis[1];
			}

			m_Eye.z += m_MoveAxis[2] * m_FinalMoveSpeed;
		}

		void Update(UFG::CSimCharacter* m_LocalPlayer, UFG::CScriptCameraComponent* m_Camera)
		{
			if (m_Toggle)
			{
				m_Toggle = false;

				if (m_Camera->mbScriptCameraOn)
				{
					m_Camera->ReleaseCamera(false);

					m_LocalPlayer->Restore();
					UFG::SimObjectUtility::SetPosition(m_LocalPlayer, m_Eye);
				}
				else
				{
					m_Camera->SwitchToScriptCam(false);

					m_Eye = m_LocalPlayer->m_pTransformNodeComponent->mWorldTransform.v3.ToVector3();
				}
			}

			if (m_Camera->mbScriptCameraOn)
			{
				UpdateMovement();

				UFG::qVector3 m_LookPos = m_Look;
				m_LookPos.DegAngles2Vector();
				m_LookPos.x += m_Eye.x;
				m_LookPos.y += m_Eye.y;
				m_LookPos.z += m_Eye.z;

				m_Camera->SetDesiredEyeLook(&m_Eye, &m_LookPos);

				m_LocalPlayer->Suspend();
				UFG::SimObjectUtility::SetPosition(m_LocalPlayer, m_Eye);
				return;
			}
		}
	};
	static ScriptCamera_t ScriptCamera;
}
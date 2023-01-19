#pragma once

namespace Callback
{
	bool m_bOnRenderDebug = true;

	void OnRender()
	{
		if (!m_bOnRenderDebug) return;

		ImGui::SetNextWindowSize(ImVec2(540.f, 360.f));
		if (ImGui::Begin("SD Debug", nullptr, ImGuiWindowFlags_NoResize))
		{
			if (ImGui::CollapsingHeader("UI / HUD", ImGuiTreeNodeFlags_DefaultOpen))
			{
				if (ImGui::TreeNode("ActionButton"))
				{
					static char m_ActionButtonText[128] = { '\0' };
					ImGui::InputText("Text", m_ActionButtonText, sizeof(m_ActionButtonText));

					static int m_ActionButtonValue = 1;
					ImGui::SliderInt("Button", &m_ActionButtonValue, 1, UFG::UIButtons::NUM_BUTTONS - 1);

					if (ImGui::Button("Hide"))
						UFG::ScreenHud->ActionButton->Hide();

					ImGui::SameLine();

					if (ImGui::Button("Show"))
						UFG::ScreenHud->ActionButton->Show(m_ActionButtonText, m_ActionButtonValue, "");

					ImGui::TreePop();
				}

				if (ImGui::TreeNode("DialogBox"))
				{
					static char m_DialogBox[3][128] = { '\0' };
					ImGui::InputText("Text", m_DialogBox[0], 128);
					ImGui::InputText("Button1", m_DialogBox[1], 128);
					ImGui::InputText("Button2", m_DialogBox[2], 128);

					static bool m_DialogBoxFullscreen = false;
					ImGui::Checkbox("Fullscreen", &m_DialogBoxFullscreen);
					ImGui::SameLine();
					if (ImGui::Button("Show"))
					{
						if (m_DialogBox[2][0] == '\0')
							UFG::ScreenDialogBox::OneButton(m_DialogBox[0], m_DialogBox[1], m_DialogBoxFullscreen);
						else
							UFG::ScreenDialogBox::TwoButton(m_DialogBox[0], m_DialogBox[1], m_DialogBox[2], m_DialogBoxFullscreen);
					}
					if (ImGui::Button("Show(noButton)"))
					{
						UFG::ScreenDialogBox::InfoStart(m_DialogBox[0]);
						
					}
					if (ImGui::Button("Show End"))
					{
						UFG::ScreenDialogBox::InfoEnd();
					}

					ImGui::TreePop();
				}

				if (ImGui::TreeNode("HintText"))
				{
					static char m_HintText[128] = { '\0' };
					ImGui::InputTextMultiline("Text", m_HintText, sizeof(m_HintText), ImVec2(0.f, 64.f));

					static float m_fTime = 1.f;
					ImGui::SliderFloat("Time", &m_fTime, 1.f, 5.f);

					if (ImGui::Button("Show"))
						UFG::ScreenHud->HintText->Show(m_HintText, m_fTime);

					ImGui::TreePop();
				}

				if (ImGui::TreeNode("MissionHealth"))
				{
					static char m_MissionHealthCaption[128] = { '\0' };
					ImGui::InputText("Caption", m_MissionHealthCaption, sizeof(m_MissionHealthCaption));

					static float m_MissionHealthValue = 100.f;
					ImGui::SliderFloat("Health", &m_MissionHealthValue, 0.f, 100.f);

					static bool m_MissionHealthVisible = false;
					ImGui::Checkbox("Visible", &m_MissionHealthVisible);
					ImGui::SameLine();
					if (ImGui::Button("Update"))
					{
						UFG::ScreenHud->MissionHealth->SetVisible(m_MissionHealthVisible);
						UFG::ScreenHud->MissionHealth->SetHealth(m_MissionHealthValue);
						UFG::ScreenHud->MissionHealth->SetCaption(m_MissionHealthCaption);
					}

					ImGui::TreePop();
				}

				if (ImGui::TreeNode("MissionProgress"))
				{
					static char m_MissionProgressText[128] = { '\0' };
					ImGui::InputText("Text", m_MissionProgressText, sizeof(m_MissionProgressText));

					static int m_MissionProgressState = 0;
					ImGui::SliderInt("State", &m_MissionProgressState, 0, 3);

					static int m_MissionProgressSlot = 0;
					ImGui::SliderInt("Slot", &m_MissionProgressSlot, 0, 3);

					if (ImGui::Button("Set"))
					{
						UFG::ScreenHud->MissionProgress->SetText(m_MissionProgressText, m_MissionProgressSlot);
						UFG::ScreenHud->MissionProgress->SetState(m_MissionProgressState + 2, m_MissionProgressSlot);
					}

					ImGui::SameLine();

					if (ImGui::Button("Clear"))
						UFG::ScreenHud->MissionProgress->Clear();

					ImGui::TreePop();
				}

				if (ImGui::TreeNode("Map - Blip"))
				{
					static float m_BlipColor[4] = { 1.f, 1.f, 1.f, 1.f };

					ImGui::ColorEdit4("Color", m_BlipColor, ImGuiColorEditFlags_NoAlpha);

					if (ImGui::Button("Update"))
					{
						UFG::CSimObject* m_LocalPlayer = UFG::LocalPlayer::Get();
						if (m_LocalPlayer)
						{
							UFG::Map::GetBlipManager()->RemoveIcon(0x1337);

							UFG::qVector4 m_BlipPos = m_LocalPlayer->m_pTransformNodeComponent->mWorldTransform.v3;
							UFG::CUIMapBlip* m_Blip = UFG::Map::GetBlipManager()->CreateIcon(0x1337, "friendly", 0.f, 0.f);
							if (m_Blip)
							{
								m_Blip->SetPosition(reinterpret_cast<UFG::qVector3*>(&m_BlipPos));
								m_Blip->SetColor(UFG::qColour(m_BlipColor[0], m_BlipColor[1], m_BlipColor[2], m_BlipColor[3]));
							}
						}
					}

					ImGui::TreePop();
				}
			}

			UFG::CBaseCameraComponent* m_Camera = UFG::Director::GetCurrentCamera();
			UFG::CScriptCameraComponent* m_ScriptCamera = m_Camera->GetScriptCamera();
			if (ImGui::CollapsingHeader("Script Camera", ImGuiTreeNodeFlags_DefaultOpen))
			{
				if (ImGui::Button("Toggle"))
					Feature::ScriptCamera.m_Toggle = true;

				ImGui::SliderFloat("Move Speed##ScriptCamera", &Feature::ScriptCamera.m_MoveSpeed, 0.1f, 3.f, "%.1f", 0.1f);
				ImGui::SliderFloat("Look Speed##ScriptCamera", &Feature::ScriptCamera.m_LookSpeed, 0.1f, 3.f, "%.1f", 0.1f);
			}

			if (ImGui::CollapsingHeader("Day Manager", ImGuiTreeNodeFlags_DefaultOpen))
			{
				ImGui::SliderFloat("Time", &UFG::TimeOfDayManager->m_SecondsSinceMidnight, 0.f, 86400.f);
				ImGui::SliderFloat("Rain State", &UFG::TimeOfDayManager->m_WeatherState, 0.f, 2.f);
				ImGui::SliderFloat("Rain Target", &UFG::TimeOfDayManager->m_WeatherTarget, 0.f, 2.f);
				ImGui::SliderFloat("Next Rain Target", &UFG::TimeOfDayManager->m_NextWeatherTarget, 0.f, 2.f);
				ImGui::SliderFloat("Wind Speed", &UFG::TimeOfDayManager->mWindSpeed, 0.f, 10.f);
			}
			
			UFG::CSimCharacter* m_LocalPlayer = UFG::LocalPlayer::Get();
			if (ImGui::CollapsingHeader("Local Player", ImGuiTreeNodeFlags_DefaultOpen) && m_LocalPlayer)
			{
				ImGui::Checkbox("God Mode", &m_GodMode);

				UFG::qVector4& m_LocalPlayerPos = m_LocalPlayer->m_pTransformNodeComponent->mWorldTransform.v3;
				
				for (char i = 0; 3 > i; ++i)
				{
					if (i != 0) ImGui::SameLine(0.f, -10.f);

					char m_cButton0[] = { ' ', '-', ' ', '#', '#', (i), '\0' };
					if (ImGui::Button(m_cButton0))
					{
						float* m_pAdjust = &reinterpret_cast<float*>(&m_LocalPlayerPos.x)[i];
						*m_pAdjust -= 2.5f;

						m_pTeleport = new UFG::qVector3;
						m_pTeleport->x = m_LocalPlayerPos.x;
						m_pTeleport->y = m_LocalPlayerPos.y;
						m_pTeleport->z = m_LocalPlayerPos.z;
					}

					ImGui::SameLine();
					ImGui::Text("%.3f", reinterpret_cast<float*>(&m_LocalPlayerPos.x)[i]);
					ImGui::SameLine();

					char m_cButton1[] = { ' ', '+', ' ', '#', '#', (i), '\0' };
					if (ImGui::Button(m_cButton1))
					{
						float* m_pAdjust = &reinterpret_cast<float*>(&m_LocalPlayerPos.x)[i];
						*m_pAdjust += 2.5f;

						m_pTeleport = new UFG::qVector3;
						m_pTeleport->x = m_LocalPlayerPos.x;
						m_pTeleport->y = m_LocalPlayerPos.y;
						m_pTeleport->z = m_LocalPlayerPos.z;
					}
				}

				if (ImGui::Button("Teleport to nearest waypoint's road"))
				{
					UFG::CMapGPS* m_GPS = UFG::Map::GetGPS();
					if (m_GPS && m_GPS->mActive)
					{
						UFG::CRoadNetworkResource* m_RoadNetwork = UFG::RoadNetwork::Get();
						if (m_RoadNetwork)
						{
							UFG::qVector3 m_RoadLanePos = m_RoadNetwork->GetClosetLane(&m_GPS->mDestinationPos);

							m_pTeleport = new UFG::qVector3;
							m_pTeleport->x = m_RoadLanePos.x;
							m_pTeleport->y = m_RoadLanePos.y;
							m_pTeleport->z = m_RoadLanePos.z;
						}
					}
				}

				if (ImGui::TreeNode("Animation"))
				{
					static char m_AnimationName[256];
					ImGui::InputText("Name", m_AnimationName, sizeof(m_AnimationName));
					if (ImGui::Button("Playback"))
						m_Animation = m_AnimationName;

					ImGui::TreePop();
				}
			}

			if (ImGui::CollapsingHeader("Vehicle", ImGuiTreeNodeFlags_DefaultOpen))
			{
				struct VehicleData
				{
					UFG::qSymbol m_Hash;
					std::string m_Name;

					VehicleData() { }
					VehicleData(UFG::qSymbol hash, std::string name)
					{
						m_Hash = hash;
						m_Name = name;
					}
				};
				static std::vector<VehicleData> m_VehicleList;

				static bool m_VehicleListInit = true;
				if (m_VehicleListInit)
				{
					m_VehicleListInit = false;

					for (auto m_Vehicle : UFG::Vehicle::m_List)
						m_VehicleList.emplace_back(VehicleData(m_Vehicle.first, std::string(m_Vehicle.second) + "##" + std::to_string(m_Vehicle.first)));

					std::sort(m_VehicleList.begin(), m_VehicleList.end(), [](const VehicleData& lhs, const VehicleData& rhs) { return lhs.m_Name < rhs.m_Name; });
				}

				static int m_VehicleID = 0;

				if (ImGui::BeginListBox("##Vehicles"))
				{
					for (int i = 0; m_VehicleList.size() > i; ++i)
					{
						const bool item_selected = (i == m_VehicleID);
						if (ImGui::Selectable(m_VehicleList[i].m_Name.c_str(), item_selected))
							m_VehicleID = i;

						if (item_selected)
							ImGui::SetItemDefaultFocus();
					}

					ImGui::EndListBox();
				}

				if (ImGui::Button("Spawn"))
				{
					Callback::m_VehicleHash = m_VehicleList[m_VehicleID].m_Hash;
				}
			}

			ImGui::End();
		}
	}
}
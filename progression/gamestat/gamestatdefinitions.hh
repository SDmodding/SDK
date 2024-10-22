#pragma once

namespace UFG
{
	class GameStat
	{
	public:
		enum BinaryStat
		{
			CustomizationData,
			GameLog,
			DUMMY_Binary,
			Num_Binary_Stats
		};

		enum BoolStat
		{
			VehicleRamUpgrade,
			PreserveOnSave,
			Collectible_Bio_New,
			EnableSpyCams,
			EnablePDA,
			EnableValet,
			EnableHealthShrineIndicators,
			EnableLockboxIndicators,
			EnableSpyCamIndicators,
			EnableJadeStatueIndicators,
			EnableJumpIndicators,
			EnableDragonHelmet,
			EnableDLC01CollectibleIndicators,
			EnableDLC02CollectibleIndicators,
			EnableDLC03CollectibleIndicators,
			EnableDLC04CollectibleIndicators,
			EnableDLC05CollectibleIndicators,
			EnableDLC06CollectibleIndicators,
			EnableDLC07CollectibleIndicators,
			EnableDLC08CollectibleIndicators,
			EnableDLC09CollectibleIndicators,
			EnableDLC10CollectibleIndicators,
			EnableDLC11CollectibleIndicators,
			EnableDLC12CollectibleIndicators,
			EnableDLC13CollectibleIndicators,
			EnableDLC14CollectibleIndicators,
			EnableDLC15CollectibleIndicators,
			EnableDLC16CollectibleIndicators,
			EnableDLC17CollectibleIndicators,
			EnableDLC18CollectibleIndicators,
			EnableDLC19CollectibleIndicators,
			EnableDLC20CollectibleIndicators,
			EnableKaraoke,
			LastUsedVehicleIsCurrentlyUsed,
			GameHints,
			ContextHelp,
			HudEnable,
			XAxisInverted,
			YAxisInverted,
			SocialHubVisited,
			CameraFreeLook,
			AimSoftLockEnabled,
			Vibration,
			OptionsDisableSocial,
			GPSArrows,
			PCKeyboardSwapMode,
			PCMouseInputRaw,
			HasNewChallengeMessage,
			Display_IsFullscreen,
			Display_EnableMultiMonitor,
			Display_Enable3D,
			Display_EnableVSync,
			Display_HighResTextures,
			Display_ShadowResolution,
			Display_ShadowFiltering,
			Display_HighQualityMotionBlur,
			Display_SSAO,
			Display_FPSLimiter,
			Num_Bool_Stats
		};

		enum FloatRangedStat
		{
			DUMMY_FloatRanged,
			Num_FloatRanged_Stats,
		};

		enum FloatStat
		{
			TotalDistanceDriven,
			TotalTimeDriven,
			TotalDistanceWalked,
			Berserk_Damage_Multiplier,
			Berserk_Activated,
			Berserk_Duration,
			Sharpshooter_Damage_Multiplier,
			Sharpshooter_Accuracy_Rate_Multiplier,
			Sharpshooter_Activated,
			Sharpshooter_Duration,
			Sharpshooter_Duration_Level1,
			Sharpshooter_Duration_Level2,
			Sharpshooter_Duration_Level3,
			HealthRegen_Activated,
			HealthRegen_Duration_Level1,
			HealthRegen_Duration_Level2,
			HealthRegen_Duration_Level3,
			EnergyDrinkBuff_MeleeDamage_Multiplier1,
			EnergyDrinkBuff_MeleeDamage_Multiplier2,
			EnergyDrinkBuff_MeleeDamage_Multiplier3,
			EnergyDrinkBuff_Accuracy_Rate_Multiplier,
			EnergyDrinkBuff_Activated,
			EnergyDrinkBuff_Duration,
			TeahouseBuff_Damage_Reduction1,
			TeahouseBuff_Damage_Reduction2,
			TeahouseBuff_Damage_Reduction3,
			TeaHouseBuff_Activated,
			TeaHouseBuff_Duration,
			MassageParlourBuff_FaceEarned_Multiplier1,
			MassageParlourBuff_FaceEarned_Multiplier2,
			MassageParlourBuff_FaceEarned_Multiplier3,
			MassageParlourBuff_Activated,
			MassageParlourBuff_Duration,
			PlayerFaceMeterBuff_BuffTimer,
			PlayerFaceMeterBuff_Activated,
			PlayerFaceMeterBuff_HealthPerHitGainedAtLevel2,
			PlayerFaceMeterBuff_CombatMeterBonusAdjustmentAtLevel5,
			StrikingBuff_ExtraDamage_Multiplier,
			StrikingBuff_Activated,
			StrikingBuff_Duration,
			MaxHealth,
			Heat,
			MaxHeat,
			Face,
			FaceGained,
			FaceUsed,
			FaceLost,
			ClothingSetBuff_MeleeDamage_1_Multiplier,
			ClothingSetBuff_MeleeDamage_2_Multiplier,
			ClothingSetBuff_MeleeDamage_3_Multiplier,
			ClothingSetBuff_Inconspicuous_PoliceRadiusReduce_Multiplier,
			ClothingSetBuff_Bulletproof_RangedDamageReduce_Multipler,
			ClothingSetBuff_Negotiator_PurchaseDiscountPercentage_1,
			ClothingSetBuff_Negotiator_PurchaseDiscountPercentage_2,
			ClothingSetBuff_Negotiator_PurchaseDiscountPercentage_3,
			ClothingSetBuff_Monk_HealthRegenRate_Multiplier,
			ClothingSetBuff_PumpedUp_ActionMeterBonus_Multiplier,
			ClothingSetBuff_Triad_Enforcer_ActionMeterBonus_Multiplier,
			ClothingSetBuff_Dragon_ActionMeterBonus_Multiplier,
			ClothingSetBuff_Sharpshooter_RangedAccuracyBonus_Multiplier,
			ClothingSetBuff_Tourist_PurchasePriceIncrease_Multiplier,
			ClothingSetBuff_StrikingDamage_Multiplier,
			ClothingSetBuff_StrikingDamageTriadEnforcer_Multiplier,
			ClothingSetBuff_GrappleDamage_Multiplier,
			ClothingSetBuff_HeatReduction_Multiplier,
			ClothingSetBuff_CopXP_1_Multiplier,
			ClothingSetBuff_CopXP_2_Multiplier,
			ClothingSetBuff_CopXP_3_Multiplier,
			ClothingSetBuff_TriadXP_1_Multiplier,
			ClothingSetBuff_TriadXP_2_Multiplier,
			ClothingSetBuff_TriadXP_3_Multiplier,
			ClothingSetBuff_EliteSwat_Damage_Reduction_Multiplier,
			FaceLevel9_Action_MeleeDamage_Multiplier,
			FaceLevel5_Action_DamageReduction_Multiplier,
			TriadOffensiveLevel1_StrikingDamage_Multiplier,
			TriadDefensiveLevel1_DamageReduction_Multiplier,
			TriadDefensiveLevel3_MeleeWeapon_DamageReduction_Multiplier,
			MonetaryPenalty_Arrest_Percentage,
			MonetaryPenalty_Hospital_Percentage,
			PlayerCheckpointLocationX,
			PlayerCheckpointLocationY,
			PlayerCheckpointLocationZ,
			PlayerLastStableLocationX,
			PlayerLastStableLocationY,
			PlayerLastStableLocationZ,
			TotalTimeBetweenMissions,
			LongestTimeBetweenMissions,
			BestAirTime,
			BestWheelieDistance,
			HeighestJumpInCar,
			HeighestJumpOnBike,
			HeighestJumpInBoat,
			LongestJumpInCar,
			LongestJumpOnBike,
			LongestJumpOnScooter,
			LongestJumpInTruck,
			LongestHoodBounce,
			LongestBikeDriveAtMax,
			TopSpeed,
			LastUsedVehicleDismountLocationX,
			LastUsedVehicleDismountLocationY,
			LastUsedVehicleDismountLocationZ,
			LongestShot,
			LongestKill,
			PropertyDamaged,
			TimeInCars,
			TimeOnBikes,
			TimeInBoats,
			TimeInRaces,
			LongestPlaySession,
			LongestCopChase,
			LongestCopChaseAtMaxHeat,
			CameraSpeedPitch,
			CameraSpeedYaw,
			AimSpeedPitch,
			AimSpeedYaw,
			AimSensitivity,
			PCMouseSensitivity,
			StoryProgress,
			EventSuccessRate,
			GameContentExprienced,
			FireArmAccuracy,
			PistolAccuracy,
			MachineGunAccuracy,
			SniperRifleAccuracy,
			AverageTimeBetweenMissions,
			AverageSpeed,
			Health,
			RegenHealthRatio,
			WeatherIntensity,
			WeatherWetness,
			TimeOfDay,
			TelemetryLocationX,
			TelemetryLocationY,
			TelemetryLocationZ,
			TelemetryCopScore,
			TelemetryTriadScore,
			RangedDamageReceived,
			MeleeDamageReceived,
			Num_Float_Stats
		};

		enum IDStat
		{
			Headgear,
			Head,
			Glasses,
			Neck,
			Body,
			LeftWrist,
			RightWrist,
			LowerBody,
			Footwear,
			Accessories,
			Outfit,
			CurrentHeadgear,
			CurrentHead,
			CurrentGlasses,
			CurrentNeck,
			CurrentBody,
			CurrentLeftWrist,
			CurrentRightWrist,
			CurrentLowerBody,
			CurrentFootwear,
			CurrentAccessories,
			CurrentOutfit,
			Equipped,
			WeaponEquipped,
			WeaponStowed,
			FlowId,
			ValetVehicle,
			ValetVehicleObject,
			LastCompletedMaster,
			LastCompletedMission,
			LastUsedVehicle,
			TraceContact,
			KillerNameEnemy,
			KillerNameWeapon,
			PlayerWeapon,
			ReservedFID1,
			ReservedFID2,
			ReservedFID3,
			ReservedFID4,
			ReservedFCID1,
			ReservedFCID2,
			ReservedFCID3,
			ReservedFCID4,
			MissionFinishedReason,
			Num_ID_Stats
		};

		enum Int32RangedStat
		{
			WeaponsPurchased,
			VehiclesPurchased,
			NumberOfVehicleJumps,
			WeaponTypesUsed,
			VehicleTypesUsed,
			MeleeTypesUsed,
			FirearmTypesUsed,
			Num_Int32Ranged_Stats
		};

		enum Int32Stat
		{
			DebugValueF,
			HighestHeatLevel,
			TimesKilled,
			KilledByGunFire,
			KilledByMelee,
			KilledByVehicles,
			TimesArrested,
			RestoreUsed,
			PedsKilled,
			EnemiesKilled,
			PhotosTaken,
			PhotosDeleted,
			VaultsSuccess,
			VaultsFailed,
			CutSceneWatched,
			CutSceneSkipped,
			MostKillsInBikeMayhem,
			Perks,
			CustomizationVersion,
			StatueUpgradePoint,
			TriadUpgradePoint,
			CopUpgradePoint,
			StatueDefensiveStage,
			StatueOffensiveStage,
			TriadDefensiveStage,
			TriadOffensiveStage,
			GunplayUpgradeStage,
			CopDrivingStage,
			CopShootingStage,
			Standing,
			CopXP,
			TriadXP,
			CounterFailed,
			FaceActionSuccess,
			FaceActionFailed,
			MaxHealthUpgradePoint,
			NumClothingChanged,
			ClothingSetBuff,
			ClothingBuffHat,
			ClothingBuffNeck,
			ClothingBuffGlasses,
			ClothingBuffLeftWrist,
			ClothingBuffRightWrist,
			Group_Intimidate_Points,
			MonetaryPenalty_Arrest_MaxSum,
			MonetaryPenalty_Hospital_MaxSum,
			ClipAmmo,
			Collectible_HijackCargoKept,
			MiniGamePlayed,
			MissionsAttmpted,
			MissionsFailed,
			EventsAttempted,
			EventsFailed,
			FavoursAttempted,
			FavoursFailed,
			CasesAttempted,
			CasesFailed,
			DatesAttempted,
			DatesFailed,
			StreetRacesLost,
			VendorExtortionProgress,
			TotalCashEarned,
			Money,
			MostCashHeld,
			GamblingEarnings,
			GamblingLoss,
			BusDriverEarnings,
			LimoDriverEarnings,
			RepoEarnings,
			CashSpentOnClothes,
			CashSpentOnWeapons,
			CashSpentOnVehicles,
			CashSpentOnEnergyDrinks,
			CashSpentOnMassages,
			CashSpentOnHerbalTea,
			CashSpentOnPorkBuns,
			CashSpentOnTaxis,
			CashSpentOnSafehouseDecor,
			PokerDicePlayed,
			EnergyDrinksPurchased,
			MassagesPurchased,
			HerbalTeaPurchased,
			PorkBunsPurchased,
			FoodPurchased,
			VehicleKills,
			CarKills,
			BikeKills,
			BoatKills,
			VehiclesStolen,
			VehiclesActionHijacked,
			VehiclesWrecked,
			VehiclesDrovenIntoOcean,
			BikeJumpsOffCars,
			HoodBounces,
			KillsFromCover,
			BlockedAttacks,
			TiresShot,
			TiresShotFromVehicle,
			VehicleExplosions,
			LockOnKills,
			ShotsMade,
			ShotsHit,
			PistolFired,
			PistolHits,
			PistolKills,
			MachineGunFired,
			MachineGunHits,
			MachineGunKills,
			SniperRifleFired,
			SniperRifleHits,
			SniperRifleKills,
			RifleFired,
			RifleHits,
			RifleKills,
			ShotgunFired,
			ShotgunHits,
			ShotgunKills,
			WeaponsPickup,
			ElectricPanelKills,
			FridgeDoorKills,
			DumpsterKills,
			RoofFanKills,
			DebugValueO,
			Gamma,
			UIScale,
			VolumeSFX,
			VolumeDialogue,
			VolumeMusic,
			VolumeCarMusic,
			Subtitles,
			GunReticle,
			AimMode,
			DrivingConfig,
			PCKeyboardSwapModeExtended,
			SocialChallengeSent,
			SocialChallengeReceived,
			SocialChallengeBeaten,
			SocialLogEntryId,
			InstalledDLCBitField,
			InstalledDLCBitField1,
			IsBannedByCommunityManager,
			StatAward_OverallRank,
			DisplayMode_BackBufferWidth,
			DisplayMode_BackBufferHeight,
			DisplayMode_RefreshRateNumerator,
			DisplayMode_RefreshRateDenominator,
			DisplayMode_AdapterUID,
			DisplayMode_MonitorUID,
			DisplayMode_Scaling,
			DisplayMode_ScanlineMode,
			Display_AAQuality,
			DebugValueC,
			BuffsPurchased,
			GamblingProfit,
			PhotosSaved,
			ContentCopXP,
			ContentTriadXP,
			DebugValueFC,
			MissionMeleeKills,
			MissionGunKills,
			MissionMeleeWeaponKills,
			MissionDLCWeaponKills,
			CurrentVehicleKills,
			Num_Int32_Stats
		};

		enum ListStat
		{
			DUMMY_List,
			Num_List_Stats,
		};

		enum MapBinaryStat
		{
			Collectible_PhotoWall,
			SocialLogBinaryList,
			Num_MapBinary_Stats,
		};

		enum MapBoolStat
		{
			DynamicTutorials,
			Collectible_BoostRegion,
			Collectible_Generic,
			Collectible_BusStop,
			Collectible_Gunplay,
			Collectible_HidingSpot,
			Collectible_Melee,
			Collectible_MeleeDelivered,
			Collectible_EnforcerUnlocked,
			Collectible_CaseDoc,
			Collectible_WeaponSpawner,
			Collectible_CelebritiesPhotos,
			Collectible_Safehouse,
			DoorStateLocked,
			DoorOpenedByScript,
			DoorStateIsLeft,
			DoorStateAutoClose,
			Collectible_HijackReturn,
			Collectible_HijackRewards,
			Collectible_HijackFaceRewards,
			DrugVan,
			DrugBuoy,
			Collectible_Bio,
			Collectible_HealthShrineAB,
			Collectible_HealthShrineCN,
			Collectible_HealthShrineKT,
			Collectible_HealthShrineNP,
			Collectible_LockBoxAB,
			Collectible_LockBoxCN,
			Collectible_LockBoxKT,
			Collectible_LockBoxNP,
			Collectible_SpyCam,
			Collectible_GangsterPhotos,
			Collectible_LandmarksPhotos,
			Collectible_DLC_01,
			Collectible_DLC_02,
			Collectible_DLC_03,
			Collectible_DLC_04,
			Collectible_DLC_05,
			Collectible_DLC_06,
			Collectible_DLC_07,
			Collectible_DLC_08,
			Collectible_DLC_09,
			Collectible_DLC_10,
			Collectible_DLC_11,
			Collectible_DLC_12,
			Collectible_DLC_13,
			Collectible_DLC_14,
			Collectible_DLC_15,
			Collectible_DLC_16,
			Collectible_DLC_17,
			Collectible_DLC_18,
			Collectible_DLC_19,
			Collectible_DLC_20,
			Collectible_DLC_Visibility,
			StatGamesPlayedBoolList,
			DLCRedeemed,
			DLC_Asset_Clothing,
			DLC_Asset_Vehicle,
			DLC_Asset_Boat,
			DLC_Collectible_SafehouseItems,
			Asset_Clothing,
			Asset_Vehicle,
			Asset_Boat,
			Asset_Weapon,
			VehicleTiersOwned,
			MissionsCompleted,
			EventsCompleted,
			FavoursCompleted,
			CasesCompleted,
			DatesCompleted,
			StreetRacesCompletedWon,
			JobsCompleted,
			DLCCompleted,
			AchievementsCompleted,
			CompletedGameSlice,
			KaraokeSongs,
			SafeHousesOwned,
			FoodPurchasedBoolList,
			LeaderboardDirtyScoreBoolList,
			TShirtCommunityRedeemed,
			LastDLCRedeemed,
			WatchedNISBoolList,
			Collectible_DLCPermanentReward,
			Last50ShotsBoolList,
			ReservedFMapBool1,
			ReservedFMapBool2,
			ReservedFMapBool3,
			ReservedFMapBool4,
			ReservedFCMapBool1,
			ReservedFCMapBool2,
			ReservedFCMapBool3,
			ReservedFCMapBool4,
			Num_MapBool_Stats
		};

		enum MapFloatStat
		{
			BestTimeTrial,
			BestRaceTime,
			TimeOnRadioList,
			TimeOnCarList,
			TimeOnBikeList,
			TimeOnBoatList,
			PlayersStatsFloatList,
			PlayersStatsFloatListSum,
			PlayersStatsFloatListMax,
			WeaponSpawnerTimestamp,
			ReservedFMapFloat1,
			ReservedFMapFloat2,
			ReservedFMapFloat3,
			ReservedFMapFloat4,
			ReservedFCMapFloat1,
			ReservedFCMapFloat2,
			ReservedFCMapFloat3,
			ReservedFCMapFloat4,
			Num_MapFloat_Stats
		};

		enum MapInt32Stat
		{
			KaraokeScores,
			SlomoTutorials,
			MissionScores,
			CopScore,
			TriadScore,
			Outfits_Headgear,
			Outfits_Glasses,
			Outfits_Neck,
			Outfits_Body,
			Outfits_LeftWrist,
			Outfits_RightWrist,
			Outfits_LowerBody,
			Outfits_Footwear,
			Outfits_Accessories,
			DLCHighScores,
			InventoryItems,
			Collectible_TxtMsg,
			Collectible_AreaOwnership,
			Collectible_CaseLeads,
			Collectible_SafehouseItems,
			Collectible_Completed,
			UnlockedLoadingHints,
			CaseProgression,
			CompletedGameSliceCount,
			SpecialMoves,
			MeleeWeaponKills,
			FireArmFired,
			FireArmHits,
			FireArmKills,
			LeaderboardScoreIntList,
			StatAwardRankIntList,
			PlayersStatsIntList,
			PlayersStatsIntListSum,
			PlayersStatsIntListMax,
			KeyboardMapping,
			MissionsReplayed,
			GameSliceRetries,
			RadioStation,
			MissionIntData,
			ReservedFMapInt1,
			ReservedFMapInt2,
			ReservedFMapInt3,
			ReservedFMapInt4,
			ReservedFCMapInt1,
			ReservedFCMapInt2,
			ReservedFCMapInt3,
			ReservedFCMapInt4,
			Num_MapInt32_Stats
		};

		enum MapUInt64Stat
		{
			Outfits_CreationDateStamp,
			Num_MapUInt64_Stats
		};

		enum StringStat
		{
			LoadingHintPriority0,
			LoadingHintPriority1,
			LoadingHintPriority2,
			LoadingScreenPriority0,
			LoadingScreenPriority1,
			LoadingScreenPriority2,
			ActAnimationBank,
			MostListenedRadioStation,
			LeastListenedRadioStation,
			MostDrivenCar,
			LeastDrivenCar,
			MostDrivenBike,
			LeastDrivenBike,
			MostDrivenBoat,
			LeastDrivenBoat,
			MostRecentMission,
			MeleeUpgradesUnlocked,
			PoliceUpgradesUnlocked,
			TriadUpgradesUnlocked,
			MostAccurateGun,
			MostDeadlyGun,
			MostUsedGun,
			DUMMY_String,
			RadioStationOnEnter,
			MissionFinishedCaption,
			Num_String_Stats
		};

		enum TimeStat
		{
			TimeInTaxi,
			TimeLastBPH,
			PlayTime,
			TimeOnMissions,
			TimeOnFoot,
			TimeInCover,
			TimeSwimming,
			TimeInAberdeen,
			TimeInCentral,
			TimeInKennedyTown,
			TimeInNorthPoint,
			TimeInSafeHouse,
			TimeSpentPlayingPokerDice,
			ChaseDuration,
			MaxChaseDuration,
			StatAwardChaseDuration,
			VolatileRadioTimer,
			VolatileVehicleTimer,
			TimeBetweenMissions,
			TimeSinceLastMission,
			TimeInMission,
			TimeInMissionTotal,
			ReservedFTime1,
			ReservedFTime2,
			ReservedFTime3,
			ReservedFTime4,
			ReservedFCTime1,
			ReservedFCTime2,
			ReservedFCTime3,
			ReservedFCTime4,
			Num_Time_Stats
		};

		enum UInt64Stat
		{
			DUMMY_UINT64,
			Num_UInt64_Stats
		};
	};
}
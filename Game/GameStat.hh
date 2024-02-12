#pragma once

namespace UFG
{
	//==============================================================================
	// Enums

	namespace GameStat
	{
		enum BoolStat
		{
			VehicleRamUpgrade = 0x0,
			PreserveOnSave = 0x1,
			Collectible_Bio_New = 0x2,
			EnableSpyCams = 0x3,
			EnablePDA = 0x4,
			EnableValet = 0x5,
			EnableHealthShrineIndicators = 0x6,
			EnableLockboxIndicators = 0x7,
			EnableSpyCamIndicators = 0x8,
			EnableJadeStatueIndicators = 0x9,
			EnableJumpIndicators = 0xA,
			EnableDragonHelmet = 0xB,
			EnableDLC01CollectibleIndicators = 0xC,
			EnableDLC02CollectibleIndicators = 0xD,
			EnableDLC03CollectibleIndicators = 0xE,
			EnableDLC04CollectibleIndicators = 0xF,
			EnableDLC05CollectibleIndicators = 0x10,
			EnableDLC06CollectibleIndicators = 0x11,
			EnableDLC07CollectibleIndicators = 0x12,
			EnableDLC08CollectibleIndicators = 0x13,
			EnableDLC09CollectibleIndicators = 0x14,
			EnableDLC10CollectibleIndicators = 0x15,
			EnableDLC11CollectibleIndicators = 0x16,
			EnableDLC12CollectibleIndicators = 0x17,
			EnableDLC13CollectibleIndicators = 0x18,
			EnableDLC14CollectibleIndicators = 0x19,
			EnableDLC15CollectibleIndicators = 0x1A,
			EnableDLC16CollectibleIndicators = 0x1B,
			EnableDLC17CollectibleIndicators = 0x1C,
			EnableDLC18CollectibleIndicators = 0x1D,
			EnableDLC19CollectibleIndicators = 0x1E,
			EnableDLC20CollectibleIndicators = 0x1F,
			EnableKaraoke = 0x20,
			LastUsedVehicleIsCurrentlyUsed = 0x21,
			GameHints = 0x22,
			ContextHelp = 0x23,
			HudEnable = 0x24,
			XAxisInverted = 0x25,
			YAxisInverted = 0x26,
			SocialHubVisited = 0x27,
			CameraFreeLook = 0x28,
			AimSoftLockEnabled = 0x29,
			Vibration = 0x2A,
			OptionsDisableSocial = 0x2B,
			GPSArrows = 0x2C,
			PCKeyboardSwapMode = 0x2D,
			PCMouseInputRaw = 0x2E,
			HasNewChallengeMessage = 0x2F,
			Display_IsFullscreen = 0x30,
			Display_EnableMultiMonitor = 0x31,
			Display_Enable3D = 0x32,
			Display_EnableVSync = 0x33,
			Display_HighResTextures = 0x34,
			Display_ShadowResolution = 0x35,
			Display_ShadowFiltering = 0x36,
			Display_HighQualityMotionBlur = 0x37,
			Display_SSAO = 0x38,
			Display_FPSLimiter = 0x39,
			Num_Bool_Stats = 0x3A,
		};

		enum FloatStat
		{
			TotalDistanceDriven = 0x0,
			TotalTimeDriven = 0x1,
			TotalDistanceWalked = 0x2,
			Berserk_Damage_Multiplier = 0x3,
			Berserk_Activated = 0x4,
			Berserk_Duration = 0x5,
			Sharpshooter_Damage_Multiplier = 0x6,
			Sharpshooter_Accuracy_Rate_Multiplier = 0x7,
			Sharpshooter_Activated = 0x8,
			Sharpshooter_Duration = 0x9,
			Sharpshooter_Duration_Level1 = 0xA,
			Sharpshooter_Duration_Level2 = 0xB,
			Sharpshooter_Duration_Level3 = 0xC,
			HealthRegen_Activated = 0xD,
			HealthRegen_Duration_Level1 = 0xE,
			HealthRegen_Duration_Level2 = 0xF,
			HealthRegen_Duration_Level3 = 0x10,
			EnergyDrinkBuff_MeleeDamage_Multiplier1 = 0x11,
			EnergyDrinkBuff_MeleeDamage_Multiplier2 = 0x12,
			EnergyDrinkBuff_MeleeDamage_Multiplier3 = 0x13,
			EnergyDrinkBuff_Accuracy_Rate_Multiplier = 0x14,
			EnergyDrinkBuff_Activated = 0x15,
			EnergyDrinkBuff_Duration = 0x16,
			TeahouseBuff_Damage_Reduction1 = 0x17,
			TeahouseBuff_Damage_Reduction2 = 0x18,
			TeahouseBuff_Damage_Reduction3 = 0x19,
			TeaHouseBuff_Activated = 0x1A,
			TeaHouseBuff_Duration = 0x1B,
			MassageParlourBuff_FaceEarned_Multiplier1 = 0x1C,
			MassageParlourBuff_FaceEarned_Multiplier2 = 0x1D,
			MassageParlourBuff_FaceEarned_Multiplier3 = 0x1E,
			MassageParlourBuff_Activated = 0x1F,
			MassageParlourBuff_Duration = 0x20,
			PlayerFaceMeterBuff_BuffTimer = 0x21,
			PlayerFaceMeterBuff_Activated = 0x22,
			PlayerFaceMeterBuff_HealthPerHitGainedAtLevel2 = 0x23,
			PlayerFaceMeterBuff_CombatMeterBonusAdjustmentAtLevel5 = 0x24,
			StrikingBuff_ExtraDamage_Multiplier = 0x25,
			StrikingBuff_Activated = 0x26,
			StrikingBuff_Duration = 0x27,
			MaxHealth = 0x28,
			Heat = 0x29,
			MaxHeat = 0x2A,
			Face = 0x2B,
			FaceGained = 0x2C,
			FaceUsed = 0x2D,
			FaceLost = 0x2E,
			ClothingSetBuff_MeleeDamage_1_Multiplier = 0x2F,
			ClothingSetBuff_MeleeDamage_2_Multiplier = 0x30,
			ClothingSetBuff_MeleeDamage_3_Multiplier = 0x31,
			ClothingSetBuff_Inconspicuous_PoliceRadiusReduce_Multiplier = 0x32,
			ClothingSetBuff_Bulletproof_RangedDamageReduce_Multipler = 0x33,
			ClothingSetBuff_Negotiator_PurchaseDiscountPercentage_1 = 0x34,
			ClothingSetBuff_Negotiator_PurchaseDiscountPercentage_2 = 0x35,
			ClothingSetBuff_Negotiator_PurchaseDiscountPercentage_3 = 0x36,
			ClothingSetBuff_Monk_HealthRegenRate_Multiplier = 0x37,
			ClothingSetBuff_PumpedUp_ActionMeterBonus_Multiplier = 0x38,
			ClothingSetBuff_Triad_Enforcer_ActionMeterBonus_Multiplier = 0x39,
			ClothingSetBuff_Dragon_ActionMeterBonus_Multiplier = 0x3A,
			ClothingSetBuff_Sharpshooter_RangedAccuracyBonus_Multiplier = 0x3B,
			ClothingSetBuff_Tourist_PurchasePriceIncrease_Multiplier = 0x3C,
			ClothingSetBuff_StrikingDamage_Multiplier = 0x3D,
			ClothingSetBuff_StrikingDamageTriadEnforcer_Multiplier = 0x3E,
			ClothingSetBuff_GrappleDamage_Multiplier = 0x3F,
			ClothingSetBuff_HeatReduction_Multiplier = 0x40,
			ClothingSetBuff_CopXP_1_Multiplier = 0x41,
			ClothingSetBuff_CopXP_2_Multiplier = 0x42,
			ClothingSetBuff_CopXP_3_Multiplier = 0x43,
			ClothingSetBuff_TriadXP_1_Multiplier = 0x44,
			ClothingSetBuff_TriadXP_2_Multiplier = 0x45,
			ClothingSetBuff_TriadXP_3_Multiplier = 0x46,
			ClothingSetBuff_EliteSwat_Damage_Reduction_Multiplier = 0x47,
			FaceLevel9_Action_MeleeDamage_Multiplier = 0x48,
			FaceLevel5_Action_DamageReduction_Multiplier = 0x49,
			TriadOffensiveLevel1_StrikingDamage_Multiplier = 0x4A,
			TriadDefensiveLevel1_DamageReduction_Multiplier = 0x4B,
			TriadDefensiveLevel3_MeleeWeapon_DamageReduction_Multiplier = 0x4C,
			MonetaryPenalty_Arrest_Percentage = 0x4D,
			MonetaryPenalty_Hospital_Percentage = 0x4E,
			PlayerCheckpointLocationX = 0x4F,
			PlayerCheckpointLocationY = 0x50,
			PlayerCheckpointLocationZ = 0x51,
			PlayerLastStableLocationX = 0x52,
			PlayerLastStableLocationY = 0x53,
			PlayerLastStableLocationZ = 0x54,
			TotalTimeBetweenMissions = 0x55,
			LongestTimeBetweenMissions = 0x56,
			BestAirTime = 0x57,
			BestWheelieDistance = 0x58,
			HeighestJumpInCar = 0x59,
			HeighestJumpOnBike = 0x5A,
			HeighestJumpInBoat = 0x5B,
			LongestJumpInCar = 0x5C,
			LongestJumpOnBike = 0x5D,
			LongestJumpOnScooter = 0x5E,
			LongestJumpInTruck = 0x5F,
			LongestHoodBounce = 0x60,
			LongestBikeDriveAtMax = 0x61,
			TopSpeed = 0x62,
			LastUsedVehicleDismountLocationX = 0x63,
			LastUsedVehicleDismountLocationY = 0x64,
			LastUsedVehicleDismountLocationZ = 0x65,
			LongestShot = 0x66,
			LongestKill = 0x67,
			PropertyDamaged = 0x68,
			TimeInCars = 0x69,
			TimeOnBikes = 0x6A,
			TimeInBoats = 0x6B,
			TimeInRaces = 0x6C,
			LongestPlaySession = 0x6D,
			LongestCopChase = 0x6E,
			LongestCopChaseAtMaxHeat = 0x6F,
			CameraSpeedPitch = 0x70,
			CameraSpeedYaw = 0x71,
			AimSpeedPitch = 0x72,
			AimSpeedYaw = 0x73,
			AimSensitivity = 0x74,
			PCMouseSensitivity = 0x75,
			StoryProgress = 0x76,
			EventSuccessRate = 0x77,
			GameContentExprienced = 0x78,
			FireArmAccuracy = 0x79,
			PistolAccuracy = 0x7A,
			MachineGunAccuracy = 0x7B,
			SniperRifleAccuracy = 0x7C,
			AverageTimeBetweenMissions = 0x7D,
			AverageSpeed = 0x7E,
			Health = 0x7F,
			RegenHealthRatio = 0x80,
			WeatherIntensity = 0x81,
			WeatherWetness = 0x82,
			TimeOfDay = 0x83,
			TelemetryLocationX = 0x84,
			TelemetryLocationY = 0x85,
			TelemetryLocationZ = 0x86,
			TelemetryCopScore = 0x87,
			TelemetryTriadScore = 0x88,
			RangedDamageReceived = 0x89,
			MeleeDamageReceived = 0x8A,
			Num_Float_Stats = 0x8B,
		};

		enum IDStat
		{
			Headgear = 0x0,
			Head = 0x1,
			Glasses = 0x2,
			Neck = 0x3,
			Body = 0x4,
			LeftWrist = 0x5,
			RightWrist = 0x6,
			LowerBody = 0x7,
			Footwear = 0x8,
			Accessories = 0x9,
			Outfit = 0xA,
			CurrentHeadgear = 0xB,
			CurrentHead = 0xC,
			CurrentGlasses = 0xD,
			CurrentNeck = 0xE,
			CurrentBody = 0xF,
			CurrentLeftWrist = 0x10,
			CurrentRightWrist = 0x11,
			CurrentLowerBody = 0x12,
			CurrentFootwear = 0x13,
			CurrentAccessories = 0x14,
			CurrentOutfit = 0x15,
			Equipped = 0x16,
			WeaponEquipped = 0x17,
			WeaponStowed = 0x18,
			FlowId = 0x19,
			ValetVehicle = 0x1A,
			ValetVehicleObject = 0x1B,
			LastCompletedMaster = 0x1C,
			LastCompletedMission = 0x1D,
			LastUsedVehicle = 0x1E,
			TraceContact = 0x1F,
			KillerNameEnemy = 0x20,
			KillerNameWeapon = 0x21,
			PlayerWeapon = 0x22,
			ReservedFID1 = 0x23,
			ReservedFID2 = 0x24,
			ReservedFID3 = 0x25,
			ReservedFID4 = 0x26,
			ReservedFCID1 = 0x27,
			ReservedFCID2 = 0x28,
			ReservedFCID3 = 0x29,
			ReservedFCID4 = 0x2A,
			MissionFinishedReason = 0x2B,
			Num_ID_Stats = 0x2C,
		};

		enum Int32Stat
		{
			DebugValueF = 0x0,
			HighestHeatLevel = 0x1,
			TimesKilled = 0x2,
			KilledByGunFire = 0x3,
			KilledByMelee = 0x4,
			KilledByVehicles = 0x5,
			TimesArrested = 0x6,
			RestoreUsed = 0x7,
			PedsKilled = 0x8,
			EnemiesKilled = 0x9,
			PhotosTaken = 0xA,
			PhotosDeleted = 0xB,
			VaultsSuccess = 0xC,
			VaultsFailed = 0xD,
			CutSceneWatched = 0xE,
			CutSceneSkipped = 0xF,
			MostKillsInBikeMayhem = 0x10,
			Perks = 0x11,
			CustomizationVersion = 0x12,
			StatueUpgradePoint = 0x13,
			TriadUpgradePoint = 0x14,
			CopUpgradePoint = 0x15,
			StatueDefensiveStage = 0x16,
			StatueOffensiveStage = 0x17,
			TriadDefensiveStage = 0x18,
			TriadOffensiveStage = 0x19,
			GunplayUpgradeStage = 0x1A,
			CopDrivingStage = 0x1B,
			CopShootingStage = 0x1C,
			Standing = 0x1D,
			CopXP = 0x1E,
			TriadXP = 0x1F,
			CounterFailed = 0x20,
			FaceActionSuccess = 0x21,
			FaceActionFailed = 0x22,
			MaxHealthUpgradePoint = 0x23,
			NumClothingChanged = 0x24,
			ClothingSetBuff = 0x25,
			ClothingBuffHat = 0x26,
			ClothingBuffNeck = 0x27,
			ClothingBuffGlasses = 0x28,
			ClothingBuffLeftWrist = 0x29,
			ClothingBuffRightWrist = 0x2A,
			Group_Intimidate_Points = 0x2B,
			MonetaryPenalty_Arrest_MaxSum = 0x2C,
			MonetaryPenalty_Hospital_MaxSum = 0x2D,
			ClipAmmo = 0x2E,
			Collectible_HijackCargoKept = 0x2F,
			MiniGamePlayed = 0x30,
			MissionsAttmpted = 0x31,
			MissionsFailed = 0x32,
			EventsAttempted = 0x33,
			EventsFailed = 0x34,
			FavoursAttempted = 0x35,
			FavoursFailed = 0x36,
			CasesAttempted = 0x37,
			CasesFailed = 0x38,
			DatesAttempted = 0x39,
			DatesFailed = 0x3A,
			StreetRacesLost = 0x3B,
			VendorExtortionProgress = 0x3C,
			TotalCashEarned = 0x3D,
			Money = 0x3E,
			MostCashHeld = 0x3F,
			GamblingEarnings = 0x40,
			GamblingLoss = 0x41,
			BusDriverEarnings = 0x42,
			LimoDriverEarnings = 0x43,
			RepoEarnings = 0x44,
			CashSpentOnClothes = 0x45,
			CashSpentOnWeapons = 0x46,
			CashSpentOnVehicles = 0x47,
			CashSpentOnEnergyDrinks = 0x48,
			CashSpentOnMassages = 0x49,
			CashSpentOnHerbalTea = 0x4A,
			CashSpentOnPorkBuns = 0x4B,
			CashSpentOnTaxis = 0x4C,
			CashSpentOnSafehouseDecor = 0x4D,
			PokerDicePlayed = 0x4E,
			EnergyDrinksPurchased = 0x4F,
			MassagesPurchased = 0x50,
			HerbalTeaPurchased = 0x51,
			PorkBunsPurchased = 0x52,
			FoodPurchased = 0x53,
			VehicleKills = 0x54,
			CarKills = 0x55,
			BikeKills = 0x56,
			BoatKills = 0x57,
			VehiclesStolen = 0x58,
			VehiclesActionHijacked = 0x59,
			VehiclesWrecked = 0x5A,
			VehiclesDrovenIntoOcean = 0x5B,
			BikeJumpsOffCars = 0x5C,
			HoodBounces = 0x5D,
			KillsFromCover = 0x5E,
			BlockedAttacks = 0x5F,
			TiresShot = 0x60,
			TiresShotFromVehicle = 0x61,
			VehicleExplosions = 0x62,
			LockOnKills = 0x63,
			ShotsMade = 0x64,
			ShotsHit = 0x65,
			PistolFired = 0x66,
			PistolHits = 0x67,
			PistolKills = 0x68,
			MachineGunFired = 0x69,
			MachineGunHits = 0x6A,
			MachineGunKills = 0x6B,
			SniperRifleFired = 0x6C,
			SniperRifleHits = 0x6D,
			SniperRifleKills = 0x6E,
			RifleFired = 0x6F,
			RifleHits = 0x70,
			RifleKills = 0x71,
			ShotgunFired = 0x72,
			ShotgunHits = 0x73,
			ShotgunKills = 0x74,
			WeaponsPickup = 0x75,
			ElectricPanelKills = 0x76,
			FridgeDoorKills = 0x77,
			DumpsterKills = 0x78,
			RoofFanKills = 0x79,
			DebugValueO = 0x7A,
			Gamma = 0x7B,
			UIScale = 0x7C,
			VolumeSFX = 0x7D,
			VolumeDialogue = 0x7E,
			VolumeMusic = 0x7F,
			VolumeCarMusic = 0x80,
			Subtitles = 0x81,
			GunReticle = 0x82,
			AimMode = 0x83,
			DrivingConfig = 0x84,
			PCKeyboardSwapModeExtended = 0x85,
			SocialChallengeSent = 0x86,
			SocialChallengeReceived = 0x87,
			SocialChallengeBeaten = 0x88,
			SocialLogEntryId = 0x89,
			InstalledDLCBitField = 0x8A,
			InstalledDLCBitField1 = 0x8B,
			IsBannedByCommunityManager = 0x8C,
			StatAward_OverallRank = 0x8D,
			DisplayMode_BackBufferWidth = 0x8E,
			DisplayMode_BackBufferHeight = 0x8F,
			DisplayMode_RefreshRateNumerator = 0x90,
			DisplayMode_RefreshRateDenominator = 0x91,
			DisplayMode_AdapterUID = 0x92,
			DisplayMode_MonitorUID = 0x93,
			DisplayMode_Scaling = 0x94,
			DisplayMode_ScanlineMode = 0x95,
			Display_AAQuality = 0x96,
			DebugValueC = 0x97,
			BuffsPurchased = 0x98,
			GamblingProfit = 0x99,
			PhotosSaved = 0x9A,
			ContentCopXP = 0x9B,
			ContentTriadXP = 0x9C,
			DebugValueFC = 0x9D,
			MissionMeleeKills = 0x9E,
			MissionGunKills = 0x9F,
			MissionMeleeWeaponKills = 0xA0,
			MissionDLCWeaponKills = 0xA1,
			CurrentVehicleKills = 0xA2,
			Num_Int32_Stats = 0xA3,
		};
	
		enum MapBoolStat
		{
			DynamicTutorials = 0x0,
			Collectible_BoostRegion = 0x1,
			Collectible_Generic = 0x2,
			Collectible_BusStop = 0x3,
			Collectible_Gunplay = 0x4,
			Collectible_HidingSpot = 0x5,
			Collectible_Melee = 0x6,
			Collectible_MeleeDelivered = 0x7,
			Collectible_EnforcerUnlocked = 0x8,
			Collectible_CaseDoc = 0x9,
			Collectible_WeaponSpawner = 0xA,
			Collectible_CelebritiesPhotos = 0xB,
			Collectible_Safehouse = 0xC,
			DoorStateLocked = 0xD,
			DoorOpenedByScript = 0xE,
			DoorStateIsLeft = 0xF,
			DoorStateAutoClose = 0x10,
			Collectible_HijackReturn = 0x11,
			Collectible_HijackRewards = 0x12,
			Collectible_HijackFaceRewards = 0x13,
			DrugVan = 0x14,
			DrugBuoy = 0x15,
			Collectible_Bio = 0x16,
			Collectible_HealthShrineAB = 0x17,
			Collectible_HealthShrineCN = 0x18,
			Collectible_HealthShrineKT = 0x19,
			Collectible_HealthShrineNP = 0x1A,
			Collectible_LockBoxAB = 0x1B,
			Collectible_LockBoxCN = 0x1C,
			Collectible_LockBoxKT = 0x1D,
			Collectible_LockBoxNP = 0x1E,
			Collectible_SpyCam = 0x1F,
			Collectible_GangsterPhotos = 0x20,
			Collectible_LandmarksPhotos = 0x21,
			Collectible_DLC_01 = 0x22,
			Collectible_DLC_02 = 0x23,
			Collectible_DLC_03 = 0x24,
			Collectible_DLC_04 = 0x25,
			Collectible_DLC_05 = 0x26,
			Collectible_DLC_06 = 0x27,
			Collectible_DLC_07 = 0x28,
			Collectible_DLC_08 = 0x29,
			Collectible_DLC_09 = 0x2A,
			Collectible_DLC_10 = 0x2B,
			Collectible_DLC_11 = 0x2C,
			Collectible_DLC_12 = 0x2D,
			Collectible_DLC_13 = 0x2E,
			Collectible_DLC_14 = 0x2F,
			Collectible_DLC_15 = 0x30,
			Collectible_DLC_16 = 0x31,
			Collectible_DLC_17 = 0x32,
			Collectible_DLC_18 = 0x33,
			Collectible_DLC_19 = 0x34,
			Collectible_DLC_20 = 0x35,
			Collectible_DLC_Visibility = 0x36,
			StatGamesPlayedBoolList = 0x37,
			DLCRedeemed = 0x38,
			DLC_Asset_Clothing = 0x39,
			DLC_Asset_Vehicle = 0x3A,
			DLC_Asset_Boat = 0x3B,
			DLC_Collectible_SafehouseItems = 0x3C,
			Asset_Clothing = 0x3D,
			Asset_Vehicle = 0x3E,
			Asset_Boat = 0x3F,
			Asset_Weapon = 0x40,
			VehicleTiersOwned = 0x41,
			MissionsCompleted = 0x42,
			EventsCompleted = 0x43,
			FavoursCompleted = 0x44,
			CasesCompleted = 0x45,
			DatesCompleted = 0x46,
			StreetRacesCompletedWon = 0x47,
			JobsCompleted = 0x48,
			DLCCompleted = 0x49,
			AchievementsCompleted = 0x4A,
			CompletedGameSlice = 0x4B,
			KaraokeSongs = 0x4C,
			SafeHousesOwned = 0x4D,
			FoodPurchasedBoolList = 0x4E,
			LeaderboardDirtyScoreBoolList = 0x4F,
			TShirtCommunityRedeemed = 0x50,
			LastDLCRedeemed = 0x51,
			WatchedNISBoolList = 0x52,
			Collectible_DLCPermanentReward = 0x53,
			Last50ShotsBoolList = 0x54,
			ReservedFMapBool1 = 0x55,
			ReservedFMapBool2 = 0x56,
			ReservedFMapBool3 = 0x57,
			ReservedFMapBool4 = 0x58,
			ReservedFCMapBool1 = 0x59,
			ReservedFCMapBool2 = 0x5A,
			ReservedFCMapBool3 = 0x5B,
			ReservedFCMapBool4 = 0x5C,
			Num_MapBool_Stats = 0x5D,
		};
	}

	//==============================================================================

	class CGameStatTracker
	{
	public:
		CFactionInterface mFactionInterface;
		qPropertySet* mpDefaultData;
		qPropertySet* mpRuntimeData;
		qPropertySet* mpFaceLevelPropertySet;
		qPropertyList* mpFaceLevelPropertyList;
		int m_iMaxFaceLevel;
		qPropertySet* mpXPThresholdPropertySet;
		qPropertyList* mpXPThresholdPropertyList[2];
		uint32_t mMaxXPThresholdLevels[2];

		struct GameSnapshot_t
		{
			struct Time_t
			{
				uint64_t mTimestamp;
				float mElapsedTime;
				bool mIsStarted;
			};
			Time_t mTimes[30];

			qSymbol mIDs[44];
			bool mBools[58];
			int mInts[163];
			uint64_t mUInt64s[1];
			float mFloats[139];

			struct IntRanged_t
			{
				int mValue;
				int mRange;
			};
			IntRanged_t mIntsRanged[7];

			struct FloatRanged_t
			{
				float mValue;
				float mRange;
			};
			FloatRanged_t mFloatsRanged[1];

			qString mStrings[25];

			struct Binary_t
			{
				void* mpBuffer;
				unsigned int mSize;
			};
			Binary_t mBinaries[3];

			struct MapKeyValue_t
			{
				qSymbol mKey;

				union
				{
					float mFloatValue;
					int mIntValue;
					bool mBoolValue;
				};
			};

			struct MapBool_t
			{
				int mKeepType;
				qArray<MapKeyValue_t> mValues;
				qArray<qSymbol> mNames;
				int mPersistentDataType;
			};
			MapBool_t* mpMapBools[93];

			struct MapInt_t
			{
				qArray<MapKeyValue_t> mValues;
				int mPersistentDataType;
			};
			MapInt_t* mpMapInts[47];

			struct MapUInt64_t
			{
				qArray<MapKeyValue_t> mValues;
				int mPersistentDataType;
			};
			MapUInt64_t* mpMapUInt64s[1];

			struct MapFloat_t
			{
				qArray<MapKeyValue_t> mValues;
				int mPersistentDataType;
			};
			MapFloat_t* mpMapFloats[18];

			struct MapBinary_t
			{
				qArray<MapKeyValue_t> mValues;
				int mPersistentDataType;
			};
			MapBinary_t* mpMapBinaries[2];

			struct List_t
			{
				int mType;
				union
				{
					qArray<long>* mIntList;
					qArray<int64_t>* mInt64List;
					qArray<bool>* mBoolList;
					qArray<float>* mFloatList;
					void* mListInternal;
				};
			};
			List_t* mpList[1];
		};
		GameSnapshot_t* mpSnapshots[5];
		GameSnapshot_t::Time_t mSessionTimer;
		bool m_bIsApplyingSnapshotEffects : 1;

		static UFG_INLINE CGameStatTracker* Instance()
		{
			return *reinterpret_cast<CGameStatTracker**>(UFG_RVA(0x2405488));
		}

		//======================================================================

		UFG_INLINE void SetStat(GameStat::MapBoolStat p_Stat, qSymbol p_NameUID, bool p_Value)
		{
			reinterpret_cast<void(__fastcall*)(void*, GameStat::MapBoolStat, qSymbol*, bool)>(UFG_RVA(0x4BD3E0))(this, p_Stat, &p_NameUID, p_Value);
		}

		UFG_INLINE void SetStat(GameStat::BoolStat p_Stat, bool p_Value)
		{
			mpSnapshots[0]->mBools[p_Stat] = p_Value;
		}

		UFG_INLINE void SetStat(GameStat::FloatStat p_Stat, float p_Value)
		{
			mpSnapshots[0]->mFloats[p_Stat] = p_Value;
		}

		UFG_INLINE void SetStat(GameStat::IDStat p_Stat, qSymbol p_Value)
		{
			mpSnapshots[0]->mIDs[p_Stat] = p_Value;
		}

		UFG_INLINE void SetStat(GameStat::Int32Stat p_Stat, int p_Value)
		{
			mpSnapshots[0]->mInts[p_Stat] = p_Value;
		}

		//======================================================================

		UFG_INLINE bool GetStat(GameStat::BoolStat p_Stat)
		{
			return mpSnapshots[0]->mBools[p_Stat];
		}

		UFG_INLINE float GetStat(GameStat::FloatStat p_Stat)
		{
			return mpSnapshots[0]->mFloats[p_Stat];
		}

		UFG_INLINE qSymbol GetStat(GameStat::IDStat p_Stat)
		{
			return mpSnapshots[0]->mIDs[p_Stat];
		}

		UFG_INLINE int GetStat(GameStat::Int32Stat p_Stat)
		{
			return mpSnapshots[0]->mInts[p_Stat];
		}
	};

	namespace GameStatTracker
	{
		uint8_t g_ScrambleKey[] = { 0x37, 0x0C, 0x43, 0xB9, 0x91, 0xC9, 0x8C, 0x6C, 0xE5, 0x6F, 0x9D, 0x69, 0xB4, 0xC7, 0x20, 0xD0, 0x81, 0xAE, 0x0D, 0x93, 0xE9, 0xB5, 0x65, 0x6E, 0xB2, 0xF2, 0x11, 0x7C, 0x74, 0xE8, 0x36, 0xD8 };

		uint32_t GetBufferHash(uint32_t p_HeaderSize, char* p_Buffer, uint32_t p_BufferSize)
		{
			uint32_t m_TotalSize = (p_BufferSize - p_HeaderSize - 4);
			if (0 > m_TotalSize)
				return -1;

			char* p_RawBuffer = &p_Buffer[p_HeaderSize];

			uint32_t m_Hash = -1;
			uint32_t m_CrcTable32DupFromChecksumCPP[256] = 
			{ 
				0u, 79764919u, 159529838u, 222504665u, 319059676u, 398814059u, 445009330u, 507990021u, 638119352u, 583659535u, 797628118u, 726387553u, 890018660u, 835552979u, 1015980042u, 
				944750013u, 1276238704u, 1221641927u, 1167319070u, 1095957929u, 1595256236u, 1540665371u, 1452775106u, 1381403509u, 1780037320u, 1859660671u, 1671105958u, 1733955601u, 2031960084u, 
				2111593891u, 1889500026u, 1952343757u, 2552477408u, 2632100695u, 2443283854u, 2506133561u, 2334638140u, 2414271883u, 2191915858u, 2254759653u, 3190512472u, 3135915759u, 3081330742u, 
				3009969537u, 2905550212u, 2850959411u, 2762807018u, 2691435357u, 3560074640u, 3505614887u, 3719321342u, 3648080713u, 3342211916u, 3287746299u, 3467911202u, 3396681109u, 4063920168u,
				4143685023u, 4223187782u, 4286162673u, 3779000052u, 3858754371u, 3904687514u, 3967668269u, 881225847u, 809987520u, 1023691545u, 969234094u, 662832811u, 591600412u, 771767749u, 717299826u, 
				311336399u, 374308984u, 453813921u, 533576470u, 25881363u, 88864420u, 134795389u, 214552010u, 2023205639u, 2086057648u, 1897238633u, 1976864222u, 1804852699u, 1867694188u, 1645340341u, 
				1724971778u, 1587496639u, 1516133128u, 1461550545u, 1406951526u, 1302016099u, 1230646740u, 1142491917u, 1087903418u, 2896545431u, 2825181984u, 2770861561u, 2716262478u, 3215044683u, 
				3143675388u, 3055782693u, 3001194130u, 2326604591u, 2389456536u, 2200899649u, 2280525302u, 2578013683u, 2640855108u, 2418763421u, 2498394922u, 3769900519u, 3832873040u, 3912640137u, 
				3992402750u, 4088425275u, 4151408268u, 4197601365u, 4277358050u, 3334271071u, 3263032808u, 3476998961u, 3422541446u, 3585640067u, 3514407732u, 3694837229u, 3640369242u, 1762451694u, 
				1842216281u, 1619975040u, 1682949687u, 2047383090u, 2127137669u, 1938468188u, 2001449195u, 1325665622u, 1271206113u, 1183200824u, 1111960463u, 1543535498u, 1489069629u, 1434599652u, 
				1363369299u, 622672798u, 568075817u, 748617968u, 677256519u, 907627842u, 853037301u, 1067152940u, 995781531u, 51762726u, 131386257u, 177728840u, 240578815u, 269590778u, 349224269u, 
				429104020u, 491947555u, 4046411278u, 4126034873u, 4172115296u, 4234965207u, 3794477266u, 3874110821u, 3953728444u, 4016571915u, 3609705398u, 3555108353u, 3735388376u, 3664026991u, 
				3290680682u, 3236090077u, 3449943556u, 3378572211u, 3174993278u, 3120533705u, 3032266256u, 2961025959u, 2923101090u, 2868635157u, 2813903052u, 2742672763u, 2604032198u, 2683796849u, 
				2461293480u, 2524268063u, 2284983834u, 2364738477u, 2175806836u, 2238787779u, 1569362073u, 1498123566u, 1409854455u, 1355396672u, 1317987909u, 1246755826u, 1192025387u, 1137557660u, 
				2072149281u, 2135122070u, 1912620623u, 1992383480u, 1753615357u, 1816598090u, 1627664531u, 1707420964u, 295390185u, 358241886u, 404320391u, 483945776u, 43990325u, 106832002u, 
				186451547u, 266083308u, 932423249u, 861060070u, 1041341759u, 986742920u, 613929101u, 542559546u, 756411363u, 701822548u, 3316196985u, 3244833742u, 3425377559u, 3370778784u, 
				3601682597u, 3530312978u, 3744426955u, 3689838204u, 3819031489u, 3881883254u, 3928223919u, 4007849240u, 4037393693u, 4100235434u, 4180117107u, 4259748804u, 2310601993u, 2373574846u, 
				2151335527u, 2231098320u, 2596047829u, 2659030626u, 2470359227u, 2550115596u, 2947551409u, 2876312838u, 2788305887u, 2733848168u, 3165939309u, 3094707162u, 3040238851u, 2985771188u 
			};

			for (uint32_t i = 0; m_TotalSize > i; ++i)
				m_Hash = (m_Hash << 8) ^ m_CrcTable32DupFromChecksumCPP[static_cast<uint8_t>(p_RawBuffer[i] ^ m_Hash)];

			return m_Hash;
		}

		void Descramble(uint64_t p_Timestamp, uint32_t p_HeaderSize, char* p_Buffer, uint32_t p_BufferSize)
		{
			uint32_t m_TotalSize = (p_BufferSize - p_HeaderSize);
			if (0 > m_TotalSize)
				return;

			char p_TimestampKey = 0;
			for (; p_Timestamp; p_Timestamp &= p_Timestamp - 1)
				++p_TimestampKey;

			char* p_XoredBuffer = &p_Buffer[p_HeaderSize];
			char m_UnXorIndex = 0;
			for (uint32_t i = 0; m_TotalSize > i; ++i)
			{
				char c_XorKey = static_cast<char>(i);
				c_XorKey += g_ScrambleKey[m_UnXorIndex % sizeof(g_ScrambleKey)];
				c_XorKey += g_ScrambleKey[(p_TimestampKey + static_cast<char>(i)) % sizeof(g_ScrambleKey)];

				p_XoredBuffer[i] = (p_XoredBuffer[i] ^ c_XorKey);
				m_UnXorIndex += p_XoredBuffer[i];
			}
		}
	}
}
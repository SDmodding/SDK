#pragma once

namespace UFG
{
	namespace AimingPlayerComponent
	{
		enum eAimBlendMode
		{
			eAIM_BLEND_MODE_NONE = 0x0,
			eAIM_BLEND_MODE_FREEAIM = 0x1,
			eAIM_BLEND_MODE_FREEAIM_TARGET = 0x2,
			eAIM_BLEND_MODE_SUBTARGETING = 0x3,
		};

		enum eSoftLockTypeEnum
		{
			eSOFT_LOCK_NONE = 0x0,
			eSOFT_LOCK_ABSOLUTE = 0x1,
			eSOFT_LOCK_RELATIVE_LOCAL = 0x2,
			eSOFT_LOCK_RELATIVE_LOCAL_ORIENTED_TO_ORIGIN = 0x3,
			NUM_SOFT_LOCK_TYPES = 0x4,
		};
	}

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
	}

	namespace PhysicsVehicle
	{
		enum Lod
		{
			LOD_UNINITIALIZED = 0x0,
			LOD_LOW = 0x1,
			LOD_MEDIUM = 0x2,
			LOD_HIGH = 0x3,
			LOD_NIS = 0x4,
			LOD_RESOURCES_UNLOADED = 0x5,
		};
	}

	namespace RagdollComponent
	{
		enum PoseState
		{
			STATE_VELOCITY_TRACKING = 0x0,
			STATE_POWERED_TRACKING = 0x1,
			STATE_TRANSITION_TO_POWERED = 0x2,
			STATE_FORCE = 0x3,
			STATE_UNINITIALIZED = 0x4,
			STATE_KEYFRAME_TRACKING = 0x5,
			STATE_FREEZE_TRACKING = 0x6,
		};

	}

	enum eAIObjective
	{
		eAI_OBJECTIVE_NONE = 0x0,
		eAI_OBJECTIVE_ATTACK_TARGET = 0x1,
		eAI_OBJECTIVE_ATTACK_NEARBY_TARGET = 0x2,
		eAI_OBJECTIVE_ATTACK_WHEN_SEE_TARGET = 0x3,
		eAI_OBJECTIVE_ATTACK_WHEN_STEALTH_TARGET_SPOTTED = 0x4,
		eAI_OBJECTIVE_ATTACK_USING_COVER = 0x5,
		eAI_OBJECTIVE_ATTACK_IN_SCRIPTED_VEHICLE = 0x6,
		eAI_OBJECTIVE_SHOOT_AT_MARKER = 0x7,
		eAI_OBJECTIVE_FLEE = 0x8,
		eAI_OBJECTIVE_FLEE_SPREAD_PANIC = 0x9,
		eAI_OBJECTIVE_FORCE_ENTER_COVER = 0xA,
		eAI_OBJECTIVE_RUN_LATERALLY_FROM_TARGET = 0xB,
		eAI_OBJECTIVE_INVESTIGATE_TARGET = 0xC,
		eAI_OBJECTIVE_PURSUIT_TARGET = 0xD,
		eAI_OBJECTIVE_FOLLOW_TARGET = 0xE,
		eAI_OBJECTIVE_FACE_TARGET = 0xF,
		eAI_OBJECTIVE_FACE_TARGET_WHILE_SCARED = 0x10,
		eAI_OBJECTIVE_BE_ALLY = 0x11,
		eAI_OBJECTIVE_GET_IN_VEHICLE = 0x12,
		eAI_OBJECTIVE_GET_OUT_OF_VEHICLE = 0x13,
		eAI_OBJECTIVE_BE_INTIMIDATED = 0x14,
		eAI_OBJECTIVE_PATHFIND_TO_SELECTED_OBJECT = 0x15,
		eAI_OBJECTIVE_HIJACK_VEHICLE = 0x16,
		eAI_OBJECTIVE_IDLE = 0x17,
		eAI_OBJECTIVE_MOVE_AWAY = 0x18,
		eAI_OBJECTIVE_RUN_AWAY = 0x19,
		eAI_OBJECTIVE_GRAB_AND_HOLD = 0x1A,
		eAI_OBJECTIVE_DUCK_AND_COVER = 0x1B,
		eAI_OBJECTIVE_DENOUEMENT = 0x1C,
		eAI_OBJECTIVE_WEAPON_PICKUP = 0x1D,
		eAI_OBJECTIVE_COMBAT_DUMMY = 0x1E,
		eAI_OBJECTIVE_PATHFIND_TO_POINT_WITH_BREAKOUT = 0x1F,
		eAI_OBJECTIVE_COMBAT_FAST_TALK = 0x20,
		eAI_OBJECTIVE_ATTACK_SUCKERPUNCH_TARGET = 0x21,
		eAI_OBJECTIVE_ROB_TARGET = 0x22,
		eAI_OBJECTIVE_PATDOWN_TARGET = 0x23,
		NUM_AI_OBJECTIVES = 0x24,
	};

	enum eCharacterActionRequestEnum
	{
		eCHARACTER_ACTION_REQUEST_ATTACK = 0xF,
		eCHARACTER_ACTION_REQUEST_SPRINT = 0x37,
		eCHARACTER_ACTION_REQUEST_JOG = 0x38,
		eCHARACTER_ACTION_REQUEST_WALK = 0x39,
		eCHARACTER_ACTION_REQUEST_POST_ATTACK = 0xC1,
	};

	enum eCharacterTypeEnum
	{
		eCHARACTER_TYPE_INVALID = 0x0,
		eCHARACTER_TYPE_PLAYER = 0x1,
		eCHARACTER_TYPE_AMANDA = 0x2,
		eCHARACTER_TYPE_PEDESTRIAN = 0x3,
		eCHARACTER_TYPE_SHOPKEEPER = 0x4,
		eCHARACTER_TYPE_THUG = 0x5,
		eCHARACTER_TYPE_JACKIE = 0x6,
		eCHARACTER_TYPE_WAITRESS = 0x7,
		eCHARACTER_TYPE_BARTENDER = 0x8,
		eCHARACTER_TYPE_BOUNCER = 0x9,
		eCHARACTER_TYPE_POLICE_VARIANT1 = 0xA,
		eCHARACTER_TYPE_POLICE_VARIANT2 = 0xB,
		eCHARACTER_TYPE_POLICE_VARIANT3 = 0xC,
		eCHARACTER_TYPE_POLICE_VARIANT4 = 0xD,
		eCHARACTER_TYPE_POLICE_SWAT = 0xE,
		eCHARACTER_TYPE_NET_REMOTE_PLAYER = 0xF,
		eCHARACTER_TYPE_BENNY = 0x10,
		eCHARACTER_TYPE_DIRTY_MING = 0x11,
		eCHARACTER_TYPE_MRS_CHU = 0x12,
		eCHARACTER_TYPE_SS_WORKER = 0x13,
		eCHARACTER_TYPE_PED_DRUNK = 0x14,
		eCHARACTER_TYPE_PED_JUNKIE = 0x15,
		eCHARACTER_TYPE_PED_FAST = 0x16,
		eCHARACTER_TYPE_PED_SLOW = 0x17,
		eCHARACTER_TYPE_PED_SEXY = 0x18,
		eCHARACTER_TYPE_PED_ELDERLY = 0x19,
		eCHARACTER_TYPE_BEGGAR = 0x1A,
		eCHARACTER_TYPE_METER_MAID = 0x1B,
		eCHARACTER_TYPE_THIEF = 0x1C,
		eCHARACTER_TYPE_TIFFANY = 0x1D,
		eCHARACTER_TYPE_SIFU = 0x1E,
		eCHARACTER_TYPE_MARTIAL_ARTS_STUDENT = 0x1F,
		eCHARACTER_TYPE_ROOSTER = 0x20,
		eCHARACTER_TYPE_EMT = 0x21,
		eCHARACTER_TYPE_VALET = 0x22,
		eCHARACTER_TYPE_TONG = 0x23,
		eCHARACTER_TYPE_COOK = 0x24,
		eCHARACTER_TYPE_UNCLE_PO = 0x25,
		eCHARACTER_TYPE_DOGEYES = 0x26,
		eCHARACTER_TYPE_ZI_WAI = 0x27,
		eCHARACTER_TYPE_DLC_ELITE_GHOUL = 0x28,
		eCHARACTER_TYPE_DLC_JIANG_SHI = 0x29,
		eCHARACTER_TYPE_DLC_HAPPY_CAT = 0x2A,
		NUM_CHARACTER_TYPES = 0x2B,
	};

	enum eCharacterCollisionMode
	{
		CP_INVALID = 0x0,
		CP_WALK = 0x1,
		CP_CROUCH = 0x2,
		CP_CRAWL = 0x3,
		CP_DRIVING = 0x4,
		CP_ENTER_EXIT_VEHICLE = 0x5,
		CP_DISABLED = 0x6,
		CP_SITTING = 0x7,
		CP_COMBAT = 0x8,
		CP_DEAD = 0x9,
		CP_GRAPPLE = 0xA,
		CP_GRAPPLE_SMALL = 0xB,
		CP_COVER = 0xC,
		CP_FREERUN = 0xD,
		CP_NUM_SHAPES = 0xE,
	};

	enum eFactionClassEnum
	{
		FACTION_INVALID = 0x0,
		FACTION_INDIFFERENT = 0x1,
		FACTION_PLAYER = 0x2,
		FACTION_LAW = 0x3,
		FACTION_TRIAD_WINSTON = 0x4,
		FACTION_TRIAD_DOGEYES = 0x5,
		FACTION_TRIAD_SONNY = 0x6,
		FACTION_TRIAD_JIIANG = 0x7,
		FACTION_TRIAD_CHEUK = 0x8,
		FACTION_TRIAD_TWOCHIN = 0x9,
		FACTION_TRIAD_GENERIC = 0xA,
		FACTION_TRIAD_WATERSTREET = 0xB,
		FACTION_TRIAD_18K = 0xC,
		FACTION_TRIAD_DOGBOYS = 0xD,
		FACTION_TRIAD_SUNONYEE = 0xE,
		FACTION_TRIAD_LEE = 0xF,
		FACTION_BOUNCER = 0x10,
		FACTION_INNOCENT = 0x11,
		FACTION_STUDENT = 0x12,
		FACTION_AMBIENT_AGGRESSIVE = 0x13,
		FACTION_AMBIENT_GROUP_1 = 0x14,
		FACTION_AMBIENT_GROUP_2 = 0x15,
		FACTION_AMBIENT_GROUP_3 = 0x16,
		FACTION_AMBIENT_GROUP_4 = 0x17,
		FACTION_NETWORK_TEAM_1 = 0x18,
		FACTION_NETWORK_TEAM_2 = 0x19,
		FACTION_NETWORK_TEAM_3 = 0x1A,
		FACTION_NETWORK_TEAM_4 = 0x1B,
		FACTION_NETWORK_TEAM_5 = 0x1C,
		FACTION_NETWORK_TEAM_6 = 0x1D,
		FACTION_NETWORK_TEAM_7 = 0x1E,
		FACTION_NETWORK_TEAM_8 = 0x1F,
		FACTION_HOSTILE_SPECIAL_1 = 0x20,
		FACTION_HOSTILE_SPECIAL_2 = 0x21,
		FACTION_ALLIED_SPECIAL_1 = 0x22,
		FACTION_ALLIED_SPECIAL_2 = 0x23,
		FACTION_LAW_HOSTILE = 0x24,
		FACTION_ROOSTER1 = 0x25,
		FACTION_ROOSTER2 = 0x26,
		NUM_FACTIONS = 0x27,
	};

	enum eFightingClassEnum
	{
		eFIGHTING_CLASS_INVALID = 0x0,
		eFIGHTING_CLASS_NONE = 0x1,
		eFIGHTING_CLASS_NON_COMBATANT = 0x2,
		eFIGHTING_CLASS_STRIKER = 0x3,
		eFIGHTING_CLASS_STRIKER_QUICK = 0x4,
		eFIGHTING_CLASS_STRIKER_BRAWLER = 0x5,
		eFIGHTING_CLASS_GRAPPLER = 0x6,
		eFIGHTING_CLASS_TUTORIAL = 0x7,
		eFIGHTING_CLASS_ENFORCER = 0x8,
		eFIGHTING_CLASS_ELITE = 0x9,
		NUM_FIGHTING_CLASSES = 0xA,
	};

	enum eGenderEnum
	{
		eGENDER_INVALID = 0x0,
		eGENDER_MALE = 0x1,
		eGENDER_FEMALE = 0x2,
		NUM_GENDERS = 0x3,
	};

	enum eInventoryItemEnum
	{
		eINVENTORY_ITEM_INVALID = 0x0,
		eINVENTORY_ITEM_EMPTY_POP_CAN = 0x1,
		eINVENTORY_ITEM_BOTTLED_SODA = 0x2,
		eINVENTORY_ITEM_EMPTY_BEER_BOTTLE = 0x3,
		eINVENTORY_ITEM_BATON = 0x4,
		eINVENTORY_ITEM_POLICE_BATON = 0x5,
		eINVENTORY_ITEM_PICKET_SIGN = 0x6,
		eINVENTORY_ITEM_BROOM_FULL = 0x7,
		eINVENTORY_ITEM_CLEAVER = 0x8,
		eINVENTORY_ITEM_KNIFE = 0x9,
		eINVENTORY_ITEM_STORM_SWORD = 0xA,
		eINVENTORY_ITEM_PEACHWOOD_SWORD = 0xB,
		eINVENTORY_ITEM_BROOM_PUSH = 0xC,
		eINVENTORY_ITEM_PARKINGCOMPUTER = 0xD,
		eINVENTORY_ITEM_UMBRELLA = 0xE,
		eINVENTORY_ITEM_LIONHEAD = 0xF,
		eINVENTORY_ITEM_NEWSPAPER = 0x10,
		eINVENTORY_ITEM_SHOPPING_BAG = 0x11,
		eINVENTORY_ITEM_PORK_BUN = 0x12,
		eINVENTORY_ITEM_FOODONSTICK_A = 0x13,
		eINVENTORY_ITEM_FOODONSTICK_B = 0x14,
		eINVENTORY_ITEM_NOODLE_BOWL = 0x15,
		eINVENTORY_ITEM_NOODLE_BOX = 0x16,
		eINVENTORY_ITEM_FISH_BALLS = 0x17,
		eINVENTORY_ITEM_SPICY_SQUID = 0x18,
		eINVENTORY_ITEM_DIM_SUM = 0x19,
		eINVENTORY_ITEM_ICE_CREAM = 0x1A,
		eINVENTORY_ITEM_ENERGY_DRINK = 0x1B,
		eINVENTORY_ITEM_HAPPY_ENDING = 0x1C,
		eINVENTORY_ITEM_HAPPY_ENDING_2 = 0x1D,
		eINVENTORY_ITEM_HAPPY_ENDING_3 = 0x1E,
		eINVENTORY_ITEM_HERBAL_TEA = 0x1F,
		eINVENTORY_ITEM_PISTOL_9MM = 0x20,
		eINVENTORY_ITEM_PISTOL_9MM_AMMO = 0x21,
		eINVENTORY_ITEM_PISTOL_SERVICE = 0x22,
		eINVENTORY_ITEM_PISTOL_SERVICE_AMMO = 0x23,
		eINVENTORY_ITEM_PISTOL_45CAL = 0x24,
		eINVENTORY_ITEM_PISTOL_45CAL_TAC = 0x25,
		eINVENTORY_ITEM_PISTOL_45CAL_AMMO = 0x26,
		eINVENTORY_ITEM_PISTOL_HITMAN = 0x27,
		eINVENTORY_ITEM_PISTOL_JUST_CAUSE = 0x28,
		eINVENTORY_ITEM_RIFLE_ASSAUL_TAC = 0x29,
		eINVENTORY_ITEM_RIFLE_ASSAULT = 0x2A,
		eINVENTORY_ITEM_RIFLE_ASSAULT_DLC = 0x2B,
		eINVENTORY_ITEM_RIFLE_ASSAULT_AMMO = 0x2C,
		eINVENTORY_ITEM_RIFLE_DEUS_EX = 0x2D,
		eINVENTORY_ITEM_RIFLE_GRENADE = 0x2E,
		eINVENTORY_ITEM_RIFLE_GRENADE_AMMO = 0x2F,
		eINVENTORY_ITEM_RIFLE_GRENADE_AMMO_GRENADE = 0x30,
		eINVENTORY_ITEM_RIFLE_TEAR_GAS = 0x31,
		eINVENTORY_ITEM_SHOTGUN_PUMP = 0x32,
		eINVENTORY_ITEM_SHOTGUN_PUMP_AMMO = 0x33,
		eINVENTORY_ITEM_SHOTGUN_ANTI_TAC = 0x34,
		eINVENTORY_ITEM_SHOTGUN_ANTIRIOT = 0x35,
		eINVENTORY_ITEM_SHOTGUN_ANTIRIOT_AMMO = 0x36,
		eINVENTORY_ITEM_SMG_MACHINE_PISTOL = 0x37,
		eINVENTORY_ITEM_SMG_MACHINE_PISTOL_AMMO = 0x38,
		eINVENTORY_ITEM_SMG_45CAL_TACLIG = 0x39,
		eINVENTORY_ITEM_SMG_45CAL_GOLD = 0x3A,
		eINVENTORY_ITEM_SMG_45CAL = 0x3B,
		eINVENTORY_ITEM_SMG_45CAL_AMMO = 0x3C,
		eINVENTORY_ITEM_ELECTRO_SHOCK = 0x3D,
		eINVENTORY_ITEM_CAR_TURRET = 0x3E,
		eINVENTORY_ITEM_MONKEY_KING_STAFF = 0x3F,
		eINVENTORY_ITEM_TEAPOT = 0x40,
		eINVENTORY_ITEM_CROWBAR = 0x41,
		eINVENTORY_ITEM_TIREIRON = 0x42,
		eINVENTORY_ITEM_WOODENCLUB = 0x43,
		eINVENTORY_ITEM_MONEY = 0x44,
		eINVENTORY_ITEM_DRUG_PACKET = 0x45,
		eINVENTORY_ITEM_GROCERYBAG = 0x46,
		eINVENTORY_ITEM_CONTACTCARD = 0x47,
		eINVENTORY_ITEM_GAMEGUITAR = 0x48,
		eINVENTORY_ITEM_SHOVEL = 0x49,
		eINVENTORY_ITEM_DEED_AB_01 = 0x4A,
		eINVENTORY_ITEM_DEED_KT_01 = 0x4B,
		eINVENTORY_ITEM_DEED_CN_01 = 0x4C,
		eINVENTORY_ITEM_PURSE = 0x4D,
		eINVENTORY_ITEM_PURSEHAND = 0x4E,
		eINVENTORY_ITEM_BRIEFCASE = 0x4F,
		eINVENTORY_ITEM_BRIBE_CHEAP = 0x50,
		eINVENTORY_ITEM_BRIBE_AVERAGE = 0x51,
		eINVENTORY_ITEM_BRIBE_EXPENSIVE = 0x52,
		eINVENTORY_ITEM_COCKTAIL = 0x53,
		eINVENTORY_ITEM_TAXI_RIDE = 0x54,
		eINVENTORY_ITEM_M_DEER_ANTLERS = 0x55,
		eINVENTORY_ITEM_M_PIT_VIPER = 0x56,
		eINVENTORY_ITEM_M_DBP = 0x57,
		eINVENTORY_ITEM_M_SHIRT = 0x58,
		eINVENTORY_ITEM_M_GOWN = 0x59,
		eINVENTORY_ITEM_M_NECKLACE = 0x5A,
		eINVENTORY_ITEM_M_PURSE = 0x5B,
		eINVENTORY_ITEM_M_PURSEHAND = 0x5C,
		eINVENTORY_ITEM_M_DRUGS_ILLEGAL = 0x5D,
		eINVENTORY_ITEM_M_DRUGS_PRESC = 0x5E,
		eINVENTORY_ITEM_M_BEER = 0x5F,
		eINVENTORY_ITEM_M_VIRILITY = 0x60,
		eINVENTORY_ITEM_M_APT_CENTRAL = 0x61,
		eINVENTORY_ITEM_M_APT_ABERDEEN = 0x62,
		eINVENTORY_ITEM_M_APT_KENNEDY = 0x63,
		eINVENTORY_ITEM_M_CAMBRIA_WATCH = 0x64,
		eINVENTORY_ITEM_EXTORT_CHEAP = 0x65,
		eINVENTORY_ITEM_EXTORT_AVERAGE = 0x66,
		eINVENTORY_ITEM_EXTORT_EXPENSIVE = 0x67,
		eINVENTORY_ITEM_HIJACKED_VEHICLE = 0x68,
		eINVENTORY_ITEM_RAGWIPING = 0x69,
		eINVENTORY_ITEM_CAMERA = 0x6A,
		eINVENTORY_ITEM_CIGARETTE = 0x6B,
		eINVENTORY_ITEM_CLIPBOARD = 0x6C,
		eINVENTORY_ITEM_LOCKTOOL = 0x6D,
		eINVENTORY_ITEM_HAT = 0x6E,
		eINVENTORY_ITEM_HELMET = 0x6F,
		eINVENTORY_ITEM_GLASSES = 0x70,
		eINVENTORY_ITEM_PAINTCAN = 0x71,
		eINVENTORY_ITEM_HAMMER = 0x72,
		eINVENTORY_ITEM_WINEBOTTLE = 0x73,
		eINVENTORY_ITEM_INCENSE = 0x74,
		eINVENTORY_ITEM_FLOWERS = 0x75,
		eINVENTORY_ITEM_BROCHURE = 0x76,
		eINVENTORY_ITEM_BROCHURESTACK = 0x77,
		eINVENTORY_ITEM_RAKE = 0x78,
		eINVENTORY_ITEM_CANEWALKING = 0x79,
		eINVENTORY_ITEM_SCRUBBRUSH = 0x7A,
		eINVENTORY_ITEM_SQUEEGEE = 0x7B,
		eINVENTORY_ITEM_STICKTREE = 0x7C,
		eINVENTORY_ITEM_STICKBAMBOO = 0x7D,
		eINVENTORY_ITEM_DRINKINGGLASS = 0x7E,
		eINVENTORY_ITEM_BIGHAT = 0x7F,
		eINVENTORY_ITEM_SUNGLASSES = 0x80,
		eINVENTORY_ITEM_HEADSETBOUNCER = 0x81,
		eINVENTORY_ITEM_BAR_BILL = 0x82,
		eINVENTORY_ITEM_FERRY_TICKET = 0x83,
		eINVENTORY_ITEM_TRANSIT_TICKET = 0x84,
		eINVENTORY_ITEM_COOKINGPAN = 0x85,
		eINVENTORY_ITEM_COOKINGPOT = 0x86,
		eINVENTORY_ITEM_WRENCH = 0x87,
		eINVENTORY_ITEM_BET_LOW = 0x88,
		eINVENTORY_ITEM_BET_STANDARD = 0x89,
		eINVENTORY_ITEM_BET_HIGH = 0x8A,
		eINVENTORY_ITEM_BROOMWEAPON = 0x8B,
		eINVENTORY_ITEM_BOX = 0x8C,
		eINVENTORY_ITEM_FISH_BOX = 0x8D,
		eINVENTORY_ITEM_FRUIT_BOX = 0x8E,
		eINVENTORY_ITEM_FLIERS = 0x8F,
		eINVENTORY_ITEM_MACHETETONG = 0x90,
		eINVENTORY_ITEM_CELLPHONE = 0x91,
		eINVENTORY_ITEM_COOKINGSPOON = 0x92,
		eINVENTORY_ITEM_COOKINGWOK = 0x93,
		eINVENTORY_ITEM_BULLPENIS = 0x94,
		eINVENTORY_ITEM_HANDGRINDER = 0x95,
		eINVENTORY_ITEM_PARAMEDICBAG = 0x96,
		eINVENTORY_ITEM_FISHWRAPPED = 0x97,
		eINVENTORY_ITEM_MEATWRAPPED = 0x98,
		eINVENTORY_ITEM_CYMBAL = 0x99,
		eINVENTORY_ITEM_FIREEXTINGUISHER = 0x9A,
		eINVENTORY_ITEM_PISTOL_50CAL_GOL = 0x9B,
		eINVENTORY_ITEM_PISTOL_50CAL_SIL = 0x9C,
		eINVENTORY_ITEM_PISTOL_50CAL_AMMO = 0x9D,
		eINVENTORY_ITEM_PUNCHINGPAD_L = 0x9E,
		eINVENTORY_ITEM_PUNCHINGPAD_R = 0x9F,
		eINVENTORY_ITEM_DUFFLEBAG = 0xA0,
		eINVENTORY_ITEM_GARBAGEBAG = 0xA1,
		eINVENTORY_ITEM_FISHTUNA = 0xA2,
		eINVENTORY_ITEM_NP_SAFEHOUSEITEM_01 = 0xA3,
		eINVENTORY_ITEM_NP_SAFEHOUSEITEM_02 = 0xA4,
		eINVENTORY_ITEM_NP_SAFEHOUSEITEM_03 = 0xA5,
		eINVENTORY_ITEM_NP_SAFEHOUSEITEM_04 = 0xA6,
		eINVENTORY_ITEM_NP_SAFEHOUSEITEM_05 = 0xA7,
		eINVENTORY_ITEM_CN_SAFEHOUSEITEM_01 = 0xA8,
		eINVENTORY_ITEM_CN_SAFEHOUSEITEM_02 = 0xA9,
		eINVENTORY_ITEM_CN_SAFEHOUSEITEM_03 = 0xAA,
		eINVENTORY_ITEM_CN_SAFEHOUSEITEM_04 = 0xAB,
		eINVENTORY_ITEM_CN_SAFEHOUSEITEM_05 = 0xAC,
		eINVENTORY_ITEM_AB_SAFEHOUSEITEM_01 = 0xAD,
		eINVENTORY_ITEM_AB_SAFEHOUSEITEM_02 = 0xAE,
		eINVENTORY_ITEM_AB_SAFEHOUSEITEM_03 = 0xAF,
		eINVENTORY_ITEM_AB_SAFEHOUSEITEM_04 = 0xB0,
		eINVENTORY_ITEM_AB_SAFEHOUSEITEM_05 = 0xB1,
		eINVENTORY_ITEM_KT_SAFEHOUSEITEM_01 = 0xB2,
		eINVENTORY_ITEM_KT_SAFEHOUSEITEM_02 = 0xB3,
		eINVENTORY_ITEM_KT_SAFEHOUSEITEM_03 = 0xB4,
		eINVENTORY_ITEM_KT_SAFEHOUSEITEM_04 = 0xB5,
		eINVENTORY_ITEM_KT_SAFEHOUSEITEM_05 = 0xB6,
		eINVENTORY_ITEM_PACKAGE_PAPER = 0xB7,
		eINVENTORY_ITEM_DLC_01 = 0xB8,
		eINVENTORY_ITEM_DLC_02 = 0xB9,
		eINVENTORY_ITEM_DLC_03 = 0xBA,
		eINVENTORY_ITEM_DLC_04 = 0xBB,
		eINVENTORY_ITEM_DLC_05 = 0xBC,
		eINVENTORY_ITEM_DLC_06 = 0xBD,
		eINVENTORY_ITEM_DLC_07 = 0xBE,
		eINVENTORY_ITEM_DLC_08 = 0xBF,
		eINVENTORY_ITEM_DLC_09 = 0xC0,
		eINVENTORY_ITEM_DLC_10 = 0xC1,
		eINVENTORY_ITEM_DLC_11 = 0xC2,
		eINVENTORY_ITEM_DLC_12 = 0xC3,
		eINVENTORY_ITEM_DLC_13 = 0xC4,
		eINVENTORY_ITEM_DLC_14 = 0xC5,
		eINVENTORY_ITEM_DLC_15 = 0xC6,
		eINVENTORY_ITEM_DLC_16 = 0xC7,
		eINVENTORY_ITEM_DLC_17 = 0xC8,
		eINVENTORY_ITEM_DLC_18 = 0xC9,
		eINVENTORY_ITEM_DLC_19 = 0xCA,
		eINVENTORY_ITEM_DLC_20 = 0xCB,
		eINVENTORY_ITEM_DLC_21 = 0xCC,
		eINVENTORY_ITEM_DLC_22 = 0xCD,
		eINVENTORY_ITEM_DLC_23 = 0xCE,
		eINVENTORY_ITEM_DLC_24 = 0xCF,
		eINVENTORY_ITEM_DLC_25 = 0xD0,
		NUM_INVENTORY_ITEMS = 0xD1,
	};

	enum eSimObjectTypeEnum
	{
		eSIM_OBJ_TYPE_INVALID = 0x0,
		eSIM_OBJ_TYPE_CHARACTER = 0x1,
		eSIM_OBJ_TYPE_PICKUP = 0x2,
		eSIM_OBJ_TYPE_WEAPON = 0x3,
		eSIM_OBJ_TYPE_VEHICLE = 0x4,
		eSIM_OBJ_TYPE_INTERACTIVE_PROP = 0x5,
		NUM_SIM_OBJECT_TYPES = 0x6,
	};

	enum eSimObjectVehicleTypeEnum
	{
		eSIM_OBJ_VEHICLE_TYPE_INVALID = 0x0,
		eSIM_OBJ_VEHICLE_TYPE_BIKE = 0x1,
		eSIM_OBJ_VEHICLE_TYPE_CAR = 0x2,
		eSIM_OBJ_VEHICLE_TYPE_BOAT = 0x3,
		eSIM_OBJ_VEHICLE_TYPE_VAN = 0x4,
		eSIM_OBJ_VEHICLE_TYPE_TRUCK = 0x5,
		eSIM_OBJ_VEHICLE_TYPE_SCOOTER = 0x6,
		eSIM_OBJ_VEHICLE_TYPE_MINIBUS = 0x7,
		eSIM_OBJ_VEHICLE_TYPE_DDBUS = 0x8,
		eSIM_OBJ_VEHICLE_TYPE_TRAM = 0x9,
		NUM_SIM_OBJECT_VEHICLE_TYPES = 0xA,
	};

	enum eSimObjectBoatTypeEnum
	{
		eSIM_OBJ_BOAT_TYPE_INVALID = 0x0,
		eSIM_OBJ_BOAT_TYPE_COMMERCIAL_BOAT = 0x1,
		eSIM_OBJ_BOAT_TYPE_FERRY = 0x2,
		eSIM_OBJ_BOAT_TYPE_JET_BOAT = 0x3,
		eSIM_OBJ_BOAT_TYPE_SAMPAN = 0x4,
		eSIM_OBJ_BOAT_TYPE_YACHT = 0x5,
		eSIM_OBJ_BOAT_TYPE_ZODIAC = 0x6,
		NUM_SIM_OBJECT_BOAT_TYPES = 0x7,
	};

	enum eTargetTypeEnum
	{
		eTARGET_TYPE_INVALID = 0x0,
		eTARGET_TYPE_SELF = 0x1,
		eTARGET_TYPE_ATTACKER = 0x2,
		eTARGET_TYPE_AIM_POSITION = 0x3,
		eTARGET_TYPE_VEHICLE_DRIVER = 0x4,
		eTARGET_TYPE_VEHICLE_PASSENGER = 0x5,
		eTARGET_TYPE_VEHICLE_PASSENGER2 = 0x6,
		eTARGET_TYPE_VEHICLE_PASSENGER3 = 0x7,
		eTARGET_TYPE_VEHICLE_PASSENGER4 = 0x8,
		eTARGET_TYPE_VEHICLE_ROLE_SWAP_TEMP = 0x9,
		eTARGET_TYPE_VEHICLE_CARGO1 = 0xA,
		eTARGET_TYPE_VEHICLE_CARGO2 = 0xB,
		eTARGET_TYPE_VEHICLE_CARGO3 = 0xC,
		eTARGET_TYPE_VEHICLE_PASSENGER_TRUNK = 0xD,
		eTARGET_TYPE_CLOSEST_PED = 0xE,
		eTARGET_TYPE_COVER_OBJECT = 0xF,
		eTARGET_TYPE_COVER_POPOUT = 0x10,
		eTARGET_TYPE_EQUIPPED = 0x11,
		eTARGET_TYPE_EQUIPPED_LEFT_HAND = 0x12,
		eTARGET_TYPE_EQUIPPED_HAT = 0x13,
		eTARGET_TYPE_EQUIPPED_GLASSES = 0x14,
		eTARGET_TYPE_FACING = 0x15,
		eTARGET_TYPE_FOCUS = 0x16,
		eTARGET_TYPE_GRAPPLE = 0x17,
		eTARGET_TYPE_LOOK_AT = 0x18,
		eTARGET_TYPE_POI_LOOK_AT = 0x19,
		eTARGET_TYPE_POI_USE = 0x1A,
		eTARGET_TYPE_POI_PARENT_OBJECT = 0x1B,
		eTARGET_TYPE_VEHICLE = 0x1C,
		eTARGET_TYPE_AI_OBJECTIVE = 0x1D,
		eTARGET_TYPE_TO_FOLLOW = 0x1E,
		eTARGET_TYPE_PLAYER = 0x1F,
		eTARGET_TYPE_SCRIPTED_MARKER = 0x20,
		eTARGET_TYPE_STIMULUS_PRODUCER = 0x21,
		eTARGET_TYPE_CONDITION_STIMULUS_PRODUCER = 0x22,
		eTARGET_TYPE_IGNORE_AVOIDANCE = 0x23,
		eTARGET_TYPE_LAST_THREAT = 0x24,
		eTARGET_TYPE_POINT_AT = 0x25,
		eTARGET_TYPE_ATTACKING = 0x26,
		eTARGET_TYPE_CONVERSATION = 0x27,
		eTARGET_TYPE_INTERACTIVE_PROP = 0x28,
		eTARGET_TYPE_PICKUP_ITEM = 0x29,
		eTARGET_TYPE_STOWED_WEAPON = 0x2A,
		eTARGET_TYPE_STOWED_2H_WEAPON = 0x2B,
		eTARGET_TYPE_VEHICLE_ACTION_HIJACK = 0x2C,
		eTARGET_TYPE_VEHICLE_ACTION_HIJACK_POTENTIAL = 0x2D,
		eTARGET_TYPE_VEHICLE_CLOSEST_POINT = 0x2E,
		eTARGET_TYPE_CLOSEST_DOWNED_PED = 0x2F,
		eTARGET_TYPE_DIRECTIONAL = 0x30,
		eTARGET_TYPE_PHYSICAL = 0x31,
		eTARGET_TYPE_SOCIAL = 0x32,
		eTARGET_TYPE_CROWD_PUSH_PRIMARY = 0x33,
		eTARGET_TYPE_CROWD_PUSH_SECONDARY = 0x34,
		eTARGET_TYPE_ESCORT = 0x35,
		eTARGET_TYPE_OWNER = 0x36,
		eTARGET_TYPE_LAST_CREATED_OBJECT = 0x37,
		eTARGET_TYPE_SUBTARGET = 0x38,
		eTARGET_TYPE_TRANSIT = 0x39,
		eTARGET_TYPE_WORLD_EDITOR_SELECTED_OBJECT = 0x3A,
		eTARGET_TYPE_CRANE_CONTAINER_ATTACHED = 0x3B,
		eTARGET_TYPE_CRANE_CONTAINER_UNATTACHED = 0x3C,
		eTARGET_TYPE_MY_SPAWN_POINT = 0x3D,
		eTARGET_TYPE_GROUP_LEADER = 0x3E,
		eTARGET_TYPE_GROUP_MEMBER = 0x3F,
		eTARGET_TYPE_GROUP_MEMBER2 = 0x40,
		eTARGET_TYPE_GROUP_MEMBER3 = 0x41,
		eTARGET_TYPE_GROUP_MEMBER4 = 0x42,
		eTARGET_TYPE_GROUP_MEMBER_PAIRED = 0x43,
		eTARGET_TYPE_BEST_INTERACTION_POINT = 0x44,
		eTARGET_TYPE_INTERACTION_POINT0 = 0x45,
		eTARGET_TYPE_INTERACTION_POINT1 = 0x46,
		eTARGET_TYPE_INTERACTION_POINT2 = 0x47,
		eTARGET_TYPE_INTERACTION_POINT3 = 0x48,
		eTARGET_TYPE_INTERACTION_POINT4 = 0x49,
		eTARGET_TYPE_INTERACTION_POINT5 = 0x4A,
		eTARGET_TYPE_HIJACKABLE_VEHICLE = 0x4B,
		eTARGET_TYPE_SYNC = 0x4C,
		eTARGET_TYPE_BEST_MELEE_ATTACKER = 0x4D,
		eTARGET_TYPE_LAST_ATTACKED = 0x4E,
		eTARGET_TYPE_INTERACTION_OFFSET = 0x4F,
		eTARGET_TYPE_TRANSACTION = 0x50,
		eTARGET_TYPE_LAST_GRAPPLE = 0x51,
		eTARGET_TYPE_PROBE_LOW_L = 0x52,
		eTARGET_TYPE_PROBE_LOW_C = 0x53,
		eTARGET_TYPE_PROBE_LOW_R = 0x54,
		eTARGET_TYPE_PROBE_MID_L = 0x55,
		eTARGET_TYPE_PROBE_MID_C = 0x56,
		eTARGET_TYPE_PROBE_MID_R = 0x57,
		eTARGET_TYPE_PROBE_HIGH_L = 0x58,
		eTARGET_TYPE_PROBE_HIGH_C = 0x59,
		eTARGET_TYPE_PROBE_HIGH_R = 0x5A,
		NUM_TARGET_TYPES = 0x5B,
	};

	enum VehicleEffectId
	{
		FX_NIGHTTIME = 0x0,
		FX_DAYTIME = 0x1,
		FX_PLAYERHEADLIGHTS = 0x2,
		FX_TRAFFICHEADLIGHTS = 0x3,
		FX_PLAYERHEADLIGHTFLARES = 0x4,
		FX_TRAFFICHEADLIGHTFLARES = 0x5,
		FX_BRAKELIGHTS = 0x6,
		FX_COPHEADLIGHTS = 0x7,
		FX_EXHAUST_CLEAN = 0x8,
		FX_EXHAUST_DIRTY = 0x9,
		FX_AIEXHAUST_CLEAN = 0xA,
		FX_AIEXHAUST_DIRTY = 0xB,
		FX_AILOWLODEXHAUST = 0xC,
		FX_REVERSE = 0xD,
		FX_LEFTTURN = 0xE,
		FX_RIGHTTURN = 0xF,
		FX_INTERIORLIGHTS = 0x10,
		FX_TAXILIGHTS = 0x11,
		FX_DISABLED = 0x12,
		FX_ENGINEDAMAGE = 0x13,
		FX_ENGINEBLOWN = 0x14,
		FX_DESTROYEDVEHICLE = 0x15,
		FX_SMOLDERING = 0x16,
		FX_DRAGGING = 0x17,
		FX_ROOFSLIDING = 0x18,
		FX_DESTRUCTFRONT = 0x19,
		FX_DESTRUCTMID = 0x1A,
		FX_DESTRUCTREAR = 0x1B,
		FX_DAMAGE = 0x1C,
		FX_WINDOWSHATTER = 0x1D,
		FX_WINDOWBREAKSM = 0x1E,
		FX_WINDOWBREAKMD = 0x1F,
		FX_WINDOWBREAKLG = 0x20,
		FX_SPRAY = 0x21,
		FX_AISPRAY = 0x22,
		FX_ENTERWATER = 0x23,
		FX_EXITWATER = 0x24,
		FX_WHEELEDVEHICLEJUMP = 0x25,
		FX_WHEELEDVEHICLEIMPACT = 0x26,
		EFFECT_TABLE_SIZE = 0x27,
	};

	enum eVehicleTrunkTypeEnum
	{
		eVEHICLE_TRUNK_TYPE_NONE = 0x0,
		eVEHICLE_TRUNK_TYPE_CAR_NARROW = 0x1,
		eVEHICLE_TRUNK_TYPE_CAR_STANDARD = 0x2,
		eVEHICLE_TRUNK_TYPE_CAR_WIDE = 0x3,
		eVEHICLE_TRUNK_TYPE_CAR_WIDER = 0x4,
		eVEHICLE_TRUNK_TYPE_VAN_STANDARD = 0x5,
		eVEHICLE_TRUNK_TYPE_VAN_WIDE = 0x6,
		eVEHICLE_TRUNK_TYPE_VAN_WIDER = 0x7,
		eVEHICLE_TRUNK_TYPE_VAN_NARROW = 0x8,
		NUM_VEHICLE_TRUNK_TYPES = 0x9,
	};
}
#pragma once

namespace UFG
{
	class StoreFront : public SpawnInfoInterface
	{
	public:
		enum EquipItemFlags
		{
			eNone,
			eSaveChanges,
			eRefreshCharacter
		};

		enum InventoryType : i32
		{
			InventoryType_None = 0,
			InventoryType_Clothing = 61,
			InventoryType_Vehicle,
			InventoryType_Boat
		};

		enum ItemBrand
		{
			ItemBrand_Achete,
			ItemBrand_Aspirazone,
			ItemBrand_BeautifulCorpse,
			ItemBrand_Brisk,
			ItemBrand_Cambria,
			ItemBrand_Couronne,
			ItemBrand_Jiggle,
			ItemBrand_Ikoze,
			ItemBrand_ChangTsui,
			Num_ItemBrands
		};

		enum ItemCategory : i32
		{
			ItemCategory_BODY,
			ItemCategory_LOWER_BODY,
			ItemCategory_FOOTWEAR,
			ItemCategory_HEADGEAR,
			ItemCategory_HEAD,
			ItemCategory_ACCESSORIES,
			ItemCategory_GLASSES,
			ItemCategory_NECK,
			ItemCategory_LEFTWRIST,
			ItemCategory_RIGHTWRIST,
			ItemCategory_OUTFIT,
			ItemCategory_CUSTOM_OUTFIT,
			ItemCategory_VEHICLE,
			ItemCategory_BOAT,
			Num_ItemCategories
		};

		enum OutfitNum
		{
			Outfit_1,
			Outfit_2,
			Outfit_3,
			Outfit_4,
			Outfit_5,
			Num_Outfits
		};

		enum StoreType : i32
		{
			StoreType_None,
			StoreType_Retail,
			StoreType_Storage,
			StoreType_Race
		};

		struct EquippedItemResolution
		{
			bool mIsExcluded;
			bool mSetCurrentStat;
			qPropertySet* mItem;
			qPropertySet* mDefaultItem;
			qPropertySet* mExcludedBy[16];
			u32 mExcludedByCount;
		};

		struct RestoreData
		{
			StoreType mStoreType;
			InventoryType mInventoryType;
			qPropertySet* mpStoreParameters;
			qPropertySet* mpPropertySet;
		};

		struct StoreItem : qNode<StoreItem>
		{
			u16 m_iIndex;
			bool m_bRetail;
			u16 m_iItemCategory;
		};

		qPropertySet* mpStoreParameters;
		qPropertySet* mpPropertySet;
		SimObject* mpStoreOwner;
		StoreType mStoreType;
		qSymbol mStoreName;
		InventoryType mInventoryType;
		ItemCategory mCategoryFilter;
		SimObject* mCameraMarker;
		qString mCategoryHeading;
		qString mStoreTitle;
		qString mStoreDesc;
		qSymbol mItemTypeFilter;
		qString mItemTierFilter;
		u32 mCategoryCount[15];
		qList<StoreItem> m_Items;

		/* Static Functions */

		SDK_SINLINE StoreFront* Instance() { return SDK_VAR(StoreFront*, 0x2408290); }
		SDK_SINLINE void CheckAchievement() { SDK_CALL_FUNC(void, 0x496B60)(); }
		SDK_SINLINE bool EquipCustomOutfit(OutfitNum a_eOutfitNum, bool bSaveToStats, bool bUpdateLastEquipItem) {
			return SDK_CALL_FUNC(bool, 0x49E350, OutfitNum, bool, bool)(a_eOutfitNum, bSaveToStats, bUpdateLastEquipItem);
		}
		SDK_SINLINE void EquipItem(qPropertySet* pItem, bool bSaveToStats, bool bRefreshPlayer, bool bRemoveAnyPredefinedOutfit, bool bUpdateLastEquipItem, bool bPreviewing) {
			SDK_CALL_FUNC(void, 0x49E860, qPropertySet*, bool, bool, bool, bool, bool)(pItem, bSaveToStats, bRefreshPlayer, bRemoveAnyPredefinedOutfit, bUpdateLastEquipItem, bPreviewing); 
		}
		SDK_SINLINE const char* GetCategoryHeading(int category) { return SDK_CALL_FUNC(const char*, 0x4A1EF0, void*, int)(0, category); }
		SDK_SINLINE qSymbol GetClothingBuffFromItem(qPropertySet* pItem) { return SDK_CALL_FUNC(qSymbol, 0x4A1F60, void*, qPropertySet*)(0, pItem); }
		SDK_SINLINE qSymbol GetItemBuffFromItem(qPropertySet* pItem) { return SDK_CALL_FUNC(qSymbol, 0x4A42D0, void*, qPropertySet*)(0, pItem); }
		SDK_SINLINE bool IsWeiWearingAnPrefinedOutfit() { return SDK_CALL_FUNC(bool, 0x4AD160)(); }
		SDK_SINLINE eClothingBuffEnum LookupClothingBuff(const qSymbol& sym) { return SDK_CALL_FUNC(eClothingBuffEnum, 0x4B0BB0, const qSymbol&)(sym); }
		SDK_SINLINE qSymbol LookupClothingBuffSymbol(eClothingBuffEnum eBuff) { return SDK_CALL_FUNC(qSymbol, 0x4B0BE0, eClothingBuffEnum)(eBuff); }
		SDK_SINLINE ItemCategory MapItemCategory(const qSymbol& itemCategory) { return SDK_CALL_FUNC(ItemCategory, 0x4B0C00, const qSymbol&)(itemCategory); }
		SDK_SINLINE void PreviewRemoveCustomOutfit() { SDK_CALL_FUNC(void, 0x4B2460)(); }
		SDK_SINLINE void ProcessClothingSetBonuses(GameStat::IDStat equipmentType) { SDK_CALL_FUNC(void, 0x4B2610, GameStat::IDStat)(equipmentType); }
		SDK_SINLINE void SetClothingSetBuff(eClothingBuffEnum buffType) { SDK_CALL_FUNC(void, 0x4BBCD0, eClothingBuffEnum)(buffType); }
		SDK_SINLINE u32 ValidateCustomOutfitItem(u32 itemId, const qSymbol& defaultSymbol) { return SDK_CALL_FUNC(u32, 0x4C8E10, u32, const qSymbol&)(itemId, defaultSymbol); }

		/* Impl Functions */

		SDK_INLINE int GetItemCount(ItemCategory category) { return mCategoryCount[category]; }

		/* Functions */

		void AddItemToStore(qPropertySet* pItemPropertySet, int iIndex, bool bRetail) { SDK_CALL_FUNC(void, 0x4930D0, void*, qPropertySet*, int, bool)(this, pItemPropertySet, iIndex, bRetail); }
		void BuildCategories() { SDK_CALL_FUNC(void, 0x4959F0, void*)(this); }
		bool CanPurchase(int filterIndex) { return SDK_CALL_FUNC(bool, 0x496890, void*, int)(this, filterIndex); }
		void ClosePreviewShutter() { SDK_CALL_FUNC(void, 0x498720, void*)(this); }
		bool FindItemIndex(const qSymbol& spawnInfo, u32& itemIndexOut) { return SDK_CALL_FUNC(bool, 0x4A05D0, void*, const qSymbol&, u32&)(this, spawnInfo, itemIndexOut); }
		SimObject* GetCameraMarker() { return SDK_CALL_FUNC(SimObject*, 0x4A1CD0, void*)(this); }
		qPropertySet* GetItem(int filterIndex) { return SDK_CALL_FUNC(qPropertySet*, 0x4A41F0, void*, int)(this, filterIndex); }
		u32 GetNumItems() { return SDK_CALL_FUNC(u32, 0x4A58F0, void*)(this); }
		u32 GetNumStorageItems() { return SDK_CALL_FUNC(u32, 0x4A59E0, void*)(this); }
		SimObject* GetPlayerExitMarker() { return SDK_CALL_FUNC(SimObject*, 0x4A5E20, void*)(this); }
		SimObject* GetPlayerMarker() { return SDK_CALL_FUNC(SimObject*, 0x4A5E70, void*)(this); }
		qPropertySet* GetStorageItem(int index) { return SDK_CALL_FUNC(qPropertySet*, 0x4A6950, void*, int)(this, index); }
		bool IsClothingSetItemOwned(ItemCategory eItemSearchCategory, const qSymbol& itemClothingSet) { 
			return SDK_CALL_FUNC(bool, 0x4ABBD0, void*, ItemCategory, const qSymbol&)(this, eItemSearchCategory, itemClothingSet);
		}
		bool IsOwned(qPropertySet* pItem) { return SDK_CALL_FUNC(bool, 0x4ACAF0, void*, qPropertySet*)(this, pItem); }
		bool IsOwned(int filterIndex) { return SDK_CALL_FUNC(bool, 0x4ACB80, void*, int)(this, filterIndex); }
		bool IsOwnedClothingCategoryEmpty(ItemCategory category) { return SDK_CALL_FUNC(bool, 0x4ACBA0, void*, ItemCategory)(this, category); }
		void OpenPreviewShutter() { SDK_CALL_FUNC(void, 0x4B1E30, void*)(this); }
		bool PurchaseItem(int filterIndex) { return SDK_CALL_FUNC(bool, 0x4B3750, void*, int)(this, filterIndex); }
		void ResolveItemEquip(qPropertySet* pItem, SimObject* pPlayer, StreamedResourceComponent* pSrc, qArray<EquippedItemResolution>& resolvedEquipment) { 
			SDK_CALL_FUNC(void, 0x4B7470, qPropertySet*, SimObject*, StreamedResourceComponent*, qArray<EquippedItemResolution>&)(pItem, pPlayer, pSrc, resolvedEquipment);
		}
		void SetCurrentCategory(ItemCategory category) { SDK_CALL_FUNC(void, 0x4BBE60, void*, ItemCategory)(this, category); }
		void SetData(StoreType storeType, InventoryType inventoryType, qPropertySet* pParameters, qPropertySet* pPropertySet) { 
			SDK_CALL_FUNC(void, 0x4BBFD0, void*, StoreType, InventoryType, qPropertySet*, qPropertySet*)(this, storeType, inventoryType, pParameters, pPropertySet); 
		}
		void SetNextCategory() { SDK_CALL_FUNC(void, 0x4BCEE0, void*)(this); }
		SimObject* SpawnItem(int filterIndex) { return SDK_CALL_FUNC(SimObject*, 0x4BECF0, void*, int)(this, filterIndex); }
		void UpdateCategoryHeading() { SDK_CALL_FUNC(void, 0x4C59C0, void*)(this); }
		qString GetStoreDesc() { return SDK_CALL_FUNC(qString, 0x5E9550, void*)(this); }
		qString GetStoreTitle() { return SDK_CALL_FUNC(qString, 0x5E9590, void*)(this); }
	};
	SDK_ASSERT_SIZEOF(StoreFront, 0x128);

	class StoreFrontTracker
	{
	public:
		PropertySetHandle mProperties;
		StoreFront mCurrentStore;
		StoreFront::InventoryType mInventoryType;
		int mClothingFashionValue[14];

		/* Static Functions */

		SDK_SINLINE StoreFrontTracker* Instance() { return SDK_VAR(StoreFrontTracker*, 0x2408280); }
		SDK_SINLINE f32 GetDiscount() { return SDK_CALL_FUNC(f32, 0x4A2390)(); }
		SDK_SINLINE f32 GetDiscountForFaceLevel() { return SDK_CALL_FUNC(f32, 0x4A25B0)(); }
		SDK_SINLINE f32 GetItemPriceBasedOnClothes(f32 fCurrentPrice) { return SDK_CALL_FUNC(f32, 0x4A4320, f32)(fCurrentPrice); }
		SDK_SINLINE f32 GetItemPriceBasedOnClothes(qPropertySet* pItemPropertySet) { return SDK_CALL_FUNC(f32, 0x4A4360, qPropertySet*)(pItemPropertySet); }
		SDK_SINLINE f32 GetItemPriceWithoutDiscount(qPropertySet* pItemPropertySet) { return SDK_CALL_FUNC(f32, 0x4A43C0, qPropertySet*)(pItemPropertySet); }

		/* Functions */

		void AddItemToInventory(qPropertySet* pItemPropertySet, StoreFront::InventoryType inventoryType, bool bApplyFace, bool bIsFree) {
			SDK_CALL_FUNC(void, 0x492EF0, void*, qPropertySet*, StoreFront::InventoryType, bool, bool)(this, pItemPropertySet, inventoryType, bApplyFace, bIsFree);
		}
		qPropertySet* FindClothingSetSlow(const qSymbol& clothingSetName) { return SDK_CALL_FUNC(qPropertySet*, 0x4A04B0, void*, const qSymbol&)(this, clothingSetName); }
		qPropertySet* FindItemSlow(const qSymbol& itemName) { return SDK_CALL_FUNC(qPropertySet*, 0x4A0690, void*, const qSymbol&)(this, itemName); }
		bool FindStore(qPropertySet* pStoreParameters, const qSymbol& storeName, StoreFront* pResult, StoreFront::StoreType eStoreType) {
			return SDK_CALL_FUNC(bool, 0x4A0810, void*, qPropertySet*, const qSymbol&, StoreFront*, StoreFront::StoreType)(this, pStoreParameters, storeName, pResult, eStoreType);
		}
		int GetClothingFashionValueTotal() { return SDK_CALL_FUNC(int, 0x4A1FA0, void*)(this); }
		void LoadMissionItem(const qSymbol& itemName, bool isPermanent) { SDK_CALL_FUNC(void, 0x4AEBD0, void*, const qSymbol&, bool)(this, itemName, isPermanent); }
		void LoadStoreData(const qSymbol& inventoryType) { SDK_CALL_FUNC(void, 0x4AEFF0, void*, const qSymbol&)(this, inventoryType); }
		void LoadStoreData(StoreFront::InventoryType inventoryType) { SDK_CALL_FUNC(void, 0x4AF140, void*, StoreFront::InventoryType)(this, inventoryType); }
		void ResetEquipment() { SDK_CALL_FUNC(void, 0x4B6A50, void*)(this); }
		void SetCurrentStore(qPropertySet* pStoreParameters) { SDK_CALL_FUNC(void, 0x4BBE70, void*, qPropertySet*)(this, pStoreParameters); }
		void SetCurrentStore(StoreFront::InventoryType inventorytype, const qSymbol& storeName, const char* pStoreTitle, const char* pStoreDesc) { 
			SDK_CALL_FUNC(void, 0x4BBF50, void*, StoreFront::InventoryType, const qSymbol&, const char*, const char*)(this, inventorytype, storeName, pStoreTitle, pStoreDesc);
		}
		void UnloadStoreData() { SDK_CALL_FUNC(void, 0x4C3EE0, void*)(this); }
	};

}
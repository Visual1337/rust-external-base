class ItemContainer
{
public:

	uintptr_t GetItemList()
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return NULL;

		return driver.read<uintptr_t>(reinterpret_cast<uintptr_t>(this) + Offsets::ItemContainer.ItemList);
	}
};

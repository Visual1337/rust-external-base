class PlayerInventory
{
public:
	ItemContainer* GetContainerMain()
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return NULL;

		return driver.read<ItemContainer*>(reinterpret_cast<uintptr_t>(this) + Offsets::PlayerInventory.ContainerMain);
	}

	ItemContainer* GetContainerBelt()
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return NULL;

		return driver.read<ItemContainer*>(reinterpret_cast<uintptr_t>(this) + Offsets::PlayerInventory.ContainerBelt);
	}

	ItemContainer* GetContainerWear()
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return NULL;

		return driver.read<ItemContainer*>(reinterpret_cast<uintptr_t>(this) + Offsets::PlayerInventory.ContainerWear);
	}
};
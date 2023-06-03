class Weapon
{
public:

	void SuperBow()
	{
		if (true)
		{
			driver.write<bool>(reinterpret_cast<uintptr_t>(this) + Offsets::BowWeapon.AttackReady, true);
			driver.write<float>(reinterpret_cast<uintptr_t>(this) + Offsets::BowWeapon.ArrowBack, 1.f);
		}
	}

	void NoRecoil()
	{
		if (global.no_recoil)
		{
			std::default_random_engine generator;
			std::uniform_real_distribution<float> distribution(-0.20f, -0.20f);
			float random_number = distribution(generator);

			uintptr_t recoil_properties = driver.read<uintptr_t>(reinterpret_cast<uintptr_t>(this) + Offsets::BaseProjectile.RecoilProperties);
			driver.write<float>(recoil_properties + Offsets::RecoilProperties.recoilYawMin, random_number);
			driver.write<float>(recoil_properties + Offsets::RecoilProperties.recoilYawMax, random_number);
			driver.write<float>(recoil_properties + Offsets::RecoilProperties.recoilPitchMin, random_number);
			driver.write<float>(recoil_properties + Offsets::RecoilProperties.recoilPitchMax, random_number);

			uintptr_t new_recoil_override = driver.read<uintptr_t>(recoil_properties + 0x78);
			driver.write<float>(new_recoil_override + Offsets::RecoilProperties.recoilYawMin, random_number);
			driver.write<float>(new_recoil_override + Offsets::RecoilProperties.recoilYawMax, random_number);
			driver.write<float>(new_recoil_override + Offsets::RecoilProperties.recoilPitchMin, random_number);
			driver.write<float>(new_recoil_override + Offsets::RecoilProperties.recoilPitchMax, random_number);
		}
	}

	void NoSpread()
	{
		if (global.no_spread)
		{
			std::default_random_engine generator;
			std::uniform_real_distribution<float> distribution(-0.5f, 0.5f);
			float random_number = distribution(generator);

			driver.write<float>(reinterpret_cast<uintptr_t>(this) + Offsets::BaseProjectile.SightAimConeScale, random_number);
			driver.write<float>(reinterpret_cast<uintptr_t>(this) + Offsets::BaseProjectile.HipAimConeScale, random_number);
		}
	}

	void ForceAutomatic()
	{
		if (global.force_automatic)
		{
			driver.write<bool>(reinterpret_cast<uintptr_t>(this) + Offsets::BaseProjectile.Automatic, true);
		}
	}

	void InstaEoka()
	{
		if (global.instant_eoka)
		{
			driver.write<float>(reinterpret_cast<uintptr_t>(this) + Offsets::FlintStrikeWeapon.SuccessFraction, 1.0f);
		}
	}

	void InstantCompound()
	{
		if (global.instant_compound)
		{
			driver.write<float>(reinterpret_cast<uintptr_t>(this) + Offsets::CompoundBowWeapon.StringHoldDurationMax, 0.f);
			driver.write<float>(reinterpret_cast<uintptr_t>(this) + Offsets::CompoundBowWeapon.MovementPenaltyRampUpTime, 0.f);
		}
	}

	void ExtendMelee()
	{
		if (true)
		{
			driver.write<float>(reinterpret_cast<uintptr_t>(this) + Offsets::BaseMelee.MaxDistance, 5.f);
		}
	}

	void WeaponHandler()
	{
		uintptr_t item_list = players.local->GetPlayerInventory()->GetContainerBelt()->GetItemList();
		uintptr_t active_item = players.local->GetActiveItem();

		int size = driver.read<int>(item_list + Offsets::List.Size);
		uintptr_t base = driver.read<uintptr_t>(item_list + Offsets::List.Base);

		for (int i = 0; i < size; i++)
		{
			uintptr_t item = driver.read<uintptr_t>(base + (0x20 + (i * 0x8)));

			uintptr_t uid = driver.read<uintptr_t>(item + Offsets::Item.Uid);
			Weapon* weapon = driver.read<Weapon*>(item + Offsets::Item.HeldEntity);

			if (uid == active_item)
			{

				uintptr_t info = driver.read<uintptr_t>(item + Offsets::Item.Info);
				int item_id = driver.read<int>(info + Offsets::ItemDefinition.Itemid);

				switch (item_id)
				{
				case WeaponType::AssultRifle:
				case WeaponType::IceAssultRifle:
				case WeaponType::Lr300:
				case WeaponType::M249:
				case WeaponType::M39:
				case WeaponType::Sar:
				case WeaponType::HMLMG:
				case WeaponType::L96:
				case WeaponType::BoltAction:
				case WeaponType::CustomSmg:
				case WeaponType::Mp5:
				case WeaponType::Thompson:
				case WeaponType::Python:
				case WeaponType::SemiPistol:
				case WeaponType::Revolver:
				case WeaponType::M92:
				case WeaponType::Nailgun:
					global.held_item = item;
					weapon->NoRecoil();
					weapon->NoSpread();
					weapon->ForceAutomatic();
					break;
				case WeaponType::Eoka:
					global.held_item = item;
					weapon->InstaEoka();
					weapon->NoSpread();
					break;
				case WeaponType::Spas12:
				case WeaponType::PumpShotgun:
				case WeaponType::WaterPipe:
				case WeaponType::DoubleBarrel:
					global.held_item = item;
					weapon->NoRecoil();
					weapon->NoSpread();
					break;
				case WeaponType::GrenadeLauncher:
				case WeaponType::RocketLauncher:
				case WeaponType::SnowBallGun:
				case WeaponType::FlameThrower:
					global.held_item = item;
					weapon->NoSpread();
					break;
				case WeaponType::Bow:
					global.held_item = item;
					weapon->SuperBow();
					weapon->NoSpread();
					break;
				case WeaponType::CompoundBow:
					global.held_item = item;
					weapon->NoRecoil();
					weapon->NoSpread();
					weapon->InstantCompound();
					break;
				case WeaponType::CrossBow:
					global.held_item = item;
					weapon->NoSpread();
					break;
				case::WeaponType::JackHammer:
				case::WeaponType::IcePickaxe:
				case::WeaponType::MetalPickaxe:
				case::WeaponType::StonePickaxe:
					weapon->ExtendMelee();
					break;
				default:
					global.held_item = NULL;
					break;
				}
			}
		}
	}
}*weapon;

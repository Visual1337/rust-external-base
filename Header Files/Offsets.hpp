#pragma once

#include <Windows.h>

#define STATIC_OFFSET static constexpr unsigned long long

namespace Offset
{
    STATIC_OFFSET BuildingBlock = 0x2ECBCE0;//      "Signature": "BuildingBlock_c*"
    STATIC_OFFSET BaseNetworkable_c = 0x2EC5D00;//      "Signature": "BaseNetworkable_c*"
    STATIC_OFFSET System_Collections_Generic_List_BaseGameMode_ = 0x2F02800;//      "Signature": "System_Collections_Generic_List_BaseGameMode__c*"
    STATIC_OFFSET MapMarker = 0x2EDBFC8;//      "Signature": "SleepingBagClusterMapMarker_c*"
    STATIC_OFFSET MainCamera = 0x2F23AA0;//      "Signature": "MainCamera_c*"
    STATIC_OFFSET TOD_Sky_c = 0x2EEAF50;//      "Signature": "TOD_Sky_c*"
    STATIC_OFFSET LocalPlayer = 0x2F212E8;//      "Signature": "LocalPlayer_c*"
    STATIC_OFFSET OcclusionCulling = 0x2F34020;//      "Signature": "OcclusionCulling_c*"
    STATIC_OFFSET OutlineManager_c = 0x2F3FF58;//      "Signature": "OutlineManager_c*"
    STATIC_OFFSET EffectNetwork = 0x2EEDAB8;//      "Signature": "EffectNetwork_c*"
    STATIC_OFFSET LaserBeam = 0x2F1C7E8;//      "Signature": "LaserBeam_c*"
    STATIC_OFFSET LaserLight = 0x2F1C8B0;//      "Signature": "LaserLight_c*"
    STATIC_OFFSET BradleyAPC = 0x2ECAB00;//      "Signature": "BradleyAPC_c*"
    STATIC_OFFSET ConVar_Admin_c = 0x2F43650;//      "Signature": "ConVar_Admin_c*"
    STATIC_OFFSET ConVar_Graphics = 0x2EFB888;//      "Signature": "ConVar_Graphics_c*"
    STATIC_OFFSET ConVar_Culling = 0x2EDCFC0;//      "Signature": "ConVar_Culling_c*"
    STATIC_OFFSET ConVar_Debugging = 0x2EE4DF8;//      "Signature": "ConVar_Debugging_c*"
    STATIC_OFFSET UIInventory = 0x2EF7578;//      "Signature": "UIInventory_c*"
    STATIC_OFFSET Buttons = 0x2ECC598;//      "Signature": "Buttons_c*"
    STATIC_OFFSET Network_Net = 0x2F30270;//      "Signature": "Network_Net_c*"
    STATIC_OFFSET ConsoleSystem_Index = 0x2F1C508;//      "Signature": "ConsoleSystem_Index_c*"
    STATIC_OFFSET set_flying = 0x1C34800;
    STATIC_OFFSET BuildAttackMessage = 0x787100;

    namespace BaseNetworkable
    {
        STATIC_OFFSET JustCreated__BackingField = 0x18; //bool
        STATIC_OFFSET entityDestroy = 0x20; //DeferredAction
        STATIC_OFFSET prefabID = 0x28; //uint
        STATIC_OFFSET globalBroadcast = 0x2C; //bool
        STATIC_OFFSET net = 0x30; //Networkable
        STATIC_OFFSET IsDestroyed__BackingField = 0x38; //bool
        STATIC_OFFSET _prefabName = 0x40; //string
        STATIC_OFFSET _prefabNameWithoutExtension = 0x48; //string
        STATIC_OFFSET postNetworkUpdateComponents = 0x50; //List<Component>
        STATIC_OFFSET parentEntity = 0x58; //EntityRef
        STATIC_OFFSET canTriggerParent = 0x70; //bool
    }
    namespace BaseEntity
    {
        STATIC_OFFSET ragdoll = 0x78; //Ragdoll
        STATIC_OFFSET positionLerp = 0x80; //PositionLerp
        STATIC_OFFSET menuOptions = 0x88; //List<Option>
        STATIC_OFFSET bounds = 0x90; //Bounds
        STATIC_OFFSET impactEffect = 0xA8; //GameObjectRef
        STATIC_OFFSET enableSaving = 0xB0; //bool
        STATIC_OFFSET syncPosition = 0xB1; //bool
        STATIC_OFFSET model = 0xB8; //Model
        STATIC_OFFSET flags = 0xC0; //BaseEntity.Flags
        STATIC_OFFSET parentBone = 0xC4; //uint
        STATIC_OFFSET skinID = 0xC8; //ulong
        STATIC_OFFSET _components = 0xD0; //EntityComponentBase[]
        STATIC_OFFSET HasBrain = 0xD8; //bool
        STATIC_OFFSET _name = 0xE0; //string
        STATIC_OFFSET OwnerID__BackingField = 0xE8; //ulong
        STATIC_OFFSET broadcastProtocol = 0xF0; //uint
        STATIC_OFFSET links = 0xF8; //List<EntityLink>
        STATIC_OFFSET linkedToNeighbours = 0x100; //bool
        STATIC_OFFSET _pendingFileRequests = 0x108; //List<BaseEntity.PendingFileRequest>
        STATIC_OFFSET updateParentingAction = 0x110; //Action
        STATIC_OFFSET addedToParentEntity = 0x118; //BaseEntity
        STATIC_OFFSET itemSkin = 0x120; //ItemSkin
        STATIC_OFFSET entitySlots = 0x128; //EntityRef[]
        STATIC_OFFSET triggers = 0x130; //List<TriggerBase>
        STATIC_OFFSET isVisible = 0x138; //bool
        STATIC_OFFSET isAnimatorVisible = 0x139; //bool
        STATIC_OFFSET isShadowVisible = 0x13A; //bool
        STATIC_OFFSET localOccludee = 0x140; //OccludeeSphere
        STATIC_OFFSET Weight__BackingField = 0x160; //float
    }
    namespace BaseCombatEntity
    {
        STATIC_OFFSET skeletonProperties = 0x1C0; //SkeletonProperties
        STATIC_OFFSET baseProtection = 0x1C8; //ProtectionProperties
        STATIC_OFFSET startHealth = 0x1D0; //float
        STATIC_OFFSET pickup = 0x1D8; //BaseCombatEntity.Pickup
        STATIC_OFFSET repair = 0x1F8; //BaseCombatEntity.Repair
        STATIC_OFFSET ShowHealthInfo = 0x220; //bool
        STATIC_OFFSET lifestate = 0x224; //BaseCombatEntity.LifeState
        STATIC_OFFSET sendsHitNotification = 0x228; //bool
        STATIC_OFFSET sendsMeleeHitNotification = 0x229; //bool
        STATIC_OFFSET markAttackerHostile = 0x22A; //bool
        STATIC_OFFSET _health = 0x22C; //float
        STATIC_OFFSET _maxHealth = 0x230; //float
        STATIC_OFFSET faction = 0x234; //BaseCombatEntity.Faction
        STATIC_OFFSET deathTime = 0x238; //float
        STATIC_OFFSET lastNotifyFrame = 0x23C; //int
    }
    namespace BasePlayer
    {
        STATIC_OFFSET playerModel = 0x4A8; //PlayerModel
        STATIC_OFFSET Frozen = 0x4B0; //bool
        STATIC_OFFSET voiceRecorder = 0x4B8; //PlayerVoiceRecorder
        STATIC_OFFSET voiceSpeaker = 0x4C0; //PlayerVoiceSpeaker
        STATIC_OFFSET input = 0x4C8; //PlayerInput
        STATIC_OFFSET movement = 0x4D0; //BaseMovement
        STATIC_OFFSET collision = 0x4D8; //BaseCollision
        STATIC_OFFSET _lookingAt = 0x4E0; //GameObject
        STATIC_OFFSET _lookingAtEntity = 0x4E8; //BaseEntity
        STATIC_OFFSET _lookingAtCollider = 0x4F0; //Collider
        STATIC_OFFSET lookingAtPoint__BackingField = 0x4F8; //Vector3
        STATIC_OFFSET wakeTime = 0x504; //float
        STATIC_OFFSET needsClothesRebuild = 0x508; //bool
        STATIC_OFFSET wasSleeping = 0x509; //bool
        STATIC_OFFSET wokeUpBefore = 0x50A; //bool
        STATIC_OFFSET wasDead = 0x50B; //bool
        STATIC_OFFSET lastClothesHash = 0x50C; //uint
        STATIC_OFFSET lastOpenSoundPlay = 0x510; //TimeSince
        STATIC_OFFSET currentViewMode = 0x514; //BasePlayer.CameraMode
        STATIC_OFFSET selectedViewMode = 0x518; //BasePlayer.CameraMode
        STATIC_OFFSET lastRevivePoint = 0x51C; //Vector3
        STATIC_OFFSET lastReviveDirection = 0x528; //Vector3
        STATIC_OFFSET IsWearingDiveGoggles__BackingField = 0x534; //bool
        STATIC_OFFSET GestureViewModel = 0x538; //ViewModel
        STATIC_OFFSET timeSinceUpdatedLookingAt = 0x540; //RealTimeSince
        STATIC_OFFSET nextTopologyTestTime = 0x544; //float
        STATIC_OFFSET usePressTime = 0x548; //float
        STATIC_OFFSET useHeldTime = 0x54C; //float
        STATIC_OFFSET lookingAtTest = 0x550; //HitTest
        STATIC_OFFSET cachedWaterDrinkingPoint = 0x558; //Vector3
        STATIC_OFFSET gestureList = 0x568; //GestureCollection
        STATIC_OFFSET gestureFinishedTime = 0x570; //TimeUntil
        STATIC_OFFSET blockHeldInputTimer = 0x574; //TimeSince
        STATIC_OFFSET currentGesture = 0x578; //GestureConfig
        STATIC_OFFSET disabledHeldEntity = 0x580; //HeldEntity
        STATIC_OFFSET nextGestureMenuOpenTime = 0x588; //float
        STATIC_OFFSET lastGestureCancel = 0x58C; //TimeSince
        STATIC_OFFSET client_lastHelloTime = 0x590; //float
        STATIC_OFFSET currentTeam = 0x598; //ulong
        STATIC_OFFSET clientTeam = 0x5A0; //PlayerTeam
        STATIC_OFFSET lastReceivedTeamTime = 0x5A8; //float
        STATIC_OFFSET lastPresenceTeamId = 0x5B0; //ulong
        STATIC_OFFSET lastPresenceTeamSize = 0x5B8; //int
        STATIC_OFFSET playerGroupKey = 0x5C0; //string
        STATIC_OFFSET playerGroupSizeKey = 0x5C8; //string
        STATIC_OFFSET clActiveItem = 0x5D0; //uint
        STATIC_OFFSET ClientCurrentMapNote = 0x5D8; //MapNote
        STATIC_OFFSET ClientCurrentDeathNote = 0x5E0; //MapNote
        STATIC_OFFSET missions = 0x5E8; //List<BaseMission.MissionInstance>
        STATIC_OFFSET _activeMission = 0x5F0; //int
        STATIC_OFFSET modelState = 0x5F8; //ModelState
        STATIC_OFFSET mounted = 0x600; //EntityRef
        STATIC_OFFSET nextSeatSwapTime = 0x610; //float
        STATIC_OFFSET PetEntity = 0x618; //BaseEntity
        STATIC_OFFSET lastPetCommandIssuedTime = 0x620; //float
        STATIC_OFFSET PetPrefabID = 0x624; //uint
        STATIC_OFFSET PetID = 0x628; //uint
        STATIC_OFFSET cachedBuildingPrivilegeTime = 0x62C; //float
        STATIC_OFFSET cachedBuildingPrivilege = 0x630; //BuildingPrivlidge
        STATIC_OFFSET maxProjectileID = 0x638; //int
        STATIC_OFFSET lastUpdateTime = 0x63C; //float
        STATIC_OFFSET cachedThreatLevel = 0x640; //float
        STATIC_OFFSET serverTickRate = 0x644; //int
        STATIC_OFFSET clientTickRate = 0x648; //int
        STATIC_OFFSET serverTickInterval = 0x64C; //float
        STATIC_OFFSET clientTickInterval = 0x650; //float
        STATIC_OFFSET lastSentTickTime = 0x654; //float
        STATIC_OFFSET lastTickStopwatch = 0x658; //Stopwatch
        STATIC_OFFSET lastSentTick = 0x660; //PlayerTick
        STATIC_OFFSET nextVisThink = 0x668; //float
        STATIC_OFFSET lastTimeSeen = 0x66C; //float
        STATIC_OFFSET debugPrevVisible = 0x670; //bool
        STATIC_OFFSET fallDamageEffect = 0x678; //GameObjectRef
        STATIC_OFFSET drownEffect = 0x680; //GameObjectRef
        STATIC_OFFSET playerFlags = 0x688; //BasePlayer.PlayerFlags
        STATIC_OFFSET eyes = 0x690; //PlayerEyes
        STATIC_OFFSET inventory = 0x698; //PlayerInventory
        STATIC_OFFSET blueprints = 0x6A0; //PlayerBlueprints
        STATIC_OFFSET metabolism = 0x6A8; //PlayerMetabolism
        STATIC_OFFSET modifiers = 0x6B0; //PlayerModifiers
        STATIC_OFFSET playerCollider = 0x6B8; //CapsuleCollider
        STATIC_OFFSET Belt = 0x6C0; //PlayerBelt
        STATIC_OFFSET playerRigidbody = 0x6C8; //Rigidbody
        STATIC_OFFSET userID = 0x6D0; //ulong
        STATIC_OFFSET UserIDString = 0x6D8; //string
        STATIC_OFFSET gamemodeteam = 0x6E0; //int
        STATIC_OFFSET reputation = 0x6E4; //int
        STATIC_OFFSET _displayName = 0x6E8; //string
        STATIC_OFFSET _lastSetName = 0x6F0; //string
        STATIC_OFFSET playerColliderStanding = 0x6F8; //BasePlayer.CapsuleColliderInfo
        STATIC_OFFSET playerColliderDucked = 0x70C; //BasePlayer.CapsuleColliderInfo
        STATIC_OFFSET playerColliderCrawling = 0x720; //BasePlayer.CapsuleColliderInfo
        STATIC_OFFSET playerColliderLyingDown = 0x734; //BasePlayer.CapsuleColliderInfo
        STATIC_OFFSET cachedProtection = 0x748; //ProtectionProperties
        STATIC_OFFSET lastHeadshotSoundTime = 0x750; //float
        STATIC_OFFSET nextColliderRefreshTime = 0x754; //float
        STATIC_OFFSET clothingBlocksAiming = 0x758; //bool
        STATIC_OFFSET clothingMoveSpeedReduction = 0x75C; //float
        STATIC_OFFSET clothingWaterSpeedBonus = 0x760; //float
        STATIC_OFFSET clothingAccuracyBonus = 0x764; //float
        STATIC_OFFSET equippingBlocked = 0x768; //bool
        STATIC_OFFSET eggVision = 0x76C; //float
        STATIC_OFFSET activeTelephone = 0x770; //PhoneController
        STATIC_OFFSET designingAIEntity = 0x778; //BaseEntity
    }
    namespace ConVar_Admin
    {

    }
    namespace PlayerModel
    {
        STATIC_OFFSET collision = 0x18; //BoxCollider
        STATIC_OFFSET censorshipCube = 0x20; //GameObject
        STATIC_OFFSET censorshipCubeBreasts = 0x28; //GameObject
        STATIC_OFFSET jawBone = 0x30; //GameObject
        STATIC_OFFSET neckBone = 0x38; //GameObject
        STATIC_OFFSET headBone = 0x40; //GameObject
        STATIC_OFFSET eyeController = 0x48; //EyeController
        STATIC_OFFSET blinkController = 0x50; //EyeBlink
        STATIC_OFFSET SpineBones = 0x58; //Transform[]
        STATIC_OFFSET leftFootBone = 0x60; //Transform
        STATIC_OFFSET rightFootBone = 0x68; //Transform
        STATIC_OFFSET leftHandPropBone = 0x70; //Transform
        STATIC_OFFSET rightHandPropBone = 0x78; //Transform
        STATIC_OFFSET rightHandTarget = 0x80; //Vector3
        STATIC_OFFSET leftHandTargetPosition = 0x8C; //Vector3
        STATIC_OFFSET leftHandTargetRotation = 0x98; //Quaternion
        STATIC_OFFSET rightHandTargetPosition = 0xA8; //Vector3
        STATIC_OFFSET rightHandTargetRotation = 0xB4; //Quaternion
        STATIC_OFFSET steeringTargetDegrees = 0xC4; //float
        STATIC_OFFSET rightFootTargetPosition = 0xC8; //Vector3
        STATIC_OFFSET rightFootTargetRotation = 0xD4; //Quaternion
        STATIC_OFFSET leftFootTargetPosition = 0xE4; //Vector3
        STATIC_OFFSET leftFootTargetRotation = 0xF0; //Quaternion
        STATIC_OFFSET CinematicAnimationController = 0x100; //RuntimeAnimatorController
        STATIC_OFFSET DefaultAvatar = 0x108; //Avatar
        STATIC_OFFSET CinematicAvatar = 0x110; //Avatar
        STATIC_OFFSET DefaultHoldType = 0x118; //RuntimeAnimatorController
        STATIC_OFFSET SleepGesture = 0x120; //RuntimeAnimatorController
        STATIC_OFFSET CrawlToIncapacitatedGesture = 0x128; //RuntimeAnimatorController
        STATIC_OFFSET StandToIncapacitatedGesture = 0x130; //RuntimeAnimatorController
        STATIC_OFFSET CurrentGesture = 0x138; //RuntimeAnimatorController
        STATIC_OFFSET MaleSkin = 0x140; //SkinSetCollection
        STATIC_OFFSET FemaleSkin = 0x148; //SkinSetCollection
        STATIC_OFFSET subsurfaceProfile = 0x150; //SubsurfaceProfile
        STATIC_OFFSET voiceVolume = 0x158; //float
        STATIC_OFFSET skinColor = 0x15C; //float
        STATIC_OFFSET skinNumber = 0x160; //float
        STATIC_OFFSET meshNumber = 0x164; //float
        STATIC_OFFSET hairNumber = 0x168; //float
        STATIC_OFFSET skinType = 0x16C; //int
        STATIC_OFFSET movementSounds = 0x170; //MovementSounds
        STATIC_OFFSET showSash = 0x178; //bool
        STATIC_OFFSET tempPoseType = 0x17C; //int
        STATIC_OFFSET underwearSkin = 0x180; //uint
        STATIC_OFFSET overrideSkinSeed__BackingField = 0x188; //ulong
        STATIC_OFFSET AimAngles__BackingField = 0x190; //Quaternion
        STATIC_OFFSET LookAngles__BackingField = 0x1A0; //Quaternion
        STATIC_OFFSET modelState = 0x1B0; //ModelState
        STATIC_OFFSET position = 0x1B8; //Vector3
        STATIC_OFFSET velocity = 0x1C4; //Vector3
        STATIC_OFFSET speedOverride = 0x1D0; //Vector3
        STATIC_OFFSET newVelocity = 0x1DC; //Vector3
        STATIC_OFFSET rotation = 0x1E8; //Quaternion
        STATIC_OFFSET mountedRotation = 0x1F8; //Quaternion
        STATIC_OFFSET smoothLeftFootIK = 0x208; //Vector3
        STATIC_OFFSET smoothRightFootIK = 0x214; //Vector3
        STATIC_OFFSET drawShadowOnly = 0x220; //bool
        STATIC_OFFSET isIncapacitated = 0x221; //bool
        STATIC_OFFSET flinchLocation = 0x224; //uint
        STATIC_OFFSET visible = 0x228; //bool
        STATIC_OFFSET nameTag = 0x230; //PlayerNameTag
        STATIC_OFFSET animatorNeedsWarmup = 0x238; //bool
        STATIC_OFFSET isLocalPlayer = 0x239; //bool
        STATIC_OFFSET aimSoundDef = 0x240; //SoundDefinition
        STATIC_OFFSET aimEndSoundDef = 0x248; //SoundDefinition
        STATIC_OFFSET InGesture = 0x250; //bool
        STATIC_OFFSET CurrentGestureConfig = 0x258; //GestureConfig
        STATIC_OFFSET InCinematic = 0x260; //bool
        STATIC_OFFSET defaultAnimatorController = 0x268; //RuntimeAnimatorController
        STATIC_OFFSET _multiMesh = 0x270; //SkinnedMultiMesh
        STATIC_OFFSET _animator = 0x278; //Animator
        STATIC_OFFSET _lodGroup = 0x280; //LODGroup
        STATIC_OFFSET _currentGesture = 0x288; //RuntimeAnimatorController
        STATIC_OFFSET holdTypeLock = 0x290; //float
        STATIC_OFFSET hasHeldEntity = 0x294; //bool
        STATIC_OFFSET wasMountedRightAim = 0x295; //bool
        STATIC_OFFSET cachedMask = 0x298; //int
        STATIC_OFFSET cachedConstructionMask = 0x29C; //int
        STATIC_OFFSET WorkshopHeldEntity = 0x2A0; //HeldEntity
        STATIC_OFFSET wasCrawling = 0x2A8; //bool
        STATIC_OFFSET mountedSpineLookWeight = 0x2AC; //float
        STATIC_OFFSET mountedAnimSpeed = 0x2B0; //float
        STATIC_OFFSET preserveBones = 0x2B4; //bool
        STATIC_OFFSET downLimitOverride = 0x2B8; //Nullable<float>
        STATIC_OFFSET blendShapeControllers = 0x2C0; //List<BlendShapeController>
        STATIC_OFFSET IsNpc__BackingField = 0x2C8; //bool
        STATIC_OFFSET timeSinceReactionStart = 0x2CC; //TimeSince
        STATIC_OFFSET timeSinceLeftFootTest = 0x2D0; //TimeSince
        STATIC_OFFSET cachedLeftFootPos = 0x2D4; //Vector3
        STATIC_OFFSET cachedLeftFootNormal = 0x2E0; //Vector3
        STATIC_OFFSET timeSinceRightFootTest = 0x2EC; //TimeSince
        STATIC_OFFSET cachedRightFootPos = 0x2F0; //Vector3
        STATIC_OFFSET cachedRightFootNormal = 0x2FC; //Vector3
        STATIC_OFFSET _smoothAimWeight = 0x308; //float
        STATIC_OFFSET _smoothVelocity = 0x30C; //float
        STATIC_OFFSET _smoothlookAngle = 0x310; //Vector3
        STATIC_OFFSET allowMountedHeadLook = 0x31C; //bool
        STATIC_OFFSET smoothLookDir = 0x320; //Vector3
        STATIC_OFFSET lastSafeLookDir = 0x32C; //Vector3
        STATIC_OFFSET Shoulders = 0x338; //Transform[]
        STATIC_OFFSET AdditionalSpineBones = 0x340; //Transform[]
        STATIC_OFFSET LegParts = 0x348; //List<SkinnedMeshRenderer>
        STATIC_OFFSET fakeSpineBones = 0x350; //Transform[]
        STATIC_OFFSET extraLeanBack = 0x358; //float
        STATIC_OFFSET drawState = 0x35C; //Nullable<bool>
        STATIC_OFFSET timeInArmsMode = 0x360; //float
    }
    namespace PlayerInput
    {
        STATIC_OFFSET state = 0x20; //InputState
        STATIC_OFFSET hadInputBuffer = 0x28; //bool
        STATIC_OFFSET bodyRotation = 0x2C; //Quaternion
        STATIC_OFFSET bodyAngles = 0x3C; //Vector3
        STATIC_OFFSET headRotation = 0x48; //Quaternion
        STATIC_OFFSET headAngles = 0x58; //Vector3
        STATIC_OFFSET recoilAngles = 0x64; //Vector3
        STATIC_OFFSET viewDelta = 0x70; //Vector2
        STATIC_OFFSET headLerp = 0x78; //float
        STATIC_OFFSET mouseWheelUp = 0x7C; //int
        STATIC_OFFSET mouseWheelDn = 0x80; //int
        STATIC_OFFSET autorun = 0x84; //bool
        STATIC_OFFSET toggleDuck = 0x85; //bool
        STATIC_OFFSET toggleAds = 0x86; //bool
        STATIC_OFFSET lastAdsEntity = 0x88; //uint
        STATIC_OFFSET pendingMouseDelta = 0x8C; //Vector3
        STATIC_OFFSET offsetAngles = 0x98; //Vector3
        STATIC_OFFSET ignoredButtons = 0xA4; //int
        STATIC_OFFSET hasKeyFocus = 0xA8; //bool
    }
    namespace PlayerEyes
    {
        STATIC_OFFSET thirdPersonSleepingOffset = 0x20; //Vector3
        STATIC_OFFSET defaultLazyAim = 0x30; //LazyAimProperties
        STATIC_OFFSET viewOffset = 0x38; //Vector3
        STATIC_OFFSET bodyRotation__BackingField = 0x44; //Quaternion
        STATIC_OFFSET headAngles__BackingField = 0x54; //Vector3
        STATIC_OFFSET rotationLook__BackingField = 0x60; //Quaternion
        STATIC_OFFSET IsAltLookingLegsThreshold__BackingField = 0x70; //bool
    }
    namespace ModelState
    {
        STATIC_OFFSET waterLevel = 0x10; //float
        STATIC_OFFSET lookDir = 0x14; //Vector3
        STATIC_OFFSET flags = 0x20; //int
        STATIC_OFFSET poseType = 0x24; //int
        STATIC_OFFSET inheritedVelocity = 0x28; //Vector3
        STATIC_OFFSET ShouldPool = 0x34; //bool
        STATIC_OFFSET _disposed = 0x35; //bool
    }
    namespace Translate_Phrase
    {
        STATIC_OFFSET token = 0x10; //string
        STATIC_OFFSET english = 0x18; //string
    }
    namespace Model
    {
        STATIC_OFFSET collision = 0x18; //SphereCollider
        STATIC_OFFSET rootBone = 0x20; //Transform
        STATIC_OFFSET headBone = 0x28; //Transform
        STATIC_OFFSET eyeBone = 0x30; //Transform
        STATIC_OFFSET animator = 0x38; //Animator
        STATIC_OFFSET skeleton = 0x40; //Skeleton
        STATIC_OFFSET boneTransforms = 0x48; //Transform[]
        STATIC_OFFSET boneNames = 0x50; //string[]
        STATIC_OFFSET boneDict = 0x58; //BoneDictionary
        STATIC_OFFSET skin = 0x60; //int
        STATIC_OFFSET _lodGroup = 0x68; //LODGroup
    }
    namespace BaseMountable
    {
        STATIC_OFFSET eyePositionOverride = 0x298; //Transform
        STATIC_OFFSET eyeCenterOverride = 0x2A0; //Transform
        STATIC_OFFSET pitchClamp = 0x2A8; //Vector2
        STATIC_OFFSET yawClamp = 0x2B0; //Vector2
        STATIC_OFFSET canWieldItems = 0x2B8; //bool
        STATIC_OFFSET relativeViewAngles = 0x2B9; //bool
        STATIC_OFFSET mountAnchor = 0x2C0; //Transform
        STATIC_OFFSET mountPose = 0x2C8; //PlayerModel.MountPoses
        STATIC_OFFSET maxMountDistance = 0x2CC; //float
        STATIC_OFFSET dismountPositions = 0x2D0; //Transform[]
        STATIC_OFFSET checkPlayerLosOnMount = 0x2D8; //bool
        STATIC_OFFSET disableMeshCullingForPlayers = 0x2D9; //bool
        STATIC_OFFSET allowHeadLook = 0x2DA; //bool
        STATIC_OFFSET ignoreVehicleParent = 0x2DB; //bool
        STATIC_OFFSET legacyDismount = 0x2DC; //bool
        STATIC_OFFSET modifiesPlayerCollider = 0x2DD; //bool
        STATIC_OFFSET customPlayerCollider = 0x2E0; //BasePlayer.CapsuleColliderInfo
        STATIC_OFFSET mountSoundDef = 0x2F8; //SoundDefinition
        STATIC_OFFSET swapSoundDef = 0x300; //SoundDefinition
        STATIC_OFFSET dismountSoundDef = 0x308; //SoundDefinition
        STATIC_OFFSET mountTimeStatType = 0x310; //BaseMountable.MountStatType
        STATIC_OFFSET allowedGestures = 0x314; //BaseMountable.MountGestureType
        STATIC_OFFSET canDrinkWhileMounted = 0x318; //bool
        STATIC_OFFSET allowSleeperMounting = 0x319; //bool
        STATIC_OFFSET animateClothInLocalSpace = 0x31A; //bool
        STATIC_OFFSET MountedCameraMode = 0x31C; //BasePlayer.CameraMode
        STATIC_OFFSET isMobile = 0x320; //bool
        STATIC_OFFSET SideLeanAmount = 0x324; //float
    }
    namespace BaseMovement
    {
        STATIC_OFFSET adminCheat = 0x18; //bool
        STATIC_OFFSET adminSpeed = 0x1C; //float
        STATIC_OFFSET Owner__BackingField = 0x20; //BasePlayer
        STATIC_OFFSET InheritedVelocity__BackingField = 0x28; //Vector3
        STATIC_OFFSET TargetMovement__BackingField = 0x34; //Vector3
        STATIC_OFFSET Running__BackingField = 0x40; //float
        STATIC_OFFSET Ducking__BackingField = 0x44; //float
        STATIC_OFFSET Crawling__BackingField = 0x48; //float
        STATIC_OFFSET Grounded__BackingField = 0x4C; //float
        STATIC_OFFSET lastTeleportedTime = 0x50; //float
        STATIC_OFFSET groundAngleNew = 0xc8;//float i thibk

    }
    namespace PlayerWalkMovement
    {
        STATIC_OFFSET zeroFrictionMaterial = 0x58; //PhysicMaterial
        STATIC_OFFSET highFrictionMaterial = 0x60; //PhysicMaterial
        STATIC_OFFSET capsuleHeight = 0x68; //float
        STATIC_OFFSET capsuleCenter = 0x6C; //float
        STATIC_OFFSET capsuleHeightDucked = 0x70; //float
        STATIC_OFFSET capsuleCenterDucked = 0x74; //float
        STATIC_OFFSET capsuleHeightCrawling = 0x78; //float
        STATIC_OFFSET capsuleCenterCrawling = 0x7C; //float
        STATIC_OFFSET gravityTestRadius = 0x80; //float
        STATIC_OFFSET gravityMultiplier = 0x84; //float
        STATIC_OFFSET gravityMultiplierSwimming = 0x88; //float
        STATIC_OFFSET maxAngleWalking = 0x8C; //float
        STATIC_OFFSET maxAngleClimbing = 0x90; //float
        STATIC_OFFSET maxAngleSliding = 0x94; //float
        STATIC_OFFSET maxStepHeight = 0x98; //float
        STATIC_OFFSET body = 0xA0; //Rigidbody
        STATIC_OFFSET initialColDetectionMode = 0xA8; //CollisionDetectionMode
        STATIC_OFFSET capsule = 0xB0; //CapsuleCollider
        STATIC_OFFSET ladder = 0xB8; //TriggerLadder
        STATIC_OFFSET maxVelocity = 0xC0; //float
        STATIC_OFFSET groundAngle = 0xC4; //float
        STATIC_OFFSET groundAngleNew = 0xC8; //float
        STATIC_OFFSET groundTime = 0xCC; //float
        STATIC_OFFSET jumpTime = 0xD0; //float
        STATIC_OFFSET landTime = 0xD4; //float
        STATIC_OFFSET previousPosition = 0xD8; //Vector3
        STATIC_OFFSET previousVelocity = 0xE4; //Vector3
        STATIC_OFFSET previousInheritedVelocity = 0xF0; //Vector3
        STATIC_OFFSET groundNormal = 0xFC; //Vector3
        STATIC_OFFSET groundNormalNew = 0x108; //Vector3
        STATIC_OFFSET groundVelocity = 0x114; //Vector3
        STATIC_OFFSET groundVelocityNew = 0x120; //Vector3
        STATIC_OFFSET nextSprintTime = 0x12C; //float
        STATIC_OFFSET lastSprintTime = 0x130; //float
        STATIC_OFFSET sprintForced = 0x134; //bool
        STATIC_OFFSET attemptedMountTime = 0x138; //TimeSince
        STATIC_OFFSET modify = 0x13C; //BaseEntity.MovementModify
        STATIC_OFFSET grounded = 0x140; //bool
        STATIC_OFFSET climbing = 0x141; //bool
        STATIC_OFFSET sliding = 0x142; //bool
        STATIC_OFFSET swimming = 0x143; //bool
        STATIC_OFFSET wasSwimming = 0x144; //bool
        STATIC_OFFSET jumping = 0x145; //bool
        STATIC_OFFSET wasJumping = 0x146; //bool
        STATIC_OFFSET falling = 0x147; //bool
        STATIC_OFFSET wasFalling = 0x148; //bool
        STATIC_OFFSET flying = 0x149; //bool
        STATIC_OFFSET wasFlying = 0x14A; //bool
        STATIC_OFFSET forcedDuckDelta = 0x14C; //float
    }
    namespace SkinSet
    {
        STATIC_OFFSET Label = 0x18; //string
        STATIC_OFFSET SkinColour = 0x20; //Gradient
        STATIC_OFFSET HairCollection = 0x28; //HairSetCollection
        STATIC_OFFSET Head = 0x30; //GameObjectRef
        STATIC_OFFSET Torso = 0x38; //GameObjectRef
        STATIC_OFFSET Legs = 0x40; //GameObjectRef
        STATIC_OFFSET Feet = 0x48; //GameObjectRef
        STATIC_OFFSET Hands = 0x50; //GameObjectRef
        STATIC_OFFSET CensoredTorso = 0x58; //GameObjectRef
        STATIC_OFFSET CensoredLegs = 0x60; //GameObjectRef
        STATIC_OFFSET HeadMaterial = 0x68; //Material
        STATIC_OFFSET BodyMaterial = 0x70; //Material
        STATIC_OFFSET EyeMaterial = 0x78; //Material
    }
    namespace Item
    {
        STATIC_OFFSET _condition = 0x10; //float
        STATIC_OFFSET _maxCondition = 0x14; //float
        STATIC_OFFSET info = 0x18; //ItemDefinition
        STATIC_OFFSET uid = 0x20; //uint
        STATIC_OFFSET dirty = 0x24; //bool
        STATIC_OFFSET amount = 0x28; //int
        STATIC_OFFSET position = 0x2C; //int
        STATIC_OFFSET busyTime = 0x30; //float
        STATIC_OFFSET removeTime = 0x34; //float
        STATIC_OFFSET fuel = 0x38; //float
        STATIC_OFFSET isServer = 0x3C; //bool
        STATIC_OFFSET instanceData = 0x40; //Item.InstanceData
        STATIC_OFFSET skin = 0x48; //ulong
        STATIC_OFFSET name = 0x50; //string
        STATIC_OFFSET text = 0x58; //string
        STATIC_OFFSET cookTimeLeft = 0x60; //float
        STATIC_OFFSET progressBar = 0x64; //float
        STATIC_OFFSET OnDirty = 0x68; //Action<Item>
        STATIC_OFFSET flags = 0x70; //Item.Flag
        STATIC_OFFSET contents = 0x78; //ItemContainer
        STATIC_OFFSET parent = 0x80; //ItemContainer
        STATIC_OFFSET worldEnt = 0x88; //EntityRef
        STATIC_OFFSET heldEntity = 0x98; //EntityRef
        STATIC_OFFSET amountOverride = 0xA8; //Nullable<int>
    }
    namespace AttackEntity
    {
        STATIC_OFFSET deployDelay = 0x1F8; //float
        STATIC_OFFSET repeatDelay = 0x1FC; //float
        STATIC_OFFSET animationDelay = 0x200; //float
        STATIC_OFFSET effectiveRange = 0x204; //float
        STATIC_OFFSET npcDamageScale = 0x208; //float
        STATIC_OFFSET attackLengthMin = 0x20C; //float
        STATIC_OFFSET attackLengthMax = 0x210; //float
        STATIC_OFFSET attackSpacing = 0x214; //float
        STATIC_OFFSET aiAimSwayOffset = 0x218; //float
        STATIC_OFFSET aiAimCone = 0x21C; //float
        STATIC_OFFSET aiOnlyInRange = 0x220; //bool
        STATIC_OFFSET CloseRangeAddition = 0x224; //float
        STATIC_OFFSET MediumRangeAddition = 0x228; //float
        STATIC_OFFSET LongRangeAddition = 0x22C; //float
        STATIC_OFFSET CanUseAtMediumRange = 0x230; //bool
        STATIC_OFFSET CanUseAtLongRange = 0x231; //bool
        STATIC_OFFSET reloadSounds = 0x238; //SoundDefinition[]
        STATIC_OFFSET thirdPersonMeleeSound = 0x240; //SoundDefinition
        STATIC_OFFSET recoilCompDelayOverride = 0x248; //float
        STATIC_OFFSET wantsRecoilComp = 0x24C; //bool
        STATIC_OFFSET nextAttackTime = 0x250; //float
        STATIC_OFFSET lastTickTime = 0x254; //float
        STATIC_OFFSET nextTickTime = 0x258; //float
        STATIC_OFFSET timeSinceDeploy = 0x25C; //float
        STATIC_OFFSET lastRecoilCompTime = 0x260; //float
        STATIC_OFFSET startAimingDirection = 0x264; //Vector3
        STATIC_OFFSET wasDoingRecoilComp = 0x270; //bool
        STATIC_OFFSET reductionSpeed = 0x274; //Vector3
    }
    namespace BaseProjectile
    {
        STATIC_OFFSET NoiseRadius = 0x280; //float
        STATIC_OFFSET damageScale = 0x284; //float
        STATIC_OFFSET distanceScale = 0x288; //float
        STATIC_OFFSET projectileVelocityScale = 0x28C; //float
        STATIC_OFFSET automatic = 0x290; //bool
        STATIC_OFFSET usableByTurret = 0x291; //bool
        STATIC_OFFSET turretDamageScale = 0x294; //float
        STATIC_OFFSET attackFX = 0x298; //GameObjectRef
        STATIC_OFFSET silencedAttack = 0x2A0; //GameObjectRef
        STATIC_OFFSET muzzleBrakeAttack = 0x2A8; //GameObjectRef
        STATIC_OFFSET MuzzlePoint = 0x2B0; //Transform
        STATIC_OFFSET reloadTime = 0x2B8; //float
        STATIC_OFFSET canUnloadAmmo = 0x2BC; //bool
        STATIC_OFFSET primaryMagazine = 0x2C0; //BaseProjectile.Magazine
        STATIC_OFFSET fractionalReload = 0x2C8; //bool
        STATIC_OFFSET reloadStartDuration = 0x2CC; //float
        STATIC_OFFSET reloadFractionDuration = 0x2D0; //float
        STATIC_OFFSET reloadEndDuration = 0x2D4; //float
        STATIC_OFFSET aimSway = 0x2D8; //float
        STATIC_OFFSET aimSwaySpeed = 0x2DC; //float
        STATIC_OFFSET recoil = 0x2E0; //RecoilProperties
        STATIC_OFFSET aimconeCurve = 0x2E8; //AnimationCurve
        STATIC_OFFSET aimCone = 0x2F0; //float
        STATIC_OFFSET hipAimCone = 0x2F4; //float
        STATIC_OFFSET aimconePenaltyPerShot = 0x2F8; //float
        STATIC_OFFSET aimConePenaltyMax = 0x2FC; //float
        STATIC_OFFSET aimconePenaltyRecoverTime = 0x300; //float
        STATIC_OFFSET aimconePenaltyRecoverDelay = 0x304; //float
        STATIC_OFFSET stancePenaltyScale = 0x308; //float
        STATIC_OFFSET hasADS = 0x30C; //bool
        STATIC_OFFSET noAimingWhileCycling = 0x30D; //bool
        STATIC_OFFSET manualCycle = 0x30E; //bool
        STATIC_OFFSET needsCycle = 0x30F; //bool
        STATIC_OFFSET isCycling = 0x310; //bool
        STATIC_OFFSET aiming = 0x311; //bool
        STATIC_OFFSET isBurstWeapon = 0x312; //bool
        STATIC_OFFSET canChangeFireModes = 0x313; //bool
        STATIC_OFFSET defaultOn = 0x314; //bool
        STATIC_OFFSET internalBurstRecoilScale = 0x318; //float
        STATIC_OFFSET internalBurstFireRateScale = 0x31C; //float
        STATIC_OFFSET internalBurstAimConeScale = 0x320; //float
        STATIC_OFFSET Toast_BurstDisabled = 0x328; //Translate.Phrase
        STATIC_OFFSET Toast_BurstEnabled = 0x330; //Translate.Phrase
        STATIC_OFFSET resetDuration = 0x338; //float
        STATIC_OFFSET numShotsFired = 0x33C; //int
        STATIC_OFFSET nextReloadTime = 0x340; //float
        STATIC_OFFSET startReloadTime = 0x344; //float
        STATIC_OFFSET stancePenalty = 0x348; //float
        STATIC_OFFSET aimconePenalty = 0x34C; //float
        STATIC_OFFSET cachedModHash = 0x350; //uint
        STATIC_OFFSET sightAimConeScale = 0x354; //float
        STATIC_OFFSET sightAimConeOffset = 0x358; //float
        STATIC_OFFSET hipAimConeScale = 0x35C; //float
        STATIC_OFFSET hipAimConeOffset = 0x360; //float
        STATIC_OFFSET isReloading = 0x364; //bool
        STATIC_OFFSET swaySampleTime = 0x368; //float
        STATIC_OFFSET lastShotTime = 0x36C; //float
        STATIC_OFFSET reloadPressTime = 0x370; //float
        STATIC_OFFSET ammoTypePreReload = 0x378; //ItemDefinition
        STATIC_OFFSET fractionalReloadDesiredCount = 0x380; //int
        STATIC_OFFSET fractionalReloadNumAdded = 0x384; //int
        STATIC_OFFSET currentBurst = 0x388; //int
        STATIC_OFFSET triggerReady = 0x38C; //bool
        STATIC_OFFSET nextHeightCheckTime = 0x390; //float
        STATIC_OFFSET cachedUnderground = 0x394; //bool
        STATIC_OFFSET createdProjectiles = 0x398; //List<Projectile>
    }
    namespace RecoilProperties
    {
        STATIC_OFFSET recoilYawMin = 0x18; //float
        STATIC_OFFSET recoilYawMax = 0x1C; //float
        STATIC_OFFSET recoilPitchMin = 0x20; //float
        STATIC_OFFSET recoilPitchMax = 0x24; //float
        STATIC_OFFSET timeToTakeMin = 0x28; //float
        STATIC_OFFSET timeToTakeMax = 0x2C; //float
        STATIC_OFFSET ADSScale = 0x30; //float
        STATIC_OFFSET movementPenalty = 0x34; //float
        STATIC_OFFSET clampPitch = 0x38; //float
        STATIC_OFFSET pitchCurve = 0x40; //AnimationCurve
        STATIC_OFFSET yawCurve = 0x48; //AnimationCurve
        STATIC_OFFSET useCurves = 0x50; //bool
        STATIC_OFFSET curvesAsScalar = 0x51; //bool
        STATIC_OFFSET shotsUntilMax = 0x54; //int
        STATIC_OFFSET maxRecoilRadius = 0x58; //float
        STATIC_OFFSET overrideAimconeWithCurve = 0x5C; //bool
        STATIC_OFFSET aimconeCurveScale = 0x60; //float
        STATIC_OFFSET aimconeCurve = 0x68; //AnimationCurve
        STATIC_OFFSET aimconeProbabilityCurve = 0x70; //AnimationCurve
        STATIC_OFFSET newRecoilOverride = 0x78; //RecoilProperties
    }
    namespace Projectile
    {
        STATIC_OFFSET initialVelocity = 0x18; //Vector3
        STATIC_OFFSET drag = 0x24; //float
        STATIC_OFFSET gravityModifier = 0x28; //float
        STATIC_OFFSET thickness = 0x2C; //float
        STATIC_OFFSET initialDistance = 0x30; //float
        STATIC_OFFSET remainInWorld = 0x34; //bool
        STATIC_OFFSET stickProbability = 0x38; //float
        STATIC_OFFSET breakProbability = 0x3C; //float
        STATIC_OFFSET conditionLoss = 0x40; //float
        STATIC_OFFSET ricochetChance = 0x44; //float
        STATIC_OFFSET penetrationPower = 0x48; //float
        STATIC_OFFSET damageProperties = 0x50; //DamageProperties
        STATIC_OFFSET damageDistances = 0x58; //MinMax
        STATIC_OFFSET damageMultipliers = 0x60; //MinMax
        STATIC_OFFSET damageTypes = 0x68; //List<DamageTypeEntry>
        STATIC_OFFSET rendererToScale = 0x70; //ScaleRenderer
        STATIC_OFFSET firstPersonRenderer = 0x78; //ScaleRenderer
        STATIC_OFFSET createDecals = 0x80; //bool
        STATIC_OFFSET doDefaultHitEffects = 0x81; //bool
        STATIC_OFFSET flybySound = 0x88; //SoundDefinition
        STATIC_OFFSET flybySoundDistance = 0x90; //float
        STATIC_OFFSET closeFlybySound = 0x98; //SoundDefinition
        STATIC_OFFSET closeFlybyDistance = 0xA0; //float
        STATIC_OFFSET tumbleSpeed = 0xA4; //float
        STATIC_OFFSET tumbleAxis = 0xA8; //Vector3
        STATIC_OFFSET swimScale = 0xB4; //Vector3
        STATIC_OFFSET swimSpeed = 0xC0; //Vector3
        STATIC_OFFSET owner = 0xD0; //BasePlayer
        STATIC_OFFSET sourceWeaponPrefab = 0xD8; //AttackEntity
        STATIC_OFFSET sourceProjectilePrefab = 0xE0; //Projectile
        STATIC_OFFSET mod = 0xE8; //ItemModProjectile
        STATIC_OFFSET projectileID = 0xF0; //int
        STATIC_OFFSET seed = 0xF4; //int
        STATIC_OFFSET clientsideEffect = 0xF8; //bool
        STATIC_OFFSET clientsideAttack = 0xF9; //bool
        STATIC_OFFSET integrity = 0xFC; //float
        STATIC_OFFSET maxDistance = 0x100; //float
        STATIC_OFFSET modifier = 0x104; //Projectile.Modifier
        STATIC_OFFSET invisible = 0x114; //bool
        STATIC_OFFSET currentVelocity = 0x118; //Vector3
        STATIC_OFFSET currentPosition = 0x124; //Vector3
        STATIC_OFFSET traveledDistance = 0x130; //float
        STATIC_OFFSET traveledTime = 0x134; //float
        STATIC_OFFSET launchTime = 0x138; //float
        STATIC_OFFSET sentPosition = 0x13C; //Vector3
        STATIC_OFFSET previousPosition = 0x148; //Vector3
        STATIC_OFFSET previousVelocity = 0x154; //Vector3
        STATIC_OFFSET previousTraveledTime = 0x160; //float
        STATIC_OFFSET isRicochet = 0x164; //bool
        STATIC_OFFSET isRetiring = 0x165; //bool
        STATIC_OFFSET flybyPlayed = 0x166; //bool
        STATIC_OFFSET wasFacingPlayer = 0x167; //bool
        STATIC_OFFSET flybyPlane = 0x168; //Plane
        STATIC_OFFSET flybyRay = 0x178; //Ray
        STATIC_OFFSET cleanupAction = 0x190; //Action
        STATIC_OFFSET hitTest = 0x198; //HitTest
        STATIC_OFFSET swimRandom = 0x1A0; //float
    }
    namespace ItemModProjectile
    {
        STATIC_OFFSET projectileObject = 0x18; //GameObjectRef
        STATIC_OFFSET mods = 0x20; //ItemModProjectileMod[]
        STATIC_OFFSET ammoType = 0x28; //AmmoTypes
        STATIC_OFFSET numProjectiles = 0x2C; //int
        STATIC_OFFSET projectileSpread = 0x30; //float
        STATIC_OFFSET projectileVelocity = 0x34; //float
        STATIC_OFFSET projectileVelocitySpread = 0x38; //float
        STATIC_OFFSET useCurve = 0x3C; //bool
        STATIC_OFFSET spreadScalar = 0x40; //AnimationCurve
        STATIC_OFFSET attackEffectOverride = 0x48; //GameObjectRef
        STATIC_OFFSET barrelConditionLoss = 0x50; //float
        STATIC_OFFSET category = 0x58; //string
    }
    namespace HitTest
    {
        STATIC_OFFSET type = 0x10; //HitTest.Type
        STATIC_OFFSET AttackRay = 0x14; //Ray
        STATIC_OFFSET Radius = 0x2C; //float
        STATIC_OFFSET Forgiveness = 0x30; //float
        STATIC_OFFSET MaxDistance = 0x34; //float
        STATIC_OFFSET RayHit = 0x38; //RaycastHit
        STATIC_OFFSET MultiHit = 0x64; //bool
        STATIC_OFFSET BestHit = 0x65; //bool
        STATIC_OFFSET DidHit = 0x66; //bool
        STATIC_OFFSET damageProperties = 0x68; //DamageProperties
        STATIC_OFFSET gameObject = 0x70; //GameObject
        STATIC_OFFSET collider = 0x78; //Collider
        STATIC_OFFSET ignoreEntity = 0x80; //BaseEntity
        STATIC_OFFSET HitEntity = 0x88; //BaseEntity
        STATIC_OFFSET HitPoint = 0x90; //Vector3
        STATIC_OFFSET HitNormal = 0x9C; //Vector3
        STATIC_OFFSET HitDistance = 0xA8; //float
        STATIC_OFFSET HitTransform = 0xB0; //Transform
        STATIC_OFFSET HitPart = 0xB8; //uint
        STATIC_OFFSET HitMaterial = 0xC0; //string
    }
    namespace ProjectileWeaponMod
    {
        STATIC_OFFSET defaultSilencerEffect = 0x168; //GameObjectRef
        STATIC_OFFSET isSilencer = 0x170; //bool
        STATIC_OFFSET repeatDelay = 0x174; //ProjectileWeaponMod.Modifier
        STATIC_OFFSET projectileVelocity = 0x180; //ProjectileWeaponMod.Modifier
        STATIC_OFFSET projectileDamage = 0x18C; //ProjectileWeaponMod.Modifier
        STATIC_OFFSET projectileDistance = 0x198; //ProjectileWeaponMod.Modifier
        STATIC_OFFSET aimsway = 0x1A4; //ProjectileWeaponMod.Modifier
        STATIC_OFFSET aimswaySpeed = 0x1B0; //ProjectileWeaponMod.Modifier
        STATIC_OFFSET recoil = 0x1BC; //ProjectileWeaponMod.Modifier
        STATIC_OFFSET sightAimCone = 0x1C8; //ProjectileWeaponMod.Modifier
        STATIC_OFFSET hipAimCone = 0x1D4; //ProjectileWeaponMod.Modifier
        STATIC_OFFSET isLight = 0x1E0; //bool
        STATIC_OFFSET isMuzzleBrake = 0x1E1; //bool
        STATIC_OFFSET isMuzzleBoost = 0x1E2; //bool
        STATIC_OFFSET isScope = 0x1E3; //bool
        STATIC_OFFSET zoomAmountDisplayOnly = 0x1E4; //float
        STATIC_OFFSET magazineCapacity = 0x1E8; //ProjectileWeaponMod.Modifier
        STATIC_OFFSET needsOnForEffects = 0x1F4; //bool
        STATIC_OFFSET burstCount = 0x1F8; //int
        STATIC_OFFSET timeBetweenBursts = 0x1FC; //float
    }
    namespace BaseProjectile_Magazine
    {
        STATIC_OFFSET definition = 0x10; //BaseProjectile.Magazine.Definition
        STATIC_OFFSET capacity = 0x18; //int
        STATIC_OFFSET contents = 0x1C; //int
        STATIC_OFFSET ammoType = 0x20; //ItemDefinition
    }
    namespace BowWeapon
    {
        STATIC_OFFSET attackReady = 0x3A0; //bool
        STATIC_OFFSET arrowBack = 0x3A4; //float
        STATIC_OFFSET swapArrows = 0x3A8; //SwapArrows
        STATIC_OFFSET wasAiming = 0x3B0; //bool
    }
    namespace CompoundBowWeapon
    {
        STATIC_OFFSET stringHoldDurationMax = 0x3B8; //float
        STATIC_OFFSET stringBonusDamage = 0x3BC; //float
        STATIC_OFFSET stringBonusDistance = 0x3C0; //float
        STATIC_OFFSET stringBonusVelocity = 0x3C4; //float
        STATIC_OFFSET movementPenaltyRampUpTime = 0x3C8; //float
        STATIC_OFFSET conditionLossPerSecondHeld = 0x3CC; //float
        STATIC_OFFSET conditionLossHeldDelay = 0x3D0; //float
        STATIC_OFFSET chargeUpSoundDef = 0x3D8; //SoundDefinition
        STATIC_OFFSET stringHeldSoundDef = 0x3E0; //SoundDefinition
        STATIC_OFFSET drawFinishSoundDef = 0x3E8; //SoundDefinition
        STATIC_OFFSET chargeUpSound = 0x3F0; //Sound
        STATIC_OFFSET stringHeldSound = 0x3F8; //Sound
        STATIC_OFFSET movementPenalty = 0x400; //float
        STATIC_OFFSET lastMoveTime = 0x404; //float
        STATIC_OFFSET currentHoldProgress = 0x408; //float
        STATIC_OFFSET stringHoldTimeStart = 0x40C; //float
        STATIC_OFFSET drawFinishPlayed = 0x410; //bool
    }
    namespace FlintStrikeWeapon
    {
        STATIC_OFFSET successFraction = 0x3A0; //float
        STATIC_OFFSET strikeRecoil = 0x3A8; //RecoilProperties
        STATIC_OFFSET _didSparkThisFrame = 0x3B0; //bool
        STATIC_OFFSET _isStriking = 0x3B1; //bool
        STATIC_OFFSET strikes = 0x3B4; //int
        STATIC_OFFSET lastSpectatorAttack = 0x3B8; //TimeSince
    }
    namespace BaseMelee
    {
        STATIC_OFFSET damageProperties = 0x280; //DamageProperties
        STATIC_OFFSET damageTypes = 0x288; //List<DamageTypeEntry>
        STATIC_OFFSET maxDistance = 0x290; //float
        STATIC_OFFSET attackRadius = 0x294; //float
        STATIC_OFFSET isAutomatic = 0x298; //bool
        STATIC_OFFSET blockSprintOnAttack = 0x299; //bool
        STATIC_OFFSET strikeFX = 0x2A0; //GameObjectRef
        STATIC_OFFSET useStandardHitEffects = 0x2A8; //bool
        STATIC_OFFSET aiStrikeDelay = 0x2AC; //float
        STATIC_OFFSET swingEffect = 0x2B0; //GameObjectRef
        STATIC_OFFSET materialStrikeFX = 0x2B8; //List<BaseMelee.MaterialFX>
        STATIC_OFFSET heartStress = 0x2C0; //float
        STATIC_OFFSET gathering = 0x2C8; //ResourceDispenser.GatherProperties
        STATIC_OFFSET throwReady = 0x2D0; //bool
        STATIC_OFFSET canThrowAsProjectile = 0x2D1; //bool
        STATIC_OFFSET canAiHearIt = 0x2D2; //bool
        STATIC_OFFSET onlyThrowAsProjectile = 0x2D3; //bool
    }
    namespace BaseHelicopter
    {
        STATIC_OFFSET rotorPivot = 0x240; //GameObject
        STATIC_OFFSET mainRotor = 0x248; //GameObject
        STATIC_OFFSET mainRotor_blades = 0x250; //GameObject
        STATIC_OFFSET mainRotor_blur = 0x258; //GameObject
        STATIC_OFFSET tailRotor = 0x260; //GameObject
        STATIC_OFFSET tailRotor_blades = 0x268; //GameObject
        STATIC_OFFSET tailRotor_blur = 0x270; //GameObject
        STATIC_OFFSET rocket_tube_left = 0x278; //GameObject
        STATIC_OFFSET rocket_tube_right = 0x280; //GameObject
        STATIC_OFFSET left_gun_yaw = 0x288; //GameObject
        STATIC_OFFSET left_gun_pitch = 0x290; //GameObject
        STATIC_OFFSET left_gun_muzzle = 0x298; //GameObject
        STATIC_OFFSET right_gun_yaw = 0x2A0; //GameObject
        STATIC_OFFSET right_gun_pitch = 0x2A8; //GameObject
        STATIC_OFFSET right_gun_muzzle = 0x2B0; //GameObject
        STATIC_OFFSET spotlight_rotation = 0x2B8; //GameObject
        STATIC_OFFSET rocket_fire_effect = 0x2C0; //GameObjectRef
        STATIC_OFFSET gun_fire_effect = 0x2C8; //GameObjectRef
        STATIC_OFFSET bulletEffect = 0x2D0; //GameObjectRef
        STATIC_OFFSET explosionEffect = 0x2D8; //GameObjectRef
        STATIC_OFFSET fireBall = 0x2E0; //GameObjectRef
        STATIC_OFFSET crateToDrop = 0x2E8; //GameObjectRef
        STATIC_OFFSET maxCratesToSpawn = 0x2F0; //int
        STATIC_OFFSET bulletSpeed = 0x2F4; //float
        STATIC_OFFSET bulletDamage = 0x2F8; //float
        STATIC_OFFSET servergibs = 0x300; //GameObjectRef
        STATIC_OFFSET debrisFieldMarker = 0x308; //GameObjectRef
        STATIC_OFFSET rotorWashSoundDef = 0x310; //SoundDefinition
        STATIC_OFFSET _rotorWashSound = 0x318; //Sound
        STATIC_OFFSET flightEngineSoundDef = 0x320; //SoundDefinition
        STATIC_OFFSET flightThwopsSoundDef = 0x328; //SoundDefinition
        STATIC_OFFSET flightEngineSound = 0x330; //Sound
        STATIC_OFFSET flightThwopsSound = 0x338; //Sound
        STATIC_OFFSET flightEngineGainMod = 0x340; //SoundModulation.Modulator
        STATIC_OFFSET flightThwopsGainMod = 0x348; //SoundModulation.Modulator
        STATIC_OFFSET rotorGainModSmoothing = 0x350; //float
        STATIC_OFFSET engineGainMin = 0x354; //float
        STATIC_OFFSET engineGainMax = 0x358; //float
        STATIC_OFFSET thwopGainMin = 0x35C; //float
        STATIC_OFFSET thwopGainMax = 0x360; //float
        STATIC_OFFSET spotlightJitterAmount = 0x364; //float
        STATIC_OFFSET spotlightJitterSpeed = 0x368; //float
        STATIC_OFFSET nightLights = 0x370; //GameObject[]
        STATIC_OFFSET spotlightTarget = 0x378; //Vector3
        STATIC_OFFSET engineSpeed = 0x384; //float
        STATIC_OFFSET targetEngineSpeed = 0x388; //float
        STATIC_OFFSET blur_rotationScale = 0x38C; //float
        STATIC_OFFSET _rotorWashParticles = 0x390; //ParticleSystem[]
        STATIC_OFFSET myAI = 0x398; //PatrolHelicopterAI
        STATIC_OFFSET mapMarkerEntityPrefab = 0x3A0; //GameObjectRef
        STATIC_OFFSET client_rotorPivotIdeal = 0x3A8; //Quaternion
        STATIC_OFFSET nightLightsOn = 0x3B8; //bool
        STATIC_OFFSET weakspots = 0x3C0; //BaseHelicopter.weakspot[]
    }
    namespace BaseHelicopter_weakspot
    {
        STATIC_OFFSET body = 0x10; //BaseHelicopter
        STATIC_OFFSET bonenames = 0x18; //string[]
        STATIC_OFFSET maxHealth = 0x20; //float
        STATIC_OFFSET health = 0x24; //float
        STATIC_OFFSET healthFractionOnDestroyed = 0x28; //float
        STATIC_OFFSET destroyedParticles = 0x30; //GameObjectRef
        STATIC_OFFSET damagedParticles = 0x38; //GameObjectRef
        STATIC_OFFSET damagedEffect = 0x40; //GameObject
        STATIC_OFFSET destroyedEffect = 0x48; //GameObject
        STATIC_OFFSET attackers = 0x50; //List<BasePlayer>
    }
    namespace BuildingPrivlidge
    {
        STATIC_OFFSET authorizedPlayers = 0x588; //List<PlayerNameID>
        STATIC_OFFSET allowedConstructionItems = 0x590; //List<ItemDefinition>
        STATIC_OFFSET cachedProtectedMinutes = 0x598; //float
        STATIC_OFFSET cachedUpkeepPeriodMinutes = 0x59C; //float
        STATIC_OFFSET cachedUpkeepCostFraction = 0x5A0; //float
    }
    namespace AutoTurret
    {
        STATIC_OFFSET gun_fire_effect = 0x638; //GameObjectRef
        STATIC_OFFSET bulletEffect = 0x640; //GameObjectRef
        STATIC_OFFSET bulletSpeed = 0x648; //float
        STATIC_OFFSET ambienceEmitter = 0x650; //AmbienceEmitter
        STATIC_OFFSET assignDialog = 0x658; //GameObject
        STATIC_OFFSET turnSoundModulator = 0x660; //SoundModulation.Modulator
        STATIC_OFFSET turnLoop = 0x668; //Sound
        STATIC_OFFSET nextFocusSound = 0x670; //float
        STATIC_OFFSET wasTurning = 0x674; //bool
        STATIC_OFFSET lastYaw = 0x678; //Quaternion
        STATIC_OFFSET target = 0x688; //BaseCombatEntity
        STATIC_OFFSET eyePos = 0x690; //Transform
        STATIC_OFFSET muzzlePos = 0x698; //Transform
        STATIC_OFFSET aimDir = 0x6A0; //Vector3
        STATIC_OFFSET gun_yaw = 0x6B0; //Transform
        STATIC_OFFSET gun_pitch = 0x6B8; //Transform
        STATIC_OFFSET sightRange = 0x6C0; //float
        STATIC_OFFSET turnLoopDef = 0x6C8; //SoundDefinition
        STATIC_OFFSET movementChangeDef = 0x6D0; //SoundDefinition
        STATIC_OFFSET ambientLoopDef = 0x6D8; //SoundDefinition
        STATIC_OFFSET focusCameraDef = 0x6E0; //SoundDefinition
        STATIC_OFFSET focusSoundFreqMin = 0x6E8; //float
        STATIC_OFFSET focusSoundFreqMax = 0x6EC; //float
        STATIC_OFFSET peacekeeperToggleSound = 0x6F0; //GameObjectRef
        STATIC_OFFSET onlineSound = 0x6F8; //GameObjectRef
        STATIC_OFFSET offlineSound = 0x700; //GameObjectRef
        STATIC_OFFSET targetAcquiredEffect = 0x708; //GameObjectRef
        STATIC_OFFSET targetLostEffect = 0x710; //GameObjectRef
        STATIC_OFFSET reloadEffect = 0x718; //GameObjectRef
        STATIC_OFFSET aimCone = 0x720; //float
        STATIC_OFFSET authorizedPlayers = 0x728; //List<PlayerNameID>
        STATIC_OFFSET playerController = 0x730; //BasePlayer
        STATIC_OFFSET rcIdentifier = 0x738; //string
        STATIC_OFFSET initialAimDir = 0x740; //Vector3
        STATIC_OFFSET rcTurnSensitivity = 0x74C; //float
        STATIC_OFFSET RCEyes = 0x750; //Transform
        STATIC_OFFSET targetTrigger = 0x758; //TargetTrigger
        STATIC_OFFSET socketTransform = 0x760; //Transform
    }
    namespace PlayerInventory
    {
        STATIC_OFFSET containerMain = 0x20; //ItemContainer
        STATIC_OFFSET containerBelt = 0x28; //ItemContainer
        STATIC_OFFSET containerWear = 0x30; //ItemContainer
        STATIC_OFFSET crafting = 0x38; //ItemCrafter
        STATIC_OFFSET loot = 0x40; //PlayerLoot
    }
    namespace WorldItem
    {
        STATIC_OFFSET allowPickup = 0x168; //bool
        STATIC_OFFSET item = 0x170; //Item
    }
    namespace DroppedItem
    {
        STATIC_OFFSET itemModel = 0x178; //GameObject
        STATIC_OFFSET childCollider = 0x180; //Collider
    }
    namespace DroppedItemContainer
    {
        STATIC_OFFSET lootPanelName = 0x298; //string
        STATIC_OFFSET maxItemCount = 0x2A0; //int
        STATIC_OFFSET playerSteamID = 0x2A8; //ulong
        STATIC_OFFSET _playerName = 0x2B0; //string
        STATIC_OFFSET ItemBasedDespawn = 0x2B8; //bool
        STATIC_OFFSET onlyOwnerLoot = 0x2B9; //bool
        STATIC_OFFSET openSound = 0x2C0; //SoundDefinition
        STATIC_OFFSET closeSound = 0x2C8; //SoundDefinition
    }
    namespace HackableLockedCrate
    {
        STATIC_OFFSET timerText = 0x470; //Text
        STATIC_OFFSET hackProgressBeep = 0x478; //SoundPlayer
        STATIC_OFFSET hackSeconds = 0x480; //float
        STATIC_OFFSET shockEffect = 0x488; //GameObjectRef
        STATIC_OFFSET mapMarkerEntityPrefab = 0x490; //GameObjectRef
        STATIC_OFFSET landEffect = 0x498; //GameObjectRef
        STATIC_OFFSET shouldDecay = 0x4A0; //bool
        STATIC_OFFSET beepSeconds = 0x4A4; //int
    }
    namespace ItemDefinition
    {
        STATIC_OFFSET itemid = 0x18; //int
        STATIC_OFFSET shortname = 0x20; //string
        STATIC_OFFSET displayName = 0x28; //Translate.Phrase
        STATIC_OFFSET displayDescription = 0x30; //Translate.Phrase
        STATIC_OFFSET iconSprite = 0x38; //Sprite
        STATIC_OFFSET category = 0x40; //ItemCategory
        STATIC_OFFSET selectionPanel = 0x44; //ItemSelectionPanel
        STATIC_OFFSET maxDraggable = 0x48; //int
        STATIC_OFFSET itemType = 0x4C; //ItemContainer.ContentsType
        STATIC_OFFSET amountType = 0x50; //ItemDefinition.AmountType
        STATIC_OFFSET occupySlots = 0x54; //ItemSlot
        STATIC_OFFSET stackable = 0x58; //int
        STATIC_OFFSET quickDespawn = 0x5C; //bool
        STATIC_OFFSET rarity = 0x60; //Rarity
        STATIC_OFFSET despawnRarity = 0x64; //Rarity
        STATIC_OFFSET spawnAsBlueprint = 0x68; //bool
        STATIC_OFFSET inventoryGrabSound = 0x70; //SoundDefinition
        STATIC_OFFSET inventoryDropSound = 0x78; //SoundDefinition
        STATIC_OFFSET physImpactSoundDef = 0x80; //SoundDefinition
        STATIC_OFFSET condition = 0x88; //ItemDefinition.Condition
        STATIC_OFFSET hidden = 0xA0; //bool
        STATIC_OFFSET flags = 0xA4; //ItemDefinition.Flag
        STATIC_OFFSET steamItem = 0xA8; //SteamInventoryItem
        STATIC_OFFSET steamDlc = 0xB0; //SteamDLCItem
        STATIC_OFFSET Parent = 0xB8; //ItemDefinition
        STATIC_OFFSET worldModelPrefab = 0xC0; //GameObjectRef
        STATIC_OFFSET isRedirectOf = 0xC8; //ItemDefinition
        STATIC_OFFSET redirectVendingBehaviour = 0xD0; //ItemDefinition.RedirectVendingBehaviour
        STATIC_OFFSET itemMods = 0xD8; //ItemMod[]
        STATIC_OFFSET Traits = 0xE0; //BaseEntity.TraitFlag
        STATIC_OFFSET skins = 0xE8; //ItemSkinDirectory.Skin[]
        STATIC_OFFSET _skins2 = 0xF0; //IPlayerItemDefinition[]
        STATIC_OFFSET panel = 0xF8; //GameObject
        STATIC_OFFSET ItemModWearable__BackingField = 0x100; //ItemModWearable
        STATIC_OFFSET isHoldable__BackingField = 0x108; //bool
        STATIC_OFFSET isUsable__BackingField = 0x109; //bool
        STATIC_OFFSET CraftableWithSkin__BackingField = 0x10A; //bool
        STATIC_OFFSET Children = 0x110; //ItemDefinition[]
    }
    namespace ItemContainer
    {
        STATIC_OFFSET UID = 0x10; //uint
        STATIC_OFFSET slots = 0x14; //int
        STATIC_OFFSET temperature = 0x18; //float
        STATIC_OFFSET flags = 0x1C; //int
        STATIC_OFFSET allowedContents = 0x20; //int
        STATIC_OFFSET maxStackSize = 0x24; //int
        STATIC_OFFSET allowedItems = 0x28; //List<int>
        STATIC_OFFSET availableSlots = 0x30; //List<int>
        STATIC_OFFSET contents = 0x38; //List<Item>
        STATIC_OFFSET ShouldPool = 0x40; //bool
        STATIC_OFFSET _disposed = 0x41; //bool
    }
    namespace PlayerNameID
    {
        STATIC_OFFSET username = 0x10; //string
        STATIC_OFFSET userid = 0x18; //ulong
        STATIC_OFFSET ShouldPool = 0x20; //bool
        STATIC_OFFSET _disposed = 0x21; //bool
    }
    namespace PlayerTick
    {
        STATIC_OFFSET inputState = 0x10; //InputMessage
        STATIC_OFFSET position = 0x18; //Vector3
        STATIC_OFFSET modelState = 0x28; //ModelState
        STATIC_OFFSET activeItem = 0x30; //uint
        STATIC_OFFSET eyePos = 0x34; //Vector3
        STATIC_OFFSET parentID = 0x40; //uint
        STATIC_OFFSET deltaMs = 0x44; //uint
        STATIC_OFFSET ShouldPool = 0x48; //bool
        STATIC_OFFSET _disposed = 0x49; //bool
    }
    namespace TOD_Sky
    {
        STATIC_OFFSET ColorSpace = 0x18; //TOD_ColorSpaceType
        STATIC_OFFSET ColorRange = 0x1C; //TOD_ColorRangeType
        STATIC_OFFSET ColorOutput = 0x20; //TOD_ColorOutputType
        STATIC_OFFSET SkyQuality = 0x24; //TOD_SkyQualityType
        STATIC_OFFSET CloudQuality = 0x28; //TOD_CloudQualityType
        STATIC_OFFSET MeshQuality = 0x2C; //TOD_MeshQualityType
        STATIC_OFFSET StarQuality = 0x30; //TOD_StarQualityType
        STATIC_OFFSET Cycle = 0x38; //TOD_CycleParameters
        STATIC_OFFSET World = 0x40; //TOD_WorldParameters
        STATIC_OFFSET Atmosphere = 0x48; //TOD_AtmosphereParameters
        STATIC_OFFSET Day = 0x50; //TOD_DayParameters
        STATIC_OFFSET Night = 0x58; //TOD_NightParameters
        STATIC_OFFSET Sun = 0x60; //TOD_SunParameters
        STATIC_OFFSET Moon = 0x68; //TOD_MoonParameters
        STATIC_OFFSET Stars = 0x70; //TOD_StarParameters
        STATIC_OFFSET Clouds = 0x78; //TOD_CloudParameters
        STATIC_OFFSET Light = 0x80; //TOD_LightParameters
        STATIC_OFFSET Fog = 0x88; //TOD_FogParameters
        STATIC_OFFSET Ambient = 0x90; //TOD_AmbientParameters
        STATIC_OFFSET Reflection = 0x98; //TOD_ReflectionParameters
        STATIC_OFFSET Initialized__BackingField = 0xA0; //bool
        STATIC_OFFSET Components__BackingField = 0xA8; //TOD_Components
        STATIC_OFFSET Resources__BackingField = 0xB0; //TOD_Resources
        STATIC_OFFSET IsDay__BackingField = 0xB8; //bool
        STATIC_OFFSET IsNight__BackingField = 0xB9; //bool
        STATIC_OFFSET LerpValue__BackingField = 0xBC; //float
        STATIC_OFFSET SunZenith__BackingField = 0xC0; //float
        STATIC_OFFSET SunAltitude__BackingField = 0xC4; //float
        STATIC_OFFSET SunAzimuth__BackingField = 0xC8; //float
        STATIC_OFFSET MoonZenith__BackingField = 0xCC; //float
        STATIC_OFFSET MoonAltitude__BackingField = 0xD0; //float
        STATIC_OFFSET MoonAzimuth__BackingField = 0xD4; //float
        STATIC_OFFSET SunsetTime__BackingField = 0xD8; //float
        STATIC_OFFSET SunriseTime__BackingField = 0xDC; //float
        STATIC_OFFSET LocalSiderealTime__BackingField = 0xE0; //float
        STATIC_OFFSET SunVisibility__BackingField = 0xE4; //float
        STATIC_OFFSET MoonVisibility__BackingField = 0xE8; //float
        STATIC_OFFSET SunDirection__BackingField = 0xEC; //Vector3
        STATIC_OFFSET MoonDirection__BackingField = 0xF8; //Vector3
        STATIC_OFFSET LightDirection__BackingField = 0x104; //Vector3
        STATIC_OFFSET LocalSunDirection__BackingField = 0x110; //Vector3
        STATIC_OFFSET LocalMoonDirection__BackingField = 0x11C; //Vector3
        STATIC_OFFSET LocalLightDirection__BackingField = 0x128; //Vector3
        STATIC_OFFSET SunLightColor__BackingField = 0x134; //Color
        STATIC_OFFSET MoonLightColor__BackingField = 0x144; //Color
        STATIC_OFFSET SunRayColor__BackingField = 0x154; //Color
        STATIC_OFFSET MoonRayColor__BackingField = 0x164; //Color
        STATIC_OFFSET SunSkyColor__BackingField = 0x174; //Color
        STATIC_OFFSET MoonSkyColor__BackingField = 0x184; //Color
        STATIC_OFFSET SunMeshColor__BackingField = 0x194; //Color
        STATIC_OFFSET MoonMeshColor__BackingField = 0x1A4; //Color
        STATIC_OFFSET SunCloudColor__BackingField = 0x1B4; //Color
        STATIC_OFFSET MoonCloudColor__BackingField = 0x1C4; //Color
        STATIC_OFFSET FogColor__BackingField = 0x1D4; //Color
        STATIC_OFFSET GroundColor__BackingField = 0x1E4; //Color
        STATIC_OFFSET AmbientColor__BackingField = 0x1F4; //Color
        STATIC_OFFSET MoonHaloColor__BackingField = 0x204; //Color
        STATIC_OFFSET ReflectionCur = 0x218; //TOD_Sky.ReflectionProbeState
        STATIC_OFFSET ReflectionSrc = 0x220; //TOD_Sky.ReflectionProbeState
        STATIC_OFFSET ReflectionDst = 0x228; //TOD_Sky.ReflectionProbeState
        STATIC_OFFSET timeSinceLightUpdate = 0x230; //float
        STATIC_OFFSET timeSinceAmbientUpdate = 0x234; //float
        STATIC_OFFSET timeSinceReflectionUpdate = 0x238; //float
        STATIC_OFFSET kBetaMie = 0x23C; //Vector3
        STATIC_OFFSET kSun = 0x248; //Vector4
        STATIC_OFFSET k4PI = 0x258; //Vector4
        STATIC_OFFSET kRadius = 0x268; //Vector4
        STATIC_OFFSET kScale = 0x278; //Vector4
    }
    namespace TOD_Components
    {
        STATIC_OFFSET Space = 0x18; //GameObject
        STATIC_OFFSET Stars = 0x20; //GameObject
        STATIC_OFFSET Sun = 0x28; //GameObject
        STATIC_OFFSET Moon = 0x30; //GameObject
        STATIC_OFFSET Atmosphere = 0x38; //GameObject
        STATIC_OFFSET Clear = 0x40; //GameObject
        STATIC_OFFSET Clouds = 0x48; //GameObject
        STATIC_OFFSET Billboards = 0x50; //GameObject
        STATIC_OFFSET Light = 0x58; //GameObject
        STATIC_OFFSET DomeTransform__BackingField = 0x60; //Transform
        STATIC_OFFSET SpaceTransform__BackingField = 0x68; //Transform
        STATIC_OFFSET StarTransform__BackingField = 0x70; //Transform
        STATIC_OFFSET SunTransform__BackingField = 0x78; //Transform
        STATIC_OFFSET MoonTransform__BackingField = 0x80; //Transform
        STATIC_OFFSET AtmosphereTransform__BackingField = 0x88; //Transform
        STATIC_OFFSET ClearTransform__BackingField = 0x90; //Transform
        STATIC_OFFSET CloudTransform__BackingField = 0x98; //Transform
        STATIC_OFFSET BillboardTransform__BackingField = 0xA0; //Transform
        STATIC_OFFSET LightTransform__BackingField = 0xA8; //Transform
        STATIC_OFFSET SpaceRenderer__BackingField = 0xB0; //Renderer
        STATIC_OFFSET StarRenderer__BackingField = 0xB8; //Renderer
        STATIC_OFFSET SunRenderer__BackingField = 0xC0; //Renderer
        STATIC_OFFSET MoonRenderer__BackingField = 0xC8; //Renderer
        STATIC_OFFSET AtmosphereRenderer__BackingField = 0xD0; //Renderer
        STATIC_OFFSET ClearRenderer__BackingField = 0xD8; //Renderer
        STATIC_OFFSET CloudRenderer__BackingField = 0xE0; //Renderer
        STATIC_OFFSET BillboardRenderers__BackingField = 0xE8; //Renderer[]
        STATIC_OFFSET SpaceMeshFilter__BackingField = 0xF0; //MeshFilter
        STATIC_OFFSET StarMeshFilter__BackingField = 0xF8; //MeshFilter
        STATIC_OFFSET SunMeshFilter__BackingField = 0x100; //MeshFilter
        STATIC_OFFSET MoonMeshFilter__BackingField = 0x108; //MeshFilter
        STATIC_OFFSET AtmosphereMeshFilter__BackingField = 0x110; //MeshFilter
        STATIC_OFFSET ClearMeshFilter__BackingField = 0x118; //MeshFilter
        STATIC_OFFSET CloudMeshFilter__BackingField = 0x120; //MeshFilter
        STATIC_OFFSET BillboardMeshFilters__BackingField = 0x128; //MeshFilter[]
        STATIC_OFFSET SpaceMaterial__BackingField = 0x130; //Material
        STATIC_OFFSET StarMaterial__BackingField = 0x138; //Material
        STATIC_OFFSET SunMaterial__BackingField = 0x140; //Material
        STATIC_OFFSET MoonMaterial__BackingField = 0x148; //Material
        STATIC_OFFSET AtmosphereMaterial__BackingField = 0x150; //Material
        STATIC_OFFSET ClearMaterial__BackingField = 0x158; //Material
        STATIC_OFFSET CloudMaterial__BackingField = 0x160; //Material
        STATIC_OFFSET BillboardMaterials__BackingField = 0x168; //Material[]
        STATIC_OFFSET LightSource__BackingField = 0x170; //Light
        STATIC_OFFSET Sky__BackingField = 0x178; //TOD_Sky
        STATIC_OFFSET Animation__BackingField = 0x180; //TOD_Animation
        STATIC_OFFSET Time__BackingField = 0x188; //TOD_Time
        STATIC_OFFSET Camera__BackingField = 0x190; //TOD_Camera
        STATIC_OFFSET Rays__BackingField = 0x198; //TOD_Rays
        STATIC_OFFSET Scattering__BackingField = 0x1A0; //TOD_Scattering
        STATIC_OFFSET Shadows__BackingField = 0x1A8; //TOD_Shadows
    }
    namespace TOD_Scattering
    {
        STATIC_OFFSET ScatteringShader = 0x30; //Shader
        STATIC_OFFSET ScreenClearShader = 0x38; //Shader
        STATIC_OFFSET SkyMaskShader = 0x40; //Shader
        STATIC_OFFSET DitheringTexture = 0x48; //Texture2D
        STATIC_OFFSET SinglePass = 0x50; //bool
        STATIC_OFFSET GlobalDensity = 0x54; //float
        STATIC_OFFSET HeightFalloff = 0x58; //float
        STATIC_OFFSET StartDistance = 0x5C; //float
        STATIC_OFFSET ZeroLevel = 0x60; //float
        STATIC_OFFSET Resolution = 0x64; //TOD_ImageEffect.ResolutionType
        STATIC_OFFSET BlurIterations = 0x68; //int
        STATIC_OFFSET BlurRadius = 0x6C; //float
        STATIC_OFFSET MaxRadius = 0x70; //float
        STATIC_OFFSET scatteringMaterial = 0x78; //Material
        STATIC_OFFSET screenClearMaterial = 0x80; //Material
        STATIC_OFFSET skyMaskMaterial = 0x88; //Material
    }
    namespace TOD_DayParameters
    {
        STATIC_OFFSET SunColor = 0x10; //Gradient
        STATIC_OFFSET LightColor = 0x18; //Gradient
        STATIC_OFFSET RayColor = 0x20; //Gradient
        STATIC_OFFSET SkyColor = 0x28; //Gradient
        STATIC_OFFSET CloudColor = 0x30; //Gradient
        STATIC_OFFSET FogColor = 0x38; //Gradient
        STATIC_OFFSET AmbientColor = 0x40; //Gradient
        STATIC_OFFSET LightIntensity = 0x48; //float
        STATIC_OFFSET ShadowStrength = 0x4C; //float
        STATIC_OFFSET AmbientMultiplier = 0x50; //float
        STATIC_OFFSET ReflectionMultiplier = 0x54; //float
    }
    namespace TOD_AmbientParameters
    {
        STATIC_OFFSET Mode = 0x10; // TOD_AmbientType
        STATIC_OFFSET Saturation = 0x14; // float
        STATIC_OFFSET UpdateInterval = 0x18; // float
    }
    namespace TOD_CycleParameters
    {
        STATIC_OFFSET Hour = 0x10; // float
        STATIC_OFFSET Day = 0x14; // int
        STATIC_OFFSET Month = 0x18; // int
        STATIC_OFFSET Year = 0x1c; // int
    }
    namespace OutlineManager
    {
        STATIC_OFFSET objectsToRender = 0x18; //List<OutlineObject>
        STATIC_OFFSET blurAmount = 0x20; //float
        STATIC_OFFSET glowSolidMaterial = 0x28; //Material
        STATIC_OFFSET blendGlowMaterial = 0x30; //Material
        STATIC_OFFSET nextUpdateTime = 0x38; //float
    }
    namespace Skinnable
    {
        STATIC_OFFSET Name = 0x18; //string
        STATIC_OFFSET ItemName = 0x20; //string
        STATIC_OFFSET EntityPrefab = 0x28; //GameObject
        STATIC_OFFSET EntityPrefabName = 0x30; //string
        STATIC_OFFSET ViewmodelPrefab = 0x38; //GameObject
        STATIC_OFFSET ViewmodelPrefabName = 0x40; //string
        STATIC_OFFSET MeshDownloads = 0x48; //Mesh[]
        STATIC_OFFSET MeshDownloadPaths = 0x50; //string[]
        STATIC_OFFSET Category = 0x58; //Category
        STATIC_OFFSET HideInWorkshopUpload = 0x5C; //bool
        STATIC_OFFSET Groups = 0x60; //Skinnable.Group[]
        STATIC_OFFSET _sourceMaterials = 0x68; //Material[]
    }
    namespace Skinnable_Group
    {
        STATIC_OFFSET Name = 0x10; //string
        STATIC_OFFSET Material = 0x18; //Material
        STATIC_OFFSET MaxTextureSize = 0x20; //int
    }
    namespace ConsoleSystem_Command
    {
        STATIC_OFFSET Name = 0x10; //string
        STATIC_OFFSET Parent = 0x18; //string
        STATIC_OFFSET FullName = 0x20; //string
        STATIC_OFFSET GetOveride = 0x28; //Func<string>
        STATIC_OFFSET SetOveride = 0x30; //Action<string>
        STATIC_OFFSET Call = 0x38; //Action<ConsoleSystem.Arg>
        STATIC_OFFSET Variable = 0x40; //bool
        STATIC_OFFSET Default = 0x48; //string
        STATIC_OFFSET Saved = 0x50; //bool
        STATIC_OFFSET ServerAdmin = 0x51; //bool
        STATIC_OFFSET ServerUser = 0x52; //bool
        STATIC_OFFSET Replicated = 0x53; //bool
        STATIC_OFFSET ShowInAdminUI = 0x54; //bool
        STATIC_OFFSET ClientAdmin = 0x55; //bool
        STATIC_OFFSET Client = 0x56; //bool
        STATIC_OFFSET ClientInfo = 0x57; //bool
        STATIC_OFFSET AllowRunFromServer = 0x58; //bool
        STATIC_OFFSET Description = 0x60; //string
        STATIC_OFFSET Arguments = 0x68; //string
        STATIC_OFFSET OnValueChanged = 0x70; //Action<ConsoleSystem.Command>
    }
    namespace Effect
    {
        STATIC_OFFSET Up = 0x50; //Vector3
        STATIC_OFFSET worldPos = 0x5C; //Vector3
        STATIC_OFFSET worldNrm = 0x68; //Vector3
        STATIC_OFFSET attached = 0x74; //bool
        STATIC_OFFSET transform = 0x78; //Transform
        STATIC_OFFSET gameObject = 0x80; //GameObject
        STATIC_OFFSET pooledString = 0x88; //string
        STATIC_OFFSET broadcast = 0x90; //bool
    }
    namespace Client
    {
        STATIC_OFFSET Connection__BackingField = 0x28; //Connection
        STATIC_OFFSET visibility = 0x38; //Manager
        STATIC_OFFSET ConnectedAddress__BackingField = 0x40; //string
        STATIC_OFFSET ConnectedPort__BackingField = 0x48; //int
        STATIC_OFFSET ServerName__BackingField = 0x50; //string
        STATIC_OFFSET IsOfficialServer__BackingField = 0x58; //bool
        STATIC_OFFSET IncomingStats = 0x60; //Stats
        STATIC_OFFSET callbackHandler = 0x68; //IClientCallback
    }
    namespace TOD_Rays
    {
        STATIC_OFFSET Rays = 0x198; // backing field
        STATIC_OFFSET GodRayShader = 0x30; // Shader
        STATIC_OFFSET ScreenClearShader = 0x38; // Shader
        STATIC_OFFSET SkyMaskShader = 0x40; // Shader
        STATIC_OFFSET UseDepthTexture = 0x48; // bool
        STATIC_OFFSET BlendMode = 0x4c; // TOD_Rays.BlendModeType
        STATIC_OFFSET Intensity = 0x50; // float
        STATIC_OFFSET Resolution = 0x54; // TOD_ImageEffect.ResolutionType
        STATIC_OFFSET BlurIterations = 0x58; // int
        STATIC_OFFSET BlurRadius = 0x5c; // float
        STATIC_OFFSET MaxRadius = 0x60; // float
        STATIC_OFFSET godRayMaterial = 0x68; // Material
        STATIC_OFFSET screenClearMaterial = 0x70; // Material
        STATIC_OFFSET skyMaskMaterial = 0x78; // Material
    }
}
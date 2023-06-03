struct RUSTPLAYER
{
	uintptr_t instance = NULL;
	uintptr_t head_transform = NULL;
	uintptr_t orgin_ptr = NULL;
	std::string name = "";
	unsigned int name_hash = 0;
	bool is_npc = false;
	bool is_sleeping = false;
	std::pair<float, float> health_info;
};

struct RUSTITEM
{
	uintptr_t instance = NULL;
	uintptr_t position_ptr = NULL;
	Vector3 position = {};
	std::string name = "";
	unsigned int name_hash = 0;
};

struct RUSTRESOURCE
{
	uintptr_t instance = NULL;
	uintptr_t position_ptr = NULL;
	Vector3 position = {};
	std::string name = "";
	unsigned int name_hash = 0;
};

struct RUSTWORLD
{
	uintptr_t instance = NULL;
	Vector3 position = {};
	std::string name = "";
	unsigned int name_hash = 0;
};

struct RGB
{
	float r;
	float g;
	float b;
};

enum OreType : int
{
	stone,
	metal,
	sulfur
};

enum ModelStateFlags : int 
{
	Ducked = 1,
	Jumped = 2,
	OnGround = 4,
	//Sleeping = 8,
	Sprinting = 16,
	OnLadder = 32,
	Flying = 64,
	//Aiming = 128,
	Prone = 256,
	Mounted = 512,
	//Relaxed = 1024,
	OnPhone = 2048,
	Crawling = 4096,
	HeadLook = 16384
};

enum UIBlackoutOverlay : int 
{
	FULLBLACK = 0,
	BINOCULAR = 1,
	SCOPE = 2,
	HELMETSLIT = 3,
	SNORKELGOGGLE = 4,
	NVG = 5,
	FULLWHITE = 6,
	SUNGLASSES = 7,
	NONE = 64
};

enum Layer : uint32_t 
{
	Default = 0,
	TransparentFX = 1,
	Ignore_Raycast = 2,
	Reserved1 = 3,
	Water = 4,
	UI = 5,
	Reserved2 = 6,
	Reserved3 = 7,
	Deployed = 8,
	Ragdoll = 9,
	Invisible = 10,
	AI = 11,
	PlayerMovement = 12,
	Vehicle_Detailed = 13,
	Game_Trace = 14,
	Vehicle_World = 15,
	WorldL = 16,
	Player_Server = 17,
	Trigger = 18,
	Player_Model_Rendering = 19,
	Physics_Projectile = 20,
	Construction = 21,
	Construction_Socket = 22,
	Terrain = 23,
	Transparent = 24,
	Clutter = 25,
	Debris = 26,
	Vehicle_Large = 27,
	Prevent_Movement = 28,
	Prevent_Building = 29,
	Tree = 30,
	Unused3 = 31
};

enum CameraMode : int 
{
	FirstPerson = 0,
	ThirdPerson = 1,
	Eyes = 2,
	FirstPersonWithArms = 3,
	Last = 3
};

enum PlayerFlags : int 
{
	Unused1 = 1,
	Unused2 = 2,
	IsAdmin = 4,
	ReceivingSnapshot = 8,
	Sleeping = 16,
	Spectating = 32,
	Wounded = 64,
	IsDeveloper = 128,
	Connected = 256,
	ThirdPersonViewmode = 1024,
	EyesViewmode = 2048,
	ChatMute = 4096,
	NoSprint = 8192,
	Aiming = 16384,
	DisplaySash = 32768,
	Relaxed = 65536,
	SafeZone = 131072,
	ServerFall = 262144,
	Incapacitated = 524288,
	Workbench1 = 1048576,
	Workbench2 = 2097152,
	Workbench3 = 4194304
};

enum BoneList : int
{
	pelvis = 0,
	l_hip = 1,
	l_knee = 2,
	l_foot = 3,
	l_toe = 4,
	l_ankle_scale = 5,
	penis = 6,
	GenitalCensor = 7,
	GenitalCensor_LOD0 = 8,
	Inner_LOD0 = 9,
	GenitalCensor_LOD1 = 11,
	GenitalCensor_LOD2 = 12,
	r_hip = 13,
	r_knee = 14,
	r_foot = 15,
	r_toe = 16,
	r_ankle_scale = 17,
	spine1 = 18,
	spine1_scale = 19,
	spine2 = 20,
	spine3 = 21,
	spine4 = 22,
	l_clavicle = 23,
	l_upperarm = 24,
	l_forearm = 25,
	l_hand = 26,
	l_index1 = 27,
	l_index2 = 28,
	l_index3 = 29,
	l_little1 = 30,
	l_little2 = 31,
	l_little3 = 32,
	l_middle1 = 33,
	l_middle2 = 34,
	l_middle3 = 35,
	l_prop = 36,
	l_ring1 = 37,
	l_ring2 = 38,
	l_ring3 = 39,
	l_thumb1 = 40,
	l_thumb2 = 41,
	l_thumb3 = 42,
	IKtarget_righthand_min = 43,
	IKtarget_righthand_max = 44,
	l_ulna = 45,
	neck = 46,
	head = 47,
	jaw = 48,
	eyeTranform = 49,
	l_eye = 50,
	l_Eyelid = 51,
	r_eye = 52,
	r_Eyelid = 53,
	r_clavicle = 54,
	r_upperarm = 55,
	r_forearm = 56,
	r_hand = 57,
	r_index1 = 58,
	r_index2 = 59,
	r_index3 = 60,
	r_little1 = 61,
	r_little2 = 62,
	r_little3 = 63,
	r_middle2 = 65,
	r_middle3 = 66,
	r_prop = 67,
	r_ring1 = 68,
	r_ring2 = 69,
	r_ring3 = 70,
	r_thumb1 = 71,
	r_thumb2 = 72,
	r_thumb3 = 73,
	IKtarget_lefthand_min = 74,
	IKtarget_lefthand_max = 75,
	r_ulna = 76,
	l_breast = 77,
	r_breast = 78,
	BoobCensor = 79,
	BreastCensor_LOD0 = 80,
	BreastCensor_LOD1 = 83,
	BreastCensor_LOD2 = 84
};

enum LifeState : int 
{
	Alive = 0,
	Dead = 1
};

enum WeaponType : int
{
	AssultRifle = 1545779598,
	IceAssultRifle = -1335497659,
	Lr300 = -1812555177,
	M249 = -2069578888,
	M39 = -28201841,
	Sar = -904863145,
	HMLMG = -1214542497,
	L96 = -778367295,
	BoltAction = 1588298435,
	CustomSmg = 1796682209,
	Mp5 = 1318558775,
	Thompson = -1758372725,
	Python = 1373971859,
	SemiPistol = 818877484,
	Revolver = 649912614,
	M92 = -852563019,
	Nailgun = 1953903201,
	Eoka = -75944661,
	Spas12 = -41440462,
	PumpShotgun = 795371088,
	WaterPipe = -1367281941,
	DoubleBarrel = -765183617,
	Bow = 1443579727,
	CompoundBow = 884424049,
	CrossBow = 1965232394,
	GrenadeLauncher = -1123473824,
	RocketLauncher = 442886268,
	SnowBallGun = 1103488722,
	FlameThrower = -1215753368,
	JackHammer = 1488979457,
	IcePickaxe = -1780802565,
	MetalPickaxe = -1302129395,
	StonePickaxe = 171931394
};

enum Category
{
	Shirt,
	Pants = 5,
	Jacket = 1,
	Hat,
	Mask,
	Footwear,
	Weaponn = 6,
	Miscc,
	Deployable = 9,
	Gloves
};

enum KeyCode
{
	// Token: 0x04000561 RID: 1377
	None,
	// Token: 0x04000562 RID: 1378
	Backspace = 8,
	// Token: 0x04000563 RID: 1379
	Delete = 127,
	// Token: 0x04000564 RID: 1380
	Tab = 9,
	// Token: 0x04000565 RID: 1381
	Clear = 12,
	// Token: 0x04000566 RID: 1382
	Return,
	// Token: 0x04000567 RID: 1383
	Pause = 19,
	// Token: 0x04000568 RID: 1384
	Escape1 = 27,
	// Token: 0x04000569 RID: 1385
	Space = 32,
	// Token: 0x0400056A RID: 1386
	Keypad0 = 256,
	// Token: 0x0400056B RID: 1387
	Keypad1,
	// Token: 0x0400056C RID: 1388
	Keypad2,
	// Token: 0x0400056D RID: 1389
	Keypad3,
	// Token: 0x0400056E RID: 1390
	Keypad4,
	// Token: 0x0400056F RID: 1391
	Keypad5,
	// Token: 0x04000570 RID: 1392
	Keypad6,
	// Token: 0x04000571 RID: 1393
	Keypad7,
	// Token: 0x04000572 RID: 1394
	Keypad8,
	// Token: 0x04000573 RID: 1395
	Keypad9,
	// Token: 0x04000574 RID: 1396
	KeypadPeriod,
	// Token: 0x04000575 RID: 1397
	KeypadDivide,
	// Token: 0x04000576 RID: 1398
	KeypadMultiply,
	// Token: 0x04000577 RID: 1399
	KeypadMinus,
	// Token: 0x04000578 RID: 1400
	KeypadPlus,
	// Token: 0x04000579 RID: 1401
	KeypadEnter,
	// Token: 0x0400057A RID: 1402
	KeypadEquals,
	// Token: 0x0400057B RID: 1403
	UpArrow,
	// Token: 0x0400057C RID: 1404
	DownArrow,
	// Token: 0x0400057D RID: 1405
	RightArrow,
	// Token: 0x0400057E RID: 1406
	LeftArrow,
	// Token: 0x0400057F RID: 1407
	Insert,
	// Token: 0x04000580 RID: 1408
	Home,
	// Token: 0x04000581 RID: 1409
	End,
	// Token: 0x04000582 RID: 1410
	PageUp,
	// Token: 0x04000583 RID: 1411
	PageDown,
	// Token: 0x04000584 RID: 1412
	F1,
	// Token: 0x04000585 RID: 1413
	F2,
	// Token: 0x04000586 RID: 1414
	F3,
	// Token: 0x04000587 RID: 1415
	F4,
	// Token: 0x04000588 RID: 1416
	F5,
	// Token: 0x04000589 RID: 1417
	F6,
	// Token: 0x0400058A RID: 1418
	F7,
	// Token: 0x0400058B RID: 1419
	F8,
	// Token: 0x0400058C RID: 1420
	F9,
	// Token: 0x0400058D RID: 1421
	F10,
	// Token: 0x0400058E RID: 1422
	F11,
	// Token: 0x0400058F RID: 1423
	F12,
	// Token: 0x04000590 RID: 1424
	F13,
	// Token: 0x04000591 RID: 1425
	F14,
	// Token: 0x04000592 RID: 1426
	F15,
	// Token: 0x04000593 RID: 1427
	Alpha0 = 48,
	// Token: 0x04000594 RID: 1428
	Alpha1,
	// Token: 0x04000595 RID: 1429
	Alpha2,
	// Token: 0x04000596 RID: 1430
	Alpha3,
	// Token: 0x04000597 RID: 1431
	Alpha4,
	// Token: 0x04000598 RID: 1432
	Alpha5,
	// Token: 0x04000599 RID: 1433
	Alpha6,
	// Token: 0x0400059A RID: 1434
	Alpha7,
	// Token: 0x0400059B RID: 1435
	Alpha8,
	// Token: 0x0400059C RID: 1436
	Alpha9,
	// Token: 0x0400059D RID: 1437
	Exclaim = 33,
	// Token: 0x0400059E RID: 1438
	DoubleQuote,
	// Token: 0x0400059F RID: 1439
	Hash,
	// Token: 0x040005A0 RID: 1440
	Dollar,
	// Token: 0x040005A1 RID: 1441
	Percent,
	// Token: 0x040005A2 RID: 1442
	Ampersand,
	// Token: 0x040005A3 RID: 1443
	Quote,
	// Token: 0x040005A4 RID: 1444
	LeftParen,
	// Token: 0x040005A5 RID: 1445
	RightParen,
	// Token: 0x040005A6 RID: 1446
	Asterisk,
	// Token: 0x040005A7 RID: 1447
	Plus,
	// Token: 0x040005A8 RID: 1448
	Comma,
	// Token: 0x040005A9 RID: 1449
	Minus,
	// Token: 0x040005AA RID: 1450
	Period,
	// Token: 0x040005AB RID: 1451
	Slash,
	// Token: 0x040005AC RID: 1452
	Colon = 58,
	// Token: 0x040005AD RID: 1453
	Semicolon,
	// Token: 0x040005AE RID: 1454
	Less,
	// Token: 0x040005AF RID: 1455
	Equals,
	// Token: 0x040005B0 RID: 1456
	Greater,
	// Token: 0x040005B1 RID: 1457
	Question,
	// Token: 0x040005B2 RID: 1458
	At,
	// Token: 0x040005B3 RID: 1459
	LeftBracket = 91,
	// Token: 0x040005B4 RID: 1460
	Backslash,
	// Token: 0x040005B5 RID: 1461
	RightBracket,
	// Token: 0x040005B6 RID: 1462
	Caret,
	// Token: 0x040005B7 RID: 1463
	Underscore,
	// Token: 0x040005B8 RID: 1464
	BackQuote,
	// Token: 0x040005B9 RID: 1465
	A,
	// Token: 0x040005BA RID: 1466
	B,
	// Token: 0x040005BB RID: 1467
	C,
	// Token: 0x040005BC RID: 1468
	D,
	// Token: 0x040005BD RID: 1469
	E,
	// Token: 0x040005BE RID: 1470
	F,
	// Token: 0x040005BF RID: 1471
	G,
	// Token: 0x040005C0 RID: 1472
	H,
	// Token: 0x040005C1 RID: 1473
	I,
	// Token: 0x040005C2 RID: 1474
	J,
	// Token: 0x040005C3 RID: 1475
	K,
	// Token: 0x040005C4 RID: 1476
	L,
	// Token: 0x040005C5 RID: 1477
	M,
	// Token: 0x040005C6 RID: 1478
	N,
	// Token: 0x040005C7 RID: 1479
	O,
	// Token: 0x040005C8 RID: 1480
	P,
	// Token: 0x040005C9 RID: 1481
	Q,
	// Token: 0x040005CA RID: 1482
	R,
	// Token: 0x040005CB RID: 1483
	S,
	// Token: 0x040005CC RID: 1484
	T,
	// Token: 0x040005CD RID: 1485
	U,
	// Token: 0x040005CE RID: 1486
	V,
	// Token: 0x040005CF RID: 1487
	W,
	// Token: 0x040005D0 RID: 1488
	X,
	// Token: 0x040005D1 RID: 1489
	Y,
	// Token: 0x040005D2 RID: 1490
	Z,
	// Token: 0x040005D3 RID: 1491
	LeftCurlyBracket,
	// Token: 0x040005D4 RID: 1492
	Pipe,
	// Token: 0x040005D5 RID: 1493
	RightCurlyBracket,
	// Token: 0x040005D6 RID: 1494
	Tilde,
	// Token: 0x040005D7 RID: 1495
	Numlock = 300,
	// Token: 0x040005D8 RID: 1496
	CapsLock,
	// Token: 0x040005D9 RID: 1497
	ScrollLock,
	// Token: 0x040005DA RID: 1498
	RightShift,
	// Token: 0x040005DB RID: 1499
	LeftShift,
	// Token: 0x040005DC RID: 1500
	RightControl,
	// Token: 0x040005DD RID: 1501
	LeftControl,
	// Token: 0x040005DE RID: 1502
	RightAlt,
	// Token: 0x040005DF RID: 1503
	LeftAlt,
	// Token: 0x040005E0 RID: 1504
	LeftCommand = 310,
	// Token: 0x040005E1 RID: 1505
	LeftApple = 310,
	// Token: 0x040005E2 RID: 1506
	LeftWindows,
	// Token: 0x040005E3 RID: 1507
	RightCommand = 309,
	// Token: 0x040005E4 RID: 1508
	RightApple = 309,
	// Token: 0x040005E5 RID: 1509
	RightWindows = 312,
	// Token: 0x040005E6 RID: 1510
	AltGr,
	// Token: 0x040005E7 RID: 1511
	Help = 315,
	// Token: 0x040005E8 RID: 1512
	Print,
	// Token: 0x040005E9 RID: 1513
	SysReq,
	// Token: 0x040005EA RID: 1514
	Break,
	// Token: 0x040005EB RID: 1515
	Menu1,
	// Token: 0x040005EC RID: 1516
	Mouse0 = 323,
	// Token: 0x040005ED RID: 1517
	Mouse1,
	// Token: 0x040005EE RID: 1518
	Mouse2,
	// Token: 0x040005EF RID: 1519
	Mouse3,
	// Token: 0x040005F0 RID: 1520
	Mouse4,
	// Token: 0x040005F1 RID: 1521
	Mouse5,
	// Token: 0x040005F2 RID: 1522
	Mouse6,
	// Token: 0x040005F3 RID: 1523
	JoystickButton0,
	// Token: 0x040005F4 RID: 1524
	JoystickButton1,
	// Token: 0x040005F5 RID: 1525
	JoystickButton2,
	// Token: 0x040005F6 RID: 1526
	JoystickButton3,
	// Token: 0x040005F7 RID: 1527
	JoystickButton4,
	// Token: 0x040005F8 RID: 1528
	JoystickButton5,
	// Token: 0x040005F9 RID: 1529
	JoystickButton6,
	// Token: 0x040005FA RID: 1530
	JoystickButton7,
	// Token: 0x040005FB RID: 1531
	JoystickButton8,
	// Token: 0x040005FC RID: 1532
	JoystickButton9,
	// Token: 0x040005FD RID: 1533
	JoystickButton10,
	// Token: 0x040005FE RID: 1534
	JoystickButton11,
	// Token: 0x040005FF RID: 1535
	JoystickButton12,
	// Token: 0x04000600 RID: 1536
	JoystickButton13,
	// Token: 0x04000601 RID: 1537
	JoystickButton14,
	// Token: 0x04000602 RID: 1538
	JoystickButton15,
	// Token: 0x04000603 RID: 1539
	JoystickButton16,
	// Token: 0x04000604 RID: 1540
	JoystickButton17,
	// Token: 0x04000605 RID: 1541
	JoystickButton18,
	// Token: 0x04000606 RID: 1542
	JoystickButton19,
	// Token: 0x04000607 RID: 1543
	Joystick1Button0,
	// Token: 0x04000608 RID: 1544
	Joystick1Button1,
	// Token: 0x04000609 RID: 1545
	Joystick1Button2,
	// Token: 0x0400060A RID: 1546
	Joystick1Button3,
	// Token: 0x0400060B RID: 1547
	Joystick1Button4,
	// Token: 0x0400060C RID: 1548
	Joystick1Button5,
	// Token: 0x0400060D RID: 1549
	Joystick1Button6,
	// Token: 0x0400060E RID: 1550
	Joystick1Button7,
	// Token: 0x0400060F RID: 1551
	Joystick1Button8,
	// Token: 0x04000610 RID: 1552
	Joystick1Button9,
	// Token: 0x04000611 RID: 1553
	Joystick1Button10,
	// Token: 0x04000612 RID: 1554
	Joystick1Button11,
	// Token: 0x04000613 RID: 1555
	Joystick1Button12,
	// Token: 0x04000614 RID: 1556
	Joystick1Button13,
	// Token: 0x04000615 RID: 1557
	Joystick1Button14,
	// Token: 0x04000616 RID: 1558
	Joystick1Button15,
	// Token: 0x04000617 RID: 1559
	Joystick1Button16,
	// Token: 0x04000618 RID: 1560
	Joystick1Button17,
	// Token: 0x04000619 RID: 1561
	Joystick1Button18,
	// Token: 0x0400061A RID: 1562
	Joystick1Button19,
	// Token: 0x0400061B RID: 1563
	Joystick2Button0,
	// Token: 0x0400061C RID: 1564
	Joystick2Button1,
	// Token: 0x0400061D RID: 1565
	Joystick2Button2,
	// Token: 0x0400061E RID: 1566
	Joystick2Button3,
	// Token: 0x0400061F RID: 1567
	Joystick2Button4,
	// Token: 0x04000620 RID: 1568
	Joystick2Button5,
	// Token: 0x04000621 RID: 1569
	Joystick2Button6,
	// Token: 0x04000622 RID: 1570
	Joystick2Button7,
	// Token: 0x04000623 RID: 1571
	Joystick2Button8,
	// Token: 0x04000624 RID: 1572
	Joystick2Button9,
	// Token: 0x04000625 RID: 1573
	Joystick2Button10,
	// Token: 0x04000626 RID: 1574
	Joystick2Button11,
	// Token: 0x04000627 RID: 1575
	Joystick2Button12,
	// Token: 0x04000628 RID: 1576
	Joystick2Button13,
	// Token: 0x04000629 RID: 1577
	Joystick2Button14,
	// Token: 0x0400062A RID: 1578
	Joystick2Button15,
	// Token: 0x0400062B RID: 1579
	Joystick2Button16,
	// Token: 0x0400062C RID: 1580
	Joystick2Button17,
	// Token: 0x0400062D RID: 1581
	Joystick2Button18,
	// Token: 0x0400062E RID: 1582
	Joystick2Button19,
	// Token: 0x0400062F RID: 1583
	Joystick3Button0,
	// Token: 0x04000630 RID: 1584
	Joystick3Button1,
	// Token: 0x04000631 RID: 1585
	Joystick3Button2,
	// Token: 0x04000632 RID: 1586
	Joystick3Button3,
	// Token: 0x04000633 RID: 1587
	Joystick3Button4,
	// Token: 0x04000634 RID: 1588
	Joystick3Button5,
	// Token: 0x04000635 RID: 1589
	Joystick3Button6,
	// Token: 0x04000636 RID: 1590
	Joystick3Button7,
	// Token: 0x04000637 RID: 1591
	Joystick3Button8,
	// Token: 0x04000638 RID: 1592
	Joystick3Button9,
	// Token: 0x04000639 RID: 1593
	Joystick3Button10,
	// Token: 0x0400063A RID: 1594
	Joystick3Button11,
	// Token: 0x0400063B RID: 1595
	Joystick3Button12,
	// Token: 0x0400063C RID: 1596
	Joystick3Button13,
	// Token: 0x0400063D RID: 1597
	Joystick3Button14,
	// Token: 0x0400063E RID: 1598
	Joystick3Button15,
	// Token: 0x0400063F RID: 1599
	Joystick3Button16,
	// Token: 0x04000640 RID: 1600
	Joystick3Button17,
	// Token: 0x04000641 RID: 1601
	Joystick3Button18,
	// Token: 0x04000642 RID: 1602
	Joystick3Button19,
	// Token: 0x04000643 RID: 1603
	Joystick4Button0,
	// Token: 0x04000644 RID: 1604
	Joystick4Button1,
	// Token: 0x04000645 RID: 1605
	Joystick4Button2,
	// Token: 0x04000646 RID: 1606
	Joystick4Button3,
	// Token: 0x04000647 RID: 1607
	Joystick4Button4,
	// Token: 0x04000648 RID: 1608
	Joystick4Button5,
	// Token: 0x04000649 RID: 1609
	Joystick4Button6,
	// Token: 0x0400064A RID: 1610
	Joystick4Button7,
	// Token: 0x0400064B RID: 1611
	Joystick4Button8,
	// Token: 0x0400064C RID: 1612
	Joystick4Button9,
	// Token: 0x0400064D RID: 1613
	Joystick4Button10,
	// Token: 0x0400064E RID: 1614
	Joystick4Button11,
	// Token: 0x0400064F RID: 1615
	Joystick4Button12,
	// Token: 0x04000650 RID: 1616
	Joystick4Button13,
	// Token: 0x04000651 RID: 1617
	Joystick4Button14,
	// Token: 0x04000652 RID: 1618
	Joystick4Button15,
	// Token: 0x04000653 RID: 1619
	Joystick4Button16,
	// Token: 0x04000654 RID: 1620
	Joystick4Button17,
	// Token: 0x04000655 RID: 1621
	Joystick4Button18,
	// Token: 0x04000656 RID: 1622
	Joystick4Button19,
	// Token: 0x04000657 RID: 1623
	Joystick5Button0,
	// Token: 0x04000658 RID: 1624
	Joystick5Button1,
	// Token: 0x04000659 RID: 1625
	Joystick5Button2,
	// Token: 0x0400065A RID: 1626
	Joystick5Button3,
	// Token: 0x0400065B RID: 1627
	Joystick5Button4,
	// Token: 0x0400065C RID: 1628
	Joystick5Button5,
	// Token: 0x0400065D RID: 1629
	Joystick5Button6,
	// Token: 0x0400065E RID: 1630
	Joystick5Button7,
	// Token: 0x0400065F RID: 1631
	Joystick5Button8,
	// Token: 0x04000660 RID: 1632
	Joystick5Button9,
	// Token: 0x04000661 RID: 1633
	Joystick5Button10,
	// Token: 0x04000662 RID: 1634
	Joystick5Button11,
	// Token: 0x04000663 RID: 1635
	Joystick5Button12,
	// Token: 0x04000664 RID: 1636
	Joystick5Button13,
	// Token: 0x04000665 RID: 1637
	Joystick5Button14,
	// Token: 0x04000666 RID: 1638
	Joystick5Button15,
	// Token: 0x04000667 RID: 1639
	Joystick5Button16,
	// Token: 0x04000668 RID: 1640
	Joystick5Button17,
	// Token: 0x04000669 RID: 1641
	Joystick5Button18,
	// Token: 0x0400066A RID: 1642
	Joystick5Button19,
	// Token: 0x0400066B RID: 1643
	Joystick6Button0,
	// Token: 0x0400066C RID: 1644
	Joystick6Button1,
	// Token: 0x0400066D RID: 1645
	Joystick6Button2,
	// Token: 0x0400066E RID: 1646
	Joystick6Button3,
	// Token: 0x0400066F RID: 1647
	Joystick6Button4,
	// Token: 0x04000670 RID: 1648
	Joystick6Button5,
	// Token: 0x04000671 RID: 1649
	Joystick6Button6,
	// Token: 0x04000672 RID: 1650
	Joystick6Button7,
	// Token: 0x04000673 RID: 1651
	Joystick6Button8,
	// Token: 0x04000674 RID: 1652
	Joystick6Button9,
	// Token: 0x04000675 RID: 1653
	Joystick6Button10,
	// Token: 0x04000676 RID: 1654
	Joystick6Button11,
	// Token: 0x04000677 RID: 1655
	Joystick6Button12,
	// Token: 0x04000678 RID: 1656
	Joystick6Button13,
	// Token: 0x04000679 RID: 1657
	Joystick6Button14,
	// Token: 0x0400067A RID: 1658
	Joystick6Button15,
	// Token: 0x0400067B RID: 1659
	Joystick6Button16,
	// Token: 0x0400067C RID: 1660
	Joystick6Button17,
	// Token: 0x0400067D RID: 1661
	Joystick6Button18,
	// Token: 0x0400067E RID: 1662
	Joystick6Button19,
	// Token: 0x0400067F RID: 1663
	Joystick7Button0,
	// Token: 0x04000680 RID: 1664
	Joystick7Button1,
	// Token: 0x04000681 RID: 1665
	Joystick7Button2,
	// Token: 0x04000682 RID: 1666
	Joystick7Button3,
	// Token: 0x04000683 RID: 1667
	Joystick7Button4,
	// Token: 0x04000684 RID: 1668
	Joystick7Button5,
	// Token: 0x04000685 RID: 1669
	Joystick7Button6,
	// Token: 0x04000686 RID: 1670
	Joystick7Button7,
	// Token: 0x04000687 RID: 1671
	Joystick7Button8,
	// Token: 0x04000688 RID: 1672
	Joystick7Button9,
	// Token: 0x04000689 RID: 1673
	Joystick7Button10,
	// Token: 0x0400068A RID: 1674
	Joystick7Button11,
	// Token: 0x0400068B RID: 1675
	Joystick7Button12,
	// Token: 0x0400068C RID: 1676
	Joystick7Button13,
	// Token: 0x0400068D RID: 1677
	Joystick7Button14,
	// Token: 0x0400068E RID: 1678
	Joystick7Button15,
	// Token: 0x0400068F RID: 1679
	Joystick7Button16,
	// Token: 0x04000690 RID: 1680
	Joystick7Button17,
	// Token: 0x04000691 RID: 1681
	Joystick7Button18,
	// Token: 0x04000692 RID: 1682
	Joystick7Button19,
	// Token: 0x04000693 RID: 1683
	Joystick8Button0,
	// Token: 0x04000694 RID: 1684
	Joystick8Button1,
	// Token: 0x04000695 RID: 1685
	Joystick8Button2,
	// Token: 0x04000696 RID: 1686
	Joystick8Button3,
	// Token: 0x04000697 RID: 1687
	Joystick8Button4,
	// Token: 0x04000698 RID: 1688
	Joystick8Button5,
	// Token: 0x04000699 RID: 1689
	Joystick8Button6,
	// Token: 0x0400069A RID: 1690
	Joystick8Button7,
	// Token: 0x0400069B RID: 1691
	Joystick8Button8,
	// Token: 0x0400069C RID: 1692
	Joystick8Button9,
	// Token: 0x0400069D RID: 1693
	Joystick8Button10,
	// Token: 0x0400069E RID: 1694
	Joystick8Button11,
	// Token: 0x0400069F RID: 1695
	Joystick8Button12,
	// Token: 0x040006A0 RID: 1696
	Joystick8Button13,
	// Token: 0x040006A1 RID: 1697
	Joystick8Button14,
	// Token: 0x040006A2 RID: 1698
	Joystick8Button15,
	// Token: 0x040006A3 RID: 1699
	Joystick8Button16,
	// Token: 0x040006A4 RID: 1700
	Joystick8Button17,
	// Token: 0x040006A5 RID: 1701
	Joystick8Button18,
	// Token: 0x040006A6 RID: 1702
	Joystick8Button19
};
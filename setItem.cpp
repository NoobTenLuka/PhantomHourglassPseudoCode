extern Player *gPlayerRef; // 0x27E0FB4

// 0x22152CC is set for cutscenes and the item you get from the first npc

/*****************
 * SET ITEM *
 *****************/

enum class Item
{
  green_rupee, // 0x2,
  blue_rupee,
  red_rupee,
  big_green_rupee,
  big_red_rupee,
  big_gold_rupee,
  sword,
  shield, // 0x4
  phantom_hourglass,
  sw_sea_chart,
  nw_sea_chart,
  se_sea_chart,
  ne_sea_chart,
  fishing_rod,
  not_documented,
  not_documented_2,
  sun_key,
  kings_key,
  ghost_key,
  power_gem,
  wisdom_gem,
  courage_gem,
  salvage_arm
};

// Load from Gamecard
void unk_20408A4()
{
}

// Gets called as soon as dialogue ends (NPC1) and when entering the first area with monsters and seeing the broken bridge
void unk_20D20E8(int arg1, int arg2)
{
  switch (unknown)
  {
  case something:
    unk_2037F58(arg1, arg2);
  }
}

// Gets called as soon as a dialogue ends (NPC1)
void unk_2037F58(int arg1, int arg2)
{
  switch (unknown)
  {
  case something:
    unk_20BCE48(*0x27E0FC8, arg2->field_0x4);
  }
}

void unk_20BCE48(int arg1, Item item)
{
  if (unk_20BC46C() == true)
  {
    return false;
  }

  unk_21096BC(?,item);
}

void unk_21096BC(int arg1, Item item)
{
  arg1->field_0x4 = 0xA;
  arg1->field_0x74 = item;
  unk_20A8BF8(arg1);
}

void unk_215CD10(int arg1)
{
  arg1->field_0x40 = arg1->field_0x44;

  unk_202E740(0x27E077C, 0x19, arg1->field_0x44);

  if (arg1->field_0x4C == 0x3)
  {
    unk_2109768(unk_215CD8C());
  }
}

int unk_215CD8C()
{
  return unk_1FFFCD8(0x6);
}

int unk_1FFFCD8(int arg1)
{
  return (*0x27E0FDC)[arg1 << 2];
}

bool unk_2109768(int arg1)
{
  // if (unk_20A8BF8() != 0x6) {
  //   unk_21097A8();
  // }

  // if (arg1->field_0x4 == 0xB) {
  //   unk_2109794();
  // }

  unk_21097B0(arg1, arg1->field_0x74);

  return true; // or false depending on something I haven't figured out yet
}

void unk_21097B0(int arg1, int arg2)
{
  switch (arg2)
  {
  case 0:
    if (unk_20AD020())
    {
      unk_21098BC(arg2)
    }

    giveItemToPlayer(&gPlayerRef, arg1->field_0x74);
  }
}

void giveItemToPlayer(Player *player, Item item) // 0x20ADCDC
{
  switch (item)
  {
  case unknown:
    unk_20AE368(player, 1);
    break;
  case Item::green_rupee:
    giveRupees(player, 1, 1);
    break;
  case Item::blue_rupee:
    giveRupees(player, 5, 1);
    break;
  case Item::red_rupee:
    giveRupees(player, 20, 1);
    break;
  case Item::big_green_rupee:
    giveRupees(player, 100, 1);
    break;
  case Item::big_red_rupee:
    giveRupees(player, 200, 1);
    break;
  case Item::big_gold_rupee:
    giveRupees(player, 300, 1);
    break;
  case Item::sword:
    player->field_0x128 |= 1;
    unk_20AD714();
    player->sword->unk_20();
    break;
  case Item::shield:
    player->field_0x128 |= 2;
    unk_20AD714();
    player->shield->unk_20();
    break;
  case Item::phantom_hourglass:
    player->field_0x12C |= 1;
    unk_209779C();
    break;
  case Item::sw_sea_chart:
    player->field_0x12C |= 2;
    unk_209779C();
    break;
  case Item::nw_sea_chart:
    player->field_0x12C |= 4;
    unk_209779C();
    break;
  case Item::se_sea_chart:
    player->field_0x12C |= 8;
    unk_209779C();
    break;
  case Item::ne_sea_chart:
    player->field_0x12C |= 16;
    unk_209779C();
    break;
  case Item::fishing_rod:
    player->field_0x12C |= 256;
    unk_209779C();
    break;
  case Item::not_documented:
    player->field_0x12C |= 512;
    unk_209779C();
    unk_211CA20();
    unk_211C700();
    break;
  case Item::sun_key:
    player->field_0x12C |= 64;
    unk_209779C();
    break;
  case Item::not_documented_2:
    player->field_0x12C |= 128;
    unk_209779C();
    break;
  case Item::kings_key:
    player->field_0x12C |= 1024;
    break;
  case Item::ghost_key:
    player->field_0x12C |= 2048;
    break;
  case Item::power_gem:
    player->power_gem_count += 1;
    break;
  case Item::widsom_gem:
    player->wisdom_gem_count += 1;
    break;
  case Item::courage_gem:
    player->courage_gem_count += 1;
    break;
  case Item::salvage_arm:
    player->field_0x12C |= 4096;
    unk_209779C();
    unk_27E0FBC()->field_0x8 = 5;
    break;
  }
}

void unk_20AE368(Player *_player, int unknown)
{
  int res = unk_2084B14(*0x27E0E60, unknown) if (unknown + res <= 0)
  {
    unk_2084B08(player, 0);
  }
  else
  {
    unk_2084B08(player, unknown + res);
  }
}

void unk_2084B08(Player *player, int unknown)
{
  player->field_0x260 = unknown;
}

/*******************
 * ADD RUPEE (NPC) *
 *******************/

// This function is called when going into a loading zone to exiting one and when receiving an item from an npc till you have the item
// Somehow param_1 is always 0x225D318

void unk_20B2508(int param_1)
{
  // unk_20A8D40();

  // arg1->field_0xBA /* byte (8 bit) */ = 1;

  // if (?) {

  // }

  code **ppcVar2;
  code *pcVar3;

  unk_20A8D40() + 0xBA = 1;
  ppcVar2 = (code **)(0x20E61F8 + *(int *)(param_1 + 4) * 8);
  int something = *(int *)(param_1 + ((int)ppcVar2[1] >> 1));
  if (((uint)ppcVar2[1] & 1) == 0)
  {
    pcVar3 = *ppcVar2;
  }
  else
  {
    pcVar3 = *(code **)(*ppcVar2 + something);
  }
  (*pcVar3)(something);
  return;
}

int unk_20A8D40()
{
  return *0x27E0FD4;
}

void unk_210952C(int arg1)
{
  arg1->field_0x78 /* halfword (16 bit) */ += *(0x2112770 + 0x2C);

  if (unk_20367EC(0x27E0C68) == false)
  {
    if (arg1->field_0xA5 /* byte (8 bit) */ == 0)
    {
      unk_21097B0(arg1, arg1->field_0x74);
      return;
    }
  }
}

bool unk_20367EC(int arg1)
{
  int16_t sh = arg1->field_0x28[0x100]->field_0x5C;
  if (sh > 0)
  {
    return true;
  }

  return false;
}

void giveRupees(Player *player, int16_t amount, int unknown) // 0x20AE2E0
{
  player->rupee_count += amount;
}

/***********
 * CLASSES *
 ***********/

class Player : public Something
{
public:
  //void unk_20(); //Probably update player function
  uint16_t rupee_count;      // 0x22
  uint8_t courage_gem_count; // 0x24
  uint8_t power_gem_count;   // 0x25
  uint8_t wisdom_gem_count;  // 0x26
  Sword sword;               // 0xAC
  Shield shield;             // 0xB0
  int32_t field_0x128;
  int32_t field_0x12C;
  int field_0x260;
  // Probably some more padding, size unknown
}

class Sword
{
public:
  void unk_20();
}

class Shield
{
public:
  void unk_20();
}

class Something
{
  //public:
  //virtual void unk_20(); //Probably update entity function
}
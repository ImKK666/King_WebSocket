#include "Config.hpp"

#include "King_WebSocket/King_WebSocket.hpp"

#include "configor/json.hpp"

//using json = configor::json;
using json = configor::fifo_json;

void FConfig::SetConfig(const std::string& user, const std::string& name) const
{
    json::value c;
    c["b_OpenAim"] = Config.b_OpenAim;
    c["f_Smooth"] = Config.f_Smooth;
    c["f_AimFov"] = Config.f_AimFov;
    c["i_AimKey"] = Config.i_AimKey;
    c["i_TargeterKey"] = Config.i_TargeterKey;
    c["i_OpenAim"] = Config.i_OpenAim;
    c["i_bunnyhop"] = Config.i_bunnyhop;

    c["Player"] = json::object{
               {          "PlayerType",                           Config.Player.PlayerType},
               {      "b_ShowDistance",                       Config.Player.b_ShowDistance},
               {        "b_ShowTeamId",                         Config.Player.b_ShowTeamId},
               {        "b_ShowHealth",                         Config.Player.b_ShowHealth},
               {        "b_ShowWeapon",                         Config.Player.b_ShowWeapon},
               {          "b_ShowName",                           Config.Player.b_ShowName},
               {    "b_ShowReverseAim",                     Config.Player.b_ShowReverseAim},
               { "f_color_is_vis_true",  json::array { Config.Player.f_color_is_vis_true }},
               {"f_color_is_vis_false", json::array { Config.Player.f_color_is_vis_false }}
    };

    c["Scripts"] = json::object{
        {  "bunnyhop",   Config.Scripts.bunnyhop},
        { "rapidfire",  Config.Scripts.rapidfire},
        {"autoreload", Config.Scripts.autoreload}
    };

    c["Item"] = json::object{
        {   "ItemType",    Config.Item.ItemType},
        {"DrawTexture", Config.Item.DrawTexture},
    };

    c["Item"]["Light"] = json::object{
        {"b_AlternatorSmg", Config.Item.Light.b_AlternatorSmg},
        {       "b_R99Smg",        Config.Item.Light.b_R99Smg},
        {  "b_R301Carbine",   Config.Item.Light.b_R301Carbine},
        {        "b_P2020",         Config.Item.Light.b_P2020},
        {      "b_G7Scout",       Config.Item.Light.b_G7Scout},
        { "b_M600Spitfire",  Config.Item.Light.b_M600Spitfire},
        {         "b_Ammo",          Config.Item.Light.b_Ammo}
    };

    c["Item"]["Heavy"] = json::object{
        {   "b_VK47Flatline",    Config.Item.Heavy.b_VK47Flatline},
        {  "b_HemlokBurstAR",   Config.Item.Heavy.b_HemlokBurstAR},
        {"b_ProwlerBurstPow", Config.Item.Heavy.b_ProwlerBurstPow},
        {   "b_Repeater3030",    Config.Item.Heavy.b_Repeater3030},
        {         "b_CARSmg",          Config.Item.Heavy.b_CARSmg},
        {           "b_Ammo",            Config.Item.Heavy.b_Ammo}
    };

    c["Item"]["Energy"] = json::object{
        {   "b_LStarEmg",    Config.Item.Energy.b_LStarEmg},
        { "b_HavocRifle",  Config.Item.Energy.b_HavocRifle},
        {"b_DevotionLmg", Config.Item.Energy.b_DevotionLmg},
        { "b_TripleTake",  Config.Item.Energy.b_TripleTake},
        {    "b_VoltSmg",     Config.Item.Energy.b_VoltSmg},
        {       "b_Ammo",        Config.Item.Energy.b_Ammo}
    };

    c["Item"]["Sniper"] = json::object{
        { "b_LongbowDmr",  Config.Item.Sniper.b_LongbowDmr},
        {"b_ChargeRifle", Config.Item.Sniper.b_ChargeRifle},
        {   "b_Sentinel",    Config.Item.Sniper.b_Sentinel},
        {    "b_Wingman",     Config.Item.Sniper.b_Wingman},
        {       "b_Ammo",        Config.Item.Sniper.b_Ammo}
    };

    c["Item"]["Shoutgun"] = json::object{
        {         "b_EVA8Auto",          Config.Item.Shoutgun.b_EVA8Auto},
        {      "b_Peacekeeper",       Config.Item.Shoutgun.b_Peacekeeper},
        {"b_MozambiqueShotgun", Config.Item.Shoutgun.b_MozambiqueShotgun},
        {   "b_MastiffShotgun",    Config.Item.Shoutgun.b_MastiffShotgun},
        {             "b_Ammo",              Config.Item.Shoutgun.b_Ammo}
    };

    c["Item"]["AirDropWeapon"] = json::object{
        {"b_Kraber50CalSniper", Config.Item.AirDropWeapon.b_Kraber50CalSniper},
        { "b_BocekCompoundBow",  Config.Item.AirDropWeapon.b_BocekCompoundBow},
        {       "b_RampageLmg",        Config.Item.AirDropWeapon.b_RampageLmg},
        {    "b_ThrowingKnife",     Config.Item.AirDropWeapon.b_ThrowingKnife},
        {         "b_RE45Auto",          Config.Item.AirDropWeapon.b_RE45Auto}
    };

    c["Item"]["Equipment"]["Helmet"] = json::object{
        {"b_Lv1", Config.Item.Equipment.Helmet.b_Lv1},
        {"b_Lv2", Config.Item.Equipment.Helmet.b_Lv2},
        {"b_Lv3", Config.Item.Equipment.Helmet.b_Lv3},
        {"b_Lv4", Config.Item.Equipment.Helmet.b_Lv4},
    };

    c["Item"]["Equipment"]["Shield"] = json::object{
        {"b_Lv1", Config.Item.Equipment.Shield.b_Lv1},
        {"b_Lv2", Config.Item.Equipment.Shield.b_Lv2},
        {"b_Lv3", Config.Item.Equipment.Shield.b_Lv3},
        {"b_Lv4", Config.Item.Equipment.Shield.b_Lv4},
        {"b_Lv5", Config.Item.Equipment.Shield.b_Lv5},
    };

    c["Item"]["Equipment"]["KnockdownShield"] = json::object{
        {"b_Lv1", Config.Item.Equipment.KnockdownShield.b_Lv1},
        {"b_Lv2", Config.Item.Equipment.KnockdownShield.b_Lv2},
        {"b_Lv3", Config.Item.Equipment.KnockdownShield.b_Lv3},
        {"b_Lv4", Config.Item.Equipment.KnockdownShield.b_Lv4},
    };

    c["Item"]["Equipment"]["BackPack"] = json::object{
        {"b_Lv1", Config.Item.Equipment.BackPack.b_Lv1},
        {"b_Lv2", Config.Item.Equipment.BackPack.b_Lv2},
        {"b_Lv3", Config.Item.Equipment.BackPack.b_Lv3},
        {"b_Lv4", Config.Item.Equipment.BackPack.b_Lv4},
    };

    c["Item"]["Consumables"]["Health"] = json::object{
        {"b_PhoenixKit", Config.Item.Consumables.Health.b_PhoenixKit},
        {    "b_MedKit",     Config.Item.Consumables.Health.b_MedKit},
        {   "b_Syringe",    Config.Item.Consumables.Health.b_Syringe},
    };

    c["Item"]["Consumables"]["Battery"] = json::object{
        {"b_ShieldBattery", Config.Item.Consumables.Battery.b_ShieldBattery},
        {   "b_ShieldCell",    Config.Item.Consumables.Battery.b_ShieldCell}
    };

    c["Item"]["Consumables"]["Skill"] = json::object{
        {"b_UltimateAccelerant", Config.Item.Consumables.Skill.b_UltimateAccelerant},
    };

    c["Item"]["Missile"] = json::object{
        {"b_ThermiteGrenade", Config.Item.Missile.b_ThermiteGrenade},
        {    "b_FragGrenade",     Config.Item.Missile.b_FragGrenade},
        {        "b_ArcStar",         Config.Item.Missile.b_ArcStar},
    };

    c["Item"]["Sight"]["Primary"] = json::object{
        { "b_HcogClassic",  Config.Item.Sight.Primary.b_HcogClassic},
        { "b_HcogBruiser",  Config.Item.Sight.Primary.b_HcogBruiser},
        {        "b_Holo",         Config.Item.Sight.Primary.b_Holo},
        {"b_VariableHolo", Config.Item.Sight.Primary.b_VariableHolo},
    };

    c["Item"]["Sight"]["Intermediate"] = json::object{
        { "b_HcogRanger",  Config.Item.Sight.Intermediate.b_HcogRanger},
        {"b_VariableAog", Config.Item.Sight.Intermediate.b_VariableAog}
    };

    c["Item"]["Sight"]["Advanced"] = json::object{
        {        "b_Sniper",         Config.Item.Sight.Advanced.b_Sniper},
        {"b_VariableSniper", Config.Item.Sight.Advanced.b_VariableSniper},
    };

    c["Item"]["Sight"]["AriDrop"] = json::object{
        {      "b_DigitalThreat",       Config.Item.Sight.AriDrop.b_DigitalThreat},
        {"b_DigitalSniperThreat", Config.Item.Sight.AriDrop.b_DigitalSniperThreat},
    };

    c["Item"]["Part"]["Stabilizer"] = json::object{
        {"b_Lv1", Config.Item.Part.Stabilizer.b_Lv1},
        {"b_Lv2", Config.Item.Part.Stabilizer.b_Lv2},
        {"b_Lv3", Config.Item.Part.Stabilizer.b_Lv3},
        {"b_Lv4", Config.Item.Part.Stabilizer.b_Lv4},
    };

    c["Item"]["Part"]["LaserSight"] = json::object{
        {"b_Lv1", Config.Item.Part.LaserSight.b_Lv1},
        {"b_Lv2", Config.Item.Part.LaserSight.b_Lv2},
        {"b_Lv3", Config.Item.Part.LaserSight.b_Lv3},
    };

    c["Item"]["Part"]["ExtendedMag"]["Light"] = json::object{
        {"b_Lv1", Config.Item.Part.ExtendedMag.Light.b_Lv1},
        {"b_Lv2", Config.Item.Part.ExtendedMag.Light.b_Lv2},
        {"b_Lv3", Config.Item.Part.ExtendedMag.Light.b_Lv3},
        {"b_Lv4", Config.Item.Part.ExtendedMag.Light.b_Lv4},
    };
    c["Item"]["Part"]["ExtendedMag"]["Heavy"] = json::object{
        {"b_Lv1", Config.Item.Part.ExtendedMag.Heavy.b_Lv1},
        {"b_Lv2", Config.Item.Part.ExtendedMag.Heavy.b_Lv2},
        {"b_Lv3", Config.Item.Part.ExtendedMag.Heavy.b_Lv3},
        {"b_Lv4", Config.Item.Part.ExtendedMag.Heavy.b_Lv4},
    };
    c["Item"]["Part"]["ExtendedMag"]["Energy"] = json::object{
        {"b_Lv1", Config.Item.Part.ExtendedMag.Energy.b_Lv1},
        {"b_Lv2", Config.Item.Part.ExtendedMag.Energy.b_Lv2},
        {"b_Lv3", Config.Item.Part.ExtendedMag.Energy.b_Lv3},
        {"b_Lv4", Config.Item.Part.ExtendedMag.Energy.b_Lv4},
    };
    c["Item"]["Part"]["ExtendedMag"]["Sniper"] = json::object{
        {"b_Lv1", Config.Item.Part.ExtendedMag.Sniper.b_Lv1},
        {"b_Lv2", Config.Item.Part.ExtendedMag.Sniper.b_Lv2},
        {"b_Lv3", Config.Item.Part.ExtendedMag.Sniper.b_Lv3},
        {"b_Lv4", Config.Item.Part.ExtendedMag.Sniper.b_Lv4},
    };
    c["Item"]["Part"]["ExtendedMag"]["Shotgun"] = json::object{
        {"b_Lv1", Config.Item.Part.ExtendedMag.Shotgun.b_Lv1},
        {"b_Lv2", Config.Item.Part.ExtendedMag.Shotgun.b_Lv2},
        {"b_Lv3", Config.Item.Part.ExtendedMag.Shotgun.b_Lv3},
    };

    c["Item"]["Part"]["Stock"]["Standar"] = json::object{
        {"b_Lv1", Config.Item.Part.Stock.Standar.b_Lv1},
        {"b_Lv2", Config.Item.Part.Stock.Standar.b_Lv2},
        {"b_Lv3", Config.Item.Part.Stock.Standar.b_Lv3},
    };
    c["Item"]["Part"]["Stock"]["Sniper"] = json::object{
        {"b_Lv1", Config.Item.Part.Stock.Sniper.b_Lv1},
        {"b_Lv2", Config.Item.Part.Stock.Sniper.b_Lv2},
        {"b_Lv3", Config.Item.Part.Stock.Sniper.b_Lv3},
    };

    c["Item"]["Part"]["HopUp"] = json::object{
        {       "b_Turbocharger",        Config.Item.Part.HopUp.b_Turbocharger},
        {"b_SkullpiercerRifling", Config.Item.Part.HopUp.b_SkullpiercerRifling},
        {  "b_HammerpointRounds",   Config.Item.Part.HopUp.b_HammerpointRounds},
        {      "b_AnvilReceiver",       Config.Item.Part.HopUp.b_AnvilReceiver},
        {   "b_QuickdrawHolster",    Config.Item.Part.HopUp.b_QuickdrawHolster},
        {       "b_DeadeyeTempo",        Config.Item.Part.HopUp.b_DeadeyeTempo},
        {        "b_ShatterCaps",         Config.Item.Part.HopUp.b_ShatterCaps},
        {      "b_KineticFeeder",       Config.Item.Part.HopUp.b_KineticFeeder},
        {      "b_BoostedLoader",       Config.Item.Part.HopUp.b_BoostedLoader},
        {         "b_DualLoader",          Config.Item.Part.HopUp.b_DualLoader},
    };

    json::value j;
    j["type"] = "SetConfig";
    j["user"] = user;
    j["name"] = name;
    j["content"] = { c };

    g_ws->send(json::dump(j, { json::serializer::with_encoding< configor::encoding::ignore >() }));
}
void FConfig::GetConfig(std::string user, std::string name) const
{
    const json::value t = json::object{
        {"type", "GetConfig"},
        {"user",        user},
        {"name",        name},
    };

    g_ws->send(json::dump(t, { json::serializer::with_encoding< configor::encoding::ignore >() }));
}
void FConfig::GetConfigList(std::string user) const
{
    const json::value t = json::object{
        {"type", "ConfigList"},
        {"user",         user},
    };

    g_ws->send(json::dump(t));
}
void FConfig::DeleteConfig(std::string user, std::string name) const
{
    const json::value t = json::object{
        {"type", "DeleteConfig"},
        {"user",           user},
        {"name",           name},
    };

    g_ws->send(json::dump(t));
}

void FConfig::GetConfigList_Callbak(const std::string& json_string) {
    auto j = json::parse(json_string);
    ConfigSize = static_cast<int>(j["content"].size());
    for (int i = 0; i < ConfigSize; ++i) {
        ConfigList[i] = King_WebSocket::UTF8ToGBK(j["content"][i].get< std::string >());
    }
}
void FConfig::GetConfig_Callbak(const std::string& json_string) {
    auto j = json::parse(json_string);

    Config.b_OpenAim = j["content"]["b_OpenAim"].get< bool >();
    //Config.f_Smooth                                    = j [ "content" ][ "f_Smooth" ].get< float >( );
    //Config.f_AimFov                                    = j [ "content" ][ "f_AimFov" ].get< float >( );
    Config.i_AimKey = j["content"]["i_AimKey"].get< int >();
    Config.i_TargeterKey = j["content"]["i_TargeterKey"].get< int >();
    Config.i_OpenAim = j["content"]["i_OpenAim"].get< int >();
    Config.i_bunnyhop = j["content"]["i_bunnyhop"].get< int >();


    Config.Player.PlayerType = j["content"]["Player"]["PlayerType"].get< int >();
    Config.Player.b_ShowDistance = j["content"]["Player"]["b_ShowDistance"].get< bool >();
    Config.Player.b_ShowTeamId = j["content"]["Player"]["b_ShowTeamId"].get< bool >();
    Config.Player.b_ShowHealth = j["content"]["Player"]["b_ShowHealth"].get< bool >();
    Config.Player.b_ShowWeapon = j["content"]["Player"]["b_ShowWeapon"].get< bool >();
    Config.Player.b_ShowName = j["content"]["Player"]["b_ShowName"].get< bool >();
    Config.Player.b_ShowReverseAim = j["content"]["Player"]["b_ShowReverseAim"].get< bool >();
    //Config.Player.f_color_is_vis_true [ 0 ]            = j [ "content" ][ "Player" ][ "f_color_is_vis_true" ][ 0 ].get< float >( );
    //Config.Player.f_color_is_vis_true [ 1 ]            = j [ "content" ][ "Player" ][ "f_color_is_vis_true" ][ 1 ].get< float >( );
    //Config.Player.f_color_is_vis_true [ 2 ]            = j [ "content" ][ "Player" ][ "f_color_is_vis_true" ][ 2 ].get< float >( );
    //Config.Player.f_color_is_vis_false [ 0 ]           = j [ "content" ][ "Player" ][ "f_color_is_vis_false" ][ 0 ].get< float >( );
    //Config.Player.f_color_is_vis_false [ 1 ]           = j [ "content" ][ "Player" ][ "f_color_is_vis_false" ][ 1 ].get< float >( );
    //Config.Player.f_color_is_vis_false [ 2 ]           = j [ "content" ][ "Player" ][ "f_color_is_vis_false" ][ 2 ].get< float >( );
    Config.Scripts.bunnyhop = j["content"]["Scripts"]["bunnyhop"].get< bool >();
    Config.Scripts.rapidfire = j["content"]["Scripts"]["rapidfire"].get< bool >();
    Config.Scripts.autoreload = j["content"]["Scripts"]["autoreload"].get< bool >();

    Config.Item.ItemType = j["content"]["Item"]["ItemType"].get< int >();
    Config.Item.DrawTexture = j["content"]["Item"]["DrawTexture"].get< bool >();

    Config.Item.Light.b_AlternatorSmg = j["content"]["Item"]["Light"]["b_AlternatorSmg"].get< bool >();
    Config.Item.Light.b_R99Smg = j["content"]["Item"]["Light"]["b_R99Smg"].get< bool >();
    Config.Item.Light.b_R301Carbine = j["content"]["Item"]["Light"]["b_R301Carbine"].get< bool >();
    Config.Item.Light.b_P2020 = j["content"]["Item"]["Light"]["b_P2020"].get< bool >();
    Config.Item.Light.b_G7Scout = j["content"]["Item"]["Light"]["b_G7Scout"].get< bool >();
    Config.Item.Light.b_M600Spitfire = j["content"]["Item"]["Light"]["b_M600Spitfire"].get< bool >();
    Config.Item.Light.b_Ammo = j["content"]["Item"]["Light"]["b_Ammo"].get< bool >();

    Config.Item.Energy.b_LStarEmg = j["content"]["Item"]["Energy"]["b_LStarEmg"].get< bool >();
    Config.Item.Energy.b_HavocRifle = j["content"]["Item"]["Energy"]["b_HavocRifle"].get< bool >();
    Config.Item.Energy.b_DevotionLmg = j["content"]["Item"]["Energy"]["b_DevotionLmg"].get< bool >();
    Config.Item.Energy.b_TripleTake = j["content"]["Item"]["Energy"]["b_TripleTake"].get< bool >();
    Config.Item.Energy.b_VoltSmg = j["content"]["Item"]["Energy"]["b_VoltSmg"].get< bool >();
    Config.Item.Energy.b_Ammo = j["content"]["Item"]["Energy"]["b_Ammo"].get< bool >();

    Config.Item.Sniper.b_LongbowDmr = j["content"]["Item"]["Sniper"]["b_LongbowDmr"].get< bool >();
    Config.Item.Sniper.b_ChargeRifle = j["content"]["Item"]["Sniper"]["b_ChargeRifle"].get< bool >();
    Config.Item.Sniper.b_Sentinel = j["content"]["Item"]["Sniper"]["b_Sentinel"].get< bool >();
    Config.Item.Sniper.b_Wingman = j["content"]["Item"]["Sniper"]["b_Wingman"].get< bool >();
    Config.Item.Sniper.b_Ammo = j["content"]["Item"]["Sniper"]["b_Ammo"].get< bool >();

    Config.Item.Shoutgun.b_EVA8Auto = j["content"]["Item"]["Shoutgun"]["b_EVA8Auto"].get< bool >();
    Config.Item.Shoutgun.b_Peacekeeper = j["content"]["Item"]["Shoutgun"]["b_Peacekeeper"].get< bool >();
    Config.Item.Shoutgun.b_MozambiqueShotgun = j["content"]["Item"]["Shoutgun"]["b_MozambiqueShotgun"].get< bool >();
    Config.Item.Shoutgun.b_MastiffShotgun = j["content"]["Item"]["Shoutgun"]["b_MastiffShotgun"].get< bool >();
    Config.Item.Shoutgun.b_Ammo = j["content"]["Item"]["Shoutgun"]["b_Ammo"].get< bool >();

    Config.Item.AirDropWeapon.b_Kraber50CalSniper = j["content"]["Item"]["AirDropWeapon"]["b_Kraber50CalSniper"].get< bool >();
    Config.Item.AirDropWeapon.b_BocekCompoundBow = j["content"]["Item"]["AirDropWeapon"]["b_BocekCompoundBow"].get< bool >();
    Config.Item.AirDropWeapon.b_RampageLmg = j["content"]["Item"]["AirDropWeapon"]["b_RampageLmg"].get< bool >();
    Config.Item.AirDropWeapon.b_ThrowingKnife = j["content"]["Item"]["AirDropWeapon"]["b_ThrowingKnife"].get< bool >();
    Config.Item.AirDropWeapon.b_RE45Auto = j["content"]["Item"]["AirDropWeapon"]["b_RE45Auto"].get< bool >();

    Config.Item.Equipment.Helmet.b_Lv1 = j["content"]["Item"]["Equipment"]["Helmet"]["b_Lv1"].get< bool >();
    Config.Item.Equipment.Helmet.b_Lv2 = j["content"]["Item"]["Equipment"]["Helmet"]["b_Lv2"].get< bool >();
    Config.Item.Equipment.Helmet.b_Lv3 = j["content"]["Item"]["Equipment"]["Helmet"]["b_Lv3"].get< bool >();
    Config.Item.Equipment.Helmet.b_Lv4 = j["content"]["Item"]["Equipment"]["Helmet"]["b_Lv4"].get< bool >();

    Config.Item.Equipment.Shield.b_Lv1 = j["content"]["Item"]["Equipment"]["Shield"]["b_Lv1"].get< bool >();
    Config.Item.Equipment.Shield.b_Lv2 = j["content"]["Item"]["Equipment"]["Shield"]["b_Lv2"].get< bool >();
    Config.Item.Equipment.Shield.b_Lv3 = j["content"]["Item"]["Equipment"]["Shield"]["b_Lv3"].get< bool >();
    Config.Item.Equipment.Shield.b_Lv4 = j["content"]["Item"]["Equipment"]["Shield"]["b_Lv4"].get< bool >();
    Config.Item.Equipment.Shield.b_Lv4 = j["content"]["Item"]["Equipment"]["Shield"]["b_Lv5"].get< bool >();

    Config.Item.Equipment.KnockdownShield.b_Lv1 = j["content"]["Item"]["Equipment"]["KnockdownShield"]["b_Lv1"].get< bool >();
    Config.Item.Equipment.KnockdownShield.b_Lv2 = j["content"]["Item"]["Equipment"]["KnockdownShield"]["b_Lv2"].get< bool >();
    Config.Item.Equipment.KnockdownShield.b_Lv3 = j["content"]["Item"]["Equipment"]["KnockdownShield"]["b_Lv3"].get< bool >();
    Config.Item.Equipment.KnockdownShield.b_Lv4 = j["content"]["Item"]["Equipment"]["KnockdownShield"]["b_Lv4"].get< bool >();

    Config.Item.Equipment.BackPack.b_Lv1 = j["content"]["Item"]["Equipment"]["BackPack"]["b_Lv1"].get< bool >();
    Config.Item.Equipment.BackPack.b_Lv2 = j["content"]["Item"]["Equipment"]["BackPack"]["b_Lv2"].get< bool >();
    Config.Item.Equipment.BackPack.b_Lv3 = j["content"]["Item"]["Equipment"]["BackPack"]["b_Lv3"].get< bool >();
    Config.Item.Equipment.BackPack.b_Lv4 = j["content"]["Item"]["Equipment"]["BackPack"]["b_Lv4"].get< bool >();

    Config.Item.Consumables.Health.b_PhoenixKit = j["content"]["Item"]["Consumables"]["Health"]["b_PhoenixKit"].get< bool >();
    Config.Item.Consumables.Health.b_MedKit = j["content"]["Item"]["Consumables"]["Health"]["b_MedKit"].get< bool >();
    Config.Item.Consumables.Health.b_Syringe = j["content"]["Item"]["Consumables"]["Health"]["b_Syringe"].get< bool >();

    Config.Item.Consumables.Battery.b_ShieldBattery = j["content"]["Item"]["Consumables"]["Battery"]["b_ShieldBattery"].get< bool >();
    Config.Item.Consumables.Battery.b_ShieldCell = j["content"]["Item"]["Consumables"]["Battery"]["b_ShieldCell"].get< bool >();

    Config.Item.Consumables.Skill.b_UltimateAccelerant = j["content"]["Item"]["Consumables"]["Skill"]["b_UltimateAccelerant"].get< bool >();

    Config.Item.Missile.b_ThermiteGrenade = j["content"]["Item"]["Missile"]["b_ThermiteGrenade"].get< bool >();
    Config.Item.Missile.b_FragGrenade = j["content"]["Item"]["Missile"]["b_FragGrenade"].get< bool >();
    Config.Item.Missile.b_ArcStar = j["content"]["Item"]["Missile"]["b_ArcStar"].get< bool >();

    Config.Item.Sight.Primary.b_HcogClassic = j["content"]["Item"]["Sight"]["Primary"]["b_HcogClassic"].get< bool >();
    Config.Item.Sight.Primary.b_HcogBruiser = j["content"]["Item"]["Sight"]["Primary"]["b_HcogBruiser"].get< bool >();
    Config.Item.Sight.Primary.b_Holo = j["content"]["Item"]["Sight"]["Primary"]["b_Holo"].get< bool >();
    Config.Item.Sight.Primary.b_VariableHolo = j["content"]["Item"]["Sight"]["Primary"]["b_VariableHolo"].get< bool >();

    Config.Item.Sight.Intermediate.b_HcogRanger = j["content"]["Item"]["Sight"]["Intermediate"]["b_HcogRanger"].get< bool >();
    Config.Item.Sight.Intermediate.b_VariableAog = j["content"]["Item"]["Sight"]["Intermediate"]["b_VariableAog"].get< bool >();

    Config.Item.Sight.Advanced.b_Sniper = j["content"]["Item"]["Sight"]["Advanced"]["b_Sniper"].get< bool >();
    Config.Item.Sight.Advanced.b_VariableSniper = j["content"]["Item"]["Sight"]["Advanced"]["b_VariableSniper"].get< bool >();

    Config.Item.Sight.AriDrop.b_DigitalThreat = j["content"]["Item"]["Sight"]["AriDrop"]["b_DigitalThreat"].get< bool >();
    Config.Item.Sight.AriDrop.b_DigitalSniperThreat = j["content"]["Item"]["Sight"]["AriDrop"]["b_DigitalSniperThreat"].get< bool >();

    Config.Item.Part.Stabilizer.b_Lv1 = j["content"]["Item"]["Part"]["Stabilizer"]["b_Lv1"].get< bool >();
    Config.Item.Part.Stabilizer.b_Lv2 = j["content"]["Item"]["Part"]["Stabilizer"]["b_Lv2"].get< bool >();
    Config.Item.Part.Stabilizer.b_Lv3 = j["content"]["Item"]["Part"]["Stabilizer"]["b_Lv3"].get< bool >();
    Config.Item.Part.Stabilizer.b_Lv4 = j["content"]["Item"]["Part"]["Stabilizer"]["b_Lv4"].get< bool >();

    Config.Item.Part.LaserSight.b_Lv1 = j["content"]["Item"]["Part"]["LaserSight"]["b_Lv1"].get< bool >();
    Config.Item.Part.LaserSight.b_Lv2 = j["content"]["Item"]["Part"]["LaserSight"]["b_Lv2"].get< bool >();
    Config.Item.Part.LaserSight.b_Lv3 = j["content"]["Item"]["Part"]["LaserSight"]["b_Lv3"].get< bool >();

    Config.Item.Part.ExtendedMag.Light.b_Lv1 = j["content"]["Item"]["Part"]["ExtendedMag"]["Light"]["b_Lv1"].get< bool >();
    Config.Item.Part.ExtendedMag.Light.b_Lv2 = j["content"]["Item"]["Part"]["ExtendedMag"]["Light"]["b_Lv2"].get< bool >();
    Config.Item.Part.ExtendedMag.Light.b_Lv3 = j["content"]["Item"]["Part"]["ExtendedMag"]["Light"]["b_Lv3"].get< bool >();
    Config.Item.Part.ExtendedMag.Light.b_Lv4 = j["content"]["Item"]["Part"]["ExtendedMag"]["Light"]["b_Lv4"].get< bool >();

    Config.Item.Part.ExtendedMag.Heavy.b_Lv1 = j["content"]["Item"]["Part"]["ExtendedMag"]["Heavy"]["b_Lv1"].get< bool >();
    Config.Item.Part.ExtendedMag.Heavy.b_Lv2 = j["content"]["Item"]["Part"]["ExtendedMag"]["Heavy"]["b_Lv2"].get< bool >();
    Config.Item.Part.ExtendedMag.Heavy.b_Lv3 = j["content"]["Item"]["Part"]["ExtendedMag"]["Heavy"]["b_Lv3"].get< bool >();
    Config.Item.Part.ExtendedMag.Heavy.b_Lv4 = j["content"]["Item"]["Part"]["ExtendedMag"]["Heavy"]["b_Lv4"].get< bool >();

    Config.Item.Part.ExtendedMag.Energy.b_Lv1 = j["content"]["Item"]["Part"]["ExtendedMag"]["Energy"]["b_Lv1"].get< bool >();
    Config.Item.Part.ExtendedMag.Energy.b_Lv2 = j["content"]["Item"]["Part"]["ExtendedMag"]["Energy"]["b_Lv2"].get< bool >();
    Config.Item.Part.ExtendedMag.Energy.b_Lv3 = j["content"]["Item"]["Part"]["ExtendedMag"]["Energy"]["b_Lv3"].get< bool >();
    Config.Item.Part.ExtendedMag.Energy.b_Lv4 = j["content"]["Item"]["Part"]["ExtendedMag"]["Energy"]["b_Lv4"].get< bool >();

    Config.Item.Part.ExtendedMag.Sniper.b_Lv1 = j["content"]["Item"]["Part"]["ExtendedMag"]["Sniper"]["b_Lv1"].get< bool >();
    Config.Item.Part.ExtendedMag.Sniper.b_Lv2 = j["content"]["Item"]["Part"]["ExtendedMag"]["Sniper"]["b_Lv2"].get< bool >();
    Config.Item.Part.ExtendedMag.Sniper.b_Lv3 = j["content"]["Item"]["Part"]["ExtendedMag"]["Sniper"]["b_Lv3"].get< bool >();
    Config.Item.Part.ExtendedMag.Sniper.b_Lv4 = j["content"]["Item"]["Part"]["ExtendedMag"]["Sniper"]["b_Lv4"].get< bool >();

    Config.Item.Part.ExtendedMag.Shotgun.b_Lv1 = j["content"]["Item"]["Part"]["ExtendedMag"]["Shotgun"]["b_Lv1"].get< bool >();
    Config.Item.Part.ExtendedMag.Shotgun.b_Lv2 = j["content"]["Item"]["Part"]["ExtendedMag"]["Shotgun"]["b_Lv2"].get< bool >();
    Config.Item.Part.ExtendedMag.Shotgun.b_Lv3 = j["content"]["Item"]["Part"]["ExtendedMag"]["Shotgun"]["b_Lv3"].get< bool >();

    Config.Item.Part.Stock.Standar.b_Lv1 = j["content"]["Item"]["Part"]["Stock"]["Standar"]["b_Lv1"].get< bool >();
    Config.Item.Part.Stock.Standar.b_Lv2 = j["content"]["Item"]["Part"]["Stock"]["Standar"]["b_Lv2"].get< bool >();
    Config.Item.Part.Stock.Standar.b_Lv3 = j["content"]["Item"]["Part"]["Stock"]["Standar"]["b_Lv3"].get< bool >();

    Config.Item.Part.Stock.Sniper.b_Lv1 = j["content"]["Item"]["Part"]["Stock"]["Sniper"]["b_Lv1"].get< bool >();
    Config.Item.Part.Stock.Sniper.b_Lv2 = j["content"]["Item"]["Part"]["Stock"]["Sniper"]["b_Lv2"].get< bool >();
    Config.Item.Part.Stock.Sniper.b_Lv3 = j["content"]["Item"]["Part"]["Stock"]["Sniper"]["b_Lv3"].get< bool >();

    Config.Item.Part.HopUp.b_Turbocharger = j["content"]["Item"]["Part"]["HopUp"]["b_Turbocharger"].get< bool >();
    Config.Item.Part.HopUp.b_SkullpiercerRifling = j["content"]["Item"]["Part"]["HopUp"]["b_SkullpiercerRifling"].get< bool >();
    Config.Item.Part.HopUp.b_HammerpointRounds = j["content"]["Item"]["Part"]["HopUp"]["b_HammerpointRounds"].get< bool >();
    Config.Item.Part.HopUp.b_AnvilReceiver = j["content"]["Item"]["Part"]["HopUp"]["b_AnvilReceiver"].get< bool >();
    Config.Item.Part.HopUp.b_QuickdrawHolster = j["content"]["Item"]["Part"]["HopUp"]["b_QuickdrawHolster"].get< bool >();
    Config.Item.Part.HopUp.b_DeadeyeTempo = j["content"]["Item"]["Part"]["HopUp"]["b_DeadeyeTempo"].get< bool >();
    Config.Item.Part.HopUp.b_ShatterCaps = j["content"]["Item"]["Part"]["HopUp"]["b_ShatterCaps"].get< bool >();
    Config.Item.Part.HopUp.b_KineticFeeder = j["content"]["Item"]["Part"]["HopUp"]["b_KineticFeeder"].get< bool >();
    Config.Item.Part.HopUp.b_BoostedLoader = j["content"]["Item"]["Part"]["HopUp"]["b_BoostedLoader"].get< bool >();
    Config.Item.Part.HopUp.b_DualLoader = j["content"]["Item"]["Part"]["HopUp"]["b_DualLoader"].get< bool >();
}
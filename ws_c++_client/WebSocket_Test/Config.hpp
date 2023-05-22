#pragma once
#include <cstdint>
#include <string>
#include <vector>


struct FConfig {
    bool b_ShowMenu{};

    bool b_BattleMode{};
    bool b_SniperMode{};

    struct FPlayer {
        int32_t PlayerType = 3;

        bool b_ShowDistance = true;
        bool b_ShowTeamId = true;
        bool b_ShowHealth = true;
        bool b_ShowWeapon = true;
        bool b_ShowName = true;
        bool b_ShowReverseAim = true;

        float f_color_is_vis_true[3] = { 1, 0, 1 };
        float f_color_is_vis_false[3] = { 0.34f, 0.59f, 0.86f };

    } Player;

    struct FScripts {
        bool bunnyhop{};
        bool rapidfire = true;
        bool autoreload = true;
    } Scripts;

    struct FItem {
        int32_t ItemType = 3;
        bool    DrawTexture = false;

        struct FLight {
            bool b_AlternatorSmg = true;
            bool b_R99Smg = true;
            bool b_R301Carbine = true;
            bool b_P2020{};
            bool b_G7Scout{};
            bool b_M600Spitfire = true;
            bool b_Ammo = true;
        } Light;

        struct FHeavy {
            bool b_VK47Flatline{};
            bool b_HemlokBurstAR = true;
            bool b_ProwlerBurstPow{};
            bool b_Repeater3030{};
            bool b_CARSmg{};
            bool b_Ammo = true;
        } Heavy;

        struct FEnergy {
            bool b_LStarEmg{};
            bool b_HavocRifle = true;
            bool b_DevotionLmg = true;
            bool b_TripleTake{};
            bool b_VoltSmg = true;
            bool b_Ammo = true;
        } Energy;

        struct FSniper {
            bool b_LongbowDmr{};
            bool b_ChargeRifle{};
            bool b_Sentinel{};
            bool b_Wingman = true;
            bool b_Ammo = true;
        } Sniper;

        struct FShoutgun {
            bool b_EVA8Auto;
            bool b_Peacekeeper;
            bool b_MozambiqueShotgun;
            bool b_Ammo;
            bool b_MastiffShotgun;
        } Shoutgun{};

        struct FAirDropWeapon {
            bool b_Kraber50CalSniper = true;
            bool b_BocekCompoundBow = true;
            bool b_RampageLmg = true;
            bool b_ThrowingKnife{};
            bool b_RE45Auto = true;
        } AirDropWeapon;

        struct FEquipment {
            struct FHelmet {
                bool b_Lv1{};
                bool b_Lv2 = true;
                bool b_Lv3 = true;
                bool b_Lv4 = true;
            } Helmet;

            struct FShield {
                bool b_Lv1{};
                bool b_Lv2{};
                bool b_Lv3 = true;
                bool b_Lv4 = true;
                bool b_Lv5 = true;
            } Shield;

            struct FKnockdownShield {
                bool b_Lv1{};
                bool b_Lv2{};
                bool b_Lv3 = true;
                bool b_Lv4 = true;
            } KnockdownShield;

            struct FBackPack {
                bool b_Lv1{};
                bool b_Lv2 = true;
                bool b_Lv3 = true;
                bool b_Lv4 = true;
            } BackPack;

        } Equipment;

        struct FConsumables {
            struct FHealth {
                bool b_PhoenixKit = true;
                bool b_MedKit = true;
                bool b_Syringe{};
            } Health;

            struct FBattery {
                bool b_ShieldBattery = true;
                bool b_ShieldCell = true;
            } Battery;

            struct FSkill {
                bool b_UltimateAccelerant;
            } Skill{};

        } Consumables;

        struct FMissile {
            bool b_ThermiteGrenade = true;
            bool b_FragGrenade = true;
            bool b_ArcStar = true;
        } Missile;

        struct FSight {
            struct FPrimary {
                bool b_HcogClassic = true;
                bool b_HcogBruiser = true;
                bool b_Holo{};
                bool b_VariableHolo{};
            } Primary;

            struct FIntermediate {
                bool b_HcogRanger;
                bool b_VariableAog;
            } Intermediate{};

            struct FAdvanced {
                bool b_Sniper = true;
                bool b_VariableSniper{};
            } Advanced;

            struct FAriDrop {
                bool b_DigitalThreat = true;
                bool b_DigitalSniperThreat = true;
            } AriDrop;

        } Sight;

        struct FPart {
            struct FStabilizer {
                bool b_Lv1{};
                bool b_Lv2{};
                bool b_Lv3 = true;
                bool b_Lv4 = true;
            } Stabilizer;

            struct FLaserSight {
                bool b_Lv1{};
                bool b_Lv2{};
                bool b_Lv3 = true;
            } LaserSight;

            struct FExtendedMag {
                struct FLight {
                    bool b_Lv1{};
                    bool b_Lv2{};
                    bool b_Lv3 = true;
                    bool b_Lv4 = true;
                } Light;

                struct FHeavy {
                    bool b_Lv1{};
                    bool b_Lv2{};
                    bool b_Lv3 = true;
                    bool b_Lv4 = true;
                } Heavy;

                struct FEnergy {
                    bool b_Lv1{};
                    bool b_Lv2{};
                    bool b_Lv3 = true;
                    bool b_Lv4 = true;
                } Energy;

                struct FSniper {
                    bool b_Lv1{};
                    bool b_Lv2{};
                    bool b_Lv3 = true;
                    bool b_Lv4 = true;
                } Sniper;

                struct FShotgun {
                    bool b_Lv1;
                    bool b_Lv2;
                    bool b_Lv3;
                } Shotgun{};

            } ExtendedMag;

            struct FStock {
                struct FStandar {
                    bool b_Lv1{};
                    bool b_Lv2 = true;
                    bool b_Lv3 = true;
                } Standar;

                struct FSniper {
                    bool b_Lv1;
                    bool b_Lv2;
                    bool b_Lv3;
                } Sniper{};

            } Stock;

            struct FOthers {
                bool b_Turbocharger = true;
                bool b_SkullpiercerRifling{};
                bool b_HammerpointRounds{};
                bool b_AnvilReceiver = true;
                bool b_QuickdrawHolster{};
                bool b_DeadeyeTempo = true;
                bool b_ShatterCaps = true;
                bool b_KineticFeeder{};
                bool b_BoostedLoader = true;
                bool b_DualLoader = true;
            } HopUp;
        } Part;

    } Item;

    bool b_BuffParts{};

    bool  b_OpenAim = true;
    float f_Smooth = 3.0f;
    float f_AimFov = 5.5f;

    int   i_AimKey = 1;
    int   i_TargeterKey = 70;
    int   i_OpenAim = 84;
    int   i_bunnyhop = 66;

    bool b_Chinese{};


    int ConfigSize = 0;
    std::string ConfigList[100] = { };

    void SetConfig(const std::string& user, const std::string& name) const;
    void GetConfig(std::string user, std::string name) const;
    void GetConfigList(std::string user) const;
    void DeleteConfig(std::string user, std::string name) const;

    void GetConfigList_Callbak(const std::string& json_string);
    void GetConfig_Callbak(const std::string& json_string);
};

static FConfig Config;

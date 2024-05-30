#include"equipment_factory.h"

Equipment* AccessoryFactory::createEquipment(const std::string& quality) {

    if (quality == "普通") return new LeatherArmor();
    if (quality == "稀有") return new ChainmailArmor();
    if (quality == "传说") return new DragonScaleArmor();
    return nullptr;
}
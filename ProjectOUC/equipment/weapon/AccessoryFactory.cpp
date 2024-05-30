#include"equipment_factory.h"

Equipment* AccessoryFactory::createEquipment(const std::string& quality) {

    if (quality == "��ͨ") return new LeatherArmor();
    if (quality == "ϡ��") return new ChainmailArmor();
    if (quality == "��˵") return new DragonScaleArmor();
    return nullptr;
}
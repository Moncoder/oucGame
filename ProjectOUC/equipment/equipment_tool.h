#pragma once
#include <vector>
#include <map>
#include "equipment_factory.h"

enum class EquipmentType { Weapon, Armor, Accessory };

class EquipmentTool {
public:
    EquipmentTool() {
        std::srand(std::time(nullptr));
        initProbability();
    }

    ~EquipmentTool() {
        for (Equipment* equipment : equipments) {
            delete equipment;
        }
    }

    // 随机生成装备
    Equipment* generateEquipment(EquipmentType type) {
        std::string quality = getQuality();
        EquipmentFactory* factory = getFactory(type);
        if (factory) {
            Equipment* equipment = factory->createEquipment(quality);
            if (equipment) {
                equipments.push_back(equipment);
            }
            delete factory;
            return equipment;
        }
        return nullptr;
    }

    // 删除装备
    void removeEquipment(Equipment* equipment) {
        auto it = std::find(equipments.begin(), equipments.end(), equipment);
        if (it != equipments.end()) {
            equipments.erase(it);
        }
    }

private:
    std::vector<Equipment*> equipments;
    std::map<std::string, int> probability;

    void initProbability() {
        // 初始化不同品质的概率
        probability["普通"] = 70;
        probability["稀有"] = 20;
        probability["传说"] = 10;
    }

    std::string getQuality() {
        int total = 0;
        for (const auto& p : probability) {
            total += p.second;
        }

        int rand = std::rand() % total;
        int cumulative = 0;
        for (const auto& p : probability) {
            cumulative += p.second;
            if (rand < cumulative) {
                return p.first;
            }
        }
        return "普通";
    }

    EquipmentFactory* getFactory(EquipmentType type) {
        switch (type) {
        case EquipmentType::Weapon:
            return new WeaponFactory();
        case EquipmentType::Armor:
            return new ArmorFactory();
        case EquipmentType::Accessory:
            return new AccessoryFactory();
        default:
            return nullptr;
        }
    }
};

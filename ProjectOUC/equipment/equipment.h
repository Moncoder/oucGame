#include <iostream>
#include <string>

class Equipment {
protected:
    std::string name;
    std::string description;
    int space;        // 占用空间
    int durability;   // 耐久度（0—100）
    int level;        // 等级（1—3级）
    std::string quality;      // 品质（普通、稀有、史诗、传奇）

public:
    // 构造函数
    Equipment(const std::string& name, const std::string& description, int space, int durability, int level, 
        const std::string& quality)
        : name(name), description(description), space(space), durability(durability), level(level), quality(quality) {}

    // 析构函数
    virtual ~Equipment() {}

    // Setters
    void setName(const std::string& name) { this->name = name; }
    void setDescription(const std::string& description) { this->description = description; }
    void setSpace(int space) { this->space = space; }
    void setDurability(int durability) { this->durability = durability; }
    void setLevel(int level) { this->level = level; }
    void setQuality(const std::string& quality) { this->quality = quality; }

    // Getters
    std::string getName() const { return name; }
    std::string getDescription() const { return description; }
    int getSpace() const { return space; }
    int getDurability() const { return durability; }
    int getLevel() const { return level; }
    std::string getQuality() const { return quality; }

    // 显示信息函数
    virtual void display() const {
        std::cout << "名称: " << name << std::endl;
        std::cout << "描述: " << description << std::endl;
        std::cout << "占用空间: " << space << std::endl;
        std::cout << "耐久度: " << durability << std::endl;
        std::cout << "等级: " << level << std::endl;
        std::cout << "品质: " << quality << std::endl;
    }

};

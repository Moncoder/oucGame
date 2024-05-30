#include <iostream>
#include <string>

class Equipment {
protected:
    std::string name;
    std::string description;
    int space;        // ռ�ÿռ�
    int durability;   // �;öȣ�0��100��
    int level;        // �ȼ���1��3����
    std::string quality;      // Ʒ�ʣ���ͨ��ϡ�С�ʷʫ�����棩

public:
    // ���캯��
    Equipment(const std::string& name, const std::string& description, int space, int durability, int level, 
        const std::string& quality)
        : name(name), description(description), space(space), durability(durability), level(level), quality(quality) {}

    // ��������
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

    // ��ʾ��Ϣ����
    virtual void display() const {
        std::cout << "����: " << name << std::endl;
        std::cout << "����: " << description << std::endl;
        std::cout << "ռ�ÿռ�: " << space << std::endl;
        std::cout << "�;ö�: " << durability << std::endl;
        std::cout << "�ȼ�: " << level << std::endl;
        std::cout << "Ʒ��: " << quality << std::endl;
    }

};

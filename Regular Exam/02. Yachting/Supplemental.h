#ifndef __SUPPLEMENTAL_H
#define __SUPPLEMENTAL_H

#include "Info.h"
#include "Named.h"
#include <string>
#include <sstream>
#include <memory>
#include <map>

class Supplement : public Info , public Named {

        std::string name;

    public:
        Supplement() = default;
        Supplement(const std::string & name) : name(name) {}
        Supplement(const Supplement &) = default;
        Supplement(Supplement &&) = default;

        virtual ~Supplement() = default;

        virtual std::string getInfo() const override { return name; };

        virtual std::string getName() const override { return name; }
};

class Passenger : public Supplement {

    public:
        Passenger() = default;
        Passenger(const std::string & name) : Supplement(name) {}

};

class Supply : public Supplement {

    int quantity = 0;

    public:
        Supply() = default;
        Supply(const std::string & name, const int quantity) : Supplement(name), quantity(quantity) {}

        virtual std::string getInfo() const override;

        void add(const Supply & s) {
            if (getName() == s.getName())
                quantity += s.quantity;
        }

        int getQuantity() const { return quantity; }

};

class Supplements :  public Info {

    public:
        typedef std::map<std::string, std::unique_ptr<Supplement>> SupplementData;

        Supplement & operator[](const std::string & str) { return *data[str].get(); }

        bool insert(Supplement * sup);
        Supplement * get(const std::string & name);

        virtual std::string getInfo() const override;

    private:
        SupplementData data;
};

#endif
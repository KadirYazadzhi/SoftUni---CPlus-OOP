#include "Yacht.h"

#include <sstream>
#include <iostream>

bool Yacht::onSupplementArrival(Supplement *s) {

    Supply * sp = dynamic_cast<Supply *>(s);
    
    if (sp != nullptr) { // it's Supply
        std::ostringstream ostr;
        // Supply Fuel added to yacht Dreamcatcher. New quantity: 250.
        ostr << "Supply " << s->getName() << " added to yacht " << getName() << ". New quantity: ";
        Supply *sup = dynamic_cast<Supply *>(supplies.get(s->getName()));
        if (sup != nullptr) {
            sup->add(*dynamic_cast<Supply *>(s));
            ostr << sup->getQuantity() << '.';
        } else {
            ostr << sp->getQuantity() << '.';
            supplies.insert(s);
        }
        std::cout << ostr.str() << std::endl;
        return sup == nullptr; // if it was already found in the list - delete the `s` object
    } 
    else 
    { // it must be a Passenger!
        Supplement * sp = passengers.get(s->getName());
        if (sp != nullptr) {
            // Error: passenger John already exists in SeaBreeze crew!
            std::cout << "Error: passenger " << s->getName() << " already exists in " << getName() << " crew!" << std::endl;
            return false; // another passenger with the same name exists - the new one must be deleted
        }
        passengers.insert(s);

        // Passenger Michael added to crew. New crew: [Emma, Michael].
        std::cout << "Passenger " << s->getName() << " added to crew. New crew: " << passengers.getInfo() << '.' << std::endl;
        
        return true; // added successfully
    }
};

std::string Yacht::undock() const {
    std::ostringstream ostr;

    //Yacht OceanQueen successfully undocked with passengers [empty] and supplies [empty]. 
    ostr << "Yacht " << getName() << " successfully undocked with "<< getInfo() << '.';

    return ostr.str();
}

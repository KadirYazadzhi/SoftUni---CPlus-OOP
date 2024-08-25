#include <iostream>
#include <sstream>
#include <memory>
#include <map>

#include "Yacht.h"
#include "Supplemental.h"

class Engine {

    typedef std::map<std::string, std::unique_ptr<Yacht> > YachtData;

    YachtData theDock;

    public:

        void processCommand(const std::string & str) {
            std::istringstream istr(str);

            std::string initial;
            istr >> initial;

            if (initial == "Yacht")
                processYacht(istr);
            else if (initial == "Supply")
                processSupply(istr);
            else if (initial == "Passenger")
                processPassenger(istr);
            else
                // ignore unknown command!
                ;

        }

        void finalize(void) {
            if (theDock.size() == 0)
                std::cout << "Dock empty." << std::endl;
            else
                for (YachtData::iterator it = theDock.begin(); it != theDock.end(); it++) {
                    Yacht * y = it->second.get();
                    // Yacht SeaBreeze remains on dock with passengers [Alice, John] and supplies [Booze:85, Water:20].
                    std:: cout << "Yacht " << y->getName() << " remains on dock with " << y->getInfo() << '.' << std::endl; 
                }
        }

    protected:

        void processYacht(std::istream & istr) {

            std::string name, event;
            istr >> name >> event;

            YachtData::iterator itFound = theDock.find(name);

            if (event == "docking") {
                if (itFound != theDock.end()) {
                    // error - already docked
                    std::cout << "Error: Yacht " << name << " already on dock!" << std::endl;
                } else {
                    Yacht * docking = new Yacht(name);
                    theDock[name] = std::unique_ptr<Yacht>(docking);
                    std::cout << docking->dock() << std::endl;
                }
            } else if (event == "undocking") {
                if (itFound == theDock.end()) {
                    // error - not docked
                    std::cout << "Error: Yacht " << name << " is not on dock!" << std::endl;
                } else {
                    std::cout << itFound->second->undock() << std::endl;
                    theDock.erase(itFound);
                }
            }
        }

        void processSupply(std::istream & istr) {
            std::string waste, action, supplyName, yachtName;
            int supplyQuantity;

            istr >> supplyName >> supplyQuantity >> waste >> yachtName >> action;

            if (action == "arriving") {
                YachtData::iterator itFound = theDock.find(yachtName);
                if (itFound == theDock.end())
                    std::cout << "Error: Yacht " << yachtName << " is not on dock!" << std::endl; 
                else {
                    Supplement * s = new Supply(supplyName, supplyQuantity);
                    if (!itFound->second->onSupplementArrival(s))
                        delete s; // did not get added!
                }
            }
        }

        void processPassenger(std::istream & istr) {
            std::string waste, action, passengerName, yachtName;
            int supplyQuantity;

            istr >> passengerName >> action >> waste >> yachtName;

            if (action == "arrived") {
                YachtData::iterator itFound = theDock.find(yachtName);
                if (itFound == theDock.end())
                    std::cout << "Error: Yacht " << yachtName << " is not on dock!" << std::endl;
                else {
                    Supplement * p = new Passenger(passengerName);
                    if (!itFound->second->onSupplementArrival(p)) {
                        delete p; // did not get added!
                    }
                }
            }
        }

};

int main() {

    Engine e;

    std::string str;
    while(getline(std::cin, str) && str != "End")
        e.processCommand(str);

    e.finalize();

    return 0;
}
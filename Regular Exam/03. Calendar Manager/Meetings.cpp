
#include "Meetings.h"

Meeting::Meeting(size_t inputOrder, std::istream & is) : inputOrder(inputOrder) {
    is >> id >> dtp;
}

Meeting::Meeting(size_t inputOrder, const std::string & id, const DateTimePeriod & dtp) 
    : inputOrder(inputOrder), id(id), dtp(dtp) {}

bool Meeting::doesOverlapWith(const Meeting * m) const {
    if (m == this)
        return false;
    
    return dtp.doesOverlapWith(m->dtp);
}

void Meeting::registerParticipant(const Participant *part) { 
    participants.insert(part);
}


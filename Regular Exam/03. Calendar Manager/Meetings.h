#ifndef __MEETING_H
#define __MEETING_H

#include <string>
#include <set>
#include <memory>
#include "DateTime.h"
#include "Participant.h"

class Meeting {
    std::string id;
    DateTimePeriod dtp;
    std::set<const Participant *> participants;
    size_t inputOrder;

public:
    Meeting(size_t inputOrder, std::istream & is);
    Meeting(size_t inputOrder, const std::string & id, const DateTimePeriod & dtp);

    std::string getId() const { return id; }
    DateTimePeriod getDateTimePeriod() const { return dtp; }
    size_t getInputOrder() const { return inputOrder; }

    bool doesOverlapWith(const Meeting * m) const;
    void registerParticipant(const Participant *part);

    typedef std::set<const Participant *> Participants;

    Participants getParticipants() const { return participants; }

    bool hasParticipant(const Participant *part) const {
        return participants.find(part) != participants.end();
    }

    int participantCount() const { return participants.size(); }  // Имплементация на метода participantCount
};

#endif



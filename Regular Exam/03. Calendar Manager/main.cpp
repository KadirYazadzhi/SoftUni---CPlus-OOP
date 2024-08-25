
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <sstream>
#include <iomanip>

#include "DateTime.h"
#include "Meetings.h"
#include "Contributor.h"

class Engine {

        typedef std::multimap<std::string, std::unique_ptr<Meeting>> MeetingsData;
        MeetingsData meetings;

        typedef std::map<std::string, std::unique_ptr<Participant>> ParticipantsData; 
        ParticipantsData participants;

        std::ostream & errorStream;

    public:

        Engine(std::ostream & errorStream) : errorStream(errorStream) { }

        void process(std::istream & is);
        void checkErrors() const;

    protected:

        void registerParticipant(const std::string & meetingID, Participant *p);

        void checkEmptyMeetings() const;
        void checkParticipantAvailability() const;
};

void Engine::process(std::istream & is) {

    size_t meetingOrder = 1;

    std::string line;
    while(getline(is, line) && line != ".") {
        std::istringstream is(line);

        std::string type;

        is >> type;
        if (type[0] == 'M') {
            Meeting * m = new Meeting(meetingOrder++, is);
            meetings.insert(std::pair<std::string, std::unique_ptr<Meeting>>(m->getId(), std::unique_ptr<Meeting>(m)));
        }
        else if (type[0] == 'C') {

            std::string meetingId;
            is >> meetingId;

            std::unique_ptr<Participant> part = std::make_unique<Contributor>(is);
            ParticipantsData::iterator itPD = participants.find(part->getId());
            Participant *pUpdate;
            if (itPD != participants.end()) {
                // this participant already exists
                pUpdate = itPD->second.get();
            } else {
                pUpdate = part.get();
                // new participant - save the data
                participants.emplace(part->getId(), std::move(part));
            }

            registerParticipant(meetingId, pUpdate);

        } else
            ; // ignore anything else
    }

}

void Engine::registerParticipant(const std::string & meetingID, Participant *c) {

    MeetingsData::iterator itM = meetings.find(meetingID);
    if (itM == meetings.end())
        // error message
        // `FirstName SecondName: No meeting MeetingID.`, for example `Stamat Stamatov: No meeting StrangeMeeting.`.
        errorStream << c->toString() << ": No meeting " << meetingID << '.' << std::endl;
    else
        itM->second.get()->registerParticipant(c);
}


void Engine::checkErrors() const {

    checkEmptyMeetings();
    checkParticipantAvailability();

}

void Engine::checkEmptyMeetings() const {

    for(auto itM = meetings.begin();itM != meetings.end();itM++) {
        Meeting * m = itM->second.get();
        if (m->participantCount() == 0) {
            errorStream << "Meeting " << m->getId() << " has no participants." << std::endl;
        }
    }

}

void Engine::checkParticipantAvailability() const {

    // Create the processing order is all meetings: all meetings, ordered by their:
    //   Start time of the meeting + the length of the meeting + the creation order of the meeting
    std::map<std::string, const Meeting *> processingOrder;
    for(auto itM = meetings.begin(); itM != meetings.end(); itM++) {
        Meeting * m = itM->second.get();
        std::ostringstream ostr;
        ostr << m->getDateTimePeriod().toString() << '_' << std::setw(4) << std::setfill('0') << m->getInputOrder();
        processingOrder.insert(std::pair<std::string, const Meeting *>(ostr.str(), m));
    }

    for(auto itM = processingOrder.begin();itM != processingOrder.end();itM++) {
        const Meeting * m = itM->second;
        Meeting::Participants parts = m->getParticipants();

        // check each participants availability for the meetings *after* the meeting in itM
        for(auto itP = parts.begin(); itP != parts.end(); itP++) {
            const Participant * part = *itP;
            auto itNextM = itM;
            for(itNextM++; itNextM != processingOrder.end(); itNextM++) {
                const Meeting * meetingToCheck = itNextM->second;
                if (meetingToCheck->hasParticipant(part)) {
                    // let's see if the two meetings overlap. 
                    if (m->doesOverlapWith(meetingToCheck)) {
                        // John Doe cannot attend InternalDiscussion meeting: still in ClientMeeting meeting.
                        errorStream << part->toString() << " cannot attend " << meetingToCheck->getId() << " meeting: still in " << m->getId() << " meeting." << std::endl;
                    }
                }
            }
            
        }
    }

}

int main() {

    std::ostringstream errorStream;
    Engine e(errorStream);

    e.process(std::cin);
    e.checkErrors();

    std::string result = errorStream.str();
    if (result.length() == 0) {
        std::cout << "No errors." << std::endl;
    } else
        std::cout << result;

    return 0;
}
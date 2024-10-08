//Author Name: Omkar Mhamal
//Roll No: 30
//Title: Goa Legislative Assembly implemented using OOP's concept
//Start Date: 15-07-2024 
//Modified Date: 22-07-2024
//Description: Goa Legislative Assembly's various features and function are represented using object oriented approach.

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Member;
class Speaker;
class DeputySpeaker;
class ChiefMinister;
class Session;
class Committee;
class Bill;

// Member class
class Member {
private:
    string name;
    string constituency;
    string party;
    bool isNominated;

public:
    Member(string name, string constituency, string party, bool isNominated)
        : name(name), constituency(constituency), party(party), isNominated(isNominated) {}

    string getName() const { return name; }
    string getConstituency() const { return constituency; }
    string getParty() const { return party; }
    bool getIsNominated() const { return isNominated; }
};

// Speaker class
class Speaker {
private:
    string name;

public:
    Speaker(string name) : name(name) {}

    string getName() const { return name; }
};

// DeputySpeaker class
class DeputySpeaker {
private:
    string name;

public:
    DeputySpeaker(string name) : name(name) {}

    string getName() const { return name; }
};

// ChiefMinister class
class ChiefMinister {
private:
    string name;
    string party;

public:
    ChiefMinister(string name, string party) : name(name), party(party) {}

    string getName() const { return name; }
    string getParty() const { return party; }
};

// Session class
class Session {
private:
    string name;
    string startDate;
    string endDate;

public:
    Session(string name, string startDate, string endDate)
        : name(name), startDate(startDate), endDate(endDate) {}

    string getName() const { return name; }
    string getStartDate() const { return startDate; }
    string getEndDate() const { return endDate; }
};

// Committee class
class Committee {
private:
    string name;
    string type;

public:
    Committee(string name, string type) : name(name), type(type) {}

    string getName() const { return name; }
    string getType() const { return type; }
};

// Bill class
class Bill {
private:
    string title;
    string description;

public:
    Bill(string title, string description) : title(title), description(description) {}

    string getTitle() const { return title; }
    string getDescription() const { return description; }
};

// LegislativeAssembly class
class LegislativeAssembly {
private:
    string name;
    vector<Member> members;
    Speaker *speaker;
    DeputySpeaker *deputySpeaker;
    ChiefMinister *chiefMinister;
    vector<Session> sessions;
    vector<Committee> committees;
    vector<Bill> bills;

public:
    LegislativeAssembly(string name) : name(name), speaker(nullptr), deputySpeaker(nullptr), chiefMinister(nullptr) {}

    void addMember(Member member) {
        members.push_back(member);
    }

    void electSpeaker(Speaker *speaker) {
        this->speaker = speaker;
    }

    void electDeputySpeaker(DeputySpeaker *deputySpeaker) {
        this->deputySpeaker = deputySpeaker;
    }

    void appointChiefMinister(ChiefMinister *chiefMinister) {
        this->chiefMinister = chiefMinister;
    }

    void callSession(Session session) {
        sessions.push_back(session);
    }

    void formCommittee(Committee committee) {
        committees.push_back(committee);
    }

    void introduceBill(Bill bill) {
        bills.push_back(bill);
    }

    const vector<Bill>& getBills() const {
        return bills;
    }

    void passBill(const Bill& bill) {
        cout << "Bill passed: " << bill.getTitle() << endl;
    }

    void display() const {
        cout << "Legislative Assembly Details:" << endl;
        cout << "Name: " << name << endl;

        // Display Speaker
        if (speaker != nullptr) {
            cout << "Speaker: " << speaker->getName() << endl;
        } else {
            cout << "Speaker: Not elected yet." << endl;
        }

        // Display Deputy Speaker
        if (deputySpeaker != nullptr) {
            cout << "Deputy Speaker: " << deputySpeaker->getName() << endl;
        } else {
            cout << "Deputy Speaker: Not elected yet." << endl;
        }

        // Display Chief Minister
        if (chiefMinister != nullptr) {
            cout << "Chief Minister: " << chiefMinister->getName() << " (" << chiefMinister->getParty() << ")" << endl;
        } else {
            cout << "Chief Minister: Not appointed yet." << endl;
        }

        // Display Members
        cout << "Members:" << endl;
        for (const auto& member : members) {
            cout << "- Name: " << member.getName() << ", Constituency: " << member.getConstituency()
                 << ", Party: " << member.getParty();
            if (member.getIsNominated()) {
                cout << " (Reserved)" << endl;
            } else {
                cout << " (Unreserved)" << endl;
            }
        }

        // Display Sessions
        cout << "Sessions:" << endl;
        for (const auto& session : sessions) {
            cout << "- Name: " << session.getName() << ", Start Date: " << session.getStartDate()
                 << ", End Date: " << session.getEndDate() << endl;
        }

        // Display Committees
        cout << "Committees:" << endl;
        for (const auto& committee : committees) {
            cout << "- Name: " << committee.getName() << ", Type: " << committee.getType() << endl;
        }

        // Display Bills
        cout << "Bills:" << endl;
        for (const auto& bill : bills) {
            cout << "- Title: " << bill.getTitle() << ", Description: " << bill.getDescription() << endl;
        }
    }
};

// Main function
int main() {
    LegislativeAssembly assembly("Goa");
    bool exit = false;

    while (!exit) {
        cout << "\nMenu:" << endl;
        cout << "1. Add Member" << endl;
        cout << "2. Elect Speaker" << endl;
        cout << "3. Elect Deputy Speaker" << endl;
        cout << "4. Appoint Chief Minister" << endl;
        cout << "5. Call Session" << endl;
        cout << "6. Form Committee" << endl;
        cout << "7. Introduce Bill" << endl;
        cout << "8. Pass Bill" << endl;
        cout << "9. Display Assembly Details" << endl;
        cout << "10. Exit" << endl;
        cout << "Choose an option: ";

        int choice;
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                string name, constituency, party;
                bool isNominated;
                cout << "Enter member name: ";
                getline(cin, name);
                cout << "Enter constituency: ";
                getline(cin, constituency);
                cout << "Enter party: ";
                getline(cin, party);
                while(1){
                    cout << "Is elected from Reserved Seat? (1 for true/ 0 for false): ";
                    cin >> isNominated;
                    if(isNominated==1 || isNominated==0){
                        cin.ignore();
                        break;
                    }
                    else{cout << "\n Enter 0 or 1";}
                    cin.ignore();
                }
                Member member(name, constituency, party, isNominated);
                assembly.addMember(member);
                break;
            }
            case 2: {
                string name;
                cout << "Enter speaker name: ";
                getline(cin, name);
                Speaker speaker(name);
                assembly.electSpeaker(&speaker);
                break;
            }
            case 3: {
                string name;
                cout << "Enter deputy speaker name: ";
                getline(cin, name);
                DeputySpeaker deputySpeaker(name);
                assembly.electDeputySpeaker(&deputySpeaker);
                break;
            }
            case 4: {
                string name, party;
                cout << "Enter chief minister name: ";
                getline(cin, name);
                cout << "Enter party: ";
                getline(cin, party);
                ChiefMinister chiefMinister(name, party);
                assembly.appointChiefMinister(&chiefMinister);
                break;
            }
            case 5: {
                string name, startDate, endDate;
                cout << "Enter session name: ";
                getline(cin, name);
                cout << "Enter start date (YYYY-MM-DD): ";
                getline(cin, startDate);
                cout << "Enter end date (YYYY-MM-DD): ";
                getline(cin, endDate);
                Session session(name, startDate, endDate);
                assembly.callSession(session);
                break;
            }
            case 6: {
                string name, type;
                cout << "Enter committee name: ";
                getline(cin, name);
                cout << "Enter committee type (Standing/Ad hoc): ";
                getline(cin, type);
                Committee committee(name, type);
                assembly.formCommittee(committee);
                break;
            }
            case 7: {
                string title, description;
                cout << "Enter bill title: ";
                getline(cin, title);
                cout << "Enter bill description: ";
                getline(cin, description);
                Bill bill(title, description);
                assembly.introduceBill(bill);
                break;
            }
            case 8: {
                string title;
                cout << "Enter bill title: ";
                getline(cin, title);
                const vector<Bill>& bills = assembly.getBills();
                bool billFound = false;
                for (const auto& b : bills) {
                    if (b.getTitle() == title) {
                        assembly.passBill(b);
                        billFound = true;
                        break;
                    }
                }
                if (!billFound) {
                    cout << "Bill not found." << endl;
                }
                break;
            }
            case 9:
                assembly.display();
                break;
            case 10:
                exit = true;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

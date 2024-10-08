# //Author Name: Omkar Mhamal
# //Roll No: 30
# //Title: Goa Legislative Assembly implemented using OOP's concept
# //Start Date: 15-07-2024 
# //Modified Date: 22-07-2024
# //Description: Goa Legislative Assembly's various features and function are represented using object oriented approach.


# Define Member class
class Member:
    def __init__(self, name, constituency, party, is_nominated):
        self.name = name
        self.constituency = constituency
        self.party = party
        self.is_nominated = is_nominated

# Define Speaker class
class Speaker:
    def __init__(self, name):
        self.name = name

# Define DeputySpeaker class
class DeputySpeaker:
    def __init__(self, name):
        self.name = name

# Define ChiefMinister class
class ChiefMinister:
    def __init__(self, name, party):
        self.name = name
        self.party = party

# Define Session class
class Session:
    def __init__(self, name, start_date, end_date):
        self.name = name
        self.start_date = start_date
        self.end_date = end_date

# Define Committee class
class Committee:
    def __init__(self, name, type):
        self.name = name
        self.type = type

# Define Bill class
class Bill:
    def __init__(self, title, description):
        self.title = title
        self.description = description

# Define LegislativeAssembly class
class LegislativeAssembly:
    def __init__(self, name):
        self.name = name
        self.members = []
        self.speaker = None
        self.deputy_speaker = None
        self.chief_minister = None
        self.sessions = []
        self.committees = []
        self.bills = []

    def add_member(self, member):
        self.members.append(member)

    def elect_speaker(self, speaker):
        self.speaker = speaker

    def elect_deputy_speaker(self, deputy_speaker):
        self.deputy_speaker = deputy_speaker

    def appoint_chief_minister(self, chief_minister):
        self.chief_minister = chief_minister

    def call_session(self, session):
        self.sessions.append(session)

    def form_committee(self, committee):
        self.committees.append(committee)

    def introduce_bill(self, bill):
        self.bills.append(bill)

    def pass_bill(self, bill):
        self.bills.remove(bill)

    def get_bills(self):
        return self.bills

    def __str__(self):
        details = f"Legislative Assembly: {self.name}\n"
        details += "Members:\n"
        for member in self.members:
            details += f"  - {member.name}, {member.constituency}, {member.party} , {member.is_nominated}\n"
        details += f"Speaker: {self.speaker.name if self.speaker else 'Not elected yet'}\n"
        details += f"Deputy Speaker: {self.deputy_speaker.name if self.deputy_speaker else 'Not elected yet'}\n"
        details += f"Chief Minister: {self.chief_minister.name if self.chief_minister else 'Not appointed yet'}\n"
        details += "Sessions:\n"
        for session in self.sessions:
            details += f"  - {session.name}, {session.start_date} to {session.end_date}\n"
        details += "Committees:\n"
        for committee in self.committees:
            details += f"  - {committee.name}, {committee.type}\n"
        details += "Bills:\n"
        for bill in self.bills:
            details += f"  - {bill.title}, {bill.description}\n"
        return details

#Main program
if __name__ == "__main__":
    assembly = LegislativeAssembly("Goa")
    
    while True:
        print("\nMenu:")
        print("1. Add member")
        print("2. Elect Speaker")
        print("3. Elect Deputy Speaker")
        print("4. Appoint Chief Minister")
        print("5. Call Session")
        print("6. Form Committee")
        print("7. Introduce Bill")
        print("8. Pass Bill")
        print("9. Display Assembly Details")
        print("10. Exit")
        
        choice = int(input("Choose an option: "))
        
        if choice == 1:
            name = input("Enter member name: ")
            constituency = input("Enter constituency: ")
            party = input("Enter party: ")
            k=True
         
            while k:
                is_nominated = input("Is elected from Reserved Seat ? (true/false): ").lower()    
                if is_nominated == 'true' or is_nominated =='false':
                    break
                print("Enter either true or false")
            member = Member(name, constituency, party, is_nominated)
            assembly.add_member(member)
        
        elif choice == 2:
            name = input("Enter speaker name: ")
            speaker = Speaker(name)
            assembly.elect_speaker(speaker)
        
        elif choice == 3:
            name = input("Enter deputy speaker name: ")
            deputy_speaker = DeputySpeaker(name)
            assembly.elect_deputy_speaker(deputy_speaker)
        
        elif choice == 4:
            name = input("Enter chief minister name: ")
            party = input("Enter party: ")
            chief_minister = ChiefMinister(name, party)
            assembly.appoint_chief_minister(chief_minister)
        
        elif choice == 5:
            name = input("Enter session name: ")
            start_date = input("Enter start date (YYYY-MM-DD): ")
            end_date = input("Enter end date (YYYY-MM-DD): ")
            session = Session(name, start_date, end_date)
            assembly.call_session(session)
        
        elif choice == 6:
            name = input("Enter committee name: ")
            type = input("Enter committee type (Standing/Ad hoc): ")
            committee = Committee(name, type)
            assembly.form_committee(committee)
        
        elif choice == 7:
            title = input("Enter bill title: ")
            description = input("Enter bill description: ")
            bill = Bill(title, description)
            assembly.introduce_bill(bill)
        
        elif choice == 8:
            title = input("Enter bill title: ")
            bill = next((b for b in assembly.get_bills() if b.title == title), None)
            if bill:
                assembly.pass_bill(bill)
            else:
                print("Bill not found.")
        
        elif choice == 9:
            print(assembly)
        
        elif choice == 10:
            break
        
        else:
            print("Invalid choice. Please try again.")

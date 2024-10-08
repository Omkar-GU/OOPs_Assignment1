//Author Name: Omkar Mhamal
//Roll No: 30
//Title: Goa Legislative Assembly implemented using OOP's concept
//Start Date: 15-07-2024 
//Modified Date: 22-07-2024
//Description: Goa Legislative Assembly's various features and function are represented using object oriented approach.

using System;
using System.Collections.Generic;

namespace Goa
{
    public class Speaker
    {
        private string name;

        public Speaker(string name)
        {
            this.name = name;
        }

        public override string ToString()
        {
            return name;
        }
    }

    public class Session
    {
        private string sessionName;
        private string startDate;
        private string endDate;

        public Session(string sessionName, string startDate, string endDate)
        {
            this.sessionName = sessionName;
            this.startDate = startDate;
            this.endDate = endDate;
        }

        public override string ToString()
        {
            return $"{sessionName} ({startDate} to {endDate})";
        }
    }

    public class Member
    {
        private string name;
        private string constituency;
        private string party;
        private bool isReservedSeat;

        public Member(string name, string constituency, string party, bool isReservedSeat)
        {
            this.name = name;
            this.constituency = constituency;
            this.party = party;
            this.isReservedSeat = isReservedSeat;
        }

        public override string ToString()
        {
            return $"{name} ({party})";
        }
    }

    public class LegislativeAssembly
    {
        private string stateName;
        private List<Member> members;
        private Speaker speaker;
        private DeputySpeaker deputySpeaker;
        private ChiefMinister chiefMinister;
        private List<Session> sessions;
        private List<Committee> committees;
        private List<Bill> bills;

        public LegislativeAssembly(string stateName)
        {
            this.stateName = stateName;
            this.members = new List<Member>();
            this.sessions = new List<Session>();
            this.committees = new List<Committee>();
            this.bills = new List<Bill>();
        }

        public void AddMember(Member member)
        {
            members.Add(member);
        }

        public void ElectSpeaker(Speaker speaker)
        {
            this.speaker = speaker;
        }

        public void ElectDeputySpeaker(DeputySpeaker deputySpeaker)
        {
            this.deputySpeaker = deputySpeaker;
        }

        public void AppointChiefMinister(ChiefMinister chiefMinister)
        {
            this.chiefMinister = chiefMinister;
        }

        public void CallSession(Session session)
        {
            sessions.Add(session);
        }

        public void FormCommittee(Committee committee)
        {
            committees.Add(committee);
        }

        public void IntroduceBill(Bill bill)
        {
            bills.Add(bill);
            Console.WriteLine($"Bill {bill.Title} introduced in {stateName} Legislative Assembly.");
        }

        public void PassBill(Bill bill)
        {
            if (bills.Contains(bill))
            {
                Console.WriteLine($"Bill {bill.Title} passed in {stateName} Legislative Assembly.");
            }
            else
            {
                Console.WriteLine($"Bill {bill.Title} has not been introduced yet.");
            }
        }

        public override string ToString()
        {
            return $"State: {stateName}\n" +
                   $"Members: {string.Join(", ", members)}\n" +
                   $"Speaker: {speaker}\n" +
                   $"Deputy Speaker: {deputySpeaker}\n" +
                   $"Chief Minister: {chiefMinister}\n" +
                   $"Sessions: {string.Join(", ", sessions)}\n" +
                   $"Committees: {string.Join(", ", committees)}\n" +
                   $"Bills: {string.Join(", ", bills)}";
        }

        public List<Bill> GetBills()
        {
            return bills;
        }
    }

    public class DeputySpeaker
    {
        private string name;

        public DeputySpeaker(string name)
        {
            this.name = name;
        }

        public override string ToString()
        {
            return name;
        }
    }

    public class Committee
    {
        private string name;
        private string type;

        public Committee(string name, string type)
        {
            this.name = name;
            this.type = type;
        }

        public override string ToString()
        {
            return $"{name} ({type})";
        }
    }

    public class ChiefMinister
    {
        private string name;
        private string party;

        public ChiefMinister(string name, string party)
        {
            this.name = name;
            this.party = party;
        }

        public override string ToString()
        {
            return $"{name} ({party})";
        }
    }

    public class Bill
    {
        private string title;
        private string description;

        public Bill(string title, string description)
        {
            this.title = title;
            this.description = description;
        }

        public string Title => title;

        public override string ToString()
        {
            return $"{title}: {description}";
        }
    }

    public class MainClass
    {
        private static LegislativeAssembly assembly = new LegislativeAssembly("Goa");

        public static void Main(string[] args)
        {
            bool exit = false;

            while (!exit)
            {
                Console.WriteLine("\nMenu:");
                Console.WriteLine("1. Add Member");
                Console.WriteLine("2. Elect Speaker");
                Console.WriteLine("3. Elect Deputy Speaker");
                Console.WriteLine("4. Appoint Chief Minister");
                Console.WriteLine("5. Call Session");
                Console.WriteLine("6. Form Committee");
                Console.WriteLine("7. Introduce Bill");
                Console.WriteLine("8. Pass Bill");
                Console.WriteLine("9. Display Assembly Details");
                Console.WriteLine("10. Exit");
                Console.Write("Choose an option: ");

                int choice = int.Parse(Console.ReadLine());
                Console.WriteLine("---------------------");
                switch (choice)
                {
                    case 1:
                        AddMember();
                        break;
                    case 2:
                        ElectSpeaker();
                        break;
                    case 3:
                        ElectDeputySpeaker();
                        break;
                    case 4:
                        AppointChiefMinister();
                        break;
                    case 5:
                        CallSession();
                        break;
                    case 6:
                        FormCommittee();
                        break;
                    case 7:
                        IntroduceBill();
                        break;
                    case 8:
                        PassBill();
                        break;
                    case 9:
                        DisplayAssemblyDetails();
                        break;
                    case 10:
                        exit = true;
                        break;
                    default:
                        Console.WriteLine("Invalid choice. Please try again.");
                        break;
                }
            }
        }

        private static void AddMember()
        {
            Console.Write("Enter member name: ");
            string name = Console.ReadLine();
            Console.Write("Enter constituency: ");
            string constituency = Console.ReadLine();
            Console.Write("Enter party: ");
            string party = Console.ReadLine();
            Console.Write("Is elected from Reserved Seat ? (true/false): ");
            bool isNominated = bool.Parse(Console.ReadLine());

            Member member = new Member(name, constituency, party, isNominated);
            assembly.AddMember(member);
        }

        private static void ElectSpeaker()
        {
            Console.Write("Enter speaker name: ");
            string name = Console.ReadLine();

            Speaker speaker = new Speaker(name);
            assembly.ElectSpeaker(speaker);
        }

        private static void ElectDeputySpeaker()
        {
            Console.Write("Enter deputy speaker name: ");
            string name = Console.ReadLine();

            DeputySpeaker deputySpeaker = new DeputySpeaker(name);
            assembly.ElectDeputySpeaker(deputySpeaker);
        }

        private static void AppointChiefMinister()
        {
            Console.Write("Enter chief minister name: ");
            string name = Console.ReadLine();
            Console.Write("Enter party: ");
            string party = Console.ReadLine();

            ChiefMinister chiefMinister = new ChiefMinister(name, party);
            assembly.AppointChiefMinister(chiefMinister);
        }

        private static void CallSession()
        {
            Console.Write("Enter session name: ");
            string name = Console.ReadLine();
            Console.Write("Enter start date (YYYY-MM-DD): ");
            string startDate = Console.ReadLine();
            Console.Write("Enter end date (YYYY-MM-DD): ");
            string endDate = Console.ReadLine();

            Session session = new Session(name, startDate, endDate);
            assembly.CallSession(session);
        }

        private static void FormCommittee()
        {
            Console.Write("Enter committee name: ");
            string name = Console.ReadLine();
            Console.Write("Enter committee type (Standing/Ad hoc): ");
            string type = Console.ReadLine();

            Committee committee = new Committee(name, type);
            assembly.FormCommittee(committee);
        }

        private static void IntroduceBill()
        {
            Console.Write("Enter bill title: ");
            string title = Console.ReadLine();
            Console.Write("Enter bill description: ");
            string description = Console.ReadLine();

            Bill bill = new Bill(title, description);
            assembly.IntroduceBill(bill);
        }

        private static void PassBill()
        {
            Console.Write("Enter bill title: ");
            string title = Console.ReadLine();
            Bill bill = null;
            foreach (Bill b in assembly.GetBills())
            {
                if (b.Title.Equals(title))
                {
                    bill = b;
                    break;
                }
            }
            if (bill != null)
            {
                assembly.PassBill(bill);
            }
            else
            {
                Console.WriteLine("Bill not found.");
            }
        }

        private static void DisplayAssemblyDetails()
        {
            Console.WriteLine(assembly);
        }
    }
}

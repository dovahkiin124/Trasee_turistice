#include <iostream>
#include<string>

#include "Classes.cpp"
using namespace std;
struct User {
    string firstName;
    string lastName;
    string username;
    string password;

    string birthdate;
    string address;
};

bool login() {
    string username, password;
    cout << "Username: ";
    cin >> username;
    cout << "Parola: ";
    cin >> password;

    // Verificam daca fisierul de utilizatori exista
    ifstream usersFile("C:/Users/Asus/Desktop/users.txt");
    if (!usersFile.is_open()) {
        cout << "Nu s-a putut deschide fisierul!" << endl;
        return false;
    }

    // Verificam daca exista un utilizator cu datele introduse
    string line;
    while (getline(usersFile, line)) {
        if (line.find(username + " " + password) != string::npos) {
            cout << "Autentificare facuta cu succes!" << endl;
            usersFile.close();
            return true;
        }
    }

    // Daca nu s-a gasit un utilizator cu datele introduse, afisam un mesaj de eroare
    cout << "Username sau parola invalida!" << endl;
    usersFile.close();
    return false;
}

void registerUser() {
    User user;

    cout << "Numele: ";
    cin >> user.firstName;
    cout << "Prenumele: ";
    cin >> user.lastName;
    cout << "Username: ";
    cin >> user.username;
    cout << "Parola: ";
    cin >> user.password;
    cout << "Data Nasterii: ";
    cin >> user.birthdate;
    cout << "Adresa: ";
    cin >> user.address;

    // Salvam datele utilizatorului in fisierul "users.txt"
    ofstream usersFile("C:/Users/Asus/Desktop/users.txt", ios::app);
    if (!usersFile.is_open()) {
        cout << "Nu s-a putut deschide fisierul!" << endl;
        return;
    }

    usersFile << user.firstName << " "
              << user.lastName << " "
              << user.username << " "
              << user.password << " "
              << user.birthdate << " "
              << user.address << endl;

    usersFile.close();
    cout << "Inregistrare facuta cu succes!" << endl;
}


int main() {
    int Optiune;
    cout<<"1.Administrator"<<endl;
    cout<<"2.Utilizator"<<endl;
    cout << "Selectati o optiune: ";
    cin>>Optiune;
    do{
        AgentieTurism agentie;
        vector<Booking> bookings;

        switch(Optiune)
        {
            case 1: {
                char parola[10];
                const char *parol = "Game"; //Parola admin tip default
                cout << "Introduceti parola admin: ";
                int nr_incercari = 0; // initializare numarator pentru incercarile de introducere a parolei incorecte
                while(nr_incercari < 3) // accepta maxim 3 incercari incorecte
                {
                    cin >> parola;
                    if (strcmp(parol,parola) == 0) //Verificare parola
                    {
                        Meniu_administrator admin;
                        int optiune;
                        do {
                            admin.afiseaza();
                            cin >> optiune;
                            cout << endl;

                            switch (optiune) {
                                case 0:
                                    exit(1);
                                case 1: {
                                    string nume, des;
                                    int pret;

                                    cout << "Introduceti numele pachetului turistic: ";
                                    cin >> nume;
                                    cout << "Introduceti descrierea pachetului turistic: ";
                                    cin >> des;
                                    cout << "Introduceti pretul pachetului turistic: ";
                                    cin >> pret;

                                    PachetTuristic pachet(nume, des, pret);
                                    agentie.adaugaPachetTuristic(pachet);
                                    cout << "Pachetul turistic a fost adaugat cu succes!" << std::endl << std::endl;
                                    break;
                                }
                                case 2:
                                    agentie.afiseazaPachete();
                                    break;
                                case 3: {

                                    string nume, prenume;
                                    cout << "Introduceti numele turistului: " << endl;
                                    cin >> nume;
                                    cout << "Introduceti prenumele turistului: " << endl;
                                    cin >> prenume;


                                    Turist turist(nume, prenume);
                                    agentie.adaugaTurist(turist);



                                    break;
                                }
                                case 4: {
                                    int  turistId;


                                    cout << "Introduceti ID-ul turistului pe care doriti sa il stergeti: ";
                                    cin >> turistId;
                                    agentie.stergeTurist(turistId);
                                    break;



                                }
                                case 5:
                                    readBookingsFromJson(bookings,"C:/Users/Asus/Desktop/rezervari.json");
                                    if (bookings.empty()) {
                                        cout << "Nici o rezervare inca." << endl;
                                    } else {
                                        cout << "Rezervari:" << endl;
                                        for (const auto& booking : bookings) {
                                            cout << "Oferta: " << booking.getOffer().getName() << endl;
                                            cout << "Cantitate: " << booking.getQuantity() << endl;
                                            cout << "Pret total: " << booking.getTotalPrice() << endl << endl;
                                        }
                                    }

                                    break;
                                case 6:
                                {
                                    agentie.afiseazaTuristi();
                                    break;
                                }
                                case 7:
                                {
                                    int id;
                                    cout << "Introduceii ID-ul pachetului de sters: ";
                                    cin >> id;
                                    agentie.stergePachetTuristic(id);
                                    break;
                                }
                                default:
                                    cout << "Optiune invalida! Va rugam sa introduceti o optiune valida." << std::endl
                                         << std::endl;
                            }
                        } while (optiune != 0);
                    }
                    else
                    {
                        nr_incercari++; // incrementeaza numarul de accesari incorecte
                        cout << "Parola incorecta\nIncercati din nou\n";
                    }
                }
                if(nr_incercari >= 3) // daca sunt facute 3incercari incorecte programul se va inchide
                {
                    cout << "Prea multe incercari incorecte. Programul se inchide.";
                    exit(0); //inchidere program
                }
                break;
            }
            case 2:
            {
                cout << "1. Logare" << endl;
                cout << "2. Inregistrare" << endl;


                int choice;
                cin >> choice;

                switch (choice) {
                    case 1:
                    {
                        // Autentificare utilizator
                        bool authenticated = login();

                        // Daca autentificarea a esuat, inchidem aplicatia
                        if (!authenticated) {
                            return 0;
                        }


                        // Afisam meniul principal
                        int option;
                        do {

                            cout << "1. Vizualizare oferte turistice" << endl;
                            cout << "2. Cautare oferte turistice" << endl;
                            cout << "3. Rezervare pachete turistice" << endl;
                            cout << "4. Vizualizare istoric rezervari" << endl;
                            cout << "5. Deconectare" << endl;
                            cout << "Selectati o optiune: ";
                            cin >> option;

                            switch (option) {
                                case 1:
                                    agentie.afiseazaPachete();
                                    break;
                                case 2:
                                    agentie.CautaPacheteTuristice();
                                    break;
                                case 3:
                                    makeBooking(bookings);
                                    if (bookings.empty()) {
                                        cout << "Fara rezervari de salvat." << endl;
                                    } else {

                                        writeBookingsToJson(bookings, "C:/Users/Asus/Desktop/rezervari.json");
                                        cout << "Rezervare salvata." << endl;
                                    }
                                    break;
                                case 4:
                                    readBookingsFromJson(bookings,"C:/Users/Asus/Desktop/rezervari.json");
                                    if (bookings.empty()) {
                                        cout << "Fara rezervari." << endl;
                                    } else {
                                        cout << "Rezervari:" << endl;
                                        for (const auto& booking : bookings) {
                                            cout << "Oferta: " << booking.getOffer().getName() << endl;
                                            cout << "Cantitate: " << booking.getQuantity() << endl;
                                            cout << "Pret total: " << booking.getTotalPrice() << endl << endl;
                                        }
                                    }

                                    break;
                                case 5:
                                    cout << "Deconectare..." << endl;
                                    break;
                                default:
                                    cout << "Optiune invalida!" << endl;
                                    break;
                            }
                        } while (option != 5);
                    }
                        break;
                    case 2:
                        registerUser();
                        break;
                    default:
                        cout << "Optiune Invalida!" << endl;
                        break;
                }


            }
                break;
            default:
                cout<<"Optiune Invalida!!";;
                break;
        }

    }while (true);



}


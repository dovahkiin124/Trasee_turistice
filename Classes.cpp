#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include<fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;
using namespace std;

// Clasa Turist
class Turist {
public:
    Turist(const std::string& nume, const std::string& prenume) : m_nume(nume), m_prenume(prenume), m_id(s_nextId++) {}

    const std::string& getNume() const { return m_nume; }
    const std::string& getPrenume() const { return m_prenume; }
    int getId() const { return m_id; }




private:
    string m_nume;
    string m_prenume;
    int m_id;
    static int s_nextId;
};
int setNextIdp(){
    int i = 1;
    std::ifstream file("C:/Users/Asus/Desktop/fturist.json");
    nlohmann::json j;

    // Verificăm dacă fișierul există și are cel puțin un element
    if (file.is_open() && file.peek() != std::ifstream::traits_type::eof()) {
        file >> j;

        int max_id = 0;
        for (const auto& p : j) {
            // Verificăm dacă elementul "id" există în fișierul JSON
            if (p.find("id") != p.end()) {
                int id = p["id"];
                if (id > max_id) {
                    max_id = id;
                }
            }
        }

        i = max_id + 1;
    }

    return i;
}
int Turist::s_nextId = setNextIdp();

// Clasa PachetTuristic
class PachetTuristic {
public:
    PachetTuristic(const std::string& nume, const std::string& descriere, int pret) : m_nume(nume), m_desc(descriere), m_pret(pret), m_id(s_nextId++) {}
    PachetTuristic(const std::string& nume, const std::string& descriere, int pret,int id) : m_nume(nume), m_desc(descriere), m_pret(pret), m_id(id) {}
    PachetTuristic();

    const string& getNume() const { return m_nume; }
    const string& getDescriere() const { return m_desc; }
    int getPret() const { return m_pret; }
    int getID() const { return m_id; }

    //std::vector<Turist> m_turisti;
private:
    string m_nume;
    string m_desc;
    int m_pret;
    int m_id;
    //std::vector<Turist> m_turisti;

    static int s_nextId;
};
int setNextIdt(){
    int i = 1;
    std::ifstream file("C:/Users/Asus/Desktop/pachete_turistice.json");
    nlohmann::json j;

    // Verificăm dacă fișierul există și are cel puțin un element
    if (file.is_open() && file.peek() != std::ifstream::traits_type::eof()) {
        file >> j;

        int max_id = 0;
        for (const auto& p : j) {
            // Verificăm dacă elementul "id" există în fișierul JSON
            if (p.find("id") != p.end()) {
                int id = p["id"];
                if (id > max_id) {
                    max_id = id;
                }
            }
        }

        i = max_id + 1;
    }

    return i;
}

int PachetTuristic::s_nextId = setNextIdt();



PachetTuristic::PachetTuristic() {}

// Clasa AgentieTurism
class AgentieTurism:PachetTuristic {
public:
    AgentieTurism() {

    }

    void stergeTurist(int id) {
        m_turisti.erase(std::remove_if(m_turisti.begin(), m_turisti.end(), [id](const Turist& turist) { return turist.getId() == id; }), m_turisti.end());

        // Încarca datele JSON din fișier.
        nlohmann::json j;
        std::ifstream file("C:/Users/Asus/Desktop/fturist.json");
        file >> j;

        // Elimina datele din obiectul JSON.
        j.erase(std::remove_if(j.begin(), j.end(), [id](const nlohmann::json& j_turist) { return j_turist["id"] == id; }), j.end());

        // Scrie obiectul JSON actualizat înapoi în fișier.
        std::ofstream out("C:/Users/Asus/Desktop/fturist.json");
        out << std::setw(4) << j << std::endl;
    }
    void adaugaTurist(const Turist& turist) {
        m_turisti.push_back(turist);

        // Încarcă conținutul fișierului într-un obiect JSON.
        nlohmann::json j;
        std::ifstream file("C:/Users/Asus/Desktop/fturist.json");
        if (file.is_open()) {
            file >> j;
        }
        // Adaugă datele noului pachet în obiectul JSON.
        nlohmann::json j_turist;
        j_turist["id"] = turist.getId();
        j_turist["nume"] = turist.getNume();
        j_turist["prenume"] = turist.getPrenume();

        j.push_back(j_turist);


        // Salveaza obiectul JSON într-un fișier.
        std::ofstream file_out("C:/Users/Asus/Desktop/fturist.json");
        file_out << j.dump();
    }
    std::vector<Turist> m_turisti;

    void adaugaPachetTuristic(const PachetTuristic& pachet) {
        m_pachete.push_back(pachet);

        // Încarcă conținutul fișierului într-un obiect JSON.
        nlohmann::json j;
        std::ifstream file("C:/Users/Asus/Desktop/pachete_turistice.json");
        if (file.is_open()) {
            file >> j;
        }

        // Adaugă datele noului pachet în obiectul JSON.
        nlohmann::json j_pachet;
        j_pachet["nume"] = pachet.getNume();
        j_pachet["descriere"] = pachet.getDescriere();
        j_pachet["pret"] = pachet.getPret();
        j_pachet["id"] = pachet.getID();
        j.push_back(j_pachet);

        // Salvează obiectul JSON actualizat înapoi în fișier.
        std::ofstream file_out("C:/Users/Asus/Desktop/pachete_turistice.json");
        file_out << j.dump();

    }

    std::vector<PachetTuristic> m_pachete;

    void stergePachetTuristic(int id) {

        // Verifică dacă pachetul există
        bool found = false;
        for (int i = 0; i < m_pachete.size(); ++i) {
            if (m_pachete[i].getID() == id) {
                found = true;
                break;
            }
        }
        if (!found) {
            std::cout << "Pachetul cu ID-ul " << id << " nu a fost gasit." << std::endl;
            return;
        }


        // Confirmă ștergerea cu utilizatorul
        char confirm;
        std::cout << "Sunteti sigur ca doriti sa stergeti acest pachet? (y/n): ";
        std::cin >> confirm;

        if (confirm == 'y' || confirm == 'Y') {
            // Șterge pachetul din obiectul JSON
            nlohmann::json j;
            std::ifstream file("C:/Users/Asus/Desktop/pachete_turistice.json");
            file >> j;

            int index = -1;
            for (int i = 0; i < j.size(); ++i) {
                if (j[i]["id"] == id) {
                    index = i;
                    break;
                }
            }

            if (index != -1) {
                j.erase(j.begin() + index);
                std::ofstream file_out("C:/Users/Asus/Desktop/pachete_turistice.json");
                file_out << j.dump();
            }

            // Șterge pachetul din vector
            for (auto it = m_pachete.begin(); it != m_pachete.end(); ++it) {
                if (it->getID() == id) {
                    m_pachete.erase(it);
                    break;
                }
            }

            std::cout << "Pachetul cu ID-ul " << id << " a fost sters." << std::endl;
        } else {
            std::cout << "Stergerea a fost anulata." << std::endl;
        }
    }


    void CautaPacheteTuristice() {
        // Citeste pachetele din fișierul JSON.
        std::ifstream file("C:/Users/Asus/Desktop/pachete_turistice.json");
        nlohmann::json j;
        file >> j;

        string query;
        cout << "Introdu o secventa: ";
        cin >> query;

        vector<PachetTuristic> results;
        for (const auto& j_pachet : j) {
            PachetTuristic pachet(j_pachet["nume"], j_pachet["descriere"], j_pachet["pret"], j_pachet["id"]);
            if (pachet.getNume().find(query) != string::npos ||
                pachet.getDescriere().find(query) != string::npos ||
                to_string(pachet.getPret()).find(query) != string::npos ||
                to_string(pachet.getID()).find(query) != string::npos) {
                results.push_back(pachet);
            }
        }

        if (results.empty()) {
            cout << "Nici un rezultat." << endl;
        } else {
            cout << "Cauta rezultate:" << endl;
            for (const auto& pachet : results) {
                cout << "Nume: " << pachet.getNume() << endl;
                cout << "Destinatie: " << pachet.getDescriere() << endl;
                cout << "Pret: " << pachet.getPret() << endl;
                cout << "ID: " << pachet.getID() << endl << endl;
            }
        }
    }


    void afiseazaTuristi() {
        std::ifstream fin("C:/Users/Asus/Desktop/fturist.json");
        if (!fin.is_open()) {
            std::cout << "Eroare la deschiderea fisierului fturist.json!" << std::endl;
            return;
        }

        json data;
        fin >> data;

        std::cout << "Turisti:" << std::endl;
        for (const auto& element : data)  {
            std::cout << "ID: " << element["id"] << ", Nume: " << element["nume"]
                      << ", Prenume: " << element["prenume"] << std::endl;

            std::cout << std::endl;
        }

        fin.close();
    }


    void afiseazaPachete() {
        std::ifstream fin("C:/Users/Asus/Desktop/pachete_turistice.json");
        if (!fin.is_open()) {
            std::cout << "Eroare la deschiderea fisierului pachete_turistice.json!" << std::endl;
            return;
        }

        json data;
        fin >> data;

        std::cout << "Pachete turistice disponibile:" << std::endl;
        for (const auto& element : data)  {
            std::cout << "ID: " << element["id"] << ", Nume: " << element["nume"]
                      << ", Descriere: " << element["descriere"] << ", Pret: " << element["pret"]
                      << std::endl;

            std::cout << std::endl;
        }

        fin.close();
    }



};


// Clasa Meniu
class Meniu_administrator{
public:
    void afiseaza()
    {
        cout << "=== Main Menu ===" << endl;
        cout << "1. Adauga pachet turistic" << std::endl;
        cout << "2. Afiseaza pachete turistice" << std::endl;
        cout << "3. Adauga turist" << std::endl;
        cout << "4. Sterge turist" << std::endl;
        cout << "5. Vizualizare istoric rezervari" << std::endl;
        cout << "6. Afiseaza turisti" <<std::endl;
        cout << "7. Sterge pachet turistic" <<std::endl;
        cout << "0. Iesire" << std::endl;
        cout << "Selectati o optiune: ";
    }
};





// Clasa reprezentand o oferta turistica
class TouristOffer {
public:
    TouristOffer(string name, string description, int price,int ID)
            : name(name), description(description), price(price),id(ID) {}

    string getName() const { return name; }
    string getDescription() const { return description; }
    double getPrice() const { return price; }

private:
    string name;
    string description;
    int price,id;
};

// Clasa reprezentând o rezervare
class Booking {
public:
    Booking(TouristOffer offer, int quantity)
            : offer(offer), quantity(quantity) {}

    TouristOffer getOffer() const { return offer; }
    int getQuantity() const { return quantity; }
    double getTotalPrice() const { return offer.getPrice() * quantity; }

    // Serializeaza rezervarea la JSON
    json toJson() const {
        return {
                {"Numele Ofertei", offer.getName()},
                {"Cantitatea", quantity},
                {"Pret Total", getTotalPrice()}
        };
    }

private:
    TouristOffer offer;
    int quantity;
};

// Funcție pentru efectuarea unei rezervări
void makeBooking(vector<Booking>& bookings) {
    // Încarca ofertele turistice disponibile dintr-un fișier JSON
    std::ifstream file("C:/Users/Asus/Desktop/pachete_turistice.json");
    nlohmann::json j;
    file >> j;

    // Creeaza un vector de obiecte TouristOffer din datele JSON
    vector<TouristOffer> offers;
    for (const auto& offer : j) {
        TouristOffer touristOffer(offer["nume"], offer["descriere"], offer["pret"], offer["id"]);
        offers.push_back(touristOffer);
    }

    // Arată ofertele turistice disponibile
    for (int i = 0; i < offers.size(); ++i) {
        cout << "[" << i << "] ";
        cout << "Nume: " << offers[i].getName() << endl;
        cout << "Descriere: " << offers[i].getDescription() << endl;
        cout << "Pret: " << offers[i].getPrice() << endl;

    }

    // Obține oferta de alegere a utilizatorului
    int offerIndex;
    cout << "Introdu numarul ofertei: ";
    cin >> offerIndex;

    // Obține cantitatea dorită de utilizator
    int quantity;
    cout << "Introdu cantitatea: ";
    cin >> quantity;

    // Creeza un obiect de rezervare și il adauga la vectorul rezervărilor
    Booking booking(offers[offerIndex], quantity);
    bookings.push_back(booking);

    cout << "Rezervare facuta!" << endl;
}


// Funcție pentru scrierea rezervărilor în fișierul JSON
void writeBookingsToJson(const vector<Booking>& bookings, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        json data;
        for (const auto& booking : bookings) {
            data.push_back(booking.toJson());
        }
        file << data.dump(4);
    }
}
// Funcție pentru citirea rezervărilor din fișierul JSON
void readBookingsFromJson(vector<Booking>& bookings, const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        json data;
        file >> data;

        for (const auto& bookingData : data) {
            string offerName = bookingData["Numele Ofertei"];
            int quantity = bookingData["Cantitatea"];
            double totalPrice = bookingData["Pret Total"];

            TouristOffer touristOffer(offerName, "", totalPrice, 0);
            Booking booking(touristOffer, quantity);
            bookings.push_back(booking);
        }

        file.close();
    }
}





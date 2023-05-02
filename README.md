# Trasee_turistice
Se oferă două blocuri de cod pentru a reprezenta funcționalitatea unei agenții de turism folosind limbajul de programare C++. Primul bloc de cod se referă la funcționalitățile de autentificare a utilizatorului și de administrare a agenției de turism, cum ar fi adăugarea de pachete turistice, afișarea pachetelor, adăugarea și ștergerea de turiști și gestionarea rezervărilor. Al doilea bloc de cod definește trei clase: Turist, PachetTuristic și AgentieTurism. Clasa Turist reprezintă un turist, clasa PachetTuristic reprezintă un pachet turistic, iar clasa AgentieTurism reprezintă o agenție de turism. În plus, este folosită biblioteca nlohmann/json pentru citirea și scrierea datelor în format JSON.

Clasa Turist are trei membri de date privați: m_nume și m_prenume de tip string pentru a stoca numele și prenumele turistului, respectiv m_id de tip int pentru a stoca ID-ul unic al turistului. Clasa Turist are un constructor parametrizat care inițializează m_nume, m_prenume și m_id și trei funcții membre publice: getNume() care returnează numele turistului, getPrenume() care returnează prenumele turistului și getId() care returnează ID-ul unic al turistului.

Clasa PachetTuristic are patru membri de date privați: m_nume și m_desc de tip string pentru a stoca numele și descrierea pachetului turistic, respectiv m_pret de tip int pentru a stoca prețul pachetului turistic și m_id de tip int pentru a stoca ID-ul unic al pachetului turistic. Clasa PachetTuristic are doi constructori: un constructor parametrizat care inițializează m_nume, m_desc, m_pret și m_id și un constructor implicit. De asemenea, are patru funcții membre publice: getNume() care returnează numele pachetului turistic, getDestinatie() care returnează descrierea pachetului turistic, getPret() care returnează prețul pachetului turistic și getID() care returnează ID-ul unic al pachetului turistic.

Clasa AgentieTurism reprezintă o agenție de turism și este derivată din clasa PachetTuristic. Clasa AgentieTurism are doi membri de date privați: m_turisti de tip vector<Turist> pentru a stoca turiștii care au cumpărat un pachet turistic și s_nextId de tip int pentru a stoca următorul ID unic al pachetului turistic. Clasa AgentieTurism are un constructor implicit. De asemenea, are trei funcții membre publice: stergeTurist() care elimină un turist din vectorul m_turisti și șterge datele turistului din fișierul "turist.json", adaugaTurist() care adaugă un turist în vectorul m_turisti și scrie datele turistului în fișierul "turist.json" și adaugaPachetTuristic() care adaugă un pachet turistic în vectorul m_pacheteTuristice și scrie datele pachetului turistic în fișierul "pachet.json". Clasa AgentieTurism mai are două funcții membre publice: afiseazaPacheteTuristice() care afișează toate pachetele turistice existente și cautaPachetTuristic() care caută un pachet turistic după ID și returnează un pointer către acel pachet turistic.

Exact, aceste clase și funcții sunt utilizate pentru a gestiona și stoca informații despre oferte turistice și rezervări într-un sistem de rezervare turistică. Clasa TouristOffer definește o ofertă turistică, care este apoi utilizată în clasa Booking pentru a crea o rezervare și pentru a calcula prețul total al acesteia. Funcția writeBookingsToJson scrie informațiile despre rezervări într-un format JSON într-un fișier, în timp ce funcția makeBooking permite utilizatorului să creeze o rezervare prin alegerea unei oferte turistice și specificarea unei cantități.

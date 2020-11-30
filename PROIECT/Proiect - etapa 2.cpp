#include <iostream>
#include <list>
#include <string.h>

using namespace std;

class Carte
{
    char* titlu;
    char* nume_autor;
    string editura;
    int an_publicatie, numar_pagini;
    float pret;
    bool stare_buna;
    const int cod_de_bare;
    static int cod_carte;
    static int nr_pagini;

public:

    Carte():cod_de_bare(cod_carte++) //constructor fara parametrii
    {
        this->titlu = new char[strlen("Necunoscut") + 1];
        strcpy(this->titlu, "Necunoscut");

        this->nume_autor = new char[strlen("Necunoscut") + 1];
        strcpy(this->nume_autor, "Necunoscut");

        this->editura = "Necunoscut";

        this->an_publicatie = 0;
        this->nr_pagini = 300;
        this->pret = 0;
    }

    void Citire_carte()
    {
        char titlu[100];
        char nume_autor[100];
        char editura[100];

        cout<<"Introduceti titlul cartii:";
        cin.get(titlu, 100);
        this->titlu = new char[strlen(titlu) + 1];
        strcpy(this->titlu, titlu);
        cin.ignore(100,'\n');

        cout<<"\nIntroduceti numele autorului:";
        cin.get(nume_autor, 100);
        this->nume_autor = new char[strlen(nume_autor) + 1];
        strcpy(this->nume_autor, nume_autor);
        cin.ignore(100,'\n');

        cout<<"\nIntroduceti editura:";
        getline(cin, this->editura);

        cout<<"\nIntroduceti numarul de pagini ale cartii:";
        cin>>this->numar_pagini;
        cin.ignore(100,'\n');


        cout<<"\nIntroduceti anul in care a fost publicata cartea:";
        cin>>this->an_publicatie;
        cin.ignore(100,'\n');

        cout<<"\nIntroduceti pretul cartii:";
        cin>>this->pret;
        cin.ignore(100,'\n');

        cout<<"\nIntroduceti 1 daca starea cartii este buna sau 0 daca nu este:";
        cin>>this->stare_buna;
        cin.ignore(10,'\n');

        cout<<"\nCodul cartii este:"<<cod_carte;
        cout<<"\n";
    }

    bool Verificare_pagini()
    {
        if(this->numar_pagini != nr_pagini)
        {
            cout<<"\nNumarul de pagini introdus este invalid, cartea trebuie sa aibe 300 de pagini."<<endl;
            cout<<"Pentru a reintroduce numarul de pagini apasati 'r'"<<endl;
            cout<<"Pentru a anula introducere cartii apasati 'n'"<<endl;
            char refacere;
            cin>>refacere;

            if(refacere == 'r')
            {
                while (this->numar_pagini != nr_pagini)
                {
                    cout<<"\nIntroduceti numarul de pagini ale cartii:";
                    cin>>this->numar_pagini;
                    cin.ignore(100,'\n');
                }
            }
            else if(refacere == 'n')
            {
                return false;
            }
            return true;
        }
    }

    Carte(const Carte &carte_veche):cod_de_bare(carte_veche.cod_carte) //copy constructor
    {
        this->titlu = new char[strlen(carte_veche.titlu) + 1];
        strcpy(this->titlu, carte_veche.titlu);

        this->nume_autor = new char[strlen(carte_veche.nume_autor) + 1];
        strcpy(this->nume_autor, carte_veche.nume_autor);

        editura = carte_veche.editura;

        this->numar_pagini = carte_veche.numar_pagini;
        this->an_publicatie = carte_veche.an_publicatie;
        this->pret = carte_veche.pret;

    }

    Carte(int cod, char* titlu, char* nume_autor, string editura, int numar_pagini, int an_publicatie, float pret):cod_de_bare(cod_carte++) // constructor cu parametrii
    {
        this->titlu = new char[strlen(titlu) + 1];
        strcpy(this->titlu, titlu);

        this->nume_autor = new char[strlen(nume_autor) + 1];
        strcpy(this->nume_autor, nume_autor);

        this->editura = editura;

        this->numar_pagini = numar_pagini;

        this->an_publicatie = an_publicatie;

        this->pret = pret;

    }

    Carte(int cod, char* titlu, char* nume_autor, string editura):cod_de_bare(cod_carte++)
    {
        this->titlu = new char[strlen(titlu) + 1];
        strcpy(this->titlu, titlu);

        this->nume_autor = new char[strlen(nume_autor) + 1];
        strcpy(this->nume_autor, nume_autor);

        this->editura = editura;
    }

    void Afisare_carte()
    {
        cout<<"Titlul cartii este: "<< this->titlu<<", iar autorul: "<<this->nume_autor<<", cartea are "<<this->numar_pagini<<" de pagini."<<endl;
        cout<<"A fost publicata in anul "<<this->an_publicatie<< ", la editura "<<this->editura<<" si costa "<<this->pret<<" lei."<<endl;
    }

    void Set_Titlu(char* titlu)
    {
        this->titlu = titlu;
    }

    void Set_Autor(char* nume_autor)
    {
        this->nume_autor = nume_autor;
    }

    char* Get_Titlu()
    {
        return this->titlu;
    }

    char* Get_Nume()
    {
        return this->nume_autor;
    }

    void Getter_Info() const //il folosesc la afisarea listei de carti
    {
        cout<<this->titlu<<" de "<<this->nume_autor;
    }

    bool operator==(const Carte& carte) //supraincarcare == (verificare doar pentru titlu si autor)
    {
        for(int i = 0; i<strlen(this->titlu); i++)
        {
            if(this->titlu[i] != carte.titlu[i])
                return false;
        }
        for(int i = 0; i<strlen(this->nume_autor); i++)
        {
            if(this->nume_autor[i] != carte.nume_autor[i])
                return false;
        }
        return true;
    }

    Carte operator=(const Carte &carte_veche)
    {
        if(this != &carte_veche) //compara doua adrese
        {
            this->titlu = carte_veche.titlu;
            this->nume_autor = carte_veche.nume_autor;
            this->editura = carte_veche.editura;
            this->numar_pagini = carte_veche.numar_pagini;
            this->an_publicatie = carte_veche.an_publicatie;
            this->pret = carte_veche.pret;
        }
        return *this;
    }

    friend ostream& operator<< (ostream& out, const Carte carte)
    {
        out<<"Titlul cartii este: "<< carte.titlu<<", iar autorul: "<<carte.nume_autor<<", cartea are "<<carte.numar_pagini<<" de pagini."<<endl;
        out<<"A fost publicata in anul "<<carte.an_publicatie<< ", la editura "<<carte.editura<<" si costa "<<carte.pret<<" lei."<<endl;
    }

    friend istream& operator>> (istream& in, Carte& carte)
    {
        char titlu[100];
        char nume_autor[100];
        char editura[100];

        cout<<"Introduceti titlul cartii:";
        in.get(titlu, 100);
        in.ignore(100, '\n');

        if(carte.titlu != NULL)
            delete[] carte.titlu;

        carte.titlu = new char[strlen(titlu) + 1];
        strcpy(carte.titlu, titlu);

        cout<<"\nIntroduceti numele autorului:";
        in.get(nume_autor, 100);
        in.ignore(100, '\n');

        if(carte.nume_autor != NULL)
            delete[] carte.nume_autor;

        carte.nume_autor = new char[strlen(nume_autor) + 1];
        strcpy(carte.nume_autor, nume_autor);

        cout<<"\nIntroduceti editura:";
        in.get(editura, 100);
        const char* editurac = editura;
        carte.editura = editurac;
        in.ignore(100, '\n');

        cout<<"\nIntroduceti numarul de pagini ale cartii:";
        in>>carte.numar_pagini;
        in.ignore(100, '\n');

        cout<<"\nIntroduceti anul in care a fost publicata cartea:";
        in>>carte.an_publicatie;
        in.ignore(100, '\n');

        cout<<"\nIntroduceti pretul cartii:";
        in>>carte.pret;
        in.ignore(100, '\n');

        cout<<"\nIntroduceti 1 daca starea cartii este buna sau 0 daca nu este:";
        in>>carte.stare_buna;
        in.ignore(100, '\n');

        return in;
    }

    Carte operator++(int d);
    Carte operator++();
    friend Carte operator+(Carte,int);

    bool operator>(const Carte& carte_comparata)
    {
        if(this->pret == carte_comparata.pret)
            return true;
        else
            return false;
    }

    operator int()
    {
        return an_publicatie;
    }

    ~Carte()
    {
        if(titlu != NULL)
            delete [] this->titlu;

        if(nume_autor != NULL)
            delete [] this->nume_autor;
    };

} ;

int Carte::nr_pagini = 300;
int Carte::cod_carte = 1110;

Carte Carte::operator++ (int d)
{
    pret += 10;
    return *this;
}

Carte Carte::operator++ ()
{
    pret += 10;
    return *this;
}

Carte operator+ (Carte x, int p)
{
    Carte r;
    r.titlu = new char[strlen(x.titlu) + 1];
    strcpy(r.titlu, x.titlu);
    r.nume_autor = new char[strlen(x.nume_autor) + 1];
    strcpy(r.nume_autor, x.nume_autor);
    r.editura = x.editura;
    r.numar_pagini = x.numar_pagini;
    r.an_publicatie = x.an_publicatie;

    r.pret = x.pret + p;

    return r;
}

class Carte_Romaneasca: public Carte
{
    string gen;
    bool editie_cartonata;
    int nr_copii;

public:

    Carte_Romaneasca(): Carte()
    {
        this->gen = "Gen necunoscut";
        this->editie_cartonata = 0;
        this->nr_copii = 0;
    }

    Carte_Romaneasca(Carte c, string gen, bool editie_cartonata, int nr_copii): Carte(c)
    {
        this->gen = gen;
        this->editie_cartonata = editie_cartonata;
        this->nr_copii = nr_copii;
    }

    Carte_Romaneasca(const Carte_Romaneasca& cr): Carte(cr)
    {
        this->gen = cr.gen;
        this->editie_cartonata = cr.editie_cartonata;
        this->nr_copii = cr.nr_copii;
    }

    Carte_Romaneasca& operator=(const Carte_Romaneasca& cr)
    {
        if(this != &cr)
        {
            Carte::operator=(cr);
            this->gen = cr.gen;
            this->editie_cartonata = cr.editie_cartonata;
            this->nr_copii = cr.nr_copii;
        }

        return *this;
    }

    void Citire_carte()
    {
        Carte::Citire_carte();
        cout<<"\nIntroduceti genul cartii: ";
        getline(cin, gen);
        cout<<"\nIntroduceti 1 daca cartea este cartonata sau 0 daca nu este: ";
        cin>>this->editie_cartonata;
        cout<<"\nIntroduceti numarul de copii: ";
        cin>>this->nr_copii;
    }

    void Afisare_carte()
    {
        Carte::Afisare_carte();
        cout<<"Genul cartii este: "<<this->gen<<". "<<endl;

        if(this->editie_cartonata == 0)
            cout<<"Editia cartii este necartonata."<<endl;
        else
            cout<<"Editia cartii este cartonata. "<<endl;

        cout<<"Numarul de copii ale cartii este: "<<this->nr_copii<<endl;
    }

    ~Carte_Romaneasca()
    {

    };

};

class ListaCarti
{
    list<Carte> lista_carti;
    int nr_carti = 0;

public:

    ListaCarti()
    {
        //Carte c;
        // lista_carti.push_back(c);
        // nr_carti++;
    }

    ListaCarti(Carte& c)
    {
        lista_carti.push_back(c);
        nr_carti++;
    }

    ListaCarti(Carte& c1, Carte & c2)
    {
        lista_carti.push_back(c1);
        nr_carti++;
        lista_carti.push_back(c2);
        nr_carti++;
    }

    ListaCarti(const ListaCarti& lista)
    {
        lista_carti = lista.lista_carti;
        nr_carti = lista.nr_carti;
    }

    void Adaugare_carte(Carte& carte_de_adaugat)
    {
        lista_carti.push_back(carte_de_adaugat);
        nr_carti++;
    }

    void Stergere_carte(Carte& carte_de_sters)
    {
        lista_carti.remove(carte_de_sters);
        nr_carti--;
    }

    void Afisare_lista()
    {
        int j = 1;
        for(auto const& i: lista_carti)
        {
            cout<<"Cartea "<<j<<" este: ";
            i.Getter_Info();
            j++;
            cout<<endl;
        }

        cout<<"Lista contine:"<<lista_carti.size()<<" carti"<<endl;
    }

    bool Verificare_carti(Carte& carte_de_verificat) //verifica daca cartea introdusa exista deja in lista (se verifica doar titlul si autorul)
    {
        for(list<Carte>::iterator i = lista_carti.begin(); i != lista_carti.end(); ++i)
        {
            if(*i == carte_de_verificat)
            {
                return false;
                break;
            }
        }
        return true;
    }

    void Cautare_carti(string titlu_carte)
    {
        bool apare = false;
        for(list<Carte>::iterator i = lista_carti.begin(); i != lista_carti.end(); ++i)
        {
            string titlu = (*i).Get_Titlu();
            if(titlu == titlu_carte)
            {
                cout<<"\nRezultatul cautarii:\n"<<*i;
                cout<<"\nApasati 0 pentru a reveni la meniul principal sau continuati cu o alta comanda."<<endl;
                apare = true;
                break;
            }
        }

        if(!apare)
        {
            cout<<"\n!!! Cartea cautata nu exista in lista !!!"<<endl;
            cout<<"\nApasati 0 pentru a reveni la meniul principal sau continuati cu o alta comanda."<<endl;
        }
    }

    int Marime_lista()
    {
        return lista_carti.size();
    }

    list<Carte> GetLista()
    {
        return lista_carti;
    }

    int Get_nr_carti()
    {
        return nr_carti;
    }

    friend istream& operator>>(istream& in, ListaCarti& lista)
    {
        Carte c;
        c.Citire_carte();
        lista.lista_carti.push_back(c);
        return in;
    }

    friend ostream& operator<<(ostream& out, ListaCarti lis)
    {
        for(list<Carte>:: iterator i  = lis.lista_carti.begin(); i != lis.lista_carti.end(); i++)
        {
            out<<"\n"<<*i;
        }

    }

    ListaCarti operator=(const ListaCarti& lista_veche)
    {
        lista_carti = lista_veche.lista_carti;
        return *this;
    }

    ListaCarti operator [](int indice)
    {
        list<Carte>::iterator i;
        if(indice > lista_carti.size())
            cout<<"\nIndicele depaseste dimeniusea listei"<<endl;
        else
        {
            int j = 0;
            for(i = lista_carti.begin(); i != lista_carti.end(); ++i)
            {
                if(j == indice)
                    return *i;
                j++;
            }
        }
    }

    ListaCarti& operator-(Carte& c)
    {
        lista_carti.remove(c);
        nr_carti--;

        return *this;
    }

    ~ListaCarti()
    {

    };

};


class Autor
{
    char* nume;
    char data_nasterii[10];
    int nr_carti;
    int* ani_publicare_carti;
    float varsta;
    bool contemporan;
    const int cod_autor;
    static int cod;

public:

    Autor():cod_autor(cod++)
    {
        this->nume = new char[strlen("Necunoscut") + 1];
        strcpy(this->nume, "Necunoscut");
        strcpy(this->data_nasterii,"00-00-0000");
        this->nr_carti = 0;
        this->ani_publicare_carti = new int[1];
        ani_publicare_carti[0] = 0;
        this-> varsta = 0;
        this->contemporan = 0;
    }

    void Citire_autor()
    {
        char nume[100];

        cout<<"\nIntroduceti numele autorului:";
        cin.get(nume, 100);
        this->nume = new char [strlen(nume)+1];
        strcpy(this->nume, nume);
        cin.ignore(100, '\n');

        cout<<"\nIntroduceti data de nastere a autorului (in formatul dd-mm-yyyy):";
        cin.get(this->data_nasterii, 10);
        cin.ignore(100, '\n');

        cout<<"\nIntroduceti varsta autorului(puteti introduce varsta si ca un numar rational):";
        cin>>this->varsta;

        cout<<"\nIntroduceti numarul de carti pe care autorul le-a scris:";
        cin>>this->nr_carti;

        this->ani_publicare_carti = new int[this->nr_carti];
        cout<<"\nIntroduceti anii in care autorul a publicat carti:";
        for(int i = 0; i < nr_carti; i++)
        {
            cin>>this->ani_publicare_carti[i];
        }

        cin.ignore(100,'\n');

        /*cout<<"Ani in care a publicat:";  //verificarea vectorului cu ani
        for(int i = 0; i < nr_carti; i++)
            cout<<ani_publicare_carti[i]<<", ";*/

        cout<<"\nIntroduceti 1 daca autorul este contemporan sau 0 daca nu este:";
        cin>>this->contemporan;
        cin.ignore(10,'\n');

        cout<<"\nCodul autorului este:"<<cod;
        cout<<"\n";
    }

    Autor(int cod, char* nume, char data_nasterii[10], float varsta, int nr_carti, int* ani_publicare_carti, bool contemporan):cod_autor(cod) //constructor cu parametrii
    {
        this->nume = new char[strlen(nume) + 1];
        strcpy(this->nume, nume);

        strcpy(this->data_nasterii, data_nasterii);

        this->varsta = varsta;

        this->nr_carti = nr_carti;

        this->ani_publicare_carti = new int[nr_carti];
        for(int i = 0; i < nr_carti; i++)
            this->ani_publicare_carti[i] = ani_publicare_carti[i];

        this->contemporan = contemporan;

    }

    Autor(int cod, char* nume, char data_nasterii[10]):cod_autor(cod)
    {
        this->nume = new char[strlen(nume) + 1];
        strcpy(this->nume, nume);

        strcpy(this->data_nasterii, data_nasterii);


    }

    void Afisare_autor()
    {
        cout<<"Numele autorului este: "<<this->nume<<", iar data sa de nastere este: "<<this->data_nasterii<<" si are "<<this->varsta<<" de ani."<<endl;
        cout<<"A scris "<<this->nr_carti<<" carti, iar acestea au fost publicate in anii: ";

        for(int i = 0; i < nr_carti; i++)
            cout<<this->ani_publicare_carti[i]<<", ";

        cout<<endl;
        if(this->contemporan != 0)
            cout<<"Autorul este unul contemporan."<<endl;
        else
            cout<<"Autorul nu este contemporan."<<endl;

    }

    Autor(const Autor& autor_initial): cod_autor(autor_initial.cod)
    {
        this->nume = new char(strlen(autor_initial.nume)+1);
        strcpy(this->nume, autor_initial.nume);

        strcpy(this->data_nasterii, autor_initial.data_nasterii);

        this->varsta = autor_initial.varsta;

        this->nr_carti = autor_initial.nr_carti;

        this->ani_publicare_carti = new int[autor_initial.nr_carti];
        for(int i = 0; i < nr_carti; i++)
            this->ani_publicare_carti[i] = autor_initial.ani_publicare_carti[i];

        this->contemporan = autor_initial.contemporan;
    }

    Autor& operator=(const Autor& autor_precedent)
    {
        if(this != &autor_precedent) //compara doua adrese
        {
            if(this->nume != NULL)
                delete[] this->nume;

            this->nume = new char[strlen(autor_precedent.nume) + 1];
            strcpy(this->nume, autor_precedent.nume);

            strcpy(this->data_nasterii, autor_precedent.data_nasterii);

            this->varsta = autor_precedent.varsta;

            this->nr_carti = autor_precedent.nr_carti;

            if(ani_publicare_carti != NULL)
                delete[] ani_publicare_carti;

            for(int i = 0; i < autor_precedent.nr_carti; i++)
                this->ani_publicare_carti[i] = autor_precedent.ani_publicare_carti[i];

            this->contemporan = autor_precedent.contemporan;
        }
        return *this;
    }

    bool operator==(const Autor& autor) //supraincarcare == (verificare doar pentru titlu si autor)
    {
        for(int i = 0; i<strlen(this->nume); i++)
        {
            if(this->nume[i] != autor.nume[i])
                return false;
        }
        if(!strcmp(this->data_nasterii, autor.data_nasterii))
            return false;

        return true;
    }

    friend ostream& operator<< (ostream& out, const Autor autor)
    {
        out<<"Numele autorului este: "<<autor.nume<<", iar data sa de nastere este: "<<autor.data_nasterii<<" si are "<<autor.varsta<<" de ani."<<endl;
        out<<"A scris "<<autor.nr_carti<<" carti, iar acestea au fost publicate in anii: ";

        for(int i = 0; i < autor.nr_carti; i++)
            out<<autor.ani_publicare_carti[i]<<", ";

        out<<endl;
        if(autor.contemporan != 0)
            out<<"Autorul este unul contemporan"<<endl;
        else
            out<<"Autorul nu este contemporan"<<endl;

    }

    friend istream& operator>>(istream& in, Autor& autor)
    {
        char nume[100];

        cout<<"\nIntroduceti numele autorului:";
        in.get(nume, 100);
        autor.nume = new char [strlen(nume)+1];
        strcpy(autor.nume, nume);
        in.ignore(100, '\n');

        cout<<"\nIntroduceti data de nastere a autorului (in formatul dd-mm-yyyy):";
        in.get(autor.data_nasterii, 10);
        in.ignore(100, '\n');

        cout<<"\nIntroduceti varsta autorului(puteti introduce varsta si ca un numar rational):";
        in>>autor.varsta;

        cout<<"\nIntroduceti numarul de carti pe care autorul le-a scris:";
        in>>autor.nr_carti;

        autor.ani_publicare_carti = new int[autor.nr_carti];
        cout<<"\nIntroduceti anii in care autorul a publicat carti:";
        for(int i = 0; i < autor.nr_carti; i++)
        {
            in>>autor.ani_publicare_carti[i];
        }

        in.ignore(100,'\n');

        /*cout<<"Ani in care a publicat:";  //verificarea vectorului cu ani
        for(int i = 0; i < nr_carti; i++)
            cout<<ani_publicare_carti[i]<<", ";*/

        cout<<"\nIntroduceti 1 daca autorul este contemporan sau 0 daca nu este:";
        in>>autor.contemporan;
        in.ignore(10,'\n');

        cout<<"\nCodul autorului este:"<<cod;
        cout<<"\n";
    }

    char* Set_nume(char* nume)
    {
        this->nume = nume;
    }

    float Set_varsta(float varsta)
    {
        this->varsta = varsta;
    }

    char Set_data_nasterii(char data_nasterii[10])
    {
        for(int i = 0; i<10; i++)
            this->data_nasterii[i] = data_nasterii[i];
    }

    char* Get_nume()
    {
        return this->nume;
    }

    float Get_varsta()
    {
        return this->varsta;
    }

    void Get_Info() const //il folosesc la afisarea listei de autori
    {
        cout<<"Numele autorului este: "<<this->nume<<", iar data sa de nastere este: "<<this->data_nasterii<<" si are "<<this->varsta<<" de ani."<<endl;
        cout<<"A scris "<<this->nr_carti<<" carti, iar acestea au fost publicate in anii: ";

        for(int i = 0; i < nr_carti; i++)
            cout<<this->ani_publicare_carti[i]<<", ";

        cout<<endl;
        if(this->contemporan != 0)
            cout<<"Autorul este unul contemporan"<<endl;
        else
            cout<<"Autorul nu este contemporan"<<endl;

        cout<<endl;
    }

    Autor operator++(int);
    Autor operator++();
    friend Autor operator+(Autor& a, int v);
    friend Autor operator+(int v, Autor& a);

    bool operator>(const Autor& autor_comparat)
    {
        if(this->varsta == autor_comparat.varsta)
            return true;
        else
            return false;
    }

    operator int() const
    {
        return nr_carti;
    }

    ~Autor()
    {
        if(this->nume != NULL)
            delete[] this->nume;

        if(this->ani_publicare_carti != NULL)
            delete[] this->ani_publicare_carti;
    }

};

int Autor::cod = 1110;

Autor Autor::operator++(int d)
{
    varsta += 1;
    return *this;
}

Autor Autor::operator++()
{
    varsta += 1;
    return *this;
}

class Autor_Celebru: public Autor
{
    int nr_carti_vandute;

public:

    Autor_Celebru(): Autor()
    {
        this->nr_carti_vandute = 0;
    }

    Autor_Celebru(Autor a, int nr_carti_vandute): Autor(a)
    {
        this->nr_carti_vandute = nr_carti_vandute;
    }

    Autor_Celebru(const Autor_Celebru& ac): Autor(ac)
    {
        this->nr_carti_vandute = ac.nr_carti_vandute;
    }

    Autor_Celebru& operator=(const Autor_Celebru& ac)
    {
        if(this != &ac)
        {
            Autor::operator=(ac);
            this->nr_carti_vandute = ac.nr_carti_vandute;
        }
        return *this;
    }

    void Citire_autor()
    {
        Autor::Citire_autor();
        cout<<"\nIntroduceti numarul de carti pe care autorul le-a vandutt:";
        cin>>this->nr_carti_vandute;
        cout<<endl;
    }

    void Afisare_autor()
    {
        Autor::Afisare_autor();
        cout<<"Numarul de cartii vandute de autor este: "<<this->nr_carti_vandute<<endl;
    }

    ~Autor_Celebru()
    {

    };

};

class ListaAutori
{
    list<Autor> lista_autori;
    int nr_autori = 0;

public:

    ListaAutori()
    {
        //Autor a;
        // lista_autori.push_back(a);
        // nr_autori++;
    }

    ListaAutori(Autor& a)
    {
        lista_autori.push_back(a);
        nr_autori++;
    }

    ListaAutori(Autor& a1, Autor& a2)
    {
        lista_autori.push_back(a1);
        nr_autori++;
        lista_autori.push_back(a2);
        nr_autori++;
    }

    ListaAutori(const ListaAutori& lista)
    {
        lista_autori = lista.lista_autori;
        nr_autori - lista.nr_autori;
    }

    void Adaugare_autor(Autor& autor_de_adaugat)
    {
        lista_autori.push_back(autor_de_adaugat);
        nr_autori++;
    }

    void Stergere_autor(Autor& autor_de_sters)
    {
        lista_autori.remove(autor_de_sters);
        nr_autori--;
    }

    void Afisare_autori() //combinatie de Stackoverflow si nimereala (trebuie sa ma mai uit peste ea ca sa inteleg exact ce se intampla)
    {
        int j = 1;
        for(auto const& i: lista_autori)
        {
            cout<<"Autorul "<<j<<" este: \n";
            i.Get_Info();
            j++;
            cout<<endl;
        }

        cout<<"Lista contine:"<<lista_autori.size()<<" autori"<<endl;
    }

    int Marime_lista()
    {
        return lista_autori.size();
    }

    friend istream& operator>>(istream& in, ListaAutori& lista)
    {
        Autor a;
        a.Citire_autor();
        lista.lista_autori.push_back(a);
        return in;
    }

    friend ostream& operator<<(ostream& out, ListaAutori lis)
    {
        for(list<Autor>:: iterator i  = lis.lista_autori.begin(); i != lis.lista_autori.end(); i++)
        {
            out<<"\n"<<*i;
        }

    }

    bool Verificare_autori(Autor& autor_de_verificat) //verifica daca autorul introdus exista deja in lista (se verifica doar numele si data nasterii)
    {
        for(list<Autor>::iterator i = lista_autori.begin(); i != lista_autori.end(); i++)
        {
            if(*i == autor_de_verificat)
            {
                return false;
                break;
            }
        }
        return true;
    }

    ListaAutori operator=(const ListaAutori& lista_veche)
    {
        lista_autori = lista_veche.lista_autori;
        nr_autori = lista_veche.nr_autori;
        return *this;
    }

    list<Autor> GetLista()
    {
        return lista_autori;
    }

    int Get_nr_autori()
    {
        return nr_autori;
    }

    ListaAutori operator [](int indice)
    {
        list<Autor>::iterator i;
        if(indice > lista_autori.size())
            cout<<"\nIndicele depaseste dimeniusea listei"<<endl;
        else
        {
            int j = 0;
            for(i = lista_autori.begin(); i != lista_autori.end(); ++i)
            {
                if(j == indice)
                    return *i;
                j++;
            }
        }
    }

    ListaAutori& operator+(Autor& a)
    {
        lista_autori.push_back(a);
        nr_autori++;

        return *this;
    }

    ListaAutori& operator-(Autor& a)
    {
        lista_autori.remove(a);
        nr_autori--;

        return *this;
    }

    ~ListaAutori()
    {

    };

};

class MeniuAbstract
{

public:
    virtual void Verificare_Comanda()=0;

    virtual void Afisare()
    {
        cout<<"Afisare..."<<endl;
    }
};

class Meniu: public MeniuAbstract //clasa construita ca sa imi fie mai usor cu meniul si ca sa nu umplu main cu prea multe comenzi
{
    int optiune;

public:
    void Afisare()
    {
        //system("Color 2E"); ///schimba culoarea consolei (numarul = background, litera = textul) merge dor in windows
        cout<<"______________________________________________BOOK LOG_____________________________________________"<<endl;
        cout<<" "<<endl;
        cout<<"Puteti accesa urmatoarele comenzi:"<<endl;
        cout<<"0 - Revenire la meniul principal"<<endl;
        cout<<"1 - Adaugare carte in lista personala (optional puteti adauga si detalii legate de autor, pastrate in lista de autori)"<<endl;
        cout<<"2 - Cautare carte"<<endl;
        cout<<"3 - Deschidere lista personala"<<endl;
        cout<<"4 - Deschidere lista de carti romanesti"<<endl;
        cout<<"5 - Deschidere lista de autori"<<endl;
        cout<<"6 - Deschidere lista autori celebrii"<<endl;
        cout<<"7 - Eliminare carte din lista persoanala"<<endl;
        cout<<"8 - Eliminare autor din lista"<<endl;
        cout<<"9 - Oprire program"<<endl;
        cout<<"\n";
    }

    void Verificare_Comanda()
    {
        /*Carte_Romaneasca cr;  ///verificare pentru clasa derivata Autor_Celebru
        cr.Citire_carte();
        cout<<"\n";
        cr.Afisare_carte();*/

        /*Autor_Celebru ac;   ///verificare pentru clasa derivata Carte_Romaneasca
        ac.Citire_autor();
        ac.Afisare_autor();*/

        ListaCarti lista_carti, lista_carti_romanesti;
        ListaAutori lista_autori, lista_autori_celebrii;
        string stergere;

        Carte c(12345, "Hotul de carti", "Markus Zusak", "rao", 300, 2011, 42.99);
        Carte c1(12346, "Toata lumina pe care nu o putem vedea", "Anthony Doerr", "humanitas", 300, 2016, 37.6);
        lista_carti.Adaugare_carte(c);
        lista_carti.Adaugare_carte(c1);

        int ani[] = {1998, 1999, 2000, 2001, 2003, 2007, 2012, 2013, 2018, 2020};
        Autor a(2345, "J. K. Rowling", "31-07-1965", 55, 10, ani, 1);
        lista_autori.Adaugare_autor(a);
        /*cout<<lista_carti[1];
        cout<<lista_autori[0];
        lista_autori=lista_autori + a;
        cout<<lista_carti.Get_nr_carti();
        cout<<lista_autori.Get_nr_autori();*/

        while(optiune != 9)
        {
            cin>>optiune;

            while(cin.fail() || optiune >= 10 || optiune < 0)
            {
                cout<<"Comanda inexistenta!"<<endl;
                cout<<"Introduceti alta comanda:"<<endl;
                cin.clear();
                cin.ignore(1000,'\n');
                cin >> optiune;
            }

            if(optiune == 0)
            {
                Afisare();
            }

            if(optiune == 1)
            {
                string tip;
                cout<<"Introducteti 'da' daca cartea pe care doriti sa o adaugati este romaneasca sau 'nu' altfel."<<endl;
                cin>>tip;
                cout<<"\n";
                if(tip == "nu")
                {
                    cin.ignore(1000,'\n');
                    Carte carte_adaugata;
                    carte_adaugata.Citire_carte();
                    bool verif = carte_adaugata.Verificare_pagini();

                    if(lista_carti.Verificare_carti(carte_adaugata) &&  verif == true)
                    {
                        lista_carti.Adaugare_carte(carte_adaugata);
                        cout<<"\nCartea dumneavoastra a fost adaugata."<<endl;
                        cout<<"\nDaca doriti sa adaugati detalii legate de autor introduceti cuvantul cheie 'autor'"<<endl;
                        cout<<"Daca doriti sa va intoarceti la meniul principal apasati 0."<<endl;
                        string adaugaAutor;
                        cin>>adaugaAutor;
                        cin.ignore(100, '\n');

                        if(adaugaAutor == "autor")
                        {
                            string autor;
                            cout<<"Introduceti 'da' daca autorul este unul celebru sau 'nu' altfel."<<endl;
                            cin>>autor;

                            if(autor == "nu")
                            {
                                cin.ignore(10, '\n');
                                Autor autor_adaugat;
                                autor_adaugat.Citire_autor();
                                if(lista_autori.Verificare_autori(autor_adaugat))
                                {
                                    lista_autori.Adaugare_autor(autor_adaugat);
                                    cout<<"\nDetaliile legate de autor au fost adaugate"<<endl;
                                    cout<<"Apasati 0 pentru a reveni la meniul principal sau continuati cu o alta comanda."<<endl;
                                }
                                else
                                {
                                    cout<<"Autorul introdus exista deja in lista."<<endl;
                                    cout<<"Apasati 0 pentru a reveni la meniul principal sau continuati cu o alta comanda."<<endl;
                                }

                            }
                            else if(autor == "da")
                            {
                                cin.ignore(10, '\n');
                                Autor_Celebru autor_adaugat_c;
                                autor_adaugat_c.Citire_autor();
                                if(lista_autori_celebrii.Verificare_autori(autor_adaugat_c))
                                {
                                    lista_autori_celebrii.Adaugare_autor(autor_adaugat_c);
                                    cout<<"\nDetaliile legate de autor au fost adaugate"<<endl;
                                    cout<<"Apasati 0 pentru a reveni la meniul principal sau continuati cu o alta comanda."<<endl;
                                }
                                else
                                {
                                    cout<<"Autorul introdus exista deja in lista."<<endl;
                                    cout<<"Apasati 0 pentru a reveni la meniul principal sau continuati cu o alta comanda."<<endl;
                                }

                                if(lista_autori.Verificare_autori(autor_adaugat_c))
                                    lista_autori.Adaugare_autor(autor_adaugat_c);

                            }
                            else
                            {
                                cout<<"\nComanda invalida. Introduceti alta comanda."<<endl;
                                Afisare();
                            }
                        }
                        else if(adaugaAutor == "0")
                            Afisare();
                        else
                        {
                            cout<<"\nComanda invalida. Introduceti alta comanda."<<endl;
                            Afisare();
                        }
                    }
                    else if(lista_carti.Verificare_carti(carte_adaugata) == false && verif == true)
                    {
                        cout<<"\nCartea introdusa a fost adaugata deja."<<endl;
                        cout<<"Apasati 0 pentru a reveni la meniul principal sau continuati cu o alta comanda."<<endl;

                    }
                    else if(verif == false)
                    {
                        cout<<"Introducerea cartii a fost anulata."<<endl;
                        Meniu();
                    }
                }
                else if(tip == "da")
                {
                    cin.ignore(100, '\n');
                    Carte_Romaneasca carte_adaugata_r;
                    carte_adaugata_r.Citire_carte();
                    if(lista_carti_romanesti.Verificare_carti(carte_adaugata_r))
                    {
                        lista_carti_romanesti.Adaugare_carte(carte_adaugata_r);
                        cout<<"Cartea dumneavoastra a fost adaugata."<<endl;
                        cout<<"\nDaca doriti sa adaugati detalii legate de autor introduceti cuvantul cheie 'autor'"<<endl;
                        cout<<"Daca doriti sa va intoarceti la meniul principal apasati 0."<<endl;
                        string adaugaAutor;
                        cin>>adaugaAutor;
                        cin.ignore(100, '\n');

                        if(adaugaAutor == "autor")
                        {
                            string autor;
                            cout<<"Introduceti 'da' daca autorul este unul celebru sau 'nu' altfel."<<endl;
                            cin>>autor;

                            if(autor == "nu")
                            {
                                cin.ignore(10, '\n');
                                Autor autor_adaugat;
                                autor_adaugat.Citire_autor();
                                if(lista_autori.Verificare_autori(autor_adaugat))
                                {
                                    lista_autori.Adaugare_autor(autor_adaugat);
                                    cout<<"\nDetaliile legate de autor au fost adaugate"<<endl;
                                    cout<<"Apasati 0 pentru a reveni la meniul principal sau continuati cu o alta comanda."<<endl;
                                }
                                else
                                {
                                    cout<<"Autorul introdus exista deja in lista."<<endl;
                                    cout<<"Apasati 0 pentru a reveni la meniul principal sau continuati cu o alta comanda."<<endl;
                                }

                            }
                            else if(autor == "da")
                            {
                                cin.ignore(10, '\n');
                                Autor_Celebru autor_adaugat_c;
                                autor_adaugat_c.Citire_autor();
                                if(lista_autori_celebrii.Verificare_autori(autor_adaugat_c))
                                {
                                    lista_autori_celebrii.Adaugare_autor(autor_adaugat_c);
                                    cout<<"\nDetaliile legate de autor au fost adaugate"<<endl;
                                    cout<<"Apasati 0 pentru a reveni la meniul principal sau continuati cu o alta comanda."<<endl;
                                }
                                else
                                {
                                    cout<<"Autorul introdus exista deja in lista."<<endl;
                                    cout<<"Apasati 0 pentru a reveni la meniul principal sau continuati cu o alta comanda."<<endl;
                                }

                                if(lista_autori.Verificare_autori(autor_adaugat_c))
                                    lista_autori.Adaugare_autor(autor_adaugat_c);

                            }
                            else
                            {
                                cout<<"\nComanda invalida. Introduceti alta comanda."<<endl;
                                Afisare();
                            }
                        }
                        else if(adaugaAutor == "0")
                            Afisare();
                        else
                        {
                            cout<<"\nComanda invalida. Introduceti alta comanda."<<endl;
                            Afisare();
                        }
                    }

                    else
                    {
                        cout<<"\nCartea introdusa a fost adaugata deja."<<endl;
                        cout<<"Apasati 0 pentru a reveni la meniul principal sau continuati cu o alta comanda."<<endl;
                    }

                    if(lista_carti.Verificare_carti(carte_adaugata_r))
                        lista_carti.Adaugare_carte(carte_adaugata_r);
                }
            }

            if(optiune == 2)
            {
                cin.ignore(100, '\n');
                cout<<"Introduceti titlul cartii cautate: "<<endl;
                string titlu;
                getline(cin, titlu);
                lista_carti.Cautare_carti(titlu);
            }

            if(optiune == 3)
            {
                if(lista_carti.Marime_lista() > 0)
                {
                    cout<<"Lista de carti personala este:\n"<<endl;
                    lista_carti.Afisare_lista();
                }
                else
                    cout<<"\nLista de carti personala este goala."<<endl;

                cout<<"\nApasati 0 pentru a reveni la meniul principal sau continuati cu o alta comanda."<<endl;
            }

            if(optiune == 4)
            {
                if(lista_carti_romanesti.Marime_lista() > 0)
                {
                    cout<<"Lista de carti romanesti este: \n"<<endl;
                    lista_carti_romanesti.Afisare_lista();
                }
                else
                    cout<<"\nLista de carti romanesti este goala."<<endl;

                cout<<"\nApasati 0 pentru a reveni la meniul principal sau continuati cu o alta comanda."<<endl;
            }

            if(optiune == 5)
            {
                if(lista_autori.Marime_lista() > 0)
                {
                    cout<<"\nLista de autori:\n"<<endl;
                    lista_autori.Afisare_autori();
                }
                else
                    cout<<"\nLista de autori este goala."<<endl;

                cout<<"\nApasati 0 pentru a reveni la meniul principal sau continuati cu o alta comanda."<<endl;
            }

            if(optiune == 6)
            {
                if(lista_autori_celebrii.Marime_lista() > 0)
                {
                    cout<<"\nLista de autori:\n"<<endl;
                    lista_autori_celebrii.Afisare_autori();
                }
                 else
                    cout<<"\nLista de autori celebrii este goala."<<endl;

                cout<<"\nApasati 0 pentru a reveni la meniul principal sau continuati cu o alta comanda."<<endl;
            }

            if(optiune == 7)
            {
                if(lista_carti.Marime_lista() == 0)
                    cout<<"Lista dumneavoastra este goala"<<endl;
                else
                {
                    cout<<"\nPentru a elimina carti din lista introduceti cuvantul cheie 'sterge'."<<endl;
                    cin>>stergere;
                    cin.ignore(100, '\n');

                    if(stergere == "sterge")
                    {
                        Carte carte_sters;
                        carte_sters.Citire_carte();

                        if(lista_carti.Verificare_carti(carte_sters) == true)
                        {
                            cout<<"\nCartea introdusa nu exista in lista."<<endl;
                            cout<<"Apasati 0 pentru a reveni la meniul principal sau continuati cu o alta comanda."<<endl;
                        }
                        else
                        {
                            lista_carti.Stergere_carte(carte_sters);

                            cout<<"\nCartea a fost eliminata din lista."<<endl;
                            cout<<"Apasati 0 pentru a reveni la meniul principal sau continuati cu o alta comanda."<<endl;
                        }
                    }
                    else
                    {
                        cout<<"\nComanada introdusa este invalida. Introduceti o alta comanda.\n"<<endl;
                        Afisare();
                    }
                }
            }

            if(optiune == 8)
            {
                {
                    if(lista_autori.Marime_lista() == 0)
                        cout<<"Lista de autori este goala"<<endl;
                    else
                    {
                        cout<<"\nPentru a elimina autori din lista introduceti cuvantul cheie 'sterge'."<<endl;
                        cin>>stergere;
                        cin.ignore(100, '\n');

                        if(stergere == "sterge")
                        {
                            Autor autor_sters;
                            autor_sters.Citire_autor();

                            if(lista_autori.Verificare_autori(autor_sters) == true)
                            {
                                cout<<"\nAutorul introdusa nu exista in lista."<<endl;
                                cout<<"Apasati 0 pentru a reveni la meniul principal sau continuati cu o alta comanda."<<endl;
                            }
                            else
                            {
                                lista_autori.Stergere_autor(autor_sters);
                                cout<<"\nAutorul a fost eliminata din lista."<<endl;
                                cout<<"Apasati 0 pentru a reveni la meniul principal sau continuati cu o alta comanda."<<endl;
                            }
                        }
                        else
                        {
                            cout<<"\nComanada introdusa este invalida. Introduceti o alta comanda.\n"<<endl;
                            Afisare();
                        }
                    }
                }
            }
        }
    }
};


int main()
{

    /*int ani[] = {1998, 1999, 2000, 2001, 2003, 2007, 2012, 2013, 2018, 2020};      ///verificare pentru functiile din clasa autor
    Autor a(1321, "J. K. Rowling", "31-07-1965", 55, 10, ani, 1);
    a.Afisare_autor();
    Autor a1(a);
    cout<<a1<<"\n";
    Autor a2;
    cout<<a2<<"\n";
    Autor a3;
    a++;
    cout<<a<<"\n";
    //cin>>a3;
    int ani1[] = {1998, 1999, 2000, 2001, 2003, 2007, 2012, 2013, 2018, 2020};
    Autor a4(1321, "J. K. Rowling", "31-07-1965", 55, 10, ani1, 1);
    cout<<int(a4)<<"\n";*/

    /*Carte c(12345, "Hotul de carti", "Markus Zusak", "rao", 300, 2011, 42.99);      ///verificare pentru functiile din clasa carte
    Carte c1(c);
    Carte c2;
    cout<<c2<<"\n";
    c1.Afisare_carte();
    cout<<c1<<"\n";
    Carte c3;
    //cin>>c3;
    c++;
    cout<<c<<"\n";
    Carte c4;
    c4 = c+100;
    cout<<c4<<"\n";
    Carte c5(12345, "Hotul de carti", "Markus Zusak", "rao", 300, 2011, 42.99);
    ++c5;
    cout<<c5;*/

    MeniuAbstract *meniu = new Meniu;
    (*meniu).Afisare();
    (*meniu).Verificare_Comanda();

    return 0;
}

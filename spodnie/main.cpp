#include <iostream>

using namespace std;

class CSpodnie {
    private:
        bool Zapiete;
        bool Zalozone;


    public:
        bool getZapiete() {
            return Zapiete;
        }

        virtual void setZapiete(bool aZapiete) {
            Zapiete = aZapiete;
        }

        bool getZalozone() {
            return Zalozone;
        }

        void Zaloz() {
            if(Zapiete == false){
                Zalozone == true;
            } else {
                cout<<"Spodnie zapiete, nie da siê ich zalozyc"<<endl;
            }
        }

        void Zdejmij()
        {
            if(Zapiete == false) {
                   Zalozone == false;
            } else {
                cout<<"Spodnie zapiete,nie da sie ich zdjac"<<endl;
            }
        }


        CSpodnie() {
            Zalozone = false;
            Zapiete = false;
        }

};

class CPasek {
    public:
        bool Zapiety;

    public:

    bool getZapiety() {
        return Zapiety;
    }

    void setZapiety(bool aZapiety) {
        Zapiety = aZapiety;
    }


    CPasek() {
        Zapiety = false;
    }

};


class CSpodniezPaskiem: public CSpodnie {
    public:
        CPasek* pasek;

    void Zaloz() {
        if(pasek->getZapiety() == false)
            CSpodnie::Zaloz();
        else
            cout<<"Pasek zapiety, nie mozna zalozyc spodni"<<endl;
    }

    void Zdejmij() {
        if(pasek->getZapiety() == false)
            CSpodnie::Zdejmij();
        else
            cout<<"Pasek zapiety, nie mozna zdjac spodni"<<endl;
    }

    void setZapiete(bool aZapiete) {
        if(pasek->getZapiety() == false)
            CSpodnie::setZapiete(aZapiete);
    }

    void ZmienPasek(CPasek &nowyPasek) {
        pasek = &nowyPasek;
    }

    CSpodniezPaskiem(CPasek* aPasek) {
        pasek = aPasek;
    }
};

int main() {
    CSpodnie mojeSpodnie;
    CPasek mojPasek;
    CPasek* mojPasekt = &mojPasek;
    CSpodniezPaskiem passpodnie(mojPasekt);

    mojeSpodnie.getZapiete();
    mojeSpodnie.Zaloz();

    passpodnie.Zdejmij();

    return 0;
}

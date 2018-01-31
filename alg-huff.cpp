#include <iostream>
#include <fstream>
#include <map>

using namespace std;

class huff
{
    public:
        string kompresujHuff(ifstream &plik);
        ~huff();

    private:
        struct lisc
        {
            char znak;
            int wystapien;
            lisc *lewy, *prawy;
            lisc(const char znak, const int wystapien): znak(znak), wystapien(wystapien)
            {
                lewy = NULL;
                prawy = NULL;
            }
        };
        map<char,string> tab_kodow;
        multimap<int,lisc*> drzewo;
        void dajWystapienia(ifstream &plik);
        void dajDrzewo();
        void dajKody(auto &drzewo,string kod);
        void dajTabliceKodow();
        void usunDrzewo(auto &drzewo);
};

string huff::kompresujHuff(ifstream &plik)
{
    cout << "------------------------------" << endl;
    cout << "Rozpoczynam kompresję pliku..." << endl << endl;
    dajWystapienia(plik);
    dajDrzewo();

    cout << "Tablica kodów: ";
    dajKody(drzewo.begin()->second,"");
    dajTabliceKodow();

    cout << endl << "Skompresowane dane:" << endl;
    plik.clear();
    plik.seekg(0, ios::beg);
    char znak;
    string kompresja;
    while(plik.get(znak))
    {
        kompresja += tab_kodow[znak];
    }
    return kompresja;
}

void huff::dajWystapienia(ifstream &plik)
{
    cout << "Liczba wystąpień znaków: ";
    plik.clear();
    plik.seekg(0, ios::beg);
    map<char,int> zliczony;
    char znak;
    while(plik.get(znak))
    {
        if(zliczony[znak])
        {
            zliczony[znak] = zliczony[znak]+1;
        }
        else
        {
            zliczony[znak] = 1;
        }
    }
    for(map<char,int>::iterator i = zliczony.begin();i != zliczony.end();i++)
    {
        cout << (*i).first << " : " << (*i).second << endl;
        drzewo.insert(pair<int,lisc*>((*i).second,new lisc((*i).first,(*i).second)));
    }
    cout << endl;
}

void huff::dajDrzewo()
{
    lisc *lewy, *prawy, *glowa;
    while(drzewo.size()>1)
    {
        lewy = drzewo.begin()->second;
        drzewo.erase(drzewo.begin());

        prawy = drzewo.begin()->second;
        drzewo.erase(drzewo.begin());

        glowa = new lisc('|',lewy->wystapien+prawy->wystapien);
        glowa->lewy = lewy;
        glowa->prawy = prawy;
        drzewo.insert(pair<int,lisc*>(lewy->wystapien+prawy->wystapien,glowa));
    }
}

void huff::dajKody(auto &drzewo,string kod)
{
    if(drzewo->znak != '|')
    {
        tab_kodow[drzewo->znak] = kod;
    }
    if(drzewo->lewy != NULL) dajKody(drzewo->lewy,kod+"0");
    if(drzewo->prawy != NULL) dajKody(drzewo->prawy,kod+"1");
}

void huff::dajTabliceKodow()
{
    for(map<char,string>::iterator i = tab_kodow.begin();i != tab_kodow.end();i++)
    {
        cout << (*i).first << " : " << (*i).second << endl;
    }
}

void huff::usunDrzewo(auto &drzewo)
{
    if(drzewo->lewy != NULL)
    {
        usunDrzewo(drzewo->lewy);
        drzewo->lewy = NULL;
    }
    if(drzewo->prawy != NULL)
    {
        usunDrzewo(drzewo->prawy);
        drzewo->prawy = NULL;
    }
    if(drzewo->lewy == NULL && drzewo->prawy == NULL)
    {
        delete drzewo;
    }
}

huff::~huff()
{
    usunDrzewo(drzewo.begin()->second);
}

int main(int argc,char **argv)
{
    ifstream plik(argv[1]);

    if(!plik.is_open())
    {
        cout << "Brak dostępu do wskazanego pliku!" << endl;
        return 1;
    }
    huff h;
    cout << h.kompresujHuff(plik) << endl << endl;
 
    plik.close();

    return 0;
}
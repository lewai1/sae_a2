
#include <iostream>
#include <cstring>
using namespace std;




class sommet
{

protected:

    char* nom;

public:

    // constructeur vide
    sommet()

    {
        nom = NULL;
    }

    //constructeur avec nom prédéfini
    sommet(string chaine)

    {

        int i;
        int nbchar = chaine.length();

        nom = new char[nbchar+1];

        for (int i = 0; i < nbchar; i++)
        {
            nom[i] = chaine[i];
        }

        nom[nbchar] = '\0';


    }

    ~sommet()

    {
        delete nom;

    }

    sommet(const sommet& s)

    {

        int nbchar = strlen(s.nom);

        nom = new char[nbchar+1];

        for (int i = 0; i < nbchar; i++)
        {
            nom[i] = s.nom[i];
        }

        nom[nbchar] = '\0';

    }


    sommet& operator=(const sommet& s)

    {
        if (this != &s)

        {

            delete nom;

            int nbchar = strlen(s.nom);

            nom = new char[nbchar+1];


            for (int i = 0; i < nbchar; i++)

            {
                nom[i] = s.nom[i];
            }

            nom[nbchar] = '\0';

        }

        return *this;

    }

    void affiche()

    {

        cout << nom;

    }


};


class arc
{

protected:

    sommet somdepart;
    sommet somarriv;
    int poids;

public:

    arc()

    {
        poids = 0;

    }

    arc(sommet s1, sommet s2, int k)

    {

        somdepart = s1;
        somarriv = s2;
        poids = k;

    }


    ~arc()
    {

    }


    arc(const arc& a)

    {
        somdepart = a.somdepart;
        somarriv = a.somarriv;
        poids = a.poids;

    }


    arc& operator= (const arc& a)

    {

        if (this != &a)

        {

            somdepart = a.somdepart;
            somarriv = a.somarriv;
            poids = a.poids;


        }

        return *this;

    }

    void affiche()

    {

        cout << "L'arc relie ";
        somdepart.affiche();
        cout << " a ";
        somarriv.affiche();
        cout << endl;
        cout << "Distance entre les deux sommets : " << poids << endl;

    }



};

class graphe

{
protected:

    sommet* So;
    arc* Ar;
    int nbsommets;
    int nbarcs;

public:

    graphe()

    {

        So = NULL;
        Ar = NULL;
        nbsommets = 0;
        nbarcs = 0;

    }

    ~graphe()

    {


    }

    //constructeur de recopie 

    graphe(const graphe& g)
    {



        So = new sommet[g.nbsommets];
        Ar = new arc[g.nbarcs];

        for (int i = 0; i < nbsommets; i++)

        {
            So[i] = g.So[i];
        }

        for (int i = 0; i < nbarcs; i++)

        {
            Ar[i] = g.Ar[i];
        }

        nbsommets = g.nbsommets;
        nbarcs = g.nbarcs;

    }

    //surcharge de l'égalité

    graphe& operator= (const graphe& g)
    {

        if (this != &g)

        {
            delete[] So;
            delete[] Ar;

            So = new sommet[g.nbsommets];
            Ar = new arc[g.nbarcs];

            for (int i = 0; i < nbsommets; i++)

            {
                So[i] = g.So[i];
            }

            for (int i = 0; i < nbarcs; i++)

            {
                Ar[i] = g.Ar[i];
            }

            nbsommets = g.nbsommets;
            nbarcs = g.nbarcs;


        }

        return *this;

    }






    // Manipulation des sommets

    void ajoutsommet(sommet s)

    {

        sommet* temp;

        temp = new sommet[nbsommets];

        for (int i = 0; i < nbsommets; i++)

        {
            temp[i] = So[i];

        }

        delete[] So;

        So = new sommet[nbsommets + 1];

        for (int i = 0; i < nbsommets; i++)

        {
            So[i] = temp[i];

        }

        So[nbsommets] = s;

        nbsommets++;

    }

    void affichesommet()

    {

        cout << "Ce graphe possede " << nbsommets << " sommet(s)." << endl;

        if (nbsommets > 0)

        {

            for (int i = 0; i < nbsommets; i++)

            {

                cout << "Sommet numero" << i + 1 << " : ";
                So[i].affiche();
                cout << endl;

            }

        }

    }

    void affichesommet(int k)
    {

        if (nbsommets > 0)
        {

            cout << "Sommet numero" << k << " : ";
            So[k = 1].affiche();
            cout << endl;

        }
        else
        {
            cout << "Ce graphe n'a aucun sommet" << endl;
        }

    }

    //manipulation des arcs

    void ajoutarc(arc a)
    {
        arc* temp;

        temp = new arc[nbarcs];

        for (int i = 0; i < nbarcs; i++)

        {
            temp[i] = Ar[i];

        }

        delete[] Ar;

        Ar = new arc[nbarcs + 1];

        for (int i = 0; i < nbarcs; i++)

        {
            Ar[i] = temp[i];

        }

        Ar[nbarcs] = a;

        nbarcs++;

    }


    void affichearc()
    {

        cout << "Ce graphe possede " << nbarcs << " arc(s)." << endl;

        if (nbarcs > 0)

        {

            for (int i = 0; i < nbarcs; i++)

            {

                cout << "Arc numero" << i + 1 << " : ";
                Ar[i].affiche();
                cout << endl;

            }

        }

    }

    void affichearc(int k)
    {

        if (nbarcs > 0)

        {

            cout << "Arc numero" << k << " : ";
            Ar[k - 1].affiche();
            cout << endl;

        }

        else

        {
            cout << "Ce graphe n'a aucun arc" << endl;
        }

    }


};


int main()
{


    sommet s1("Gare de l'Ouest");

    sommet s3("Beekant");


    arc a1(s1, s3, 2);
    a1.affiche();


    graphe G;

    G.ajoutsommet(s3);
    G.ajoutsommet(s1);

    G.affichesommet();

    G.affichesommet(2);

    G.ajoutarc(a1);

    G.affichearc();

    graphe G2;

    G2.affichesommet();
    G2.affichearc();

    sommet s4("Osseghem");

    sommet s5("Simonis Leopold II");

    G.ajoutsommet(s4);
    G.ajoutsommet(s5);

    arc a2(s3, s4, 1);
    arc a3(s4, s5, 2);

    G.ajoutarc(a2);
    G.ajoutarc(a3);

    G.affichesommet();
    G.affichearc();

    return 0;
}

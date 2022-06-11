
#include <iostream>
#include <cstring>
using namespace std;


class trajet

{

protected:

    char* stationdepart;
    char* stationarrivee;
    int distance;

public:

    trajet(string depart, string arrivee)
    {
        int nbchar_dep = depart.length();
        int nbchar_arr = arrivee.length();

        stationdepart = new char[nbchar_dep + 1];

        for (int i = 0; i < nbchar_dep; i++)
        {
            stationdepart[i] = depart[i];
        }

        stationdepart[nbchar_dep] = '\0';

        stationarrivee = new char[nbchar_arr + 1];

        for (int i = 0; i < nbchar_arr; i++)
        {
            stationarrivee[i] = arrivee[i];
        }

        stationarrivee[nbchar_arr] = '\0';

        distance = 0;

    }

    trajet(const trajet& t)
    {
        stationdepart = t.stationdepart;
        stationarrivee = t.stationarrivee;
        distance = t.distance;

    }

    trajet& operator= (const trajet& t)
    {
        if (this != &t)
        {
            if (stationdepart != NULL)
            {
                stationdepart = t.stationdepart;
            }
            else
            {
                stationdepart = NULL;
            }

            if (stationarrivee != NULL)
            {
                stationarrivee = t.stationarrivee;
            }
            else
            {
                stationarrivee = NULL;
            }

            distance = t.distance;


        }

        return *this;



    }

    void affiche()

    {
        cout << "Le trajet selectionne est le suivant : " << endl;
        cout << "Depart : " << stationdepart << endl;
        cout << "Arrivee : " << stationarrivee << endl;

    }

    string depart_recup()
    {
        return stationdepart;
    }

    string arrivee_recup()
    {
        return stationarrivee;
    }


};

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

        if (s.nom != NULL)
        {

            int nbchar = strlen(s.nom);

            nom = new char[nbchar + 1];

            for (int i = 0; i < nbchar; i++)
            {
                nom[i] = s.nom[i];
            }

            nom[nbchar] = '\0';
        }
        else
        {
            nom = NULL;
        }

    }


    sommet& operator=(const sommet& s)

    {
        if (this != &s)

        {

            int nbchar;
            delete nom;

            if (s.nom != NULL) 
            {

                nbchar = strlen(s.nom);
                nom = new char[nbchar + 1];


                for (int i = 0; i < nbchar; i++)

                {
                    nom[i] = s.nom[i];
                }

                nom[nbchar] = '\0';


            }
            else
            {
                nbchar = 0;
                nom = NULL;
            }

        }

        return *this;

    }

    const bool& operator== (const sommet &s)
    {
        if ((string)this->nom == (string)s.nom)
        {
            return true;
        }
        else
        {
            return false;
        }
    
    }

    const bool& operator!= (const sommet& s)
    {
        if ((string)this->nom != (string)s.nom)
        {
            return true;
        }
        else
        {
            return false;
        }

    }


    void affiche()

    {

        if (nom != NULL)
        {

            cout << nom;

        }
        else
        {

            cout << "NULL";
        }

    }

    char* collectnom()

    {
        return nom;

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

    string recup_sommetnom(string type) 
    
    {
        string nomsommet;

        if (type=="depart")
        {
            nomsommet = somdepart.collectnom();
        }

        if (type == "arrivee")
        {
            nomsommet = somarriv.collectnom();
        }

        return nomsommet;

    }

    sommet recup_sommetobj(const char* nomsommet)

    {

        sommet somrecup;
        char* res_som_d = somdepart.collectnom();
        char* res_som_a = somarriv.collectnom();
        bool depart_egal = true;
        bool arrivee_egal = true;
        int i;

        i = 0;

        while (res_som_d[i] != '\0' && nomsommet[i] != '\0')

        {
            if (res_som_d[i] != nomsommet[i])
            {
                depart_egal = false;
            }

            i++;
        }

        i = 0;

        while (res_som_a[i] != '\0' && nomsommet[i] != '\0')

        {
            if (res_som_a[i] != nomsommet[i])
            {
                arrivee_egal = false;
            }

            i++;
        }

        if (depart_egal)
        {
            somrecup = somdepart;
        }

        if (arrivee_egal)
        {
            somrecup = somarriv;
        }

        return somrecup;

    }

    sommet recup_inversesommetobj(const char* nomsommet)

    {

        sommet somrecup;
        char* res_som_d = somdepart.collectnom();
        char* res_som_a = somarriv.collectnom();
        bool depart_egal = true;
        bool arrivee_egal = true;
        int i;

        i = 0;

        while (res_som_d[i] != '\0' && nomsommet[i] != '\0') 
        
        {
            if (res_som_d[i] != nomsommet[i]) 
            {
                depart_egal = false;
            }

            i++;
        }

        i = 0;

        while (res_som_a[i] != '\0' && nomsommet[i] != '\0')

        {
            if (res_som_a[i] != nomsommet[i])
            {
                arrivee_egal = false;
            }

            i++;
        }

        if (depart_egal)
        {
            somrecup = somarriv;
        }

        if (arrivee_egal)
        {
            somrecup = somdepart;
        }

        return somrecup;

    }

    sommet recup_sommetencommun(arc bis)
    {
        sommet final;
        sommet recup_d = bis.recup_sommetobj(somdepart.collectnom());
        sommet recup_a = bis.recup_sommetobj(somarriv.collectnom());

        //regarde si bis contient somdepart

        if (recup_d.collectnom() != NULL) 
        {
            final = recup_d;
        }

        //regarde si bis contient somarriv

        if (recup_a.collectnom() != NULL)
        {
            final = recup_a;;
        }

        return final;
    }
    

    int recup_poids()

    {
        return poids;
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
        delete[] So;
        delete[] Ar;

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

    // Extraction des valeurs de base

    int extraction_nbsommets()
    {
        return nbsommets;
    }

    int extraction_nbarcs()
    {
        return nbarcs;
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
        bool sommetpresent_dep = false;
        bool sommetpresent_arr = false;
        
        for (int i = 0; i < nbsommets; i++) 
        {

            if (a.recup_sommetnom("depart") == So[i].collectnom())

            {
                sommetpresent_dep = true;

            }

            if (a.recup_sommetnom("arrivee") == So[i].collectnom())

            {
                sommetpresent_arr = true;

            }

        }

        if (sommetpresent_dep && sommetpresent_arr)

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

        else

        {

            cout << "L'arc ne peut pas etre ajoute au graphe" << endl;
            cout << "Verifiez que les deux sommets soient tous les deux dans le graphe..." << endl;

        }
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

    //manipulation des sommets

    void listepoints_affiche()
    {
        for (int i = 0; i < nbsommets; i++) 
        {
            So[i].affiche();
            cout << endl;
        }
    }

    //manipulation des connexions

    void listeconnexions_affiche(const string pointdepart)
    {

        for (int i = 0; i < nbarcs; i++)
        {
            if (Ar[i].recup_sommetnom("depart") == pointdepart)

            {
                Ar[i].affiche();

            }

            if (Ar[i].recup_sommetnom("arrivee") == pointdepart)

            {
                Ar[i].affiche();

            }


        }
        
    }

    void listeconnexions_affiche(sommet pointdepart)
    {

        for (int i = 0; i < nbarcs; i++)
        {

            if (Ar[i].recup_sommetnom("depart") == pointdepart.collectnom())

            {
                Ar[i].affiche();

            }

            if (Ar[i].recup_sommetnom("arrivee") == pointdepart.collectnom())

            {
                Ar[i].affiche();

            }


        }

    }

    int listeconnexions_copie(string pointdepart, arc liste[])
    
    {
 
        int nombreactuel_arcs = 0;

        for (int i = 0; i < nbarcs; i++) {

                if (Ar[i].recup_sommetnom("depart") == pointdepart)

                {
                    arc temp(Ar[i]);

                    liste[nombreactuel_arcs] = temp;
                    nombreactuel_arcs++;

                }

                if (Ar[i].recup_sommetnom("arrivee") == pointdepart)

                {

                    arc temp(Ar[i]);

                    liste[nombreactuel_arcs] = temp;
                    nombreactuel_arcs++;

                }

        }

        return nombreactuel_arcs;

    }

    int listeconnexions_copie(sommet pointdepart, arc liste[])

    {

        int nombreactuel_arcs = 0;

        for (int i = 0; i < nbarcs; i++) {

            if (Ar[i].recup_sommetnom("depart") == pointdepart.collectnom())

            {
                arc temp(Ar[i]);

                liste[nombreactuel_arcs] = temp;
                nombreactuel_arcs++;

            }

            if (Ar[i].recup_sommetnom("arrivee") == pointdepart.collectnom())

            {

                arc temp(Ar[i]);

                liste[nombreactuel_arcs] = temp;
                nombreactuel_arcs++;

            }

        }

        return nombreactuel_arcs;

    }

    // faudrait-il créer une méthode qui crée et renvoie une matrice d'adjacence du graphe?

 

    // Algorithme INCOMPLET de Dijkstra

    void dijkstra(trajet T)
    {

        //initialisation

        int i;
        int dist = 0;
        int nbconnexions;
        arc connexions_nbarcs[256];

        int* ecart = new int[nbsommets];
        sommet* precedent = new sommet[nbsommets];

        sommet* deja_visite = new sommet[nbsommets];
        sommet* a_visiter = new sommet[nbsommets];

        for (int m = 0; m < nbsommets; m++)
        {
            a_visiter[m] = So[m];
            
        }


        for (i = 1; i < nbsommets; i++)
        {
            ecart[i] = 9999999;
        }

        ecart[0] = 0;

        int cptecart = 1;

        /* On récupère T.stationdebut : ça permettra ainsi de débuter l'algorithme */

        sommet u(T.depart_recup());

        while (u.collectnom() != T.arrivee_recup())
        {
 

                nbconnexions = listeconnexions_copie(u, connexions_nbarcs);

                for (i = 0; i < nbconnexions; i++)
                {

                
                    
                         
                    int distance_alternative;

                    /*if (cptecart>1 && connexions_nbarcs[i].recup_sommetobj(u.collectnom()) == deja_visite[cptecart])
                    {
                        i++;
                    }
                    else
                    {*/

                        connexions_nbarcs[i].affiche();
                        cout << "_" << endl;

                        distance_alternative = ecart[cptecart-1] + connexions_nbarcs[i].recup_poids(); //addition ecart actuel et poids supplementaire de la liste

                        if (distance_alternative < ecart[cptecart])

                        {
                            ecart[cptecart] = distance_alternative;
                            precedent[cptecart] = u;

                        }
                    //}
                }

                cptecart++;

                deja_visite[cptecart-1] = u;

                cout << "boucle faite" << endl;

                //récupérer le u de distance la plus petite

                u = connexions_nbarcs[i - 1].recup_inversesommetobj(u.collectnom());

            
        }

         for (int j = 0; j < cptecart; j++)
         {

                 precedent[j].affiche();
                 cout << endl;
 
         }

    }
    



 };



int main()
{


    sommet s1("Gare de l'Ouest");

    sommet s3("Beekant");


    arc a1(s1, s3, 3);


    graphe G;

    G.ajoutsommet(s3);
    G.ajoutsommet(s1);

    G.ajoutarc(a1);

    sommet s4("Osseghem");

    sommet s5("Simonis Leopold II");

    sommet s6("Etangs Noirs");

    sommet s7("Jacques Brel");

    sommet s8("Delacroix");

    G.ajoutsommet(s4);
    G.ajoutsommet(s5);
    G.ajoutsommet(s6);
    G.ajoutsommet(s7);
    G.ajoutsommet(s8);

    arc a2(s3, s4, 1);
    arc a3(s4, s5, 2);
    arc a4(s3, s6, 2);
    arc a5(s1, s7, 1);
    arc a6(s8, s1, 2);


    G.ajoutarc(a2);
    G.ajoutarc(a3);
    G.ajoutarc(a4);
    G.ajoutarc(a5);
    G.ajoutarc(a6);

    G.affichesommet();
    G.affichearc();

    cout << "Recuperation a1" << endl;
    sommet s32 = a1.recup_sommetobj("Gare de l'Ouest");
    s32.affiche();
    cout << endl;

    trajet T("Delacroix", "Jacques Brel");
    T.affiche();

    G.dijkstra(T);

    /*arc listedesarcs[255];
    

    cout << "Affichage arcs" << endl;

    int nbdesarcs = G.listeconnexions_copie(s3, listedesarcs);

    for (int i = 0; i < nbdesarcs; i++)
    {
        listedesarcs[i].affiche();

    }

    G.listepoints_affiche();

    cout<<"test sommet en commun"<<endl;

    sommet s9 = a5.recup_sommetencommun(a6);

    s9.affiche();
    cout << endl;
    cout << endl;

    sommet s10 = a4.recup_sommetobj("Etangs Noirs");

    s10.affiche();
    cout << endl;


    trajet t("Gare de l'Ouest", "Osseghem");

    t.affiche();

    sommet s12("Prout");
    sommet s11("Prout");

    if (s12 == s11) 
    
    {
        cout << "Les sommets sont les memes" << endl;

    }

    else
    {

        cout << "Les sommets sont differents" << endl;
    }
    

    sommet s13 = a1.recup_inversesommetobj("Gare de l'Ouest");

    s13.affiche();

    sommet s14("Machin");


    arc a16(s1, s14, 42);

    a16.affiche();

    G.ajoutarc(a16);

    */
    
    return 0;
}

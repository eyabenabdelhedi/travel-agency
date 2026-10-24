#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define max 1000


// Déclaration des variables globales
int voyage_id[max] = {1, 2, 3, 4, 5, 6, 7};
char date_depart[max][11] = {"01/01/2025", "10/01/2025", "09/02/2025", "03/03/2025", "25/04/2025", "12/05/2025", "10/06/2025"};
char date_arrive[max][11] = {"08/01/2025", "17/01/2025", "17/02/2025", "10/03/2025", "02/05/2025", "20/05/2025", "25/06/2025"};
char pays_destination[max][50] = {"Italie", "Turquie", "France", "Canada", "Russie", "Allemagne", "Emirats"};
char ville_destination[max][50] = {"Como", "Adana", "Nice", "Montreal", "Moscow", "Kassel", "Dubai"};
char nature[max][50] = {"individuel", "groupe", "individuel", "groupe", "individuel", "groupe", "groupe"};
int nb_places[max] = {22, 10, 15, 13, 50, 8, 10};
float prix[max] = {710.5, 950, 565.5, 2500, 1800, 825.5, 1500};
char num_passport[max][20] = {"AB12DC3", "OUI12345", "NON67890", "CD45678E", "FG90123H", "IJ45678K", "LM90123N"}; // Tableaux de passeports

char prenom[max][50]= {"sara","karim","nadia","omar","lina","yassine","salma"};
char nom[max][50]={"ben salah","trabelsi","gharbi","mansour","jebali","hammami","khelifi"};
char date_naissance[max][11] = {"06/02/2004", "17/03/2000", "12/03/2001", "10/03/1991", "02/06/1999"};
int num_reservation[max];     // Numéros des réservations
int voyage_reservation[max];  // IDs des voyages réservés
char passport_reservation[max][20];  // Passeports associés aux réservations
int num_passeport_reservation[max] = {1, 2, 1, 3, 2};  // Exemples de réservations (numéros de passeport)
int nb_voyages = 7, nb_clients = 5, nb_reservations = 6;  // Initialisation des nombres
// vérivication de validité des dates
int date_verif(char date[11]) {
char jour[3],mois[3],annee[5];
int i,jj=0,mm=0,aa=0,valide=1 ;
//validite
for (i=0 ;i<2 ;i++) ;
{jour[i]=date[i] ;}
jour[2]="\0" ;
for(i=3 ;i<5 ;i++) ;
{mois[i-3]=date[i] ;}
mois[2]="\0" ;
for(i=6 ;i<10 ;i++) ;
{annee[i-6]=date[i] ;}
annee[4]="\0" ;

//conversion
jj=atoi(jour) ;
mm=atoi(mois) ;
aa=atoi(annee) ;

//validite du mois
if(mm<1||mm>12)
  {valide=0 ;}
else {switch(mm){
case  1 :case 3 :case 5 :case 7 :case 8 :case 10 : case 12 :
  if(jj<1||jj>31) valide=0 ;
break ;
case  4 :case 6:case 9 :case 11 :
      if(jj<1||jj>30) valide=0 ;
break ;
case 2 :
  if(aa%4==0&& aa%100 !=0||(aa%400==0)){
    if(jj<1||jj>29);valide=0; }
}}
    return(0);}


// Affichage de tous les voyages
void affichervoyages() {
    printf("\nListe des voyages proposés :\n");
    for (int i = 0; i < nb_voyages; i++) {
        printf("ID: %d, Départ: %s, Arrivée: %s, Ville: %s, Pays: %s, Nature: %s, Places: %d, Prix: %.2f\n",
               voyage_id[i], date_depart[i], date_arrive[i], ville_destination[i],
               pays_destination[i], nature[i], nb_places[i], prix[i]);
    }
}

// Affichage des voyages individuels
void affichervoyagesindividuels() {
    printf("\nLes voyages individuels disponibles sont :\n");
    for (int i = 0; i < nb_voyages; i++) {
        if (strcmp(nature[i], "individuel") == 0) {
            printf("ID: %d, Départ: %s, Arrivée: %s, Ville: %s, Pays: %s, Prix: %.2f\n",
                   voyage_id[i], date_depart[i], date_arrive[i], ville_destination[i],
                   pays_destination[i], prix[i]);
        }
    }
}

// Affichage des voyages en groupes
void affichervoyagesgroupes() {
    printf("\nLes voyages en groupes disponibles sont :\n");
    for (int i = 0; i < nb_voyages; i++) {
        if (strcmp(nature[i], "groupe") == 0) {
            printf("ID: %d, Départ: %s, Arrivée: %s, Ville: %s, Pays: %s, Places: %d, Prix: %.2f\n",
                   voyage_id[i], date_depart[i], date_arrive[i], ville_destination[i],
                   pays_destination[i], nb_places[i], prix[i]);
        }
    }
}

// Rechercher les voyages effectués par un voyageur donné (par numéro de passeport)
void recherchervoyagesparpassport() {
    char passport[20];
    int trouve = 0;
    printf("Entrez votre numéro de passeport: ");
    scanf("%s", passport);
    printf("\nLes voyages effectués par le voyageur avec le passeport %s :\n", passport);
    for (int i = 0; i < nb_reservations; i++) {
        if (strcmp(passport_reservation[i], passport) == 0) {
            printf("Voyage ID: %d, Départ: %s, Arrivée: %s, Ville: %s, Pays: %s, Nature: %s, Places: %d, Prix: %.2f\n",
                   voyage_id[i], date_depart[i], date_arrive[i], ville_destination[i],
                   pays_destination[i], nature[i], nb_places[i], prix[i]);
            trouve = 1;
        }
    }
    if (!trouve) {
        printf("Aucun voyage trouvé pour le passeport numéro %s.\n", passport);
    }
}

// Affichage des réservations
void afficherreservations() {
    if (nb_reservations == 0) {
        printf("Aucune réservation effectuée.\n");
        return;
    }
    printf("\nListe des réservations :\n");
    for (int i = 0; i < nb_reservations; i++) {
        printf("Numéro de réservation: %d\n", num_reservation[i]);
        printf("Voyage ID: %d, Départ: %s, Arrivée: %s\n", voyage_id[i], date_depart[i], date_arrive[i]);
        printf("Destination: %s, Ville: %s, Pays: %s\n", pays_destination[i], ville_destination[i], pays_destination[i]);
        printf("Nature du voyage: %s, Places restantes: %d, Prix: %.2f\n", nature[i], nb_places[i], prix[i]);
        printf("Nom du passager: %s, Prénom: %s\n", nom[i], prenom[i]);
        printf("Date de naissance: %s, Numéro de passeport: %s\n\n", date_naissance[i], num_passport[i]);
    }
}

// Ajouter un nouveau voyage
void ajoutervoyage() {
    int id_voyage;
    char nature_voyage[50];
    char date_dep[11], date_arr[11];
    char pays_dest[50], ville_dest[50];
    int places_disponibles;
    float prix_voyage;

    printf("\nAjouter un nouveau voyage:\n");
    id_voyage = nb_voyages + 1;  // ID séquentiel basé sur le nombre actuel de voyages
    printf("Nature du voyage (individuel/groupe): ");
    scanf("%s", nature_voyage);
    //do{
        printf("Date de départ (JJ/MM/AAAA): ");
        scanf("%10s", date_dep);
      //}while(!date_verif(date_dep));
     //do{
        printf("Date d'arrivée (JJ/MM/AAAA): ");
        scanf("%s", date_arr);
        //}while(!date_verif(date_arr));
    printf("Pays de destination: ");
    scanf("%s", pays_dest);
    printf("Ville de destination: ");
    scanf("%s", ville_dest);
    printf("Nombre de places disponibles: ");
    scanf("%d", &places_disponibles);
    if (places_disponibles>16){
        printf("les places ne doivent pas dépasser 15 places");
    }
    printf("Prix du voyage: ");
    scanf("%f", &prix_voyage);

    // Stocker les détails du voyage dans les tableaux
    voyage_id[nb_voyages] = id_voyage;
    strcpy(nature[nb_voyages], nature_voyage);
    strcpy(date_depart[nb_voyages], date_dep);
    strcpy(date_arrive[nb_voyages], date_arr);
    strcpy(pays_destination[nb_voyages], pays_dest);
    strcpy(ville_destination[nb_voyages], ville_dest);
    nb_places[nb_voyages] = places_disponibles;
    prix[nb_voyages] = prix_voyage;
    nb_voyages++;  // Incrémenter le nombre de voyages

    printf("\nLe voyage a été ajouté avec succès !\n");
}

// Réserver un voyage
void reservervoyage() {
    int id_voyage;
    char passport[20];
    printf("Entrez l'ID du voyage à réserver : ");
    scanf("%d", &id_voyage);

    int trouve = 0;
    for (int i = 0; i < nb_voyages; i++) {
        if (voyage_id[i] == id_voyage && nb_places[i] > 0) {
            trouve = 1;

        }
    }

    if (!trouve) {
        printf("Voyage non disponible ou complet!\n");
        return;
    }

    printf("Entrez le numéro de passeport : ");
    scanf("%s", passport);

    num_reservation[nb_reservations] = nb_reservations + 1;
    voyage_reservation[nb_reservations] = id_voyage;
    strcpy(passport_reservation[nb_reservations], passport);

    // Mise à jour des places disponibles
    for (int i = 0; i < nb_voyages; i++) {
        if (voyage_id[i] == id_voyage) {
            nb_places[i]--;

        }
    }

    nb_reservations++;
    printf("Réservation effectuée avec succès!\n");
}

// Suppression d'un voyage
void suppressionvoyage() {
    int id_voyage;
    printf("Entrez l'ID du voyage à supprimer : ");
    scanf("%d", &id_voyage);

    int index = -1;
    for (int i = 0; i < nb_voyages; i++) {
        if (voyage_id[i] == id_voyage) {
            index = i;

        }
    }

    if (index == -1) {
        printf("Voyage non trouvé.\n");
        return;
    }

    // Supprimer le voyage en décalant les éléments
    for (int i = index; i < nb_voyages - 1; i++) {
        voyage_id[i] = voyage_id[i + 1];
        strcpy(date_depart[i], date_depart[i + 1]);
        strcpy(date_arrive[i], date_arrive[i + 1]);
        strcpy(ville_destination[i], ville_destination[i + 1]);
        strcpy(pays_destination[i], pays_destination[i + 1]);
        strcpy(nature[i], nature[i + 1]);
        nb_places[i] = nb_places[i + 1];
        prix[i] = prix[i + 1];
    }

    nb_voyages--;
    printf("Voyage supprimé avec succès!\n");
}

// Annulation d'une réservation
void annulerreservation() {
    int num_res;
    printf("Entrez le numéro de réservation à annuler : ");
    scanf("%d", &num_res);

    int index = -1;
    for (int i = 0; i < nb_reservations; i++) {
        if (num_reservation[i] == num_res) {
            index = i;

        }
    }

    if (index == -1) {
        printf("Réservation non trouvée!\n");
        return;
    }

    // Mise à jour des places disponibles
    int voyage_id_annule = voyage_reservation[index];
    for (int i = 0; i < nb_voyages; i++) {
        if (voyage_id[i] == voyage_id_annule) {
            nb_places[i]++;

        }
    }

    // Supprimer la réservation en décalant les éléments
    for (int i = index; i < nb_reservations - 1; i++) {
        num_reservation[i] = num_reservation[i + 1];
        voyage_reservation[i] = voyage_reservation[i + 1];
        strcpy(passport_reservation[i], passport_reservation[i + 1]);
    }

    nb_reservations--;
    printf("Réservation annulée avec succès!\n");
}
// Fonction pour retarder un voyage
void retarder_voyage() {
    int trouve = 0;
    int nouvelle_voyage_id;
    char nouvelle_date_depart[11],nouvelle_date_arrive[11];
    // Recherche du voyage par son ID
    for (int i = 0; i < nb_voyages; i++) {
        if (nouvelle_voyage_id == voyage_id[i]) {
            // Mise à jour des dates de départ et d'arrivée
            strcpy(date_depart[i], nouvelle_date_depart);
            strcpy(date_arrive[i], nouvelle_date_arrive);
            trouve = 1;

            // Affichage du voyage modifié
            printf("Voyage %d a été retardé. Nouvelle date de départ: %s, Nouvelle date d'arrivée: %s\n",
                   nouvelle_voyage_id, date_depart[i], date_arrive[i]);

        }
    }

    if (!trouve) {
        printf("Voyage avec ID %d non trouvé.\n", voyage_id);
    }
}
void tirageAuSort() {
    if (nb_clients == 0) {
        printf("Aucun client inscrit pour le tirage!\n");
        return;
    }

    srand(time(NULL));
    int winner = rand() % nb_clients; // Random winner based on client index
    printf("Le gagnant du voyage gratuit est le client avec le passeport: %s\n", num_passport[winner]);
}
// Fonction pour afficher le nombre total de voyages effectués par l'agence
void afficher_voyages_effectues() {
    printf("Nombre total de voyages effectués par l'agence : %d\n", nb_voyages);
}

// Fonction pour afficher le nombre de clients distincts
void afficher_clients_distincts() {
    int distinctCount = 0;
    int passeports_utilises[max] = {0};  // Tableau pour suivre les passeports utilisés

    // Parcours des passeports pour vérifier les clients distincts
    for (int i = 0; i < nb_clients; i++) {
        int isDistinct = 1;

        // Vérification des doublons de passeports
        for (int j = 0; j < i; j++) {
            if (strcmp(num_passport[i], num_passport[j]) == 0) {
                isDistinct = 0;

            }
        }

        // Si le passeport est distinct, on l'ajoute au comptage
        if (isDistinct) {
            distinctCount++;
        }
    }

    printf("Nombre total de clients distincts : %d\n", distinctCount);
}

// Fonction pour afficher le voyageur ayant effectué le plus de voyages
void voyageur_plus_voyages() {
    int voyageur_counts[max] = {0};  // Compteur des voyages pour chaque client
    int max_voyages = 0;
    int voyageur_idx = -1;

    // Parcours des réservations pour compter les voyages
    for (int i = 0; i < nb_reservations; i++) {
        for (int j = 0; j < nb_clients; j++) {
            // Si le passeport de la réservation correspond à celui du client
            if (strcmp(passport_reservation[i], num_passport[j]) == 0) {
                voyageur_counts[j]++;
                if (voyageur_counts[j] > max_voyages) {
                    max_voyages = voyageur_counts[j];
                    voyageur_idx = j;
                }
            }
        }
    }

    // Affichage du client avec le plus de voyages
    if (voyageur_idx != -1) {
        printf("Le voyageur ayant effectué le plus de voyages est: %s %s avec %d voyages\n",
            prenom[voyageur_idx], nom[voyageur_idx], max_voyages);
    } else {
        printf("Aucun voyageur n'a effectué de voyage.\n");
    }
}

// Fonction pour afficher les voyages les plus rentables
void voyages_les_plus_rentables() {
    float max_revenu_individuel = 0, max_revenu_groupe = 0;
    int idx_voyage_individuel = -1, idx_voyage_groupe = -1;

    // Calcul des revenus pour chaque voyage
    for (int i = 0; i < nb_voyages; i++) {
        float revenu = 0;
        for (int j = 0; j < nb_reservations; j++) {
            if (voyage_reservation[j] == voyage_id[i]) {
                revenu += prix[i];
            }
        }

        // Mise à jour des voyages les plus rentables
        if (strcmp(nature[i], "individuel") == 0) {
            if (revenu > max_revenu_individuel) {
                max_revenu_individuel = revenu;
                idx_voyage_individuel = i;
            }
        } else if (strcmp(nature[i], "groupe") == 0) {
            if (revenu > max_revenu_groupe) {
                max_revenu_groupe = revenu;
                idx_voyage_groupe = i;
            }
        }
    }

    // Affichage des voyages les plus rentables
    if (idx_voyage_individuel != -1) {
        printf("Le voyage individuel le plus rentable est %d avec un revenu de %.2f\n", voyage_id[idx_voyage_individuel], max_revenu_individuel);
    }
    if (idx_voyage_groupe != -1) {
        printf("Le voyage en groupe le plus rentable est %d avec un revenu de %.2f\n", voyage_id[idx_voyage_groupe], max_revenu_groupe);
    }
}
// Fonction pour calculer et afficher la moyenne des revenus par voyage
void moyenne_revenus_par_voyage() {
    float total_revenus = 0.0;

    // Calcul des revenus pour chaque voyage
    for (int i = 0; i < nb_voyages; i++) {
        int reservation_count = 0;

        // Compter le nombre de réservations pour le voyage actuel
        for (int j = 0; j < nb_reservations; j++) {
            if (voyage_id[i] == num_passeport_reservation[j]) {
                reservation_count++;
            }
        }

        // Calculer le revenu pour ce voyage
        total_revenus += prix[i] * reservation_count;
    }

    // Calculer la moyenne des revenus par voyage
    float moyenne = total_revenus / nb_voyages;

    // Affichage de la moyenne des revenus par voyage
    printf("La moyenne des revenus par voyage est de: %.2f\n", moyenne);
}
// Fonction pour afficher le pays de destination le plus fréquenté
void pays_destinations_frequentes() {
    int count_pays[max] = {0};  // Compteur des voyages par pays
    int num_pays = 0;

    // Comptabiliser les voyages par pays
    for (int i = 0; i < nb_voyages; i++) {
        int trouve = 0;
        for (int j = 0; j < num_pays; j++) {
            if (strcmp(pays_destination[i], pays_destination[j]) == 0) {
                trouve = 1;

            }
        }
        if (!trouve) {
            strcpy(pays_destination[num_pays], pays_destination[i]);
            num_pays++;
        }
    }

    // Calculer le nombre de voyages pour chaque pays
    for (int i = 0; i < num_pays; i++) {
        for (int j = 0; j < nb_voyages; j++) {
            if (strcmp(pays_destination[j], pays_destination[i]) == 0) {
                count_pays[i]++;
            }
        }
    }

    // Trouver le pays le plus fréquenté
    int max_freq = 0;
    int idx_max_freq = -1;
    for (int i = 0; i < num_pays; i++) {
        if (count_pays[i] > max_freq) {
            max_freq = count_pays[i];
            idx_max_freq = i;
        }
    }

    // Afficher le pays le plus fréquenté
    if (idx_max_freq != -1) {
        printf("Le pays de destination le plus fréquenté est: %s avec %d voyages.\n", pays_destination[idx_max_freq], max_freq);
    } else {
        printf("Aucune destination trouvée.\n");
    }
}
// Fonction pour afficher le pays de destination le moins fréquenté
void pays_destinations_moins_frequentes() {
    int count_pays[max] = {0};  // Compteur des voyages par pays
    int num_pays = 0;

    // Comptabiliser les voyages par pays
    for (int i = 0; i < nb_voyages; i++) {
        int trouve = 0;
        for (int j = 0; j < num_pays; j++) {
            if (strcmp(pays_destination[i], pays_destination[j]) == 0) {
                trouve = 1;

            }
        }
        if (!trouve) {
            strcpy(pays_destination[num_pays], pays_destination[i]);
            num_pays++;
        }
    }

    // Calculer le nombre de voyages pour chaque pays
    for (int i = 0; i < num_pays; i++) {
        for (int j = 0; j < nb_voyages; j++) {
            if (strcmp(pays_destination[j], pays_destination[i]) == 0) {
                count_pays[i]++;
            }
        }
    }

    // Trouver le pays le moins fréquenté
    int min_freq = max;  // On initialise avec une valeur très haute
    int idx_min_freq = -1;
    for (int i = 0; i < num_pays; i++) {
        if (count_pays[i] < min_freq) {
            min_freq = count_pays[i];
            idx_min_freq = i;
        }
    }

    // Afficher le pays le moins fréquenté
    if (idx_min_freq != -1) {
        printf("Le pays de destination le moins fréquenté est: %s avec %d voyages.\n", pays_destination[idx_min_freq], min_freq);
    } else {
        printf("Aucune destination trouvée.\n");
    }
}
// Fonction pour afficher le mois durant lequel l'agence reçoit le plus de demandes
void mois_plus_demande() {
    int demandes_par_mois[12] = {0};  // Tableau pour compter les demandes par mois (index 0 = janvier, index 11 = décembre)

    // Calculer le nombre de demandes par mois
    for (int i = 0; i < nb_reservations; i++) {
        // Extraire le mois de la date de départ (format: "jj/mm/aaaa")
        int mois = (date_depart[i][3] - '0') * 10 + (date_depart[i][4] - '0') - 1;  // Convertir les caractères du mois en entier
        demandes_par_mois[mois]++;
    }

    // Trouver le mois avec le plus de demandes
    int max_demandes = 0;
    int mois_max = -1;
    for (int i = 0; i < 12; i++) {
        if (demandes_par_mois[i] > max_demandes) {
            max_demandes = demandes_par_mois[i];
            mois_max = i;
        }
    }

    // Afficher le mois avec le plus de demandes
    if (mois_max != -1) {
        printf("Le mois avec le plus de demandes est: %d avec %d demandes.\n", mois_max + 1, max_demandes); // Afficher le mois sous forme humaine (1 pour janvier, 12 pour décembre)
    } else {
        printf("Aucune demande trouvée.\n");
    }
}
// Fonction pour afficher le mois durant lequel l'agence enregistre le moins de demandes
void mois_moins_demande() {
    int demandes_par_mois[12] = {0};  // Tableau pour compter les demandes par mois (index 0 = janvier, index 11 = décembre)

    // Calculer le nombre de demandes par mois
    for (int i = 0; i < nb_reservations; i++) {
        // Extraire le mois de la date de départ (format: "jj/mm/aaaa")
        int mois = (date_depart[i][3] - '0') * 10 + (date_depart[i][4] - '0') - 1;  // Convertir les caractères du mois en entier
        demandes_par_mois[mois]++;
    }

    // Trouver le mois avec le moins de demandes
    int min_demandes = 9999;  // Initialisation avec un grand nombre
    int mois_min = -1;
    for (int i = 0; i < 12; i++) {
        if (demandes_par_mois[i] < min_demandes && demandes_par_mois[i] > 0) {  // Ignorer les mois avec 0 demandes
            min_demandes = demandes_par_mois[i];
            mois_min = i;
        }
    }

    // Afficher le mois avec le moins de demandes
    if (mois_min != -1) {
        printf("Le mois avec le moins de demandes est: %d avec %d demandes.\n", mois_min + 1, min_demandes);  // Afficher le mois sous forme humaine (1 pour janvier, 12 pour décembre)
    } else {
        printf("Aucune demande trouvée.\n");
    }
}
// Fonction pour afficher la tranche d'âge la plus fréquente
void tranche_age_plus_frequente() {
    int count_tranches[4] = {0}; // Compteurs pour chaque tranche d'âge

    // Calcul des tranches d'âge
    for (int i = 0; i < nb_clients; i++) {
        // Calcul de l'âge à partir de la date de naissance (en supposant l'année actuelle = 2024)
        int annee_naissance = (date_naissance[i][6] - '0') * 1000 + (date_naissance[i][7] - '0') * 100 + (date_naissance[i][8] - '0') * 10 + (date_naissance[i][9] - '0');
        int age = 2024 - annee_naissance;

        // Déterminer la tranche d'âge
        if (age <= 18) {
            count_tranches[0]++;  // <= 18
        } else if (age >= 19 && age <= 35) {
            count_tranches[1]++;  // [19, 35]
        } else if (age >= 36 && age <= 60) {
            count_tranches[2]++;  // [36, 60]
        } else {
            count_tranches[3]++;  // 60>
        }
    }

    // Trouver la tranche d'âge la plus fréquente
    int max_tranche = 0;  // Initialiser à 0 (la première tranche)
    for (int i = 1; i < 4; i++) {
        if (count_tranches[i] > count_tranches[max_tranche]) {
            max_tranche = i;  // Mettre à jour la tranche la plus fréquente
        }
    }

    // Affichage de la tranche d'âge la plus fréquente
    printf("La tranche d'âge la plus fréquente est: ");
    if (max_tranche == 0) {
        printf("<= 18\n");
    } else if (max_tranche == 1) {
        printf("[19, 35]\n");
    } else if (max_tranche == 2) {
        printf("[36, 60]\n");
    } else {
        printf("60>\n");
    }
}
// Affichage du menu principal
void afficherMenu() {

        printf("            =========================================================================\n");
        printf("           ||                      MENU PRINCIPAL DE L'AGENCE                        ||\n");
        printf("            =========================================================================\n");
        printf("                                                                                       \n");
        printf("                                                                                       \n");
        printf("                                                                                       \n");
        printf("                                                                                       \n");
        printf("            =========================================================================\n");
        printf("           ||                                                                        ||\n");
        printf("           ||---------------------Bienvenue au menu principale-----------------------||\n");
        printf("           ||                                                                        ||\n");
        printf("           ||--------------Veuillez choisir l'objectif de l'opération----------------||\n");
        printf("           ||                                                                        ||\n");
        printf("           ||-------------------------1. Gestion des voyages-------------------------||\n");
        printf("           ||-------------------------2. Statistiques pour l'agence------------------||\n");
        printf("           ||                                                                        ||\n");
        printf("           ||-------------------------3. quitter-------------------------------------||\n");
        printf("           ||                                                                        ||\n");
        printf("            =========================================================================\n");



}
void affiche_gestion() {
    // Menu Gestion de Voyage
    int choix;
    do {
        printf("            =========================================================================\n");
        printf("           ||-----------------BIENVENUE SUR NOTRE SITE DE GESTION-------------------||\n");
        printf("           ||-----------------------DES VOYAGES DE L'AGENCE-------------------------||\n");
        printf("            =========================================================================\n");
        printf("           ||                                                                       ||\n");
        printf("           ||-----------------###veuillez choisir votre operation###----------------||\n");
        printf("           ||                                                                       ||\n");
        printf("            =========================================================================\n");
        printf("           ||                                                                       ||\n");
        printf("           ||-------------------1. Afficher les voyages-----------------------------||\n");
        printf("           ||-------------------2. Afficher tous les voyages individuels------------||\n");
        printf("           ||-------------------3. Afficher tous les voyages en groupe--------------||\n");
        printf("           ||-------------------4. Rechercher les voyages d'un client ---------------||\n");
        printf("           ||-------------------5. Afficher toutes les réservations ----------------||\n");
        printf("           ||-------------------6. Ajouter un nouveau voyage  -----------------------||\n");
        printf("           ||-------------------7. Réserver un voyage  ------------------------------||\n");
        printf("           ||-------------------8. Supprimer un voyage  -----------------------------||\n");
        printf("           ||-------------------9. Retarder un voyage  ------------------------------||\n");
        printf("           ||-------------------10. Annuler une réservation  ------------------------||\n");
        printf("           ||-------------------11. Tirage au sort  -------------------------------||\n");
        printf("           ||-------------------12. Quitter ----------------------------------------||\n");
        printf("Entrez votre choix: ");
        scanf("%d", &choix);

        // Traitement du choix de l'utilisateur
        switch (choix) {
            case 1: affichervoyages(); break;
            case 2: affichervoyagesindividuels(); break;
            case 3: affichervoyagesgroupes(); break;
            case 4: recherchervoyagesparpassport(); break;
            case 5: afficherreservations(); break;
            case 6: ajoutervoyage(); break;
            case 7: reservervoyage(); break;
            case 8: suppressionvoyage(); break;
            case 9: retarder_voyage(); break;
            case 10: annulerreservation(); break;
            case 11: tirageAuSort(); break;
            case 12:
                printf("Au revoir!\n");
                return; // Quitte la fonction et retourne au programme principal
            default:
                printf("Choix invalide. Essayez encore.\n");
                break;
        }

        // Demander si l'utilisateur veut effectuer une autre opération
        printf("\nSouhaitez-vous faire une autre opération ? (1: Oui, 0: Non): ");
        scanf("%d", &choix);
    } while (choix == 1); // Continuer tant que l'utilisateur choisit "1" pour oui
}

void affiche_stat(){
    int choix1;
    do {
        printf("            =============================================================================\n");
        printf("           ||----------------------BIENVENUE DANS LE MENU DE---------------------------||\n");
        printf("           ||----------------------------STATISTIQUES----------------------------------||\n");
        printf("            =============================================================================\n");
        printf("           ||                                                                          ||\n");
        printf("           ||-----------------###veuillez choisir votre operation###-------------------||\n");
        printf("           ||                                                                          ||\n");
        printf("            =============================================================================\n");
        printf("           ||                                                                          ||\n");
        printf("           ||------------------1. Afficher le nombre total des voyages-----------------||\n");
        printf("           ||------------------2. Afficher le nombre des clients distincts-------------||\n");
        printf("           ||------------------3. Afficher le voyageur ayant effectué le plus de voyage||\n");
        printf("           ||------------------4. Afficher les voyages les plus rentables--------------||\n");
        printf("           ||------------------5. Afficher la moyenne des revenus par voyage-----------||\n");
        printf("           ||------------------6. Afficher les destinations les plus fréquentes--------||\n");
        printf("           ||------------------7. Afficher les destinations les moins fréquentes-------||\n");
        printf("           ||------------------8. Afficher le mois ayant le plus de demandes-----------||\n");
        printf("           ||------------------9. Afficher le mois ayant le moins de demandes----------||\n");
        printf("           ||------------------10. Afficher la tranche d'âges la plus fréquente--------||\n");
        printf("           ||                                                                          ||\n");
        printf("            =============================================================================\n");
        printf("           ||                                                                          ||\n");
        printf("           ||------------------11. Quitter----------------------------------------------||\n");
        printf("            ==============================================================================\n");

        printf("Veuillez choisir une option: ");
        scanf("%d", &choix1);

        // Traitement du choix de l'utilisateur
        switch (choix1) {
            case 1: afficher_voyages_effectues(); break;
            case 2: afficher_clients_distincts(); break;
            case 3: voyageur_plus_voyages(); break;
            case 4: voyages_les_plus_rentables(); break;
            case 5: moyenne_revenus_par_voyage(); break;
            case 6: pays_destinations_frequentes(); break;
            case 7: pays_destinations_moins_frequentes(); break;
            case 8: mois_plus_demande(); break;
            case 9: mois_moins_demande(); break;
            case 10: tranche_age_plus_frequente(); break;
            case 11:
                printf("Au revoir !\n");
                return; // Quitte la fonction
            default:
                printf("Option invalide, veuillez réessayer.\n");
                break;
        }

        // Demander si l'utilisateur veut effectuer une autre opération
        printf("\nSouhaitez-vous faire une autre opération ? (1: Oui, 0: Non): ");
        scanf("%d", &choix1);
    } while (choix1 == 1); // Continuer tant que l'utilisateur choisit "1" pour oui
}

int main() {
    int choice;


    do {
        afficherMenu();
        printf("Entrez votre choix (1-3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                 affiche_gestion();
                break;
            case 2:
                 affiche_stat();
                 break;

                 case 3:

       printf("            =========================================================================\n");
       printf("           ||-----------------------------------------------------------------------||\n");
       printf("           ||-----------------------------------------------------------------------||\n");
       printf("           ||-----------------------------FIN D'OPERATION---------------------------||\n");
       printf("           ||---------------------------------AU REVOIR-----------------------------||\n");
       printf("           ||-----------------------------------------------------------------------||\n");
       printf("           ||-----------------------------------------------------------------------||\n");
       printf("            =========================================================================\n");
       break;
            default:
                printf("Choix invalide. Essayez encore.\n");
        }
    }  while (choice < 1 || choice > 3);

    return 0;
}



















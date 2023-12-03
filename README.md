# IOT-
		   
     
     TP  Cours IOT
Année : 2022-2023
Enseignant : Mouhamadou Lamine KEBE 

TP1 : Installation et prise en main d’un serveur IoT - NodeRed

Installer Nodered sur votre ordinateur sur ce lien 





TP2 : Conception de notre objet connecté 
Rendre opérationnel l’objet connecté réalisé l’année dernière avec le capteur BME 
Installer la bibliothèque Arduino Json pour le formatage des données ICI



TP3 : Stockage & Traitement : Installation et utilisation de la base de données Influxdb 

Traitement 


Désencapsuler les données sous format Json pour pouvoir manipuler les différentes données reçues sur de votre objet connecté à l’aide du noeud JSON
Faites la visualisation des différents résultats sur le noeud de débogage 


Stockage avec InfluxDb
Installer la base de données Influxdb ICI avec l’interface graphique d’abord
Exemple de requête InfluxDb ICI 
Désencapsuler les données et créer 4 mesures sur InfluxDb pour insérer les données de votre capteur depuis NodeRed
Visualiser les données de la base de données à l’outil graphique et faites des captures d’écran




TP4 : Interface d’affichage 
               
Mettre en place un plan UX/UI pour votre application Web de prise de décision 
Actionneur
Allumer et éteindre le led de votre arduino depuis votre application à travers le widget Swith
Indication
Serial node
Blink exemple 
Serial.read() fonction ICI
Créer 4 interfaces pour chacune des données avec les statistiques suivantes 
Moyenne
Min
Max 
Valeur normale
Indication
Requête flux exemple pour récupérer la moyenne d’une mesure 
from(bucket: "example-bucket")
    |> range(start: -1d)
    |> filter(fn: (r) => r._measurement == "example-measurement")
    |> mean()
    |> yield(name: "_results")

Accéder à une valeur d’un tableau msg.payload[0]
puis à un objet msg.payload.attribut

TP5 : Déploiement application sur le cloud AWS & IBM

Déployer son application avec NGROK ICI
Lien machine du prof https://516b-154-124-215-241.ngrok-free.app
Déployer votre application sur AWS ICI

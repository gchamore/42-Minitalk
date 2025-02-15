# 📡 Minitalk

## 📝 Présentation

**Minitalk** est un projet permettant de comprendre et manipuler les **signaux UNIX** pour établir une communication entre un **client** et un **serveur**.  
L'objectif est d'envoyer une chaîne de caractères du client vers le serveur **uniquement via des signaux**, sans utiliser de sockets ni de mémoire partagée.

Ce projet met l’accent sur la **gestion des processus**, la **synchronisation**, et l’optimisation des **communications asynchrones**.

---

## 🛠️ Fonctionnalités

### ✅ Partie Obligatoire :
- **Communication entre deux processus** en utilisant uniquement les signaux `SIGUSR1` et `SIGUSR2`.
- **Affichage du PID du serveur** lors de son lancement.
- **Le client envoie une chaîne de caractères** au serveur via une **série de signaux binaires**.
- **Le serveur reçoit et affiche le message**.
- **Gestion des erreurs** : PID invalide, message vide, signaux mal reçus, etc.
- **Le serveur peut recevoir plusieurs messages consécutifs sans être relancé**.

### 🎯 Bonus (si implémenté) :
- **Le serveur envoie une confirmation** au client après réception du message.
- **Support des caractères Unicode** (envoi de caractères multi-octets).
- **Optimisation de la vitesse de transmission des messages**.

---

## 📌 Technologies Utilisées

- **C (Norminette respectée)**
- **Signaux UNIX (`signal`, `sigaction`, `kill`)**
- **Gestion des processus (`getpid`, `pause`, `sleep`, `usleep`)**
- **Manipulation de la mémoire (`malloc`, `free`)**
- **Conversion binaire et transmission de données bit par bit**

---

## 🏗️ Structure du Projet

📂 headers  
┣ 📜 libft.h  
┣ 📜 minitalk.h  
┗ 📜 minitalk_bonus.h  

📂 libft  

📂 srcs  
┣ 📜 client.c  
┣ 📜 server.c  
┗ 📜 tools.c  

📂 srcs_bonus  
┣ 📜 client_bonus.c  
┣ 📜 server_bonus.c  
┗ 📜 tools_bonus.c  

📜 Makefile  
📜 Subject_MINITALK.pdf  

---

## 🔥 Difficultés Rencontrées

- **Conversion et transmission des caractères en binaire**.  
- **Synchronisation entre le client et le serveur** pour éviter la perte de signaux.  
- **Gestion des signaux asynchrones (`sigaction`)** pour assurer la réception correcte.  
- **Réception continue de messages sans interrompre le serveur**.  
- **Optimisation des délais (`usleep`) pour éviter les ralentissements**.  

---

## 🏗️ Mise en place

1. **Cloner le dépôt** :  
   ```bash
   git clone https://github.com/ton-repo/minitalk.git
   cd minitalk
2. **Compiler le projet** :
   ```bash
   make
3. **Lancer le serveur** :
   ```bash
   ./server
Le serveur affichera son PID.  

4. **Lancer le client et envoyer un message** :
   ```bash
   ./client <PID_DU_SERVEUR> "Hello, world!"
   ```
5. **Nettoyer les fichiers compilés** :
   ```bash
   make clean
   make fclean
---

## 👨‍💻 Équipe  

👤 Grégoire Chamorel (Gchamore)  

---

## 📜 Projet réalisé dans le cadre du cursus 42.  

Tu peux bien sûr modifier ce README selon tes besoins, ajouter plus de détails sur ton approche et des instructions d’installation précises. 🚀  

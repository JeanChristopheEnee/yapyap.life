yApyAp - Plateforme de streaming social basée sur XMPP et Jamulus

Description

yApyAp est une application de streaming social open-source qui combine vidéo en direct, animations 3D, et monétisation via l’envoi de cadeaux et le temps de diffusion. Basé sur un modèle client/serveur, yApyAp exploite les protocoles XMPP pour la communication et Jamulus pour un transport audio ultra-faible latence.

L’objectif est de permettre aux utilisateurs de diffuser des vidéos en direct avec des avatars et animations 3D créées sous Blender, tout en offrant une interactivité et une expérience immersive unique.

Fonctionnalités principales

🎥 Streaming vidéo en direct avec animations 3D

🏆 Monétisation via l'envoi de cadeaux et temps de diffusion

📹 Création et partage de vidéos enregistrées (style YouTube)

🎙 Production et diffusion de fichiers audio

🔊 Transport audio ultra-faible latence avec Jamulus

💬 Messagerie et interactions via XMPP

🌍 Compatible multi-plateforme (Android, iOS, Windows, macOS, Apple Vision Pro)

🔓 100% open-source sous licence GPLv3 et Creative Commons

Architecture et technologies utilisées

1. Partie Serveur (Linux uniquement)

Le serveur est basé sur Prosody (XMPP) pour la gestion des connexions et Jamulus pour la transmission audio.

yapyap-server/
├── config/            # Fichiers de configuration (Prosody XMPP, Jamulus...)
├── modules/           # Modules XMPP personnalisés (gestion des cadeaux, interactions...)
├── scripts/           # Scripts pour l’installation et le démarrage du serveur
├── db/                # Base de données des utilisateurs et historiques
├── main_server.py     # Serveur principal XMPP en Python

2. Partie Client (Godot, C# - Multiplateforme)

L’application cliente est développée avec Godot Engine (C#) pour une compatibilité totale avec Android, iOS, Windows, macOS et Apple Vision Pro.

yapyap-client/
├── godot_project/     # Projet client sous Godot
│   ├── scenes/        # Interfaces et interactions utilisateur
│   ├── scripts/       # Scripts C# pour gérer les interactions et communications
│   ├── assets/        # Modèles 3D, textures et sons pour l’animation
├── build/             # Builds et exports pour chaque plateforme

Installation du serveur

1. Installer les dépendances

Exécute le script d’installation des dépendances :

chmod +x yapyap-server/scripts/install_dependencies.sh && \
yapyap-server/scripts/install_dependencies.sh

2. Lancer le serveur

Une fois les dépendances installées, démarre le serveur avec :

python3 yapyap-server/main_server.py

Installation du client

1. Compiler Godot avec le support de Mono et C#

scons platform=linuxbsd target=editor dev_build=yes module_mono_enabled=yes dotnet_enabled=yes -j$(nproc)

2. Lancer l’éditeur Godot avec le projet client

./bin/godot.linuxbsd.editor.mono.x86_64 -e yapyap-client/godot_project

Déploiement et exportation du client

Une fois le projet testé et fonctionnel, génère les exports pour les différentes plateformes :

Linux :

./bin/godot.linuxbsd.editor.mono.x86_64 --export-release "Linux" build/linux/yapyap.x86_64

Windows :

./bin/godot.linuxbsd.editor.mono.x86_64 --export-release "Windows Desktop" build/windows/yapyap.exe

Android :

./bin/godot.linuxbsd.editor.mono.x86_64 --export-release "Android" build/android/yapyap.apk

iOS :

./bin/godot.linuxbsd.editor.mono.x86_64 --export-release "iOS" build/ios/yapyap.ipa

macOS :

./bin/godot.linuxbsd.editor.mono.x86_64 --export-release "MacOS" build/macos/yapyap.app

Apple Vision Pro (via visionOS) :

./bin/godot.linuxbsd.editor.mono.x86_64 --export-release "iOS" build/vision_pro/yapyap.ipa

Contributions

Ce projet est open-source sous GPLv3 et Creative Commons. Les contributions sont les bienvenues, que ce soit pour ajouter des fonctionnalités, corriger des bugs ou améliorer les performances.

Contact

Auteur : Jean-Christophe Enee📌 GitHub : JeanChristopheEnee📌 Email : contact@yapyap.life

🚀 Rejoignez le projet et contribuez à l’avenir du streaming interactif !



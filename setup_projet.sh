#!/bin/bash

# Création des dossiers pour le serveur
mkdir -p yapyap-server/{config,modules,scripts,logs,db}
touch yapyap-server/config/{prosody.cfg.lua,jamulus.cfg,server_settings.json}
touch yapyap-server/modules/{mod_yapyap.lua,mod_rtp.lua}
touch yapyap-server/scripts/{start_server.sh,install_dependencies.sh}
touch yapyap-server/logs/server.log
touch yapyap-server/db/users.db
touch yapyap-server/{main_server.py,requirements.txt}

# Création des dossiers pour le client
mkdir -p yapyap-client/{godot_project/{scenes,scripts,assets/{models,textures,sounds}},build/{android,ios,windows,macos,vision_pro}}
touch yapyap-client/godot_project/scenes/{main.tscn,live_scene.tscn,profile.tscn}
touch yapyap-client/godot_project/scripts/{main.gd,live_manager.gd,animation_manager.gd,xmpp_client.gd,jamulus_client.gd,monetization.gd}
touch yapyap-client/godot_project/godot.cfg
touch yapyap-client/README.md

# Initialisation de Git et ajout des fichiers
git init
git add .
git commit -m "Initialisation du projet yApyAp avec serveur et client"
git branch -M main

# Remplace <URL_DU_DEPOT> par l'URL de ton dépôt GitHub
git remote add origin https://github.com/JeanChristopheEnee/yapyap.life
git push -u origin main

echo "Projet yApyAp structuré et ajouté à GitHub avec succès !"

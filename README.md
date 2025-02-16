# yapyap.life

## Projet C++ avec Unreal Engine

Ce guide vous expliquera comment ajouter les dépendances nécessaires pour réaliser un projet en C++ avec Unreal Engine.

### Prérequis

Avant de commencer, assurez-vous d'avoir les éléments suivants installés sur votre machine :

1. **Unreal Engine** : Vous pouvez télécharger la dernière version d'Unreal Engine à partir du site officiel [Unreal Engine](https://www.unrealengine.com/).
2. **Visual Studio** : Unreal Engine utilise Visual Studio pour compiler les projets C++. Assurez-vous d'avoir Visual Studio 2019 ou une version ultérieure installée avec les composants nécessaires pour le développement de jeux.

### Étapes pour ajouter les dépendances

#### 1. Créer un nouveau projet Unreal Engine

1. Ouvrez Unreal Engine.
2. Cliquez sur **New Project** et sélectionnez **Games**.
3. Cliquez sur **Next**.
4. Sélectionnez **Blank** comme modèle de projet.
5. Cliquez sur **Next**.
6. Sous **Project Settings**, assurez-vous de sélectionner **C++** comme langage de programmation.
7. Choisissez un emplacement pour votre projet et donnez-lui un nom.
8. Cliquez sur **Create Project**.

#### 2. Configurer Visual Studio

1. Ouvrez Visual Studio.
2. Allez dans **Tools** > **Get Tools and Features**.
3. Sous l'onglet **Workloads**, sélectionnez **Game development with C++**.
4. Assurez-vous que les composants suivants sont cochés :
    - **Desktop development with C++**
    - **.NET desktop development**
    - **Universal Windows Platform development** (si nécessaire)
5. Cliquez sur **Modify** pour installer les composants nécessaires.

#### 3. Ajouter les dépendances nécessaires

1. Ouvrez votre projet Unreal Engine dans Visual Studio.
2. Dans l'**Solution Explorer**, faites un clic droit sur le dossier **Source** de votre projet et sélectionnez **Add** > **New Item**.
3. Sélectionnez **C++ File (.cpp)** et donnez un nom à votre fichier.
4. Ajoutez les includes nécessaires en haut de votre fichier `.cpp` :
    ```cpp
    #include "CoreMinimal.h"
    #include "Modules/ModuleManager.h"
    #include "Engine/Engine.h"
    #include "GameFramework/Actor.h"
    #include "MyProject.h"
    ```
5. Si vous avez besoin d'ajouter des modules supplémentaires, ouvrez le fichier `.uproject` de votre projet et ajoutez les modules nécessaires dans la section `Modules` :
    ```json
    "Modules": [
        {
            "Name": "MyProject",
            "Type": "Runtime",
            "LoadingPhase": "Default"
        },
        {
            "Name": "MyAdditionalModule",
            "Type": "Runtime",
            "LoadingPhase": "Default"
        }
    ]
    ```

#### 4. Compiler et exécuter le projet

1. Dans Visual Studio, sélectionnez la configuration **Development Editor** et la plateforme **Win64**.
2. Cliquez sur **Build** > **Build Solution** ou appuyez sur `Ctrl+Shift+B` pour compiler votre projet.
3. Une fois la compilation terminée, revenez dans Unreal Engine et cliquez sur le bouton **Play** pour exécuter votre projet.

### Conclusion

Vous avez maintenant configuré un projet C++ avec Unreal Engine et ajouté les dépendances nécessaires pour commencer le développement. N'hésitez pas à consulter la documentation officielle d'Unreal Engine pour plus d'informations et d'exemples.

Bon développement !
---

# Project Setup

### Windows

1. Install [CMake](https://cmake.org/download/)
2. Install [Git](https://git-scm.com/download/win)
3. Install a C++ compiler, such as [MinGW](http://www.mingw.org/)
4. Clone the repository:
   ```sh
   git clone https://github.com/JeanChristopheEnee/yapyap.life.git
   ```
   Navigate to the project directory:
   ```sh
   cd yapyap.life
   ```
Create a build directory and navigate to it:
  ```sh
  mkdir build
  cd build
  ```
Run CMake to configure the project:
  ```sh
  cmake ..
  ```
Build the project:
  ```sh
  cmake --build .
  ```
### MacOS

  Install Homebrew:
  ```sh
  /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
  ```
Install CMake:
  ```sh
  brew install cmake
  ```
Install Git:
  ```sh
  brew install git
  ```
Install a C++ compiler, such as Xcode Command Line Tools
  ```sh
  xcode-select --install
  ```
Clone the repository:
  ```sh
  git clone https://github.com/JeanChristopheEnee/yapyap.life.git
  ```
Navigate to the project directory:
  ```sh
  cd yapyap.life
  ```
Create a build directory and navigate to it:
  ```sh
  mkdir build
  cd build
  ```
Run CMake to configure the project:
  ```sh
  cmake ..
  ```
Build the project:
  ```sh
  cmake --build .
  ```
### Ubuntu Linux LTS

Install CMake:
  ```sh
  sudo apt update
  sudo apt install cmake
  ```
Install Git:
  ```sh
  sudo apt install git
  ```
Install a C++ compiler:
  ```sh
  sudo apt install build-essential
  ```
Clone the repository:
  ```sh
  git clone https://github.com/JeanChristopheEnee/yapyap.life.git
  ```
Navigate to the project directory:
  ```sh
  cd yapyap.life
  ```
Create a build directory and navigate to it:
  ```sh
  mkdir build
  cd build
  ```
Run CMake to configure the project:
  ```sh
  cmake ..
  ```
Build the project:
  ```sh
  cmake --build .
  ```
### Neovim Configuration

1. Install Neovim:
   - **Windows**: Download the installer from the [Neovim releases page](https://github.com/neovim/neovim/releases).
   - **MacOS**:
     ```sh
     brew install neovim
     ```
   - **Ubuntu Linux LTS**:
     ```sh
     sudo apt update
     sudo apt install neovim
     ```

2. Configure Neovim for C++ development:
   - Create a configuration directory:
     ```sh
     mkdir -p ~/.config/nvim
     ```
   - Create or edit the `init.vim` file in this directory:
     ```sh
     nvim ~/.config/nvim/init.vim
     ```
   - Add the following configuration to `init.vim`:
     ```vim
     " Basic settings
     set number
     syntax on

     " Install plug.vim for plugin management
     if empty(glob('~/.local/share/nvim/site/autoload/plug.vim'))
       silent !curl -fLo ~/.local/share/nvim/site/autoload/plug.vim --create-dirs
           \ 'https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim'
       autocmd VimEnter * PlugInstall
     endif

     call plug#begin('~/.local/share/nvim/plugged')

     " Add desired plugins
     Plug 'neoclide/coc.nvim', {'branch': 'release'}
     Plug 'scrooloose/nerdtree'
     Plug 'airblade/vim-gitgutter'
     Plug 'vim-airline/vim-airline'
     Plug 'vim-airline/vim-airline-themes'

     call plug#end()

     " COC settings for C++ development
     let g:coc_global_extensions = ['coc-clangd']

     " NERDTree settings
     map <C-n> :NERDTreeToggle<CR>
     ```

3. Launch Neovim and install the plugins:
   ```sh
   nvim
   ```
    Run ```:PlugInstall``` to install the plugins.

   ## For C++ development, make sure you have clangd installed:

   **Windows**: Install via the LLVM installer from the [LLVM releases page](https://releases.llvm.org/download.html).

    **MacOS**:
    ```sh
    brew install llvm
    ```
    **Ubuntu** Linux LTS:
    ```sh
    sudo apt install clangd
    ```
    
__Open your project in Neovim:__
```sh
nvim <path-to-your-project>
```
With these steps, you will have Neovim configured for C++ development.

© 2025 Blues Softwares / Jean-Christophe Énée. All Rights Reserved.


# 42sh - Shell Programming  
![Shell Logo](https://img.icons8.com/ios-filled/50/000000/console.png)  
**Projet : B-PSU-210**  
**École : Epitech**  
**Année : 2024**  

---

## Description du Projet  
Le projet **42sh** consiste à développer un shell Unix en **C**, compatible avec **tcsh**, dans le cadre du cursus de programmation système. Ce shell devra être capable de parser et d'exécuter des commandes tout en prenant en charge diverses fonctionnalités de base telles que les redirections, les pipes, les variables d'environnement et bien plus encore.

## Détails Techniques  

- **Nom binaire** : `42sh`  
- **Nom du dépôt** : `PSU_42sh_$ACADEMICYEAR`  
- **Langage** : C  
![C Logo](https://img.icons8.com/color/48/000000/c-programming.png)
- **Compilation** : Utilisation d'un `Makefile` avec les règles `re`, `clean`, et `fclean`.
![Makefile Logo](https://img.icons8.com/plasticine/100/000000/makefile.png)

### Fonctionnalités Obligatoires  
Le shell doit prendre en charge les fonctionnalités suivantes :

- Gestion des espaces et tabulations.
- Prise en charge de `$PATH` et des variables d'environnement.
- Gestion des redirections (`<`, `>`, `<<`, `>>`).
- Gestion des pipes (`|`).
- Implémentation des **builtins** : `cd`, `echo`, `exit`, `setenv`, `unsetenv`.
- Gestion des séparateurs (`;`, `&&`, `||`).
- Gestion des erreurs et des valeurs de retour.

### Fonctionnalités Optionnelles  
Ces fonctionnalités sont fortement recommandées et apportent des points supplémentaires :

- Inhibiteurs (`\`).
- Globbings (`*`, `?`, `[]`).
- Gestion des jobs (`&`, `fg`).
- Variables locales et d'environnement.
- Gestion de l'historique (`!`).
- Aliases.
- Édition de ligne : multi-lignes, rebinding dynamique, autocomplétion.

## Compilation et Exécution  
Pour compiler et exécuter le shell, il suffit de suivre les commandes suivantes :

```bash
make
./42sh
```

Pour nettoyer les fichiers objets et binaires :

```bash
make clean
make fclean
```

---

## Exemple d'Exécution  
```bash
$ ./42sh
42sh> cd ; </etc/hosts od -c | grep xx | wc >> /tmp/z -l ; cd - && echo "OK"
```

---

## Conseils  
- Formez une équipe solide et répartissez intelligemment le travail.
- Utilisez Git pour suivre l'évolution du code, et n'hésitez pas à utiliser des branches.
- Écrivez des tests unitaires régulièrement pour garantir la stabilité de votre code.

![Git Logo](https://img.icons8.com/ios-glyphs/30/000000/git.png) ![C Logo](https://img.icons8.com/color/48/000000/c-programming.png)

---

## Contact  
**Équipe** : *Insérez vos noms ici*  
**Email** : *contact@epitech.eu*

#!/usr/bin/env bash
# This will update all the submodules automatically after a 'git pull'

echo "Good Day Friend, building all submodules while checking out from MASTER branch."

git submodule update 
git submodule foreach git checkout master 
git submodule foreach git pull origin master 

git add linp/
git commit -m "atualizado desde o último push neste repositório" linp/
#!/bin/bash

# TODO: Delete this file
# Only needed for forcing directories and files to 
# lowercase

to_lowercase() {
    echo $1 | tr '[:lower:]' '[:upper:]'
}

export -f to_lowercase

# TODO: Research the reasoning for having to take a two step process
# https://stackoverflow.com/questions/3011625/git-mv-and-only-change-case-of-directory

# handle renaming directories first. this will be a 2 step process
git ls-tree -r -d --name-only HEAD | uniq | while read -r directory; do echo "$directory"; done
# handle renaming files after directories
git ls-files


git ls-files -o -d | grep '/$'


